{

  string dummy;
  double wavelength_db, absp_db;
  vector<double> wavelength;  
  vector<double> absp_fresh1, absp_fresh2;
  vector<double> absp_15cm1_1, absp_15cm1_2, absp_15cm1_3;
  vector<double> absp_15cm2_1, absp_15cm2_2, absp_15cm2_3, absp_15cm2_4;
  vector<double> absp_30cm2_1, absp_30cm2_2, absp_30cm2_3, absp_30cm2_4;      

  int i = 1;
  ostringstream str;
  str << i;
  string pos = str.str();

  string fresh1 = "../converted/converted_once_more/FRESHSOLUTIONTOWATER.txt";
  string fresh2 = "../converted/converted_once_more/FRESHSOLUTION2TOWATERV2.txt";  
  string front  = "../converted/converted_once_more/NO";
  string first  = "FIRSTTIME";
  string second = "SECONDTIME";
  string third  = "THIRDTIME";
  string fourth = "FOURTHTIME";      
  string back_15cm1 = "10MM.txt";
  string back_15cm2 = "10MMAFTERNOON.txt";
  string back_30cm  = "10MMAFTERNOON30CMSETUP.txt";      




  TCanvas *c1 = new TCanvas("c1", "c1", 200, 10, 700,   500);

  ifstream myfile;
  myfile.open(fresh1.c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    wavelength.push_back(wavelength_db);
    absp_fresh1.push_back(absp_db);
    //    cout<<wavelength_db<<endl;
  }
  myfile.close();

  myfile.open(fresh2.c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    wavelength.push_back(wavelength_db);
    absp_fresh2.push_back(absp_db);
    //    cout<<wavelength_db<<endl;
  }
  myfile.close();  

  myfile.open((front+pos+first+back_15cm1).c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    absp_15cm1_1.push_back(absp_db);
    //    cout<<absp_db<<endl;
  }
  myfile.close();

  myfile.open((front+pos+second+back_15cm1).c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    absp_15cm1_2.push_back(absp_db);
  }
  myfile.close();

  myfile.open((front+pos+first+back_15cm2).c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    absp_15cm2_1.push_back(absp_db);
  }
  myfile.close();      


  myfile.open((front+pos+second+back_15cm2).c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    absp_15cm2_2.push_back(absp_db);
  }
  myfile.close();      


  myfile.open((front+pos+third+back_15cm2).c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    absp_15cm2_3.push_back(absp_db);
  }
  myfile.close();      


  myfile.open((front+pos+fourth+back_15cm2).c_str());
  while(myfile>>wavelength_db>>absp_db>>dummy){
    absp_15cm2_4.push_back(absp_db);
    //    cout<<absp_db<<endl;
  }
  myfile.close();      


  TMultiGraph *mg = new TMultiGraph();

  TGraph *gr_15cm1_1 = new TGraph(wavelength.size(), &wavelength[0], &absp_15cm1_1[0]);
  gr_15cm1_1->SetLineColor(4);
  gr_15cm1_1->SetMarkerColor(4);  
  gr_15cm1_1->SetMarkerStyle(1);  
  mg->Add(gr_15cm1_1);

  TGraph *gr_15cm1_2 = new TGraph(wavelength.size(), &wavelength[0], &absp_15cm1_2[0]);
  gr_15cm1_2->SetLineColor(3);
  gr_15cm1_2->SetMarkerColor(3);  
  gr_15cm1_2->SetMarkerStyle(1);  
  mg->Add(gr_15cm1_2);  

  TGraph *gr_15cm2_1 = new TGraph(wavelength.size(), &wavelength[0], &absp_15cm2_1[0]);
  gr_15cm2_1->SetLineColor(5);
  gr_15cm2_1->SetMarkerColor(5);  
  gr_15cm2_1->SetMarkerStyle(1);  
  mg->Add(gr_15cm2_1);  

  TGraph *gr_15cm2_2 = new TGraph(wavelength.size(), &wavelength[0], &absp_15cm2_2[0]);
  gr_15cm2_2->SetLineColor(6);
  gr_15cm2_2->SetMarkerColor(6);  
  gr_15cm2_2->SetMarkerStyle(1);  
  mg->Add(gr_15cm2_2);  

  TGraph *gr_15cm2_3 = new TGraph(wavelength.size(), &wavelength[0], &absp_15cm2_3[0]);
  gr_15cm2_3->SetLineColor(7);
  gr_15cm2_3->SetMarkerColor(7);  
  gr_15cm2_3->SetMarkerStyle(1);  
  mg->Add(gr_15cm2_3);  

  TGraph *gr_15cm2_4 = new TGraph(wavelength.size(), &wavelength[0], &absp_15cm2_4[0]);
  gr_15cm2_4->SetLineColor(8);
  gr_15cm2_4->SetMarkerColor(8);  
  gr_15cm2_4->SetMarkerStyle(1);  
  mg->Add(gr_15cm2_4);  



  TGraph *gr_fresh2 = new TGraph(wavelength.size(), &wavelength[0], &absp_fresh2[0]);
  gr_fresh2->SetLineColor(1);
  gr_fresh2->SetMarkerColor(1);  
  gr_fresh2->SetMarkerStyle(1);  
  gr_fresh2->SetTitle("15cm solution morning");
  gr_fresh2->GetXaxis()->SetLimits(190,500);
  //  gr_fresh2->GetYaxis()->SetRangeUser(-0.02,0.8);
  gr_fresh2->GetXaxis()->SetTitle("Wavelength [nm]");
  gr_fresh2->GetYaxis()->SetTitle("Absorption");  
  gr_fresh2->Draw("APL");
  mg->Draw("PL");
  
}
