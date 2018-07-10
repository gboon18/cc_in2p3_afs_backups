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
//
// $Id: HistoManager.hh 92322 2015-08-27 14:54:05Z gcosmo $
// GEANT4 tag $Name: geant4-09-04 $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

//20171127(start)
#include "G4ThreeVector.hh"
//20171127(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class TFile;
class TTree;
class TH1D;

const G4int MaxHisto = 4;
const G4int MaxNtuple = 1116;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class HistoManager
{
public:
  HistoManager();
  ~HistoManager();
   
  //20171201(start)
  //  void Book();
  void Book(G4String);
  //20171201(finish)

  //20171013(start)
  //20171017(start) 
  void FillNtuple();
  void Save();
  //20180209(start)
  void SetPrimaryParticle(G4double, G4int, G4ThreeVector, G4ThreeVector, G4double);
  //20180209(finish)
  void SetEnergyandPID(G4int , G4int, G4double, G4int, G4int, G4int, G4int, G4int);//20171017//20180117
  //20171017(finish)
  //20171013(finish)

  //20171020(start)
  void SetOP(G4int , G4int );//20171017
  //20171020(finish)
  void PrintStatistic();
        
private:
  TFile*   fRootFile;
  TTree*   fNtuple;
  //  G4double fEdep[MaxNtuple+1];
  G4double fEdep[MaxNtuple];
  //20171124(start)
  G4int    fPID[MaxNtuple];
  //20171124(finish)
  //20180117(start)
  G4int    fOP_sc[MaxNtuple];
  G4int    fOP_ce[MaxNtuple];
  G4int    fOP_cover[MaxNtuple];
  G4int    fOP_frontcover[MaxNtuple];
  G4int    fOP_pmtcover[MaxNtuple];
  //20180117(finish)

  //20180209(start)
  G4double fPrimaryTime;
  G4int fPrimaryPID;
  G4double fPrimaryPos[3];
  G4double fPrimaryMom[3];
  G4double fPrimaryEnergy;
  //20180209(finish)

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

