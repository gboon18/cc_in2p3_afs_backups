void delete(){


  ofstream outfile("output/07022018/resolution/delete.txt" /*, ios::app */);//ios::app is to append the existing file, not overwrite.
  outfile<<"sqrt(A*A + (B/sqrt(E))*(B/sqrt(E)) + (C/E)*(C/E))"<<"\n"<<endl;

  const int n = 6;

  double energy[n] = {0.5, 1, 3.25, 5.5, 7.75, 10};

  double er_x[n] = {0.};

  double mean_0_0[n] = {15090, 30172.3, 98144.3, 166070, 234006, 301938};
  double mean_er_0_0[n] = {7.778, 6.673, 19.15, 14.24, 38.6, 22.11};
  double sigma_0_0[n] = {156.647, 260.312, 498.649, 686.175, 848.874, 974.089};
  double sigma_er_0_0[n] = {6.8, 7.0, 18.1, 17.3, 37.1, 27.4};
  double res_0_0[n] = {0.};
  double res_erl_0_0[n] = {0.};
  double res_erh_0_0[n] = {0.};
  double res_er_0_0[n] = {0.};
  double chi_0_0[n] = {0.768555, 1.23626, 0.710275, 0.761587, 1.18192,1.26921};

  double mean_0_5[n] = {15056.9, 30180.2, 98073.8, 165971, 233899, 301594};
  double mean_er_0_5[n] = {21.88, 12.56, 17.38, 24.0, 28.18, 26.27};
  double sigma_0_5[n] = {186.673, 247.158, 486.996, 685.698, 791.328, 1067.88};
  double sigma_er_0_5[n] = {16.7, 10.5, 18.1, 26.4, 26.1, 32.6};
  double res_0_5[n] = {0.};
  double res_erl_0_5[n] = {0.};
  double res_erh_0_5[n] = {0.};
  double res_er_0_5[n] = {0.};
  double chi_0_5[n] = {1.52495, 1.06272, 0.823513, 0.936865, 1.0369, 1.19709};

  double mean_1_0[n] = {15050.9, 30137.1, 98003.9, 165811, 233616, 301299};
  double mean_er_1_0[n] = {4.094, 6.4, 25, 15.01, 44.08, 34.58};
  double sigma_1_0[n] = {178.155, 256.184, 482.243, 723.691, 817.994, 1028.49};
  double sigma_er_1_0[n] = {4.4, 6.0, 25.5, 16.8, 30.5, 37.3};
  double res_1_0[n] = {0.};
  double res_erl_1_0[n] = {0.};
  double res_erh_1_0[n] = {0.};
  double res_er_1_0[n] = {0.};
  double chi_1_0[n] = {0.62615, 1.47331, 1.02548, 1.3496, 1.00004, 0.771304};

  double mean_1_5[n] = {15041.8, 30125.5, 97884.5, 165705, 383147, 301028};
  double mean_er_1_5[n] = {3.363, 7.202, 35.74, 33.92, 18.82, 105};
  double sigma_1_5[n] = {194.464, 253.535, 520.956, 654.795, 1397.57, 1056.08};
  double sigma_er_1_5[n] = {3.3, 6.6, 27.2, 25.7, 19.3, 77.4};
  double res_1_5[n] = {0.};
  double res_erl_1_5[n] = {0.};
  double res_erh_1_5[n] = {0.};
  double res_er_1_5[n] = {0.};
  double chi_1_5[n] = {1.58804, 1.1135, 0.690863, 1.237, 1.56974, 0.851701};

  double mean_2_0[n] = {15035.5, 30088.9, 97766.9, 165486, 232917, 300566};
  double mean_er_2_0[n] = {4.356, 10.83, 12.45, 44.17, 29.02, 61.06};
  double sigma_2_0[n] = {186.102, 282.581, 547.748, 699.66, 1043.8, 1102.99};
  double sigma_er_2_0[n] = {4.7, 10.7, 12.6, 36.8, 33.3, 56.5};
  double res_2_0[n] = {0.};
  double res_erl_2_0[n] = {0.};
  double res_erh_2_0[n] = {0.};
  double res_er_2_0[n] = {0.};
  double chi_2_0[n] = {0.824414, 0.641367, 1.25332, 0.870274, 1.23378, 1.23317};



  for(int i = 0 ; i < n ; i++){

    mean_0_0[i] = mean_0_0[i]*0.5;
    mean_0_5[i] = mean_0_5[i]*0.5;
    mean_1_0[i] = mean_1_0[i]*0.5;
    mean_1_5[i] = mean_1_5[i]*0.5;
    mean_2_0[i] = mean_2_0[i]*0.5;

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

  TCanvas *c1 = new TCanvas("c1", "resolution", 200, 10, 700, 500);
  c1->cd();
  c1->SetGrid();

  TCanvas *c2 = new TCanvas("c2", "resolution each", 200, 10, 1400, 1500);
  c2->Divide(2,3);

  TCanvas *c3 = new TCanvas("c3", "Parameters", 200, 10, 1400, 1000);
  c3->Divide(2,2);  

  TMultiGraph *mg = new TMultiGraph();

  const char *fit_00_name = "sqrt([0]*[0] + ([1]/sqrt(x))*([1]/sqrt(x)) + ([2]/x)*([2]/x))";
  TF1 *fit_00 = new TF1("fit_00", fit_00_name, 0, 10);
  fit_00->SetParName(0, "A");//optional, name
  fit_00->SetParName(1, "B");
  fit_00->SetParName(2, "C");
  fit_00->SetParameter(0, 0.01);//mandatory, start values
  fit_00->SetParameter(1, 0.01);
  fit_00->SetParameter(2, 0.01);
  fit_00->SetParLimits(0, 0, 10);
  fit_00->SetParLimits(1, 0, 10);
  fit_00->SetParLimits(2, 0, 10);


  TGraphErrors *gr_00 = new TGraphErrors(n, energy, res_0_0, er_x, res_er_0_0);
  gr_00->SetTitle("0.0mm");
  gr_00->SetMarkerColor(1);
  gr_00->SetMarkerSize(1);
  gr_00->SetMarkerStyle(24);
  gr_00->Fit("fit_00");
  gr_00->GetFunction("fit_00")->SetLineColor(1);
  gr_00->GetFunction("fit_00")->SetLineWidth(1);
  outfile<<"gap : 0.0mm"<<endl;
  outfile<<"A       : "<<gr_00->GetFunction("fit_00")->GetParameter(0)<<endl;
  outfile<<"A error : "<<gr_00->GetFunction("fit_00")->GetParError(0)<<endl;
  outfile<<"B       : "<<gr_00->GetFunction("fit_00")->GetParameter(1)<<endl;
  outfile<<"B error : "<<gr_00->GetFunction("fit_00")->GetParError(1)<<endl;
  outfile<<"C       : "<<gr_00->GetFunction("fit_00")->GetParameter(2)<<endl;
  outfile<<"C error : "<<gr_00->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_00 = gr_00->GetFunction("fit_00")->GetParameter(0);
  double A_err_00 = gr_00->GetFunction("fit_00")->GetParError(0);
  double B_00 = gr_00->GetFunction("fit_00")->GetParameter(1);
  double B_err_00 = gr_00->GetFunction("fit_00")->GetParError(1);
  double C_00 = gr_00->GetFunction("fit_00")->GetParameter(2);
  double C_err_00 = gr_00->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_00);
  c2->cd(1);
  gr_00->Draw("APE");

  //gr_00->Draw("AP");//A : draw axis

  //  TGraph *gr_05 = new TGraph(n, energy, res_0_5);
  TGraphErrors *gr_05 = new TGraphErrors(n, energy, res_0_5, er_x, res_er_0_5);
  gr_05->SetTitle("0.5mm");
  gr_05->SetMarkerColor(2);
  gr_00->SetMarkerSize(1);
  gr_05->SetMarkerStyle(25);
  gr_05->Fit("fit_00");
  gr_05->GetFunction("fit_00")->SetLineColor(2);
  gr_05->GetFunction("fit_00")->SetLineWidth(1);
  outfile<<"gap : 0.5mm"<<endl;
  outfile<<"A       : "<<gr_05->GetFunction("fit_00")->GetParameter(0)<<endl;
  outfile<<"A error : "<<gr_05->GetFunction("fit_00")->GetParError(0)<<endl;
  outfile<<"B       : "<<gr_05->GetFunction("fit_00")->GetParameter(1)<<endl;
  outfile<<"B error : "<<gr_05->GetFunction("fit_00")->GetParError(1)<<endl;
  outfile<<"C       : "<<gr_05->GetFunction("fit_00")->GetParameter(2)<<endl;
  outfile<<"C error : "<<gr_05->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_05 = gr_05->GetFunction("fit_00")->GetParameter(0);
  double A_err_05 = gr_05->GetFunction("fit_00")->GetParError(0);
  double B_05 = gr_05->GetFunction("fit_00")->GetParameter(1);
  double B_err_05 = gr_05->GetFunction("fit_00")->GetParError(1);
  double C_05 = gr_05->GetFunction("fit_00")->GetParameter(2);
  double C_err_05 = gr_05->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_05);
  c2->cd(2);
  gr_05->Draw("APE");

  //  TGraph *gr_10 = new TGraph(n, energy, res_1_0);

  TGraphErrors *gr_10 = new TGraphErrors(n, energy, res_1_0, er_x, res_er_1_0);
  gr_10->SetTitle("1.0mm");
  gr_10->SetMarkerColor(3);
  gr_10->SetMarkerSize(1);
  gr_10->SetMarkerStyle(4);
  gr_10->Fit("fit_00");
  gr_10->GetFunction("fit_00")->SetLineColor(3);
  gr_10->GetFunction("fit_00")->SetLineWidth(1);
  outfile<<"gap : 1.0mm"<<endl;
  outfile<<"A       : "<<gr_10->GetFunction("fit_00")->GetParameter(0)<<endl;
  outfile<<"A error : "<<gr_10->GetFunction("fit_00")->GetParError(0)<<endl;
  outfile<<"B       : "<<gr_10->GetFunction("fit_00")->GetParameter(1)<<endl;
  outfile<<"B error : "<<gr_10->GetFunction("fit_00")->GetParError(1)<<endl;
  outfile<<"C       : "<<gr_10->GetFunction("fit_00")->GetParameter(2)<<endl;
  outfile<<"C error : "<<gr_10->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_10 = gr_10->GetFunction("fit_00")->GetParameter(0);
  double A_err_10 = gr_10->GetFunction("fit_00")->GetParError(0);
  double B_10 = gr_10->GetFunction("fit_00")->GetParameter(1);
  double B_err_10 = gr_10->GetFunction("fit_00")->GetParError(1);
  double C_10 = gr_10->GetFunction("fit_00")->GetParameter(2);
  double C_err_10 = gr_10->GetFunction("fit_00")->GetParError(2); 
  mg->Add(gr_10);
  c2->cd(3);
  gr_10->Draw("APE");

  //  TGraph *gr_15 = new TGraph(n, energy, res_1_5);
  TGraphErrors *gr_15 = new TGraphErrors(n, energy, res_1_5, er_x, res_er_1_5);
  gr_15->SetTitle("1.5mm");
  gr_15->SetMarkerColor(4);
  gr_15->SetMarkerSize(1);
  gr_15->SetMarkerStyle(26);
  gr_15->Fit("fit_00");
  gr_15->GetFunction("fit_00")->SetLineColor(4);
  gr_15->GetFunction("fit_00")->SetLineWidth(1);
  outfile<<"gap : 1.5mm"<<endl;
  outfile<<"A       : "<<gr_15->GetFunction("fit_00")->GetParameter(0)<<endl;
  outfile<<"A error : "<<gr_15->GetFunction("fit_00")->GetParError(0)<<endl;
  outfile<<"B       : "<<gr_15->GetFunction("fit_00")->GetParameter(1)<<endl;
  outfile<<"B error : "<<gr_15->GetFunction("fit_00")->GetParError(1)<<endl;
  outfile<<"C       : "<<gr_15->GetFunction("fit_00")->GetParameter(2)<<endl;
  outfile<<"C error : "<<gr_15->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_15 = gr_15->GetFunction("fit_00")->GetParameter(0);
  double A_err_15 = gr_15->GetFunction("fit_00")->GetParError(0);
  double B_15 = gr_15->GetFunction("fit_00")->GetParameter(1);
  double B_err_15 = gr_15->GetFunction("fit_00")->GetParError(1);
  double C_15 = gr_15->GetFunction("fit_00")->GetParameter(2);
  double C_err_15 = gr_15->GetFunction("fit_00")->GetParError(2);
  mg->Add(gr_15);
  c2->cd(4);
  gr_15->Draw("APE");

  //  TGraph *gr_20 = new TGraph(n, energy, res_2_0);
  //  TGraphAsymmErrors *gr_20 = new TGraphAsymmErrors(n, energy, er_x, er_x, res_2_0, res_erl_2_0, res_erh_2_0);
  TGraphErrors *gr_20 = new TGraphErrors(n, energy, res_2_0, er_x, res_er_2_0);
  gr_20->SetTitle("Resolution of the NPS depending on the gap btw the crystals");
  gr_20->GetXaxis()->SetTitle("Energy [GeV]");
  gr_20->GetYaxis()->SetTitle("Resolution [%]");
  gr_20->SetMarkerColor(6);
  gr_20->SetMarkerSize(1);
  gr_20->SetMarkerStyle(27);
  gr_20->Fit("fit_00");
  gr_20->GetFunction("fit_00")->SetLineColor(6);
  gr_20->GetFunction("fit_00")->SetLineWidth(1);
  outfile<<"gap : 2.0mm"<<endl;
  outfile<<"A       : "<<gr_20->GetFunction("fit_00")->GetParameter(0)<<endl;
  outfile<<"A error : "<<gr_20->GetFunction("fit_00")->GetParError(0)<<endl;
  outfile<<"B       : "<<gr_20->GetFunction("fit_00")->GetParameter(1)<<endl;
  outfile<<"B error : "<<gr_20->GetFunction("fit_00")->GetParError(1)<<endl;
  outfile<<"C       : "<<gr_20->GetFunction("fit_00")->GetParameter(2)<<endl;
  outfile<<"C error : "<<gr_20->GetFunction("fit_00")->GetParError(2)<<"\n"<<endl;
  double A_20 = gr_20->GetFunction("fit_00")->GetParameter(0);
  double A_err_20 = gr_20->GetFunction("fit_00")->GetParError(0);
  double B_20 = gr_20->GetFunction("fit_00")->GetParameter(1);
  double B_err_20 = gr_20->GetFunction("fit_00")->GetParError(1);
  double C_20 = gr_20->GetFunction("fit_00")->GetParameter(2);
  double C_err_20 = gr_20->GetFunction("fit_00")->GetParError(2);
  c1->cd();
  gr_20->Draw("APE");
  mg->Draw("PE");


  TGraphErrors *gr_20_2 = new TGraphErrors(n, energy, res_2_0, er_x, res_er_2_0);
  gr_20_2->SetTitle("2.0mm");
  gr_20_2->GetXaxis()->SetTitle("Energy [GeV]");
  gr_20_2->GetYaxis()->SetTitle("Resolution [%]");
  gr_20_2->SetMarkerColor(6);
  gr_20_2->SetMarkerSize(1);
  gr_20_2->SetMarkerStyle(27);
  gr_20_2->Fit("fit_00");
  gr_20_2->GetFunction("fit_00")->SetLineColor(6);
  gr_20_2->GetFunction("fit_00")->SetLineWidth(1);
  c2->cd(5);
  gr_20_2->Draw("APE");

  TLegend *leg = new TLegend(0.55, 0.55, .9, .9);
  leg->AddEntry(gr_00, "0.0mm", "p");
  leg->AddEntry(gr_05, "0.5mm", "p");
  leg->AddEntry(gr_10, "1.0mm", "p");
  leg->AddEntry(gr_15, "1.5mm", "p");
  leg->AddEntry(gr_20, "2.0mm", "p");
  c1->cd();
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
  par_A->SetMarkerColor(1);
  par_A->SetMarkerSize(1);
  par_A->SetMarkerStyle(24);
  c3->cd(1);
  par_A->Draw("APE");

  TGraphErrors *par_B = new TGraphErrors(5, gap, B, gap_err, B_err);
  par_B->SetTitle("B");
  par_B->GetXaxis()->SetRangeUser(-3.0,3.0);
  par_B->GetXaxis()->SetTitle("gap [mm]");
  par_B->GetYaxis()->SetTitle("Parameter");
  par_B->SetMarkerColor(2);
  par_B->SetMarkerSize(1);
  par_B->SetMarkerStyle(25);
  c3->cd(2);
  par_B->Draw("APE");

  TGraphErrors *par_C = new TGraphErrors(5, gap, C, gap_err, C_err);
  par_C->SetTitle("C");
  par_C->GetXaxis()->SetRangeUser(-3.0,3.0);
  par_C->GetXaxis()->SetTitle("gap [mm]");
  par_C->GetYaxis()->SetTitle("Parameter");
  par_C->SetMarkerColor(4);
  par_C->SetMarkerSize(1);
  par_C->SetMarkerStyle(26);
  c3->cd(3);
  par_C->Draw("APE");



  c1->Print("output/07022018/resolution/delete.png");
  c2->Print("output/07022018/resolution/delete.png");
  c3->Print("output/07022018/resolution/delete.png");

}
