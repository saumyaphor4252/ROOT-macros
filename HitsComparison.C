TString ToString( int num )
{
  ostringstream start;
  start<<num;
  TString start1=start.str();
  return start1;
}

void HitsComparison()
{
   gStyle->SetOptStat(0);
   
   TString Allfiles[3] = {"CTF_2018.root","CosmicTF_2018.root","Regional_2018.root"};
   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
        
    gSystem->Exec("mkdir -p Combined_Hits_Plots");

   TCanvas* Canvas[8];
   for(int i=10; i<18; i++)
   {
       TString numstr=ToString(i);
       TString canvasName="Canvas"+numstr; 
       Canvas[i]= new TCanvas(canvasName,canvasName,800,600);    // Declare canvas
       gStyle->SetOptStat(0);
       
       Canvas[i]->SetFillColor(0);
       Canvas[i]->SetBorderMode(0);
       Canvas[i]->SetBorderSize(2);
       Canvas[i]->SetTickx(1);
       Canvas[i]->SetTicky(1);
       Canvas[i]->SetGrid();
       Canvas[i]->SetRightMargin(0.04193254);
       Canvas[i]->SetTopMargin(0.08736718);
       Canvas[i]->SetBottomMargin(0.08854782);
       Canvas[i]->SetFrameBorderMode(0);
    }

     vector<double>     *pt;
 
   vector<int>     *nHitsValid;
   vector<int>     *nHitsPIXEL;
   vector<int>     *nHitsBPIX;
   vector<int>     *nHitsFPIX;
   vector<int>     *nHitsTIB;
   vector<int>     *nHitsTOB;
   vector<int>     *nHitsTID;
   vector<int>     *nHitsTEC;
     
   int total=0;
   for(int nFile=0; nFile<3; nFile++)
     {
       
       TString filename=Allfiles[nFile];
       TFile *file = new TFile(filename.Data());
       TTree *tree;
       tree = (TTree*)file->Get("cosmicRateAnalyzer/Event");

       pt = 0;
       nHitsValid = 0;
       nHitsPIXEL = 0;
       nHitsBPIX = 0;
       nHitsFPIX = 0;
       nHitsTIB = 0;
       nHitsTOB = 0;
       nHitsTID = 0;
       nHitsTEC = 0;
       
       tree->SetBranchAddress("pt", &pt);
       tree->SetBranchAddress("nHitsValid", &nHitsValid);
       tree->SetBranchAddress("nHitsPIXEL", &nHitsPIXEL);
       tree->SetBranchAddress("nHitsBPIX", &nHitsBPIX);
       tree->SetBranchAddress("nHitsFPIX", &nHitsFPIX);
       tree->SetBranchAddress("nHitsTIB", &nHitsTIB);
       tree->SetBranchAddress("nHitsTOB", &nHitsTOB);
       tree->SetBranchAddress("nHitsTID", &nHitsTID);
       tree->SetBranchAddress("nHitsTEC", &nHitsTEC);

       TH1I h_nHitsValid        ("h_nHitsValid","h_nHitsValid",50,0,50);
       TH1I h_nHitsPIXEL	("h_nHitsPIXEL","h_nHitsPIXEL",10,0,10);
       TH1I h_nHitsBPIX 	("h_nHitsBPIX","h_nHitsBPIX",10,0,10);
       TH1I h_nHitsFPIX		("h_nHitsFPIX","h_nHitsFPIX",10,0,10);
       TH1I h_nHitsTIB 		("h_nHitsTIB","h_nHitsTIB",25,0,25);
       TH1I h_nHitsTOB 		("h_nHitsTOB","h_nHitsTOB",30,0,30);
       TH1I h_nHitsTID 		("h_nHitsTID","h_nHitsTID",15,0,15);
       TH1I h_nHitsTEC 		("h_nHitsTEC","h_nHitsTEC",20,0,20);
       
       Long64_t n = tree->GetEntriesFast();   
       for (Long64_t jentry=0; jentry<1000; jentry++)                          // Event Loop
	 {
	   tree->GetEntry(jentry);
	 
	   for (int k = 0; k < pt->size() ; k++)			// Loop to calculate Kinematical distributions
	     {
	       h_nHitsValid.Fill(nHitsValid->at(k));
	       h_nHitsPIXEL.Fill(nHitsPIXEL->at(k));
	       h_nHitsBPIX.Fill(nHitsBPIX->at(k));
	       h_nHitsFPIX.Fill(nHitsFPIX->at(k));
	       h_nHitsTIB.Fill(nHitsTIB->at(k));
	       h_nHitsTOB.Fill(nHitsTOB->at(k));
	       h_nHitsTID.Fill(nHitsTID->at(k));
	       h_nHitsTEC.Fill(nHitsTEC->at(k));
	       total++;
	     }
	 }
       
       if(nFile==0) { ci=TColor::GetColor("#3113ba"); }
       else if(nFile==1) { ci=TColor::GetColor("#de0b1d"); }
       else if(nFile==2) { ci=TColor::GetColor("#33cc33"); }
                   
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

   
       //+++++++++++++++++++++++++++++++       Valid Hits Distribution      ++++++++++++++++++++++++++++++++++++++++
       Canvas[10]->cd();
       h_nHitsValid.SetLineColor(ci);
       h_nHitsValid.SetLineWidth(3); 
       h_nHitsValid.SetTitle("Valid Hits");
       h_nHitsValid.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsValid.DrawNormalized(); }
       else
       {  h_nHitsValid.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------

       //+++++++++++++++++++++++++++++++       PIXEL Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[11]->cd();
       h_nHitsPIXEL.SetLineColor(ci);
       h_nHitsPIXEL.SetLineWidth(3); 
       h_nHitsPIXEL.SetTitle("Hits in PIXEL");
       h_nHitsPIXEL.SetXTitle("Hits [#}");
       if(nFile==0)
	 {  h_nHitsPIXEL.DrawNormalized(); }
       else
       {  h_nHitsPIXEL.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------

       //+++++++++++++++++++++++++++++++       BPIX Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[12]->cd();
       h_nHitsBPIX.SetLineColor(ci);
       h_nHitsBPIX.SetLineWidth(3); 
       h_nHitsBPIX.SetTitle("BPIX Hits");
       h_nHitsBPIX.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsBPIX.DrawNormalized(); }
       else
       {  h_nHitsBPIX.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------

       //+++++++++++++++++++++++++++++++      FPIX Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[13]->cd();
       h_nHitsFPIX.SetLineColor(ci);
       h_nHitsFPIX.SetLineWidth(3); 
       h_nHitsFPIX.SetTitle("FPIX Hits");
       h_nHitsFPIX.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsFPIX.DrawNormalized(); }
       else
       {  h_nHitsFPIX.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------
       
       //+++++++++++++++++++++++++++++++       TIB Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[14]->cd();
       h_nHitsTIB.SetLineColor(ci);
       h_nHitsTIB.SetLineWidth(3); 
       h_nHitsTIB.SetTitle("Hits in TIB");
       h_nHitsTIB.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsTIB.DrawNormalized(); }
       else
       {  h_nHitsTIB.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------

       //+++++++++++++++++++++++++++++++       TOB Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[15]->cd();
       h_nHitsTOB.SetLineColor(ci);
       h_nHitsTOB.SetLineWidth(3); 
       h_nHitsTOB.SetTitle("Hits in TOB");
       h_nHitsTOB.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsTOB.DrawNormalized(); }
       else
       {  h_nHitsTOB.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------

       //+++++++++++++++++++++++++++++++       TID Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[16]->cd();
       h_nHitsTID.SetLineColor(ci);
       h_nHitsTID.SetLineWidth(3); 
       h_nHitsTID.SetTitle("TID Hits");
       h_nHitsTID.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsTID.DrawNormalized(); }
       else
       {  h_nHitsTID.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------

       //+++++++++++++++++++++++++++++++       TEC Hits      ++++++++++++++++++++++++++++++++++++++++
       Canvas[17]->cd();
       h_nHitsTEC.SetLineColor(ci);
       h_nHitsTEC.SetLineWidth(3); 
       h_nHitsTEC.SetTitle("TEC Hits");
       h_nHitsTEC.SetXTitle("Hits [#]");
       if(nFile==0)
	 {  h_nHitsTEC.DrawNormalized(); }
       else
       {  h_nHitsTEC.DrawNormalized("SAME"); }
       leg->Draw();
       //---------------------------------------------------------------------------------------------------
       
     
       h_nHitsValid.Clear(); 
       h_nHitsPIXEL.Clear(); 
       h_nHitsBPIX.Clear();
       h_nHitsFPIX.Clear(); 
       h_nHitsTIB.Clear();
       h_nHitsTOB.Clear();
       h_nHitsTID.Clear(); 
       h_nHitsTEC.Clear(); 
          
       nHitsValid->clear();
       nHitsPIXEL->clear();
       nHitsBPIX->clear();
       nHitsFPIX->clear();
       nHitsTIB->clear();
       nHitsTOB->clear();
       nHitsTID->clear();
       nHitsTEC->clear();
       pt->clear();
          
       file->Close();
     }

  Canvas[10]->SaveAs("nHitsValid.png");
  Canvas[11]->SaveAs("nHitsPIXEL.png");
  Canvas[12]->SaveAs("nHitsBPIX.png");
  Canvas[13]->SaveAs("nHitsFPIX.png");
  Canvas[14]->SaveAs("nHitsTIB.png");
  Canvas[15]->SaveAs("nHitsTOB.png");
  Canvas[16]->SaveAs("nHitsTID.png");
  Canvas[17]->SaveAs("nHitsTEC.png");
  
  Canvas[10]->SaveAs("nHitsValid.C");
  Canvas[11]->SaveAs("nHitsPIXEL.C");
  Canvas[12]->SaveAs("nHitsBPIX.C");
  Canvas[13]->SaveAs("nHitsFPIX.C");
  Canvas[14]->SaveAs("nHitsTIB.C");
  Canvas[15]->SaveAs("nHitsTOB.C");
  Canvas[16]->SaveAs("nHitsTID.C");
  Canvas[17]->SaveAs("nHitsTEC.C");

  gSystem->Exec("mv nHitsValid.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsPIXEL.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsBPIX.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsFPIX.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTIB.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTOB.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTID.png Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTEC.png Combined_Hits_Plots");
  
  gSystem->Exec("mv nHitsValid.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsPIXEL.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsBPIX.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsFPIX.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTIB.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTOB.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTID.C Combined_Hits_Plots");
  gSystem->Exec("mv nHitsTEC.C Combined_Hits_Plots");

  using namespace std;
  std::cout<<"Total Tracks: "<<total<<std::endl;
}
