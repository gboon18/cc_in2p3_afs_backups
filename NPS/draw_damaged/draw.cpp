{

  string dummy;
  string wavelength_str, abs_str;


  double wavelength_db, abs_db;
  vector<double> wavelength, abs;
  ifstream myfile;
  myfile.open("../converted/NO2FIRSTTIME10MM.CSV");

  // myfile>>dummy>>dummy;
  // cout<<dummy<<endl;

  while(myfile>>wavelength_str>>abs_str>>dummy>>dummy){
    wavelength.push_back(atof(wavelength_str.c_str()));
    abs.push_back(abs_db);
    cout<<atof(wavelength_str.c_str())<<endl;
  }

  // TGraph *gr = new TGraph(wavelength.size(), &wavelength[0], &abs[0]);
  // gr->Draw("APL");

}
