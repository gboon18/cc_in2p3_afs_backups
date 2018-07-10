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
/// \file analysis/AnaEx02/AnaEx02.cc
/// \brief Main program of the analysis/AnaEx02 example
//
//
// $Id: AnaEx02.cc 81444 2014-05-28 14:28:20Z gcosmo $
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*
//20171013(start)
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
//20171013(finish)
*/
#include "G4RunManager.hh"
#include "G4UImanager.hh"
//20171016(start)
//20171123(start)
//#include "dvcsPhysicsList.hh"
#include "PhysicsList.hh"
//20171123(finish)
//#include "FTFP_BERT.hh"
//20171016(finish)

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "HistoManager.hh"

//20171019(start)
#include <ctime>//for cout time
//20171019(finish)

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{ 
  
  //20171019(start) 
  // current date/time based on current system
  time_t now = time(0);
  //20171019(finish) 

  /*
  //20171013(start)
  // Construct the default run manager
  #ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  G4int nThreads = G4Threading::G4GetNumberOfCores();
  if (argc==3) nThreads = G4UIcommand::ConvertToInt(argv[2]);
  runManager->SetNumberOfThreads(nThreads);
  #else
  G4RunManager* runManager = new G4RunManager;
  #endif
  //20171013(finish)
  */

  //20180129(start)
  // Choose the Random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);
  //20180129(finish)

  G4RunManager* runManager = new G4RunManager;
  // Set mandatory initialization classes
  //
  //20180118(start)
  G4double gap;
  G4double NPS_distance;
  G4double NPS_angle;
  G4bool field;
  G4cout<<"Size of the gap between the crystals(mm)?"<<G4endl;
  G4cin>>gap;
  G4cout<<"Distance of the NPS from the target?(mm)"<<G4endl;
  G4cin>>NPS_distance;
  G4cout<<"Anlge of the NPS from the beam line?(deg)"<<G4endl;
  G4cin>>NPS_angle;
  G4cout<<"Sweeping Magnetic Field On? Off? (On : 1(true), Off : 0(false))"<<G4endl;
  G4cin>>field;
  DetectorConstruction* detector = new DetectorConstruction(gap, NPS_distance, NPS_angle, field);
  //  DetectorConstruction* detector = new DetectorConstruction();
  runManager->SetUserInitialization(detector);
  //20180118(finish)
  //
  //20171016(start)
  //runManager->SetUserInitialization(new FTFP_BERT);
//20171123(start) 
 PhysicsList* phys = new PhysicsList;
//dvcsPhysicsList* phys = new dvcsPhysicsList;
  runManager->SetUserInitialization(phys);          
//20171123(finish)
  //20171016(finish)
  // set an HistoManager
  //
  HistoManager*  histo = new HistoManager();
      
  // Set user action classes
  //
  //20171013(start)
  /*
    PrimaryGeneratorAction* gen_action = 
    new PrimaryGeneratorAction(detector);
  */ 
  PrimaryGeneratorAction* gen_action = 
    new PrimaryGeneratorAction();
  runManager->SetUserAction(gen_action);
  //
  //20171013(finish)

//20171201(start)
  G4String fileNamee;
  G4cout<<"Name of the output file?"<<G4endl;
  G4cin>>fileNamee;
  //20180129(start)
  long seed1, seed2;
  G4cout<<"seed1?"<<G4endl;
  G4cin>>seed1;
  G4cout<<"seed2?"<<G4endl;
  G4cin>>seed2;
  //  RunAction* run_action = new RunAction(histo, fileNamee);  
  RunAction* run_action = new RunAction(histo, fileNamee, seed1, seed2);  
  //20180129(finish)
  runManager->SetUserAction(run_action);
//20171201(finish)

  //
  /*
  RunAction* run_action = new RunAction(histo);  
  runManager->SetUserAction(run_action);
  */
  //
  EventAction* event_action = new EventAction(run_action,histo);
  runManager->SetUserAction(event_action);
  //
  SteppingAction* stepping_action =
    new SteppingAction(detector, event_action);
  runManager->SetUserAction(stepping_action);
  
  // Initialize G4 kernel
  //
  //20171019(start)
  //  runManager->Initialize();//in order to use "/testem/phys/addPhysics" command. Initialize in macro!
  //add physics process before initializing!!
  //20171019(finish)
  // Get the pointer to the User Interface manager
  //
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  
  if (argc!=1)   // batch mode
    {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);    
    }
  else
    {  // interactive mode : define visualization and UI terminal
#ifdef G4VIS_USE
      G4VisManager* visManager = new G4VisExecutive;
      visManager->Initialize();
#endif
#ifdef G4UI_USE
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
      ui->SessionStart();
      delete ui;
#endif

#ifdef G4VIS_USE
      delete visManager;
#endif
    }

  //20171019(start) 
  // current date/time based on current system
  time_t then = time(0);
  time_t diff = then - now;
  // convert now to string form
  char* dt = ctime(&diff);
  // convert now to tm struct for UTC
  tm* gmtm = gmtime(&diff);
  dt = asctime(gmtm);
  G4cout << "It took :"<< dt <<"for the job to be done." << G4endl;
  //20171019(finish) 

  // Job termination
  delete histo;                
  delete runManager;

  return 0;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
