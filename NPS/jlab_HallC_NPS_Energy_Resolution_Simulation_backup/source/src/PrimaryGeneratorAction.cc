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
/// \file electromagnetic/TestEm4/src/PrimaryGeneratorAction.cc
/// \brief Implementation of the PrimaryGeneratorAction class
//
//
// $Id: PrimaryGeneratorAction.cc 67268 2013-02-13 11:38:40Z ihrivnac $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "PrimaryGeneratorAction.hh"

//20180209(start)
#include "HistoManager.hh"
//20180209(finish)

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4Geantino.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//20171006(start)
#include "G4GeneralParticleSource.hh"
//20171006(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//20180209(start)
//PrimaryGeneratorAction::PrimaryGeneratorAction()
PrimaryGeneratorAction::PrimaryGeneratorAction(HistoManager* histo)
//20180209(finish)
: G4VUserPrimaryGeneratorAction(),fParticleGun(0),
//20180209(start)
  fHistoManager(histo)
//20180209(finish)
{
  //  G4int n_particle = 1;
  fParticleGun  = new G4GeneralParticleSource(/*n_particle*/);//20171006 changed from G4ParticleGun
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  fParticleGun->GeneratePrimaryVertex(anEvent);
  //20180209(start)
  G4double t = fParticleGun->GetParticleTime();
  //  G4ParticleDefinition* PID = fParticleGun->GetParticleDefinition();
  G4int PID = fParticleGun->GetParticleDefinition()->GetPDGEncoding();
  // G4int n = fParticleGun->GetNumberOfParticles();
  G4ThreeVector xyz = fParticleGun->GetParticlePosition();
  G4ThreeVector Pxyz = fParticleGun->GetParticleMomentumDirection();
  G4double E = fParticleGun->GetParticleEnergy();

  fHistoManager->SetPrimaryParticle(t, PID, xyz, Pxyz, E);

  // G4cout<<"time   : "<<t<<G4endl;
  // G4cout<<"PID    : "<<PID<<G4endl;
  // G4cout<<"n      : "<<n<<G4endl;
  // G4cout<<"pos    : "<<xyz.x()<<", "<<xyz.y()<<", "<<xyz.z()<<G4endl;
  // G4cout<<"mom    : "<<Pxyz.x()<<", "<<Pxyz.y()<<", "<<Pxyz.z()<<G4endl;
  // G4cout<<"energy : "<<E<<G4endl;
  //20180209(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

