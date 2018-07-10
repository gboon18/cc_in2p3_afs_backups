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
/// \file hadronic/Hadr03/src/DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
// $Id: DetectorConstruction.cc 70755 2013-06-05 12:17:48Z ihrivnac $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

//20171009(start)
#include "G4SDManager.hh"
#include "B5HadCalorimeterSD.hh"
#include "G4AutoDelete.hh"
//20171009(finish)

#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

//20171006(start)
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4PVReplica.hh"
#include "G4VisAttributes.hh"//coloring
//20171006(finishi)

//20171123(start)
#include "G4SubtractionSolid.hh"
//#include "G4VSolid.hh"
//#include "G4Orb.hh"
//20171123(finish)

//20180117(start)
#include "CrystalCoverSD.hh"
#include "CrystalFrontCoverSD.hh"
#include "PMTcoverSD.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4OpticalSurface.hh"
//20180117(finish)


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//20180118(start)
//DetectorConstruction::DetectorConstruction()
DetectorConstruction::DetectorConstruction(G4double gap_input)
//20180118(start)
  :G4VUserDetectorConstruction(),
   //20171122(start)
   fVacuumMater(0),
   //20171122(finish)
  fDetectorMater(0), fLogicDetector(0),
//20171010(start)
  fLogicCrystal(0),
//20171010(finish) 

//20180117(start)
  fLogicPMT(0), fLogicWrap(0), fLogicPMTcover(0), fLogicWrapFront(0),
  fPMTmater(0), fWrapMater(0), fPMTcoverMater(0), 
//20180117(finish)

//20180222(start)
  fFrameMater(0),
//20180222(finish)

  fWorldMater(0), fPhysiWorld(0),
  fDetectorMessenger(0)
{
  fDetectorLength    = 5*cm; 
  fDetectorThickness = 2*cm;

  //20171006(start) added
  fWorld_X = 10*m;
  fWorld_Y = 10*m;
  fWorld_Z = 10*m;

//20180118(start)
  gap = gap_input*mm;
//20180118(finish)

  fCrystal_X = 20.5*mm;//PbWO4
  fCrystal_Y = 20.5*mm;//inside mother volume#5 with PMT
  fCrystal_Z = 200.5*mm;
  fCrystal_pos_X = 0*mm;//In case there will be PMT someday, 
  fCrystal_pos_Y = 0*mm;
  fCrystal_pos_Z = 0*mm;

  //20180117(start)
  fWrapThickness = 65*1e-3*mm;
  //  fPMTcoverThickness = 65*1e-3*mm;
  //20180117(finish)

  fMom_X = 2575*mm;//mother volume#1(contains temp control box, detector, support frames)
  //  fMom_X = 713.5*mm;//mother volume#1(contains temp control box, detector, support frames)
  fMom_Y = 2988*mm;
  fMom_Z = 794*mm;
  fMom_pos_X = 0*mm;//mother volume#1 position(to move it freely)
  fMom_pos_Y = 0*mm;
  //20180209(start)
  fMom_pos_Z = 4000*mm + 0.5*fSingle_Z;
  //20180209(finish)
  //now the front face wrapper of the crystal is located at 4mm fromt the center of the world.
//0.5*fCrystal_Z;// 0.5*200.5*mm;//positioning the NPS front face at 4m.

  //20171121(start)
  fMom_theta = -8.93*pi/180.;//-15.*pi/180.;//-8.93*pi/180.;//-7.93*pi/180.;
  //20171121(finish)

  fTemp_X = 1555*mm;//temp control box(mother volume#2)(contains detectors)
  //  fTemp_X = 713*mm;//temp control box(mother volume#2)(contains detectors)
  fTemp_Y = 1573*mm;//this is inside the mother volume#1
  fTemp_Z = 418*mm;
  fTemp_pos_X = 0*m;//temp control box position inside mother volume#1
  fTemp_pos_Y = 0*m;
  fTemp_pos_Z = 0*m;
  /*
    fNPS_X;//NPS inside mother volume#2(mother volume#3)
    fNPS_Y;
    fNPS_Z;
    fNPS_pos_X;//NPS position inside mother volume#2
    fNPS_pos_Y;
    fNPS_pos_Z;

    fBulk_X;//Singles combined into one column(total 31 columns)(mother volume#4)
    fBulk_Y;//inside mother volume#3
    fBulk_Z;

    fSingle_X;//Detector(mother volume#5)(contains crystal and pmt, shielding)
    fSingle_Y;//this is inside the mother volume#4
    fSingle_Z;
  */


  fPMT_X = 20.5*mm;//size of the PMT
  fPMT_Y = 20.5*mm;//inside mother volume#5 with Crystal
  fPMT_Z = 20.5*mm;
  //20171006(finish)

  DefineMaterials();
    
  fDetectorMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ delete fDetectorMessenger;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  return ConstructVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{
  // build materials
  //20171006(start)
  //  G4double a;  // atomic mass
  //  G4double z;  // atomic number
  G4double density, fractionmass;
  G4int ncomponents, natoms;

  G4NistManager* nist = G4NistManager::Instance();


  //World Material
  G4Element* N  = new G4Element("Nitrogen",  "N",   7, 14.01*g/mole);
  G4Element* O  = new G4Element("Oxygen",    "O",   8, 16.00*g/mole);
  //20171006(start)
  G4Element* Al  = new G4Element("Aluminium","Al", 13, 26.98*g/mole);
  //20171006(finish) 
  G4Material* Air20 = new G4Material("Air", 1.205*mg/cm3, ncomponents=2,
				     kStateGas, 293.*kelvin, 1.*atmosphere);
  Air20->AddElement(N, fractionmass=0.7);
  Air20->AddElement(O, fractionmass=0.3);
  //
  fWorldMater = Air20;

  //20171123(start)
  fVacuumMater = nist->FindOrBuildMaterial("G4_Galactic");//vacuum
  //20171123(finish)

  //Detector Material PbWO4
  G4Isotope *Pb204 = new G4Isotope("204Pb", 82, 204, 203.97*g/mole);
  G4Isotope *Pb206 = new G4Isotope("204Pb", 82, 206, 205.97*g/mole);
  G4Isotope *Pb207 = new G4Isotope("204Pb", 82, 207, 206.98*g/mole);
  G4Isotope *Pb208 = new G4Isotope("204Pb", 82, 208, 207.98*g/mole);
  G4Element* Pb = new G4Element("Plomo"    ,"Pb", 4); //Introducimos el plomo  
  Pb->AddIsotope(Pb204, 1.400*perCent);
  Pb->AddIsotope(Pb206, 24.100*perCent);
  Pb->AddIsotope(Pb207, 22.100*perCent);
  Pb->AddIsotope(Pb208, 52.400*perCent);

  G4Isotope *W180 = new G4Isotope("180W", 74, 180, 179.95*g/mole);
  G4Isotope *W182 = new G4Isotope("182W", 74, 182, 181.95*g/mole);
  G4Isotope *W183 = new G4Isotope("183W", 74, 183, 182.95*g/mole);
  G4Isotope *W184 = new G4Isotope("184W", 74, 184, 183.95*g/mole);
  G4Isotope *W186 = new G4Isotope("186W", 74, 186, 185.95*g/mole);
  G4Element* W  = new G4Element("Wolframio","W" , 5); //Introducimos el Wolframio
  W->AddIsotope(W180, 0.120*perCent);
  W->AddIsotope(W182, 26.500*perCent);
  W->AddIsotope(W183, 14.310*perCent);
  W->AddIsotope(W184, 30.640*perCent);
  W->AddIsotope(W186, 28.430*perCent);

  //  G4Material* PbWO4=//Material detector
  fDetectorMater = 
    new G4Material("PbWO4", density=8.3*g/cm3, ncomponents=3);
  fDetectorMater->AddElement(Pb, natoms=1);
  fDetectorMater->AddElement(W , natoms=1);
  fDetectorMater->AddElement(O , natoms=4);
  //20171006(finish)

  //20180117(start)
  G4Element* Si = new G4Element("Silicon", "Si", 14, 28.09*g/mole);
  fPMTmater = new G4Material("SiO2", 2.648*g/cm3, ncomponents=2);
  fPMTmater -> AddElement(Si, fractionmass = 1./3.);
  fPMTmater -> AddElement(O, fractionmass = 2./3.);

  G4Element* C  = new G4Element("Carbon",    "C",   6, 12.01*g/mole);
  G4Element* H  = new G4Element("Hydrogen",  "H",   1, 1.008*g/mole);
  fWrapMater = new G4Material("VM2000", 1.38*g/cm3, ncomponents=3);
  fWrapMater->AddElement(C, fractionmass=10./22.);
  fWrapMater->AddElement(H, fractionmass=8./22.);
  fWrapMater->AddElement(O, fractionmass=4./22.);

  fPMTcoverMater = new G4Material("Al_cover", 2.70*g/cm3, ncomponents=1);
  fPMTcoverMater -> AddElement(Al, fractionmass = 1.);
  //20180117(finish)

  //20180222(start)
  fFrameMater = new G4Material("Frame", 1.55*g/cm3, ncomponents=1);
  fFrameMater -> AddElement(C, fractionmass = 1.);
  //20180222(finish)

}

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::ConstructVolumes()
{

  //20180117(start)
  //
  //optical photons properties
  // 
  G4double hc = 1.23984193;
  
  const G4int n = 8;
  G4double OpticalPhotonWavelength[n] = //in micro meters
    { 0.400, 0.440, 0.480, 0.520, 0.560, 0.600, 0.640, 0.680};
  G4double OpticalPhotonEnergy[n] = {0.}; 
  for (G4int i = 0 ; i < n ; i++){
    OpticalPhotonEnergy[i] = (hc/OpticalPhotonWavelength[i])*eV;
  }

  //Refractive Index of Crystal
  G4double RefractiveIndexCrystal[n] = 
    { 2.35, 2.30, 2.27, 2.25, 2.23, 2.21, 2.201, 2.2}; 

  //Refractive Index of Air
  G4double RefractiveIndexAir[n] = 
    { 1., 1., 1., 1., 1., 1., 1., 1.};

  //Reflectivity. To be filled from down below
  G4double R[n] = {0.};

  //Theoretical Transmittance. To be filled from down below
  G4double Ts[n] = {0.};

  //Measured Transmittance(longitudinal)
  G4double T[n] = 
    { 0.33, 0.48, 0.62, 0.67, 0.68, 0.689, 0.69, 0.69};

  //Attenuation length
  G4double LAL[n] = {0.};


  for (G4int i = 0 ; i < n ; i++){
    R[i] = ((RefractiveIndexCrystal[i] - RefractiveIndexAir[i])*(RefractiveIndexCrystal[i] - RefractiveIndexAir[i]))/((RefractiveIndexCrystal[i] + RefractiveIndexAir[i])*(RefractiveIndexCrystal[i] + RefractiveIndexAir[i]));
    Ts[i] = (1 - R[i])/(1 + R[i]); 
    LAL[i] = fCrystal_Z/(log((T[i]*(1-Ts[i])*(1-Ts[i]))/(sqrt(4*Ts[i]*Ts[i]*Ts[i]*Ts[i] + T[i]*T[i]*(1-Ts[i]*Ts[i])*(1-Ts[i]*Ts[i]))-2*Ts[i]*Ts[i])));
    G4cout<<"n[i]"<<RefractiveIndexCrystal[i]<<"["<<i<<"], "<<"Wavelength[i] : "<<OpticalPhotonWavelength[i]<<"["<<i<<"], "<<"R[i] : "<<R[i]<<"["<<i<<"], "<<"T[i] : "<<T[i]<<"["<<i<<"], "<<"LAL[i] : "<<LAL[i]<<"["<<i<<"]"<<G4endl;  
  }

  G4double ScintilFast[n] =
    {10., 25., 45., 55., 40., 35., 20., 12.};

  G4MaterialPropertiesTable* CrystalOP = new G4MaterialPropertiesTable();
  CrystalOP->AddProperty("RINDEX",       OpticalPhotonEnergy, RefractiveIndexCrystal,n);
  CrystalOP->AddProperty("ABSLENGTH",    OpticalPhotonEnergy, LAL,     n);
  CrystalOP->AddProperty("FASTCOMPONENT",OpticalPhotonEnergy, ScintilFast,     n);

  //slow component is also filled with fast component?
  CrystalOP->AddProperty("SLOWCOMPONENT",OpticalPhotonEnergy, ScintilFast,     n);

  CrystalOP->AddConstProperty("SCINTILLATIONYIELD",0.455*0.5*3.34*15/MeV);//to make 15/MeV arrive at the PMT, I multiplied 3.34. 4490 arrived at the PMT for 1GeV particle when it was set to 15/MeV.
  //20180217 multiplied 0.455 more
  //19022018. It was over estimated. multiplied 0.5 to adjust the light collection in the PMT from ~30/MeV to ~15/MeV.
  CrystalOP->AddConstProperty("RESOLUTIONSCALE",1.0);  
  CrystalOP->AddConstProperty("FASTTIMECONSTANT", 13.26*ns);
  CrystalOP->AddConstProperty("SLOWTIMECONSTANT", 412.2*ns);
  CrystalOP->AddConstProperty("YIELDRATIO",0.85);
  CrystalOP->DumpTable();

  fDetectorMater->SetMaterialPropertiesTable(CrystalOP);

  G4double RefractiveIndexPMT[n] =
    {1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50};

  G4double AbsorptionPMT[n] =
    { 1.*m, 1.*m, 1.*m, 1.*m, 1.*m, 1.*m, 1.*m, 1.*m};
  
  G4MaterialPropertiesTable* pmtOP = new G4MaterialPropertiesTable();
  pmtOP->AddProperty("RINDEX",       OpticalPhotonEnergy, RefractiveIndexPMT,n);
  pmtOP->AddProperty("ABSLENGTH",    OpticalPhotonEnergy, AbsorptionPMT,     n);
  pmtOP->DumpTable();

  fPMTmater->SetMaterialPropertiesTable(pmtOP);
  //20180117(finish)

  // Cleanup old geometry
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();
  
  //20171006(start)
  //controlling the sizes  
  fSingle_X = fCrystal_X + 2*fWrapThickness + gap;
  fSingle_Y = fCrystal_Y + 2*fWrapThickness + gap;
  fSingle_Z = fCrystal_Z + fPMT_Z + fWrapThickness/* pmtcover thickness*/ + fWrapThickness;/* crystal wrapper thickness*/ // + /*20180222*/fWrapThickness

  fCrystal_pos_X = 0*mm;
  fCrystal_pos_Y = 0*mm;
  fCrystal_pos_Z = -(0.5*fSingle_Z - (0.5*fCrystal_Z + fWrapThickness));
  fPMT_pos_X = 0*mm;//position of the PMT inside mother volume#5(single)
  fPMT_pos_Y = 0*mm;
  fPMT_pos_Z = 0.5*fSingle_Z - (0.5*fPMT_Z + fWrapThickness/*pmt cover thickness*/);

  fBulk_X = fSingle_X;
  fBulk_Y = fSingle_Y*36;//36 singles combined into one column (totally, 31 of them exists)
  fBulk_Z = fSingle_Z;

  fNPS_X = fBulk_X*31;//now 31 of the colums become one
  fNPS_Y = fBulk_Y;
  fNPS_Z = fBulk_Z;
  //20171006(finish)

  //20180209(start)
  fMom_pos_Z = 4000*mm + 0.5*fSingle_Z;
  //20180209(finish)

  //20171027(start)
  fCheckOverlaps = true;//activate checing overlaps
  //20171027(finish)

  //20171006(start) new world box
  G4Box* sWorld =
    new G4Box("World_sol",0.5*fWorld_X, 0.5*fWorld_Y, 0.5*fWorld_Z); //its size
 			   
  G4LogicalVolume* lWorld =                         
    new G4LogicalVolume(sWorld,          //its solid
			fWorldMater,         //its material(air)
			"World_log");            //its name
                                   
  fPhysiWorld = 
    new G4PVPlacement(0,                     //no rotation
  		      G4ThreeVector(),       //at (0,0,0)
  		      lWorld,            //its logical volume
  		      "World_pos",               //its name
  		      0,                     //its mother  volume
  		      false,                 //no boolean operation
  		      0,                     //copy number
  		      fCheckOverlaps);       // checking overlaps 

  //20171006(finish)

  // Detector
  //
  //20171006(start)
  //Mother Volume #1 : to contain NPS and its temp control box. To move & rotate it freely.
  G4Box*
    sMother = new G4Box("Mother_sol", 0.5*fMom_X, 0.5*fMom_Y, 0.5*fMom_Z);

  G4LogicalVolume* lMother = new G4LogicalVolume(sMother,
						 fWorldMater,//air
						 "Mother_log");

  G4RotationMatrix *yMomRot = new G4RotationMatrix;  // Rotates X and Z axes only
  // yMomRot->rotateY(fMom_theta);                     
  new G4PVPlacement(yMomRot,                     //no rotation
		    G4ThreeVector(fMom_pos_X, fMom_pos_Y, fMom_pos_Z),//fMom_pos_Z*sin(-fMom_theta), fMom_pos_Y, fMom_pos_Z*cos(-fMom_theta)),
		    lMother,            //its logical volume
		    "Mother_pos",               //its name
		    lWorld,                     //its mother  volume
		    false,                 //no boolean operation
		    0,                     //copy number
		    fCheckOverlaps);       // checking overlaps 
 
  //Temp Control Box(Mother Volume #2)
  G4Box*
    sTemp = new G4Box("Temp_sol", 0.5*fTemp_X, 0.5*fTemp_Y, 0.5*fTemp_Z);

  G4LogicalVolume* lTemp = new G4LogicalVolume(sTemp,
					       fWorldMater,//air
					       "Temp_log");
  new G4PVPlacement(0,                     //no rotation
		    G4ThreeVector(fTemp_pos_X, fTemp_pos_Y, fTemp_pos_Z),       //at (0,0,0)
		    lTemp,            //its logical volume
		    "Temp_pos",               //its name
		    lMother,                     //its mother  volume
		    false,                 //no boolean operation
		    0,                     //copy number
		    fCheckOverlaps);       // checking overlaps 


  //20171127(finish)

  ////////////////////////////////////////////////////////////////////////

  //Each Crystals Logical Volume
  G4Box*
    sCrystal = new G4Box("Crystal_sol", 0.5*fCrystal_X, 0.5*fCrystal_Y, 0.5*fCrystal_Z);

  fLogicCrystal = new G4LogicalVolume(sCrystal,
				      fDetectorMater,//detectormater = crystmater
				      "Crystal_log");
  
  //Each Detectors(Crysital + PMT + gap) Logical Volume (Mother volume #5)
  G4Box*
    sSingle = new G4Box("Single_sol", 0.5*fSingle_X, 0.5*fSingle_Y, 0.5*(fSingle_Z+/*20180222*/fWrapThickness));

  G4LogicalVolume* lSingle = new G4LogicalVolume(sSingle,
						 fWorldMater,//air
						 "Single_log");
  //Each columns Logical Volume (Mother volume #4) (36 crystals in y-axis become one single bulk, 31 colums in total)
  G4Box*
    sBulk = new G4Box("Bulk_sol", 0.5*fBulk_X, 0.5*fBulk_Y, 0.5*fBulk_Z);

  G4LogicalVolume* lBulk = new G4LogicalVolume(sBulk,
					       fWorldMater,//air
					       "Bulk_log");
  
  //NPS made with 31 bulks (Mother volume #3)
  G4Box* sNPS = new G4Box("Detector_sol", 0.5*fNPS_X, 0.5*fNPS_Y, 0.5*fNPS_Z);
  G4LogicalVolume* lNPS = new G4LogicalVolume(sNPS,
					      fWorldMater,//air

					      "Detector_sol");


  for(G4int ly = 0 ; ly < 31 ; ly++){
    for(G4int lx = 0 ; lx < 36 ; lx++){
      new G4PVPlacement(0,
			G4ThreeVector(15*fSingle_X - ly*fSingle_X, -17.5*fSingle_Y + lx*fSingle_Y,0),
			lSingle,
			"Single",
			lTemp,//place the NPS inside the Temp control box
			false,
			lx + ly*36,
			fCheckOverlaps);
    }
  }
  

  //Now, position the Crystals inside each Singles
  G4PVPlacement* fCrystalPos = new G4PVPlacement(0,                     //no rotation
						 G4ThreeVector(fCrystal_pos_X, fCrystal_pos_Y, fCrystal_pos_Z),       //at (0,0,0)
						 fLogicCrystal,            //its logical volume
						 "Crystal",               //its name
						 lSingle,                     //its mother  volume
						 false,                 //no boolean operation
						 0,                     //copy number
						 fCheckOverlaps);       // checking overlaps 

  //20180117(start)
  //
  //crystal wrapper
  //
  G4Box*
    sWrap = new G4Box("Wrap_sol", 0.5*fCrystal_X + fWrapThickness, 0.5*fCrystal_Y + fWrapThickness, 0.5*fCrystal_Z + fWrapThickness);

  G4RotationMatrix* Rot = new G4RotationMatrix;
  G4ThreeVector trans(0., 0., 0.5*(fCrystal_Z + fWrapThickness));
  G4Box*
    sWrap_end = new G4Box("Wrap_end_sol", 0.5*(fCrystal_X + 2*fWrapThickness), 0.5*(fCrystal_Y + 2*fWrapThickness), 0.5*fWrapThickness);

  G4SubtractionSolid* sWrap_end_sol = new G4SubtractionSolid("Wrap_sub_sol_1", sWrap, sWrap_end, Rot, trans);

  G4Box*
    sWrap_inside = new G4Box("Wrap_inside_sol", 0.5*fCrystal_X, 0.5*fCrystal_Y, 0.5*fCrystal_Z);//to hollow out the crystal wrapper         
  G4SubtractionSolid* sWrap_inside_sol = new G4SubtractionSolid("Wrap_sub_sol", sWrap_end_sol, sWrap_inside);
  G4Box*
    sWrap_front = new G4Box("Wrap_front_sol", 0.5*(fCrystal_X + 2*fWrapThickness), 0.5*(fCrystal_Y + 2*fWrapThickness), 0.5*fWrapThickness);

  G4ThreeVector trans_front(0., 0., -0.5*(fCrystal_Z + fWrapThickness));
  G4SubtractionSolid* sWrap_front_sol = new G4SubtractionSolid("Wrap_sub_sol_1", sWrap_inside_sol, sWrap_front, Rot, trans_front);

  fLogicWrap = new G4LogicalVolume(sWrap_front_sol,
				   fWrapMater,
				   "Wrap_log");

  G4PVPlacement* fWrapPos = new G4PVPlacement(0,
					      G4ThreeVector(fCrystal_pos_X, fCrystal_pos_Y, fCrystal_pos_Z),
					      fLogicWrap,
					      "Wrap_pos",
					      lSingle,
					      false,
					      0,
					      fCheckOverlaps);

  fLogicWrapFront = new G4LogicalVolume(sWrap_front,
					fWrapMater,
					"WrapFront_log");

  G4PVPlacement* fWrapFrontPos = new G4PVPlacement(0,
						   G4ThreeVector(fCrystal_pos_X, fCrystal_pos_Y, fCrystal_pos_Z) + trans_front,
						   fLogicWrapFront,
						   "WrapFront_pos",
						   lSingle,
						   false,
						   0,
						   fCheckOverlaps);


  //20180117(start)
  //
  //PMT
  //
  G4Box*
    sPMT = new G4Box("PMT_sol", 0.5*fPMT_X, 0.5*fPMT_Y, 0.5*fPMT_X);

  fLogicPMT = new G4LogicalVolume(sPMT,
                                  fPMTmater,
                                  "PMT_log");
  G4PVPlacement* fPMTpos = new G4PVPlacement(0,
                                             G4ThreeVector(fPMT_pos_X, fPMT_pos_Y, fPMT_pos_Z),
                                             fLogicPMT,
                                             "PMT_pos",
                                             lSingle,
                                             false,
                                             0,
                                             fCheckOverlaps);

  //
  //PMTcover
  //
  G4ThreeVector trans2(0., 0., -0.5*(fPMT_Z + fWrapThickness));
  G4Box*
    sPMTcover = new G4Box("PMTcover_sol", 0.5*(fPMT_X + 2*fWrapThickness), 0.5*(fPMT_Y + 2*fWrapThickness), 0.5*(fPMT_Z + 2*fWrapThickness));
  G4Box*
    sPMTcover_front = new G4Box("PMTcover_front_sol", 0.5*(fPMT_X + 2*fWrapThickness), 0.5*(fPMT_Y + 2*fWrapThickness), 0.5*fWrapThickness);  //to get rid of the cover at the front side of the crystal
  G4SubtractionSolid* sPMTcover_sol_1 = new G4SubtractionSolid("PMTcover_sub_sol_1", sPMTcover, sPMTcover_front, Rot, trans2);
  G4Box*
    sPMTcover_inside = new G4Box("PMTcover_inside_sol", 0.5*fPMT_X, 0.5*fPMT_Y, 0.5*fPMT_Z);
  G4SubtractionSolid* sPMTcover_sol = new G4SubtractionSolid("Wrap_sub_sol", sPMTcover_sol_1, sPMTcover_inside);

  fLogicPMTcover = new G4LogicalVolume(sPMTcover_sol,
				       fPMTcoverMater,
				       "PMTcover_log");



  G4PVPlacement* fPMTcoverPos = new G4PVPlacement(0,
						  G4ThreeVector(fPMT_pos_X, fPMT_pos_Y, fPMT_pos_Z),
						  fLogicPMTcover,
						  "PMTcover_pos",
						  lSingle,
						  false,
						  0,
						  fCheckOverlaps);
  //20180117(finish)

  //20180222(start)
  G4Box* sFrame_outer = new G4Box("Frame_outer_sol", 0.5*fSingle_X, 0.5*fSingle_Y, 0.5*(fSingle_Z + fWrapThickness));
  G4Box* sFrame_inner = new G4Box("Frame_inner_sol", 0.5*(fSingle_X-gap), 0.5*(fSingle_Y-gap), 0.5*fSingle_Z);
  G4Box* sFrame_front_back = new G4Box("Frame_front_back_sol", 0.5*fSingle_X, 0.5*fSingle_Y, 0.5*0.5*fWrapThickness);

  G4SubtractionSolid* sFrame_no_inner = new G4SubtractionSolid("Frame_no_inner_sol", sFrame_outer, sFrame_inner, Rot, G4ThreeVector());
  G4SubtractionSolid* sFrame_no_front = new G4SubtractionSolid("Frame_no_front_sol", sFrame_no_inner, sFrame_front_back, Rot, G4ThreeVector(0, 0, -(0.5*fSingle_Z + 0.5*0.5*fWrapThickness)));
  G4SubtractionSolid* sFrame = new G4SubtractionSolid("Frame_no_front_sol", sFrame_no_front, sFrame_front_back, Rot, G4ThreeVector(0, 0, (0.5*fSingle_Z + 0.5*0.5*fWrapThickness)));

  G4LogicalVolume* lFrame = new G4LogicalVolume(sFrame,
						fFrameMater,
						"Frame_log");
  G4PVPlacement* fFramePos = new G4PVPlacement(0,
					       G4ThreeVector(),
					       lFrame,					       
					       "Frame_pos",
					       lSingle,
					       false,
					       0,
					       fCheckOverlaps);


  //20180117(start)
  //
  //opticalsurface
  //
  G4OpticalSurface* opWrapperSurface = new G4OpticalSurface("WrapperSurface");
  opWrapperSurface->SetType(dielectric_LUT);
  opWrapperSurface->SetFinish(polishedvm2000air);
  opWrapperSurface->SetModel(LUT);
  new G4LogicalBorderSurface("WrapperSurface",
			     fCrystalPos,fWrapPos,opWrapperSurface);
  G4MaterialPropertiesTable* opWS = new G4MaterialPropertiesTable();
  opWS->DumpTable();
  opWrapperSurface->SetMaterialPropertiesTable(opWS);

  G4OpticalSurface* opWrapperFrontSurface = new G4OpticalSurface("WrapperFrontSurface");
  opWrapperFrontSurface->SetType(dielectric_LUT);
  opWrapperFrontSurface->SetFinish(polishedvm2000air);
  opWrapperFrontSurface->SetModel(LUT);
  new G4LogicalBorderSurface("WrapperFrontSurface",
			     fCrystalPos,fWrapFrontPos,opWrapperFrontSurface);
  G4MaterialPropertiesTable* opWFS = new G4MaterialPropertiesTable();
  opWFS->DumpTable();
  opWrapperFrontSurface->SetMaterialPropertiesTable(opWFS);

  G4OpticalSurface* opPMTSurface = new G4OpticalSurface("PMTSurface");
  opPMTSurface->SetType(dielectric_dielectric);
  opPMTSurface->SetFinish(polished);
  opPMTSurface->SetModel(unified);
  new G4LogicalBorderSurface("PMTSurface",
			     fCrystalPos,fPMTpos,opPMTSurface);
  G4MaterialPropertiesTable* opPS = new G4MaterialPropertiesTable();
  opPS->DumpTable();
  opPMTSurface->SetMaterialPropertiesTable(opPS);

  G4OpticalSurface* opPMTcoverSurface = new G4OpticalSurface("PMTcoverSurface");
  opPMTcoverSurface->SetType(dielectric_metal);
  opPMTcoverSurface->SetFinish(polished);
  opPMTcoverSurface->SetModel(unified);
  const  G4int nEntriesPMTcover = 2;
  G4double PhotonEnergyPMTcover[nEntriesPMTcover] = { 2.30*eV, 3.26*eV}; 
  G4double reflectivityPMTcover[nEntriesPMTcover] = {0., 0.};
  G4double efficiencyPMTcover[nEntriesPMTcover] = {1., 1.};
  new G4LogicalBorderSurface("PMTcoverSurface",
			     fPMTpos,fPMTcoverPos,opPMTcoverSurface);
  G4MaterialPropertiesTable* opPcS = new G4MaterialPropertiesTable();
  opPcS -> AddProperty("REFLECTIVITY",PhotonEnergyPMTcover,reflectivityPMTcover,nEntriesPMTcover);
  opPcS -> AddProperty("EFFICIENCY",PhotonEnergyPMTcover,efficiencyPMTcover,nEntriesPMTcover);  
  opPcS->DumpTable();
  opPMTcoverSurface->SetMaterialPropertiesTable(opPcS);

  //20180117(finish)


  //Coloring
  G4VisAttributes* CrystalVisAtt = new G4VisAttributes(G4Colour(1.,1.,0.));//yellow
  fLogicCrystal->SetVisAttributes(CrystalVisAtt);

  G4VisAttributes* WrapVisAtt = new G4VisAttributes(G4Colour(0.,1.,1.));//cyan
  fLogicWrap->SetVisAttributes(WrapVisAtt);

  G4VisAttributes* WrapFrontVisAtt = new G4VisAttributes(G4Colour(1.,0.,0.));//red
  fLogicWrapFront->SetVisAttributes(WrapFrontVisAtt);

  G4VisAttributes* PMTVisAtt = new G4VisAttributes(G4Colour(0.,1.,0.));//green
  fLogicPMT->SetVisAttributes(PMTVisAtt);
  G4VisAttributes* PMTcoverVisAtt = new G4VisAttributes(G4Colour(0.,0.,1.));//blue
  fLogicPMTcover->SetVisAttributes(PMTcoverVisAtt);

  G4VisAttributes* TempVisAtt = new G4VisAttributes(G4Colour(0.,1.,0.));//green
  lTemp->SetVisAttributes(TempVisAtt);
  G4VisAttributes* MomVisAtt = new G4VisAttributes(G4Colour(0.,0.,1.));//blue
  lMother->SetVisAttributes(MomVisAtt);

  G4VisAttributes* FrameVisAtt = new G4VisAttributes(G4Colour(1.,0.,1.));//magenta
  lFrame->SetVisAttributes(FrameVisAtt);
  //20171006(finish)


  PrintParameters();

  //always return the root volume
  //
  return fPhysiWorld;
}

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
    //20171009(start)
void DetectorConstruction::ConstructSDandField()
{
  // sensitive detectors -----------------------------------------------------
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  G4String SDname;
  G4VSensitiveDetector* PbWO4 
    = new B5HadCalorimeterSD(SDname="/HadCalorimeter");
  SDman->AddNewDetector(PbWO4);
  fLogicCrystal->SetSensitiveDetector(PbWO4);

  //20180117(start)
  G4VSensitiveDetector* CrystalCover
    = new CrystalCoverSD(SDname="/CrystalCover");
  SDman->AddNewDetector(CrystalCover);
  fLogicWrap->SetSensitiveDetector(CrystalCover);

  G4VSensitiveDetector* CrystalFrontCover
    = new CrystalFrontCoverSD(SDname="/CrystalFrontCover");
  SDman->AddNewDetector(CrystalFrontCover);
  fLogicWrapFront->SetSensitiveDetector(CrystalFrontCover);

  G4VSensitiveDetector* PMTcover
    = new PMTcoverSD(SDname="/PMTcover");
  SDman->AddNewDetector(PMTcover);
  fLogicPMTcover->SetSensitiveDetector(PMTcover);
  //20180117(finish)

}
  //20181009(finish)


  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  void DetectorConstruction::PrintParameters()
  {
  }


  //20180117(start)
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  void DetectorConstruction::SetDetectorGap(G4double value)
  {
    gap = value;
    G4RunManager::GetRunManager()->ReinitializeGeometry();
  }
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //20180117(finish)

