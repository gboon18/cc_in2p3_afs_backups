{
  TChain *ch_on1 = new TChain("t");
  TChain *ch_on2 = new TChain("t");
  TChain *ch_on3 = new TChain("t");
  TChain *ch_on4 = new TChain("t");
  TChain *ch_off1 = new TChain("t");
  TChain *ch_off2 = new TChain("t");
  TChain *ch_off3 = new TChain("t");
  TChain *ch_off4 = new TChain("t");

  string dir_on_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/26042018/rootfiles/";
  string dir_off_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/";
  string field_on_str = "dose_";
  string field_off_str = "dose_";
  string file_end_str = ".root";


  for(int i = 1; i < 101 ; i++){
    string i_str;
    ostringstream convert;
    convert << i ;
    i_str = convert.str();// = to_string(i);
    string comb_on_6_3 = dir_on_str + field_on_str + "6_3_" + i_str + file_end_str;
    string comb_on_16_6 = dir_on_str + field_on_str + "16_6_" + i_str + file_end_str;
    string comb_on_26_9 = dir_on_str + field_on_str + "26_9_" + i_str + file_end_str;
    string comb_on_37_2 = dir_on_str + field_on_str + "37_2_" + i_str + file_end_str;
    const char* file_on_6_3 = comb_on_6_3.c_str();
    const char* file_on_16_6 = comb_on_16_6.c_str();
    const char* file_on_26_9 = comb_on_26_9.c_str();
    const char* file_on_37_2 = comb_on_37_2.c_str();
    ch_on1->Add(file_on_6_3);
    ch_on2->Add(file_on_16_6);
    ch_on3->Add(file_on_26_9);
    ch_on4->Add(file_on_37_2);
  }
  for(int i = 1; i < 2 ; i++){
    string i_str;
    ostringstream convert;
    convert << i ;
    i_str = convert.str();// = to_string(i);
    string comb_off_6_3 = dir_off_str + field_off_str + "6_3_" + i_str + file_end_str;
    string comb_off_16_6 = dir_off_str + field_off_str + "16_6_" + i_str + file_end_str;
    string comb_off_26_9 = dir_off_str + field_off_str + "26_9_" + i_str + file_end_str;
    string comb_off_37_2 = dir_off_str + field_off_str + "37_2_" + i_str + file_end_str;
    const char* file_off_6_3 = comb_off_6_3.c_str();
    const char* file_off_16_6 = comb_off_16_6.c_str();
    const char* file_off_26_9 = comb_off_26_9.c_str();
    const char* file_off_37_2 = comb_off_37_2.c_str();
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

  gStyle->SetOptStat(0);
  TCanvas *c_pattern = new TCanvas("c_pattern", "checking the background on NPS and dose", 200, 10, 1000, 500);
  c_pattern->Divide(2,1);
  //  TH2F *h_edep_pattern = new TH2F("h_edep_pattern", "edep pattern", 31, 0, 31, 36, 0, 36);//(x, y)
  TH1F *h_dose_on = new TH1F("h_dose_on", "field on", 41, 1, 42);//in x axis
  h_dose_on->GetXaxis()->SetTitle("angle");
  h_dose_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_dose_off = new TH1F("h_dose_off", "field off", 41, 1, 42);//in x axis
  h_dose_off->GetXaxis()->SetTitle("angle");
  h_dose_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  for(int i = 0 ; i < ch_off1->GetEntries() ; i++){
    ch_off1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep1[j]);
      h_dose_off->Fill(angle, edep_off1[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch_off2->GetEntries() ; i++){
    ch_off2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep2[j]);
      h_dose_off->Fill(angle, edep_off2[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch_off3->GetEntries() ; i++){
    ch_off3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep3[j]);
      h_dose_off->Fill(angle, edep_off3[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch_off4->GetEntries() ; i++){
    ch_off4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep4[j]);
      h_dose_off->Fill(angle, edep_off4[j]*MeV_to_rad_per_hr);
    }
  } 
  for(int i = 0 ; i < ch_on1->GetEntries() ; i++){
    ch_on1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep1[j]);
      h_dose_on->Fill(angle, edep_on1[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch_on2->GetEntries() ; i++){
    ch_on2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep2[j]);
      h_dose_on->Fill(angle, edep_on2[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch_on3->GetEntries() ; i++){
    ch_on3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep3[j]);
      h_dose_on->Fill(angle, edep_on3[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch_on4->GetEntries() ; i++){
    ch_on4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      //h_edep_pattern->Fill(x, y, edep4[j]);
      h_dose_on->Fill(angle, edep_on4[j]*MeV_to_rad_per_hr);
    }
  } 
  c_pattern->cd(1);
  gPad->SetLogy(1);
  h_dose_off->Draw();

  //  gPad->SetLogz(0);
  //h_edep_pattern->Draw("colz");
  c_pattern->cd(2);
  gPad->SetLogy(1);
  h_dose_on->Draw();
}
