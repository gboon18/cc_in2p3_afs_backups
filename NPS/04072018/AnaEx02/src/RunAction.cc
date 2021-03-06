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
/// \file analysis/shared/src/RunAction.cc
/// \brief Implementation of the RunAction class
//
//
// $Id: RunAction.cc 92322 2015-08-27 14:54:05Z gcosmo $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "RunAction.hh"
#include "HistoManager.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//20171201(start)
//RunAction::RunAction(HistoManager* histo)
//20180129(start)
//RunAction::RunAction(HistoManager* histo, G4String fileName)
RunAction::RunAction(HistoManager* histo, G4String fileName, long i, long j)
  //20180129(finish)
  //20171201(finish)
  : G4UserRunAction(),
    fHistoManager(histo),
    //20171201(start) 
    fFileName(fileName),
    //20171201(finish)
    fSumEAbs(0.), fSum2EAbs(0.),
    fSumEGap(0.), fSum2EGap(0.),
    fSumLAbs(0.), fSum2LAbs(0.),
    fSumLGap(0.), fSum2LGap(0.),
    //20180129(start)
    fSeed1(i), fSeed2(j)
    //20180129(finish)    
{
  //20180425(start)
  fEdep[1116] = {0.};
  fPID[1116] = {0};//this is dummy. Too lazy to change HistoManager::SetEnergyandPID
  fOP_sc[1116] = {0};
  fOP_ce[1116] = {0};
  fOP_cover[1116] = {0};
  fOP_frontcover[1116] = {0};
  fOP_pmtcover[1116] = {0};
  //20180425(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{ 
  //20180129(start)  
  long seeds[2];
  seeds[0] = fSeed1;
  seeds[1] = fSeed2;
  G4Random::setTheSeeds(seeds);
  G4Random::showEngineStatus();
  //20180129(finish)

G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
    
  //initialize cumulative quantities
  //
  fSumEAbs = fSum2EAbs =fSumEGap = fSum2EGap = 0.;
  fSumLAbs = fSum2LAbs =fSumLGap = fSum2LGap = 0.;
  
  //histograms
  //
  //20171201(start)
  //  fHistoManager->Book(); 
  fHistoManager->Book(fFileName); 
  //20171201(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::fillPerEvent(G4double EAbs, G4double EGap,
                                  G4double LAbs, G4double LGap)
{
  //accumulate statistic
  //
  fSumEAbs += EAbs;  fSum2EAbs += EAbs*EAbs;
  fSumEGap += EGap;  fSum2EGap += EGap*EGap;
  
  fSumLAbs += LAbs;  fSum2LAbs += LAbs*LAbs;
  fSumLGap += LGap;  fSum2LGap += LGap*LGap;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//20180425(start)
void RunAction::AddEdepPerEvent(G4int id, G4int pid, G4double edep, G4int sc, G4int ce, G4int opc, G4int opfc, G4int oppc)
{

  //Add edep per each crystal for whole run (all the events)
  fEdep[id] += edep;
  // if(edep) G4cout<<"RunAction, Add all edep, "<<id<<", "<<edep<<G4endl;
  // if(edep) G4cout<<"RunAction, Added   edep, "<<id<<", "<<fEdep[id]<<G4endl;
  //  G4cout<<"RunAction, Add all edep, no if(edep), "<<id<<", "<<edep<<G4endl;
  /*
    fOP_sc[id] += sc;
    fOP_ce[id] += ce;
    fOP_cover[id] += opc;
    fOP_frontcover[id] += opfc;
    fOP_pmtcover[id] += oppc;
  */
}
//20180425(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  G4int NbOfEvents = aRun->GetNumberOfEvent();
  if (NbOfEvents == 0) return;
  
  //compute statistics: mean and rms
  //
  fSumEAbs /= NbOfEvents; fSum2EAbs /= NbOfEvents;
  G4double rmsEAbs = fSum2EAbs - fSumEAbs*fSumEAbs;
  if (rmsEAbs >0.) rmsEAbs = std::sqrt(rmsEAbs); else rmsEAbs = 0.;
  
  fSumEGap /= NbOfEvents; fSum2EGap /= NbOfEvents;
  G4double rmsEGap = fSum2EGap - fSumEGap*fSumEGap;
  if (rmsEGap >0.) rmsEGap = std::sqrt(rmsEGap); else rmsEGap = 0.;
  
  fSumLAbs /= NbOfEvents; fSum2LAbs /= NbOfEvents;
  G4double rmsLAbs = fSum2LAbs - fSumLAbs*fSumLAbs;
  if (rmsLAbs >0.) rmsLAbs = std::sqrt(rmsLAbs); else rmsLAbs = 0.;
  
  fSumLGap /= NbOfEvents; fSum2LGap /= NbOfEvents;
  G4double rmsLGap = fSum2LGap - fSumLGap*fSumLGap;
  if (rmsLGap >0.) rmsLGap = std::sqrt(rmsLGap); else rmsLGap = 0.;
  
  //print
  //
  G4cout
    << "\n--------------------End of Run------------------------------\n"
    << "\n mean Energy in Absorber : " << G4BestUnit(fSumEAbs,"Energy")
    << " +- "                          << G4BestUnit(rmsEAbs,"Energy")  
    << "\n mean Energy in Gap      : " << G4BestUnit(fSumEGap,"Energy")
    << " +- "                          << G4BestUnit(rmsEGap,"Energy")
    << G4endl;
     
  G4cout
    << "\n mean trackLength in Absorber : " << G4BestUnit(fSumLAbs,"Length")
    << " +- "                               << G4BestUnit(rmsLAbs,"Length")  
    << "\n mean trackLength in Gap      : " << G4BestUnit(fSumLGap,"Length")
    << " +- "                               << G4BestUnit(rmsLGap,"Length")
    << "\n------------------------------------------------------------\n"
    << G4endl;

  //20180425(start)
  for(G4int i  = 0 ; i < 1116 ; i++){
    //    if(fEdep[i]) G4cout<<i<<", "<<fEdep[i]<<G4endl;
    fHistoManager->SetEnergyandPID(i, fPID[i], fEdep[i], fOP_sc[i], fOP_ce[i], fOP_cover[i], fOP_frontcover[i], fOP_pmtcover[i]);
  }
  fHistoManager->FillNtuple();//moved from EventAction.cc
  //20180425(finish)
     
  //save histograms
  //
  //  fHistoManager->PrintStatistic();
  fHistoManager->Save();   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
