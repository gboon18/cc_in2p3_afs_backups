{
     TFile *f1 = TFile::Open("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/dose_6_3_1.root");
  //    TFile *f2 = TFile::Open("../../18042018_field_off/build/test.root");                                                                                                             

  /* TFile *f1 = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/test2_6_3_1.root"); */
  /* TFile *f2 = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/test3_6_3_1.root"); */
  /* TFile *f3 = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/23042018/rootfiles/dose_2.root"); */
  /* TFile *f4 = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/23042018/rootfiles/dose_3.root"); */
  TTree *t1 = (TTree*)f1->Get("t");
  /* TTree *t2 = (TTree*)f2->Get("t"); */
  /* TTree *t3 = (TTree*)f3->Get("t"); */
  /* TTree *t4 = (TTree*)f4->Get("t"); */
  TCanvas *c1 = new TCanvas("c1", "c1", 200, 10, 1400, 1000);
  c1->Divide(2,2);

  TH1F *h1 = new TH1F("h1", "11GeV, physical magnet present", 2000,0,2000);
  /* TH1F *h2 = new TH1F("h2", "11GeV, no physical magnet present", 2000,0,2000); */
  /* TH1F *h3 = new TH1F("h3", "8.8GeV, no physical magnet present", 2000,0,2000); */
  /* TH1F *h4 = new TH1F("h4", "6.6GeV, no physical magnet present", 2000,0,2000); */

  double totedep1 = 0.;
  double totot1 = 0.;
  double edep1[1116] = {0.};
  double totedep2 = 0.;
  double totot2 = 0.;
  double edep2[1116] = {0.};
  double totedep3 = 0.;
  double totot3 = 0.;
  double edep3[1116] = {0.};
  double totedep4 = 0.;
  double totot4 = 0.;
  double edep4[1116] = {0.};
  int k  = 0;
  int n = 0;

  c1->cd(1);
  t1->SetBranchAddress("edep", edep1);
  for(int i = 0 ; i < t1->GetEntries() ; i++){ totedep1 = 0.;
    t1->GetEntry(i);
    for(int j = 0 ; j < 1116 ; j++){
      if(edep1[j]){ totedep1+=edep1[j];h1->Fill(j, edep1[j]);}
    }
    if(totedep1){/* h1->Fill(totedep1); */ totot1 += totedep1;}
  }
  cout<<totot1<<endl;
  h1->Draw();

  /* c1->cd(2); */
  /* t2->SetBranchAddress("edep", edep2); */
  /* for(int i = 0 ; i < t2->GetEntries() ; i++){ totedep2 = 0.; */
  /*   t2->GetEntry(i); */
  /*   for(int j = 0 ; j < 1116 ; j++){ */
  /*     if(edep2[j]){ totedep2+=edep2[j];} */
  /*     h2->Fill(totedep2); */
  /*   } */
  /*   if(totedep2){ totot2 += totedep2;} */
  /* } */
  /* cout<<totot2<<endl; */
  /* h2->Draw(); */

  /* c1->cd(3); */
  /* t3->SetBranchAddress("edep", edep3); */
  /* for(int i = 0 ; i < t3->GetEntries() ; i++){ totedep3 = 0.; */
  /*   t3->GetEntry(i); */
  /*   for(int j = 0 ; j < 1116 ; j++){ */
  /*     if(edep3[j]){ totedep3+=edep3[j];} */
  /*   } */
  /*   if(totedep3){h3->Fill(totedep3); totot3 += totedep3;} */
  /* } */
  /* cout<<totot3<<endl; */
  /* h3->Draw(); */

  /* c1->cd(4); */
  /* t4->SetBranchAddress("edep", edep4); */
  /* for(int i = 0 ; i < t4->GetEntries() ; i++){ totedep4 = 0.; */
  /*   t4->GetEntry(i); */
  /*   for(int j = 0 ; j < 1116 ; j++){ */
  /*     if(edep4[j]){ totedep4+=edep4[j];} */
  /*   } */
  /*   if(totedep4){h4->Fill(totedep4); totot4 += totedep4;} */
  /* } */
  /* cout<<totot4<<endl; */
  /* h4->Draw(); */
}

