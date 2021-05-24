void GetKinematicPlots()

{
  TFile *file1 = new TFile("CRAB_CTF_Residuals.root");
  TFile *file2 = new TFile("CRAB_CosmicTF_Residuals.root");
  TTree *tree1, *tree2;
  tree1 = (TTree*)file1->Get("demo/Event");
  tree2 = (TTree*)file2->Get("demo/Event");

  //========================Local varibles to store parameters from tree===================//
  vector<double>  *pt_CTF;
  vector<double>  *charge_CTF;
  vector<double>  *chi2_CTF;
  vector<double>  *chi2_ndof_CTF;
  vector<double>  *eta_CTF;
  vector<double>  *theta_CTF;
  vector<double>  *phi_CTF;
  vector<double>  *d0_CTF;
  vector<double>  *dz_CTF;
  vector<int>  *nHitsValid_CTF;
  vector<int>  *nHitsPIXEL_CTF;
  vector<int>  *nHitsBPIX_CTF;
  vector<int>  *nHitsFPIX_CTF;
  vector<int>  *nHitsTIB_CTF;
  vector<int>  *nHitsTID_CTF;
  vector<int>  *nHitsTOB_CTF;
  vector<int>  *nHitsTEC_CTF;
  
  pt_CTF=0; charge_CTF=0; chi2_CTF=0; chi2_ndof_CTF=0; eta_CTF=0; theta_CTF=0; phi_CTF=0; d0_CTF=0; dz_CTF=0;
  nHitsValid_CTF=0; nHitsPIXEL_CTF=0; nHitsBPIX_CTF=0;  nHitsFPIX_CTF=0;  nHitsTIB_CTF=0;  nHitsTID_CTF=0;  nHitsTOB_CTF=0;  nHitsTEC_CTF=0;

  //=======tree2======//
  vector<double>  *pt_CosmicTF;
  vector<double>  *charge_CosmicTF;
  vector<double>  *chi2_CosmicTF;
  vector<double>  *chi2_ndof_CosmicTF;
  vector<double>  *eta_CosmicTF;
  vector<double>  *theta_CosmicTF;
  vector<double>  *phi_CosmicTF;
  vector<double>  *d0_CosmicTF;
  vector<double>  *dz_CosmicTF;
  vector<int>  *nHitsValid_CosmicTF;
  vector<int>  *nHitsPIXEL_CosmicTF;
  vector<int>  *nHitsBPIX_CosmicTF;
  vector<int>  *nHitsFPIX_CosmicTF;
  vector<int>  *nHitsTIB_CosmicTF;
  vector<int>  *nHitsTOB_CosmicTF;
  vector<int>  *nHitsTID_CosmicTF;
  vector<int>  *nHitsTEC_CosmicTF;
  
  pt_CosmicTF=0; charge_CosmicTF=0; chi2_CosmicTF=0; chi2_ndof_CosmicTF=0; eta_CosmicTF=0; theta_CosmicTF=0; phi_CosmicTF=0; d0_CosmicTF=0; dz_CosmicTF=0;
  nHitsValid_CosmicTF=0; nHitsPIXEL_CosmicTF=0; nHitsBPIX_CosmicTF=0;  nHitsFPIX_CosmicTF=0;  nHitsTIB_CosmicTF=0;  nHitsTID_CosmicTF=0;  nHitsTOB_CosmicTF=0;  nHitsTEC_CosmicTF=0;

  //==============================Setting tree branches to local varibles================//
  tree1->SetBranchAddress("pt", &pt_CTF);
  tree1->SetBranchAddress("charge", &charge_CTF);
  tree1->SetBranchAddress("chi2", &chi2_CTF);
  tree1->SetBranchAddress("chi2_ndof", &chi2_ndof_CTF);
  tree1->SetBranchAddress("eta", &eta_CTF);
  tree1->SetBranchAddress("theta", &theta_CTF);
  tree1->SetBranchAddress("phi", &phi_CTF);
  tree1->SetBranchAddress("d0", &d0_CTF);
  tree1->SetBranchAddress("dz", &dz_CTF);
  tree1->SetBranchAddress("nHitsValid", &nHitsValid_CTF);
  tree1->SetBranchAddress("nHitsPIXEL", &nHitsPIXEL_CTF);
  tree1->SetBranchAddress("nHitsBPIX", &nHitsBPIX_CTF);
  tree1->SetBranchAddress("nHitsFPIX", &nHitsFPIX_CTF);
  tree1->SetBranchAddress("nHitsTIB", &nHitsTIB_CTF);
  tree1->SetBranchAddress("nHitsTID", &nHitsTID_CTF);
  tree1->SetBranchAddress("nHitsTOB", &nHitsTOB_CTF);
  tree1->SetBranchAddress("nHitsTEC", &nHitsTEC_CTF);
  
  tree2->SetBranchAddress("pt", &pt_CosmicTF);
  tree2->SetBranchAddress("charge", &charge_CosmicTF);
  tree2->SetBranchAddress("chi2", &chi2_CosmicTF);
  tree2->SetBranchAddress("chi2_ndof", &chi2_ndof_CosmicTF);
  tree2->SetBranchAddress("eta", &eta_CosmicTF);
  tree2->SetBranchAddress("theta", &theta_CosmicTF);
  tree2->SetBranchAddress("phi", &phi_CosmicTF);
  tree2->SetBranchAddress("d0", &d0_CosmicTF);
  tree2->SetBranchAddress("dz", &dz_CosmicTF);
  tree2->SetBranchAddress("nHitsValid", &nHitsValid_CosmicTF);
  tree2->SetBranchAddress("nHitsPIXEL", &nHitsPIXEL_CosmicTF);
  tree2->SetBranchAddress("nHitsBPIX", &nHitsBPIX_CosmicTF);
  tree2->SetBranchAddress("nHitsFPIX", &nHitsFPIX_CosmicTF);
  tree2->SetBranchAddress("nHitsTIB", &nHitsTIB_CosmicTF);
  tree2->SetBranchAddress("nHitsTOB", &nHitsTOB_CosmicTF);
  tree2->SetBranchAddress("nHitsTID", &nHitsTID_CosmicTF);
  tree2->SetBranchAddress("nHitsTEC", &nHitsTEC_CosmicTF); 

  Long64_t n1 = tree1->GetEntriesFast();
  Long64_t n2 = tree2->GetEntriesFast();
  std::cout<<"Events :"<<n1<<std::endl;
  std::cout<<"Events :"<<n2<<std::endl;

  //===============Defining histograms for filling================//
  TH1D h_pt_CTF 		("h_pt_CTF","h_pt",100,0,100);
  TH1D h_charge_CTF 	        ("h_charge_CTF","h_charge",10,-5,5);
  TH1D h_chi2_CTF 		("h_chi2_CTF","h_chi2",200,0,100);
  TH1D h_chi2_ndof_CTF    	("h_chi2_ndof_CTF","h_chi2_ndof",100,0,10);
  TH1D h_eta_CTF 		("h_eta_CTF","h_eta",500,-3,3);
  TH1D h_theta_CTF      	("h_thetaCTF","h_theta",500,-3,3);
  TH1D h_phi_CTF 		("h_phi_CTF","h_phi",400,-3.5,3.5);
  TH1D h_d0_CTF 		("h_d0_CTF","h_d0",1000,-85,85);
  TH1D h_dz_CTF 		("h_dz_CTF","h_dz",1500,-350,350);

  TH1D h_pt_CosmicTF 		("h_pt_CosmicTF","h_pt",200,0,200);
  TH1D h_charge_CosmicTF 	("h_charge_CosmicTF","h_charge",10,-5,5);
  TH1D h_chi2_CosmicTF 		("h_chi2_CosmicTF","h_chi2",200,0,100);
  TH1D h_chi2_ndof_CosmicTF 	("h_chi2_ndof_CosmicTF","h_chi2_ndof",200,0,20);
  TH1D h_eta_CosmicTF 		("h_eta_CosmicTF","h_eta",500,-3,3);
  TH1D h_theta_CosmicTF 	("h_thetaCosmicTF","h_theta",500,-3,3);
  TH1D h_phi_CosmicTF 		("h_phi_CosmicTF","h_phi",400,-3.5,3.5);
  TH1D h_d0_CosmicTF 		("h_d0_CosmicTF","h_d0",1000,-85,85);
  TH1D h_dz_CosmicTF 		("h_dz_CosmicTF","h_dz",1500,-350,350);

  //-----Hits-----//
  TH1D h_nHitsValid_CTF("h_nHitsValid_CTF", "Valid Hits;Hits (#); Tracks", 50, 0, 50);
  TH1I h_nHitsPIXEL_CTF("h_nHitsPIXEL_CTF", "Hits in PIXEL;Hits (#); Tracks", 10, 0, 10);
  TH1I h_nHitsBPIX_CTF("h_nHitsBPIX_CTF", "Hits in BPIX;Hits (#); Tracks", 10, 0, 10);
  TH1I h_nHitsFPIX_CTF("h_nHitsFPIX_CTF", "Hits in FPIX;Hits (#); Tracks", 10, 0, 10);
  TH1I h_nHitsTIB_CTF("h_nHitsTIB_CTF", "Hits in TIB;Hits (#); Tracks", 30, 0, 30);
  TH1I h_nHitsTOB_CTF("h_nHitsTOB_CTF", "Hits in TOB;Hits (#); Tracks", 30, 0, 30);
  TH1I h_nHitsTID_CTF("h_nHitsTID_CTF", "Hits in TID;Hits (#); Tracks", 30, 0, 30); 
  TH1I h_nHitsTEC_CTF("h_nHitsTEC_CTF", "Hits in TEC;Hits (#); Tracks", 30, 0, 30);
  
  TH1D h_nHitsValid_CosmicTF("h_nHitsValid_CosmicTF", "Valid Hits;Hits (#); Tracks", 50, 0, 50);
  TH1I h_nHitsPIXEL_CosmicTF("h_nHitsPIXEL_CosmicTF", "Hits in PIXEL;Hits (#); Tracks", 10, 0, 10);
  TH1I h_nHitsBPIX_CosmicTF("h_nHitsBPIX_CosmicTF", "Hits in BPIX;Hits (#); Tracks", 10, 0, 10);
  TH1I h_nHitsFPIX_CosmicTF("h_nHitsFPIX_CosmicTF", "Hits in FPIX;Hits (#); Tracks", 10, 0, 10);
  TH1I h_nHitsTIB_CosmicTF("h_nHitsTIB_CosmicTF", "Hits in TIB;Hits (#); Tracks", 30, 0, 30);
  TH1I h_nHitsTOB_CosmicTF("h_nHitsTOB_CosmicTF", "Hits in TOB;Hits (#); Tracks", 30, 0, 30);
  TH1I h_nHitsTID_CosmicTF("h_nHitsTID_CosmicTF", "Hits in TID;Hits (#); Tracks", 30, 0, 30);
  TH1I h_nHitsTEC_CosmicTF("h_nHitsTEC_CosmicTF", "Hits in TEC;Hits (#); Tracks", 30, 0, 30);

  TH1D h_delta_pt("h_delta_pt", "#Delta p_{T}",100,-5,5); 
  TH1D h_delta_eta("h_delta_eta","#Delta #eta",1000,-1,1 ); 
  TH1D h_delta_phi("h_delta_phi", "#Delta #phi",1000,-1,1);
  TH1D h_deltaPtByPtCosmicTF("h_deltaPtByPtCosmiTF", "#Delta p_{T}/p_{T}", 100, -1, 1);
  TH1D h_deltaEtaByEtaCosmicTF("h_deltaEtaByEtaCosmicTF","\frac{#Delta #eta}{#eta}", 1000, -1, 1 );
  TH1D h_deltaPtByPtCTF("h_deltaPtByPtCTF", "#Delta p_{T}/p_{T}", 100, -1, 1);
  TH1D h_deltaEtaByEtaCTF("h_deltaEtaByEtaCTF","\frac{#Delta #eta}{#eta}",1000 , -1, 1 );

  FILE *DeltaRIndices = fopen("Track_Matching_Indices.csv","r");
  //File having Indices of selected events, and matching track indices "CosmicTF event, CosmicTF track, CTF event, CTF track
  
  int nMatchedEvents=0,Idx_Event_CosmicTF=0, Idx_Track_CosmicTF=0, Idx_Track_CTF=0; float Idx_Event_CTF=0;
  while(!feof(DeltaRIndices))
    {
      fscanf(DeltaRIndices,"%i,%i,%f,%i\n",&Idx_Event_CosmicTF,&Idx_Track_CosmicTF,&Idx_Event_CTF,&Idx_Track_CTF);
      if(nMatchedEvents<10) std::cout<<Idx_Event_CosmicTF<<" : "<<Idx_Track_CosmicTF<<" : "<<Idx_Event_CTF<<" : "<<Idx_Track_CTF<<std::endl;
      nMatchedEvents++;

      tree1->GetEntry(Idx_Event_CTF);       //Get first track matched event of CTF 
      tree2->GetEntry(Idx_Event_CosmicTF);  //Get first track matched event of CosmicTF

      h_pt_CosmicTF.Fill(pt_CosmicTF->at(Idx_Track_CosmicTF));
      h_charge_CosmicTF.Fill(charge_CosmicTF->at(Idx_Track_CosmicTF));
      h_chi2_CosmicTF.Fill(chi2_CosmicTF->at(Idx_Track_CosmicTF));
      h_chi2_ndof_CosmicTF.Fill(chi2_ndof_CosmicTF->at(Idx_Track_CosmicTF));
      h_eta_CosmicTF.Fill(eta_CosmicTF->at(Idx_Track_CosmicTF));
      h_theta_CosmicTF.Fill(theta_CosmicTF->at(Idx_Track_CosmicTF));
      h_phi_CosmicTF.Fill(phi_CosmicTF->at(Idx_Track_CosmicTF));
      h_d0_CosmicTF.Fill(d0_CosmicTF->at(Idx_Track_CosmicTF));
      h_dz_CosmicTF.Fill(dz_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsValid_CosmicTF.Fill(nHitsValid_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsPIXEL_CosmicTF.Fill(nHitsPIXEL_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsBPIX_CosmicTF.Fill(nHitsBPIX_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsFPIX_CosmicTF.Fill(nHitsFPIX_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsTIB_CosmicTF.Fill(nHitsTIB_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsTOB_CosmicTF.Fill(nHitsTOB_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsTID_CosmicTF.Fill(nHitsTID_CosmicTF->at(Idx_Track_CosmicTF));
      h_nHitsTEC_CosmicTF.Fill(nHitsTEC_CosmicTF->at(Idx_Track_CosmicTF));
      
      h_pt_CTF.Fill(pt_CTF->at(Idx_Track_CTF));
      h_charge_CTF.Fill(charge_CTF->at(Idx_Track_CTF));
      h_chi2_CTF.Fill(chi2_CTF->at(Idx_Track_CTF));
      h_chi2_ndof_CTF.Fill(chi2_ndof_CTF->at(Idx_Track_CTF));
      h_eta_CTF.Fill(eta_CTF->at(Idx_Track_CTF));
      h_theta_CTF.Fill(theta_CTF->at(Idx_Track_CTF));
      h_phi_CTF.Fill(phi_CTF->at(Idx_Track_CTF));
      h_d0_CTF.Fill(d0_CTF->at(Idx_Track_CTF));
      h_dz_CTF.Fill(dz_CTF->at(Idx_Track_CTF));
      h_nHitsValid_CTF.Fill(nHitsValid_CTF->at(Idx_Track_CTF));
      h_nHitsPIXEL_CTF.Fill(nHitsPIXEL_CTF->at(Idx_Track_CTF));
      h_nHitsBPIX_CTF.Fill(nHitsBPIX_CTF->at(Idx_Track_CTF));
      h_nHitsFPIX_CTF.Fill(nHitsFPIX_CTF->at(Idx_Track_CTF));
      h_nHitsTIB_CTF.Fill(nHitsTIB_CTF->at(Idx_Track_CTF));
      h_nHitsTOB_CTF.Fill(nHitsTOB_CTF->at(Idx_Track_CTF));
      h_nHitsTID_CTF.Fill(nHitsTID_CTF->at(Idx_Track_CTF));
      h_nHitsTEC_CTF.Fill(nHitsTEC_CTF->at(Idx_Track_CTF));

      h_delta_pt.Fill( pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF) );
      h_delta_eta.Fill( eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF) );
      h_delta_phi.Fill( phi_CosmicTF->at(Idx_Track_CosmicTF)-phi_CTF->at(Idx_Track_CTF) );
      h_deltaPtByPtCosmicTF.Fill( (pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF))/pt_CosmicTF->at(Idx_Track_CosmicTF) );
      h_deltaEtaByEtaCosmicTF.Fill( (eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF))/eta_CosmicTF->at(Idx_Track_CosmicTF) );
      h_deltaPtByPtCTF.Fill( (pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF))/pt_CTF->at(Idx_Track_CTF) );
      h_deltaEtaByEtaCTF.Fill( (eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF))/eta_CTF->at(Idx_Track_CTF) );
      
    }
  std::cout<<nMatchedEvents<<std::endl;
  fclose(DeltaRIndices);


  //TCanvas c("c", "c",594,190,661,666);
  TCanvas c("c", "c",556,214,661,641);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0); // Dont show Title
  c.Range(-7.156863,-810349,5.764706,4951034);
  c.SetFillColor(0);
  c.SetBorderMode(0);
  c.SetBorderSize(3);
  c.SetGridx();
  c.SetGridy();
  c.SetTickx(1);
  c.SetTicky(1);
  c.SetLeftMargin(0.1669196);
  c.SetRightMargin(0.05918058);
  c.SetTopMargin(0.08233276);
  c.SetBottomMargin(0.1406518);
  c.SetFrameLineWidth(3);
  c.SetFrameBorderMode(0);
  c.SetFrameLineWidth(3);
  c.SetFrameBorderMode(0);
  TGaxis::SetMaxDigits(3);

  TLegend *leg = new TLegend(0.6494689,0.7324185,0.8952959,0.8696398,NULL,"brNDC");
  leg->SetBorderSize(1);
  leg->SetTextFont(62);
  leg->SetTextSize(0.03606557);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Track Collection","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","CTF","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry((TObject*)0,"CosmicTF","lpflpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);

  TLatex Title = TLatex();
  Title.SetTextFont(42);
  Title.SetTextSize(0.04);
   
  gSystem->Exec("mkdir -p Kinematical_Plots");
  
  //+++++++++++++++++++++++++++++++       pT Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_pt_CTF.SetLineColor(kBlue);
  h_pt_CTF.SetLineWidth(3);
  h_pt_CTF.SetTitle("p_{T} Distribution");
  h_pt_CTF.SetXTitle("Track p_{T} (GeV)");
  h_pt_CTF.SetYTitle("Tracks (#)");
  h_pt_CTF.Draw("EHIST");
  h_pt_CTF.GetXaxis()->SetLabelSize(0.05);
  h_pt_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_pt_CTF.GetYaxis()->SetLabelSize(0.05);
  h_pt_CTF.GetYaxis()->SetTitleSize(0.05);
  //h_pt_CTF.GetXaxis()->SetTitleOffset(1.12);	
  //h_pt_CTF.GetYaxis()->SetTitleOffset(1.45);
  
  h_pt_CosmicTF.SetLineColor(kRed);
  h_pt_CosmicTF.SetLineWidth(3);
  h_pt_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("pt.png");
  c.SaveAs("pt.C");
  c.Clear();
  gSystem->Exec("mv pt.png Kinematical_Plots");
  gSystem->Exec("mv pt.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       charge Distribution      ++++++++++++++++++++++++++++++++++++++++      
  h_charge_CTF.SetLineColor(kBlue);
  h_charge_CTF.SetLineWidth(3);
  h_charge_CTF.SetTitle("Charge (e)");
  h_charge_CTF.SetXTitle("Track charge (e)");
  h_charge_CTF.SetYTitle("Tracks (#)");
  h_charge_CTF.Draw();
  h_charge_CTF.GetXaxis()->SetLabelSize(0.05);
  h_charge_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_charge_CTF.GetYaxis()->SetLabelSize(0.05);
  h_charge_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_charge_CosmicTF.SetLineColor(kRed);
  h_charge_CosmicTF.SetLineWidth(3);
  h_charge_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");

  TLatex *   tex = new TLatex(66.27451,2987022,"cosmic rays (2018)");
  tex->SetTextFont(42);
  tex->SetTextSize(0.03773585);
  tex->SetLineWidth(2);
  tex->Draw();

  c.SaveAs("charge.png");
  c.SaveAs("charge.C");
  c.Clear();
  gSystem->Exec("mv charge.png Kinematical_Plots");
  gSystem->Exec("mv charge.C Kinematical_Plots");
  //--------------------------------------------------------------------------------------------------- 
  
  //+++++++++++++++++++++++++++++++       chi2 Distribution      ++++++++++++++++++++++++++++++++++++++++      
  h_chi2_CTF.SetLineColor(kBlue);
  h_chi2_CTF.SetLineWidth(3); 
  h_chi2_CTF.SetTitle("#chi^{2} Distribution");
  h_chi2_CTF.SetXTitle("Track #chi^{2}");
  h_chi2_CTF.SetYTitle("Tracks (#)");
  h_chi2_CTF.Draw();
  h_chi2_CTF.GetXaxis()->SetLabelSize(0.05);
  h_chi2_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_chi2_CTF.GetYaxis()->SetLabelSize(0.05);
  h_chi2_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_chi2_CosmicTF.SetLineColor(kRed);
  h_chi2_CosmicTF.SetLineWidth(3); 
  h_chi2_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");

  c.SaveAs("chi2.png");
  c.SaveAs("chi2.C");   
  c.Clear();      
  gSystem->Exec("mv chi2.png Kinematical_Plots");
  gSystem->Exec("mv chi2.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       chi2/ndof Distribution      ++++++++++++++++++++++++++++++++++++++++       
  h_chi2_ndof_CTF.SetLineColor(kBlue);
  h_chi2_ndof_CTF.SetLineWidth(3); 
  h_chi2_ndof_CTF.SetTitle("#chi^{2} per NDF");
  h_chi2_ndof_CTF.SetXTitle("Track #chi^{2} per NDF");
  h_chi2_ndof_CTF.SetYTitle("Tracks (#)");
  h_chi2_ndof_CTF.Draw();
  h_chi2_ndof_CTF.GetXaxis()->SetLabelSize(0.05);
  h_chi2_ndof_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_chi2_ndof_CTF.GetYaxis()->SetLabelSize(0.05);
  h_chi2_ndof_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_chi2_ndof_CosmicTF.SetLineColor(kRed);
  h_chi2_ndof_CosmicTF.SetLineWidth(3); 
  h_chi2_ndof_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("chi2_ndof.png");
  c.SaveAs("chi2_ndof.C");  
  c.Clear();
  gSystem->Exec("mv chi2_ndof.png Kinematical_Plots");
  gSystem->Exec("mv chi2_ndof.C Kinematical_Plots");
  //--------------------------------------------------------------------------------------------------- 
  
  //+++++++++++++++++++++++++++++++       eta Distribution      ++++++++++++++++++++++++++++++++++++++++       
  h_eta_CTF.SetLineColor(kBlue);
  h_eta_CTF.SetLineWidth(3); 
  h_eta_CTF.SetTitle("#eta Distribution");
  h_eta_CTF.SetXTitle("Track #eta");
  h_eta_CTF.SetYTitle("Tracks (#)");
  h_eta_CTF.Draw();
  h_eta_CTF.GetXaxis()->SetLabelSize(0.05);
  h_eta_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_eta_CTF.GetYaxis()->SetLabelSize(0.05);
  h_eta_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_eta_CosmicTF.SetLineColor(kRed);
  h_eta_CosmicTF.SetLineWidth(3); 
  h_eta_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("eta.png");
  c.SaveAs("eta.C");  
  c.Clear();      
  gSystem->Exec("mv eta.png Kinematical_Plots");
  gSystem->Exec("mv eta.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------  
  
  //+++++++++++++++++++++++++++++++       theta Distribution      ++++++++++++++++++++++++++++++++++++++++       
  h_theta_CTF.SetLineColor(kBlue);
  h_theta_CTF.SetLineWidth(3); 
  h_theta_CTF.SetTitle("#theta Distribution");
  h_theta_CTF.SetXTitle("Track #theta (rad)");
  h_theta_CTF.SetYTitle("Tracks (#)");
  h_theta_CTF.Draw();
  h_theta_CTF.GetXaxis()->SetLabelSize(0.05);
  h_theta_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_theta_CTF.GetYaxis()->SetLabelSize(0.05);
  h_theta_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_theta_CosmicTF.SetLineColor(kRed);
  h_theta_CosmicTF.SetLineWidth(3); 
  h_theta_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SetGrid();    
  c.SaveAs("theta.png");
  c.SaveAs("theta.C");  
  c.Clear();      
  gSystem->Exec("mv theta.png Kinematical_Plots");
  gSystem->Exec("mv theta.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------  
  
  //+++++++++++++++++++++++++++++++       phi Distribution      ++++++++++++++++++++++++++++++++++++++++      
  h_phi_CTF.SetLineColor(kBlue);
  h_phi_CTF.SetLineWidth(3); 
  h_phi_CTF.SetTitle("#phi distribution");
  h_phi_CTF.SetXTitle("Track #phi (rad)");
  h_phi_CTF.SetYTitle("Tracks (#)");
  h_phi_CTF.Draw();
  h_phi_CTF.GetXaxis()->SetLabelSize(0.05);
  h_phi_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_phi_CTF.GetYaxis()->SetLabelSize(0.05);
  h_phi_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_phi_CosmicTF.SetLineColor(kRed);
  h_phi_CosmicTF.SetLineWidth(3); 
  h_phi_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("phi.png");
  c.SaveAs("phi.C");     
  c.Clear();      
  gSystem->Exec("mv phi.png Kinematical_Plots");
  gSystem->Exec("mv phi.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------  
  
  //+++++++++++++++++++++++++++++++       d0 Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_d0_CTF.SetLineColor(kBlue);
  h_d0_CTF.SetLineWidth(3); 
  h_d0_CTF.SetTitle("d_{0} Distribution");
  h_d0_CTF.SetXTitle("Track d_{0} (cm)");
  h_d0_CTF.SetYTitle("Tracks (#)");
  h_d0_CTF.Draw();
  h_d0_CTF.GetXaxis()->SetLabelSize(0.05);
  h_d0_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_d0_CTF.GetYaxis()->SetLabelSize(0.05);
  h_d0_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_d0_CosmicTF.SetLineColor(kRed);
  h_d0_CosmicTF.SetLineWidth(3); 
  h_d0_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("d0.png");
  c.SaveAs("d0.C");     
  c.Clear();      
  gSystem->Exec("mv d0.png Kinematical_Plots");
  gSystem->Exec("mv d0.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       dz Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_dz_CTF.SetLineColor(kBlue);
  h_dz_CTF.SetLineWidth(3); 
  h_dz_CTF.SetTitle("d_{z} Distribution");
  h_dz_CTF.SetXTitle("Track d_{z} (cm)");
  h_dz_CTF.SetYTitle("Tracks (#)");
  h_dz_CTF.Draw();
  h_dz_CTF.GetXaxis()->SetLabelSize(0.05);
  h_dz_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_dz_CTF.GetYaxis()->SetLabelSize(0.05);
  h_dz_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_dz_CosmicTF.SetLineColor(kRed);
  h_dz_CosmicTF.SetLineWidth(3); 
  h_dz_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("dz.png");
  c.SaveAs("dz.C");  
  c.Clear();      
  gSystem->Exec("mv dz.png Kinematical_Plots");
  gSystem->Exec("mv dz.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

    //+++++++++++++++++++++++++++++++      Valid Hits Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsValid_CTF.SetLineColor(kBlue);
  h_nHitsValid_CTF.SetLineWidth(3); 
  h_nHitsValid_CTF.SetTitle("Valid Hits");
  h_nHitsValid_CTF.SetXTitle("Valid Hits (#)");
  h_nHitsValid_CTF.SetYTitle("Tracks (#)");
  h_nHitsValid_CTF.Draw();
  h_nHitsValid_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsValid_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsValid_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsValid_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsValid_CosmicTF.SetLineColor(kRed);
  h_nHitsValid_CosmicTF.SetLineWidth(3); 
  h_nHitsValid_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsValid.png");
  c.SaveAs("nHitsValid.C"); 
  c.Clear();
  gSystem->Exec("mv nHitsValid.png Kinematical_Plots");
  gSystem->Exec("mv nHitsValid.C Kinematical_Plots");
  
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       nHitsPIXEL Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsPIXEL_CTF.SetLineColor(kBlue);
  h_nHitsPIXEL_CTF.SetLineWidth(3); 
  h_nHitsPIXEL_CTF.SetTitle("PIXEL Hits");
  h_nHitsPIXEL_CTF.SetXTitle("Track Hits in PIXEL (#)");
  h_nHitsPIXEL_CTF.SetYTitle("Tracks (#)");
  h_nHitsPIXEL_CTF.Draw();
  h_nHitsPIXEL_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsPIXEL_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsPIXEL_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsPIXEL_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsPIXEL_CosmicTF.SetLineColor(kRed);
  h_nHitsPIXEL_CosmicTF.SetLineWidth(3); 
  h_nHitsPIXEL_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsPIXEL.png");
  c.SaveAs("nHitsPIXEL.C");
  c.Clear();      
  gSystem->Exec("mv nHitsPIXEL.png Kinematical_Plots");
  gSystem->Exec("mv nHitsPIXEL.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       nHitsBPIX Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsBPIX_CTF.SetLineColor(kBlue);
  h_nHitsBPIX_CTF.SetLineWidth(3); 
  h_nHitsBPIX_CTF.SetTitle("BPIX Hits");
  h_nHitsBPIX_CTF.SetXTitle("Track Hits in BPIX (#)");
  h_nHitsBPIX_CTF.SetYTitle("Tracks (#)");
  h_nHitsBPIX_CTF.Draw();
  h_nHitsBPIX_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsBPIX_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsBPIX_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsBPIX_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsBPIX_CosmicTF.SetLineColor(kRed);
  h_nHitsBPIX_CosmicTF.SetLineWidth(3); 
  h_nHitsBPIX_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsBPIX.png");
  c.SaveAs("nHitsBPIX.C");      
  c.Clear();      
  gSystem->Exec("mv nHitsBPIX.png Kinematical_Plots");
  gSystem->Exec("mv nHitsBPIX.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       nHitsFPIX Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsFPIX_CTF.SetLineColor(kBlue);
  h_nHitsFPIX_CTF.SetLineWidth(3); 
  h_nHitsFPIX_CTF.SetTitle("FPIX Hits");
  h_nHitsFPIX_CTF.SetXTitle("Track Hits in FPIX (#)");
  h_nHitsFPIX_CTF.SetYTitle("Tracks (#)");
  h_nHitsFPIX_CTF.Draw();
  h_nHitsFPIX_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsFPIX_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsFPIX_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsFPIX_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsFPIX_CosmicTF.SetLineColor(kRed);
  h_nHitsFPIX_CosmicTF.SetLineWidth(3); 
  h_nHitsFPIX_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsFPIX.png");
  c.SaveAs("nHitsFPIX.C"); 
  c.Clear();      
  gSystem->Exec("mv nHitsFPIX.png Kinematical_Plots");
  gSystem->Exec("mv nHitsFPIX.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

 //+++++++++++++++++++++++++++++++       nHitsTIB Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTIB_CTF.SetLineColor(kBlue);
  h_nHitsTIB_CTF.SetLineWidth(3); 
  h_nHitsTIB_CTF.SetTitle("TIB Hits");
  h_nHitsTIB_CTF.SetXTitle("Track Hits in TIB (#)");
  h_nHitsTIB_CTF.SetYTitle("Tracks (#)");
  h_nHitsTIB_CTF.Draw();
  h_nHitsTIB_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsTIB_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsTIB_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsTIB_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsTIB_CosmicTF.SetLineColor(kRed);
  h_nHitsTIB_CosmicTF.SetLineWidth(3); 
  h_nHitsTIB_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsTIB.png");
  c.SaveAs("nHitsTIB.C");     
  c.Clear();      
  gSystem->Exec("mv nHitsTIB.png Kinematical_Plots");
  gSystem->Exec("mv nHitsTIB.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

   //+++++++++++++++++++++++++++++++       nHitsTID Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTID_CTF.SetLineColor(kBlue);
  h_nHitsTID_CTF.SetLineWidth(3); 
  h_nHitsTID_CTF.SetTitle("TID Hits");
  h_nHitsTID_CTF.SetXTitle("Track Hits in TID (#)");
  h_nHitsTID_CTF.SetYTitle("Tracks (#)");
  h_nHitsTID_CTF.Draw();
  h_nHitsTID_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsTID_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsTID_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsTID_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsTID_CosmicTF.SetLineColor(kRed);
  h_nHitsTID_CosmicTF.SetLineWidth(3); 
  h_nHitsTID_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsTID.png");
  c.SaveAs("nHitsTID.C");  
  c.Clear();      
  gSystem->Exec("mv nHitsTID.png Kinematical_Plots");
  gSystem->Exec("mv nHitsTID.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       nHitsTOB Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTOB_CTF.SetLineColor(kBlue);
  h_nHitsTOB_CTF.SetLineWidth(3); 
  h_nHitsTOB_CTF.SetTitle("TOB Hits");
  h_nHitsTOB_CTF.SetXTitle("Track Hits in TOB (#)");
  h_nHitsTOB_CTF.SetYTitle("Tracks (#)");
  h_nHitsTOB_CTF.Draw();
  h_nHitsTOB_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsTOB_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsTOB_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsTOB_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsTOB_CosmicTF.SetLineColor(kRed);
  h_nHitsTOB_CosmicTF.SetLineWidth(3); 
  h_nHitsTOB_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsTOB.png");
  c.SaveAs("nHitsTOB.C");  
  c.Clear();      
  gSystem->Exec("mv nHitsTOB.png Kinematical_Plots");
  gSystem->Exec("mv nHitsTOB.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       nHitsTEC Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTEC_CTF.SetLineColor(kBlue);
  h_nHitsTEC_CTF.SetLineWidth(3); 
  h_nHitsTEC_CTF.SetTitle("TEC Hits");
  h_nHitsTEC_CTF.SetXTitle("Track Hits in TEC (#)");
  h_nHitsTEC_CTF.SetYTitle("Tracks (#)");
  h_nHitsTEC_CTF.Draw();
  h_nHitsTEC_CTF.GetXaxis()->SetLabelSize(0.05);
  h_nHitsTEC_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_nHitsTEC_CTF.GetYaxis()->SetLabelSize(0.05);
  h_nHitsTEC_CTF.GetYaxis()->SetTitleSize(0.05);
  
  h_nHitsTEC_CosmicTF.SetLineColor(kRed);
  h_nHitsTEC_CosmicTF.SetLineWidth(3); 
  h_nHitsTEC_CosmicTF.Draw("SAME");

  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("nHitsTEC.png");
  c.SaveAs("nHitsTEC.C");     
  c.Clear();      
  gSystem->Exec("mv nHitsTEC.png Kinematical_Plots");
  gSystem->Exec("mv nHitsTEC.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

    //+++++++++++++++++++++++++++++++       Delta pt     ++++++++++++++++++++++++++++++++++++++++     
  h_delta_pt.SetLineColor(kOrange-3);
  h_delta_pt.SetLineWidth(3); 
  h_delta_pt.SetTitle("#Delta p_{T}");
  h_delta_pt.SetXTitle("#Delta p_{T} (GeV)");
  h_delta_pt.SetYTitle("Tracks (#)");
  h_delta_pt.Draw();
  h_delta_pt.GetXaxis()->SetLabelSize(0.05);
  h_delta_pt.GetXaxis()->SetTitleSize(0.05); 
  h_delta_pt.GetYaxis()->SetLabelSize(0.05);
  h_delta_pt.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("deltaPt.png");
  c.SaveAs("deltaPt.C");      
  c.Clear();      
  gSystem->Exec("mv deltaPt.png Kinematical_Plots");
  gSystem->Exec("mv deltaPt.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta eta     ++++++++++++++++++++++++++++++++++++++++     
  h_delta_eta.SetLineColor(kOrange-3);
  h_delta_eta.SetLineWidth(3); 
  h_delta_eta.SetTitle("#Delta #eta");
  h_delta_eta.SetXTitle("#Delta#eta_{Track}");
  h_delta_eta.SetYTitle("Tracks (#)");
  h_delta_eta.Draw();
  h_delta_eta.GetXaxis()->SetLabelSize(0.05);
  h_delta_eta.GetXaxis()->SetTitleSize(0.05); 
  h_delta_eta.GetYaxis()->SetLabelSize(0.05);
  h_delta_eta.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("deltaEta.png");
  c.SaveAs("deltaEta.C");   
  c.Clear();      
  gSystem->Exec("mv deltaEta.png Kinematical_Plots");
  gSystem->Exec("mv deltaEta.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta phi     ++++++++++++++++++++++++++++++++++++++++     
  h_delta_phi.SetLineColor(kOrange-3);
  h_delta_phi.SetLineWidth(3); 
  h_delta_phi.SetTitle("#Delta#phi");
  h_delta_phi.SetXTitle("#Delta#phi_{Track} (rad)");
  h_delta_phi.SetYTitle("Tracks (#)");
  h_delta_phi.Draw();
  h_delta_phi.GetXaxis()->SetLabelSize(0.05);
  h_delta_phi.GetXaxis()->SetTitleSize(0.05); 
  h_delta_phi.GetYaxis()->SetLabelSize(0.05);
  h_delta_phi.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("deltaPhi.png");
  c.SaveAs("deltaPhi.C");  
  c.Clear();      
  gSystem->Exec("mv deltaPhi.png Kinematical_Plots");
  gSystem->Exec("mv deltaPhi.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta pt By Pt_CosmicTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaPtByPtCosmicTF.SetLineColor(kOrange-3);
  h_deltaPtByPtCosmicTF.SetLineWidth(3); 
  h_deltaPtByPtCosmicTF.SetTitle("#Deltap_{T} /p_{T}");
  h_deltaPtByPtCosmicTF.SetXTitle("#Deltap_{T}/p_{T CosmicTF}");
  h_deltaPtByPtCosmicTF.SetYTitle("Tracks (#)");
  h_deltaPtByPtCosmicTF.Draw();
  h_deltaPtByPtCosmicTF.GetXaxis()->SetLabelSize(0.05);
  h_deltaPtByPtCosmicTF.GetXaxis()->SetTitleSize(0.05); 
  h_deltaPtByPtCosmicTF.GetYaxis()->SetLabelSize(0.05);
  h_deltaPtByPtCosmicTF.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
 
  c.SaveAs("deltaPtByPtCosmicTF.png");
  c.SaveAs("deltaPtByPtCosmicTF.C");   
  c.Clear();      
  gSystem->Exec("mv deltaPtByPtCosmicTF.png Kinematical_Plots");
  gSystem->Exec("mv deltaPtByPtCosmicTF.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta pt By Pt_CTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaPtByPtCTF.SetLineColor(kOrange-3);
  h_deltaPtByPtCTF.SetLineWidth(3); 
  h_deltaPtByPtCTF.SetTitle("#Deltap_{T}/p_{T}");
  h_deltaPtByPtCTF.SetXTitle("#Deltap_{T} /p_{T CTF}");
  h_deltaPtByPtCTF.SetYTitle("Tracks (#)");
  h_deltaPtByPtCTF.Draw();
  h_deltaPtByPtCTF.GetXaxis()->SetLabelSize(0.05);
  h_deltaPtByPtCTF.GetXaxis()->SetTitleSize(0.05); 
  h_deltaPtByPtCTF.GetYaxis()->SetLabelSize(0.05);
  h_deltaPtByPtCTF.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
 
  c.SaveAs("deltaPtByPtCTF.png");
  c.SaveAs("deltaPtByPtCTF.C");    
  c.Clear();      
  gSystem->Exec("mv deltaPtByPtCTF.png Kinematical_Plots");
  gSystem->Exec("mv deltaPtByPtCTF.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta eta By eta_CTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaEtaByEtaCTF.SetLineColor(kOrange-3);
  h_deltaEtaByEtaCTF.SetLineWidth(3); 
  h_deltaEtaByEtaCTF.SetTitle("#Delta#eta/#eta_{CTF}");
  h_deltaEtaByEtaCTF.SetXTitle("#Delta#eta/#eta_{CTF}");
  h_deltaEtaByEtaCTF.SetYTitle("Tracks (#)");
  h_deltaEtaByEtaCTF.Draw();
  h_deltaEtaByEtaCTF.GetXaxis()->SetLabelSize(0.05);
  h_deltaEtaByEtaCTF.GetXaxis()->SetTitleSize(0.05); 
  h_deltaEtaByEtaCTF.GetYaxis()->SetLabelSize(0.05);
  h_deltaEtaByEtaCTF.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("deltaEtaByEtaCTF.png");
  c.SaveAs("deltaEtaByEtaCTF.C");     
  c.Clear();      
  gSystem->Exec("mv deltaEtaByEtaCTF.png Kinematical_Plots");
  gSystem->Exec("mv deltaEtaByEtaCTF.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta eta By eta_CosmicTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaEtaByEtaCosmicTF.SetLineColor(kOrange-3);
  h_deltaEtaByEtaCosmicTF.SetLineWidth(3); 
  h_deltaEtaByEtaCosmicTF.SetTitle("#Delta#eta /#eta_{CosmicTF}");
  h_deltaEtaByEtaCosmicTF.SetXTitle("#Delta#eta /#eta_{CosmicTF}");
  h_deltaEtaByEtaCosmicTF.SetYTitle("Tracks (#)");
  h_deltaEtaByEtaCosmicTF.Draw();
  h_deltaEtaByEtaCosmicTF.GetXaxis()->SetLabelSize(0.05);
  h_deltaEtaByEtaCosmicTF.GetXaxis()->SetTitleSize(0.05); 
  h_deltaEtaByEtaCosmicTF.GetYaxis()->SetLabelSize(0.05);
  h_deltaEtaByEtaCosmicTF.GetYaxis()->SetTitleSize(0.05);

  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  
  c.SaveAs("deltaEtaByEtaCosmicTF.png");
  c.SaveAs("deltaEtaByEtaCosmicTF.C");     
  c.Clear();      
  gSystem->Exec("mv deltaEtaByEtaCosmicTF.png Kinematical_Plots");
  gSystem->Exec("mv deltaEtaByEtaCosmicTF.C Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
}


