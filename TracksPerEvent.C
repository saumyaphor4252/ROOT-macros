void TracksPerEvent()
{
  gStyle->SetOptStat(0);
   
  TFile *file1 = new TFile("CTF_2018.root");
  TFile *file2 = new TFile("CosmicTF_2018.root");
  TFile *file3 = new TFile("Regional_2018.root");
   
  Int_t ci;      // for color index setting
  TColor *color; // for color definition with alpha
 
  TCanvas c("c","c",800,600);    // Declare canvas
  c.SetFillColor(0);
  c.SetBorderMode(0);
  c.SetBorderSize(3);
  c.SetTickx(1);
  c.SetTicky(1);
  c.SetGrid();
  c.SetRightMargin(0.04193254);
  c.SetTopMargin(0.08736718);
  c.SetBottomMargin(0.08854782);
  c.SetFrameBorderMode(0);
  
  TTree *tree1;
  TTree *tree2;
  TTree *tree3;

  tree1 = (TTree*)file1->Get("cosmicRateAnalyzer/Event");
  tree2 = (TTree*)file2->Get("cosmicRateAnalyzer/Event");
  tree3 = (TTree*)file3->Get("cosmicRateAnalyzer/Event");  

  int ntrk1=500,ntrk2=500,ntrk3=500,trk1=0,trk2=0,trk3=0;
  tree1->SetBranchAddress("ntrk", &ntrk1);
  tree2->SetBranchAddress("ntrk", &ntrk2);
  tree3->SetBranchAddress("ntrk", &ntrk3);
  
  TH1D h1 		("h1","h1",10,0,10);
  TH1D h2       	("h2","h2",10,0,10);
  TH1D h3 		("h3","h3",10,0,10);
  
  Long64_t n = tree1->GetEntriesFast();     
  for (Long64_t jentry=0; jentry<n; jentry++) //Event Loop
  {
    tree1->GetEntry(jentry);  // Get 
    h1.Fill(ntrk1);
    trk1=trk1+ntrk1;
    tree2->GetEntry(jentry);
    h2.Fill(ntrk2);
    trk2=trk2+ntrk2;
    tree3->GetEntry(jentry);
    h3.Fill(ntrk3);
    trk3=trk3+ntrk3;
  }
       
  file1->Close();
  file2->Close();
  file3->Close();
       
  c.cd();
   TLegend *leg = new TLegend(0.1259501,0.7437811,0.3507058,0.8843284,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.04975124);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","CTF","lpf");
   entry->SetFillStyle(1001);

   entry->SetLineColor( TColor::GetColor("#3113ba"));
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","CosmicTF","lpflpf");
   entry->SetFillStyle(1001);
   
   entry->SetLineColor(TColor::GetColor("#de0b1d"));
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","Regional","lpflpflpf");
   entry->SetFillStyle(1001);

   entry->SetLineColor(TColor::GetColor("#33cc33"));
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
  h1.SetLineColor(TColor::GetColor("#3113ba"));
  h1.SetLineWidth(3); 
  h1.SetTitle("Tracks per Event");
  h1.SetXTitle("Tracks [#]");
  h1.DrawNormalized();
  h2.SetLineColor(TColor::GetColor("#de0b1d"));
  h2.SetLineWidth(3); 
  h2.SetTitle("Tracks per Event");
  h2.SetXTitle("Tracks [#]");
  h2.DrawNormalized("same");
  h3.SetLineColor(TColor::GetColor("#33cc33"));
  h3.SetLineWidth(3); 
  h3.SetTitle("Tracks per Event");
  h3.SetXTitle("Tracks [#]");
  h3.DrawNormalized("same");

  

  c.SaveAs("TracksMultiplicity_Normalized.png");
  c.SaveAs("TracksMultiplicity_Normalized.C");

  std::cout<<"Tracks from CTF: "<<trk1<<std::endl;
  std::cout<<"Tracks from CosmicTF: "<<trk2<<std::endl;
  std::cout<<"Tracks from Regional: "<<trk3<<std::endl;
}
