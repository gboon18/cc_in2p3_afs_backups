{

// /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/09072018/rootfiles_bogdan/histo.root

  const int array = 1116;

  TFile *f = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/09072018/rootfiles_bogdan/histo.root");
  TTree *t_on = (TTree*)f->Get("t_on");
  TTree *t_off = (TTree*)f->Get("t_off");

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

  t_on->SetBranchAddress("elec1", elec_on1);
  t_on->SetBranchAddress("elec2", elec_on2);
  t_on->SetBranchAddress("elec3", elec_on3);
  t_on->SetBranchAddress("elec4", elec_on4);
  t_on->SetBranchAddress("pos1", pos_on1);
  t_on->SetBranchAddress("pos2", pos_on2);
  t_on->SetBranchAddress("pos3", pos_on3);
  t_on->SetBranchAddress("pos4", pos_on4);
  t_on->SetBranchAddress("gamma1", gamma_on1);
  t_on->SetBranchAddress("gamma2", gamma_on2);
  t_on->SetBranchAddress("gamma3", gamma_on3);
  t_on->SetBranchAddress("gamma4", gamma_on4);
  t_off->SetBranchAddress("elec1", elec_off1);
  t_off->SetBranchAddress("elec2", elec_off2);
  t_off->SetBranchAddress("elec3", elec_off3);
  t_off->SetBranchAddress("elec4", elec_off4);
  t_off->SetBranchAddress("pos1", pos_off1);
  t_off->SetBranchAddress("pos2", pos_off2);
  t_off->SetBranchAddress("pos3", pos_off3);
  t_off->SetBranchAddress("pos4", pos_off4);
  t_off->SetBranchAddress("gamma1", gamma_off1);
  t_off->SetBranchAddress("gamma2", gamma_off2);
  t_off->SetBranchAddress("gamma3", gamma_off3);
  t_off->SetBranchAddress("gamma4", gamma_off4);

  int x, y;
  int i = 101;
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


  gStyle->SetOptStat(0);

  TCanvas *c_pid = new TCanvas("c_pid", "checking the pid on NPS", 200, 10, 1400, 1000);
  c_pid->Divide(2,2);

  TCanvas *c_ene_pid = new TCanvas("c_ene_pid", "checking the energy flux on NPS each PID", 200, 10, 1400, 500);
  c_ene_pid->Divide(4,1);

  TCanvas *c_flux = new TCanvas("c_flux", "checking the energy flux on NPS", 200, 10, 700, 1000);
  c_flux->Divide(1,2);

  TCanvas *c_flux_pid = new TCanvas("c_flux_pid", "checking the energy flux on NPS each PID", 200, 10, 1400, 2000);
  c_flux_pid->Divide(4,2);

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


  //  TH2F *h_edep_pattern = new TH2F("h_edep_pattern", "edep pattern", 31, 0, 31, 36, 0, 36);//(x, y)
  TH1F *h_ene_on = new TH1F("h_ene_on", "field on", 127, edges);//in x axis
  h_ene_on->GetXaxis()->SetTitle("angle");
  h_ene_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_ene_off = new TH1F("h_ene_off", "field off", 127, edges);//in x axis
  h_ene_off->GetXaxis()->SetTitle("angle");
  h_ene_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH1F *h_elec_ene_on = new TH1F("h_elec_ene_on", "electron, field on", 127, edges);//in x axis
  h_elec_ene_on->GetXaxis()->SetTitle("angle");
  h_elec_ene_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_elec_ene_off = new TH1F("h_elec_ene_off", "electron, field off", 127, edges);//in x axis
  h_elec_ene_off->GetXaxis()->SetTitle("angle");
  h_elec_ene_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH1F *h_pos_ene_on = new TH1F("h_pos_ene_on", "positron, field on", 127, edges);//in x axis
  h_pos_ene_on->GetXaxis()->SetTitle("angle");
  h_pos_ene_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_pos_ene_off = new TH1F("h_pos_ene_off", "positron, field off", 127, edges);//in x axis
  h_pos_ene_off->GetXaxis()->SetTitle("angle");
  h_pos_ene_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH1F *h_gamma_ene_on = new TH1F("h_gamma_ene_on", "gamma, field on", 127, edges);//in x axis
  h_gamma_ene_on->GetXaxis()->SetTitle("angle");
  h_gamma_ene_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_gamma_ene_off = new TH1F("h_gamma_ene_off", "gamma, field off", 127, edges);//in x axis
  h_gamma_ene_off->GetXaxis()->SetTitle("angle");
  h_gamma_ene_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH1F *h_unknown_ene_on = new TH1F("h_unknown_ene_on", "unknown, field on", 127, edges);//in x axis
  h_unknown_ene_on->GetXaxis()->SetTitle("angle");
  h_unknown_ene_on->GetYaxis()->SetTitle("dose rate [rad/hr]");
  TH1F *h_unknown_ene_off = new TH1F("h_unknown_ene_off", "unknown, field off", 127, edges);//in x axis
  h_unknown_ene_off->GetXaxis()->SetTitle("angle");
  h_unknown_ene_off->GetYaxis()->SetTitle("dose rate [rad/hr]");

  TH2F *h_pattern_on = new TH2F("h_pattern_on", "field on",127, edges, 36, 0, 35);
  TH2F *h_pattern_off = new TH2F("h_pattern_off", "field off",127, edges, 36, 0, 35);
  TH2F *h_elec_pattern_on = new TH2F("h_elec_pattern_on", "field on, electron",127, edges, 36, 0, 35);
  TH2F *h_gamma_pattern_on = new TH2F("h_gamma_pattern_on", "field on, gamma",127, edges, 36, 0, 35);
  TH2F *h_elec_pattern_off = new TH2F("h_elec_pattern_off", "field off, electron",127, edges, 36, 0, 35);
  TH2F *h_gamma_pattern_off = new TH2F("h_gamma_pattern_off", "field off, gamma",127, edges, 36, 0, 35);
  TH2F *h_pos_pattern_on = new TH2F("h_pos_pattern_on", "field on, positron",127, edges, 36, 0, 35);
  TH2F *h_pos_pattern_off = new TH2F("h_pos_pattern_off", "field off, positron",127, edges, 36, 0, 35);
  TH2F *h_unknown_pattern_on = new TH2F("h_unknown_pattern_on", "field on, unknown",127, edges, 36, 0, 35);
  TH2F *h_unknown_pattern_off = new TH2F("h_unknown_pattern_off", "field off, unknown",127, edges, 36, 0, 35);

  // int elec_on = 0, elec_off = 0, pos_on = 0, pos_off = 0, gamma_on = 0, gamma_off = 0, unknown_on = 0, unknown_off = 0; 

  for(int i = 0 ; i < t_on->GetEntries() ; i++){
    t_on->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );

      h_elec_pattern_on->Fill(angle, y, elec_on1[j]);
      h_elec_ene_on->Fill(angle, elec_on1[j]*MeV_to_rad_per_hr);
      h_pos_pattern_on->Fill(angle, y, pos_on1[j]);
      h_pos_ene_on->Fill(angle, pos_on1[j]*MeV_to_rad_per_hr);
      h_gamma_pattern_on->Fill(angle, y, gamma_on1[j]); 
      h_gamma_ene_on->Fill(angle, gamma_on1[j]*MeV_to_rad_per_hr);
    }
  }

  for(int i = 0 ; i < t_off->GetEntries() ; i++){
    t_off->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      x = int(j/36);
      y = j%36;
      angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    );

      h_elec_pattern_off->Fill(angle, y, elec_off1[j]);
      h_elec_ene_off->Fill(angle, elec_off1[j]*MeV_to_rad_per_hr);
      h_pos_pattern_off->Fill(angle, y, pos_off1[j]);
      h_pos_ene_off->Fill(angle, pos_off1[j]*MeV_to_rad_per_hr);
      h_gamma_pattern_off->Fill(angle, y, gamma_off1[j]); 
      h_gamma_ene_off->Fill(angle, gamma_off1[j]*MeV_to_rad_per_hr);
    }
  }






  c_pid->cd(1);
  gPad->SetLogz(1);
  h_elec_pattern_on->GetZaxis()->SetRangeUser(1,5e5); 
  h_elec_pattern_on->Draw("colz");
  c_pid->cd(2);
  gPad->SetLogz(1);
  h_elec_pattern_off->GetZaxis()->SetRangeUser(1,5e5);
  h_elec_pattern_off->Draw("colz");
  c_pid->cd(3);
  gPad->SetLogz(1);
  h_gamma_pattern_on->GetZaxis()->SetRangeUser(1,5e5);
  h_gamma_pattern_on->Draw("colz");
  c_pid->cd(4);
  gPad->SetLogz(1);
  h_gamma_pattern_off->GetZaxis()->SetRangeUser(1,5e5);
  h_gamma_pattern_off->Draw("colz");

  c_pid->Print("output/pid.eps");

  c_flux->cd(1);
  gPad->SetLogz(1);
  h_pattern_on->GetZaxis()->SetRangeUser(1,5e5); 
  h_pattern_on->Draw("colz");
  c_flux->cd(2);
  gPad->SetLogz(1);
  h_pattern_off->GetZaxis()->SetRangeUser(1,5e5);
  h_pattern_off->Draw("colz");

  c_flux->Print("output/flux.eps");

  c_flux_pid->cd(1);
  gPad->SetLogz(1);
  h_elec_pattern_on->GetZaxis()->SetRangeUser(1,2e6); 
  h_elec_pattern_on->Draw("colz");

  c_flux_pid->cd(2);
  gPad->SetLogz(1);
  h_pos_pattern_on->GetZaxis()->SetRangeUser(1,2e6);
  h_pos_pattern_on->Draw("colz");

  c_flux_pid->cd(3);
  gPad->SetLogz(1);
  h_gamma_pattern_on->GetZaxis()->SetRangeUser(1,2e6); 
  h_gamma_pattern_on->Draw("colz");

  c_flux_pid->cd(4);
  gPad->SetLogz(1);
  h_unknown_pattern_on->GetZaxis()->SetRangeUser(1,2e6);
  h_unknown_pattern_on->Draw("colz");

  c_flux_pid->cd(5);
  gPad->SetLogz(1);
  h_elec_pattern_off->GetZaxis()->SetRangeUser(1,2e6); 
  h_elec_pattern_off->Draw("colz");

  c_flux_pid->cd(6);
  gPad->SetLogz(1);
  h_pos_pattern_off->GetZaxis()->SetRangeUser(1,2e6);
  h_pos_pattern_off->Draw("colz");

  c_flux_pid->cd(7);
  gPad->SetLogz(1);
  h_gamma_pattern_off->GetZaxis()->SetRangeUser(1,2e6); 
  h_gamma_pattern_off->Draw("colz");

  c_flux_pid->cd(8);
  gPad->SetLogz(1);
  h_unknown_pattern_off->GetZaxis()->SetRangeUser(1,2e6);
  h_unknown_pattern_off->Draw("colz");

  c_flux_pid->Print("output/flux_pid.eps");

  c_ene_pid->cd(1); 
  gPad->SetLogy(1); 
  h_elec_ene_off->SetMaximum(1e6); 
  h_elec_ene_off->SetMinimum(1); 
  h_elec_ene_off->SetLineColor(2); 
  h_elec_ene_off->SetTitle("Dose on NPS with field on|off, electron"); 
  h_elec_ene_on->SetLineColor(4); 
  h_elec_ene_off->Draw(); 
  h_elec_ene_on->Draw("SAME"); 
  TLegend *leg_elec = new TLegend(0.6, 0.65, .9, .9); 
  leg_elec->AddEntry(h_elec_ene_off, "field off", "l"); 
  leg_elec->AddEntry(h_elec_ene_on, "field on", "l"); 
  //  leg_elec->AddEntry(elec_on, "test", ""); 
  leg_elec->Draw(); 

  c_ene_pid->cd(2); 
  gPad->SetLogy(1); 
  h_pos_ene_off->SetMaximum(1e6); 
  h_pos_ene_off->SetMinimum(1); 
  h_pos_ene_off->SetLineColor(2); 
  h_pos_ene_off->SetTitle("Dose on NPS with field on|off, positron"); 
  h_pos_ene_on->SetLineColor(4); 
  h_pos_ene_off->Draw(); 
  h_pos_ene_on->Draw("SAME"); 
  TLegend *leg_pos = new TLegend(0.6, 0.65, .9, .9); 
  leg_pos->AddEntry(h_pos_ene_off, "field off", "l"); 
  leg_pos->AddEntry(h_pos_ene_on, "field on", "l"); 
  leg_pos->Draw(); 

  c_ene_pid->cd(3); 
  gPad->SetLogy(1); 
  h_gamma_ene_off->SetMaximum(1e6); 
  h_gamma_ene_off->SetMinimum(1); 
  h_gamma_ene_off->SetLineColor(2); 
  h_gamma_ene_off->SetTitle("Dose on NPS with field on|off, gamma"); 
  h_gamma_ene_on->SetLineColor(4); 
  h_gamma_ene_off->Draw(); 
  h_gamma_ene_on->Draw("SAME"); 
  TLegend *leg_gamma = new TLegend(0.6, 0.65, .9, .9); 
  leg_gamma->AddEntry(h_gamma_ene_off, "field off", "l"); 
  leg_gamma->AddEntry(h_gamma_ene_on, "field on", "l"); 
  leg_gamma->Draw(); 

  c_ene_pid->cd(4); 
  gPad->SetLogy(1); 
  h_unknown_ene_off->SetMaximum(1e6); 
  h_unknown_ene_off->SetMinimum(1); 
  h_unknown_ene_off->SetLineColor(2); 
  h_unknown_ene_off->SetTitle("Dose on NPS with field on|off, unknown"); 
  h_unknown_ene_on->SetLineColor(4); 
  h_unknown_ene_off->Draw(); 
  h_unknown_ene_on->Draw("SAME"); 
  TLegend *leg_unknown = new TLegend(0.6, 0.65, .9, .9); 
  leg_unknown->AddEntry(h_unknown_ene_off, "field off", "l"); 
  leg_unknown->AddEntry(h_unknown_ene_on, "field on", "l"); 
  leg_unknown->Draw();   

  c_ene_pid->Print("output/ene_pid.eps");

}
