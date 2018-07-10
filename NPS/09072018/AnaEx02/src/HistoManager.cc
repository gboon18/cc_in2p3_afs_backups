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
/// \file analysis/AnaEx02/src/HistoManager.cc
/// \brief Implementation of the HistoManager class
//
// $Id: HistoManager.cc 92374 2015-08-31 08:52:09Z gcosmo $
// GEANT4 tag $Name: geant4-09-04 $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
#include <CLHEP/Units/SystemOfUnits.h>

#include "HistoManager.hh"
#include "G4UnitsTable.hh"

//20171127(start)
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
//20171127(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::HistoManager()
  :fRootFile(0),
   //20171127(start)
   fNtuple(0),
   //20180425(start)

   //20180622(start)
   fNtuple2(0)
   //20180622(finish)

   //delete
   /*
   fNtuple2(0),
   fFluxEnergy(-999.),
   fFluxPID(-999),
   fPos_x(-999.), 
   fPos_y(-999.), 
   fPos_z(-999.), 
   //20171127(finish)
   //20171129(start)
   fChambWindEnergy(-999.),
   fChambWindPID(-999),
   fChambWindPos_x(-999.), 
   fChambWindPos_y(-999.), 
   fChambWindPos_z(-999.) 
   //20171129(finish)
   */
   //20180425(finish)
{
  fEdep[MaxNtuple] = {0.};
  fPID[MaxNtuple] = {0};
  fOP_sc[MaxNtuple] = {0};
  fOP_ce[MaxNtuple] = {0};
  fOP_cover[MaxNtuple] = {0};
  fOP_frontcover[MaxNtuple] = {0};
  fOP_pmtcover[MaxNtuple] = {0};

  //20180622(start)
  fFluxEne[MaxNtuple] = {0.};
  fFluxPID[MaxNtuple] = {0};
  //20180622(finish)
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::~HistoManager()
{
  if (fRootFile) delete fRootFile;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//20171201(start)
//void HistoManager::Book()
void HistoManager::Book(G4String fileName)
//20171201(finish)
{ 
  // Creating a tree container to handle histograms and ntuples.
  // This tree is associated to an output file.
  //
  // G4String fileName = "AnaEx02_20171130_mapmagon_2.root";
  fRootFile = new TFile(fileName,"RECREATE");
  if (! fRootFile) {
    G4cout << " HistoManager::Book :" 
           << " problem creating the ROOT TFile "
           << G4endl;
    return;
  }
  
  fNtuple = new TTree("t","Energy deposition and OP in crystas");
  fNtuple->Branch("edep", fEdep, "energy_deposition[1116]/D");//20171017(changed from"energy_deposition[1116]/F"<--does not work!!!)
  // fNtuple->Branch("pid", fPID, "PID[1116]/I");

  //20180425(start)
  //temporarily disabled, no op physics
  // //20180117(start)
  // fNtuple->Branch("sc", fOP_sc, "scintillated OP[1116]/I");
  // fNtuple->Branch("ce", fOP_ce, "cerenkov OP[1116]/I");
  // fNtuple->Branch("op_cover", fOP_cover, "OP on the side of the crystal wrapper[1116]/I");
  // fNtuple->Branch("op_frontcover", fOP_frontcover, "OP on the front side of the crystal wrapper[1116]/I");
  // fNtuple->Branch("op_pc", fOP_pmtcover, "OP arrived at the pmt cover[1116]/I");
  // //20180117(finish)
  //20180425(finish)

  //20180622(start)
  fNtuple2 = new TTree("t2","Checking the flux at the Crystal front face of the NPS");
  fNtuple2->Branch("ene", fFluxEne, "Energy of the flux in Crystal's front face[1116]/D");
  fNtuple2->Branch("pid", fFluxPID, "PID of the flux in Crystal's front face[1116]/I");
  //20180622(finish)

  //20180425(start)
  //delete
  /*
    //20171127(start)
  fNtuple2 = new TTree("t2","Checking the flux at the front face of the NPS");
  fNtuple2->Branch("fluxEnergy", &fFluxEnergy, "Energy of the flux in psuedo volume/D");
  fNtuple2->Branch("fluxPID", &fFluxPID, "PID of the flux in psuedo volume/I");
  fNtuple2->Branch("x", &fPos_x, "Position(x) of the flux in psuedo volume/D");
  fNtuple2->Branch("y", &fPos_y, "Position(y) of the flux in psuedo volume/D");
  fNtuple2->Branch("z", &fPos_z, "Position(z) of the flux in psuedo volume/D");
  //20171127(finish)
  //20171129(start)
  fNtuple2->Branch("ChambWindEnergy", &fChambWindEnergy, "Energy of the flux in chamber window/D");
  fNtuple2->Branch("ChambWindPID", &fChambWindPID, "PID of the flux in flux in chamber window/I");
  fNtuple2->Branch("chambx", &fChambWindPos_x, "Position(x) of the flux in flux in chamber window/D");
  fNtuple2->Branch("chamby", &fChambWindPos_y, "Position(y) of the flux in flux in chamber window/D");
  fNtuple2->Branch("chambz", &fChambWindPos_z, "Position(z) of the flux in flux in chamber window/D");
  //20171129(finish)
  */
  //20180425(finish)
  G4cout << "\n----> Output file is open in " << fileName << G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::FillNtuple()
{
  //  G4cout<<"Getting Called, FillNtuple"<<G4endl;
  //  G4cout<<"filling"<<G4endl;
  fNtuple->Fill();//20171127(temp)
  //  fNtuple2->Fill();
}
//20171013(finish)
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//20180622(start)
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::FillNtuple2()
{
  //   G4cout<<"filling"<<G4endl;
  fNtuple2->Fill();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//20180622(finish)

void HistoManager::Save()
{ 
  if (! fRootFile) return;
  fRootFile->Write();       // Writing the histograms to the file
  fRootFile->Close();       // and closing the tree (and the file)
  
  G4cout << "\n----> Histograms and ntuples are saved\n" << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//20171017(start)
void HistoManager::SetEnergyandPID(G4int id, G4int PID, G4double edep, G4int sc, G4int ce, G4int opc, G4int opfc, G4int oppc)
{
  //  G4cout<<"Getting Called, SetEnergyandPID, "<<id<<G4endl;
  if(edep) fEdep[id] = edep;
  //  if(fEdep[id])G4cout<<"Getting fEdep[id] : "<<fEdep[id]<<"["<<id<<"]"<<G4endl;
  //  if(edep) G4cout<<id<<", "<<fEdep[id]<<G4endl;

  //20180425(start)
  /*
  //temporarily disabled. no op physics
  fPID[id] = PID;

  //20180117(start)
  fOP_sc[id] = sc;
  fOP_ce[id] = ce;
  fOP_cover[id] = opc;
  fOP_frontcover[id] = opfc;
  fOP_pmtcover[id] = oppc;
  //20180117(finish)
  */
  //20180425(finish)
}
//20171017(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//20180622(start)
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HistoManager::SetFluxEnergyandPID(G4int id, G4int PID, G4double ene)
{

  //20180704(start)//need to initialize!!
  for(int i = 0 ; i < MaxNtuple ; i++){fFluxPID[i] = 0; fFluxEne[i] = 0.;}
  //20180704(finish)
  fFluxPID[id] = PID;
  fFluxEne[id] = ene;
  // G4cout<<"HistoManager, "<<fFluxEne[id]<<"["<<id<<"]"<<G4endl;

}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//20180622(finish)

//20180425(start)
//delete(finish)
/*
//20171127(start)
//void HistoManager::SetFluxEnergyandPID(G4int FluxPID, G4double energy, G4ThreeVector position)
//20171129(start)
void HistoManager::SetFluxEnergyandPID(G4int FluxPID, G4double energy, G4ThreeVector position, G4int ChambWindPID, G4double ChambWindenergy, G4ThreeVector ChambWindposition)
//20171129(finish)
{

  G4double fMom_theta = 8.93*pi/180.;
  G4double fCrystal_Z = 20.5*mm; 
  G4double fSingle_Z = fCrystal_Z;//+fPMT_Z;// later day
  G4double fBulk_Z = fSingle_Z;
  G4double fNPS_Z = fBulk_Z;
  G4double fMom_Z = 794*mm;
  G4double fMom_pos_Z = 4000*mm - 0.5*fMom_Z + 0.5*fCrystal_Z;//front face of the NPS is 4m from the target
  G4double fFlux_Z = 65*1e-3*mm;
  G4double fPseudo_pos_Z = (fMom_pos_Z-0.5*(fFlux_Z + fNPS_Z))*cos(fMom_theta);
  G4double fPseudo_pos_X = (fMom_pos_Z-0.5*(fFlux_Z + fNPS_Z))*sin(fMom_theta);
*/
// G4double fRel_pos_Z_1 = position.z() - fPseudo_pos_Z;//*cos(fMom_theta);
// G4double fRel_pos_X_1 = position.x() - fPseudo_pos_X;//*sin(fMom_theta);
/*
  G4double fRel_pos_Z = fRel_pos_Z_1*cos(fMom_theta) + fRel_pos_X_1*sin(fMom_theta);
  G4double fRel_pos_X = fRel_pos_X_1*cos(fMom_theta) - fRel_pos_Z_1*sin(fMom_theta);
  //  if(energy!=0){
  fFluxEnergy = energy;
  fFluxPID = FluxPID;
  fPos_x = fRel_pos_X;
  fPos_y = position.y();
  fPos_z = fRel_pos_Z;
  //  }

  //20171129(start)
  fChambWindEnergy = ChambWindenergy;
  fChambWindPID = ChambWindPID;
  fChambWindPos_x = ChambWindposition.x();
  fChambWindPos_y = ChambWindposition.y();
  fChambWindPos_z = ChambWindposition.z();
  //20171129(finish)


}
//20171127(finish)
*/
//20180425(finish)
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
