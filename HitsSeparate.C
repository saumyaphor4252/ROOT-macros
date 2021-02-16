void HitsSeparate()
{
  gStyle->SetOptStat(0);

  gSystem->Exec("mkdir -p Combined_Hits_Plots");
   
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

   TCanvas c1("c1","c1",800,600);    // Declare canvas
  c1.SetFillColor(0);
  c1.SetBorderMode(0);
  c1.SetBorderSize(3);
  c1.SetTickx(1);
  c1.SetTicky(1);
  c1.SetGrid();
  c1.SetRightMargin(0.04193254);
  c1.SetTopMargin(0.08736718);
  c1.SetBottomMargin(0.08854782);
  c1.SetFrameBorderMode(0);
  
  TTree *tree1;
  TTree *tree2;
  TTree *tree3;

  tree1 = (TTree*)file1->Get("cosmicRateAnalyzer/Event");
  tree2 = (TTree*)file2->Get("cosmicRateAnalyzer/Event");
  tree3 = (TTree*)file3->Get("cosmicRateAnalyzer/Event");
  int trk1=0,trk2=0,trk3=0;

  vector<int> *vectorHits_1, *vectorHits_2, *vectorHits_3;

    vectorHits_1=0;
    vectorHits_2=0;
    vectorHits_3=0;
    
  tree1->SetBranchAddress("nHitsTOB", &vectorHits_1);
  tree2->SetBranchAddress("nHitsTOB", &vectorHits_2);
  tree3->SetBranchAddress("nHitsTOB", &vectorHits_3);
  
  TH1D h1 		("h1","h1",30,0,30);
  TH1D h2       	("h2","h2",30,0,30);
  TH1D h3 		("h3","h3",30,0,30);
  
  Long64_t n = tree1->GetEntriesFast();     
  for (Long64_t jentry=0; jentry<n; jentry++) //Event Loop
  {
  
    tree1->GetEntry(jentry);  // Get 
    for (int k = 0; k < vectorHits_1->size() ; k++)			// Loop to calculate Kinematical distributions
      {
	h1.Fill(vectorHits_1->at(k));     
	trk1++;
      }
    vectorHits_1->clear();
    
    
    tree2->GetEntry(jentry);
    for (int k = 0; k < vectorHits_2->size() ; k++)			// Loop to calculate Kinematical distributions
      {
	h2.Fill(vectorHits_2->at(k));     
	trk2++;
      }
     vectorHits_2->clear();
    
    tree3->GetEntry(jentry);
    for (int k = 0; k < vectorHits_3->size() ; k++)			// Loop to calculate Kinematical distributions
      {
	h3.Fill(vectorHits_3->at(k));     
	trk3++;
      }
     vectorHits_3->clear();
    
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
  
 
  h1.SetLineColor(TColor::GetColor("#3113ba"));
  h1.SetLineWidth(3); 
  h1.SetTitle("Hits in TOB");
  h1.SetXTitle("Hits [#]");
  h1.DrawNormalized();
  h2.SetLineColor(TColor::GetColor("#de0b1d"));
  h2.SetLineWidth(3); 
  h2.SetXTitle("Hits [#]");
  h2.DrawNormalized("same");
  h3.SetLineColor(TColor::GetColor("#33cc33"));
  h3.SetLineWidth(3); 
  h3.SetXTitle("Hits [#]");
  h3.DrawNormalized("same");
   leg->Draw();
  c.SaveAs("nHitsTOB_Normalized.png");
  c.SaveAs("nHitsTOB_Normalized.C");

  c1.cd();
    h1.SetLineColor(TColor::GetColor("#3113ba"));
  h1.SetLineWidth(3); 
  h1.SetTitle("Hits in TOB");
  h1.SetXTitle("Hits [#]");
  h1.DrawCopy();
  h2.SetLineColor(TColor::GetColor("#de0b1d"));
  h2.SetLineWidth(3); 
  h2.SetXTitle("Hits [#]");
  h2.DrawCopy("same");
  h3.SetLineColor(TColor::GetColor("#33cc33"));
  h3.SetLineWidth(3); 
  h3.SetXTitle("Hits [#]");
  h3.DrawCopy("same");
   leg->Draw();
    c1.SaveAs("nHitsTOB.png");
  c1.SaveAs("nHitsTOB.C");

  gSystem->Exec("mv nHitsTOB.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTOB_Normalized.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTOB.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTOB_Normalized.png Combined_Hits_Plots");
 
  std::cout<<"Tracks from CTF: "<<trk1<<std::endl;
  std::cout<<"Tracks from CosmicTF: "<<trk2<<std::endl;
  std::cout<<"Tracks from Regional: "<<trk3<<std::endl;
}
