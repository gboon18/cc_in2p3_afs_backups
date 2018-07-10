{
  const int array = 1116;
  double edep[array] ={0.};
  int     pid[array] ={0};
  double  ene[array] ={0.};

  TFile* f = new TFile("/afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/04072018/build/test_on.root");
  TTree *t = (TTree*)f->Get("t");
  TTree *t2 = (TTree*)f->Get("t2");

  t->SetBranchAddress("edep", edep);
  t2->SetBranchAddress("pid", pid);
  t2->SetBranchAddress("ene", ene);
  /* TCanvas *c_pattern = new TCanvas("c_pattern", "checking the pattern on NPS", 200, 10, 700, 1000); */
  /* c_pattern->Divide(1,2); */
  /* TH2F *h_edep_pattern_on = new TH2F("h_edep_pattern_on", "edep pattern, field on", 41, 1, 42, 36, 0, 36);//(x, y) */
  /* TH2F *h_flux_pattern_on = new TH2F("h_flux_pattern_on", "flux pattern, field on", 41, 1, 42, 36, 0, 36);//(x, y) */

  int elec_on = 0, elec_off = 0, pos_on = 0, pos_off = 0, gamma_on = 0, gamma_off = 0, unknown_on = 0, unknown_off = 0; 
  int enee = 0, enee_tot=0;
  for(int i = 0 ; i < t2->GetEntries() ; i++){
    t2->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      /* x = int(j/36); */
      /* y = j%36; */
      /* angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    ); */
      /* h_flux_pattern_on->Fill(angle, y, ene_on1[j]*MeV_to_rad_per_hr); */
      /* cout<<i<<", "<<j<<", "<<pid_on1[j]<<", "<<ene_on1[j]<<endl; */
      enee += ene[j];
    }
  } 
  cout<<"Flux, No_entries : "<<t2->GetEntries()<<endl;
  cout<<"Flux, tot_edep : "<<enee<<endl;
  for(int i = 0 ; i < t->GetEntries() ; i++){
    t->GetEntry(i);
    for(int j = 0 ; j < array ; j++){
      /* x = int(j/36); */
      /* y = j%36; */
      /* angle = NPS_angle1  - (180./TMath::Pi())*TMath::ATan( (gap + cry_x)*(x - 15)/400.    ); */
      /* h_edep_pattern_on->Fill(angle, y, edep_on1[j]*MeV_to_rad_per_hr); */
      enee_tot += edep[j];
    }
  } 

  cout<<"Edep, No_entries : "<<t->GetEntries()<<endl;
  cout<<"Edep, tot_edep : "<<enee_tot<<endl;

  /* c_pattern->cd(1); */
  /* gPad->SetLogz(); */
  /* h_flux_pattern_on->GetZaxis()->SetRangeUser(1,3e3); */
  /* h_flux_pattern_on->Draw("colz"); */
  /* c_pattern->cd(2); */
  /* gPad->SetLogz(); */
  /* h_edep_pattern_on->GetZaxis()->SetRangeUser(1,3e3); */
  /* h_edep_pattern_on->Draw("colz"); */

}
