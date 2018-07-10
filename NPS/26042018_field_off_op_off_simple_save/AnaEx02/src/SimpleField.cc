/**
  * @file
  * @brief implements class SimpleField
*/

// GN 2015 from above model

#include "SimpleField.hh"
#include "G4SystemOfUnits.hh"

//20171121(start)
#include "G4PhysicalConstants.hh"//pi = 3.14159.....
//20171121(finish)

SimpleField::SimpleField()
{
  // first things first, let's read the data from the file
  // hardwired for now, later we'll see.
  //  const char * filename ="../DumpMagnet/Dump-field.table.txt";
  const char * filename ="../AnaEx02/DumpMagnet/SAM-Mc.table_5cm_step";
  double lenUnit= cm;
  G4cout << "\n-----------------------------------------------------------"
	 << "\n      3D Magnetic field from TOSCA MODEL (BW) "
	 << "\n-----------------------------------------------------------";
  G4cout << "\n ---> " "Reading the field grid from " << filename << " ... " << endl; 
  ifstream file( filename ); // Open the file for reading.
  if(file)G4cout<<"YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEAAAAAAAAAAAAAAAAH"<<G4endl;
  if(!file)G4cout<<"FUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUCK"<<G4endl;
  // Read table dimensions
  G4double tmp;
  file >> fNx >> fNy >> fNz >> tmp;
  G4cout << "  [ Grid size in x,y,z: " 
	 << fNx << " " << fNy << " " << fNz << " ] "
	 << G4endl;
  //
    // Set up storage space for table
  fXField.resize( fNx );
  fYField.resize( fNx );
  fZField.resize( fNx );
  int ix, iy, iz;
  for (ix=0; ix<fNx; ix++) {
    fXField[ix].resize(fNy);
    fYField[ix].resize(fNy);
    fZField[ix].resize(fNy);
    for (iy=0; iy<fNy; iy++) {
      fXField[ix][iy].resize(fNz);
      fYField[ix][iy].resize(fNz);
      fZField[ix][iy].resize(fNz);
    }
  }
  // Read in the data
  // double xval,yval,zval,bx,by,bz;
  float xval,yval,zval,bx,by,bz;
  //  double permeability; // Not used in this example.
  for (ix=0; ix<fNx; ix++) {
    for (iy=0; iy<fNy; iy++) {
      for (iz=0; iz<fNz; iz++) {
        file >> xval >> yval >> zval >> bx >> by >> bz;
	if (iz<5 && iy==0 && ix==0) {
	  G4cout << xval << " "<<yval << " "<<zval<<G4endl;
	}
        if ( ix==0 && iy==0 && iz==0 ) {
          fMinix = xval * lenUnit;
          fMiniy = yval * lenUnit;
          fMiniz = zval * lenUnit;
        }
        fXField[ix][iy][iz] = bx *gauss;
        fYField[ix][iy][iz] = by *gauss;
        fZField[ix][iy][iz] = bz *gauss;
      }
    }
  }
  fMaxix = xval * lenUnit;
  fMaxiy = yval * lenUnit;
  fMaxiz = zval * lenUnit;
  G4cout << "\n ---> ... done reading " << G4endl;
  // G4cout << " Read values of field from file " << filename << endl; 
  G4cout << " ---> assumed the order:  x, y, z, Bx, By, Bz "
	 << "\n ---> Min values x,y,z: " 
	 << fMinix/cm << " " << fMiniy/cm << " " << fMiniz/cm << " cm "
	 <<"\n ---> Min position field Bx,By,Bz: "
	 << fXField[0][0][0] << fYField[0][0][0] << fZField[0][0][0] << ""
	 << "\n ---> Max values x,y,z: " 
	 << fMaxix/cm << " " << fMaxiy/cm << " " << fMaxiz/cm << " cm " 
	 <<"\n ---> Max position field Bx,By,Bz: "
	 << fXField[40][20][30] << fYField[40][20][30] << fZField[40][20][30] << endl;

  fDx = fMaxix - fMinix;
  fDy = fMaxiy - fMiniy;
  fDz = fMaxiz - fMiniz;
  G4cout << "\n ---> Dif values x,y,z (range): " 
	 << fDx/cm << " " << fDy/cm << " " << fDz/cm << " cm in z "
	 << "\n-----------------------------------------------------------" << endl;
  //close the file
  file.close();

  ifstream file2( "../AnaEx02/DumpMagnet/field_str.txt" ); // Open the file for reading.
  // Read field strength
  file2 >> str;
  G4cout<< "----> Using "<<str<<" for field strength."<<endl;
  //close the file
  file2.close();     
  /////
  G4cout << "\n-----------------------------------------------------------"
	 << "\n  Done Initializing Simple Magnetic Field! "
	 << "\n-----------------------------------------------------------"<<G4endl;;
  return;
}
 
SimpleField::~SimpleField()
{;}

void SimpleField::GetFieldValue(const double point[4],double *Bfield) const
{

  // G4double coef, G0;
  //G0 = 0;
  //coef=1; // for protons
  //coef=2; // for alphas

  //******************************************************************

  // Interpolate field MAP (a la TabulatedField3D!)
  Bfield[0] = 0.0;
  Bfield[1] = 0.0;
  Bfield[2] = 0.0;
  Bfield[3] = 0.0;
  Bfield[4] = 0.0;
  Bfield[5] = 0.0;

  //20171121(start)  

  //20180425(start)
    // double x = point[0];
    // double y = point[1];
    // double z = point[2]; 
 
  //changing the coordinate from target coordinate to magnetic field coordinate
    double x = ( (point[0] - 157*cm*sin((2.2*pi)/180.))*cos((2.2*pi)/180.) - (point[2] - 157*cm*cos((2.2*pi)/180.))*sin((2.2*pi)/180.) );
    double y = point[1];
    double z = ( (point[0] - 157*cm*sin((2.2*pi)/180.))*sin((2.2*pi)/180.) + (point[2] - 157*cm*cos((2.2*pi)/180.))*cos((2.2*pi)/180.) );
  //20180425(finish)
  
  // ofstream test("text.txt");
  // test<<
  //   "\n\n!!!!!!!!!!!!!!!"<<position_X<<", "<<position_Z<<""
  // 			 <<"\npoints : "<<point[0]<<", "<<point[1]<<", "<<point[2]<<""
  // 			 <<"\nx-, y-, z- : "<<x_prime<<", "<<y<<", "<<z_prime<<""
  // 			 <<"\nx, y, z : "<<x<<", "<<y<<", "<<z;
  // test.close();
  
  // G4cout<<"!!!!!!!!!!!!!!!"<<position_X<<", "<<position_Z<<G4endl;
  // G4cout<<"points : "<<point[0]<<", "<<point[1]<<", "<<point[2]<<G4endl;
  // G4cout<<"x-, y-, z- : "<<x_prime<<", "<<y<<", "<<z_prime<<G4endl;
  // G4cout<<"x, y, z : "<<x<<", "<<y<<", "<<z<<G4endl;

  //20171121(finish)

  //  G4int quad;
  //G4double gradient[5];
  /*  
      gradient[0]=fGradient1*(gauss/cm)/coef;
      gradient[1]=fGradient2*(gauss/cm)/coef;
      gradient[2]=fGradient3*(gauss/cm)/coef; 
      gradient[3]=fGradient4*(gauss/cm)/coef;
      gradient[4]=-fGradient3*(gauss/cm)/coef;
  */
  // Check that the point is within the defined region 
  
  if   (
	//20171128(start)
	// x>=fMinix && x<=fMaxix &&
	// y>=fMiniy && y<=fMaxiy &&
	// z>=fMiniz && z<=fMaxiz  ) 
	x>=fMinix && x<=fMaxix &&
	y>=fMiniy && y<=fMaxiy &&
	z>=fMiniz && z<=fMaxiz  )//-1 is to prevent finding the B field in position 41 ,-41 71 or -71. 
    //20171128(finish)
    {
      // Position of given point within region, normalized to the range
      // [0,1]
      double xfraction = (x - fMinix) / fDx;
      double yfraction = (y - fMiniy) / fDy; 
      double zfraction = (z - fMiniz) / fDz;
      // Need addresses of these to pass to modf below.
      // modf uses its second argument as an OUTPUT argument.
      double xdindex, ydindex, zdindex;
    
      // Position of the point within the cuboid defined by the
      // nearest surrounding tabulated points
      double xlocal = ( std::modf(xfraction*(fNx-1), &xdindex));
      double ylocal = ( std::modf(yfraction*(fNy-1), &ydindex));
      double zlocal = ( std::modf(zfraction*(fNz-1), &zdindex));
      
    
      // The indices of the nearest tabulated point whose coordinates
      // are all less than those of the given point
      int xindex = static_cast<int>(xdindex);
      int yindex = static_cast<int>(ydindex);
      int zindex = static_cast<int>(zdindex);
      
      // ofstream test2("text2.txt");
      // test2<<
      // 	"\n\nfMinix : "<<fMinix<<""
      // 		       <<"\nindix : "<<xindex<<", "<<yindex<<", "<<zindex<<""
      // 		       <<"\nlocal : "<<xlocal<<", "<<ylocal<<", "<<zlocal<<""
      // 		       <<"\nfXField : "<< fXField[xindex  ][yindex+1][zindex  ];
      // test2.close();
      
      // G4cout<<"fMinix : "<<fMinix<<G4endl;
      // G4cout<<"indix : "<<xindex<<", "<<yindex<<", "<<zindex<<G4endl;
      // G4cout<<"local : "<<xlocal<<", "<<ylocal<<", "<<zlocal<<G4endl;
      // G4cout<<"fXField : "<< fXField[xindex  ][yindex+1][zindex  ] <<G4endl;

      // Interpolated field
      Bfield[0] =
	((fXField[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
	  fXField[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
	  fXField[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
	  fXField[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
	  fXField[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
	  fXField[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
	  fXField[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
	  fXField[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal)
	 + Bfield[0])*str;
      
      Bfield[1] =
	((fYField[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
	  fYField[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
	  fYField[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
	  fYField[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
	  fYField[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
	  fYField[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
	  fYField[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
	  fYField[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal) 
	 + Bfield[1])*str;

      Bfield[2] =
	((fZField[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
	  fZField[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
	  fZField[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
	  fZField[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
	  fZField[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
	  fZField[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
	  fZField[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
	  fZField[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal)
	 + Bfield[2])*str;
    }
  //   G4cout<< "str = "<<str<<" B = "<<Bfield[0]<<" "<<Bfield[1]<<" "<<Bfield[2]<<G4endl;
  //end  MAP
}
