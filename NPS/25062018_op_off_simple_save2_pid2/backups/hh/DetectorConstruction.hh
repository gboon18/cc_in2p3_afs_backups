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
//20171009(start)
#include "G4FieldManager.hh"
//20171009(finish)

//20171114(start)
#include "SimpleField.hh"
//20171114(finish)

class G4LogicalVolume;
class G4Material;
class DetectorMessenger;
//20171009(start)
class B5MagneticField;
class SensitiveDetector;
//20171009(finish)

//20171114(start)
class G4Mag_UsualEqRhs;
class G4MagIntegratorStepper;
class G4ChordFinder;
//20171114(finish)

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  
  DetectorConstruction();
  ~DetectorConstruction();

public:
  
  virtual G4VPhysicalVolume* Construct();
    
  //20171009
  virtual void ConstructSDandField();
  //20171009

  void SetTargetLength (G4double value);
  void SetTargetRadius (G4double value);
  void SetTargetMaterial (G4String);
    
  void SetDetectorLength(G4double value);           
  void SetDetectorThickness(G4double value);  
  void SetDetectorMaterial(G4String);               
  //20171114(start)
  //  void ConstructField();    
  //20171114(finish)
 
  void PrintParameters();
 
public:
      
  G4double GetTargetLength();
  G4double GetTargetRadius();
  G4Material* GetTargetMaterial();       
  G4LogicalVolume* GetLogicTarget();
    
  G4double GetDetectorLength();
  G4double GetDetectorThickness();
  G4Material* GetDetectorMaterial();                 
  G4LogicalVolume* GetLogicDetector();      
                       
private:
  
  G4double           fTargetLength; 
  G4double           fTargetRadius;
  G4double           fTargetCoverLength; 
  G4double           fTargetCoverRadius;
  G4double           fTargetWindowThickness;
  G4Material*        fTargetMater;
  G4LogicalVolume*   fLogicTarget;
  //20171006(start)
  G4Material*        fTargetCoverMater;
  G4LogicalVolume*   fLogicTargetCover;
  //20171006(finish)                 

  G4double           fDetectorLength;
  G4double           fDetectorThickness;
  G4Material*        fDetectorMater;
  G4LogicalVolume*   fLogicDetector;

  //20171010(start)
  G4LogicalVolume*   fLogicCrystal;//in order to call from ConstructSDandField
  G4LogicalVolume*   fLogicalMagnetic;//in order to call from ConstructSDandField//for the magnetic field in certain volume. can be used someday
  //20171010(finish)

  //20171114(start)
  G4LogicalVolume* logicEnv;
  G4double      env_size[3];
  G4Material*   env_material;
  G4Material*   coil_material;
  G4Material*   core_material;
  G4Material*   coilinsert_material;
  G4Material*   concrete_shield;
  //  beamline_material = nist->FindOrBuildMaterial("G4_Fe");
  G4Material*   radiator_material;
  SimpleField *fField;
G4Mag_UsualEqRhs *fEquation;
   G4MagIntegratorStepper* fStepper;
G4ChordFinder*          fChordFinder;
  //20171114(finish)


 /*20171006 deleted for new world box               
    G4double           fWorldLength;
    G4double           fWorldRadius;
  */
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

  G4double             fPMT_X;
  G4double             fPMT_Y;
  G4double             fPMT_Z;
  G4double             fPMT_pos_X;
  G4double             fPMT_pos_Y;
  G4double             fPMT_pos_Z;
  //20171006
  //20171121(start)
  G4double             fSweepingMagnet_X;
  G4double             fSweepingMagnet_Y;
  G4double             fSweepingMagnet_Z;
  G4double             fSweepingMagnet_pos_Z;
  G4double             fSweepingMagnet_theta;
  //20171121(finish)
  G4Material*          fWorldMater;     
  G4VPhysicalVolume*   fPhysiWorld;
                
  DetectorMessenger*   fDetectorMessenger;


  //20171009(start)
  static G4ThreadLocal B5MagneticField* fMagneticField;
  static G4ThreadLocal G4FieldManager* fFieldMgr;
  //20171009(finish)

private:
    
  void               DefineMaterials();
  G4VPhysicalVolume* ConstructVolumes();     
  G4bool fCheckOverlaps; //20171009 added

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif

