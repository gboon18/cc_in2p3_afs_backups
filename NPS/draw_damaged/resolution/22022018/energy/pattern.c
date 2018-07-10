void pattern(/* int i = 0 */){

  string histo_edep_string_front = "energy deposition in NPS with e-";
  string histo_nps_string_front = "optical photons in NPS with e-";
  string histo_pmt_string_front = "optical photons in PMT with e-";
  string file_dir = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/17022018/rootfiles/17022018_resolution_";
  string file_end = "_0000%d.root";

  string output_string_front = "../output/17022018/edep/edep";
  string output_string_back = ".eps";

  string dash = "_";
  string space = " ";
  string ene_string;
  string gap_string;

  int NumberOfRuns;

  int gap_size = 0;
  int ene = 0;

  /* for(int gap_size = 0 ; gap_size < 5 ; gap_size++){ */
  if (gap_size == 0)       gap_string = "0_0mm";
  else if (gap_size == 1)  gap_string = "0_5mm";
  else if (gap_size == 2)  gap_string = "1_0mm";
  else if (gap_size == 3)  gap_string = "1_5mm";
  else if (gap_size == 4)  gap_string = "2_0mm";

  /* for(int ene = 0 ; ene < 2/\* ene_range *\/ ; ene++){ */
  if (ene == 0)       {ene_string = "500MeV";  NumberOfRuns = 10*2;}
  else if (ene == 1)  {ene_string = "1GeV";    NumberOfRuns = 20*2;}
  /* else if (ene == 2)  {ene_string = "3_25GeV"; NumberOfRuns = 45*2;} */
  /* else if (ene == 3)  {ene_string = "5_5GeV";  NumberOfRuns = 111*2;} */
  /* else if (ene == 4)  {ene_string = "7_75GeV"; NumberOfRuns = 156*2;} */
  /* else if (ene == 5)  {ene_string = "10GeV";   NumberOfRuns = 200*2;} */


  //    int ene = 0;    ene_string = "500MeV";NumberOfRuns = 10;

  TChain *ch = new TChain("t");

  string file_string = file_dir + gap_string + dash  + ene_string + file_end;
  const char *file_char = file_string.c_str();

  string histo_edep_string = histo_edep_string_front + space + ene_string + space + gap_string;
  const char *histo_edep_char = histo_edep_string.c_str();
  string histo_nps_string = histo_nps_string_front + space + ene_string + space + gap_string;
  const char *histo_nps_char = histo_nps_string.c_str();
  string histo_pmt_string = histo_pmt_string_front + space + ene_string + space + gap_string;
  const char *histo_pmt_char = histo_pmt_string.c_str();


  string output_string = output_string_front + dash + ene_string + dash + gap_string + output_string_back;
  const char *output_char = output_string.c_str();


  for(int runNo = 1 ; runNo < NumberOfRuns + 1 ; runNo++){

    ch->Add(Form(file_char,runNo));
    cout<<runNo<<endl;
  }


  const int n = 1116;

  double edep[n];
  int pid[n];
  int sc[n];
  int op_pc[n];
  int nentries;
  
  t->SetBranchAddress("edep", edep);
  t->SetBranchAddress("pid", pid);
  t->SetBranchAddress("sc", sc);
  t->SetBranchAddress("op_pc", op_pc);
  //  t->Scan("edep");
  nentries =  t->GetEntries();

  const int nn = nentries;
  double totE[nn] = {0.};
  double E_max[nn] = {0.};
  int S_max[nn] = {0};
  int P_max[nn] = {0};

  int x, y, x1, y1;
  TCanvas* c_edep = new TCanvas("c_edep","c_edep",1200,1200);
  c_edep->Divide(2,2);
  TH2F *h_edep = new TH2F("h_edep","",31,0,31,36,0,36);//(x,y) 
  TH2F *h_sc = new TH2F("h_sc","",31,0,31,36,0,36);//(x,y) 
  TH2F *h_pc = new TH2F("h_pc","",31,0,31,36,0,36);//(x,y) 
  TH1F *h = new TH1F("h", "", 100, 0, 100);
  TH1F *h_pid = new TH1F("h_pid", "", 61, -30, 30);
  TH2F *h_ratio = new TH2F("h_ratio", "", 31, 0, 31, 36, 0, 36);

  double  edep_max = 0.;
  int  sc_max = 0;
  int  pc_max = 0;
  double  edep_next_max = 0.;
  double totedep;
  int totsc;
  int totpc;
  int edep_j, sc_j, pc_j;

  /* int i = 1; */
  for(int i = 0 ; i < nentries ; i++){

    t->GetEntry(i);

    edep_max = 0.;
    sc_max = 0;
    pc_max = 0;

    totedep = 0.;
    totsc = 0;
    totpc = 0;
    for(int j = 0 ; j < n ; j++){
      totedep += edep[j];
      totsc += sc[j];
      totpc += op_pc[j];
      totE[i] += edep[j];
      /* x = j%31; */
      /* y = 35 - int(j/31); */
      if(edep[j]){cout<<edep[j]<<"["<<j<<"]"<<endl;}
      if(edep[j] > edep_max) {edep_max = edep[j]; edep_j = j;E_max[i] = edep[j];}
      if(sc[j] > sc_max)     {sc_max = sc[j]; sc_j = j;S_max[i] = sc[j];}
      if(op_pc[j] > pc_max)     {pc_max = op_pc[j]; pc_j = j;P_max[i] = op_pc[j];}

      y = j%36;
      x = int(j/36);
      /* if(edep[j]) */    h_edep->Fill(x,y,edep[j]);
      h_sc->Fill(x,y,sc[j]);
      h_pc->Fill(x,y,op_pc[j]);
      /* if(pid[j]!=0) {h_pid->Fill(pid[j]); h_ratio->Fill(pid[j],edep[j]);} */
    }
    if(totedep!=0)    h->Fill(100*edep_max/totedep);


    /* cout<<"totedep : "<<totpc/totedep<<endl; */
    /* cout<<"totpc : "<<totpc<<endl; */
    /* c_edep->cd(); */
    /* h_edep->Draw("text"); */
   
    cout<<i<<"\t edep[j] : "<<edep_max<<"["<<edep_j<<"]"<<",\t sc[j] :"<<sc_max<<"["<<sc_j<<"]"<<",\t pc[j] :"<<pc_max<<"["<<pc_j<<"]"<<endl;
  }

/*   for(int i = 0 ; i < 10 ; i++){ */
/*     for(int j = 0 ; j < n ; j++){ */
/*       y = j%36; */
/*       x = int(j/36); */
/*       if(totE[i]!=0) h_ratio->Fill(x,y,100*(E_max[i]/totE[i])); */
/*     } */
/* /\* if(totE[i]!=0)  cout<<E_max[i]/totE[i]/nentries<<endl; *\/ */
/* } */


  c_edep->cd(1);
  h_edep->Draw("colz");
  c_edep->cd(2);
  h_sc->Draw("colz");
  /* h_ratio->Draw("colz"); */
  c_edep->cd(3);
  /* h_ratio->Draw("colz"); */
  h_pc->Draw("colz");
  c_edep->cd(4);
  h->Draw();
  c_edep->Print("../output/17022018/edep/shape.eps");
  /*   } */
  /* } */
}
