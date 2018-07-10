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
  const char * filename_5cm ="../AnaEx02/DumpMagnet/SAM-Mc.table_5cm_step";
  // const char * filename_20cm ="../AnaEx02/DumpMagnet/SAM-Mc.table_20cm_step";
  double lenUnit= cm;
  G4cout << "\n-----------------------------------------------------------"
	 << "\n      3D Magnetic field from TOSCA MODEL (BW) "
	 << "\n-----------------------------------------------------------";
  G4cout << "\n ---> " "Reading the field grid from " << filename_5cm << " ... " << endl; 

  ifstream file_5cm( filename_5cm ); // Open the file for reading.
  if(file_5cm)G4cout<<"YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEAAAAAAAAAAAAAAAAH"<<G4endl;
  if(!file_5cm)G4cout<<"FUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUCK"<<G4endl;
  // Read table dimensions
  G4double tmp;
  file_5cm >> fNx_5cm >> fNy_5cm >> fNz_5cm >> tmp;
  G4cout << "  [ Grid size in x,y,z: " 
	 << fNx_5cm << " " << fNy_5cm << " " << fNz_5cm << " ] "
	 << G4endl;
  //
    // Set up storage space for table
  fXField_5cm.resize( fNx_5cm );
  fYField_5cm.resize( fNx_5cm );
  fZField_5cm.resize( fNx_5cm );
  int ix, iy, iz;
  for (ix=0; ix<fNx_5cm; ix++) {
    fXField_5cm[ix].resize(fNy_5cm);
    fYField_5cm[ix].resize(fNy_5cm);
    fZField_5cm[ix].resize(fNy_5cm);
    for (iy=0; iy<fNy_5cm; iy++) {
      fXField_5cm[ix][iy].resize(fNz_5cm);
      fYField_5cm[ix][iy].resize(fNz_5cm);
      fZField_5cm[ix][iy].resize(fNz_5cm);
    }
  }
  // Read in the data
  // double xval,yval,zval,bx,by,bz;
  float xval,yval,zval,bx,by,bz;
  //  double permeability; // Not used in this example.
  for (ix=0; ix<fNx_5cm; ix++) {
    for (iy=0; iy<fNy_5cm; iy++) {
      for (iz=0; iz<fNz_5cm; iz++) {
        file_5cm >> xval >> yval >> zval >> bx >> by >> bz;
	if (iz<5 && iy==0 && ix==0) {
	  G4cout << xval << " "<<yval << " "<<zval<<G4endl;
	}
        if ( ix==0 && iy==0 && iz==0 ) {
          fMinix_5cm = xval * lenUnit;
          fMiniy_5cm = yval * lenUnit;
          fMiniz_5cm = zval * lenUnit;
        }
        fXField_5cm[ix][iy][iz] = bx *gauss;
        fYField_5cm[ix][iy][iz] = by *gauss;
        fZField_5cm[ix][iy][iz] = bz *gauss;
      }
    }
  }
  fMaxix_5cm = xval * lenUnit;
  fMaxiy_5cm = yval * lenUnit;
  fMaxiz_5cm = zval * lenUnit;
  G4cout << "\n ---> ... done reading " << G4endl;
  // G4cout << " Read values of field from file " << filename_5cm << endl; 
  G4cout << " ---> assumed the order:  x, y, z, Bx, By, Bz "
	 << "\n ---> Min values x,y,z: " 
	 << fMinix_5cm/cm << " " << fMiniy_5cm/cm << " " << fMiniz_5cm/cm << " cm "
	 <<"\n ---> Min position field Bx,By,Bz: "
	 << fXField_5cm[0][0][0] << " " << fYField_5cm[0][0][0] << " " << fZField_5cm[0][0][0] << ""
	 << "\n ---> Max values x,y,z: " 
	 << fMaxix_5cm/cm << " " << fMaxiy_5cm/cm << " " << fMaxiz_5cm/cm << " cm " 
	 <<"\n ---> Max position field Bx,By,Bz: "
	 << fXField_5cm[fNx_5cm - 1][fNy_5cm - 1][fNz_5cm - 1] << " " << fYField_5cm[fNx_5cm - 1][fNy_5cm - 1][fNz_5cm - 1] << " " << fZField_5cm[fNx_5cm - 1][fNy_5cm - 1][fNz_5cm - 1] << endl;

  fDx_5cm = fMaxix_5cm - fMinix_5cm;
  fDy_5cm = fMaxiy_5cm - fMiniy_5cm;
  fDz_5cm = fMaxiz_5cm - fMiniz_5cm;
  G4cout << "\n ---> Dif values x,y,z (range): " 
	 << fDx_5cm/cm << " " << fDy_5cm/cm << " " << fDz_5cm/cm << " cm in z "
	 << "\n-----------------------------------------------------------" << endl;
  //close the file
  file_5cm.close();

  // ifstream file_20cm( filename_20cm ); // Open the file for reading.
  // if(file_20cm)G4cout<<"YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEAAAAAAAAAAAAAAAAH"<<G4endl;
  // if(!file_20cm)G4cout<<"FUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUCK"<<G4endl;
  // // Read table dimensions

  // file_20cm >> fNx_20cm >> fNy_20cm >> fNz_20cm >> tmp;
  // G4cout << "  [ Grid size in x,y,z: " 
  // 	 << fNx_20cm << " " << fNy_20cm << " " << fNz_20cm << " ] "
  // 	 << G4endl;
  // //
  //   // Set up storage space for table
  // fXField_20cm.resize( fNx_20cm );
  // fYField_20cm.resize( fNx_20cm );
  // fZField_20cm.resize( fNx_20cm );
  // for (ix=0; ix<fNx_20cm; ix++) {
  //   fXField_20cm[ix].resize(fNy_20cm);
  //   fYField_20cm[ix].resize(fNy_20cm);
  //   fZField_20cm[ix].resize(fNy_20cm);
  //   for (iy=0; iy<fNy_20cm; iy++) {
  //     fXField_20cm[ix][iy].resize(fNz_20cm);
  //     fYField_20cm[ix][iy].resize(fNz_20cm);
  //     fZField_20cm[ix][iy].resize(fNz_20cm);
  //   }
  // }
  // // Read in the data
  // // double xval,yval,zval,bx,by,bz;
  // //  double permeability; // Not used in this example.
  // for (ix=0; ix<fNx_20cm; ix++) {
  //   for (iy=0; iy<fNy_20cm; iy++) {
  //     for (iz=0; iz<fNz_20cm; iz++) {
  //       file_20cm >> xval >> yval >> zval >> bx >> by >> bz;
  // 	if (iz<5 && iy==0 && ix==0) {
  // 	  G4cout << xval << " "<<yval << " "<<zval<<G4endl;
  // 	}
  //       if ( ix==0 && iy==0 && iz==0 ) {
  //         fMinix_20cm = xval * lenUnit;
  //         fMiniy_20cm = yval * lenUnit;
  //         fMiniz_20cm = zval * lenUnit;
  //       }
  //       fXField_20cm[ix][iy][iz] = bx *gauss;
  //       fYField_20cm[ix][iy][iz] = by *gauss;
  //       fZField_20cm[ix][iy][iz] = bz *gauss;
  //     }
  //   }
  // }
  // fMaxix_20cm = xval * lenUnit;
  // fMaxiy_20cm = yval * lenUnit;
  // fMaxiz_20cm = zval * lenUnit;
  // G4cout << "\n ---> ... done reading " << G4endl;
  // // G4cout << " Read values of field from file " << filename_20cm << endl; 
  // G4cout << " ---> assumed the order:  x, y, z, Bx, By, Bz "
  // 	 << "\n ---> Min values x,y,z: " 
  // 	 << fMinix_20cm/cm << " " << fMiniy_20cm/cm << " " << fMiniz_20cm/cm << " cm "
  // 	 <<"\n ---> Min position field Bx,By,Bz: "
  // 	 << fXField_20cm[0][0][0] << " " << fYField_20cm[0][0][0] << " " << fZField_20cm[0][0][0] << ""
  // 	 << "\n ---> Max values x,y,z: " 
  // 	 << fMaxix_20cm/cm << " " << fMaxiy_20cm/cm << " " << fMaxiz_20cm/cm << " cm " 
  // 	 <<"\n ---> Max position field Bx,By,Bz: "
  // 	 << fXField_20cm[fNx_20cm - 1][fNy_20cm - 1][fNz_20cm - 1] << " " << fYField_20cm[fNx_20cm - 1][fNy_20cm - 1][fNz_20cm - 1] << " " << fZField_20cm[fNx_20cm - 1][fNy_20cm - 1][fNz_20cm - 1] << endl;

  // fDx_20cm = fMaxix_20cm - fMinix_20cm;
  // fDy_20cm = fMaxiy_20cm - fMiniy_20cm;
  // fDz_20cm = fMaxiz_20cm - fMiniz_20cm;
  // G4cout << "\n ---> Dif values x,y,z (range): " 
  // 	 << fDx_20cm/cm << " " << fDy_20cm/cm << " " << fDz_20cm/cm << " cm in z "
  // 	 << "\n-----------------------------------------------------------" << endl;
  // //close the file
  // file_20cm.close();

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
  //20180426 comment : you need to put the unit in mm since the default unit of Geant4 is mm. not 157*cm, just 1570.
    double x = ( (point[0] - 1570*sin((2.2*pi)/180.))*cos((2.2*pi)/180.) - (point[2] - 1570*cos((2.2*pi)/180.))*sin((2.2*pi)/180.) );
    double y = point[1];
    double z = ( (point[0] - 1570*sin((2.2*pi)/180.))*sin((2.2*pi)/180.) + (point[2] - 1570*cos((2.2*pi)/180.))*cos((2.2*pi)/180.) );
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
	// x>=fMinix_5cm && x<=fMaxix_5cm &&
	// y>=fMiniy_5cm && y<=fMaxiy_5cm &&
	// z>=fMiniz_5cm && z<=fMaxiz_5cm  ) 
	x>=fMinix_5cm && x<=fMaxix_5cm &&
	y>=fMiniy_5cm && y<=fMaxiy_5cm &&
	z>=fMiniz_5cm && z<=fMaxiz_5cm  )//-1 is to prevent finding the B field in position 41 ,-41 71 or -71. 
    //20171128(finish)
    {//G4cout<<"5cm!!!!!!!!!!!!!"<<G4endl;
      // Position of given point within region, normalized to the range
      // [0,1]
      double xfraction = (x - fMinix_5cm) / fDx_5cm;
      double yfraction = (y - fMiniy_5cm) / fDy_5cm; 
      double zfraction = (z - fMiniz_5cm) / fDz_5cm;
      // Need addresses of these to pass to modf below.
      // modf uses its second argument as an OUTPUT argument.
      double xdindex, ydindex, zdindex;
    
      // Position of the point within the cuboid defined by the
      // nearest surrounding tabulated points
      double xlocal = ( std::modf(xfraction*(fNx_5cm-1), &xdindex));
      double ylocal = ( std::modf(yfraction*(fNy_5cm-1), &ydindex));
      double zlocal = ( std::modf(zfraction*(fNz_5cm-1), &zdindex));
      
    
      // The indices of the nearest tabulated point whose coordinates
      // are all less than those of the given point
      int xindex = static_cast<int>(xdindex);
      int yindex = static_cast<int>(ydindex);
      int zindex = static_cast<int>(zdindex);
      
      // ofstream test2("text2.txt");
      // test2<<
      // 	"\n\nfMinix_5cm : "<<fMinix_5cm<<""
      // 		       <<"\nindix : "<<xindex<<", "<<yindex<<", "<<zindex<<""
      // 		       <<"\nlocal : "<<xlocal<<", "<<ylocal<<", "<<zlocal<<""
      // 		       <<"\nfXField_5cm : "<< fXField_5cm[xindex  ][yindex+1][zindex  ];
      // test2.close();
      
      // G4cout<<"fMinix_5cm : "<<fMinix_5cm<<G4endl;
      // G4cout<<"indix : "<<xindex<<", "<<yindex<<", "<<zindex<<G4endl;
      // G4cout<<"local : "<<xlocal<<", "<<ylocal<<", "<<zlocal<<G4endl;
      // G4cout<<"fXField_5cm : "<< fXField_5cm[xindex  ][yindex+1][zindex  ] <<G4endl;

      // Interpolated field
      Bfield[0] =
	((fXField_5cm[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
	  fXField_5cm[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
	  fXField_5cm[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
	  fXField_5cm[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
	  fXField_5cm[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
	  fXField_5cm[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
	  fXField_5cm[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
	  fXField_5cm[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal)
	 + Bfield[0])*str;
      
      Bfield[1] =
	((fYField_5cm[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
	  fYField_5cm[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
	  fYField_5cm[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
	  fYField_5cm[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
	  fYField_5cm[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
	  fYField_5cm[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
	  fYField_5cm[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
	  fYField_5cm[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal) 
	 + Bfield[1])*str;

      Bfield[2] =
	((fZField_5cm[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
	  fZField_5cm[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
	  fZField_5cm[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
	  fZField_5cm[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
	  fZField_5cm[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
	  fZField_5cm[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
	  fZField_5cm[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
	  fZField_5cm[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal)
	 + Bfield[2])*str;
    }
    // }else if(
    // 	     (!(x>=fMinix_5cm && x<=fMaxix_5cm && y>=fMiniy_5cm && y<=fMaxiy_5cm && z>=fMiniz_5cm && z<=fMaxiz_5cm))
    // 	  && (x>=fMinix_20cm && x<=fMaxix_20cm && y>=fMiniy_20cm && y<=fMaxiy_20cm && z>=fMiniz_20cm && z<=fMaxiz_20cm ))
    // {//G4cout<<"20cm!!!!!!!!!!!!!"<<G4endl;
    //   // Position of given point within region, normalized to the range
    //   // [0,1]
    //   double xfraction = (x - fMinix_20cm) / fDx_20cm;
    //   double yfraction = (y - fMiniy_20cm) / fDy_20cm; 
    //   double zfraction = (z - fMiniz_20cm) / fDz_20cm;
    //   // Need addresses of these to pass to modf below.
    //   // modf uses its second argument as an OUTPUT argument.
    //   double xdindex, ydindex, zdindex;
    
    //   // Position of the point within the cuboid defined by the
    //   // nearest surrounding tabulated points
    //   double xlocal = ( std::modf(xfraction*(fNx_20cm-1), &xdindex));
    //   double ylocal = ( std::modf(yfraction*(fNy_20cm-1), &ydindex));
    //   double zlocal = ( std::modf(zfraction*(fNz_20cm-1), &zdindex));
      
    
    //   // The indices of the nearest tabulated point whose coordinates
    //   // are all less than those of the given point
    //   int xindex = static_cast<int>(xdindex);
    //   int yindex = static_cast<int>(ydindex);
    //   int zindex = static_cast<int>(zdindex);
      
    //   // ofstream test2("text2.txt");
    //   // test2<<
    //   // 	"\n\nfMinix_20cm : "<<fMinix_20cm<<""
    //   // 		       <<"\nindix : "<<xindex<<", "<<yindex<<", "<<zindex<<""
    //   // 		       <<"\nlocal : "<<xlocal<<", "<<ylocal<<", "<<zlocal<<""
    //   // 		       <<"\nfXField_20cm : "<< fXField_20cm[xindex  ][yindex+1][zindex  ];
    //   // test2.close();
      
    //   // G4cout<<"fMinix_20cm : "<<fMinix_20cm<<G4endl;
    //   // G4cout<<"indix : "<<xindex<<", "<<yindex<<", "<<zindex<<G4endl;
    //   // G4cout<<"local : "<<xlocal<<", "<<ylocal<<", "<<zlocal<<G4endl;
    //   // G4cout<<"fXField_20cm : "<< fXField_20cm[xindex  ][yindex+1][zindex  ] <<G4endl;

    //   // Interpolated field
    //   Bfield[0] =
    // 	((fXField_20cm[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
    // 	  fXField_20cm[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
    // 	  fXField_20cm[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
    // 	  fXField_20cm[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
    // 	  fXField_20cm[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
    // 	  fXField_20cm[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
    // 	  fXField_20cm[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
    // 	  fXField_20cm[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal)
    // 	 + Bfield[0])*str;
      
    //   Bfield[1] =
    // 	((fYField_20cm[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
    // 	  fYField_20cm[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
    // 	  fYField_20cm[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
    // 	  fYField_20cm[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
    // 	  fYField_20cm[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
    // 	  fYField_20cm[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
    // 	  fYField_20cm[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
    // 	  fYField_20cm[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal) 
    // 	 + Bfield[1])*str;

    //   Bfield[2] =
    // 	((fZField_20cm[xindex  ][yindex  ][zindex  ] * (1-xlocal) * (1-ylocal) * (1-zlocal) +
    // 	  fZField_20cm[xindex  ][yindex  ][zindex+1] * (1-xlocal) * (1-ylocal) *    zlocal  +
    // 	  fZField_20cm[xindex  ][yindex+1][zindex  ] * (1-xlocal) *    ylocal  * (1-zlocal) +
    // 	  fZField_20cm[xindex  ][yindex+1][zindex+1] * (1-xlocal) *    ylocal  *    zlocal  +
    // 	  fZField_20cm[xindex+1][yindex  ][zindex  ] *    xlocal  * (1-ylocal) * (1-zlocal) +
    // 	  fZField_20cm[xindex+1][yindex  ][zindex+1] *    xlocal  * (1-ylocal) *    zlocal  +
    // 	  fZField_20cm[xindex+1][yindex+1][zindex  ] *    xlocal  *    ylocal  * (1-zlocal) +
    // 	  fZField_20cm[xindex+1][yindex+1][zindex+1] *    xlocal  *    ylocal  *    zlocal)
    // 	 + Bfield[2])*str;
    // }
  //   G4cout<< "str = "<<str<<" B = "<<Bfield[0]<<" "<<Bfield[1]<<" "<<Bfield[2]<<G4endl;
  //end  MAP
}
