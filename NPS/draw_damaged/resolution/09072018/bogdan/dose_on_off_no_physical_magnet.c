{
  TChain *ch_on1 = new TChain("t");
  TChain *ch_on2 = new TChain("t");
  TChain *ch_on3 = new TChain("t");
  TChain *ch_on4 = new TChain("t");
  TChain *ch_off1 = new TChain("t");
  TChain *ch_off2 = new TChain("t");
  TChain *ch_off3 = new TChain("t");
  TChain *ch_off4 = new TChain("t");

  string dir_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/09072018/rootfiles_bogdan/";
  string field_on_str = "dose2_field_on_";
  string field_off_str = "dose2_field_off_";
  string file_end_str = ".root";


  for(int i = 1; i < 101 ; i++){
    string i_str;
    ostringstream convert;
    convert << i ;
    i_str = convert.str();// = to_string(i);
    string comb_on_6_3 = dir_str + field_on_str + "6_3_" + i_str + file_end_str;
    string comb_on_16_6 = dir_str + field_on_str + "16_6_" + i_str + file_end_str;
    string comb_on_26_9 = dir_str + field_on_str + "26_9_" + i_str + file_end_str;
    string comb_on_37_2 = dir_str + field_on_str + "37_2_" + i_str + file_end_str;
    string comb_off_6_3 = dir_str + field_off_str + "6_3_" + i_str + file_end_str;
    string comb_off_16_6 = dir_str + field_off_str + "16_6_" + i_str + file_end_str;
    string comb_off_26_9 = dir_str + field_off_str + "26_9_" + i_str + file_end_str;
    string comb_off_37_2 = dir_str + field_off_str + "37_2_" + i_str + file_end_str;
    const char* file_on_6_3 = comb_on_6_3.c_str();
    const char* file_on_16_6 = comb_on_16_6.c_str();
    const char* file_on_26_9 = comb_on_26_9.c_str();
    const char* file_on_37_2 = comb_on_37_2.c_str();
    const char* file_off_6_3 = comb_off_6_3.c_str();
    const char* file_off_16_6 = comb_off_16_6.c_str();
    const char* file_off_26_9 = comb_off_26_9.c_str();
    const char* file_off_37_2 = comb_off_37_2.c_str();
    ch_on1->Add(file_on_6_3);
    ch_on2->Add(file_on_16_6);
    ch_on3->Add(file_on_26_9);
    ch_on4->Add(file_on_37_2);
    ch_off1->Add(file_off_6_3);
    ch_off2->Add(file_off_16_6);
    ch_off3->Add(file_off_26_9);
    ch_off4->Add(file_off_37_2);
  }

  /* TTree *t1 = (TTree*)ch_on1->GetTree(); */
  /* TTree *t2 = (TTree*)ch_on2->GetTree(); */
  /* TTree *t3 = (TTree*)ch_on3->GetTree(); */
  /* TTree *t4 = (TTree*)ch_on4->GetTree(); */

  const int array = 1116;

  double edep_on1[array] = {0.};
  double edep_on2[array] = {0.};
  double edep_on3[array] = {0.};
  double edep_on4[array] = {0.};
  double totedep_on = 0.;
  double edep_off1[array] = {0.};
  double edep_off2[array] = {0.};
  double edep_off3[array] = {0.};
  double edep_off4[array] = {0.};
  double totedep_off = 0.;
  int x, y;
  int No_event = (i - 1)*1e5;//each file has 1e5 events. 200 files per settings
  double angle;
  double gap = 0.1;//1mm gap
  double cry_x = 2;//2cm in x-dimension
  double NPS_dist = 400;//4m distance of NPS from the target
  double NPS_angle1 = 6.3;//NPS center angle
  double NPS_angle2 = 16.6;//NPS center angle
  double NPS_angle3 = 26.9;//NPS center angle
  double NPS_angle4 = 37.2;//NPS center angle

  double MeV_to_rad_per_hr = 100*3600/(0.6624*No_event);
  //double MeV_to_rad_per_hr = ((1.6e-19)/0.6624)/*(J/kg)*/*((10e-6)/(1.6e-19))/*(1uA = electron/sec)*/*3600/*(second to hour)*/*100/*Gy to rad*/*1e6/*eV to MeV*//No_event;//
  //(100*((1.6e-13)/(0.6624)*(3600/(1.6e-13)))/(1e-7);//100*(((1.6e-13)/0.6624)/((1.6e-20)/3600));

  ch_on1->SetBranchAddress("edep", edep_on1);
  ch_on2->SetBranchAddress("edep", edep_on2);
  ch_on3->SetBranchAddress("edep", edep_on3);
  ch_on4->SetBranchAddress("edep", edep_on4);
  ch_off1->SetBranchAddress("edep", edep_off1);
  ch_off2->SetBranchAddress("edep", edep_off2);
  ch_off3->SetBranchAddress("edep", edep_off3);
  ch_off4->SetBranchAddress("edep", edep_off4);

  ////set variable bin widths
  double edges[128] = {0.}; //4 NPS positions(31 + 1 bin edges X 4)
  for(int bin_edge = 0 ; bin_edge < 31 ; bin_edge++){
    edges[bin_edge] = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - bin_edge) + 0.5*(gap + cry_x))/400.    );
  }

  edges[bin_edge] = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - bin_edge) + 0.5*(gap + cry_x))/400.    );

  for(int bin_edge = 32 ; bin_edge < 32 + 31 ; bin_edge++){
    edges[bin_edge] = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - (bin_edge - 32)) + 0.5*(gap + cry_x))/400.    );
  }
  edges[bin_edge] = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - (bin_edge - 32)) + 0.5*(gap + cry_x))/400.    );

  for(int bin_edge = 32 + 32 ; bin_edge < 32 + 32 + 31 ; bin_edge++){
    edges[bin_edge] = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - (bin_edge - 32 - 32)) + 0.5*(gap + cry_x))/400.    );
  }
  edges[bin_edge] = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - (bin_edge - 32 - 32)) + 0.5*(gap + cry_x))/400.    );

  for(int bin_edge = 32 + 32 + 32; bin_edge < 32 + 32 + 32 + 31 ; bin_edge++){
    edges[bin_edge] = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - (bin_edge - 32 - 32 - 32)) + 0.5*(gap + cry_x))/400.    );
  }
  edges[bin_edge] = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( ((gap + cry_x)*(15 - (bin_edge - 32 - 32 - 32)) + 0.5*(gap + cry_x))/400.    );

  /* for(int bin_edge = 0 ; bin_edge < 32 ; bin_edge++){ */
  /*   cout<< edges[bin_edge]<<endl;  */
  /* } */
  /* cout<<"---------------------------"<<endl; */
  gStyle->SetOptStat(0);
  TCanvas *c_pattern = new TCanvas("c_pattern", "checking the pattern on NPS", 200, 10, 700, 1000);
  c_pattern->Divide(1,2);
  TCanvas *c_dose = new TCanvas("c_dose", "checking the dose on NPS", 200, 10, 700, 500);
  /* c_pattern->Divide(2,1); */
  TH2F *h_edep_pattern_on = new TH2F("h_edep_pattern_on", "edep pattern, field on", 127, edges, 36, 0, 36);//(x, y)
  TH2F *h_edep_pattern_off = new TH2F("h_edep_pattern_off", "edep pattern, field off", 127, edges, 36, 0, 36);//(x, y)
  TH1F *h_dose_on = new TH1F("h_dose_on", "field on", 127, edges);//in x axis
  h_dose_on->GetXaxis()->SetTitle("angle");
  h_dose_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_dose_off = new TH1F("h_dose_off", "field off", 127, edges);//in x axis
  h_dose_off->GetXaxis()->SetTitle("angle");
  h_dose_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  /* double edepp, edeppp; */
  /* int k; */

  /* for(int i = 98 ; i < 100/\* ch_on1->GetEntries() *\/ ; i++){ */
  /*   k = 0; */
  /*   ch_on1->GetEntry(i); */
  /*   ch_off1->GetEntry(i); */
  /*   for(int j = 0 ; j < array ; j++){ */
  /*     x = int(j/36); */
  /*     y = j%36; */
  /*     angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    ); */
  /*     //h_edep_pattern->Fill(x, y, edep1[j]); */
  /*     edepp = edepp = 0; */
  /*     edepp = edep_on1[j]; */
  /*     cout<<"i = 0, "<<edepp<<endl; */
  /*     ch_on1->GetEntry(i-1); */
  /*     edeppp = edep_on1[j]; */
  /*     cout<<"i = 1,  "<<edeppp<<endl; */
  /*     ch_on1->GetEntry(i); */
  /*     if(i == 98 && edepp == edeppp && edepp!= 0){ */
  /* 	cout<<".............."<<edepp<<", "<<edeppp<<endl; */
  /*     } */
  /*   } */
  /* } */
  /* cout<< ch_on1->GetEntries()<<endl; */
  /* cout<< ch_on2->GetEntries()<<endl; */
  /* cout<< ch_on3->GetEntries()<<endl; */
  /* cout<< ch_on4->GetEntries()<<endl; */
  /* cout<< ch_off1->GetEntries()<<endl; */
  /* cout<< ch_off2->GetEntries()<<endl; */
  /* cout<< ch_off3->GetEntries()<<endl; */
  /* cout<< ch_off4->GetEntries()<<endl; */
  for(int i = 0 ; i < ch_on1->GetEntries() ; i++){
    ch_on1->GetEntry(i);
    ch_off1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep2[j]);
      h_dose_on->Fill(angle, edep_on1[j]*MeV_to_rad_per_hr);
      h_dose_off->Fill(angle, edep_off1[j]*MeV_to_rad_per_hr);
      h_edep_pattern_on->Fill(angle, y, edep_on1[j]);
      h_edep_pattern_off->Fill(angle, y, edep_off1[j]);
    }
  } 

  for(int i = 0 ; i < ch_on2->GetEntries() ; i++){
    ch_on2->GetEntry(i);
    ch_off2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep2[j]);
      h_dose_on->Fill(angle, edep_on2[j]*MeV_to_rad_per_hr);
      h_dose_off->Fill(angle, edep_off2[j]*MeV_to_rad_per_hr);
      h_edep_pattern_on->Fill(angle, y, edep_on2[j]);
      h_edep_pattern_off->Fill(angle, y, edep_off2[j]);
    }
  } 

  for(int i = 0 ; i < ch_on3->GetEntries() ; i++){
    ch_on3->GetEntry(i);
    ch_off3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep3[j]);
      h_dose_on->Fill(angle, edep_on3[j]*MeV_to_rad_per_hr);
      h_dose_off->Fill(angle, edep_off3[j]*MeV_to_rad_per_hr);
      h_edep_pattern_on->Fill(angle, y, edep_on3[j]);
      h_edep_pattern_off->Fill(angle, y, edep_off3[j]);
    }
  } 

  for(int i = 0 ; i < ch_on4->GetEntries() ; i++){
    ch_on4->GetEntry(i);
    ch_off4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      /* cout<<"edep_on : "<<edep_on1[j]<<endl; */
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep4[j]);
      h_dose_on->Fill(angle, edep_on4[j]*MeV_to_rad_per_hr);
      h_dose_off->Fill(angle, edep_off4[j]*MeV_to_rad_per_hr);
      h_edep_pattern_on->Fill(angle, y, edep_on4[j]);
      h_edep_pattern_off->Fill(angle, y, edep_off4[j]);
    }
  } 
  /* c_pattern->cd(1); */
  /* gPad->SetLogy(1); */
  /* h_dose_off->Draw(); */

  //  gPad->SetLogz(0);
  //h_edep_pattern->Draw("colz");
  /* c_pattern->cd(2); */

  c_pattern->cd(1);
  h_edep_pattern_on->GetZaxis()->SetRangeUser(1,2e6);
  gPad->SetLogz(1);
  h_edep_pattern_on->Draw("colz");
  c_pattern->cd(2);
  h_edep_pattern_off->GetZaxis()->SetRangeUser(1,2e6);
  gPad->SetLogz(1);
  h_edep_pattern_off->Draw("colz");

  c_pattern->Print("output/pattern.eps");

  c_dose->cd();
  gPad->SetLogy(1);

  h_dose_off->SetMaximum(1e6);
  h_dose_off->SetMinimum(1);
  h_dose_off->SetLineColor(2);
  h_dose_off->SetTitle("Dose on NPS with field on|off");

  h_dose_on->SetLineColor(4);


  h_dose_off->Draw();
  h_dose_on->Draw("SAME");
  

  TLegend *leg = new TLegend(0.6, 0.65, .9, .9);

  leg->AddEntry(h_dose_off, "field off", "l");
  leg->AddEntry(h_dose_on, "field on", "l");
  leg->Draw();

  c_dose->Print("output/dose.eps");

}
