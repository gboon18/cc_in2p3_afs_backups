void pattern(int gap_size = 0, int ene = 0){

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

  double gap;
  double crystal_size;

  int NumberOfRuns;

  /* int gap_size = 0; */
  /* int ene = 0; */

  /* for(int gap_size = 0 ; gap_size < 5 ; gap_size++){ */
  if (gap_size == 0)       {gap_string = "0_0mm"; gap = 0;}
  else if (gap_size == 1)  {gap_string = "0_5mm"; gap = 0.5;}
  else if (gap_size == 2)  {gap_string = "1_0mm"; gap = 1.;}
  else if (gap_size == 3)  {gap_string = "1_5mm"; gap = 1.5;}
  else if (gap_size == 4)  {gap_string = "2_0mm"; gap = 2.0;}

  /* for(int ene = 0 ; ene < 2/\* ene_range *\/ ; ene++){ */
  if (ene == 0)       {ene_string = "500MeV";  NumberOfRuns = 10*2;}
  else if (ene == 1)  {ene_string = "1GeV";    NumberOfRuns = 20*2;}
  else if (ene == 2)  {ene_string = "3_25GeV"; NumberOfRuns = 45*2;}
  else if (ene == 3)  {ene_string = "5_5GeV";  NumberOfRuns = 111*2;}
  else if (ene == 4)  {ene_string = "7_75GeV"; NumberOfRuns = 156*2;}
  else if (ene == 5)  {ene_string = "10GeV";   NumberOfRuns = 200*2;}

  crystal_size = 20.5 + 2*65e-3 + gap;
  cout<<crystal_size<<endl;
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
    /* cout<<runNo<<endl; */
  }


  const int n = 1116;

  double edep[n];
  int pid[n];
  int sc[n];
  int op_pc[n];
  double w[n]={0.};
  double PM[3];
  int nentries;
  
  t->SetBranchAddress("edep", edep);
  t->SetBranchAddress("pid", pid);
  t->SetBranchAddress("sc", sc);
  t->SetBranchAddress("op_pc", op_pc);
  t->SetBranchAddress("PM", PM);
  //  t->Scan("edep");
  nentries =  t->GetEntries();

  const int nn = nentries;
  double totE[nn] = {0.};
  double E_max[nn] = {0.};
  int S_max[nn] = {0};
  int P_max[nn] = {0};
  double pos_x_rec[nn] = {0.};
  double pos_y_rec[nn] = {0.};

  int x, y, x1, y1;
  TCanvas* c_edep = new TCanvas("c_edep","c_edep",1200,1200);
  c_edep->cd();
  c_edep->Divide(2,2);
  TH2F *h_edep = new TH2F("h_edep","",31,0,31,36,0,36);//(x,y) 
  TH2F *h_sc = new TH2F("h_sc","",31,0,31,36,0,36);//(x,y) 
  TH2F *h_pc = new TH2F("h_pc","",31,0,31,36,0,36);//(x,y) 
  TH1F *h = new TH1F("h", "", 100, 0, 100);
  TH1F *h_pid = new TH1F("h_pid", "", 61, -30, 30);
  TH2F *h_ratio = new TH2F("h_ratio", "", 31, 0, 31, 36, 0, 36);

  TCanvas* c_pos = new TCanvas("c_pos","c_pos", 200, 10, 1200, 1200);
  c_pos->cd();
  c_pos->Divide(2,2);
  TH2F *h_inc  = new TH2F("h_inc","",100,-19*20*2,19*20*2,100,-19*20*2,19*20*2);
  TH2F *h_rec  = new TH2F("h_rec","",100,-19*20*2,19*20*2,100,-19*20*2,19*20*2);
  TH1F *h_dif1 = new TH1F("h_dif1","",100,-1,1);
  TH2F *h_dif2 = new TH2F("h_dif2","",100,-1,1,100,-10,10);


  double  edep_max = 0.;
  int  sc_max = 0;
  int  pc_max = 0;
  double  edep_next_max = 0.;
  double totedep;
  int totsc;
  int totpc;
  int edep_j, sc_j, pc_j;

  double pos_x_inc = 0.;
  double pos_y_inc = 0.;

  for(int i = 0 ; i < nentries ; i++){

    t->GetEntry(i);

    edep_max = 0.;
    sc_max = 0;
    pc_max = 0;

    totedep = 0.;
    totsc = 0;
    totpc = 0;

    pos_x_inc = 0.;
    pos_y_inc = 0.;

    for(int j = 0 ; j < n ; j++){
      totedep += edep[j];
      totsc += sc[j];
      totpc += op_pc[j];
      totE[i] += edep[j];
      if(edep[j] > edep_max) {edep_max = edep[j]; edep_j = j;E_max[i] = edep[j];}
      if(sc[j] > sc_max)     {sc_max = sc[j]; sc_j = j;S_max[i] = sc[j];}
      if(op_pc[j] > pc_max)     {pc_max = op_pc[j]; pc_j = j;P_max[i] = op_pc[j];}

      y = j%36;
      x = int(j/36);
      //from (0,0) to (30,36)

      h_edep->Fill(x,y,edep[j]);
      h_sc->Fill(x,y,sc[j]);
      h_pc->Fill(x,y,op_pc[j]);
    }
    /* if(edep_j - pc_j != 0) cout<<edep_j - pc_j<<endl; */

    /* for(int j = 0 ; j < n ; j++){ */
    /*   y = j%36; */
    /*   x = int(j/36); */
    
    /*   if(edep_j - pc_j != 0) h_edep->Fill(x,y,edep[j]); */
    /*   h_sc->Fill(x,y,sc[j]); */
    /*   if(edep_j - pc_j != 0) h_pc->Fill(x,y,op_pc[j]); */
    /* } */
    if(totedep!=0)    h->Fill(100*edep_max/totedep);

    for(int j = 0 ; j < n ; j++){
      w[j] = edep[j]/totE[i];
    }
    for(int j = 0 ; j < n ; j++){
      y = ((j%36)*crystal_size - (36-1)*0.5*crystal_size);//20mm per each crystal
      x = ((31-1)*0.5*crystal_size - (int(j/36))*crystal_size);
      //from (0,0) to (30,36)

      pos_x_rec[i] += x*w[j];
      pos_y_rec[i] += y*w[j];
    }
    /* cout<<pc_j<<endl; */
    pos_x_inc = PM[0]*3000/PM[2];
    pos_y_inc = PM[1]*3000/PM[2];
    double temp1_1 = (31-1)*0.5*crystal_size - (int(pc_j/36))*crystal_size;
    double temp1_2 = (pos_x_rec[i] - ((31-1)*0.5*crystal_size - (int(pc_j/36))*crystal_size))/crystal_size;
    double temp2 = pos_x_rec[i] - pos_x_inc;
    /* if(pos_x_rec[i] == pos_x_rec[i]) cout<<pos_x_rec[i]<<", "<<temp1_1<<", "<<temp1_2<<endl; */
    /* if(pos_x_rec[i] == pos_x_rec[i]) cout<<pos_x_rec[i]<<", "<<pos_x_inc<<", "<<temp2<<endl; */

    h_inc->Fill(pos_x_inc, pos_y_inc);
    h_rec->Fill(pos_x_rec[i], pos_y_rec[i]);
    /* if(pos_x_rec[i] == pos_x_rec[i]) h_dif1->Fill((pos_x_rec[i] - ((31-1)*0.5*crystal_size - (int(pc_j/36))*crystal_size))/crystal_size); */
    /* if(pos_x_rec[i] == pos_x_rec[i]) h_dif2->Fill((pos_x_rec[i] - ((31-1)*0.5*crystal_size - (int(pc_j/36))*crystal_size))/crystal_size, pos_x_rec[i] - pos_x_inc); */
    if(pos_x_rec[i] == pos_x_rec[i]) h_dif1->Fill((pos_x_rec[i] - ((31-1)*0.5*crystal_size - (int(pc_j/36))*crystal_size))/crystal_size);
    if(pos_x_rec[i] == pos_x_rec[i]) h_dif2->Fill((pos_x_rec[i] - ((31-1)*0.5*crystal_size - (int(pc_j/36))*crystal_size))/crystal_size, pos_x_rec[i] - pos_x_inc);
  }

  c_edep->cd(1);
  h_edep->Draw("colz");
  c_edep->cd(2);
  h_sc->Draw("colz");
  c_edep->cd(3);
  h_pc->Draw("colz");
  c_edep->cd(4);
  h->Draw();

  c_pos->cd(1);
  h_inc->Draw("colz");
  c_pos->cd(2);
  h_rec->Draw("colz");
  c_pos->cd(3);
  h_dif2->Draw("colz");
  c_pos->cd(4);
  h_dif1->Draw();
  gStyle->SetOptStat(11111111);
  /*   } */
  /* } */
}
