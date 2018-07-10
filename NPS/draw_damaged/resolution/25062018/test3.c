{
  TChain *ch_on1 = new TChain("t");
  TChain *ch_on2 = new TChain("t");
  TChain *ch_on3 = new TChain("t");
  TChain *ch_on4 = new TChain("t");
  TChain *ch_off1 = new TChain("t");
  TChain *ch_off2 = new TChain("t");
  TChain *ch_off3 = new TChain("t");
  TChain *ch_off4 = new TChain("t");

  /* TChain *ch_ene_on1 = new TChain("t2"); */
  /* TChain *ch_ene_on2 = new TChain("t2"); */
  /* TChain *ch_ene_on3 = new TChain("t2"); */
  /* TChain *ch_ene_on4 = new TChain("t2"); */
  /* TChain *ch_ene_off1 = new TChain("t2"); */
  /* TChain *ch_ene_off2 = new TChain("t2"); */
  /* TChain *ch_ene_off3 = new TChain("t2"); */
  /* TChain *ch_ene_off4 = new TChain("t2"); */

  TChain *ch_pid_on1 = new TChain("t2");
  TChain *ch_pid_on2 = new TChain("t2");
  TChain *ch_pid_on3 = new TChain("t2");
  TChain *ch_pid_on4 = new TChain("t2");
  TChain *ch_pid_off1 = new TChain("t2");
  TChain *ch_pid_off2 = new TChain("t2");
  TChain *ch_pid_off3 = new TChain("t2");
  TChain *ch_pid_off4 = new TChain("t2");

  //  string dir_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/25062018/rootfiles_backup_field_str_1/";
  string dir_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/25062018/rootfiles_flux/";
  string field_on_str = "dose2_field_on_";
  string field_off_str = "dose2_field_off_";
  string file_end_str = ".root";


  for(int i = 1; i < 2 /* 101 */ ; i++){
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

    /* ch_ene_on1->Add(file_on_6_3); */
    /* ch_ene_on2->Add(file_on_16_6); */
    /* ch_ene_on3->Add(file_on_26_9); */
    /* ch_ene_on4->Add(file_on_37_2); */
    /* ch_ene_off1->Add(file_off_6_3); */
    /* ch_ene_off2->Add(file_off_16_6); */
    /* ch_ene_off3->Add(file_off_26_9); */
    /* ch_ene_off4->Add(file_off_37_2); */

    ch_pid_on1->Add(file_on_6_3);
    ch_pid_on2->Add(file_on_16_6);
    ch_pid_on3->Add(file_on_26_9);
    ch_pid_on4->Add(file_on_37_2);
    ch_pid_off1->Add(file_off_6_3);
    ch_pid_off2->Add(file_off_16_6);
    ch_pid_off3->Add(file_off_26_9);
    ch_pid_off4->Add(file_off_37_2);
  }
  //  cout<<ch_pid_on1->GetEntries();<<endl;
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
  int No_event = 1e7;//each file containes 1e5 events and we have 100 files per each settings.
  double angle;
  double gap = 0.1;//1mm gap
  double cry_x = 2;//2cm in x-dimension
  double NPS_dist = 400;//4m distance of NPS from the target
  double NPS_angle1 = 6.3;//NPS center angle
  double NPS_angle2 = 16.6;//NPS center angle
  double NPS_angle3 = 26.9;//NPS center angle
  double NPS_angle4 = 37.2;//NPS center angle

  double MeV_to_rad_per_hr = 100*3600/(0.6624*No_event);
  //  double MeV_to_rad_per_hr = ((1.6e-19)/0.6624)/*(J/kg)*/*((10e-6)/(1.6e-19))/*(1uA = electron/sec)*/*3600/*(second to hour)*/*100/*Gy to rad*/*1e6/*eV to MeV*//No_event;//
  //(100*((1.6e-13)/(0.6624)*(3600/(1.6e-13)))/(1e-7);//100*(((1.6e-13)/0.6624)/((1.6e-20)/3600));

  ch_on1->SetBranchAddress("edep", edep_on1);
  ch_on2->SetBranchAddress("edep", edep_on2);
  ch_on3->SetBranchAddress("edep", edep_on3);
  ch_on4->SetBranchAddress("edep", edep_on4);
  ch_off1->SetBranchAddress("edep", edep_off1);
  ch_off2->SetBranchAddress("edep", edep_off2);
  ch_off3->SetBranchAddress("edep", edep_off3);
  ch_off4->SetBranchAddress("edep", edep_off4);

  /* ch_ene_on1->SetBranchAddress("ene", ene_on1); */
  /* ch_ene_on2->SetBranchAddress("ene", ene_on2); */
  /* ch_ene_on3->SetBranchAddress("ene", ene_on3); */
  /* ch_ene_on4->SetBranchAddress("ene", ene_on4); */
  /* ch_ene_off1->SetBranchAddress("ene", ene_off1); */
  /* ch_ene_off2->SetBranchAddress("ene", ene_off2); */
  /* ch_ene_off3->SetBranchAddress("ene", ene_off3); */
  /* ch_ene_off4->SetBranchAddress("ene", ene_off4); */

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

  TCanvas *c_pattern = new TCanvas("c_pattern", "checking the pattern on NPS", 200, 10, 700, 1000);
  c_pattern->Divide(1,2);
  TH2F *h_edep_pattern_on = new TH2F("h_edep_pattern_on", "edep pattern, field on", 41, 1, 42, 36, 0, 36);//(x, y)
  TH2F *h_flux_pattern_on = new TH2F("h_flux_pattern_on", "flux pattern, field on", 41, 1, 42, 36, 0, 36);//(x, y)

  int elec_on = 0, elec_off = 0, pos_on = 0, pos_off = 0, gamma_on = 0, gamma_off = 0, unknown_on = 0, unknown_off = 0; 
  int ene = 0, ene_tot=0;
  for(int i = 0 ; i < ch_pid_on1->GetEntries() ; i++){
    ch_pid_on1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_flux_pattern_on->Fill(angle, y, ene_on1[j]*MeV_to_rad_per_hr);
      /* cout<<i<<", "<<j<<", "<<pid_on1[j]<<", "<<ene_on1[j]<<endl; */
      ene += ene_on1[j];
    }
  } 
  cout<<ene<<endl;
  for(int i = 0 ; i < ch_on1->GetEntries() ; i++){
    ch_on1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_edep_pattern_on->Fill(angle, y, edep_on1[j]*MeV_to_rad_per_hr);
      ene_tot += edep_on1[j];
    }
  } 
  cout<<ene_tot<<endl;

  c_pattern->cd(1);
  gPad->SetLogz();
  h_flux_pattern_on->GetZaxis()->SetRangeUser(1,3e3);
  h_flux_pattern_on->Draw("colz");
  c_pattern->cd(2);
  gPad->SetLogz();
  h_edep_pattern_on->GetZaxis()->SetRangeUser(1,3e3);
  h_edep_pattern_on->Draw("colz");

}
