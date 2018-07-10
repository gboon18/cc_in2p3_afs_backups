{
  TFile *f1 = new TFile("/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/test4_6_3_1.root");

  TTree *t1 = (TTree*)f1->Get("t");
  TTree *t2 = (TTree*)f1->Get("t2");

  TCanvas *c1 = new TCanvas("c1", "c1", 200, 10, 1400, 500);
  c1->Divide(2,1);

  double totedep1 = 0.;
  double totot1 = 0.;
  double edep1[1116] = {0.};
  double totedep2 = 0.;
  double totot2 = 0.;
  double edep2[1116] = {0.};

  TH1F *h1 = new TH1F("h1", "11GeV, Run by Run saving", 2000,0,2000);
  TH1F *h2 = new TH1F("h2", "11GeV, Event by Event saving", 2000,0,2000);

  c1->cd(1);
  t1->SetBranchAddress("edep", edep1);
  for(int i = 0 ; i < t1->GetEntries() ; i++){ totedep1 = 0.;
    t1->GetEntry(i);
    for(int j = 0 ; j < 1116 ; j++){
      if(edep1[j]){ totedep1+=edep1[j];h1->Fill(j , edep1[j]);}
      //           h1->Fill(totedep1);
    }
    if(totedep1){ totot1 += totedep1;}
  }
  cout<<totot1<<endl;
  h1->Draw();


  c1->cd(2);
  t2->SetBranchAddress("edep", edep2);
  for(int i = 0 ; i < t2->GetEntries() ; i++){ totedep2 = 0.;
    t2->GetEntry(i);
    for(int j = 0 ; j < 1116 ; j++){
      if(edep2[j]){ totedep2+=edep2[j];h2->Fill(j, edep2[j]);}
    }
    if(totedep2){/* h2->Fill(totedep2); */ totot2 += totedep2;}
  }
  cout<<totot2<<endl;
  h2->Draw();



}
