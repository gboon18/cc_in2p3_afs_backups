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
/// \file analysis/shared/src/SteppingAction.cc
/// \brief Implementation of the SteppingAction class
//
//
// $Id: SteppingAction.cc 67226 2013-02-08 12:07:18Z ihrivnac $
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "SteppingAction.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"

#include "G4Step.hh"

//20180621(start)
#include "G4TouchableHistory.hh"
#include "HistoManager.hh"
//20180621(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//20180622(start)
// SteppingAction::SteppingAction(DetectorConstruction* det,
//                                          EventAction* evt)
SteppingAction::SteppingAction(DetectorConstruction* det,
			       EventAction* evt,
			       HistoManager* histo)
  //20180622(finish)
  : G4UserSteppingAction(), 
    fDetector(det), fEventAction(evt),
    //20180622(start)
    fHistoManager(histo), fEne(), fPID()
    //20180622(finish)
{
  //20180622(start)
  fEne.resize(1116,0.), fPID.resize(1116,0);
  //20180622(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  // get volume of the current step
  G4VPhysicalVolume* volume_pre 
    = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();

  // collect energy and track length step by step
  G4double edep = aStep->GetTotalEnergyDeposit();

  //20180621(start)
  G4VPhysicalVolume* volume_post
    = aStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume();

  if(
     volume_pre->GetLogicalVolume()->GetName() == "WrapFront_log"
     //     && volume_post->GetLogicalVolume()->GetName() == "Crystal_log"
     ){

    G4TouchableHistory* touchable
      = (G4TouchableHistory*)(aStep->GetPreStepPoint()->GetTouchable());

    //from B5HadCalorimeterSD.cc
    //crystal numbering. column by column!
    G4VPhysicalVolume* cellPhysical = touchable->GetVolume(2);
    G4int rowNo = cellPhysical->GetCopyNo();//0~30(31) in total
    //    G4cout<<"rowNo :"<<rowNo<<G4endl;
    G4VPhysicalVolume* columnPhysical = touchable->GetVolume(1);
    G4int columnNo = columnPhysical->GetCopyNo();//0~35(36) in total
    //    G4cout<<"columnNo :"<<columnNo<<G4endl;
    G4int hitID = columnNo+36*rowNo;//0~1115(1116)
    // G4cout<<"hitID :"<<hitID<<G4endl;
    
    G4Track* track = aStep->GetTrack();
    G4int PID = track->GetDynamicParticle()->GetParticleDefinition()->GetPDGEncoding();
    G4double ene = track->GetTotalEnergy();
    // G4cout<<ene<<G4endl;
    // G4cout<<"you are here"<<G4endl;

    //20180623(start)
    //20180704(start)(to delete)
    // fEventAction->GetFluxEnergy(ene);//20180704 deleted
    //20180704(finish)(to delete)
    //20180623(finish)

    fHistoManager->SetFluxEnergyandPID(hitID, PID, ene);
    //20180704(start)
    fHistoManager->FillNtuple2();
    //20180704(finish)
  }
  //20180621(finish)

  
  G4double stepl = 0.;
  if (aStep->GetTrack()->GetDefinition()->GetPDGCharge() != 0.)
    stepl = aStep->GetStepLength();
      
  //20171013(start)
  /*
    if (volume_pre == fDetector->GetAbsorber()) fEventAction->AddAbs(edep,stepl);
    if (volume_pre == fDetector->GetGap())      fEventAction->AddGap(edep,stepl);
  */
  if (volume_pre->GetName() == "Target_log") fEventAction->AddAbs(edep,stepl);
  if (volume_pre->GetName() == "Crystal_log")      fEventAction->AddGap(edep,stepl);
  //20171013(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
