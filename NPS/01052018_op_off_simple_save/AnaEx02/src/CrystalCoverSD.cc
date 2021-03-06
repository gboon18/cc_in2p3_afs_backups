//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B5HadCalorimeterSD.cc 76474 2013-11-11 10:36:34Z gcosmo $
//
/// \file B5HadCalorimeterSD.cc
/// \brief Implementation of the B5HadCalorimeterSD class

#include "CrystalCoverSD.hh"
#include "CrystalCoverHit.hh"

#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CrystalCoverSD::CrystalCoverSD(G4String name)
: G4VSensitiveDetector(name), fHitsCollection(0), fHCID(-1)
{
    collectionName.insert("CrystalCoverColl");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CrystalCoverSD::~CrystalCoverSD()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CrystalCoverSD::Initialize(G4HCofThisEvent* hce)
{
  fHitsCollection 
    = new CrystalCoverHitsCollection(SensitiveDetectorName,collectionName[0]);
  if (fHCID<0)
    { fHCID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection); }
  hce->AddHitsCollection(fHCID,fHitsCollection);

  //20180117(start)
  // fill calorimeter hits with zero energy deposition
  for (G4int iColumn=0 ; iColumn<36 ; iColumn++)
    for (G4int iRow=0 ; iRow<31 ; iRow++)
      {
	CrystalCoverHit* hit = new CrystalCoverHit();
	fHitsCollection->insert(hit);
      }
  //20180117(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool CrystalCoverSD::ProcessHits(G4Step* step, G4TouchableHistory*)
{
  //20171031(start)
  G4Track* track = step->GetTrack();
  G4String ParticleName = track->GetDynamicParticle()->GetParticleDefinition()->GetParticleName();
  G4int op = 0;
  if (ParticleName!="opticalphoton") return true;
  else if (ParticleName=="opticalphoton") op = 1;
  //20171031(finish)

  //20171102(start)
  G4TouchableHistory* touchable
    = (G4TouchableHistory*)(step->GetPreStepPoint()->GetTouchable());

  //20180216(start)
  G4VPhysicalVolume* cellPhysical = touchable->GetVolume(2);
  G4int rowNo = cellPhysical->GetCopyNo();//0~30(31) in total
  //    G4cout<<"rowNo :"<<rowNo<<G4endl;
  G4VPhysicalVolume* columnPhysical = touchable->GetVolume(1);
  G4int columnNo = columnPhysical->GetCopyNo();//0~35(36) in total
  //    G4cout<<"columnNo :"<<columnNo<<G4endl;
  G4int hitID = columnNo+36*rowNo;//0~1115(1116)
  //    G4cout<<"hitID :"<<hitID<<G4endl;
  //20180216(finish)


  // //20180117(start)
  // G4VPhysicalVolume* cellPhysical = touchable->GetVolume(2);
  // G4int rowNo = cellPhysical->GetCopyNo();//0~30(31) in total
  // //    G4cout<<"rowNo :"<<rowNo<<G4endl;
  // G4VPhysicalVolume* columnPhysical = touchable->GetVolume(1);
  // G4int columnNo = columnPhysical->GetCopyNo();//0~35(36) in total
  // //    G4cout<<"columnNo :"<<columnNo<<G4endl;
  // G4int hitID = 31*columnNo+rowNo;//0~1115(1116)
  // //    G4cout<<"hitID :"<<hitID<<G4endl;
  // //20180117(finish)

  CrystalCoverHit* hit = (*fHitsCollection)[hitID];
  //CrystalCoverHit* hit = new CrystalCoverHit();
  //20171102(finish)

  //20180117(start)
  // check if it is first touch
  if (hit->GetColumnID()<0)
    {
      hit->SetColumnID(columnNo);
      hit->SetRowID(rowNo);
      G4int depth = touchable->GetHistory()->GetDepth();
      G4AffineTransform transform 
	= touchable->GetHistory()->GetTransform(depth-2);
      transform.Invert();
      hit->SetRot(transform.NetRotation());
      hit->SetPos(transform.NetTranslation());
    }
  //20180117(finish)

  //20171020(start)
  hit->AddOPInt(op);
  //20171020(finish)

  return true;
}

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
