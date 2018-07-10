void draw(){

  /* int i = 3; */
  TCanvas *c1 = new TCanvas("c1", "c1", 200, 10, 1400, 1000);
  TCanvas *c2 = new TCanvas("c2", "c2", 200, 10, 1400, 1000);
  TCanvas *c3 = new TCanvas("c3", "c3", 200, 10, 700,   500);
  c1->Divide(3,3);
  c2->Divide(3,3);
  TH2F *h = new TH2F("h","dose rate",3,0,6,3,0,6);
  for(int i = 1 ; i < 10 ; i++){
    //  int i = 0;
    /* i = i + 1; */
    if     (i == 1) c1->cd(7);
    else if(i == 2) c1->cd(4);
    else if(i == 3) c1->cd(1);
    else if(i == 4) c1->cd(8);
    else if(i == 5) c1->cd(5);
    else if(i == 6) c1->cd(2);
    else if(i == 7) c1->cd(9);
    else if(i == 8) c1->cd(6);
    else if(i == 9) c1->cd(3);    
    ostringstream str;
    str << i;
    string pos = str.str();
    
    string front = "../converted/pos";
    string back_2_5min = "_2.5min.dat";
    string back_5min = "_5min.dat";
    string back_7_5min = "_7.5min.dat";
    string back_10min = "_10min.dat";
    string back_12_5min = "_12.5min.dat";
    string output_front1 = "output/";
    string output_front2 = "pos";
    string output_front = output_front1 + output_front2;
    string output_back = "_with_2_points.eps";
    /* string output_back = ".png"; */

    string slope = "slope";
    
    string comb_2_5min = front + pos + back_2_5min;
    string comb_5min = front + pos + back_5min;
    string comb_7_5min = front + pos + back_7_5min;
    string comb_10min = front + pos + back_10min;
    string comb_12_5min = front + pos + back_12_5min;

    string out_name = output_front2 + " " +  pos /*+ " absorption corrected4"*/;
    string out = output_front + pos /*+ "_corrected4"*/ + output_back;

    string slop_name = slope + " " + pos /*+ " absorption corrected4"*/;
    string slope_out = output_front1 + slope + pos /*+ "_corrected4"*/ + output_back;

    const char* _default = "../converted/default.dat";
    
    const char* pos1_2_5min = comb_2_5min.c_str();
    const char* pos1_5min = comb_5min.c_str();
    const char* pos1_7_5min = comb_7_5min.c_str();
    const char* pos1_10min = comb_10min.c_str();
    const char* pos1_12_5min = comb_12_5min.c_str();

    const char* output_name = out_name.c_str();
    const char* output_file = out.c_str();

    const char* slope_name = slop_name.c_str();
    const char* slope_file = slope_out.c_str();
    
    double wavelength_db, abs_db;
    vector<double> wavelength1_default, abs1_default;
    vector<double> wavelength1_2_5min, abs1_2_5min;
    vector<double> wavelength1_5min, abs1_5min;
    vector<double> wavelength1_7_5min, abs1_7_5min;
    vector<double> wavelength1_10min, abs1_10min;
    vector<double> wavelength1_12_5min, abs1_12_5min;

    double abs_corrected;
    vector<double> abs1_default_corrected;    
    vector<double> abs1_2_5min_corrected;
    vector<double> abs1_5min_corrected;
    vector<double> abs1_7_5min_corrected;
    vector<double> abs1_10min_corrected;
    vector<double> abs1_12_5min_corrected;

    ifstream my1_default;
    my1_default.open(_default);
    while(my1_default>>wavelength_db>>abs_db){
      wavelength1_default.push_back(wavelength_db);
      abs1_default.push_back(abs_db);
      if(wavelength_db == 500) abs_corrected = abs_db;
    }
    my1_default.close();
    my1_default.open(_default);
    while(my1_default>>wavelength_db>>abs_db){
      abs1_default_corrected.push_back(abs_db - abs_corrected);
    }
    my1_default.close();
  
    ifstream my1_2_5min;
    my1_2_5min.open(pos1_2_5min);
    while(my1_2_5min>>wavelength_db>>abs_db){
      wavelength1_2_5min.push_back(wavelength_db);
      abs1_2_5min.push_back(abs_db);
      if(wavelength_db == 500) abs_corrected = abs_db;
    }
    my1_2_5min.close();
    my1_2_5min.open(pos1_2_5min);
   while(my1_2_5min>>wavelength_db>>abs_db){
      abs1_2_5min_corrected.push_back(abs_db - abs_corrected);
    }
    my1_2_5min.close();

    ifstream my1_5min;
    my1_5min.open(pos1_5min);
    while(my1_5min>>wavelength_db>>abs_db){
      wavelength1_5min.push_back(wavelength_db);
      abs1_5min.push_back(abs_db);
      if(wavelength_db == 500) abs_corrected = abs_db;
    }
    my1_5min.close();
    my1_5min.open(pos1_5min);
    while(my1_5min>>wavelength_db>>abs_db){
      abs1_5min_corrected.push_back(abs_db - abs_corrected);
    }
    my1_5min.close();

    ifstream my1_7_5min;
    my1_7_5min.open(pos1_7_5min);
    while(my1_7_5min>>wavelength_db>>abs_db){
      wavelength1_7_5min.push_back(wavelength_db);
      abs1_7_5min.push_back(abs_db);
      if(wavelength_db == 500) abs_corrected = abs_db;
    }
    my1_7_5min.close();
    my1_7_5min.open(pos1_7_5min);
    while(my1_7_5min>>wavelength_db>>abs_db){
      abs1_7_5min_corrected.push_back(abs_db - abs_corrected);
      /* cout<<abs_corrected<<endl; */
    }
    my1_7_5min.close();

    ifstream my1_10min;
    my1_10min.open(pos1_10min);
    while(my1_10min>>wavelength_db>>abs_db){
      wavelength1_10min.push_back(wavelength_db);
      abs1_10min.push_back(abs_db);
      if(wavelength_db == 500) abs_corrected = abs_db;
    }
    my1_10min.close();
    my1_10min.open(pos1_10min);
    while(my1_10min>>wavelength_db>>abs_db){
      abs1_10min_corrected.push_back(abs_db - abs_corrected);
      /* cout<<abs_corrected<<endl; */
    }
    my1_10min.close();

    ifstream my1_12_5min;
    my1_12_5min.open(pos1_12_5min);
    while(my1_12_5min>>wavelength_db>>abs_db){
      wavelength1_12_5min.push_back(wavelength_db);
      abs1_12_5min.push_back(abs_db);
      if(wavelength_db == 500) abs_corrected = abs_db;
    }
    my1_12_5min.close();
    my1_12_5min.open(pos1_12_5min);
    while(my1_12_5min>>wavelength_db>>abs_db){
      abs1_12_5min_corrected.push_back(abs_db - abs_corrected);
      /* cout<<abs_corrected<<endl; */
    }
    my1_12_5min.close();

    //    TCanvas *c1 = new TCanvas("c1", "c1", 200, 10, 700, 500);
    //    c1->cd();
    
    TMultiGraph *mg = new TMultiGraph();

    TGraph *gr1_default = new TGraph(wavelength1_default.size(), &wavelength1_default[0], &abs1_default/*_corrected*/[0]);
    gr1_default->SetTitle("");
    gr1_default->SetLineColor(1);
    gr1_default->SetMarkerColor(1);
    gr1_default->SetMarkerStyle(1);
    mg->Add(gr1_default);

    TGraph *gr1_2_5min = new TGraph(wavelength1_2_5min.size(), &wavelength1_2_5min[0], &abs1_2_5min/*_corrected*/[0]);
    gr1_2_5min->SetTitle("");
    gr1_2_5min->SetLineColor(3);
    gr1_2_5min->SetMarkerColor(3);
    gr1_2_5min->SetMarkerStyle(1);
    mg->Add(gr1_2_5min);

    TGraph *gr1_5min = new TGraph(wavelength1_5min.size(), &wavelength1_5min[0], &abs1_5min/*_corrected*/[0]);
    gr1_5min->SetTitle("");
    gr1_5min->SetLineColor(2);
    gr1_5min->SetMarkerColor(2);
    gr1_5min->SetMarkerStyle(1);
    mg->Add(gr1_5min);

    TGraph *gr1_7_5min = new TGraph(wavelength1_7_5min.size(), &wavelength1_7_5min[0], &abs1_7_5min/*_corrected*/[0]);
    //    gr1_7_5min->GetXaxis()->SetLimits(190, 1000);
    //    gr1_7_5min->GetYaxis()->SetRangeUser(-0.05, 0.8);
    /* gr1_7_5min->GetXaxis()->SetLimits(190, 500); */
    /* gr1_7_5min->GetYaxis()->SetRangeUser(0, 0.8); */
    /* gr1_7_5min->SetTitle(output_name); */
    /* gr1_7_5min->GetYaxis()->SetTitle("absorption [AU]"); */
    /* gr1_7_5min->GetXaxis()->SetTitle("wavelength [nm]"); */
    gr1_7_5min->SetTitle("");
    gr1_7_5min->SetLineColor(6);
    gr1_7_5min->SetMarkerColor(6);
    gr1_7_5min->SetMarkerStyle(1);
    mg->Add(gr1_7_5min);

    TGraph *gr1_10min = new TGraph(wavelength1_10min.size(), &wavelength1_10min[0], &abs1_10min/*_corrected*/[0]);
    gr1_10min->SetTitle("");
    gr1_10min->SetLineColor(7);
    gr1_10min->SetMarkerColor(7);
    gr1_10min->SetMarkerStyle(1);
    mg->Add(gr1_10min);

    TGraph *gr1_12_5min = new TGraph(wavelength1_12_5min.size(), &wavelength1_12_5min[0], &abs1_12_5min/*_corrected*/[0]);
    //    gr1_12_5min->GetXaxis()->SetLimits(190, 1000);
    //    gr1_12_5min->GetYaxis()->SetRangeUser(-0.05, 0.8);
    gr1_12_5min->GetXaxis()->SetLimits(190, 500);
    gr1_12_5min->GetYaxis()->SetRangeUser(0, 0.8);
    gr1_12_5min->SetTitle(output_name);
    gr1_12_5min->GetYaxis()->SetTitle("absorption [AU]");
    gr1_12_5min->GetXaxis()->SetTitle("wavelength [nm]");
    gr1_12_5min->SetLineColor(9);
    gr1_12_5min->SetMarkerColor(9);
    gr1_12_5min->SetMarkerStyle(1);
    gr1_12_5min->Draw("APL");
    mg->Draw("PL");

    TLegend *leg = new TLegend(0.45, 0.45, .9, .9);
    leg->AddEntry(gr1_default, "default", "l");
    leg->AddEntry(gr1_2_5min, "2.5min", "l");
    leg->AddEntry(gr1_5min, "5min", "l");
    leg->AddEntry(gr1_7_5min, "7.5min", "l");
    leg->AddEntry(gr1_10min, "10min", "l");
    leg->AddEntry(gr1_12_5min, "12.5min", "l");
    leg->Draw();

    //    TLine *line_0 = new TLine(190,0,1000,0);//(x1, y1, x2, y2)
    //    line_0->SetLineColor(4);//bleu
    //    line_0->SetLineWidth(2);
    //    line_0->SetLineStyle(4);//dotted line
    //    line_0->Draw("");//no need to say "SAME"
    
    //    c1->Print(output_file);
    //    c1->Close();

    //getting the absorption value from 304nm wavelength
    double epsilon = 2204;
    double I  = 1;
    double rho = 1.024;
    double G = 0.00000162;

    vector<double> absorbance;
    vector<double> time;

    time.push_back(0);    
    time.push_back(2.5);
    time.push_back(5);
    time.push_back(7.5);
    time.push_back(10);
    time.push_back(12.5);
    absorbance.push_back(abs1_default/*_corrected*/[114]);
    absorbance.push_back(abs1_2_5min/*_corrected*/[114]);
    absorbance.push_back(abs1_5min/*_corrected*/[114]);
    absorbance.push_back(abs1_7_5min/*_corrected*/[114]);
    absorbance.push_back(abs1_10min/*_corrected*/[114]);
    absorbance.push_back(abs1_12_5min/*_corrected*/[114]);

    if     (i == 1) c2->cd(7);
    else if(i == 2) c2->cd(4);
    else if(i == 3) c2->cd(1);
    else if(i == 4) c2->cd(8);
    else if(i == 5) c2->cd(5);
    else if(i == 6) c2->cd(2);
    else if(i == 7) c2->cd(9);
    else if(i == 8) c2->cd(6);
    else if(i == 9) c2->cd(3);

    //    TCanvas *c2 = new TCanvas("c2", "c2", 200, 10, 700, 500);
    
    gStyle->SetOptFit(111111);
    TGraph *gr_slope = new TGraph(time.size(), &time[0], &absorbance[0]);
    gr_slope->GetXaxis()->SetLimits(0,80);
    gr_slope->GetYaxis()->SetRangeUser(0,0.4);
    gr_slope->SetTitle(slope_name);
    gr_slope->GetYaxis()->SetTitle("absorption [AU]");
    gr_slope->GetXaxis()->SetTitle("wavelength [nm]");
    gr_slope->SetLineColor(2);
    gr_slope->SetMarkerColor(2);
    gr_slope->SetMarkerStyle(2);
    gr_slope->SetMarkerSize(2);
    //    gr_slope->Fit("pol1", "F");
    gr_slope->Fit("pol1", "", "", 0, 2.5);
    TF1 *f = gr_slope->GetFunction("pol1");
    f->SetRange(0, 12.5);
    f->SetLineColor(2);
    f->SetLineWidth(1);
    gr_slope->Draw("AP");
    //    c2->Print(slope_file);
    //    c2->Close();
    ofstream dose("output/slope.txt", ios::app);
    if(i == 1){
      dose <<"epsilon : "<<epsilon<<"\n"
    	   <<"I : "      <<I<<"\n"
    	   <<"rho : "    <<rho<<"\n"
    	   <<"G : "      <<G<<"\n"<<endl;

      dose<<"position : "<<pos<<"\n"
    	  <<"slope : "<<gr_slope->GetFunction("pol1")->GetParameter(1)<<"\n"
    	  <<"dose : "<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<"\n"<<endl;
    }
    else{
      dose<<"position : "<<pos<<"\n"
    	  <<"slope : "<<gr_slope->GetFunction("pol1")->GetParameter(1)<<"\n"
    	  <<"dose : "<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<"\n"<<endl;
    }

    if     (i == 1) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(1,1,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 2) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(1,3,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 3) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(1,5,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 4) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(3,1,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 5) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(3,3,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 6) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(3,5,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 7) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(5,1,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 8) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(5,3,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}
    else if(i == 9) {cout<<(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G)<<endl;h->Fill(5,5,(gr_slope->GetFunction("pol1")->GetParameter(1))/(epsilon*I*rho*G));}

  }
  c1->Print(output_file);
  c1->Close();
  c2->Print(slope_file);
  c2->Close();
  c3->cd();
  gStyle->SetOptStat(0);
  h->Draw("colztext");

  c3->Print("output/dose_with_2_points.eps");
}
