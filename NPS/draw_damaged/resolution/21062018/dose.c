{
  TChain *ch1 = new TChain("t");
  TChain *ch2 = new TChain("t");
  TChain *ch3 = new TChain("t");
  TChain *ch4 = new TChain("t");

  string dir_str = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27042018/rootfiles/";
  string field_on_str = "dose_field_on_";
  string field_off_str = "dose_field_off_";
  string file_end_str = ".root";


  for(int i = 1; i < 101 ; i++){
    string i_str;
    ostringstream convert;
    convert << i ;
    i_str = convert.str();// = to_string(i);
    string comb_6_3 = dir_str + field_off_str + "6_3_" + i_str + file_end_str;
    string comb_16_6 = dir_str + field_off_str + "16_6_" + i_str + file_end_str;
    string comb_26_9 = dir_str + field_off_str + "26_9_" + i_str + file_end_str;
    string comb_37_2 = dir_str + field_off_str + "37_2_" + i_str + file_end_str;
    const char* file_6_3 = comb_6_3.c_str();
    const char* file_16_6 = comb_16_6.c_str();
    const char* file_26_9 = comb_26_9.c_str();
    const char* file_37_2 = comb_37_2.c_str();
    ch1->Add(file_6_3);
    ch2->Add(file_16_6);
    ch3->Add(file_26_9);
    ch4->Add(file_37_2);
  }

  /* TTree *t1 = (TTree*)ch1->GetTree(); */
  /* TTree *t2 = (TTree*)ch2->GetTree(); */
  /* TTree *t3 = (TTree*)ch3->GetTree(); */
  /* TTree *t4 = (TTree*)ch4->GetTree(); */

  const int array = 1116;

  double edep1[array] = {0.};
  double edep2[array] = {0.};
  double edep3[array] = {0.};
  double edep4[array] = {0.};
  double totedep = 0.;
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

  ch1->SetBranchAddress("edep", edep1);
  ch2->SetBranchAddress("edep", edep2);
  ch3->SetBranchAddress("edep", edep3);
  ch4->SetBranchAddress("edep", edep4);

  gStyle->SetOptStat(0);
  TCanvas *c_pattern = new TCanvas("c_pattern", "checking the background on NPS and dose", 200, 10, 1000, 500);
  c_pattern->Divide(2,1);
  TH2F *h_edep_pattern = new TH2F("h_edep_pattern", "edep pattern", 31, 0, 31, 36, 0, 36);//(x, y)
  TH1F *h_dose = new TH1F("h_dose", "dose rate", 41, 1, 42);//in x axis
  h_dose->GetXaxis()->SetTitle("angle");
  h_dose->GetYaxis()->SetTitle("dose rate [rad/hr]");

  for(int i = 0 ; i < ch1->GetEntries() ; i++){
    ch1->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_edep_pattern->Fill(x, y, edep1[j]);
      h_dose->Fill(angle, edep1[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch2->GetEntries() ; i++){
    ch2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle2  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_edep_pattern->Fill(x, y, edep2[j]);
      h_dose->Fill(angle, edep2[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch3->GetEntries() ; i++){
    ch3->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle3  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_edep_pattern->Fill(x, y, edep3[j]);
      h_dose->Fill(angle, edep3[j]*MeV_to_rad_per_hr);
    }
  } 

  for(int i = 0 ; i < ch4->GetEntries() ; i++){
    ch4->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle4  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );
      h_edep_pattern->Fill(x, y, edep4[j]);
      h_dose->Fill(angle, edep4[j]*MeV_to_rad_per_hr);
    }
  } 
  c_pattern->cd(1);
  gPad->SetLogz(0);
  h_edep_pattern->Draw("colz");
  c_pattern->cd(2);
  gPad->SetLogy(1);
  h_dose->Draw();
}
