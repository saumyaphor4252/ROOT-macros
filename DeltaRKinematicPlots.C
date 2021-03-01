using namespace ROOT::VecOps;

void DeltaRKinematicPlots()
{

  TFile *file1 = new TFile("CTF_Residuals.root");
  TFile *file2 = new TFile("CosmicTF_Residuals.root");

  FILE *pFile, *OpFile, *DeltaREventIndices;
  pFile = fopen("CheckDeltaR.csv","w"); // Information about events passing the cut of DeltaR, charge, matching 
  DeltaREventIndices = fopen("DeltaREventIndices.csv","w");  //File having Indivces of selected events, and matching track indices
  OpFile = fopen("OpFile.csv","w");  // INformation about events passing the cuts and used for plotting 
    
  TTree *tree1, *tree2;
  // tree1 = (TTree*)file1->Get("cosmicRateAnalyzer/Event");
  // tree2 = (TTree*)file2->Get("cosmicRateAnalyzer/Event");
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
  /*  vector<double>  *p_CTF;
  vector<double>  *px_CTF;
  vector<double>  *py_CTF;
   vector<double>  *pz_CTF;
  */vector<double>  *d0_CTF;
  vector<double>  *dz_CTF;
  vector<int>  *nHitsValid_CTF;
  vector<int>  *nHitsPIXEL_CTF;
  vector<int>  *nHitsBPIX_CTF;
  vector<int>  *nHitsFPIX_CTF;
  vector<int>  *nHitsTIB_CTF;
  vector<int>  *nHitsTID_CTF;
  vector<int>  *nHitsTOB_CTF;
  vector<int>  *nHitsTEC_CTF;
  
  pt_CTF=0; charge_CTF=0; chi2_CTF=0; chi2_ndof_CTF=0; eta_CTF=0; theta_CTF=0; phi_CTF=0; //p_CTF=0; px_CTF=0; py_CTF=0; pz_CTF=0;
  d0_CTF=0; dz_CTF=0;
  nHitsValid_CTF=0; nHitsPIXEL_CTF=0; nHitsBPIX_CTF=0;  nHitsFPIX_CTF=0;  nHitsTIB_CTF=0;  nHitsTID_CTF=0;  nHitsTOB_CTF=0;  nHitsTEC_CTF=0;

  //=======tree2======//
  vector<double>  *pt_CosmicTF;
  vector<double>  *charge_CosmicTF;
  vector<double>  *chi2_CosmicTF;
  vector<double>  *chi2_ndof_CosmicTF;
  vector<double>  *eta_CosmicTF;
  vector<double>  *theta_CosmicTF;
  vector<double>  *phi_CosmicTF;
  /*  vector<double>  *p_CosmicTF;
  vector<double>  *px_CosmicTF;
  vector<double>  *py_CosmicTF;
  vector<double>  *pz_CosmicTF;
  */ vector<double>  *d0_CosmicTF;
  vector<double>  *dz_CosmicTF;
  vector<int>  *nHitsValid_CosmicTF;
  vector<int>  *nHitsPIXEL_CosmicTF;
  vector<int>  *nHitsBPIX_CosmicTF;
  vector<int>  *nHitsFPIX_CosmicTF;
  vector<int>  *nHitsTIB_CosmicTF;
  vector<int>  *nHitsTOB_CosmicTF;
  vector<int>  *nHitsTID_CosmicTF;
  vector<int>  *nHitsTEC_CosmicTF;
  pt_CosmicTF=0; charge_CosmicTF=0; chi2_CosmicTF=0; chi2_ndof_CosmicTF=0; eta_CosmicTF=0; theta_CosmicTF=0; phi_CosmicTF=0; //p_CosmicTF=0; px_CosmicTF=0; py_CosmicTF=0; pz_CosmicTF=0;
  d0_CosmicTF=0; dz_CosmicTF=0;
  nHitsValid_CosmicTF=0; nHitsPIXEL_CosmicTF=0; nHitsBPIX_CosmicTF=0;  nHitsFPIX_CosmicTF=0;  nHitsTIB_CosmicTF=0;  nHitsTID_CosmicTF=0;  nHitsTOB_CosmicTF=0;  nHitsTEC_CosmicTF=0;
  
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
  /*  tree1->SetBranchAddress("p", &p_CTF);
  tree1->SetBranchAddress("px", &px_CTF);
  tree1->SetBranchAddress("py", &py_CTF);
  tree1->SetBranchAddress("pz", &pz_CTF);*/
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
  /*  tree2->SetBranchAddress("p", &p_CosmicTF);
  tree2->SetBranchAddress("px", &px_CosmicTF);
  tree2->SetBranchAddress("py", &py_CosmicTF);
  tree2->SetBranchAddress("pz", &pz_CosmicTF);*/
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
   
  //===========================Variables to check loss of events and keep track of code======================//
  int nEvents_NotHavingTracksInBothCollections=0, nTracks_NotMatchingDeltaRCut=0, nTracks_NotHavingSameCharge=0;

  //----------Loop for Track matching: At the end of this loop the events no, trackCTF ,trackCosmicTF will be stored in a csv file "DeltaREventIndices":--------------
  fprintf(pFile," , , %s, %s, %s ,%s, %s, %s \n","CosmicTF","CTF","DeltaR","DeltaPt","DeltaPhi","DeltaEta");
  
  Long64_t n1 = tree1->GetEntriesFast();
  Long64_t n2 = tree2->GetEntriesFast();
  std::cout<<"Events :"<<n1<<std::endl;
  std::cout<<"Events :"<<n1<<std::endl;
  for (int jentry=0; jentry<100000; jentry++) //Event Loop
    {

      if((jentry%50000)==0)
	{std::cout<<"For loop 1, Analysing event: "<<jentry<<std::endl;}
      
      tree1->GetEntry(jentry); //Get first Event of tree 1
      tree2->GetEntry(jentry);

      fprintf(pFile,"Event %i , , %zu Tracks, %zu Tracks, , , , \n",jentry, phi_CosmicTF->size(), phi_CTF->size());
      
      //xxxxxxxxxxxxxxxxxxxx---Matching a track in CosmicTF with a track in CTF (Tracks in CTF>Tracks in CosmicTF always!!)---xxxxxxxxxxxxxxxxxxxxxx//
      //Check if theres atleast 1 track in both collections
      if(! (phi_CosmicTF->size()>0 && phi_CTF->size()>0) )
	{
	  nEvents_NotHavingTracksInBothCollections++;
	  fprintf(pFile,",%s , , , , , , \n","Not Tracks in Both");
	  continue;
	} 
      fprintf(pFile,",%s , , , , , , \n","Tracks in Both");

      //Looping over CosmicTF
      for (int i = 0; i < phi_CosmicTF->size() ; i++)  	//Track Loop CosmicTF
      {
	eta1.clear();
	phi1.clear();
	eta1.push_back(eta_CosmicTF->at(i));
	phi1.push_back(phi_CosmicTF->at(i));

	//Looping over CTF to find a match for track in CosmicTF Track
	TempDeltaR.clear();      	
	for(int j = 0; j < phi_CTF->size() ; j++)  // Track Loop CTF
	  {
	    eta2.clear();
	    phi2.clear();
	    //Check if charge is same for tracks
	    if( !(charge_CosmicTF->at(i)*charge_CTF->at(j)>0) )
	      {
		nTracks_NotHavingSameCharge++;
		fprintf(pFile,", %s, %f, %f, , , , \n","Not same charge", charge_CosmicTF->at(i), charge_CTF->at(j));
		continue;
	      }            
	    fprintf(pFile,", %s, %f, %f, , , , \n","Same charge", charge_CosmicTF->at(i), charge_CTF->at(j));
	    
	    eta2.push_back(eta_CTF->at(j));
	    phi2.push_back(phi_CTF->at(j));

	    //Evaluate DeltaR for a gicen pair of CTF & CosmicTF and store in a temprory vector TempDEltaR
	    TempDeltaR.push_back(DeltaR(eta1,eta2,phi1,phi2)[0]);
	    fprintf(pFile,", Track (%i-%i), , ,%f ,%f ,%f ,%f \n", i, j, DeltaR(eta1,eta2,phi1,phi2)[0], pt_CosmicTF->at(i)-pt_CTF->at(j),
		                                                             eta_CosmicTF->at(i)-eta_CTF->at(j), phi_CosmicTF->at(i)-phi_CTF->at(j) );    	    	    
	  }   //CTF Track Loop j

	//Find Min DeltaR for the CosmicTF track 
        float min=Min(TempDeltaR);
	fprintf(pFile,", , Min DeltaR for Track %i in Cosmic TF, %f, , , , \n", i, min);
      	if(min>0.4) // Delta R cut 
	  { 
	    //nTracks_NotMatchingDeltaRCut++;
	    fprintf(pFile,", %s, %s, , , , , \n", "Rejected", "MinDeltaR>0.4");
	    continue;
	  }
	//std::cout<<"Event with R<0.4 :"<<jentry<<std::endl;
	//std::cout<<"CosmicTF Index : "<<i<<std::endl;
	//std::cout<<"CTF Index : "<<ArgMin(TempDeltaR)<<std::endl;

	//Storing indices for Events, CosmicTF Track and CTF Track matched in vectors Idx 
	//	if (std::find(Idx_Event.begin(), Idx_Event.end(), jentry) != Idx_Event.end())
	//  { std::cout << "Event %i exists"<<jentry<<std::endl;
	// }
	//else
	//  { //std::cout << "Event %i added"<<jentry<<std::endl; 
	//    //Idx_Event.push_back(jentry);
	    
	//  }    

	int CTFindex=ArgMin(TempDeltaR);
	fprintf(DeltaREventIndices,"%i, %i, %i \n",jentry , i, CTFindex);
      }// CosmicTF track Loop i	    
    }// Event Loop for Getting Events having matching tracks with deltaR<0.4
  
  fclose(pFile);
  fclose(DeltaREventIndices);

  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx READING INCIDCES and Plotting xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
   
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
  /*  TH1D h_p_CTF          	("h_p_CTF","h_pt",200,0,200);
  TH1D h_px_CTF	                ("h_px_CTF","h_pt",200,0,200);
  TH1D h_py_CTF	                ("h_py_CTF","h_pt",200,0,200);
  TH1D h_pz_CTF	                ("h_pz_CTF","h_pt",200,0,200);
  //TH1D h_ntrk_CTF	        ("h_pt_CTF","h_pt",200,0,200);
  // TH1D h_MagField_CTF	        ("h_pt_CTF","h_pt",200,0,200);*/
  
  TH1D h_pt_CosmicTF 		("h_pt_CosmicTF","h_pt",200,0,200);
  TH1D h_charge_CosmicTF 	("h_charge_CosmicTF","h_charge",10,-5,5);
  TH1D h_chi2_CosmicTF 		("h_chi2_CosmicTF","h_chi2",200,0,100);
  TH1D h_chi2_ndof_CosmicTF 	("h_chi2_ndof_CosmicTF","h_chi2_ndof",200,0,20);
  TH1D h_eta_CosmicTF 		("h_eta_CosmicTF","h_eta",500,-3,3);
  TH1D h_theta_CosmicTF 	("h_thetaCosmicTF","h_theta",500,-3,3);
  TH1D h_phi_CosmicTF 		("h_phi_CosmicTF","h_phi",400,-3.5,3.5);
  TH1D h_d0_CosmicTF 		("h_d0_CosmicTF","h_d0",1000,-85,85);
  TH1D h_dz_CosmicTF 		("h_dz_CosmicTF","h_dz",1500,-350,350);
  /* TH1D h_p_CosmicTF          	("h_p_CTF","h_pt",200,0,200);
  TH1D h_px_CosmicTF	        ("h_px_CTF","h_pt",200,0,200);
  TH1D h_py_CosmicTF	        ("h_py_CTF","h_pt",200,0,200);
  TH1D h_pz_CosmicTF	        ("h_pz_CTF","h_pt",200,0,200);*/
  //TH1D h_ntrk_CosmicTF	        ("h_pt_CTF","h_pt",200,0,200);
  // TH1D h_MagField_CosmicTF      ("h_pt_CTF","h_pt",200,0,200);

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
 /*
  TH1D h_delta_pt("h_delta_pt", "#Delta p_{T}",1000,-1,1); 
  TH1D h_delta_eta("h_delta_eta","#Delta #eta",1000,-1,1 ); 
  TH1D h_delta_phi("h_delta_phi", "#Delta #phi",1000,-1,1);
  TH1D h_deltaPtByPtCosmicTF("h_deltaPtByPtCosmiTF", "#Delta p_{T}/p_{T}", 1000, -1, 1);
  TH1D h_deltaEtaByEtaCosmicTF("h_deltaEtaByEtaCosmicTF","\frac{#Delta #eta}{#eta}", 1000, -1, 1 );
  TH1D h_deltaPtByPtCTF("h_deltaPtByPtCTF", "#Delta p_{T}/p_{T}", 1000, -1, 1);
  TH1D h_deltaEtaByEtaCTF("h_deltaEtaByEtaCTF","\frac{#Delta #eta}{#eta}",1000 , -1, 1 );
 
   //-----Residual Plots-----//
  TH1D h_ResBPIXxPrime_CTF("h_ResBPIXxPrime", "BPIX Track X-residuals;res_{X'} (#mum);Hits", 100, -500., 500.);
  TH1D h_ResFPIXxPrime_CTF("h_ResFPIXxPrime", "FPPIX Track X-residuals;res_{X'} (#mum);Hits", 100, -200., 200.);
  TH1D h_ResTIBxPrime_CTF("h_ResTIBxPrime", "TIB Track X-residuals;Res_{X'} (#mum);Hits", 100, -2000., 2000.);
  TH1D h_ResTIDxPrime_CTF("h_ResTIDxPrime", "TID Track X-residuals;Res_{X'} (#mum);Hits", 100, -10000., 10000.);
  TH1D h_ResTOBxPrime_CTF("h_ResTOBxPrime", "TOB Track X-residuals;Res_{X'} (#mum);Hits", 100, -10000., 10000.);
  TH1D h_ResTECxPrime_CTF("h_ResTECxPrime", "TEC Track X-residuals;Res_{X'} (#mum);Hits", 100, -10000., 10000.);
  TH1D h_ResBPIXyPrime_CTF("h_ResBPIXyPrime", "BPix Track Y-residuals;res_{Y'} (#mum);Hits", 100, -2000., 2000.);
  TH1D h_ResFPIXyPrime_CTF("h_ResFPIXyPrime", "FPix Track Y-residuals;res_{Y'} (#mum);Hits", 100, -500., 500.);
  TH1D h_ResTIByPrime_CTF("h_ResTIByPrime", "TIB Track Y-residuals;Res_{Y'} (#mum);Hits", 100, -40000., 40000.);
  TH1D h_ResTIDyPrime_CTF("h_ResTIDyPrime", "TID Track Y-residuals;Res_{Y'} (#mum);Hits", 100, -40000., 40000.);
  TH1D h_ResTOByPrime_CTF("h_ResTOByPrime", "TOB Track Y-residuals;Res_{X'} (#mum);Hits", 100, -40000., 40000.);
  TH1D h_ResTECyPrime_CTF("h_ResTECyPrime", "TEC Track Y-residuals;Res_{X'} (#mum);Hits", 100, -40000., 40000.);

  TH1D h_ResBPIXxPrime_CosmicTF("h_ResBPIXxPrime", "BPIX Track X-residuals;res_{X'} (#mum);Hits", 100, -500., 500.);
  TH1D h_ResFPIXxPrime_CosmicTF("h_ResFPIXxPrime", "FPPIX Track X-residuals;res_{X'} (#mum);Hits", 100, -200., 200.);
  TH1D h_ResTIBxPrime_CosmicTF("h_ResTIBxPrime", "TIB Track X-residuals;Res_{X'} (#mum);Hits", 100, -2000., 2000.);
  TH1D h_ResTIDxPrime_CosmicTF("h_ResTIDxPrime", "TID Track X-residuals;Res_{X'} (#mum);Hits", 100, -10000., 10000.);
  TH1D h_ResTOBxPrime_CosmicTF("h_ResTOBxPrime", "TOB Track X-residuals;Res_{X'} (#mum);Hits", 100, -10000., 10000.);
  TH1D h_ResTECxPrime_CosmicTF("h_ResTECxPrime", "TEC Track X-residuals;Res_{X'} (#mum);Hits", 100, -10000., 10000.);
  TH1D h_ResBPIXyPrime_CosimcTF("h_ResBPIXyPrime", "BPix Track Y-residuals;res_{Y'} (#mum);Hits", 100, -2000., 2000.);
  TH1D h_ResFPIXyPrime_CosmicTF("h_ResFPIXyPrime", "FPix Track Y-residuals;res_{Y'} (#mum);Hits", 100, -500., 500.);
  TH1D h_ResTIByPrime_CosmicTF("h_ResTIByPrime", "TIB Track Y-residuals;Res_{Y'} (#mum);Hits", 100, -40000., 40000.);
  TH1D h_ResTIDyPrime_CosmicTF("h_ResTIDyPrime", "TID Track Y-residuals;Res_{Y'} (#mum);Hits", 100, -40000., 40000.);
  TH1D h_ResTOByPrime_CosmicTF("h_ResTOByPrime", "TOB Track Y-residuals;Res_{X'} (#mum);Hits", 100, -40000., 40000.);
  TH1D h_ResTECyPrime_CosmicTF("h_ResTECyPrime", "TEC Track Y-residuals;Res_{X'} (#mum);Hits", 100, -40000., 40000.);
  */ 

  //==========Event Loop for Drawing Histograms and Storing=================//
  fprintf(OpFile,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s \n","Event No.","CosmicTF Track Idx.", "CTF Track Idx", "Delta_pt", "Delta_eta", "Delta_phi", "DeltaPt/Pt", "DeltaEta/Eta");

  DeltaREventIndices = fopen("DeltaREventIndices.csv","r");
  int Idx_Event=0, Idx_Track_CosmicTF=0, Idx_Track_CTF=0;
  int jentry=0;
  while(!feof(DeltaREventIndices))
  //for(int i=0;i<15;i++)
    {
      jentry++;
      fscanf(DeltaREventIndices,"%i, %i ,%i \n",&Idx_Event,&Idx_Track_CosmicTF,&Idx_Track_CTF);
      // std::cout<<"Event: "<<Idx_Event<<" | "<<"CosmicTF Idx: "<<Idx_Track_CosmicTF<<" | "<<"CTF Idx: "<<Idx_Track_CTF<<std::endl;
      
      tree1->GetEntry(Idx_Event); //Get first Event of tree 1
      tree2->GetEntry(Idx_Event);

      h_pt_CosmicTF.Fill(pt_CosmicTF->at(Idx_Track_CosmicTF));
      h_charge_CosmicTF.Fill(charge_CosmicTF->at(Idx_Track_CosmicTF));
      h_chi2_CosmicTF.Fill(chi2_CosmicTF->at(Idx_Track_CosmicTF));
      h_chi2_ndof_CosmicTF.Fill(chi2_ndof_CosmicTF->at(Idx_Track_CosmicTF));
      h_eta_CosmicTF.Fill(eta_CosmicTF->at(Idx_Track_CosmicTF));
      h_theta_CosmicTF.Fill(theta_CosmicTF->at(Idx_Track_CosmicTF));
      h_phi_CosmicTF.Fill(phi_CosmicTF->at(Idx_Track_CosmicTF));
      h_d0_CosmicTF.Fill(d0_CosmicTF->at(Idx_Track_CosmicTF));
      h_dz_CosmicTF.Fill(dz_CosmicTF->at(Idx_Track_CosmicTF));
      /*    h_p_CosmicTF.Fill(p_CosmicTF->at(Idx_Track_CosmicTF));
      h_px_CosmicTF.Fill(px_CosmicTF->at(Idx_Track_CosmicTF));
      h_py_CosmicTF.Fill(py_CosmicTF->at(Idx_Track_CosmicTF));
      h_pz_CosmicTF.Fill(pz_CosmicTF->at(Idx_Track_CosmicTF));*/
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
      /*  h_p_CTF.Fill(p_CTF->at(Idx_Track_CTF));
      h_px_CTF.Fill(px_CTF->at(Idx_Track_CTF));
      h_py_CTF.Fill(py_CTF->at(Idx_Track_CTF));
      h_pz_CTF.Fill(pz_CTF->at(Idx_Track_CTF));*/
      h_nHitsValid_CTF.Fill(nHitsValid_CTF->at(Idx_Track_CTF));
      h_nHitsPIXEL_CTF.Fill(nHitsPIXEL_CTF->at(Idx_Track_CTF));
      h_nHitsBPIX_CTF.Fill(nHitsBPIX_CTF->at(Idx_Track_CTF));
      h_nHitsFPIX_CTF.Fill(nHitsFPIX_CTF->at(Idx_Track_CTF));
      h_nHitsTIB_CTF.Fill(nHitsTIB_CTF->at(Idx_Track_CTF));
      h_nHitsTOB_CTF.Fill(nHitsTOB_CTF->at(Idx_Track_CTF));
      h_nHitsTID_CTF.Fill(nHitsTID_CTF->at(Idx_Track_CTF));
      h_nHitsTEC_CTF.Fill(nHitsTEC_CTF->at(Idx_Track_CTF));      

      /*    h_delta_pt.Fill( pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF) );
      h_delta_eta.Fill( eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF) );
      h_delta_phi.Fill( phi_CosmicTF->at(Idx_Track_CosmicTF)-phi_CTF->at(Idx_Track_CTF) );
      h_deltaPtByPtCosmicTF.Fill( (pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF))/pt_CosmicTF->at(Idx_Track_CosmicTF) );
      h_deltaEtaByEtaCosmicTF.Fill( (eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF))/eta_CosmicTF->at(Idx_Track_CosmicTF) );
      h_deltaPtByPtCTF.Fill( (pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF))/pt_CTF->at(Idx_Track_CTF) );
      h_deltaEtaByEtaCTF.Fill( (eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF))/eta_CTF->at(Idx_Track_CTF) );*/
      
      fprintf(OpFile,"%i ,%i ,%i ,%f ,%f ,%f ,%f, %f \n", Idx_Event, Idx_Track_CosmicTF, Idx_Track_CTF,
	      pt_CosmicTF->at(Idx_Track_CosmicTF)- pt_CTF->at(Idx_Track_CTF), //Delta pt
	      eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF), //Delta eta
	      phi_CosmicTF->at(Idx_Track_CosmicTF)-phi_CTF->at(Idx_Track_CTF), // Delta phi
	      (pt_CosmicTF->at(Idx_Track_CosmicTF)-pt_CTF->at(Idx_Track_CTF))/pt_CosmicTF->at(Idx_Track_CosmicTF), //Delta pt/pt
	      (eta_CosmicTF->at(Idx_Track_CosmicTF)-eta_CTF->at(Idx_Track_CTF))/eta_CosmicTF->at(Idx_Track_CosmicTF) //Delta eta/eta	       
	      );
    }

  fclose(DeltaREventIndices);
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
  c.Clear();      
  gSystem->Exec("mv dz.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  /*   //+++++++++++++++++++++++++++++++       p Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_p_CTF.SetLineColor(kBlue);
  h_p_CTF.SetLineWidth(3); 
  h_p_CTF.SetTitle("Momenetum Distribution");
  h_p_CTF.SetXTitle("p (GeV)");
  h_p_CTF.Draw();
  
  h_p_CosmicTF.SetLineColor(kRed);
  h_p_CosmicTF.SetLineWidth(3); 
  h_p_CosmicTF.Draw("SAME");
  
  c.SaveAs("p.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv p.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

   //+++++++++++++++++++++++++++++++       px Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_px_CTF.SetLineColor(kBlue);
  h_px_CTF.SetLineWidth(3); 
  h_px_CTF.SetTitle("p_{x} Distribution");
  h_px_CTF.SetXTitle("p_{x} (GeV)");
  h_px_CTF.Draw();
  
  h_px_CosmicTF.SetLineColor(kRed);
  h_px_CosmicTF.SetLineWidth(3); 
  h_px_CosmicTF.Draw("SAME");
  
  c.SaveAs("px.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv px.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       py Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_py_CTF.SetLineColor(kBlue);
  h_py_CTF.SetLineWidth(3); 
  h_py_CTF.SetTitle("p_{y} Distribution");
  h_py_CTF.SetXTitle("p_{y} (GeV)");
  h_py_CTF.Draw();
  
  h_py_CosmicTF.SetLineColor(kRed);
  h_py_CosmicTF.SetLineWidth(3); 
  h_py_CosmicTF.Draw("SAME");
  
  c.SaveAs("py.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv py.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       pz Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_pz_CTF.SetLineColor(kBlue);
  h_pz_CTF.SetLineWidth(3); 
  h_pz_CTF.SetTitle("p_{z} Distribution");
  h_pz_CTF.SetXTitle("p_{z} (GeV)");
  h_pz_CTF.Draw();
  
  h_pz_CosmicTF.SetLineColor(kRed);
  h_pz_CosmicTF.SetLineWidth(3); 
  h_pz_CosmicTF.Draw("SAME");
  
  c.SaveAs("pz.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv pz.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------*/

  //+++++++++++++++++++++++++++++++      Valid Hits Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsValid_CTF.SetLineColor(kBlue);
  h_nHitsValid_CTF.SetLineWidth(3); 
  h_nHitsValid_CTF.SetTitle("Valid Hits");
  h_nHitsValid_CTF.SetXTitle("Hits (#)");
  h_nHitsValid_CTF.Draw();
  
  h_nHitsValid_CosmicTF.SetLineColor(kRed);
  h_nHitsValid_CosmicTF.SetLineWidth(3); 
  h_nHitsValid_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsValid.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsValid.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       nHitsPIXEL Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsPIXEL_CTF.SetLineColor(kBlue);
  h_nHitsPIXEL_CTF.SetLineWidth(3); 
  h_nHitsPIXEL_CTF.SetTitle("PIXEL Hits");
  h_nHitsPIXEL_CTF.SetXTitle("Hits (#)");
  h_nHitsPIXEL_CTF.Draw();
  
  h_nHitsPIXEL_CosmicTF.SetLineColor(kRed);
  h_nHitsPIXEL_CosmicTF.SetLineWidth(3); 
  h_nHitsPIXEL_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsPIXEL.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsPIXEL.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       nHitsBPIX Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsBPIX_CTF.SetLineColor(kBlue);
  h_nHitsBPIX_CTF.SetLineWidth(3); 
  h_nHitsBPIX_CTF.SetTitle("BPIX Hits");
  h_nHitsBPIX_CTF.SetXTitle("Hits (#)");
  h_nHitsBPIX_CTF.Draw();
  
  h_nHitsBPIX_CosmicTF.SetLineColor(kRed);
  h_nHitsBPIX_CosmicTF.SetLineWidth(3); 
  h_nHitsBPIX_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsBPIX.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsBPIX.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       nHitsFPIX Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsFPIX_CTF.SetLineColor(kBlue);
  h_nHitsFPIX_CTF.SetLineWidth(3); 
  h_nHitsFPIX_CTF.SetTitle("BPIX Hits");
  h_nHitsFPIX_CTF.SetXTitle("Hits (#)");
  h_nHitsFPIX_CTF.Draw();
  
  h_nHitsFPIX_CosmicTF.SetLineColor(kRed);
  h_nHitsFPIX_CosmicTF.SetLineWidth(3); 
  h_nHitsFPIX_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsFPIX.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsFPIX.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

 //+++++++++++++++++++++++++++++++       nHitsTIB Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTIB_CTF.SetLineColor(kBlue);
  h_nHitsTIB_CTF.SetLineWidth(3); 
  h_nHitsTIB_CTF.SetTitle("TIB Hits");
  h_nHitsTIB_CTF.SetXTitle("Hits (#)");
  h_nHitsTIB_CTF.Draw();
  
  h_nHitsTIB_CosmicTF.SetLineColor(kRed);
  h_nHitsTIB_CosmicTF.SetLineWidth(3); 
  h_nHitsTIB_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsTIB.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsTIB.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

   //+++++++++++++++++++++++++++++++       nHitsTID Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTID_CTF.SetLineColor(kBlue);
  h_nHitsTID_CTF.SetLineWidth(3); 
  h_nHitsTID_CTF.SetTitle("TID Hits");
  h_nHitsTID_CTF.SetXTitle("Hits (#)");
  h_nHitsTID_CTF.Draw();
  
  h_nHitsTID_CosmicTF.SetLineColor(kRed);
  h_nHitsTID_CosmicTF.SetLineWidth(3); 
  h_nHitsTID_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsTID.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsTID.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       nHitsTOB Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTOB_CTF.SetLineColor(kBlue);
  h_nHitsTOB_CTF.SetLineWidth(3); 
  h_nHitsTOB_CTF.SetTitle("TOB Hits");
  h_nHitsTOB_CTF.SetXTitle("Hits (#)");
  h_nHitsTOB_CTF.Draw();
  
  h_nHitsTOB_CosmicTF.SetLineColor(kRed);
  h_nHitsTOB_CosmicTF.SetLineWidth(3); 
  h_nHitsTOB_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsTOB.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsTOB.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  
  //+++++++++++++++++++++++++++++++       nHitsTEC Distribution      ++++++++++++++++++++++++++++++++++++++++     
  h_nHitsTEC_CTF.SetLineColor(kBlue);
  h_nHitsTEC_CTF.SetLineWidth(3); 
  h_nHitsTEC_CTF.SetTitle("TEC Hits");
  h_nHitsTEC_CTF.SetXTitle("Hits (#)");
  h_nHitsTEC_CTF.Draw();
  
  h_nHitsTEC_CosmicTF.SetLineColor(kRed);
  h_nHitsTEC_CosmicTF.SetLineWidth(3); 
  h_nHitsTEC_CosmicTF.Draw("SAME");
  
  c.SaveAs("nHitsTEC.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv nHitsTEC.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------
  /*
  //+++++++++++++++++++++++++++++++       Delta pt     ++++++++++++++++++++++++++++++++++++++++     
  h_delta_pt.SetLineColor(kOrange-3);
  h_delta_pt.SetLineWidth(3); 
  h_delta_pt.SetTitle("#Delta p_{T}");
  h_delta_pt.SetXTitle("#Delta p_{T} (GeV)");
  h_delta_pt.Draw();
  
  c.SaveAs("deltaPt.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv deltaPt.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta eta     ++++++++++++++++++++++++++++++++++++++++     
  h_delta_eta.SetLineColor(kOrange-3);
  h_delta_eta.SetLineWidth(3); 
  h_delta_eta.SetTitle("#Delta #eta");
  h_delta_eta.SetXTitle("#Delta #eta");
  h_delta_eta.Draw();
  
  c.SaveAs("deltaEta.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv deltaEta.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta phi     ++++++++++++++++++++++++++++++++++++++++     
  h_delta_phi.SetLineColor(kOrange-3);
  h_delta_phi.SetLineWidth(3); 
  h_delta_phi.SetTitle("#Delta #phi");
  h_delta_phi.SetXTitle("#Delta #phi");
  h_delta_phi.Draw();
  
  c.SaveAs("deltaPhi.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv deltaPhi.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta pt By Pt_CosmicTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaPtByPtCosmicTF.SetLineColor(kOrange-3);
  h_deltaPtByPtCosmicTF.SetLineWidth(3); 
  h_deltaPtByPtCosmicTF.SetTitle("#Delta p_{T}");
  h_deltaPtByPtCosmicTF.SetXTitle("#Delta p_{T} (GeV)");
  h_deltaPtByPtCosmicTF.Draw();
  
  c.SaveAs("deltaPtByPtCosmicTF.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv deltaPtByPtCosmicTF.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta pt By Pt_CTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaPtByPtCTF.SetLineColor(kOrange-3);
  h_deltaPtByPtCTF.SetLineWidth(3); 
  h_deltaPtByPtCTF.SetTitle("#Delta p_{T}");
  h_deltaPtByPtCTF.SetXTitle("#Delta p_{T} (GeV)");
  h_deltaPtByPtCTF.Draw();
  
  c.SaveAs("deltaPtByPtCTF.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv deltaPtByPtCTF.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta eta By eta_CTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaEtaByEtaCTF.SetLineColor(kOrange-3);
  h_deltaEtaByEtaCTF.SetLineWidth(3); 
  h_deltaEtaByEtaCTF.SetTitle("#Delta #eta");
  h_deltaEtaByEtaCTF.SetXTitle("#Delta #eta");
  h_deltaEtaByEtaCTF.Draw();
  
  c.SaveAs("h_deltaEtaByEtaCTF.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv h_deltaEtaByEtaCTF.png Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++       Delta eta By eta_CosmicTF    ++++++++++++++++++++++++++++++++++++++++     
  h_deltaEtaByEtaCosmicTF.SetLineColor(kOrange-3);
  h_deltaEtaByEtaCosmicTF.SetLineWidth(3); 
  h_deltaEtaByEtaCosmicTF.SetTitle("#Delta #eta");
  h_deltaEtaByEtaCosmicTF.SetXTitle("#Delta #eta");
  h_deltaEtaByEtaCosmicTF.Draw();
  
  c.SaveAs("deltaEtaByEtaCosmicTF.png");                                                                                                                  
  c.Clear();      
  gSystem->Exec("mv deltaEtaByEtaCosmicTF Kinematical_Plots");
  //---------------------------------------------------------------------------------------------------

  */


  
}
