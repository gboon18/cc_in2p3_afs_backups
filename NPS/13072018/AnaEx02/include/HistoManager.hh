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
/// \file analysis/AnaEx02/include/HistoManager.hh
/// \brief Definition of the HistoManager class
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
  //  void FillNtuple2(G4int id, G4double edep);
  void FillNtuple();
  //20180622(start)
  void FillNtuple2();
  //20180622(finish)
  void Save();
  void SetEnergyandPID(G4int , G4int, G4double, G4int, G4int, G4int, G4int, G4int);//20171017/20180117
  //20180622(start)
  void SetFluxEnergyandPID(G4int , G4int, G4double);
  //20180622(finish)
  //20180713(start)
  void SetFluxSphereEnergyandPID(G4int , G4double, G4ThreeVector);
  //20180713(finish)
  //  void SetFluxEnergyandPID(G4int, G4double, G4ThreeVector);//20171127
  //  void SetFluxEnergyandPID(G4int, G4double, G4ThreeVector, G4int, G4double, G4ThreeVector);//20171129
  //20171017(finish)
  //20171013(finish)

  //20171020(start)
  void SetOP(G4int , G4int );//20171017
  //20171020(finish)
  void PrintStatistic();
        
private:
  TFile*   fRootFile;
  TTree*   fNtuple;
  //20180622(start)
  TTree*   fNtuple2;
  //20180622(finish)
  //20180713(start)
  TTree*   fNtuple3;
  //20180713(finish)
  //20171127(start)
  //  TTree*   fNtuple2;//20180425 deleted
  //20171127(finish)
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
  //20180425(start)

  //20180622(start)
  G4double fFluxEne[MaxNtuple];
  G4int fFluxPID[MaxNtuple];
  //20180622(finish)

  //delete
  //20180713(start) reuse for Pseudo Sphere   
 
  //20171127(start)
  G4double fFluxEnergy;
  G4int    fFluxPID2;
  //G4ThreeVector fPos;
  G4double fPos_x; 
  G4double fPos_y; 
  G4double fPos_z; 
  //20180713(finish)
  /* 
  //20171127(finish)
  //20171129(start)
  G4double fChambWindEnergy;
  G4int    fChambWindPID;
  G4double fChambWindPos_x; 
  G4double fChambWindPos_y; 
  G4double fChambWindPos_z; 
 //20171129(finish)
 */
  //20180425(finish)
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

