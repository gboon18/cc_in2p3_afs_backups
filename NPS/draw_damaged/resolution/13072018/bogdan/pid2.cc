{
  TChain *ch_on1 = new TChain("t");
  TChain *ch_on2 = new TChain("t");
  TChain *ch_on3 = new TChain("t");
  TChain *ch_on4 = new TChain("t");
  TChain *ch_off1 = new TChain("t");
  TChain *ch_off2 = new TChain("t");
  TChain *ch_off3 = new TChain("t");
  TChain *ch_off4 = new TChain("t");

  TChain *ch_pid_on1 = new TChain("t2");
  TChain *ch_pid_on2 = new TChain("t2");
  TChain *ch_pid_on3 = new TChain("t2");
  TChain *ch_pid_on4 = new TChain("t2");
  TChain *ch_pid_off1 = new TChain("t2");
  TChain *ch_pid_off2 = new TChain("t2");
  TChain *ch_pid_off3 = new TChain("t2");
  TChain *ch_pid_off4 = new TChain("t2");

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

    ch_pid_on1->Add(file_on_6_3);
    ch_pid_on2->Add(file_on_16_6);
    ch_pid_on3->Add(file_on_26_9);
    ch_pid_on4->Add(file_on_37_2);
    ch_pid_off1->Add(file_off_6_3);
    ch_pid_off2->Add(file_off_16_6);
    ch_pid_off3->Add(file_off_26_9);
    ch_pid_off4->Add(file_off_37_2);
  }
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

  double ene_on1[array] = {0};
  double ene_on2[array] = {0};
  double ene_on3[array] = {0};
  double ene_on4[array] = {0};
  double ene_off1[array] = {0};
  double ene_off2[array] = {0};
  double ene_off3[array] = {0};
  double ene_off4[array] = {0};

  int pid_on1[array] = {0};
  int pid_on2[array] = {0};
  int pid_on3[array] = {0};
  int pid_on4[array] = {0};
  int pid_off1[array] = {0};
  int pid_off2[array] = {0};
  int pid_off3[array] = {0};
  int pid_off4[array] = {0};

  double totedep_off = 0.;
  int x, y;
  int No_event = (i - 1)*1e5;//each file containes 1e5 events and we have 200 files per each settings.
  double angle;
  double gap = 0.1;//1mm gap
  double cry_x = 2;//2cm in x-dimension
  double NPS_dist = 400;//4m distance of NPS from the target
  double NPS_angle1 = 6.3;//NPS center angle
  double NPS_angle2 = 16.6;//NPS center angle
  double NPS_angle3 = 26.9;//NPS center angle
  double NPS_angle4 = 37.2;//NPS center angle

  double MeV_to_rad_per_hr = 100*3600/(0.6624*No_event);

  ch_on1->SetBranchAddress("edep", edep_on1);
  ch_on2->SetBranchAddress("edep", edep_on2);
  ch_on3->SetBranchAddress("edep", edep_on3);
  ch_on4->SetBranchAddress("edep", edep_on4);
  ch_off1->SetBranchAddress("edep", edep_off1);
  ch_off2->SetBranchAddress("edep", edep_off2);
  ch_off3->SetBranchAddress("edep", edep_off3);
  ch_off4->SetBranchAddress("edep", edep_off4);

  ch_pid_on1->SetBranchAddress("ene", ene_on1);
  ch_pid_on2->SetBranchAddress("ene", ene_on2);
  ch_pid_on3->SetBranchAddress("ene", ene_on3);
  ch_pid_on4->SetBranchAddress("ene", ene_on4);
  ch_pid_off1->SetBranchAddress("ene", ene_off1);
  ch_pid_off2->SetBranchAddress("ene", ene_off2);
  ch_pid_off3->SetBranchAddress("ene", ene_off3);
  ch_pid_off4->SetBranchAddress("ene", ene_off4);

  ch_pid_on1->SetBranchAddress("pid", pid_on1);
  ch_pid_on2->SetBranchAddress("pid", pid_on2);
  ch_pid_on3->SetBranchAddress("pid", pid_on3);
  ch_pid_on4->SetBranchAddress("pid", pid_on4);
  ch_pid_off1->SetBranchAddress("pid", pid_off1);
  ch_pid_off2->SetBranchAddress("pid", pid_off2);
  ch_pid_off3->SetBranchAddress("pid", pid_off3);
  ch_pid_off4->SetBranchAddress("pid", pid_off4);

  gStyle->SetOptStat(0);

  TCanvas *c_pattern_pid = new TCanvas("c_pattern_pid", "checking the pattern on NPS each PID", 200, 10, 1400, 2000);
  c_pattern_pid->Divide(3,2);

  TCanvas *c_flux_pid = new TCanvas("c_flux_pid", "checking the energy flux on NPS each PID", 200, 10, 1400, 2000);
  c_flux_pid->Divide(3,2);

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



  TH2F *h_pattern_on = new TH2F("h_pattern_on", "field on",127, edges, 36, 0, 35);
  TH2F *h_pattern_off = new TH2F("h_pattern_off", "field off",127, edges, 36, 0, 35);
  TH2F *h_elec_pattern_on = new TH2F("h_elec_pattern_on", "field on, electron",127, edges, 36, 0, 35);
  TH2F *h_gamma_pattern_on = new TH2F("h_gamma_pattern_on", "field on, gamma",127, edges, 36, 0, 35);
  TH2F *h_elec_pattern_off = new TH2F("h_elec_pattern_off", "field off, electron",127, edges, 36, 0, 35);
  TH2F *h_gamma_pattern_off = new TH2F("h_gamma_pattern_off", "field off, gamma",127, edges, 36, 0, 35);
  TH2F *h_pos_pattern_on = new TH2F("h_pos_pattern_on", "field on, positron",127, edges, 36, 0, 35);
  TH2F *h_pos_pattern_off = new TH2F("h_pos_pattern_off", "field off, positron",127, edges, 36, 0, 35);
  // TH2F *h_unknown_pattern_on = new TH2F("h_unknown_pattern_on", "field on, unknown",127, edges, 36, 0, 35);
  // TH2F *h_unknown_pattern_off = new TH2F("h_unknown_pattern_off", "field off, unknown",127, edges, 36, 0, 35;);

  TH2F *h_flux_on = new TH2F("h_flux_on", "field on",127, edges, 36, 0, 35);
  TH2F *h_flux_off = new TH2F("h_flux_off", "field off",127, edges, 36, 0, 35);
  TH2F *h_elec_flux_on = new TH2F("h_elec_flux_on", "field on, electron",127, edges, 36, 0, 35);
  TH2F *h_gamma_flux_on = new TH2F("h_gamma_flux_on", "field on, gamma",127, edges, 36, 0, 35);
  TH2F *h_elec_flux_off = new TH2F("h_elec_flux_off", "field off, electron",127, edges, 36, 0, 35);
  TH2F *h_gamma_flux_off = new TH2F("h_gamma_flux_off", "field off, gamma",127, edges, 36, 0, 35);
  TH2F *h_pos_flux_on = new TH2F("h_pos_flux_on", "field on, positron",127, edges, 36, 0, 35);
  TH2F *h_pos_flux_off = new TH2F("h_pos_flux_off", "field off, positron",127, edges, 36, 0, 35);
  // TH2F *h_unknown_flux_on = new TH2F("h_unknown_flux_on", "field on, unknown",127, edges, 36, 0, 35);
  // TH2F *h_unknown_flux_off = new TH2F("h_unknown_flux_off", "field off, unknown",127, edges, 36, 0, 35);


  int elec_on = 0, elec_off = 0, pos_on = 0, pos_off = 0, gamma_on = 0, gamma_off = 0, unknown_on = 0, unknown_off = 0; 
  //MeV_to_rad_per_hr
  for(int i = 0 ; i < ch_pid_on1->GetEntries() ; i++){
    ch_pid_on1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_on1[j] == 11)  {h_elec_pattern_on->Fill(angle, y);h_elec_flux_on->Fill(angle, y, ene_on1[j]*MeV_to_rad_per_hr);}
      else if(pid_on1[j] == 22)  {h_gamma_pattern_on->Fill(angle, y);h_gamma_flux_on->Fill(angle, y, ene_on1[j]*MeV_to_rad_per_hr);}
      else if(pid_on1[j] == -11) {h_pos_pattern_on->Fill(angle, y);h_pos_flux_on->Fill(angle, y, ene_on1[j]*MeV_to_rad_per_hr);}
      //      else{unknown_on++;h_unknown_pattern_on->Fill(angle, y); h_unknown_ene_on->Fill(angle, ene_on1[j]*MeV_to_rad_per_hr);}
    }
  } 

  for(int i = 0 ; i < ch_pid_on2->GetEntries() ; i++){
    ch_pid_on2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_on2[j] == 11)  {h_elec_pattern_on->Fill(angle, y);h_elec_flux_on->Fill(angle, y, ene_on2[j]*MeV_to_rad_per_hr);}
      else if(pid_on2[j] == 22)  {h_gamma_pattern_on->Fill(angle, y);h_gamma_flux_on->Fill(angle, y, ene_on2[j]*MeV_to_rad_per_hr);}
      else if(pid_on2[j] == -11) {h_pos_pattern_on->Fill(angle, y);h_pos_flux_on->Fill(angle, y, ene_on2[j]*MeV_to_rad_per_hr);}
      //      else{unknown_on++;h_unknown_pattern_on->Fill(angle, y); h_unknown_ene_on->Fill(angle, ene_on2[j]*MeV_to_rad_per_hr);}
    }
  } 

  for(int i = 0 ; i < ch_pid_on3->GetEntries() ; i++){
    ch_pid_on3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep3[j]);

      if(pid_on3[j] == 11)  {h_elec_pattern_on->Fill(angle, y);h_elec_flux_on->Fill(angle, y, ene_on3[j]*MeV_to_rad_per_hr);}
      else if(pid_on3[j] == 22)  {h_gamma_pattern_on->Fill(angle, y);h_gamma_flux_on->Fill(angle, y, ene_on3[j]*MeV_to_rad_per_hr);}
      else if(pid_on3[j] == -11) {h_pos_pattern_on->Fill(angle, y);h_pos_flux_on->Fill(angle, y, ene_on3[j]*MeV_to_rad_per_hr);}
      //      else{unknown_on++;h_unknown_pattern_on->Fill(angle, y); h_unknown_ene_on->Fill(angle, ene_on3[j]*MeV_to_rad_per_hr);}
    }
  } 

  //  ch_pid_on4->Print();
  //  cout<<"ch_pid_on4 entries : "<<ch_pid_on4->GetEntries()<<endl;
  for(int i = 0 ; i < ch_pid_on4->GetEntries() ; i++){
    ch_pid_on4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep4[j]);
      //      if(ene_on4[j]!=0){cout<<"ene_on4 : "<<ene_on4[j]<<endl;      cout<<ene_on4[j]*MeV_to_rad_per_hr<<endl;}

      if(pid_on4[j] == 11)  {h_elec_pattern_on->Fill(angle, y);h_elec_flux_on->Fill(angle, y, ene_on4[j]*MeV_to_rad_per_hr);}
      else if(pid_on4[j] == 22)  {h_gamma_pattern_on->Fill(angle, y);h_gamma_flux_on->Fill(angle, y, ene_on4[j]*MeV_to_rad_per_hr);}
      else if(pid_on4[j] == -11) {h_pos_pattern_on->Fill(angle, y);h_pos_flux_on->Fill(angle, y, ene_on4[j]*MeV_to_rad_per_hr);}
      //      else{unknown_on++;h_unknown_pattern_on->Fill(angle, y); h_unknown_ene_on->Fill(angle, ene_on4[j]*MeV_to_rad_per_hr);}
    }
  }
  cout<<"you are here1"<<endl;
  ////////////////////////////////////////////////////////////////////////////////
  for(int i = 0 ; i < ch_pid_off1->GetEntries() ; i++){
    ch_pid_off1->GetEntry(i); 
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );

      if(pid_off1[j] == 11)  {h_elec_pattern_off->Fill(angle, y);h_elec_flux_off->Fill(angle, y, ene_off1[j]*MeV_to_rad_per_hr);}
      else if(pid_off1[j] == 22)  {h_gamma_pattern_off->Fill(angle, y);h_gamma_flux_off->Fill(angle, y, ene_off1[j]*MeV_to_rad_per_hr);}
      else if(pid_off1[j] == -11) {h_pos_pattern_off->Fill(angle, y);h_pos_flux_off->Fill(angle, y, ene_off1[j]*MeV_to_rad_per_hr);}
      //      else{unknown_off++;h_unknown_pattern_off->Fill(angle, y); h_unknown_ene_off->Fill(angle, ene_off1[j]*MeV_to_rad_per_hr);}
    }
  } 
  cout<<"you are here2"<<endl;
  for(int i = 0 ; i < ch_pid_off2->GetEntries() ; i++){
    ch_pid_off2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );

      if(pid_off2[j] == 11)  {h_elec_pattern_off->Fill(angle, y);h_elec_flux_off->Fill(angle, y, ene_off2[j]*MeV_to_rad_per_hr);}
      else if(pid_off2[j] == 22)  {h_gamma_pattern_off->Fill(angle, y);h_gamma_flux_off->Fill(angle, y, ene_off2[j]*MeV_to_rad_per_hr);}
      else if(pid_off2[j] == -11) {h_pos_pattern_off->Fill(angle, y);h_pos_flux_off->Fill(angle, y, ene_off2[j]*MeV_to_rad_per_hr);}
      //      else{unknown_off++;h_unknown_pattern_off->Fill(angle, y); h_unknown_ene_off->Fill(angle, ene_off2[j]*MeV_to_rad_per_hr);}
    }
  } 
  cout<<"you are here3"<<endl;
  for(int i = 0 ; i < ch_pid_off3->GetEntries() ; i++){
    ch_pid_off3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );

      if(pid_off3[j] == 11)  {h_elec_pattern_off->Fill(angle, y);h_elec_flux_off->Fill(angle, y, ene_off3[j]*MeV_to_rad_per_hr);}
      else if(pid_off3[j] == 22)  {h_gamma_pattern_off->Fill(angle, y);h_gamma_flux_off->Fill(angle, y, ene_off3[j]*MeV_to_rad_per_hr);}
      else if(pid_off3[j] == -11) {h_pos_pattern_off->Fill(angle, y);h_pos_flux_off->Fill(angle, y, ene_off3[j]*MeV_to_rad_per_hr);}
      //      else{unknown_off++;h_unknown_pattern_off->Fill(angle, y); h_unknown_ene_off->Fill(angle, ene_off3[j]*MeV_to_rad_per_hr);}
    }
  } 
  cout<<"you are here4"<<endl;
  for(int i = 0 ; i < ch_pid_off4->GetEntries() ; i++){
    ch_pid_off4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_off4[j] == 11)  {h_elec_pattern_off->Fill(angle, y);h_elec_flux_off->Fill(angle, y, ene_off4[j]*MeV_to_rad_per_hr);}
      else if(pid_off4[j] == 22)  {h_gamma_pattern_off->Fill(angle, y);h_gamma_flux_off->Fill(angle, y, ene_off4[j]*MeV_to_rad_per_hr);}
      else if(pid_off4[j] == -11) {h_pos_pattern_off->Fill(angle, y);h_pos_flux_off->Fill(angle, y, ene_off4[j]*MeV_to_rad_per_hr);}
      //      else{unknown_off++;h_unknown_pattern_off->Fill(angle, y); h_unknown_ene_off->Fill(angle, ene_off4[j]*MeV_to_rad_per_hr);}
    }

  }
  cout<<"you are here5"<<endl;


  c_pattern_pid->cd(1);
  gPad->SetLogz(1);
  h_elec_pattern_on->GetZaxis()->SetRangeUser(1,3e4); 
  h_elec_pattern_on->Draw("colz");

  c_pattern_pid->cd(2);
  gPad->SetLogz(1);
  h_pos_pattern_on->GetZaxis()->SetRangeUser(1,3e4);
  h_pos_pattern_on->Draw("colz");

  c_pattern_pid->cd(3);
  gPad->SetLogz(1);
  h_gamma_pattern_on->GetZaxis()->SetRangeUser(1,3e4); 
  h_gamma_pattern_on->Draw("colz");

  c_pattern_pid->cd(4);
  gPad->SetLogz(1);
  h_elec_pattern_off->GetZaxis()->SetRangeUser(1,3e4); 
  h_elec_pattern_off->Draw("colz");

  c_pattern_pid->cd(5);
  gPad->SetLogz(1);
  h_pos_pattern_off->GetZaxis()->SetRangeUser(1,3e4);
  h_pos_pattern_off->Draw("colz");

  c_pattern_pid->cd(6);
  gPad->SetLogz(1);
  h_gamma_pattern_off->GetZaxis()->SetRangeUser(1,3e4); 
  h_gamma_pattern_off->Draw("colz");

  c_pattern_pid->Print("output/pattern2.eps");

  c_flux_pid->cd(1);
  gPad->SetLogz(1);
  h_elec_flux_on->GetZaxis()->SetRangeUser(1,3e4); 
  h_elec_flux_on->Draw("colz");

  c_flux_pid->cd(2);
  gPad->SetLogz(1);
  h_pos_flux_on->GetZaxis()->SetRangeUser(1,3e4);
  h_pos_flux_on->Draw("colz");

  c_flux_pid->cd(3);
  gPad->SetLogz(1);
  h_gamma_flux_on->GetZaxis()->SetRangeUser(1,3e4); 
  h_gamma_flux_on->Draw("colz");

  c_flux_pid->cd(4);
  gPad->SetLogz(1);
  h_elec_flux_off->GetZaxis()->SetRangeUser(1,3e4); 
  h_elec_flux_off->Draw("colz");

  c_flux_pid->cd(5);
  gPad->SetLogz(1);
  h_pos_flux_off->GetZaxis()->SetRangeUser(1,3e4);
  h_pos_flux_off->Draw("colz");

  c_flux_pid->cd(6);
  gPad->SetLogz(1);
  h_gamma_flux_off->GetZaxis()->SetRangeUser(1,3e4); 
  h_gamma_flux_off->Draw("colz");

  c_flux_pid->Print("output/flux2.eps");

}
