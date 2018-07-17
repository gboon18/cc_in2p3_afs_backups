#ifndef SimpleField_H
#define SimpleField_H 1

/**
  * @file
  * @brief Defines class SimpleField
*/
#include "globals.hh"
#include "G4MagneticField.hh"
 
#include <fstream>
#include <vector>

using namespace std;

class SimpleField 

#ifndef STANDALONE
: public G4MagneticField
#endif

{
public:
  SimpleField();
  ~SimpleField();
  void GetFieldValue( const  double Point[4],
		      double *Bfield ) const;
private:
  G4double Bvalue;
  // G4double rmax_sq;
  // G4double zMin;
  G4double zMax;
  G4double str;
  
  vector< vector< vector< double > > > fXField_5cm;
  vector< vector< vector< double > > > fYField_5cm;
  vector< vector< vector< double > > > fZField_5cm;
  G4int fNx_5cm,fNy_5cm,fNz_5cm; 
  G4double fMinix_5cm, fMaxix_5cm, fMiniy_5cm, fMaxiy_5cm, fMiniz_5cm, fMaxiz_5cm;
  G4double fDx_5cm, fDy_5cm, fDz_5cm;
  G4float fGradient1_5cm, fGradient2_5cm, fGradient3_5cm, fGradient4_5cm;

  vector< vector< vector< double > > > fXField_20cm;
  vector< vector< vector< double > > > fYField_20cm;
  vector< vector< vector< double > > > fZField_20cm;
  G4int fNx_20cm,fNy_20cm,fNz_20cm; 
  G4double fMinix_20cm, fMaxix_20cm, fMiniy_20cm, fMaxiy_20cm, fMiniz_20cm, fMaxiz_20cm;
  G4double fDx_20cm, fDy_20cm, fDz_20cm;
  G4float fGradient1_20cm, fGradient2_20cm, fGradient3_20cm, fGradient4_20cm;

  
};

#endif
