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
  double normalization = (1/(No_event));//*11e3));

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



  // TH1F *h_ene_off = new TH1F("h_ene_off", "field off", 127, edges);//in x axis
  // h_ene_off->GetXaxis()->SetTitle("angle");
  // h_ene_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH1F *h_ene_off_0 = new TH1F("h_ene_off_0", "field off 0", 1e4, 0, 1e4);//in x axis
  h_ene_off_0->GetXaxis()->SetTitle("Energy");
  h_ene_off_0->GetYaxis()->SetTitle("");
  TH1F *h_ene_off_1 = new TH1F("h_ene_off_1", "field off 1", 1e4, 0, 1e4);//in x axis
  h_ene_off_1->GetXaxis()->SetTitle("Energy");
  h_ene_off_1->GetYaxis()->SetTitle("");

  TH1F *h_ene_off_2 = new TH1F("h_ene_off_2", "field off 0", 1e4, 0, 1e4);//in x axis
  h_ene_off_2->GetXaxis()->SetTitle("Energy");
  h_ene_off_2->GetYaxis()->SetTitle("");
  TH1F *h_ene_off_3 = new TH1F("h_ene_off_3", "field off 1", 1e4, 0, 1e4);//in x axis
  h_ene_off_3->GetXaxis()->SetTitle("Energy");
  h_ene_off_3->GetYaxis()->SetTitle("");

  TH1F *h_ene_off_4 = new TH1F("h_ene_off_4", "field off 0", 1e4, 0, 1e4);//in x axis
  h_ene_off_4->GetXaxis()->SetTitle("Energy");
  h_ene_off_4->GetYaxis()->SetTitle("");
  TH1F *h_ene_off_5 = new TH1F("h_ene_off_5", "field off 1", 1e4, 0, 1e4);//in x axis
  h_ene_off_5->GetXaxis()->SetTitle("Energy");
  h_ene_off_5->GetYaxis()->SetTitle("");

  for(int i = 0 ; i < ch_pid_off1->GetEntries() ; i++){
    ch_pid_off1->GetEntry(i); 
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_off1[j] == 22 && angle < 10){h_ene_off_0->Fill(ene_off1[j]);}//, normalization);}//*normalization);}//cout<<ene_off1[j]*normalization<<endl;}
      else if(pid_off1[j] == 22 && angle > 10){h_ene_off_1->Fill(ene_off1[j]);}//, normalization);}//*normalization);}
      else if(pid_off1[j] == 11 && angle < 10){h_ene_off_2->Fill(ene_off1[j]);}//, normalization);}//*normalization);}//cout<<ene_off1[j]*normalization<<endl;}
      else if(pid_off1[j] == 11 && angle > 10){h_ene_off_3->Fill(ene_off1[j]);}//, normalization);}//*normalization);}
      else if(pid_off1[j] == -11 && angle < 10){h_ene_off_4->Fill(ene_off1[j]);}//, normalization);}//*normalization);}//cout<<ene_off1[j]*normalization<<endl;}
      else if(pid_off1[j] == -11 && angle > 10){h_ene_off_5->Fill(ene_off1[j]);}//, normalization);}//*normalization);}
    }
  } 
  for(int i = 0 ; i < ch_pid_off2->GetEntries() ; i++){
    ch_pid_off2->GetEntry(i); 
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_off2[j] == 22 && angle < 10){h_ene_off_0->Fill(ene_off2[j]);}//, normalization);}//*normalization);}
      else if(pid_off2[j] == 22 && angle > 10){h_ene_off_1->Fill(ene_off2[j]);}//, normalization);}//*normalization);}
      else if(pid_off2[j] == 11 && angle < 10){h_ene_off_2->Fill(ene_off2[j]);}//, normalization);}//*normalization);}
      else if(pid_off2[j] == 11 && angle > 10){h_ene_off_3->Fill(ene_off2[j]);}//, normalization);}//*normalization);}
      else if(pid_off2[j] == -11 && angle < 10){h_ene_off_4->Fill(ene_off2[j]);}//, normalization);}//*normalization);}
      else if(pid_off2[j] == -11 && angle > 10){h_ene_off_5->Fill(ene_off2[j]);}//, normalization);}//*normalization);}
    }
  } 
  for(int i = 0 ; i < ch_pid_off3->GetEntries() ; i++){
    ch_pid_off3->GetEntry(i); 
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_off3[j] == 22 && angle < 10){h_ene_off_0->Fill(ene_off3[j]);}//, normalization);}//*normalization);}
      else if(pid_off3[j] == 22 && angle > 10){h_ene_off_1->Fill(ene_off3[j]);}//, normalization);}//*normalization);}
      else if(pid_off3[j] == 11 && angle > 10){h_ene_off_2->Fill(ene_off3[j]);}//, normalization);}//*normalization);}
      else if(pid_off3[j] == 11 && angle > 10){h_ene_off_3->Fill(ene_off3[j]);}//, normalization);}//*normalization);}
      else if(pid_off3[j] == -11 && angle > 10){h_ene_off_4->Fill(ene_off3[j]);}//, normalization);}//*normalization);}
      else if(pid_off3[j] == -11 && angle > 10){h_ene_off_5->Fill(ene_off3[j]);}//, normalization);}//*normalization);}
    }
  } 
  for(int i = 0 ; i < ch_pid_off4->GetEntries() ; i++){
    ch_pid_off4->GetEntry(i); 
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      if(pid_off4[j] == 22 && angle < 10){h_ene_off_0->Fill(ene_off4[j]);}//, normalization);}//*normalization);}
      else if(pid_off4[j] == 22 && angle > 10){h_ene_off_1->Fill(ene_off4[j]);}//, normalization);}//*normalization);}
      else if(pid_off4[j] == 11 && angle > 10){h_ene_off_2->Fill(ene_off4[j]);}//, normalization);}//*normalization);}
      else if(pid_off4[j] == 11 && angle > 10){h_ene_off_3->Fill(ene_off4[j]);}//, normalization);}//*normalization);}
      else if(pid_off4[j] == -11 && angle > 10){h_ene_off_4->Fill(ene_off4[j]);}//, normalization);}//*normalization);}
      else if(pid_off4[j] == -11 && angle > 10){h_ene_off_5->Fill(ene_off4[j]);}//, normalization);}//*normalization);}
    }
  } 

  TCanvas *c_ene = new TCanvas("c_ene", "checking the background on NPS and dose", 200, 10, 700, 500);
  c_ene->cd(); 
  gPad->SetLogy(1); 
  gPad->SetLogx(1); 

  // h_ene_off_0->SetMaximum(1e-10); 
  // h_ene_off_0->SetMinimum(1); 
  h_ene_off_0->SetLineColor(2); 
  h_ene_off_0->SetTitle("gamma"); 

  h_ene_off_1->SetLineColor(4); 

  h_ene_off_0->Draw(); 
  h_ene_off_1->Draw("SAME"); 

  TLegend *leg = new TLegend(0.6, 0.65, .9, .9); 

  leg->AddEntry(h_ene_off_0, "0~10", "l"); 
  leg->AddEntry(h_ene_off_1, "10~40", "l"); 
  leg->Draw(); 

  c_ene->Print("output/ene.eps");

  TCanvas *c_ene2 = new TCanvas("c_ene2", "checking the background on NPS and dose", 200, 10, 700, 500);
  c_ene2->cd(); 
  gPad->SetLogy(1); 
  gPad->SetLogx(1); 

  // h_ene_off_2->SetMaximum(1e-10); 
  // h_ene_off_2->SetMinimum(1); 
  h_ene_off_2->SetLineColor(2); 
  h_ene_off_2->SetTitle("electron"); 

  h_ene_off_3->SetLineColor(4); 

  h_ene_off_2->Draw(); 
  h_ene_off_3->Draw("SAME"); 

  TLegend *leg = new TLegend(0.6, 0.65, .9, .9); 

  leg->AddEntry(h_ene_off_2, "0~10", "l"); 
  leg->AddEntry(h_ene_off_3, "10~40", "l"); 
  leg->Draw(); 

  c_ene2->Print("output/ene2.eps");

  TCanvas *c_ene3 = new TCanvas("c_ene3", "checking the background on NPS and dose", 200, 10, 700, 500);
  c_ene3->cd(); 
  gPad->SetLogy(1); 
  gPad->SetLogx(1); 

  // h_ene_off_2->SetMaximum(1e-10); 
  // h_ene_off_2->SetMinimum(1); 
  h_ene_off_4->SetLineColor(2); 
  h_ene_off_4->SetTitle("positron"); 

  h_ene_off_5->SetLineColor(4); 

  h_ene_off_4->Draw(); 
  h_ene_off_5->Draw("SAME"); 

  TLegend *leg = new TLegend(0.6, 0.65, .9, .9); 

  leg->AddEntry(h_ene_off_4, "0~10", "l"); 
  leg->AddEntry(h_ene_off_5, "10~40", "l"); 
  leg->Draw(); 

  c_ene3->Print("output/ene3.eps");


}
