using namespace ROOT::VecOps;

void CheckdeltaR()
{

  // TString Allfiles[3] = {"Cosmic_rate_tuple1.root","Cosmic_rate_tuple2.root","Cosmic_rate_tuple3.root"};
  TFile *file1 = new TFile("CTF_2018.root");
  TFile *file2 = new TFile("CosmicTF_2018.root");

  FILE *pFile, *OpFile;
  pFile = fopen("CheckDeltaR.csv","w");
  OpFile = fopen("OpFile.csv","w");
  
  TTree *tree1, *tree2;
  tree1 = (TTree*)file1->Get("cosmicRateAnalyzer/Event");
  tree2 = (TTree*)file2->Get("cosmicRateAnalyzer/Event");

  //========================Local varibles to store parameters from tree===================//
  vector<double>  *pt_CTF;
  vector<double>  *charge_CTF;
  vector<double>  *chi2_CTF;
  vector<double>  *chi2_ndof_CTF;
  vector<double>  *eta_CTF;
  vector<double>  *theta_CTF;
  vector<double>  *phi_CTF;
  vector<double>  *p_CTF;
  vector<double>  *d0_CTF;
  vector<double>  *dz_CTF;
  pt_CTF=0; charge_CTF=0; chi2_CTF=0; chi2_ndof_CTF=0; eta_CTF=0; theta_CTF=0; phi_CTF=0; p_CTF=0; d0_CTF=0; dz_CTF=0;
 
  //=======tree2======//
  vector<double>  *pt_CosmicTF;
  vector<double>  *charge_CosmicTF;
  vector<double>  *chi2_CosmicTF;
  vector<double>  *chi2_ndof_CosmicTF;
  vector<double>  *eta_CosmicTF;
  vector<double>  *theta_CosmicTF;
  vector<double>  *phi_CosmicTF;
  vector<double>  *p_CosmicTF;
  vector<double>  *d0_CosmicTF;
  vector<double>  *dz_CosmicTF;
  pt_CosmicTF=0; charge_CosmicTF=0; chi2_CosmicTF=0; chi2_ndof_CosmicTF=0; eta_CosmicTF=0; theta_CosmicTF=0; phi_CosmicTF=0; p_CosmicTF=0; d0_CosmicTF=0; dz_CosmicTF=0;
  
  //=======RVec Definition=======//
  RVec<double> eta1,eta2,phi1,phi2,TempDeltaR;

  //==============================Setting tree branches to local varibles================//
  tree1->SetBranchAddress("pt", &pt_CTF);
  tree1->SetBranchAddress("charge", &charge_CTF);
  tree1->SetBranchAddress("chi2", &chi2_CTF);
  tree1->SetBranchAddress("chi2_ndof", &chi2_ndof_CTF);
  tree1->SetBranchAddress("eta", &eta_CTF);
  tree1->SetBranchAddress("theta", &theta_CTF);
  tree1->SetBranchAddress("phi", &phi_CTF);
  tree1->SetBranchAddress("p", &p_CTF);
  tree1->SetBranchAddress("d0", &d0_CTF);
  tree1->SetBranchAddress("dz", &dz_CTF);
  
  tree2->SetBranchAddress("pt", &pt_CosmicTF);
  tree2->SetBranchAddress("charge", &charge_CosmicTF);
  tree2->SetBranchAddress("chi2", &chi2_CosmicTF);
  tree2->SetBranchAddress("chi2_ndof", &chi2_ndof_CosmicTF);
  tree2->SetBranchAddress("eta", &eta_CosmicTF);
  tree2->SetBranchAddress("theta", &theta_CosmicTF);
  tree2->SetBranchAddress("phi", &phi_CosmicTF);
  tree2->SetBranchAddress("p", &p_CosmicTF);
  tree2->SetBranchAddress("d0", &d0_CosmicTF);
  tree2->SetBranchAddress("dz", &dz_CosmicTF);
   
  //===========================Variables to check loss of events and keep track of code======================//
  int nEvents_NotHavingTracksInBothCollections=0, nTracks_NotMatchingDeltaRCut=0, nTracks_NotHavingSameCharge=0;

  //===============Defining histograms for filling================//
  TH1D h_pt_CTF 		("h_pt_CTF","h_pt",200,0,200);
  TH1D h_charge_CTF 	        ("h_charge_CTF","h_charge",10,-5,5);
  TH1D h_chi2_CTF 		("h_chi2_CTF","h_chi2",200,0,100);
  TH1D h_chi2_ndof_CTF    	("h_chi2_ndof_CTF","h_chi2_ndof",200,0,20);
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

  /* h_Delta_pt h_Delta_eta h_Delta_phi h_Delta_d0 h_Delta_dz
 
TH1D h_deltaPtByPtCosmiTF
   h_DeltaEtaByEtaCosmicTF
h_DeltaPhiByPhi

   */

  //----------Loop for Track matching: At the end of this loopthe events no, trackCTF ,trackCosmicTF will be stored in vectors--------------
  std::vector<Long64_t> Idx_Event;
  std::vector<int> Idx_Track_CosmicTF, Idx_Track_CTF;
  Idx_Event.clear(); Idx_Track_CosmicTF.clear(); Idx_Track_CTF.clear();

  fprintf(pFile," , , %s, %s, %s ,%s, %s, %s \n","CosmicTF","CTF","DeltaR","DeltaPt","DeltaPhi","DeltaEta");
  
  Long64_t n1 = tree1->GetEntriesFast();
  for (Long64_t jentry=0; jentry<100; jentry++) //Event Loop
    {
      tree1->GetEntry(jentry); //Get first Event of tree 1
      tree2->GetEntry(jentry);

      fprintf(pFile,"Event %lli , , %zu Tracks, %zu Tracks, , , , \n",jentry, phi_CosmicTF->size(), phi_CTF->size());
      
      //Matching a track in CosmicTF with a track in CTF (Tracks in CTF>Tracks in CosmicTF always!!)
      if(! (phi_CosmicTF->size()>0 && phi_CTF->size()>0) )
	{
	  nEvents_NotHavingTracksInBothCollections++;
	  fprintf(pFile,",%s , , , , , , \n","Not Tracks in Both");
	  continue;
	}  //CHeck if ytheres atleast 1 track in both collections

      fprintf(pFile,",%s , , , , , , \n","Tracks in Both");

      for (int i = 0; i < phi_CosmicTF->size() ; i++)  	//Track Loop CosmicTF
      {
	eta1.clear();
	phi1.clear();
	eta1.push_back(eta_CosmicTF->at(i));
	phi1.push_back(phi_CosmicTF->at(i));

	TempDeltaR.clear();      	
	for(int j = 0; j < phi_CTF->size() ; j++)  // Track Loop CTF
	  {
	    eta2.clear();
	    phi2.clear();
	    if( !(charge_CosmicTF->at(i)*charge_CTF->at(j)>0) )
	      {
		nTracks_NotHavingSameCharge++;
		fprintf(pFile,", %s, %f, %f, , , , \n","Not same charge", charge_CosmicTF->at(i), charge_CTF->at(j));
		continue;
	      }
            
	    fprintf(pFile,", %s, %f, %f, , , , \n","Same charge", charge_CosmicTF->at(i), charge_CTF->at(j));
	    
	    eta2.push_back(eta_CTF->at(j));
	    phi2.push_back(phi_CTF->at(j));
	    
	    TempDeltaR.push_back(DeltaR(eta1,eta2,phi1,phi2)[0]);
	    fprintf(pFile,", Track (%i-%i), , ,%f ,%f ,%f ,%f \n", i, j, DeltaR(eta1,eta2,phi1,phi2)[0], pt_CosmicTF->at(i)-pt_CTF->at(j),
		                                                             eta_CosmicTF->at(i)-eta_CTF->at(j), phi_CosmicTF->at(i)-phi_CTF->at(j) );    	    	    
	  }   //CTF Track Loop j

        float min=Min(TempDeltaR);// Check Cleaing Temp 
	fprintf(pFile,", , Min DeltaR for Track %i in Cosmic TF, %f, , , , \n", i, min);
      	if(min>0.4) 
	  { 
	    //nTracks_NotMatchingDeltaRCut++;
	    fprintf(pFile,", %s, %s, , , , , \n", "Rejected", "MinDeltaR>0.4");
	    continue;
	  }

	std::cout<<"Event with R<0.4 :"<<jentry<<std::endl;
	std::cout<<"CosmicTF Index : "<<i<<std::endl;
	std::cout<<"CTF Index : "<<ArgMin(TempDeltaR)<<std::endl;
	
	if (std::find(Idx_Event.begin(), Idx_Event.end(), jentry) != Idx_Event.end())
	  { std::cout << "Event %i exists"<<jentry<<std::endl; }
	else
	  { std::cout << "Event %i added"<<jentry<<std::endl; 
	      Idx_Event.push_back(jentry);
	  }    
	Idx_Track_CosmicTF.push_back(i);
	Idx_Track_CTF.push_back(ArgMin(TempDeltaR));
      }// CosmicTF track Loop i	
      
    }// Event Loop for Getting Events having matching tracks with deltaR<0.4
  fclose(pFile);
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  PLOTTING  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
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

  //==========Event Loop for Drawing Histograms and Storing=================//
  fprintf(OpFile,"%s ,%s ,%s ,%s ,%s ,%s \n","Event No.","CosmicTF Track Idx.", "CTF Track Idx", "Delta_pt", "Delta_eta", "Delta_phi");
  
  Long64_t n2 = tree1->GetEntriesFast();
  std::cout<<" Idx_Event Size"<<Idx_Event.size()<<std::endl;
  for (Long64_t jentry=0; jentry<Idx_Event.size(); jentry++) 
    {
      //std::cout<<" Idx_Event"<<Idx_Event.at(jentry)<<std::endl;
      //std::cout<<" Idx Track CosmicTF"<<Idx_Track_CosmicTF.at(jentry)<<std::endl;
      //std::cout<<" Idx Track CTF"<<Idx_Track_CTF.at(jentry)<<std::endl;
      tree1->GetEntry(Idx_Event.at(jentry)); //Get first Event of tree 1
      tree2->GetEntry(Idx_Event.at(jentry));
      
      h_pt_CosmicTF.Fill(pt_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_charge_CosmicTF.Fill(charge_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_chi2_CosmicTF.Fill(chi2_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_chi2_ndof_CosmicTF.Fill(chi2_ndof_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_eta_CosmicTF.Fill(eta_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_theta_CosmicTF.Fill(theta_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_phi_CosmicTF.Fill(phi_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_d0_CosmicTF.Fill(d0_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      h_dz_CosmicTF.Fill(dz_CosmicTF->at(Idx_Track_CosmicTF.at(jentry)));
      
      h_pt_CTF.Fill(pt_CTF->at(Idx_Track_CTF.at(jentry)));
      h_charge_CTF.Fill(charge_CTF->at(Idx_Track_CTF.at(jentry)));
      h_chi2_CTF.Fill(chi2_CTF->at(Idx_Track_CTF.at(jentry)));
      h_chi2_ndof_CTF.Fill(chi2_ndof_CTF->at(Idx_Track_CTF.at(jentry)));
      h_eta_CTF.Fill(eta_CTF->at(Idx_Track_CTF.at(jentry)));
      h_theta_CTF.Fill(theta_CTF->at(Idx_Track_CTF.at(jentry)));
      h_phi_CTF.Fill(phi_CTF->at(Idx_Track_CTF.at(jentry)));
      h_d0_CTF.Fill(d0_CTF->at(Idx_Track_CTF.at(jentry)));
      h_dz_CTF.Fill(dz_CTF->at(Idx_Track_CTF.at(jentry)));
      
      fprintf(OpFile,"%lld ,%i ,%i ,%f ,%f ,%f \n", Idx_Event.at(jentry), Idx_Track_CosmicTF.at(jentry), Idx_Track_CTF.at(jentry),
	       pt_CosmicTF->at(Idx_Track_CosmicTF.at(jentry))- pt_CTF->at(Idx_Track_CTF.at(jentry) ),
	       eta_CosmicTF->at(Idx_Track_CosmicTF.at(jentry))-eta_CTF->at(Idx_Track_CTF.at(jentry) ),
	       phi_CosmicTF->at(Idx_Track_CosmicTF.at(jentry))-phi_CTF->at(Idx_Track_CTF.at(jentry) )
	      );
     
    }  

  Idx_Event.clear();
  Idx_Track_CosmicTF.clear();
  Idx_Track_CTF.clear();
  fclose(OpFile);
  
  gSystem->Exec("mkdir -p Kinematical_Plots");
  //+++++++++++++++++++++++++++++++       pT Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_pt_CTF.SetLineColor(kBlue);
  h_pt_CTF.SetLineWidth(3);
  h_pt_CTF.SetTitle("p_{T} Distribution");
  h_pt_CTF.SetXTitle("p_{T} (GeV)");
  h_pt_CTF.Draw();
  
  h_pt_CosmicTF.SetLineColor(kRed);
  h_pt_CosmicTF.SetLineWidth(3);
  h_pt_CosmicTF.SetTitle("p_{T} Distribution");
  h_pt_CosmicTF.SetXTitle("p_{T} (GeV)");
  h_pt_CosmicTF.Draw("SAME");
  
  c.SaveAs("pt.png");
  c.Clear();
  gSystem->Exec("mv pt.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       charge Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_charge_CTF.SetLineColor(kBlue);
  h_charge_CTF.SetLineWidth(3);
  h_charge_CTF.SetTitle("Charge (e)");
  h_charge_CTF.SetXTitle("");
  h_charge_CTF.Draw();
  
  h_charge_CosmicTF.SetLineColor(kRed);
  h_charge_CosmicTF.SetLineWidth(3);
  h_charge_CosmicTF.SetTitle("Charge (e)");
  h_charge_CosmicTF.SetXTitle("");
  h_charge_CosmicTF.Draw("SAME");
  
  c.SaveAs("charge.png");
  c.Clear();
  gSystem->Exec("mv charge.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       chi2 Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_chi2_CTF.SetLineColor(kBlue);
  h_chi2_CTF.SetLineWidth(3); 
  h_chi2_CTF.SetTitle("#chi^{2} Distribution");
  h_chi2_CTF.SetXTitle("#chi^{2}");
  h_chi2_CTF.Draw();
  
  h_chi2_CosmicTF.SetLineColor(kRed);
  h_chi2_CosmicTF.SetLineWidth(3); 
  h_chi2_CosmicTF.SetTitle("#chi^{2} Distribution");
  h_chi2_CosmicTF.SetXTitle("#chi^{2}");
  h_chi2_CosmicTF.Draw("SAME");
  c.SaveAs("chi2.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv chi2.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       chi2/ndof Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_chi2_ndof_CTF.SetLineColor(kBlue);
  h_chi2_ndof_CTF.SetLineWidth(3); 
  h_chi2_ndof_CTF.SetTitle("#chi^{2} per NDF");
  h_chi2_ndof_CTF.SetXTitle("#chi^{2} NDF");
  h_chi2_ndof_CTF.Draw();
  
  h_chi2_ndof_CosmicTF.SetLineColor(kRed);
  h_chi2_ndof_CosmicTF.SetLineWidth(3); 
  h_chi2_ndof_CosmicTF.SetTitle("#chi^{2} per NDF");
  h_chi2_ndof_CosmicTF.SetXTitle("#chi^{2} NDF");
  h_chi2_ndof_CosmicTF.Draw("SAME");
  
  c.SaveAs("chi2_ndof.png");                                                                                                                 
  c.Clear();
  gSystem->Exec("mv chi2_ndof.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       eta Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_eta_CTF.SetLineColor(kBlue);
  h_eta_CTF.SetLineWidth(3); 
  h_eta_CTF.SetTitle("#eta Distribution");
  h_eta_CTF.SetXTitle("#eta");
  h_eta_CTF.Draw();
  
  h_eta_CosmicTF.SetLineColor(kRed);
  h_eta_CosmicTF.SetLineWidth(3); 
  h_eta_CosmicTF.SetTitle("#eta Distribution");
  h_eta_CosmicTF.SetXTitle("#eta");
  h_eta_CosmicTF.Draw("SAME");
  
  c.SaveAs("eta.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv eta.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       theta Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_theta_CTF.SetLineColor(kBlue);
  h_theta_CTF.SetLineWidth(3); 
  h_theta_CTF.SetTitle("#theta Distribution");
  h_theta_CTF.SetXTitle("#theta (rad)");
  h_theta_CTF.Draw();
  
  h_theta_CosmicTF.SetLineColor(kRed);
  h_theta_CosmicTF.SetLineWidth(3); 
  h_theta_CosmicTF.SetTitle("#theta Distribution");
  h_theta_CosmicTF.SetXTitle("#theta (rad)");
  h_theta_CosmicTF.Draw("SAME");
  
  c.SetGrid();    
  c.SaveAs("theta.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv theta.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       phi Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_phi_CTF.SetLineColor(kBlue);
  h_phi_CTF.SetLineWidth(3); 
  h_phi_CTF.SetTitle("#phi distribution");
  h_phi_CTF.SetXTitle("#phi (rad)");
  h_phi_CTF.Draw();
  
  h_phi_CosmicTF.SetLineColor(kRed);
  h_phi_CosmicTF.SetLineWidth(3); 
  h_phi_CosmicTF.SetTitle("#phi distribution");
  h_phi_CosmicTF.SetXTitle("#phi (rad)");
  h_phi_CosmicTF.Draw("SAME");
  
  c.SaveAs("phi.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv phi.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       d0 Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_d0_CTF.SetLineColor(kBlue);
  h_d0_CTF.SetLineWidth(3); 
  h_d0_CTF.SetTitle("d_{0} Distribution");
  h_d0_CTF.SetXTitle("d_{0}");
  h_d0_CTF.Draw();
  
  h_d0_CosmicTF.SetLineColor(kRed);
  h_d0_CosmicTF.SetLineWidth(3); 
  h_d0_CosmicTF.SetTitle("d_{0} Distribution");
  h_d0_CosmicTF.SetXTitle("d_{0}");
  h_d0_CosmicTF.Draw("SAME");                      
  
  c.SaveAs("d0.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv d0.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
  //+++++++++++++++++++++++++++++++       dz Distribution      ++++++++++++++++++++++++++++++++++++++++     
  
  h_dz_CTF.SetLineColor(kBlue);
  h_dz_CTF.SetLineWidth(3); 
  h_dz_CTF.SetTitle("d_{z} Distribution");
  h_dz_CTF.SetXTitle("dz");
  h_dz_CTF.Draw();
  
  h_dz_CosmicTF.SetLineColor(kRed);
  h_dz_CosmicTF.SetLineWidth(3); 
  h_dz_CosmicTF.SetTitle("d_{z} Distribution");
  h_dz_CosmicTF.SetXTitle("dz");
  h_dz_CosmicTF.Draw("SAME");
  
  c.SaveAs("dz.png");                                                                                                                  
  c.Close();      
  gSystem->Exec("mv dz.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  
}
