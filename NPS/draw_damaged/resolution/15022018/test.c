void test(){

  string histo_edep_string_front = "energy deposition in NPS with e-";
  string histo_nps_string_front = "optical photons in NPS with e-";
  string histo_pmt_string_front = "optical photons in PMT with e-";
  string file_dir = "/sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_";
  string file_end = "_0000%d.root";

  string output_string_front = "../output/15022018/edep/edep";
  string output_string_back = ".png";

  string dash = "_";
  string space = " ";
  string ene_string;
  string gap_string;

  int NumberOfRuns;

  /* ofstream outfile_edep("../output/16022018/edep/edep.txt" /\*, ios::app*\/);//ios::app is to append the existing file, not overwrite. */
  /* ofstream outfile_resolution("output/16022018/resolution/resolution.txt" /\*, ios::app *\/);//ios::app is to append the existing file, not overwrite. */
  /* outfile_resolution<<"sqrt(A*A + (B/sqrt(E))*(B/sqrt(E)) + (C/E)*(C/E))"<<"\n"<<endl; */

  //  const int n = 6;
  const int ene_range = 5;

  double energy[ene_range] = {0.5, 1, 3.25, 5.5, 7.75};//, 10};

  double er_x[ene_range] = {0.};

  double mean_0_0[ene_range] = {0.};
  double mean_er_0_0[ene_range] = {0.};
  double sigma_0_0[ene_range] = {0.};
  double sigma_er_0_0[ene_range] = {0.};
  double res_0_0[ene_range] = {0.};
  double res_erl_0_0[ene_range] = {0.};
  double res_erh_0_0[ene_range] = {0.};
  double res_er_0_0[ene_range] = {0.};
  double chi_0_0[ene_range] = {0.};

  double mean_0_5[ene_range] = {0.};//15056.9, 30180.2, 98073.8, 165971, 233899, 301594};
  double mean_er_0_5[ene_range] = {0.};//21.88, 12.56, 17.38, 24.0, 28.18, 26.27};
  double sigma_0_5[ene_range] = {0.};//186.673, 247.158, 486.996, 685.698, 791.328, 1067.88};
  double sigma_er_0_5[ene_range] = {0.};//16.7, 10.5, 18.1, 26.4, 26.1, 32.6};
  double res_0_5[ene_range] = {0.};//0.};
  double res_erl_0_5[ene_range] = {0.};//0.};
  double res_erh_0_5[ene_range] = {0.};//0.};
  double res_er_0_5[ene_range] = {0.};//0.};
  double chi_0_5[ene_range] = {0.};//1.52495, 1.06272, 0.823513, 0.936865, 1.0369, 1.19709};

  double mean_1_0[ene_range] = {0.};//15050.9, 30137.1, 98003.9, 165811, 233616, 301299};
  double mean_er_1_0[ene_range] = {0.};//4.094, 6.4, 25, 15.01, 44.08, 34.58};
  double sigma_1_0[ene_range] = {0.};//178.155, 256.184, 482.243, 723.691, 817.994, 1028.49};
  double sigma_er_1_0[ene_range] = {0.};//4.4, 6.0, 25.5, 16.8, 30.5, 37.3};
  double res_1_0[ene_range] = {0.};//0.};
  double res_erl_1_0[ene_range] = {0.};//0.};
  double res_erh_1_0[ene_range] = {0.};//0.};
  double res_er_1_0[ene_range] = {0.};//0.};
  double chi_1_0[ene_range] = {0.};//0.62615, 1.47331, 1.02548, 1.3496, 1.00004, 0.771304};

  double mean_1_5[ene_range] = {0.};//15041.8, 30125.5, 97884.5, 165705, 383147, 301028};
  double mean_er_1_5[ene_range] = {0.};//3.363, 7.202, 35.74, 33.92, 18.82, 105};
  double sigma_1_5[ene_range] = {0.};//194.464, 253.535, 520.956, 654.795, 1397.57, 1056.08};
  double sigma_er_1_5[ene_range] = {0.};//3.3, 6.6, 27.2, 25.7, 19.3, 77.4};
  double res_1_5[ene_range] = {0.};//0.};
  double res_erl_1_5[ene_range] = {0.};//0.};
  double res_erh_1_5[ene_range] = {0.};//0.};
  double res_er_1_5[ene_range] = {0.};//0.};
  double chi_1_5[ene_range] = {0.};//1.58804, 1.1135, 0.690863, 1.237, 1.56974, 0.851701};

  double mean_2_0[ene_range] = {0.};//15035.5, 30088.9, 97766.9, 165486, 232917, 300566};
  double mean_er_2_0[ene_range] = {0.};//4.356, 10.83, 12.45, 44.17, 29.02, 61.06};
  double sigma_2_0[ene_range] = {0.};//186.102, 282.581, 547.748, 699.66, 1043.8, 1102.99};
  double sigma_er_2_0[ene_range] = {0.};//4.7, 10.7, 12.6, 36.8, 33.3, 56.5};
  double res_2_0[ene_range] = {0.};//0.};
  double res_erl_2_0[ene_range] = {0.};//0.};
  double res_erh_2_0[ene_range] = {0.};//0.};
  double res_er_2_0[ene_range] = {0.};//0.};
  double chi_2_0[ene_range] = {0.};//0.824414, 0.641367, 1.25332, 0.870274, 1.23378, 1.23317};

  gap_size = 0; ene = 1;

  /* for(int gap_size = 0 ; gap_size < 5 ; gap_size++){ */
    if (gap_size == 0)       gap_string = "0_0mm";
    else if (gap_size == 1)  gap_string = "0_5mm";
    else if (gap_size == 2)  gap_string = "1_0mm";
    else if (gap_size == 3)  gap_string = "1_5mm";
    else if (gap_size == 4)  gap_string = "2_0mm";

    /* for(int ene = 0 ; ene < ene_range ; ene++){ */
      if (ene == 0)       {ene_string = "500MeV";  NumberOfRuns = 10;}
      else if (ene == 1)  {ene_string = "1GeV";    NumberOfRuns = 20;}
      else if (ene == 2)  {ene_string = "3_25GeV"; NumberOfRuns = 45;}
      else if (ene == 3)  {ene_string = "5_5GeV";  NumberOfRuns = 110;}
      else if (ene == 4)  {ene_string = "7_75GeV"; NumberOfRuns = 155;}
      //      else if (ene == 5)  {ene_string = "10GeV";   NumberOfRuns = 200;}


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
      double edep[n] = {0.};
      int pid[n] = {0};
      int sc[n] = {0};
      int op_pc[n] = {0};

      double ran[n] = {0.};
      TRandom3 rand;  //TRandom3 rand : create a generator
                      //always initialized with the same default seed
                      //Trandom3 rand(0) : create a generator 
                      //with a new seed generated by a UID(unique identifier)(time, space)
                      //or you can do rand.SetSeed(0) to be time dependently random.
      rand.SetSeed(1);//SetSeed(long). 0 : time random(UID)

      for(int i = 0 ; i < n ; i++){
	ran[i] = rand.Gaus(1, 0.01);
      }

      int nentries = 0;
      int binNo = 0;
      double totedep = 0;
      int totsc = 0;
      int totpc = 0;

      double edep_max = 0.;
      int sc_max = 0;
      int pc_max = 0;
      int edep_j = 0;
      int sc_j = 0;
      int pc_j = 0;


      double totedep_max = 0.;
      int totsc_max = 0;
      int totpc_max = 0;

      //	TTree *t = (TTree*)f->Get("t");
      t->SetBranchAddress("edep", edep);
      t->SetBranchAddress("pid", pid);
      t->SetBranchAddress("sc", sc);
      t->SetBranchAddress("op_pc", op_pc);

      /* TCanvas *c1 = new TCanvas("c1", "energy deposition in NPS", 200, 10 ,700, 500); */
      /* TCanvas *c2 = new TCanvas("c2", "optical photons in NPS", 200, 10 ,700, 500); */
      /* TCanvas *c3 = new TCanvas("c3", "optical photons in PMT", 200, 10 ,700, 500); */
      TCanvas *c1_edep = new TCanvas("c1_edep", "energy deposition in NPS", 200, 10 ,1400, 1000);
      c1_edep->Divide(2,2);

      nentries =  t->GetEntries();
      binNo = sqrt(nentries);
      cout<<nentries<<endl;
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

	  if(edep[j] > edep_max)    {edep_max = edep[j]; edep_j = j;}
	  if(sc[j] > sc_max)        {sc_max = sc[j]; sc_j = j;}
	  if(op_pc[j] > pc_max)     {pc_max = op_pc[j]; pc_j = j;}

	}

	/* if((pc_j >= 0 && pc_j <= 61)||(pc_j >= 1054 && pc_j <= 1115)||((pc_j - 30)%31 == 0)||((pc_j - 29)%31 == 0)||((pc_j - 1)%31 == 0)||(pc_j%31 == 0)) totpc = 0; */

	if(totedep > totedep_max) totedep_max = totedep;
	if(totsc > totsc_max)     totsc_max = totsc;
	if(totpc > totpc_max)     totpc_max = totpc;
      }

      int edep_x_min = 0.85*totedep_max;//histogram x-axis start
      int edep_x_max = totedep_max;//histogram x-axis finish
      int sc_x_min = 0.85*totsc_max;
      int sc_x_max = totsc_max;
      int pc_x_min = 0.85*totpc_max;
      int pc_x_max = totpc_max;

      cout<<edep_x_min<<" "<<edep_x_max<<" "<<binNo<<endl;

      TH1F *h1 = new TH1F("edep",histo_edep_char,binNo,edep_x_min,edep_x_max);
      TH1F *h2 = new TH1F("sc",histo_nps_char,binNo,sc_x_min,sc_x_max);
      TH1F *h3 = new TH1F("pmt",histo_pmt_char,binNo,pc_x_min,pc_x_max);
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

	  if(edep[j] > edep_max)    {edep_max = edep[j]; edep_j = j;}
	  if(sc[j] > sc_max)        {sc_max = sc[j]; sc_j = j;}
	  if(op_pc[j] > pc_max)     {pc_max = op_pc[j]; pc_j = j;}

	}
	/* if((pc_j >= 0 && pc_j <= 61)||(pc_j >= 1054 && pc_j <= 1115)||((pc_j - 30)%31 == 0)||((pc_j - 29)%31 == 0)||((pc_j - 1)%31 == 0)||(pc_j%31 == 0)) totpc = 0; */

	if(totedep!=0)    h1->Fill(totedep);
	if(totsc!=0)    h2->Fill(totsc);
	if(totpc!=0)    h3->Fill(totpc);

      }



      //fitting
      double edep_peak = (h1->GetMaximumBin())*((edep_x_max - edep_x_min)/(double)binNo) + edep_x_min;
      double sc_peak = h2->GetMaximumBin()*((sc_x_max - sc_x_min)/(double)binNo) + sc_x_min;
      double pc_peak = h3->GetMaximumBin()*((pc_x_max - pc_x_min)/(double)binNo) + pc_x_min;

      int edep_bin1 = h1->FindFirstBinAbove(0.5*(h1->GetMaximum()))*((edep_x_max - edep_x_min)/(double)binNo) + edep_x_min;
      int sc_bin1   = h2->FindFirstBinAbove(0.5*(h2->GetMaximum()))*((sc_x_max - sc_x_min)/(double)binNo) + sc_x_min;
      int pc_bin1   = h3->FindFirstBinAbove(0.5*(h3->GetMaximum()))*((pc_x_max - pc_x_min)/(double)binNo) + pc_x_min;
      int edep_bin2 = h1->FindLastBinAbove(0.15*(h1->GetMaximum()))*((edep_x_max - edep_x_min)/(double)binNo) + edep_x_min;
      int sc_bin2   = h2->FindLastBinAbove(0.15*(h2->GetMaximum()))*((sc_x_max - sc_x_min)/(double)binNo) + sc_x_min;
      int pc_bin2   = h3->FindLastBinAbove(0.15*(h3->GetMaximum()))*((pc_x_max - pc_x_min)/(double)binNo) + pc_x_min;

      c1_edep->cd(1);
      h1->Draw();
      gStyle->SetOptFit(111111);
      TPaveStats *st1 =//THIS PART is IMPORTANT!! the stat box can be positioned with gStle above. HOWEVER! after the fitting, you have to use TPaveStats!!
	(TPaveStats*)h1->GetListOfFunctions()->FindObject("stats");
      st1->SetX1NDC(0.15); //new x start position
      st1->SetX2NDC(0.40); //new x end position
      st1->SetY1NDC(0.5);
      st1->SetY2NDC(0.9);
      /* h1->Fit("gaus","","",edep_peak - 0.125*(edep_peak - edep_x_min) /\*- x_edep*\/, edep_peak + 0.5*(edep_x_max - edep_peak) /\*+ x_edep*\/); */
      h1->Fit("gaus","","",edep_bin1,edep_bin2);
      TF1 *fit1 = h1->GetFunction("gaus");
      double mean_edep = fit1->GetParameter(1);
      double mean_edep_err = fit1->GetParError(1);
      double sigma_edep = fit1->GetParameter(2);
      double sigma_edep_err = fit1->GetParError(2);
      double chi2_edep = fit1->GetChisquare();
      double ndf_edep = fit1->GetNDF();

      c1_edep->cd(2);
      h2->Draw();
      gStyle->SetOptFit(111111);
      TPaveStats *st2 = (TPaveStats*)h2->GetListOfFunctions()->FindObject("stats");
      st2->SetX1NDC(0.15); //new x start position
      st2->SetX2NDC(0.40); //new x end position
      st2->SetY1NDC(0.5);
      st2->SetY2NDC(0.9);
      /* h2->Fit("gaus","","",sc_peak - 0.125*(sc_peak - sc_x_min) /\*- x_sc*\/, sc_peak + 0.5*(sc_x_max - sc_peak) /\*+ x_sc*0.5*\/); */
      h2->Fit("gaus","","",sc_bin1,sc_bin2);
      TF1 *fit2 = h2->GetFunction("gaus");
      double mean_sc = fit2->GetParameter(1);
      double mean_sc_err = fit2->GetParError(1);
      double sigma_sc = fit2->GetParameter(2);
      double sigma_sc_err = fit2->GetParError(2);
      double chi2_sc = fit2->GetChisquare();
      double ndf_sc = fit2->GetNDF();

      c1_edep->cd(3);
      h3->Draw();
      gStyle->SetOptFit(111111);
      TPaveStats *st3 = (TPaveStats*)h3->GetListOfFunctions()->FindObject("stats");
      st3->SetX1NDC(0.15); //new x start position
      st3->SetX2NDC(0.40); //new x end position
      st3->SetY1NDC(0.5);
      st3->SetY2NDC(0.9);
      /* h3->Fit("gaus","","",pc_peak - 0.125*(pc_peak - pc_x_min) /\*- x_pc*\/, pc_peak + 0.5*(pc_x_max - pc_peak) /\*+ x_pc*\/); */
      h3->Fit("gaus","","",pc_bin1,pc_bin2);
      TF1 *fit3 = h3->GetFunction("gaus");
      double mean_pc = fit3->GetParameter(1);
      double mean_pc_err = fit3->GetParError(1);
      double sigma_pc = fit3->GetParameter(2);
      double sigma_pc_err = fit3->GetParError(2);
      double chi2_pc = fit3->GetChisquare();
      double ndf_pc = fit3->GetNDF();



      //outfile_edep<<histo_edep_string_front + space + ene_string + space + gap_string<<endl;
      //outfile_edep<<"mean     : "<<mean_edep<<endl;
      //outfile_edep<<"mean err : "<<mean_edep_err<<endl;
      //outfile_edep<<"sigma    : "<<sigma_edep<<endl;
      //outfile_edep<<"sigma err: "<<sigma_edep_err<<endl;
      //outfile_edep<<"chi2     : "<<chi2_edep<<endl;
      //outfile_edep<<"ndf      : "<<ndf_edep<<endl;
      //outfile_edep<<"chi2/ndf : "<<chi2_edep/ndf_edep<<"\n"<<endl;


      //outfile_edep<<histo_nps_string_front + space + ene_string + space + gap_string<<endl;
      //outfile_edep<<"mean     : "<<mean_sc<<endl;
      //outfile_edep<<"mean err : "<<mean_sc_err<<endl;
      //outfile_edep<<"sigma    : "<<sigma_sc<<endl;
      //outfile_edep<<"sigma err: "<<sigma_sc_err<<endl;
      //outfile_edep<<"chi2     : "<<chi2_sc<<endl;
      //outfile_edep<<"ndf      : "<<ndf_sc<<endl;
      //outfile_edep<<"chi2/ndf : "<<chi2_sc/ndf_sc<<"\n"<<endl;


      //outfile_edep<<histo_pmt_string_front + space + ene_string + space + gap_string<<endl;
      //outfile_edep<<"mean     : "<<mean_pc<<endl;
      //outfile_edep<<"mean err : "<<mean_pc_err<<endl;
      //outfile_edep<<"sigma    : "<<sigma_pc<<endl;
      //outfile_edep<<"sigma err: "<<sigma_pc_err<<endl;
      //outfile_edep<<"chi2     : "<<chi2_pc<<endl;
      //outfile_edep<<"ndf      : "<<ndf_pc<<endl;
      //outfile_edep<<"chi2/ndf : "<<chi2_pc/ndf_pc<<"\n"<<endl;

  
      //    cout<<"????"<<mean_pc<<", mean_0_0[ene] = "<<mean_0_0[ene]<<endl;
      if(gap_size == 0){
	//      	cout<<"!!!!!!"<<ene<<endl;
      	mean_0_0[ene] = mean_pc;
	//      	cout<<"1111111111"<<mean_0_0[ene]<<endl;
      	mean_er_0_0[ene] = mean_pc_err;
      	sigma_0_0[ene] = sigma_pc;
      	sigma_er_0_0[ene] = sigma_pc_err;
      }
      else if(gap_size == 1){
      	mean_0_5[ene] = mean_pc;
      	mean_er_0_5[ene] = mean_pc_err;
      	sigma_0_5[ene] = sigma_pc;
      	sigma_er_0_5[ene] = sigma_pc_err;
      }
      else if(gap_size == 2){
      	mean_1_0[ene] = mean_pc;
      	mean_er_1_0[ene] = mean_pc_err;
      	sigma_1_0[ene] = sigma_pc;
      	sigma_er_1_0[ene] = sigma_pc_err;
      }
      else if(gap_size == 3){
      	mean_1_5[ene] = mean_pc;
      	mean_er_1_5[ene] = mean_pc_err;
      	sigma_1_5[ene] = sigma_pc;
      	sigma_er_1_5[ene] = sigma_pc_err;
      }
      else if(gap_size == 4){
      	mean_2_0[ene] = mean_pc;
      	mean_er_2_0[ene] = mean_pc_err;
      	sigma_2_0[ene] = sigma_pc;
      	sigma_er_2_0[ene] = sigma_pc_err;
      }

      /* c1_edep->Print(output_char);cout<<"gap_size : "<<gap_size<<", ene : "<<ene<<endl; */
      /* c2->Print("output/sc_1GeV.png"); */
      /* c3->Print("output/pc_1GeV.png"); */
      /* c1_edep->Close(); */
      /* c2->Close(); */
      /* c3->Close(); */
      delete gROOT->FindObject("edep");
      delete gROOT->FindObject("sc");
      delete gROOT->FindObject("pmt");
      delete gROOT->FindObject("t");
      /* f->Close(); */
  /*   } */
  /* } */

  //outfile_edep.close();



  for(int i = 0 ; i < ene_range ; i++){

    /* mean_0_0[i] = mean_0_0[i]*0.5; */
    /* mean_0_5[i] = mean_0_5[i]*0.5; */
    /* mean_1_0[i] = mean_1_0[i]*0.5; */
    /* mean_1_5[i] = mean_1_5[i]*0.5; */
    /* mean_2_0[i] = mean_2_0[i]*0.5; */

    res_0_0[i] = sigma_0_0[i]/mean_0_0[i]*100;
    res_0_5[i] = sigma_0_5[i]/mean_0_5[i]*100;
    res_1_0[i] = sigma_1_0[i]/mean_1_0[i]*100;
    res_1_5[i] = sigma_1_5[i]/mean_1_5[i]*100;
    res_2_0[i] = sigma_2_0[i]/mean_2_0[i]*100;

    res_er_0_0[i] = sqrt((sigma_er_0_0[i]/mean_0_0[i])*(sigma_er_0_0[i]/mean_0_0[i]) + (mean_er_0_0[i]/mean_0_0[i])*(mean_er_0_0[i]/mean_0_0[i]))*100;
    res_er_0_5[i] = sqrt((sigma_er_0_5[i]/mean_0_5[i])*(sigma_er_0_5[i]/mean_0_5[i]) + (mean_er_0_5[i]/mean_0_5[i])*(mean_er_0_5[i]/mean_0_5[i]))*100;
    res_er_1_0[i] = sqrt((sigma_er_1_0[i]/mean_1_0[i])*(sigma_er_1_0[i]/mean_1_0[i]) + (mean_er_1_0[i]/mean_1_0[i])*(mean_er_1_0[i]/mean_1_0[i]))*100;
    res_er_1_5[i] = sqrt((sigma_er_1_5[i]/mean_1_5[i])*(sigma_er_1_5[i]/mean_1_5[i]) + (mean_er_1_5[i]/mean_1_5[i])*(mean_er_1_5[i]/mean_1_5[i]))*100;
    res_er_2_0[i] = sqrt((sigma_er_2_0[i]/mean_2_0[i])*(sigma_er_2_0[i]/mean_2_0[i]) + (mean_er_2_0[i]/mean_2_0[i])*(mean_er_2_0[i]/mean_2_0[i]))*100;

  }

  TCanvas *c1_res = new TCanvas("c1_res", "resolution", 200, 10, 700, 500);
  c1_res->cd();
  c1_res->SetGrid();

  TCanvas *c2_res = new TCanvas("c2_res", "resolution each", 200, 10, 1400, 1500);
  c2_res->Divide(2,3);

  TCanvas *c3_res = new TCanvas("c3_res", "Parameters", 200, 10, 1400, 1000);
  c3_res->Divide(2,2);

  TMultiGraph *mg = new TMultiGraph();

  const char *fit_00_name = "sqrt([0]*[0] + ([1]/sqrt(x))*([1]/sqrt(x)) + ([2]/x)*([2]/x))";
  TF1 *fit_00 = new TF1("fit_00", fit_00_name, 0, 10);
  fit_00->SetParName(0, "A");//optional, name
  fit_00->SetParName(1, "B");
  fit_00->SetParName(2, "C");
  fit_00->SetParameter(0, 0.01);//mandatory, start values
  fit_00->SetParameter(1, 0.01);
  //  fit_00->SetParameter(2, 0.01);
  fit_00->SetParameter(2, 0);
  fit_00->SetParLimits(0, 0, 10);
  fit_00->SetParLimits(1, 0, 10);
  // fit_00->SetParLimits(2, 0, 10);
  fit_00->FixParameter(2, 0);

  TGraphErrors *gr_00 = new TGraphErrors(ene_range, energy, res_0_0, er_x, res_er_0_0);
  gr_00->SetTitle("0.0mm");
  gr_00->SetMarkerColor(1);
  gr_00->SetMarkerSize(1);
  gr_00->SetMarkerStyle(24);
  gr_00->Fit("fit_00");
  gr_00->GetFunction("fit_00")->SetLineColor(1);
  gr_00->GetFunction("fit_00")->SetLineWidth(1);
  //outfile_resolution<<"gap : 0.0mm"<<endl;
  //outfile_resolution<<"A       : "<<gr_00->GetFunction("fit_00")->GetParameter(0)<<endl;
  //outfile_resolution<<"A error : "<<gr_00->GetFunction("fit_00")->GetParError(0)<<endl;
  //outfile_resolution<<"B       : "<<gr_00->GetFunction("fit_00")->GetParameter(1)<<endl;
  //outfile_resolution<<"B error : "<<gr_00->GetFunction("fit_00")->GetParError(1)<<endl;
  //outfile_resolution<<"C       : "<<gr_00->GetFunction("fit_00")->GetParameter(2)<<endl;
  //outfile_resolution<<"C error : "<<gr_00->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_00 = gr_00->GetFunction("fit_00")->GetParameter(0);
  double A_err_00 = gr_00->GetFunction("fit_00")->GetParError(0);
  double B_00 = gr_00->GetFunction("fit_00")->GetParameter(1);
  double B_err_00 = gr_00->GetFunction("fit_00")->GetParError(1);
  double C_00 = gr_00->GetFunction("fit_00")->GetParameter(2);
  double C_err_00 = gr_00->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_00);
  c2_res->cd(1);
  gr_00->GetXaxis()->SetLimits(0, 11);
  gr_00->GetYaxis()->SetRangeUser(0, 3);
  gr_00->Draw("APE");

  //gr_00->Draw("AP");//A : draw axis

  //  TGraph *gr_05 = new TGraph(n, energy, res_0_5);
  TGraphErrors *gr_05 = new TGraphErrors(ene_range, energy, res_0_5, er_x, res_er_0_5);
  gr_05->SetTitle("0.5mm");
  gr_05->SetMarkerColor(2);
  gr_00->SetMarkerSize(1);
  gr_05->SetMarkerStyle(25);
  gr_05->Fit("fit_00");
  gr_05->GetFunction("fit_00")->SetLineColor(2);
  gr_05->GetFunction("fit_00")->SetLineWidth(1);
  //outfile_resolution<<"gap : 0.5mm"<<endl;
  //outfile_resolution<<"A       : "<<gr_05->GetFunction("fit_00")->GetParameter(0)<<endl;
  //outfile_resolution<<"A error : "<<gr_05->GetFunction("fit_00")->GetParError(0)<<endl;
  //outfile_resolution<<"B       : "<<gr_05->GetFunction("fit_00")->GetParameter(1)<<endl;
  //outfile_resolution<<"B error : "<<gr_05->GetFunction("fit_00")->GetParError(1)<<endl;
  //outfile_resolution<<"C       : "<<gr_05->GetFunction("fit_00")->GetParameter(2)<<endl;
  //outfile_resolution<<"C error : "<<gr_05->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_05 = gr_05->GetFunction("fit_00")->GetParameter(0);
  double A_err_05 = gr_05->GetFunction("fit_00")->GetParError(0);
  double B_05 = gr_05->GetFunction("fit_00")->GetParameter(1);
  double B_err_05 = gr_05->GetFunction("fit_00")->GetParError(1);
  double C_05 = gr_05->GetFunction("fit_00")->GetParameter(2);
  double C_err_05 = gr_05->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_05);
  c2_res->cd(2);
  gr_05->GetXaxis()->SetLimits(0, 11);
  gr_05->GetYaxis()->SetRangeUser(0, 3);
  gr_05->Draw("APE");

  //  TGraph *gr_10 = new TGraph(n, energy, res_1_0);

  TGraphErrors *gr_10 = new TGraphErrors(ene_range, energy, res_1_0, er_x, res_er_1_0);
  gr_10->SetTitle("1.0mm");
  gr_10->SetMarkerColor(3);
  gr_10->SetMarkerSize(1);
  gr_10->SetMarkerStyle(4);
  gr_10->Fit("fit_00");
  gr_10->GetFunction("fit_00")->SetLineColor(3);
  gr_10->GetFunction("fit_00")->SetLineWidth(1);
  //outfile_resolution<<"gap : 1.0mm"<<endl;
  //outfile_resolution<<"A       : "<<gr_10->GetFunction("fit_00")->GetParameter(0)<<endl;
  //outfile_resolution<<"A error : "<<gr_10->GetFunction("fit_00")->GetParError(0)<<endl;
  //outfile_resolution<<"B       : "<<gr_10->GetFunction("fit_00")->GetParameter(1)<<endl;
  //outfile_resolution<<"B error : "<<gr_10->GetFunction("fit_00")->GetParError(1)<<endl;
  //outfile_resolution<<"C       : "<<gr_10->GetFunction("fit_00")->GetParameter(2)<<endl;
  //outfile_resolution<<"C error : "<<gr_10->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_10 = gr_10->GetFunction("fit_00")->GetParameter(0);
  double A_err_10 = gr_10->GetFunction("fit_00")->GetParError(0);
  double B_10 = gr_10->GetFunction("fit_00")->GetParameter(1);
  double B_err_10 = gr_10->GetFunction("fit_00")->GetParError(1);
  double C_10 = gr_10->GetFunction("fit_00")->GetParameter(2);
  double C_err_10 = gr_10->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_10);
  c2_res->cd(3);
  gr_10->GetXaxis()->SetLimits(0, 11);
  gr_10->GetYaxis()->SetRangeUser(0, 3);
  gr_10->Draw("APE");

  //  TGraph *gr_15 = new TGraph(n, energy, res_1_5);
  TGraphErrors *gr_15 = new TGraphErrors(ene_range, energy, res_1_5, er_x, res_er_1_5);
  gr_15->SetTitle("1.5mm");
  gr_15->SetMarkerColor(4);
  gr_15->SetMarkerSize(1);
  gr_15->SetMarkerStyle(26);
  gr_15->Fit("fit_00");
  gr_15->GetFunction("fit_00")->SetLineColor(4);
  gr_15->GetFunction("fit_00")->SetLineWidth(1);
  //outfile_resolution<<"gap : 1.5mm"<<endl;
  //outfile_resolution<<"A       : "<<gr_15->GetFunction("fit_00")->GetParameter(0)<<endl;
  //outfile_resolution<<"A error : "<<gr_15->GetFunction("fit_00")->GetParError(0)<<endl;
  //outfile_resolution<<"B       : "<<gr_15->GetFunction("fit_00")->GetParameter(1)<<endl;
  //outfile_resolution<<"B error : "<<gr_15->GetFunction("fit_00")->GetParError(1)<<endl;
  //outfile_resolution<<"C       : "<<gr_15->GetFunction("fit_00")->GetParameter(2)<<endl;
  //outfile_resolution<<"C error : "<<gr_15->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_15 = gr_15->GetFunction("fit_00")->GetParameter(0);
  double A_err_15 = gr_15->GetFunction("fit_00")->GetParError(0);
  double B_15 = gr_15->GetFunction("fit_00")->GetParameter(1);
  double B_err_15 = gr_15->GetFunction("fit_00")->GetParError(1);
  double C_15 = gr_15->GetFunction("fit_00")->GetParameter(2);
  double C_err_15 = gr_15->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_15);
  c2_res->cd(4);
  gr_15->GetXaxis()->SetLimits(0, 11);
  gr_15->GetYaxis()->SetRangeUser(0, 3);
  gr_15->Draw("APE");

  //  TGraph *gr_20 = new TGraph(n, energy, res_2_0);
  //  TGraphAsymmErrors *gr_20 = new TGraphAsymmErrors(n, energy, er_x, er_x, res_2_0, res_erl_2_0, res_erh_2_0);
  TGraphErrors *gr_20 = new TGraphErrors(ene_range, energy, res_2_0, er_x, res_er_2_0);
  gr_20->SetTitle("Resolution of the NPS depending on the gap btw the crystals");
  gr_20->GetXaxis()->SetTitle("Energy [GeV]");
  gr_20->GetYaxis()->SetTitle("Resolution [%]");
  gr_20->GetXaxis()->SetLimits(0, 11);
  gr_20->GetYaxis()->SetRangeUser(0, 3);
  gr_20->SetMarkerColor(6);
  gr_20->SetMarkerSize(1);
  gr_20->SetMarkerStyle(27);
  gr_20->Fit("fit_00");
  gr_20->GetFunction("fit_00")->SetLineColor(6);
  gr_20->GetFunction("fit_00")->SetLineWidth(1);
  //outfile_resolution<<"gap : 2.0mm"<<endl;
  //outfile_resolution<<"A       : "<<gr_20->GetFunction("fit_00")->GetParameter(0)<<endl;
  //outfile_resolution<<"A error : "<<gr_20->GetFunction("fit_00")->GetParError(0)<<endl;
  //outfile_resolution<<"B       : "<<gr_20->GetFunction("fit_00")->GetParameter(1)<<endl;
  //outfile_resolution<<"B error : "<<gr_20->GetFunction("fit_00")->GetParError(1)<<endl;
  //outfile_resolution<<"C       : "<<gr_20->GetFunction("fit_00")->GetParameter(2)<<endl;
  //outfile_resolution<<"C error : "<<gr_20->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_20 = gr_20->GetFunction("fit_00")->GetParameter(0);
  double A_err_20 = gr_20->GetFunction("fit_00")->GetParError(0);
  double B_20 = gr_20->GetFunction("fit_00")->GetParameter(1);
  double B_err_20 = gr_20->GetFunction("fit_00")->GetParError(1);
  double C_20 = gr_20->GetFunction("fit_00")->GetParameter(2);
  double C_err_20 = gr_20->GetFunction("fit_00")->GetParError(2);
  c1_res->cd();
  gr_20->Draw("APE");
  mg->Draw("PE");


  TGraphErrors *gr_20_2 = new TGraphErrors(ene_range, energy, res_2_0, er_x, res_er_2_0);
  gr_20_2->SetTitle("2.0mm");
  gr_20_2->GetXaxis()->SetTitle("Energy [GeV]");
  gr_20_2->GetYaxis()->SetTitle("Resolution [%]");
  gr_20_2->SetMarkerColor(6);
  gr_20_2->SetMarkerSize(1);
  gr_20_2->SetMarkerStyle(27);
  gr_20_2->Fit("fit_00");
  gr_20_2->GetFunction("fit_00")->SetLineColor(6);
  gr_20_2->GetFunction("fit_00")->SetLineWidth(1);
  c2_res->cd(5);
  gr_20_2->GetXaxis()->SetLimits(0, 11);
  gr_20_2->GetYaxis()->SetRangeUser(0, 3);
  gr_20_2->Draw("APE");

  TLegend *leg = new TLegend(0.55, 0.55, .9, .9);
  leg->AddEntry(gr_00, "0.0mm", "p");
  leg->AddEntry(gr_05, "0.5mm", "p");
  leg->AddEntry(gr_10, "1.0mm", "p");
  leg->AddEntry(gr_15, "1.5mm", "p");
  leg->AddEntry(gr_20, "2.0mm", "p");
  c1_res->cd();
  leg->Draw();


  double gap[5] = {0, 0.5, 1, 1.5, 2};
  double gap_err[5] = {0.};
  double A[5] = {A_00, A_05, A_10, A_15, A_20};
  double B[5] = {B_00, B_05, B_10, B_15, B_20};
  cout<<B_00<<B_05<<B_10<<B_15<<B_20<<endl;
  double C[5] = {C_00, C_05, C_10, C_15, C_20};
  double A_err[5] = {A_err_00, A_err_05, A_err_10, A_err_15, A_err_20};
  double B_err[5] = {B_err_00, B_err_05, B_err_10, B_err_15, B_err_20};
  double C_err[5] = {C_err_00, C_err_05, C_err_10, C_err_15, C_err_20};

  TGraphErrors *par_A = new TGraphErrors(5, gap, A, gap_err, A_err);
  par_A->SetTitle("A");
  par_A->GetXaxis()->SetRangeUser(-3.0,3.0);
  par_A->GetXaxis()->SetTitle("gap [mm]");
  par_A->GetYaxis()->SetTitle("Parameter");
  par_A->GetXaxis()->SetLimits(-0.5, 2.5);
  par_A->GetYaxis()->SetRangeUser(0, 1.2);
  par_A->SetMarkerColor(1);
  par_A->SetMarkerSize(1);
  par_A->SetMarkerStyle(24);
  c3_res->cd(1);
  par_A->Draw("APE");

  TGraphErrors *par_B = new TGraphErrors(5, gap, B, gap_err, B_err);
  par_B->SetTitle("B");
  par_B->GetXaxis()->SetRangeUser(-3.0,3.0);
  par_B->GetXaxis()->SetTitle("gap [mm]");
  par_B->GetYaxis()->SetTitle("Parameter");
  par_B->GetXaxis()->SetLimits(-0.5, 2.5);
  par_B->GetYaxis()->SetRangeUser(0, 1.2);
  par_B->SetMarkerColor(2);
  par_B->SetMarkerSize(1);
  par_B->SetMarkerStyle(25);
  c3_res->cd(2);
  par_B->Draw("APE");

  TGraphErrors *par_C = new TGraphErrors(5, gap, C, gap_err, C_err);
  par_C->SetTitle("C");
  par_C->GetXaxis()->SetRangeUser(-3.0,3.0);
  par_C->GetXaxis()->SetTitle("gap [mm]");
  par_C->GetYaxis()->SetTitle("Parameter");
  par_C->GetXaxis()->SetLimits(-0.5, 2.5);
  par_C->GetYaxis()->SetRangeUser(0, 1.2);
  par_C->SetMarkerColor(4);
  par_C->SetMarkerSize(1);
  par_C->SetMarkerStyle(26);
  c3_res->cd(3);
  par_C->Draw("APE");



  /* c1_res->Print("../output/16022018/resolution/resolution.png"); */
  /* c2_res->Print("../output/16022018/resolution/resoltuion_each.png"); */
  /* c3_res->Print("../output/16022018/resolution/parameter.png"); */
  /* c1_res->Close(); */
  /* c2_res->Close(); */
  /* c3_res->Close(); */
  //outfile_resolution.close();
}
