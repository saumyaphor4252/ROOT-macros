void MultiPlots()
{
   //==========Setting Up Canvas==========//
   TCanvas *c = new TCanvas("c", "c",754,169,800,756);
   gStyle->SetOptStat(0); // Dont show stats
   gStyle->SetOptTitle(0); // Dont show Title
   c->SetFillColor(0);  
   c->SetBorderSize(2);
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetLeftMargin(0.141604);
   c->SetRightMargin(0.04761905);
   c->SetTopMargin(0.07152683);
   c->SetBottomMargin(0.1224209);
   c->SetFrameLineWidth(3);
   c->SetFrameFillStyle(0);
   c->SetFrameLineWidth(2);
   c->SetFrameLineWidth(3);

   //=========Setting Up Legends==========//
   TLegend *leg = new TLegend(0.74,0.70,0.90,0.88);
   leg->SetHeader("Events","C");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetTextSize(0.04);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   //leg->SetFillStyle(1001);
   leg->SetFillStyle(0);
   
   //==========Making Directory for Plots=========//
   gSystem->Exec("mkdir MultiPlots");

   //===========Color Palette=========//
   Int_t colors[8]  = {kBlack,kBlue,kRed,kGreen+2,kOrange,kMagenta,kCyan,kViolet};

   //===========Mentioning File and Directory for Input============//
   TFile *file = TFile::Open("MC_Zmumu_2018.root");
   TDirectory *folder = (TDirectory*)file->Get("demo");
   TTree *tree = (TTree*)folder->Get("Event");
   TIter next(tree->GetListOfBranches());
   TKey *key;

   //===============Input File for reading the Histograms Parameters,(Here Variable name, Bins, xMin, xMax)===============//
   FILE *fp = fopen("HistParameters.csv","r");
   int Bins; float xMin,xMax; char variable[80];
   
   //=========================DEfining Histogram Array In case you wish to store Histograms in a root file ========================//
   char name[10], title[20], legEntry[20];
   TObjArray Hlist(0); // create an array of Histograms
   TH1F* h; // create a pointer to a histogram

   while ((key=(TKey*)next()))
   {
     printf("key: %s \n", key->GetName());
     TString BranchName=key->GetName();
     printf("Branch Name: %s \n",BranchName.Data());
     
     //==================Reading Histogram Parameters from CSV =======================// 
     fscanf(fp," %i, %f ,%f \n",&Bins,&xMin,&xMax);
     std::cout<<Bins<<" | "<<xMin<<" | "<<xMax<<std::endl;
   
     //===============================Loop over number of events you want to include=========================//
     int t=0;
     // TString BranchName="pt";
     for(int i=1000;i<=1000000;i=i*10, t++)
      {
	 
	 TString cmd1 = Form("%s>>hnew(%i,%f,%f)",BranchName.Data(),Bins,xMin,xMax);
	 
	 std::cout<<cmd1.Data()<<std::endl;
	 tree->Draw(cmd1.Data(),"","goff",i,0);
	 
	 //	 sprintf(name,"h%d",i);
	 // sprintf(title,"histo nr:%d",i);
	 h = (TH1F*)gDirectory->Get("hnew");
	 h->SetLineColor(colors[t]);
	 h->SetLineWidth(2);
	 h->GetXaxis()->SetLabelFont(42);
	 h->GetXaxis()->SetLabelSize(0.05);
	 h->GetXaxis()->SetTitleSize(0.05);
	 h->GetXaxis()->SetTickLength(0.05);
	 //	 h->GetXaxis()->SetTitleOffset(1.07);
	 h->GetXaxis()->SetTitleFont(42);
	 h->GetYaxis()->SetTitle("a.u.");
	 h->GetYaxis()->SetLabelFont(42);
	 h->GetYaxis()->SetLabelSize(0.05);
	 h->GetYaxis()->SetTitleSize(0.06);
	 h->GetYaxis()->SetTickLength(0.05);
	 //	 h->GetYaxis()->SetTitleOffset(1.19);
	 h->GetYaxis()->SetTitleFont(42);
	 //=======================x Axis Title =========================//
	 if(BranchName=="charge")
	   h->GetXaxis()->SetTitle("Track charge (e)");
	 else if(BranchName=="p")
	   h->GetXaxis()->SetTitle("Track p (GeV)");
	 else if(BranchName=="pt")
	   h->GetXaxis()->SetTitle("Track p_{T}(GeV)");
	 else if(BranchName=="eta")
	   h->GetXaxis()->SetTitle("Track #eta");
	 else if(BranchName=="theta")
	   h->GetXaxis()->SetTitle("Track #theta (rad)");
	 else if(BranchName=="phi")
	   h->GetXaxis()->SetTitle("Track #phi (rad)");
	 else if(BranchName=="chi2")
	   h->GetXaxis()->SetTitle("Track #chi^{2}");
	 else if(BranchName=="chi2ndf")
	   h->GetXaxis()->SetTitle("Track #chi^{2} /NDF");
	 else if(BranchName=="chi2Prob")
	   h->GetXaxis()->SetTitle("Track #chi^{2} Prob");
	 else if(BranchName=="d0")
	   h->GetXaxis()->SetTitle("Track d_{0} (cm)");
	 else if(BranchName=="dz")
	   h->GetXaxis()->SetTitle("Track d_{z} (cm)");
	 else if(BranchName=="d0PV")
	   h->GetXaxis()->SetTitle("Track d_{0}(PV) (cm)");
	 else if(BranchName=="dxyPV")
	   h->GetXaxis()->SetTitle("Track d_{xy}(PV) (cm)");
	 else if(BranchName=="dzPV")
	   h->GetXaxis()->SetTitle("Track d_{z}(PV) (cm)");
	 else if(BranchName=="d0BS")
	   h->GetXaxis()->SetTitle("Track d_{0}(BS) (cm)");
	 else if(BranchName=="dxyBS")
	   h->GetXaxis()->SetTitle("Track d_{xy}(BS) (cm)");
	 else if(BranchName=="dzBS")
	   h->GetXaxis()->SetTitle("Track d_{z}(BS) (cm)");
	 
	 //===============HITS==============
	 else if(BranchName=="nHitsValid")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if(BranchName=="nHits2D")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsPIXEL")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsBPIX")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsFPIX")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsFPIXplus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsFPIXminus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTIB")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTOB")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTID")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTIDplus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTIDminus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTEC")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if( BranchName=="nHitsTECplus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsTECminus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsENDCAP")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsENDCAPplus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 else if (BranchName=="nHitsENDCAPminus")
	   h->GetXaxis()->SetTitle("Hits (#)");
	 
	 //============RESIDUALS=========
	 else if (BranchName.Contains("xPrime"))
	   {h->GetXaxis()->SetTitle("Res_{X'} (#mum)");
	     //gStyle->SetMaxDigitsX(3);
	     TGaxis::SetMaxDigits(2);
	   }
	 else if (BranchName.Contains("yPrime"))
	   h->GetXaxis()->SetTitle("Res_{Y'} (#mum)");
	 
	 //===================Resonances=============
	 else if (BranchName=="ResonancesMass")
	   h->GetXaxis()->SetTitle("Invariant Mass (GeV/c^2)");
	 else if (BranchName=="ResonancessEta")
	   h->GetXaxis()->SetTitle("Invariant Mass #eta");
	 else if (BranchName=="ResonancessPt")
	   h->GetXaxis()->SetTitle("Invariant Mass p_T(GeV)");
	 else if (BranchName=="TracksPerEvent")
	   h->GetXaxis()->SetTitle("Tracks Per Event (#)");
	 else if (BranchName=="Temp")
	   h->GetXaxis()->SetTitle("Temp");
	 else 
	   { std::cout<<"No match to Branch Name"<<std::endl;
	   }
	 //  if(BranchName=="p")
	 //  h->GetXaxis()->SetTitle("Track p (GeV)");
	  //  else if(BranchName=="pt")
	       //   h->GetXaxis()->SetTitle("Track p_{T}(GeV)");
            
         if(i==1000)
	   h->DrawNormalized();
	 else
	   h->DrawNormalized("Same");
	 // Redraw the new axis
	 gPad->Update();
	 // hnew->SetLineColor(kRed)
	 //hnew->SetLineWidth(3)
	 //hnew->Draw()
	 //Hlist.Add(h);
	 std::cout<<"Times: "<<i<<std::endl;
      
	 //============== Drawing Legends================
	 sprintf(legEntry, "%i", i);
	 leg->SetHeader("Events","png");
	 TLegendEntry *entry=leg->AddEntry(h,legEntry,"l");
	 entry->SetFillStyle(1001);
	 entry->SetLineColor(colors[t]);
	 entry->SetLineStyle(1);
	 entry->SetLineWidth(3);
	 entry->SetMarkerColor(colors[t]);
	 entry->SetMarkerStyle(1);
	 entry->SetMarkerSize(1);
	 entry->SetTextFont(42);
	 leg->Draw();
	 }
     
     
     TString filename = BranchName + ".C";
     c->SaveAs(filename.Data());
     TString cmd = "mv  " + filename + " MultiPlots";
     gSystem->Exec(cmd.Data());
     c->Clear();
     h->Clear();
     leg->Clear();
     
   }

}
   
