void draw6(){
    TFile *f = new TFile("/sps/clas/hosanko/NPS/magnetic/01122017/AnaEx02_20171201_mapmagon_1.root");
  //  TFile *f = new TFile("../build/AnaEx02_20171130_mapmagon_1.root");
  double min;
  double max;
  const char *nameon1MeV = "Uniform Magnet on threshold : 1MeV";
  const char *nameon10MeV = "Uniform Magnet on threshold : 10MeV";
  const char *nameon100MeV = "Uniform Magnet on threshold : 100MeV";
  const char *nameoff1MeV = "Uniform Magnet off threshold : 1MeV";
  const char *nameoff10MeV = "Uniform Magnet off threshold : 10MeV";
  const char *nameoff100MeV = "Uniform Magnet off threshold : 100MeV";
  gStyle->SetOptStat(0);
  //  gStyle->SetOptStat(11);
  TCanvas* c1 = new TCanvas("c1","c1",1200,1800);
  c1->Divide(2,3);
  TH1F *h_el_on_1 = new TH1F("electron on 1MeV","",100,-310,310);
  TH1F *h_po_on_1 = new TH1F("positron on 1MeV","",100,-310,310);
  TH1F *h_ga_on_1 = new TH1F("gamma on 1MeV","",100,-310,310);
  TH1F *h_el_on_10 = new TH1F("electron on 10MeV","",100,-310,310);
  TH1F *h_po_on_10 = new TH1F("positron on 10MeV","",100,-310,310);
  TH1F *h_ga_on_10 = new TH1F("gamma on 10MeV","",100,-310,310);
  TH1F *h_el_on_100 = new TH1F("electron on 100MeV","",100,-310,310);
  TH1F *h_po_on_100 = new TH1F("positron on 100MeV","",100,-310,310);
  TH1F *h_ga_on_100 = new TH1F("gamma on 100MeV","",100,-310,310);
  double edep[1116] = {0.};
  int pid[1116] = {0};
  double fluxEnergy = 0.;
  int    fluxPID = 0;
  double posx, posy, posz = 0.;
  double totEdep = 0.;
  double totEdep_el = 0.;
  double totEdep_po = 0.;
  double totEdep_ga = 0.;
  int x, y, i, j;
  TTree *T = (TTree*)f->Get("t2");
  T->SetBranchAddress("fluxEnergy",&fluxEnergy);
  T->SetBranchAddress("fluxPID",&fluxPID);
  T->SetBranchAddress("x",&posx);
  T->SetBranchAddress("y",&posy);
  T->SetBranchAddress("z",&posz);
  int nentries2 = T->GetEntries();
  int el,po,ga = 0;
  for(int thresh = 0 ; thresh < 101 ; thresh++){
    if(thresh == 1){
      min = 0.01;
      max = 300.;
      //     const char *name =  "Uniform Magnet on threshold : 1MeV";
      for(i = 0 ; i < nentries2 ; i++){
	//    if(posx!=0)  cout<<"posx: "<<posx<<endl;
	//    if(fluxPID!=0)    cout<<"pid : "<<fluxPID<<endl;
	T->GetEntry(i);
	if(fluxEnergy!=0){
	  if(fluxPID == 11 && fluxEnergy > 1. ) {h_el_on_1 -> Fill(posx); el++;}
	  if(fluxPID == -11 && fluxEnergy > 1.) {h_po_on_1 -> Fill(posx); po++;}
	  if(fluxPID == 22 && fluxEnergy > 1. ) {h_ga_on_1 -> Fill(posx); ga++;}
	}
      }
      cout<<"el : "<<el<<endl;
      cout<<"po : "<<po<<endl;
      cout<<"ga : "<<ga<<endl;
      c1->cd(5);

      gPad->SetGridx();
      gPad->SetGridy();
      gPad->Modified();
      h_el_on_1->SetMarkerStyle(kOpenSquare);
      h_el_on_1->SetMarkerColor(2);  
      h_el_on_1->SetLineColor(2);
      h_po_on_1->SetMarkerStyle(kOpenTriangleUp);
      h_po_on_1->SetMarkerColor(8);  
      h_po_on_1->SetLineColor(8);
      h_ga_on_1->SetMarkerStyle(kOpenCircle);
      h_ga_on_1->SetMarkerColor(1);  
      h_ga_on_1->SetLineColor(1);
  

      if(ga >= el && ga >= po){
	h_ga_on_1->SetTitle(nameon1MeV);
	h_ga_on_1->SetMinimum(min);
	h_ga_on_1->SetMaximum(max);
	gPad->SetLogy();
	h_ga_on_1->Draw("LPE1");
	h_el_on_1->Draw("LPE1SAME");
	h_po_on_1->Draw("LPE1SAME");
      }
      if(el >= ga && el >= po){
	h_el_on_1->SetTitle(nameon1MeV);
	h_el_on_1->SetMinimum(min);
	h_el_on_1->SetMaximum(max);
	gPad->SetLogy();
	h_el_on_1->Draw("LPE1");
	h_po_on_1->Draw("LPE1SAME");
	h_ga_on_1->Draw("LPE1SAME");
      }
      if(po >= el && po >= ga){
	h_po_on_1->SetTitle(nameon1MeV);
	h_po_on_1->SetMinimum(min);
	h_po_on_1->SetMaximum(max);
	gPad->SetLogy();
	h_po_on_1->Draw("LPE1");
	h_el_on_1->Draw("LPE1SAME");
	h_ga_on_1->Draw("LPE1SAME");
      }
    }
    if(thresh == 10){
      el = 0;
      po = 0;
      ga = 0;
      min = 0.01;
      max = 200.;
      //     const char *name =  "Uniform Magnet on threshold : 1MeV";
      for(i = 0 ; i < nentries2 ; i++){
	//    if(posx!=0)  cout<<"posx: "<<posx<<endl;
	//    if(fluxPID!=0)    cout<<"pid : "<<fluxPID<<endl;
	T->GetEntry(i);
	if(fluxEnergy!=0){
	  if(fluxPID == 11 && fluxEnergy > 10. ) {h_el_on_10 -> Fill(posx); el++;}
	  if(fluxPID == -11 && fluxEnergy > 10.) {h_po_on_10 -> Fill(posx); po++;}
	  if(fluxPID == 22 && fluxEnergy > 10. ) {h_ga_on_10 -> Fill(posx); ga++;}
	}
      }
      cout<<"el : "<<el<<endl;
      cout<<"po : "<<po<<endl;
      cout<<"ga : "<<ga<<endl;
      c1->cd(3);

      gPad->SetGridx();
      gPad->SetGridy();
      gPad->Modified();
      h_el_on_10->SetMarkerStyle(kOpenSquare);
      h_el_on_10->SetMarkerColor(2);  
      h_el_on_10->SetLineColor(2);
      h_po_on_10->SetMarkerStyle(kOpenTriangleUp);
      h_po_on_10->SetMarkerColor(8);  
      h_po_on_10->SetLineColor(8);
      h_ga_on_10->SetMarkerStyle(kOpenCircle);
      h_ga_on_10->SetMarkerColor(1);  
      h_ga_on_10->SetLineColor(1);
  

      if(ga >= el && ga >= po){
	h_ga_on_10->SetTitle(nameon10MeV);
	h_ga_on_10->SetMinimum(min);
	h_ga_on_10->SetMaximum(max);
	gPad->SetLogy();
	h_ga_on_10->Draw("LPE1");
	h_el_on_10->Draw("LPE1SAME");
	h_po_on_10->Draw("LPE1SAME");
      }
      if(el >= ga && el >= po){
	h_el_on_10->SetTitle(nameon10MeV);
	h_el_on_10->SetMinimum(min);
	h_el_on_10->SetMaximum(max);
	gPad->SetLogy();
	h_el_on_10->Draw("LPE1");
	h_po_on_10->Draw("LPE1SAME");
	h_ga_on_10->Draw("LPE1SAME");
      }
      if(po >= el && po >= ga){
	h_po_on_10->SetTitle(nameon10MeV);
	h_po_on_10->SetMinimum(min);
	h_po_on_10->SetMaximum(max);
	gPad->SetLogy();
	h_po_on_10->Draw("LPE1");
	h_el_on_10->Draw("LPE1SAME");
	h_ga_on_10->Draw("LPE1SAME");
      }
    }
    if(thresh == 100){
      el = 0;
      po = 0;
      ga = 0;
      min = 0.01;
      max = 10.;
      //     const char *name =  "Uniform Magnet on threshold : 1MeV";
      for(i = 0 ; i < nentries2 ; i++){
	//    if(posx!=0)  cout<<"posx: "<<posx<<endl;
	//    if(fluxPID!=0)    cout<<"pid : "<<fluxPID<<endl;
	T->GetEntry(i);
	if(fluxEnergy!=0){
	  if(fluxPID == 11 && fluxEnergy > 100. ) {h_el_on_100 -> Fill(posx); el++;}
	  if(fluxPID == -11 && fluxEnergy > 100.) {h_po_on_100 -> Fill(posx); po++;}
	  if(fluxPID == 22 && fluxEnergy > 100. ) {h_ga_on_100 -> Fill(posx); ga++;}
	}
      }
      cout<<"el : "<<el<<endl;
      cout<<"po : "<<po<<endl;
      cout<<"ga : "<<ga<<endl;
      c1->cd(1);

      gPad->SetGridx();
      gPad->SetGridy();
      gPad->Modified();
      h_el_on_100->SetMarkerStyle(kOpenSquare);
      h_el_on_100->SetMarkerColor(2);  
      h_el_on_100->SetLineColor(2);
      h_po_on_100->SetMarkerStyle(kOpenTriangleUp);
      h_po_on_100->SetMarkerColor(8);  
      h_po_on_100->SetLineColor(8);
      h_ga_on_100->SetMarkerStyle(kOpenCircle);
      h_ga_on_100->SetMarkerColor(1);  
      h_ga_on_100->SetLineColor(1);
  

      if(ga >= el && ga >= po){
	h_ga_on_100->SetTitle(nameon100MeV);
	h_ga_on_100->SetMinimum(min);
	h_ga_on_100->SetMaximum(max);
	gPad->SetLogy();
	h_ga_on_100->Draw("LPE1");
	h_el_on_100->Draw("LPE1SAME");
	h_po_on_100->Draw("LPE1SAME");
      }
      if(el >= ga && el >= po){
	h_el_on_100->SetTitle(nameon100MeV);
	h_el_on_100->SetMinimum(min);
	h_el_on_100->SetMaximum(max);
	gPad->SetLogy();
	h_el_on_100->Draw("LPE1");
	h_po_on_100->Draw("LPE1SAME");
	h_ga_on_100->Draw("LPE1SAME");
      }
      if(po >= el && po >= ga){
	h_po_on_100->SetTitle(nameon100MeV);
	h_po_on_100->SetMinimum(min);
	h_po_on_100->SetMaximum(max);
	gPad->SetLogy();
	h_po_on_100->Draw("LPE1");
	h_el_on_100->Draw("LPE1fileSAME");
	h_ga_on_100->Draw("LPE1SAME");
      }
    }
  }

  TLegend *pl = new TLegend(0.8,0.8,0.99,0.99);//x1,x1,y1,y1
  pl->SetTextSize(0.04); 
  pl->SetFillColor(0);
  TLegendEntry *ple = pl->AddEntry(h_el_on_1, "electrons",  "el");
  TLegendEntry *ple = pl->AddEntry(h_po_on_1, "positrons",  "po");
  TLegendEntry *ple = pl->AddEntry(h_ga_on_1, "gammas",  "ga");
  ple->SetMarkerSize(1.);
  pl->Draw();
  //  c1->Print("output/unimagon_3_threshold_1MeV.pdf");

  ///////////////////////////////////////////////////////////////////


  TFile *f2 = new TFile("/sps/clas/hosanko/NPS/magnetic/01122017/AnaEx02_20171201_mapmagoff_1.root");

  TH1F *h_el_off_1 = new TH1F("electron off 1MeV","",100,-310,310);
  TH1F *h_po_off_1 = new TH1F("positron off 1MeV","",100,-310,310);
  TH1F *h_ga_off_1 = new TH1F("gamma off 1MeV","",100,-310,310);
  TH1F *h_el_off_10 = new TH1F("electron off 10MeV","",100,-310,310);
  TH1F *h_po_off_10 = new TH1F("positron off 10MeV","",100,-310,310);
  TH1F *h_ga_off_10 = new TH1F("gamma off 10MeV","",100,-310,310);
  TH1F *h_el_off_100 = new TH1F("electron off 100MeV","",100,-310,310);
  TH1F *h_po_off_100 = new TH1F("positron off 100MeV","",100,-310,310);
  TH1F *h_ga_off_100 = new TH1F("gamma off 100MeV","",100,-310,310);

  TTree *T2 = (TTree*)f2->Get("t2");
  T2->SetBranchAddress("fluxEnergy",&fluxEnergy);
  T2->SetBranchAddress("fluxPID",&fluxPID);
  T2->SetBranchAddress("x",&posx);
  T2->SetBranchAddress("y",&posy);
  T2->SetBranchAddress("z",&posz);

  for(int thresh = 0 ; thresh < 101 ; thresh++){
    if(thresh == 1){
      el = 0;
      po = 0;
      ga = 0;
      min = 0.01;
      max = 300.;
      //     const char *name =  "Uniform Magnet on threshold : 1MeV";
      for(i = 0 ; i < nentries2 ; i++){
	//    if(posx!=0)  cout<<"posx: "<<posx<<endl;
	//    if(fluxPID!=0)    cout<<"pid : "<<fluxPID<<endl;
	T2->GetEntry(i);
	if(fluxEnergy!=0){
	  if(fluxPID == 11 && fluxEnergy > 1. ) {h_el_off_1 -> Fill(posx); el++;}
	  if(fluxPID == -11 && fluxEnergy > 1.) {h_po_off_1 -> Fill(posx); po++;}
	  if(fluxPID == 22 && fluxEnergy > 1. ) {h_ga_off_1 -> Fill(posx); ga++;}
	}
      }
      cout<<"el : "<<el<<endl;
      cout<<"po : "<<po<<endl;
      cout<<"ga : "<<ga<<endl;
      c1->cd(6);

      gPad->SetGridx();
      gPad->SetGridy();
      gPad->Modified();
      h_el_off_1->SetMarkerStyle(kOpenSquare);
      h_el_off_1->SetMarkerColor(2);  
      h_el_off_1->SetLineColor(2);
      h_po_off_1->SetMarkerStyle(kOpenTriangleUp);
      h_po_off_1->SetMarkerColor(8);  
      h_po_off_1->SetLineColor(8);
      h_ga_off_1->SetMarkerStyle(kOpenCircle);
      h_ga_off_1->SetMarkerColor(1);  
      h_ga_off_1->SetLineColor(1);
  

      if(ga >= el && ga >= po){
	h_ga_off_1->SetTitle(nameoff1MeV);
	h_ga_off_1->SetMinimum(min);
	h_ga_off_1->SetMaximum(max);
	gPad->SetLogy();
	h_ga_off_1->Draw("LPE1");
	h_el_off_1->Draw("LPE1SAME");
	h_po_off_1->Draw("LPE1SAME");
      }
      if(el >= ga && el >= po){
	h_el_off_1->SetTitle(nameoff1MeV);
	h_el_off_1->SetMinimum(min);
	h_el_off_1->SetMaximum(max);
	gPad->SetLogy();
	h_el_off_1->Draw("LPE1");
	h_po_off_1->Draw("LPE1SAME");
	h_ga_off_1->Draw("LPE1SAME");
      }
      if(po >= el && po >= ga){
	h_po_off_1->SetTitle(nameoff1MeV);
	h_po_off_1->SetMinimum(min);
	h_po_off_1->SetMaximum(max);
	gPad->SetLogy();
	h_po_off_1->Draw("LPE1");
	h_el_off_1->Draw("LPE1SAME");
	h_ga_off_1->Draw("LPE1SAME");
      }
    }
    if(thresh == 10){
      el = 0;
      po = 0;
      ga = 0;
      min = 0.01;
      max = 200.;
      //     const char *name =  "Uniform Magnet on threshold : 1MeV";
      for(i = 0 ; i < nentries2 ; i++){
	//    if(posx!=0)  cout<<"posx: "<<posx<<endl;
	//    if(fluxPID!=0)    cout<<"pid : "<<fluxPID<<endl;
	T2->GetEntry(i);
	if(fluxEnergy!=0){
	  if(fluxPID == 11 && fluxEnergy > 10. ) {h_el_off_10 -> Fill(posx); el++;}
	  if(fluxPID == -11 && fluxEnergy > 10.) {h_po_off_10 -> Fill(posx); po++;}
	  if(fluxPID == 22 && fluxEnergy > 10. ) {h_ga_off_10 -> Fill(posx); ga++;}
	}
      }
      cout<<"el : "<<el<<endl;
      cout<<"po : "<<po<<endl;
      cout<<"ga : "<<ga<<endl;
      c1->cd(4);

      gPad->SetGridx();
      gPad->SetGridy();
      gPad->Modified();
      h_el_off_10->SetMarkerStyle(kOpenSquare);
      h_el_off_10->SetMarkerColor(2);  
      h_el_off_10->SetLineColor(2);
      h_po_off_10->SetMarkerStyle(kOpenTriangleUp);
      h_po_off_10->SetMarkerColor(8);  
      h_po_off_10->SetLineColor(8);
      h_ga_off_10->SetMarkerStyle(kOpenCircle);
      h_ga_off_10->SetMarkerColor(1);  
      h_ga_off_10->SetLineColor(1);
  

      if(ga >= el && ga >= po){
	h_ga_off_10->SetTitle(nameoff10MeV);
	h_ga_off_10->SetMinimum(min);
	h_ga_off_10->SetMaximum(max);
	gPad->SetLogy();
	h_ga_off_10->Draw("LPE1");
	h_el_off_10->Draw("LPE1SAME");
	h_po_off_10->Draw("LPE1SAME");
      }
      if(el >= ga && el >= po){
	h_el_off_10->SetTitle(nameoff10MeV);
	h_el_off_10->SetMinimum(min);
	h_el_off_10->SetMaximum(max);
	gPad->SetLogy();
	h_el_off_10->Draw("LPE1");
	h_po_off_10->Draw("LPE1SAME");
	h_ga_off_10->Draw("LPE1SAME");
      }
      if(po >= el && po >= ga){
	h_po_off_10->SetTitle(nameoff10MeV);
	h_po_off_10->SetMinimum(min);
	h_po_off_10->SetMaximum(max);
	gPad->SetLogy();
	h_po_off_10->Draw("LPE1");
	h_el_off_10->Draw("LPE1SAME");
	h_ga_off_10->Draw("LPE1SAME");
      }
    }
    if(thresh == 100){
      el = 0;
      po = 0;
      ga = 0;
      min = 0.01;
      max = 10.;
      //     const char *name =  "Uniform Magnet on threshold : 1MeV";
      for(i = 0 ; i < nentries2 ; i++){
	//    if(posx!=0)  cout<<"posx: "<<posx<<endl;
	//    if(fluxPID!=0)    cout<<"pid : "<<fluxPID<<endl;
	T2->GetEntry(i);
	if(fluxEnergy!=0){
	  if(fluxPID == 11 && fluxEnergy > 100. ) {h_el_off_100 -> Fill(posx); el++;}
	  if(fluxPID == -11 && fluxEnergy > 100.) {h_po_off_100 -> Fill(posx); po++;}
	  if(fluxPID == 22 && fluxEnergy > 100. ) {h_ga_off_100 -> Fill(posx); ga++;}
	}
      }
      cout<<"el : "<<el<<endl;
      cout<<"po : "<<po<<endl;
      cout<<"ga : "<<ga<<endl;
      c1->cd(2);

      gPad->SetGridx();
      gPad->SetGridy();
      gPad->Modified();
      h_el_off_100->SetMarkerStyle(kOpenSquare);
      h_el_off_100->SetMarkerColor(2);  
      h_el_off_100->SetLineColor(2);
      h_po_off_100->SetMarkerStyle(kOpenTriangleUp);
      h_po_off_100->SetMarkerColor(8);  
      h_po_off_100->SetLineColor(8);
      h_ga_off_100->SetMarkerStyle(kOpenCircle);
      h_ga_off_100->SetMarkerColor(1);  
      h_ga_off_100->SetLineColor(1);
  

      if(ga >= el && ga >= po){
	h_ga_off_100->SetTitle(nameoff100MeV);
	h_ga_off_100->SetMinimum(min);
	h_ga_off_100->SetMaximum(max);
	gPad->SetLogy();
	h_ga_off_100->Draw("LPE1");
	h_el_off_100->Draw("LPE1SAME");
	h_po_off_100->Draw("LPE1SAME");
      }
      if(el >= ga && el >= po){
	h_el_off_100->SetTitle(nameoff100MeV);
	h_el_off_100->SetMinimum(min);
	h_el_off_100->SetMaximum(max);
	gPad->SetLogy();
	h_el_off_100->Draw("LPE1");
	h_po_off_100->Draw("LPE1SAME");
	h_ga_off_100->Draw("LPE1SAME");
      }
      if(po >= el && po >= ga){
	h_po_off_100->SetTitle(nameoff100MeV);
	h_po_off_100->SetMinimum(min);
	h_po_off_100->SetMaximum(max);
	gPad->SetLogy();
	h_po_off_100->Draw("LPE1");
	h_el_off_100->Draw("LPE1SAME");
	h_ga_off_100->Draw("LPE1SAME");
      }
    }
  }

  TLegend *pl = new TLegend(0.8,0.8,0.99,0.99);//x1,x1,y1,y1
  pl->SetTextSize(0.04); 
  pl->SetFillColor(0);
  TLegendEntry *ple = pl->AddEntry(h_el_off_1, "electrons",  "el");
  TLegendEntry *ple = pl->AddEntry(h_po_off_1, "positrons",  "po");
  TLegendEntry *ple = pl->AddEntry(h_ga_off_1, "gammas",  "ga");
  ple->SetMarkerSize(1.);
  pl->Draw();
  c1->Print("output/fieldmap_20171201.pdf");
  //  f->Close();
  //  f2->Close();

}
