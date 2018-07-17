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


  double elec_on1[array] = {0.};
  double elec_on2[array] = {0.};
  double elec_on3[array] = {0.};
  double elec_on4[array] = {0.};
  double pos_on1[array] = {0.};
  double pos_on2[array] = {0.};
  double pos_on3[array] = {0.};
  double pos_on4[array] = {0.};
  double gamma_on1[array] = {0.};
  double gamma_on2[array] = {0.};
  double gamma_on3[array] = {0.};
  double gamma_on4[array] = {0.};
  double elec_off1[array] = {0.};
  double elec_off2[array] = {0.};
  double elec_off3[array] = {0.};
  double elec_off4[array] = {0.};
  double pos_off1[array] = {0.};
  double pos_off2[array] = {0.};
  double pos_off3[array] = {0.};
  double pos_off4[array] = {0.};
  double gamma_off1[array] = {0.};
  double gamma_off2[array] = {0.};
  double gamma_off3[array] = {0.};
  double gamma_off4[array] = {0.};

  TFile *f = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/09072018/rootfiles_bogdan/histo.root","RECREATE");
  TTree* t_on = new TTree("t_on", "Field on");
  t_on->SetDirectory(f);
  t_on->Branch("elec1", elec_on1, "Eelectron Energy Flux1[1116]/D");
  t_on->Branch("elec2", elec_on2, "Eelectron Energy Flux2[1116]/D");
  t_on->Branch("elec3", elec_on3, "Eelectron Energy Flux3[1116]/D");
  t_on->Branch("elec4", elec_on4, "Eelectron Energy Flux4[1116]/D");
  t_on->Branch("pos1", pos_on1, "Positron Energy Flux1[1116]/D");
  t_on->Branch("pos2", pos_on2, "Positron Energy Flux2[1116]/D");
  t_on->Branch("pos3", pos_on3, "Positron Energy Flux3[1116]/D");
  t_on->Branch("pos4", pos_on4, "Positron Energy Flux4[1116]/D");
  t_on->Branch("gamma1", gamma_on1, "Gamma Energy Flux1[1116]/D");
  t_on->Branch("gamma2", gamma_on2, "Gamma Energy Flux2[1116]/D");
  t_on->Branch("gamma3", gamma_on3, "Gamma Energy Flux3[1116]/D");
  t_on->Branch("gamma4", gamma_on4, "Gamma Energy Flux4[1116]/D");

  TTree* t_off = new TTree("t_off", "Field off");
  t_off->SetDirectory(f);
  t_off->Branch("elec1", elec_off1, "Eelectron Energy Flux1[1116]/D");
  t_off->Branch("elec2", elec_off2, "Eelectron Energy Flux2[1116]/D");
  t_off->Branch("elec3", elec_off3, "Eelectron Energy Flux3[1116]/D");
  t_off->Branch("elec4", elec_off4, "Eelectron Energy Flux4[1116]/D");
  t_off->Branch("pos1", pos_off1, "Positron Energy Flux1[1116]/D");
  t_off->Branch("pos2", pos_off2, "Positron Energy Flux2[1116]/D");
  t_off->Branch("pos3", pos_off3, "Positron Energy Flux3[1116]/D");
  t_off->Branch("pos4", pos_off4, "Positron Energy Flux4[1116]/D");
  t_off->Branch("gamma1", gamma_off1, "Gamma Energy Flux1[1116]/D");
  t_off->Branch("gamma2", gamma_off2, "Gamma Energy Flux2[1116]/D");
  t_off->Branch("gamma3", gamma_off3, "Gamma Energy Flux3[1116]/D");
  t_off->Branch("gamma4", gamma_off4, "Gamma Energy Flux4[1116]/D");


  cout<<"start"<<endl;
  for(int i = 0 ; i < ch_pid_on1->GetEntries() ; i++){
    ch_pid_on1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_on1[j] == 11)  {elec_on1[j] = ene_on1[j];}
      else if(pid_on1[j] == 22)  {gamma_on1[j] = ene_on1[j];}
      else if(pid_on1[j] == -11) {pos_on1[j] = ene_on1[j];}
    } t_on->Fill();  

  } 
  cout<<"on1"<<endl;
  for(int i = 0 ; i < ch_pid_on2->GetEntries() ; i++){
    ch_pid_on2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_on2[j] == 11)  {elec_on2[j] = ene_on2[j];}
      else if(pid_on2[j] == 22)  {gamma_on2[j] = ene_on2[j];}
      else if(pid_on2[j] == -11) {pos_on2[j] = ene_on2[j];}
    }t_on->Fill();  

  } 
  cout<<"on2"<<endl;
  for(int i = 0 ; i < ch_pid_on3->GetEntries() ; i++){
    ch_pid_on3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_on3[j] == 11)  {elec_on3[j] = ene_on3[j];}
      else if(pid_on3[j] == 22)  {gamma_on3[j] = ene_on3[j];}
      else if(pid_on3[j] == -11) {pos_on3[j] = ene_on3[j];}
    }t_on->Fill();  

  } 
  cout<<"on3"<<endl;
  for(int i = 0 ; i < ch_pid_on4->GetEntries() ; i++){
    ch_pid_on4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_on4[j] == 11)  {elec_on4[j] = ene_on4[j];}
      else if(pid_on4[j] == 22)  {gamma_on4[j] = ene_on4[j];}
      else if(pid_on4[j] == -11) {pos_on4[j] = ene_on4[j];}
    }t_on->Fill();  
  }
  //  t_on->Write();
  cout<<"on4"<<endl;
  ///////////////////////////////////////////////////////////////////////////////////

  for(int i = 0 ; i < ch_pid_off1->GetEntries() ; i++){
    ch_pid_off1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_off1[j] == 11)  {elec_off1[j] = ene_off1[j];}
      else if(pid_off1[j] == 22)  {gamma_off1[j] = ene_off1[j];}
      else if(pid_off1[j] == -11) {pos_off1[j] = ene_off1[j];}
    }t_off->Fill();  

  } 
  cout<<"off1"<<endl;
  for(int i = 0 ; i < ch_pid_off2->GetEntries() ; i++){
    ch_pid_off2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_off2[j] == 11)  {elec_off2[j] = ene_off2[j];}
      else if(pid_off2[j] == 22)  {gamma_off2[j] = ene_off2[j];}
      else if(pid_off2[j] == -11) {pos_off2[j] = ene_off2[j];}
    }t_off->Fill();  

  } 
  cout<<"off2"<<endl;
  for(int i = 0 ; i < ch_pid_off3->GetEntries() ; i++){
    ch_pid_off3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_off3[j] == 11)  {elec_off3[j] = ene_off3[j];}
      else if(pid_off3[j] == 22)  {gamma_off3[j] = ene_off3[j];}
      else if(pid_off3[j] == -11) {pos_off3[j] = ene_off3[j];}
    }t_off->Fill();  

  } 
  cout<<"off3"<<endl;
  for(int i = 0 ; i < ch_pid_off4->GetEntries() ; i++){
    ch_pid_off4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      if(pid_off4[j] == 11)  {elec_off4[j] = ene_off4[j];}
      else if(pid_off4[j] == 22)  {gamma_off4[j] = ene_off4[j];}
      else if(pid_off4[j] == -11) {pos_off4[j] = ene_off4[j];}
    }t_off->Fill();  

  } 
  //  t_off->Write();
  cout<<"finish!"<<endl;


  f->Write();
  f->Close();

}
