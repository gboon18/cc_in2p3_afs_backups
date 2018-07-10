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
/// \file analysis/shared/src/EventAction.cc
/// \brief Implementation of the EventAction class
//
//
// $Id: EventAction.cc 92322 2015-08-27 14:54:05Z gcosmo $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "EventAction.hh"

#include "RunAction.hh"
#include "HistoManager.hh"

#include "G4Event.hh"

//20171013(start)
#include "B5HadCalorimeterHit.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
//20171013(finish)

//20180117(start)
#include "CrystalCoverHit.hh"
#include "CrystalFrontCoverHit.hh"
#include "PMTcoverHit.hh"
//20180117(finish)

//20171127(start)
//#include "FluxHit.hh"//20180425 deleted
//20171127(finish)

//20171129(start)
//#include "ChambWindHit.hh"//20180425 deleted
//20171129(finish)


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(RunAction* run, HistoManager* histo)
  :G4UserEventAction(),
   fRunAct(run),fHistoManager(histo),
   //20171013(start)
   fHCHCID(-1),fHadCalEdep(),
   //20171013(finish)
   //20171124(start)
   fPID(),
   //20171124(finish)

   //20180117(start)
   fOP_sc(), fOP_ce(),
   fCrystCoverHCID(-1), fCrystCoverOP(), fCrystFrontCoverHCID(-1), fCrystFrontCoverOP(),

   //20180621(start)
   fCrystFrontCoverEdep(), fCrystFrontCoverPos(), fCrystFrontCoverPID(), 
   //20180621(finish)

   fPMTcoverHCID(-1), fPMTcoverOP(),
   //20180117(finish)

   //20180425(start)
   //deleted
   /*
   //20171127(start)
   fFlxHCID(-1),
  fFluxEnergy(-999), fFluxPID(-999),
  fPos(-999),
   //20171127(finish)
//20171129(start)
  fChambWindHCID(-1),
  fChambWindEnergy(-999), fChambWindPID(-999),
   fChambWindPos(-999),
   */
   //20180425(finish)
   //20171129(finish)
   fEnergyAbs(0.), fEnergyGap(0.),
  fTrackLAbs(0.), fTrackLGap(0.),
  fPrintModulo(0)                             
{
  fPrintModulo = 100; 
  //20171013(start)
  fHadCalEdep.resize(1116,0.);
  //20171013(finish)
  //20171020(start)
  fPID.resize(1116,0),
  //20171020(finish)

  //20180117(start)
  fOP_sc.resize(1116,0), fOP_ce.resize(1116,0),
  fCrystCoverOP.resize(1116,0), fCrystFrontCoverOP.resize(1116,0),

  //20180621(start)
  fCrystFrontCoverEdep.resize(1116, 0.),
  fCrystFrontCoverPos.resize(1116, G4ThreeVector(0.,0.,0.)),
  fCrystFrontCoverPID.resize(1116, 0), 
  //20180621(finish)

  fPMTcoverOP.resize(1116,0);
  //20180117(finish)

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* evt)
{  
  G4int evtNb = evt->GetEventID();
  if (evtNb%fPrintModulo == 0) 
    //    G4cout << "\n---> Begin of event: " << evtNb << G4endl;
 
    // initialisation per event
    fEnergyAbs = fEnergyGap = 0.;
  fTrackLAbs = fTrackLGap = 0.;
  
  //20171013(start)
  if (fHCHCID==-1) {

    //20171023(start)
    //cc-in2p3 does not understand(or geant4.10.02.0 does not understand) "auto"
    //    auto sdManager = G4SDManager::GetSDMpointer();
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    //20171023(finish)
    //    fTrackerID = sdManager->GetCollectionID("B2/TrackerChamberSD/TrackerHitsCollection");//B2/TrackerChamberSD is the SDname, TrackerHitsCollection is the collection ID.
    fHCHCID = sdManager->GetCollectionID("HadCalorimeter/HadCalorimeterColl");//B2/TrackerChamberSD is the SDname, TrackerHitsCollection is the collection ID.
  }
  //20171013(finish)

  //20180117(start)
  if (fCrystCoverHCID==-1) {
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    fCrystCoverHCID = sdManager->GetCollectionID("CrystalCover/CrystalCoverColl");
  }

  if (fCrystFrontCoverHCID==-1) {
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    fCrystFrontCoverHCID = sdManager->GetCollectionID("CrystalFrontCover/CrystalFrontCoverColl");
  }

  if (fPMTcoverHCID==-1) {
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    fPMTcoverHCID = sdManager->GetCollectionID("PMTcover/PMTcoverColl");
  }

  //20180117(finish)

  //20180425(start)
  //delete
  /*
  //20171127(start)
  if (fFlxHCID==-1) {
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    fFlxHCID = sdManager->GetCollectionID("Flux/FluxColl");//B2/TrackerChamberSD is the SDname, TrackerHitsCollection is the collection ID.
  }
  //20171127(finish)
  //20171129(start)
  if (fChambWindHCID==-1) {
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    fChambWindHCID = sdManager->GetCollectionID("ChambWind/ChambWindColl");//B2/TrackerChamberSD is the SDname, TrackerHitsCollection is the collection ID.
  }
  //20171129(finish)
  */
  //20180425(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//20171013(start)
//void EventAction::EndOfEventAction(const G4Event*)
void EventAction::EndOfEventAction(const G4Event* evt)
//20171013(finish)
{
  //accumulates statistic
  //
  fRunAct->fillPerEvent(fEnergyAbs, fEnergyGap, fTrackLAbs, fTrackLGap);
  
  /*
  //fill histograms
  //
  fHistoManager->FillHisto(0, fEnergyAbs);
  fHistoManager->FillHisto(1, fEnergyGap);
  fHistoManager->FillHisto(2, fTrackLAbs);
  fHistoManager->FillHisto(3, fTrackLGap);
  
  //fill ntuple
  //
  fHistoManager->FillNtuple(fEnergyAbs, fEnergyGap, fTrackLAbs, fTrackLGap);
  */
  //20171013(start)
  //20171023(start)
  //cc-in2p3 does not understand(or geant4.10.02.0 does not understand) "auto"
  //  auto hce = evt->GetHCofThisEvent();
  G4HCofThisEvent* hce = evt->GetHCofThisEvent();
  //20171023(finish)
  if (!hce) {
    G4ExceptionDescription msg;
    msg << "No hits collection of this event found." << G4endl; 
    G4Exception("EventAction::EndOfEventAction()",
		"Code001", JustWarning, msg);
    return;
  }
  
  // Get hits collections
  //20171023(start)
  //cc-in2p3 does not understand(or geant4.10.02.0 does not understand) "auto" 
  //  auto hcHC 
  B5HadCalorimeterHitsCollection* hcHC 
    //20171023(finish)
    = static_cast<B5HadCalorimeterHitsCollection*>(hce->GetHC(fHCHCID));
  if (!hcHC) {
    G4ExceptionDescription msg;
    msg << "Some of hits collections of this event not found." << G4endl; 
    G4Exception("EventAction::EndOfEventAction()",
		"Code001", JustWarning, msg);
    return;
  }   

  //20180117(start)
  CrystalCoverHitsCollection* CrystCoverHC 
    //20171023(finish)
    = static_cast<CrystalCoverHitsCollection*>(hce->GetHC(fCrystCoverHCID));
  if (!CrystCoverHC) {
    G4ExceptionDescription msg;
    msg << "Some of hits collections of this event not found." << G4endl; 
    G4Exception("EventAction::EndOfEventAction()",
		"Code001", JustWarning, msg);
    return;
  }   
  CrystalFrontCoverHitsCollection* CrystFrontCoverHC 
    //20171023(finish)
    = static_cast<CrystalFrontCoverHitsCollection*>(hce->GetHC(fCrystFrontCoverHCID));
  if (!CrystFrontCoverHC) {
    G4ExceptionDescription msg;
    msg << "Some of hits collections of this event not found." << G4endl; 
    G4Exception("EventAction::EndOfEventAction()",
		"Code001", JustWarning, msg);
    return;
  }   
  PMTcoverHitsCollection* PMTcoverHC 
    //20171023(finish)
    = static_cast<PMTcoverHitsCollection*>(hce->GetHC(fPMTcoverHCID));
  if (!PMTcoverHC) {
    G4ExceptionDescription msg;
    msg << "Some of hits collections of this event not found." << G4endl; 
    G4Exception("EventAction::EndOfEventAction()",
		"Code001", JustWarning, msg);
    return;
  }   
  //20180117(finish)

  // HCEnergy
  for (G4int i=0;i<1116;i++)
    {
      B5HadCalorimeterHit* hit = (*hcHC)[i];
      G4double eDep = hit->GetEdep();//total energy deposition of each crystals
      G4int PID = hit->GetPID();

      // if(eDep != 0){//20180116 do not use this!!
      // SetEnrgyandPID must be done for all 1116 crystals.
      // If not, the edep from last events with edep>0 will be stored again. 
      fHadCalEdep[i] = eDep;
      fPID[i] = PID;
      // fHistoManager->SetEnergyandPID( i, fPID[i], fHadCalEdep[i]);
      // }

      //20180117(start)
      CrystalCoverHit* CChit = (*CrystCoverHC)[i];
      CrystalFrontCoverHit* CFChit = (*CrystFrontCoverHC)[i];
      PMTcoverHit* PMTChit = (*PMTcoverHC)[i];
      G4double sc = hit->GetOPInt_sc();
      G4double ce = hit->GetOPInt_ce();
      fOP_sc[i] = sc;
      fOP_ce[i] = ce;

      //No. of OP reflected at the side of the crystal wrapper.
      G4int CrystalCoverOP = CChit->GetOPInt();  
      fCrystCoverOP[i] = CrystalCoverOP;
      //No. of OP reflected at the front of the crystal wrapper
      G4int CrystalFrontCoverOP = CFChit->GetOPInt();  
      fCrystFrontCoverOP[i] = CrystalFrontCoverOP;
      //No. of OP arrived at the PMT cover
      G4int PMTcoverOP = PMTChit->GetOPInt();  
      fPMTcoverOP[i] = PMTcoverOP;

      //20180621(start)
      G4double CrystFrontCoverEdep = CFChit->GetEdep();
      fCrystFrontCoverEdep[i] = CrystFrontCoverEdep;
      G4ThreeVector CrystFrontCoverPos = CFChit->GetPos();
      fCrystFrontCoverPos[i] = CrystFrontCoverPos;
      G4int CrystFrontCoverPID = CFChit->GetPID();
      fCrystFrontCoverPID[i] = CrystFrontCoverPID;
      //      if(CrystFrontCoverEdep>0) G4cout<<CrystFrontCoverEdep<<G4endl;
      //20180621(finish)

      //20180621(start)
      fHistoManager->SetFluxCrystFrontCoverPerStep(i, fCrystFrontCoverPID[i], fCrystFrontCoverEdep[i], fCrystFrontCoverPos[i]);
      //20180621(finish)

      //20180425(start)
      //      fHistoManager->SetEnergyandPID( i, fPID[i], fHadCalEdep[i], fOP_sc[i], fOP_ce[i], fCrystCoverOP[i], fCrystFrontCoverOP[i], fPMTcoverOP[i]);
      //20180117(finish)
      fRunAct->AddEdepPerEvent( i, fPID[i], fHadCalEdep[i], fOP_sc[i], fOP_ce[i], fCrystCoverOP[i], fCrystFrontCoverOP[i], fPMTcoverOP[i]);
      //20180425(finish)
    }
  
  //20180425(start)
  //delete
  /*
  //20171127(start)
  // Get hits collections
  //cc-in2p3 does not understand(or geant4.10.02.0 does not understand) "auto" 
  //  auto hcHC 
  FluxHitsCollection* fluxHC 
  = static_cast<FluxHitsCollection*>(hce->GetHC(fFlxHCID));
  if (!fluxHC) {
  G4ExceptionDescription msg;
  msg << "Some of hits collections of this event not found." << G4endl; 
  G4Exception("EventAction::EndOfEventAction()",
  "Code001", JustWarning, msg);
  return;
  }   
  FluxHit* fluxhit = (*fluxHC)[0];
  G4double energy = fluxhit->GetEdep();//energy of the particle passing through the volume
  G4int fluxPID = fluxhit->GetPID();
  G4ThreeVector position = fluxhit->GetPos();
  //  if(energy != 0){
  fFluxEnergy = energy;
  fFluxPID = fluxPID;
  fPos = position;
  //20171129(start)
  //    fHistoManager->SetFluxEnergyandPID( fFluxPID, fFluxEnergy, fPos);
  //20171129(finish)
  // }
  //20171127(finish) 

  //20171129(start)
  // Get hits collections
  //cc-in2p3 does not understand(or geant4.10.02.0 does not understand) "auto" 
  //  auto hcHC 
  ChambWindHitsCollection* chambwindHC 
  = static_cast<ChambWindHitsCollection*>(hce->GetHC(fChambWindHCID));
  if (!chambwindHC) {
  G4ExceptionDescription msg;
  msg << "Some of hits collections of this event not found." << G4endl; 
  G4Exception("EventAction::EndOfEventAction()",
  "Code001", JustWarning, msg);
  return;
  }   
  ChambWindHit* chambwindHit = (*chambwindHC)[0];
  G4double chambwind_energy = chambwindHit->GetEdep();//energy of the particle passing through the volume
  G4int chambwind_PID = chambwindHit->GetPID();
  G4ThreeVector chambwind_position = chambwindHit->GetPos();
  //  if(chambwind_energy != 0){
  fChambWindEnergy = chambwind_energy;
  fChambWindPID = chambwind_PID;
  fChambWindPos = chambwind_position;
  fHistoManager->SetFluxEnergyandPID( fFluxPID, fFluxEnergy, fPos, fChambWindPID, fChambWindEnergy, fChambWindPos);
  // }
  //20171129(finish) 
  */
  //20180425(finish)

  //20180425(start)
  //moved to RunAction.cc
  //  fHistoManager->FillNtuple();
  //20180425(finish)

  //20180621(start)
  fHistoManager->FillNtuple2();
  //20180621(start)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
