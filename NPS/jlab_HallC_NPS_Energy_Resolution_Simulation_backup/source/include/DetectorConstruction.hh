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
/// \file radioactivedecay/rdecay02/include/DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
// $Id: DetectorConstruction.hh 66586 2012-12-21 10:48:39Z ihrivnac $
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"


//20171123(start)
#include "G4SystemOfUnits.hh"//to use cm
//20171123(finish)

class G4LogicalVolume;
class G4Material;
class DetectorMessenger;
//20171009(start)
class SensitiveDetector;
//20171009(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  //20180118(start)
  //  DetectorConstruction();
  DetectorConstruction(G4double );
  //20180117(finish)
  ~DetectorConstruction();

public:
  
  virtual G4VPhysicalVolume* Construct();
    
  //20171009
  virtual void ConstructSDandField();
  //20171009

  //20180117(start)
  void SetDetectorGap(G4double value);  
  //20180117(finish)

  void PrintParameters();
 
private:
  //20171122(start)
  const G4double     inch = 2.54*cm;
  G4Material*        fVacuumMater;
  //20171122(finish)

  G4double           fDetectorLength;
  G4double           fDetectorThickness;
  G4Material*        fDetectorMater;
  G4LogicalVolume*   fLogicDetector;

  //20171010(start)
  G4LogicalVolume*   fLogicCrystal;//in order to call from ConstructSDandField
  //20171010(finish)

  //20180117(start)
  G4LogicalVolume*   fLogicPMT;
  G4LogicalVolume*   fLogicWrap;
  G4LogicalVolume*   fLogicPMTcover;
  G4LogicalVolume*   fLogicWrapFront;
  G4Material*        fPMTmater;
  G4Material*        fWrapMater;
  G4Material*        fPMTcoverMater;
  //20170117(finish)

  //20180222(start)
  G4Material* fFrameMater;
  //20180222(finish)

  //20171006 added new world box
  G4double           fWorld_X;
  G4double           fWorld_Y;
  G4double           fWorld_Z;
  //20171006
  //20171006 added
  G4double             fMom_X;//mother volume#1(contains temp control box, detector, support frames)
  G4double             fMom_Y;
  G4double             fMom_Z;
  G4double             fMom_pos_X;//mother volume#1 position(to move it freely)
  G4double             fMom_pos_Y;
  G4double             fMom_pos_Z;

  //20171121(start)
  G4double             fMom_theta;
  //20171121(finish)

  G4double             fTemp_X;//temp control box(mother volume#2)(contains detectors)
  G4double             fTemp_Y;//temp control box(mother volume#2)(contains detectors)
  G4double             fTemp_Z;//temp control box(mother volume#2)(contains detectors)
  G4double             fTemp_pos_X;//temp control box position inside mother volume#1
  G4double             fTemp_pos_Y;//temp control box position inside mother volume#1
  G4double             fTemp_pos_Z;//temp control box position inside mother volume#1

  G4double             fNPS_X;
  G4double             fNPS_Y;
  G4double             fNPS_Z;
  G4double             fNPS_pos_X;
  G4double             fNPS_pos_Y;
  G4double             fNPS_pos_Z;

  G4double             fBulk_X;
  G4double             fBulk_Y;
  G4double             fBulk_Z;

  G4double             fSingle_X;
  G4double             fSingle_Y;
  G4double             fSingle_Z;

  G4double             gap;

  G4double             fCrystal_X;//PbWO4
  G4double             fCrystal_Y;//PbWO4
  G4double             fCrystal_Z;//PbWO4
  G4double             fCrystal_pos_X;//In case there will be PMT someday, 
  G4double             fCrystal_pos_Y;//In case there will be PMT someday, 
  G4double             fCrystal_pos_Z;//In case there will be PMT someday, 

  //20180117(start)
  G4double             fWrapThickness;
  G4double             fPMTcoverThickness;
  //20180117(finish)

  G4double             fPMT_X;
  G4double             fPMT_Y;
  G4double             fPMT_Z;
  G4double             fPMT_pos_X;
  G4double             fPMT_pos_Y;
  G4double             fPMT_pos_Z;
  //20171006

  G4Material*          fWorldMater;     
  G4VPhysicalVolume*   fPhysiWorld;
                
  DetectorMessenger*   fDetectorMessenger;


private:
    
  void               DefineMaterials();
  G4VPhysicalVolume* ConstructVolumes();     
  G4bool fCheckOverlaps; //20171009 added

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif

