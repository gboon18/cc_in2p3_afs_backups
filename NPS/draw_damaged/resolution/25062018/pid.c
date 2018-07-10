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

  string dir_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/25062018/rootfiles_flux/";
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
  int No_event = 1e7;
  double angle;
  double gap = 0.1;//1mm gap
  double cry_x = 2;//2cm in x-dimension
  double NPS_dist = 400;//4m distance of NPS from the target
  double NPS_angle1 = 6.3;//NPS center angle
  double NPS_angle2 = 16.6;//NPS center angle
  double NPS_angle3 = 26.9;//NPS center angle
  double NPS_angle4 = 37.2;//NPS center angle

  double MeV_to_rad_per_hr = ((1.6e-19)/0.6624)/*(J/kg)*/*((10e-6)/(1.6e-19))/*(1uA = electron/sec)*/*3600/*(second to hour)*/*100/*Gy to rad*/*1e6/*eV to MeV*//No_event;//
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

  gStyle->SetOptStat(0);
  TCanvas *c_pattern = new TCanvas("c_pattern", "checking the background on NPS and dose", 200, 10, 700, 500);
  /* c_pattern->Divide(2,1); */

  TCanvas *c_pid = new TCanvas("c_pid", "checking the pid on NPS", 200, 10, 1400, 1000);
  c_pid->Divide(2,2);

  TCanvas *c_test = new TCanvas("c_test", "checking the flux on NPS", 200, 10, 700, 1000);
  c_test->Divide(1,2);

  //  TH2F *h_edep_pattern = new TH2F("h_edep_pattern", "edep pattern", 31, 0, 31, 36, 0, 36);//(x, y)
  TH1F *h_dose_on = new TH1F("h_dose_on", "field on", 41, 1, 42);//in x axis
  h_dose_on->GetXaxis()->SetTitle("angle");
  h_dose_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_dose_off = new TH1F("h_dose_off", "field off", 41, 1, 42);//in x axis
  h_dose_off->GetXaxis()->SetTitle("angle");
  h_dose_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH2F *h_pattern_on = new TH2F("h_pattern_on", "field on",41, 1, 42, 36, 0, 35);
  TH2F *h_pattern_off = new TH2F("h_pattern_off", "field off",41, 1, 42, 36, 0, 35);
  TH2F *h_elec_pattern_on = new TH2F("h_elec_pattern_on", "field on, electron",41, 1, 42, 36, 0, 35);
  TH2F *h_gamma_pattern_on = new TH2F("h_gamma_pattern_on", "field on, gamma",41, 1, 42, 36, 0, 35);
  TH2F *h_elec_pattern_off = new TH2F("h_elec_pattern_off", "field off, electron",41, 1, 42, 36, 0, 35);
  TH2F *h_gamma_pattern_off = new TH2F("h_gamma_pattern_off", "field off, gamma",41, 1, 42, 36, 0, 35);

  for(int i = 0 ; i < ch_pid_on1->GetEntries() ; i++){
    /* ch_on1->GetEntry(i); */
    /* ch_off1->GetEntry(i); */
    /* ch_ene_on1->GetEntry(i); */
    /* ch_ene_off1->GetEntry(i); */
    ch_pid_on1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep1[j]);
      /* cout<<"edep_on : "<<edep_on1[j]<<endl; */
      /* cout<<"edep_off : "<<edep_off1[j]<<endl; */
      /* if(ene_off1[j]) cout<<ene_off1[j]<<endl; */
      /* if(pid_off1[j] == 11) cout<<pid_off1[j]<<endl; */
      h_pattern_on->Fill(angle, y, ene_on1[j]);
      if(pid_on1[j] == 11) {/* cout<<"working"<<endl; */ h_elec_pattern_on->Fill(angle, y, ene_on1[j]);}
      if(pid_on1[j] == 22) h_gamma_pattern_on->Fill(angle, y, ene_on1[j]);
    }
  } 

  for(int i = 0 ; i < ch_pid_on2->GetEntries() ; i++){
    /* ch_on2->GetEntry(i); */
    /* ch_off2->GetEntry(i); */
    ch_pid_on2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_pattern_on->Fill(angle, y, ene_on2[j]);
      if(pid_on2[j] == 11) {/* cout<<"working"<<endl; */ h_elec_pattern_on->Fill(angle, y, ene_on2[j]);}
      if(pid_on2[j] == 22) h_gamma_pattern_on->Fill(angle, y, ene_on2[j]);
    }
  } 

  for(int i = 0 ; i < ch_pid_on3->GetEntries() ; i++){
    /* ch_on3->GetEntry(i); */
    /* ch_off3->GetEntry(i); */
    ch_pid_on3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep3[j]);
      h_pattern_on->Fill(angle, y, ene_on3[j]);
      if(pid_on3[j] == 11) {/* cout<<"working"<<endl; */ h_elec_pattern_on->Fill(angle, y, ene_on3[j]);}
      if(pid_on3[j] == 22) h_gamma_pattern_on->Fill(angle, y, ene_on3[j]);
    }
  } 

  for(int i = 0 ; i < ch_pid_on4->GetEntries() ; i++){
    /* ch_on4->GetEntry(i); */
    /* ch_off4->GetEntry(i); */
    ch_pid_on4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep4[j]);
      h_pattern_on->Fill(angle, y, ene_on4[j]);
      if(pid_on4[j] == 11) {/* cout<<"working"<<endl; */ h_elec_pattern_on->Fill(angle, y, ene_on4[j]);}
      if(pid_on4[j] == 22) h_gamma_pattern_on->Fill(angle, y, ene_on4[j]);
    }

    ////////////////////////////////////////////////////////////////////////////////
    for(int i = 0 ; i < ch_pid_off1->GetEntries() ; i++){
      /* ch_on1->GetEntry(i); */
      /* ch_off1->GetEntry(i); */
      /* ch_ene_on1->GetEntry(i); */
      /* ch_ene_off1->GetEntry(i); */
      ch_pid_off1->GetEntry(i); 
      for(int j = 0 ; j < array ; j++){
	x = int(j/36);
	y = j%36;
	angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
	//h_edep_pattern->Fill(x, y, edep1[j]);
	/* cout<<"edep_on : "<<edep_on1[j]<<endl; */
	/* cout<<"edep_off : "<<edep_off1[j]<<endl; */
	/* if(ene_off1[j]) cout<<ene_off1[j]<<endl; */
	/* if(pid_off1[j] == 11) cout<<pid_off1[j]<<endl; */
	h_pattern_off->Fill(angle, y, ene_off1[j]);
	if(pid_off1[j] == 11)  { /* cout<<h1<<endl; cout<<i<<", "<<ene_off1[j]<<"["<<j<<"]"<<endl; */  h_elec_pattern_off->Fill(angle, y, ene_off1[j]);}
	/* if(ene_off1[j] > 78 && ene_off1[j] < 78.26) {cout<<i<<endl; cout<<ene_off1[j]<<endl;} */
	if(pid_off1[j] == 22) h_gamma_pattern_off->Fill(angle, y, ene_off1[j]);
      }
    } 

    for(int i = 0 ; i < ch_pid_off2->GetEntries() ; i++){
      /* ch_on2->GetEntry(i); */
      /* ch_off2->GetEntry(i); */
      ch_pid_off2->GetEntry(i);
      for(int j = 0 ; j < array ; j++){
	x = int(j/36);
	y = j%36;
	angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
	//h_edep_pattern->Fill(x, y, edep2[j]);
	h_pattern_off->Fill(angle, y, ene_off2[j]);
	if(pid_off2[j] == 11) {/* cout<<ene_off1[j]<<"["<<j<<"]"<<endl */; h_elec_pattern_off->Fill(angle, y, ene_off2[j]);}
	if(pid_off2[j] == 22) h_gamma_pattern_off->Fill(angle, y, ene_off2[j]);
      }
    } 

    for(int i = 0 ; i < ch_pid_off3->GetEntries() ; i++){
      /* ch_on3->GetEntry(i); */
      /* ch_off3->GetEntry(i); */
      ch_pid_off3->GetEntry(i);
      for(int j = 0 ; j < array ; j++){
	x = int(j/36);
	y = j%36;
	angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
	//h_edep_pattern->Fill(x, y, edep3[j]);
	h_pattern_off->Fill(angle, y, ene_off3[j]);
	if(pid_off3[j] == 11) {/* cout<<ene_off1[j]<<"["<<j<<"]"<<endl; */ h_elec_pattern_off->Fill(angle, y, ene_off3[j]);}
	if(pid_off3[j] == 22) h_gamma_pattern_off->Fill(angle, y, ene_off3[j]);
      }
    } 

    for(int i = 0 ; i < ch_pid_off4->GetEntries() ; i++){
      /* ch_on4->GetEntry(i); */
      /* ch_off4->GetEntry(i); */
      ch_pid_off4->GetEntry(i);
      for(int j = 0 ; j < array ; j++){
	x = int(j/36);
	y = j%36;
	angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
	//h_edep_pattern->Fill(x, y, edep4[j]);
	h_pattern_off->Fill(angle, y, ene_off4[j]);
	if(pid_off4[j] == 11) {/* cout<<ene_off1[j]<<"["<<j<<"]"<<endl; */ h_elec_pattern_off->Fill(angle, y, ene_off4[j]);}
	if(pid_off4[j] == 22) h_gamma_pattern_off->Fill(angle, y, ene_off4[j]);
      }

    }
  } 
  /* c_pattern->cd(1); */
  /* gPad->SetLogy(1); */
  /* h_dose_off->Draw(); */

  //  gPad->SetLogz(0);
  //h_edep_pattern->Draw("colz");
  /* c_pattern->cd(2); */
  c_pid->cd(1);
  gPad->SetLogz(1);
  h_elec_pattern_on->GetZaxis()->SetRangeUser(1,1e7); 
  h_elec_pattern_on->Draw("colz");
  c_pid->cd(2);
  gPad->SetLogz(1);
  h_elec_pattern_off->GetZaxis()->SetRangeUser(1,1e7);
  h_elec_pattern_off->Draw("colz");
  c_pid->cd(3);
  gPad->SetLogz(1);
  h_gamma_pattern_on->GetZaxis()->SetRangeUser(1,1e7);
  h_gamma_pattern_on->Draw("colz");
  c_pid->cd(4);
  gPad->SetLogz(1);
  h_gamma_pattern_off->GetZaxis()->SetRangeUser(1,1e7);
  h_gamma_pattern_off->Draw("colz");


  c_test->cd(1);
  gPad->SetLogz(1);
  h_pattern_on->GetZaxis()->SetRangeUser(1,1e7); 
  h_pattern_on->Draw("colz");
  c_test->cd(2);
  gPad->SetLogz(1);
  h_pattern_off->GetZaxis()->SetRangeUser(1,1e7);
  h_pattern_off->Draw("colz");

  /* c_pattern->cd(); */
  /* gPad->SetLogy(1); */

  /* h_dose_off->SetMaximum(1e7); */
  /* h_dose_off->SetMinimum(1); */
  /* h_dose_off->SetLineColor(2); */
  /* h_dose_off->SetTitle("Dose on NPS with field on|off, 5cm grid only"); */

  /* h_dose_on->SetLineColor(4); */


  /* h_dose_off->Draw(); */
  /* h_dose_on->Draw("SAME"); */
  

  /* TLegend *leg = new TLegend(0.6, 0.65, .9, .9); */

  /* leg->AddEntry(h_dose_off, "field off", "l"); */
  /* leg->AddEntry(h_dose_on, "field on", "l"); */
  /* leg->Draw(); */


}
