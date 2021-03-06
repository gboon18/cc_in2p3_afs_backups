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
/// \file analysis/shared/include/RunAction.hh
/// \brief Definition of the RunAction class
//
//
// $Id: RunAction.hh 67226 2013-02-08 12:07:18Z ihrivnac $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;
class HistoManager;

//20180425(start)
//const G4int MaxNtuple = 1116;//already declared in EventAction.hh
//20180425(finish)

class RunAction : public G4UserRunAction
{
public:
  //20171201(start)
  //  RunAction(HistoManager*);
  //20180129(start)
  //  RunAction(HistoManager*, G4String);
  RunAction(HistoManager*, G4String, long, long);
  //20180129(finish)
  //20171201(finish)
  virtual ~RunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void   EndOfRunAction(const G4Run*);
    
  void fillPerEvent(G4double, G4double, G4double, G4double); 

  //20180425(start)
  void AddEdepPerEvent(G4int, G4int, G4double, G4int, G4int, G4int, G4int, G4int);
  //20180425(finish)

private:
  HistoManager* fHistoManager;

  //20171201(start)
  G4String fFileName;
  //20171201(finish)

  G4double fSumEAbs, fSum2EAbs;
  G4double fSumEGap, fSum2EGap;
    
  G4double fSumLAbs, fSum2LAbs;
  G4double fSumLGap, fSum2LGap;    

  //20180425(start)
  G4double fEdep[1116];
  G4int    fPID[1116];//this is dummy. Too lazy to change HistoManager::SetEnergyandPID
  G4int    fOP_sc[1116];
  G4int    fOP_ce[1116];
  G4int    fOP_cover[1116];
  G4int    fOP_frontcover[1116];
  G4int    fOP_pmtcover[1116];
  //20180425(finish)

  //20180129(start)
  long fSeed1, fSeed2;
  //20180129(finish)
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

