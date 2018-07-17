{










  /////////////////////////////////////////////////////////////////////////
  const int array = 1116;

  double ene[array] = {0.};
  int pid[array] = {0};

  TFile *f = new TFile("histo.root","RECREATE");
  TTree* t = new TTree("t", "");
  t->Branch("ene", ene, "Energy Flux[1116]/D");
  t->Branch("pid", pid, "Flux PID[1116]/I");

  f->Write();
  f->Close();
}
