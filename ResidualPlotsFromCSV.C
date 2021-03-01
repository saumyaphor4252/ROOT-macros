using namespace ROOT::VecOps;

void ResidualPlotsFromCSV()
{
    
  TFile *file1 = new TFile("CTF_Residuals.root");
  TFile *file2 = new TFile("CosmicTF_Residuals.root");

  FILE *DeltaREventIndices;
  
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
  vector<int>     *nHitsValid_CTF;
  vector<int>     *nHitsBPIX_CTF;
  vector<int>     *nHitsFPIX_CTF;
  vector<int>     *nHitsTIB_CTF;
  vector<int>     *nHitsTID_CTF;
  vector<int>     *nHitsTOB_CTF;
  vector<int>     *nHitsTEC_CTF;
  vector<double>  *ResBPIXxPrime_CTF;
  vector<double>  *ResFPIXxPrime_CTF;
  vector<double>  *ResTIBxPrime_CTF;
  vector<double>  *ResTOBxPrime_CTF;
  vector<double>  *ResTIDxPrime_CTF;
  vector<double>  *ResTECxPrime_CTF;
  vector<double>  *ResBPIXyPrime_CTF;
  vector<double>  *ResFPIXyPrime_CTF;
  vector<double>  *ResTIByPrime_CTF;
  vector<double>  *ResTOByPrime_CTF;
  vector<double>  *ResTIDyPrime_CTF;
  vector<double>  *ResTECyPrime_CTF;
  pt_CTF=0; charge_CTF=0; chi2_CTF=0; chi2_ndof_CTF=0; eta_CTF=0; theta_CTF=0; phi_CTF=0;
  nHitsValid_CTF=0; nHitsBPIX_CTF=0;  nHitsFPIX_CTF=0;  nHitsTIB_CTF=0;  nHitsTID_CTF=0;  nHitsTOB_CTF=0;  nHitsTEC_CTF=0;
  ResBPIXxPrime_CTF=0; ResFPIXxPrime_CTF=0; ResTIBxPrime_CTF=0; ResTOBxPrime_CTF=0; ResTIDxPrime_CTF=0;  ResTECxPrime_CTF=0;
  ResBPIXyPrime_CTF=0; ResFPIXyPrime_CTF=0; ResTIByPrime_CTF=0; ResTOByPrime_CTF=0; ResTIDyPrime_CTF=0;  ResTECyPrime_CTF=0;

   //=======tree2======//
  vector<double>  *pt_CosmicTF;
  vector<double>  *charge_CosmicTF;
  vector<double>  *chi2_CosmicTF;
  vector<double>  *chi2_ndof_CosmicTF;
  vector<double>  *eta_CosmicTF;
  vector<double>  *theta_CosmicTF;
  vector<double>  *phi_CosmicTF;
  vector<int>     *nHitsValid_CosmicTF;
  vector<int>     *nHitsPIXEL_CosmicTF;
  vector<int>     *nHitsBPIX_CosmicTF;
  vector<int>     *nHitsFPIX_CosmicTF;
  vector<int>     *nHitsTIB_CosmicTF;
  vector<int>     *nHitsTOB_CosmicTF;
  vector<int>     *nHitsTID_CosmicTF;
  vector<int>     *nHitsTEC_CosmicTF;
  vector<double>  *ResBPIXxPrime_CosmicTF;
  vector<double>  *ResFPIXxPrime_CosmicTF;
  vector<double>  *ResTIBxPrime_CosmicTF;
  vector<double>  *ResTOBxPrime_CosmicTF;
  vector<double>  *ResTIDxPrime_CosmicTF;
  vector<double>  *ResTECxPrime_CosmicTF;
  vector<double>  *ResBPIXyPrime_CosmicTF;
  vector<double>  *ResFPIXyPrime_CosmicTF;
  vector<double>  *ResTIByPrime_CosmicTF;
  vector<double>  *ResTOByPrime_CosmicTF;
  vector<double>  *ResTIDyPrime_CosmicTF;
  vector<double>  *ResTECyPrime_CosmicTF;
  pt_CosmicTF=0; charge_CosmicTF=0; chi2_CosmicTF=0; chi2_ndof_CosmicTF=0; eta_CosmicTF=0; theta_CosmicTF=0; phi_CosmicTF=0; 
  nHitsValid_CosmicTF=0; nHitsPIXEL_CosmicTF=0; nHitsBPIX_CosmicTF=0;  nHitsFPIX_CosmicTF=0;  nHitsTIB_CosmicTF=0;  nHitsTID_CosmicTF=0;  nHitsTOB_CosmicTF=0;  nHitsTEC_CosmicTF=0;
  ResBPIXxPrime_CosmicTF=0; ResFPIXxPrime_CosmicTF=0; ResTIBxPrime_CosmicTF=0; ResTOBxPrime_CosmicTF=0; ResTIDxPrime_CosmicTF=0;  ResTECxPrime_CosmicTF=0;
  ResBPIXyPrime_CosmicTF=0; ResFPIXyPrime_CosmicTF=0; ResTIByPrime_CosmicTF=0; ResTOByPrime_CosmicTF=0; ResTIDyPrime_CosmicTF=0;  ResTECyPrime_CosmicTF=0;
  
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
  tree1->SetBranchAddress("nHitsValid", &nHitsValid_CTF);
  tree1->SetBranchAddress("nHitsBPIX", &nHitsBPIX_CTF);
  tree1->SetBranchAddress("nHitsFPIX", &nHitsFPIX_CTF);
  tree1->SetBranchAddress("nHitsTIB", &nHitsTIB_CTF);
  tree1->SetBranchAddress("nHitsTID", &nHitsTID_CTF);
  tree1->SetBranchAddress("nHitsTOB", &nHitsTOB_CTF);
  tree1->SetBranchAddress("nHitsTEC", &nHitsTEC_CTF);
  tree1->SetBranchAddress("ResBPIXxPrime", &ResBPIXxPrime_CTF);
  tree1->SetBranchAddress("ResFPIXxPrime", &ResFPIXxPrime_CTF);
  tree1->SetBranchAddress("ResTIBxPrime", &ResTIBxPrime_CTF);
  tree1->SetBranchAddress("ResTOBxPrime", &ResTOBxPrime_CTF);
  tree1->SetBranchAddress("ResTIDxPrime", &ResTIDxPrime_CTF);
  tree1->SetBranchAddress("ResTECxPrime", &ResTECxPrime_CTF);
  tree1->SetBranchAddress("ResBPIXyPrime", &ResBPIXyPrime_CTF);
  tree1->SetBranchAddress("ResFPIXyPrime", &ResFPIXyPrime_CTF);
  tree1->SetBranchAddress("ResTIByPrime", &ResTIByPrime_CTF);
  tree1->SetBranchAddress("ResTOByPrime", &ResTOByPrime_CTF);
  tree1->SetBranchAddress("ResTIDyPrime", &ResTIDyPrime_CTF);
  tree1->SetBranchAddress("ResTECyPrime", &ResTECyPrime_CTF);

  tree2->SetBranchAddress("pt", &pt_CosmicTF);
  tree2->SetBranchAddress("charge", &charge_CosmicTF);
  tree2->SetBranchAddress("chi2", &chi2_CosmicTF);
  tree2->SetBranchAddress("chi2_ndof", &chi2_ndof_CosmicTF);
  tree2->SetBranchAddress("eta", &eta_CosmicTF);
  tree2->SetBranchAddress("theta", &theta_CosmicTF);
  tree2->SetBranchAddress("phi", &phi_CosmicTF);
  tree2->SetBranchAddress("nHitsValid", &nHitsValid_CosmicTF);
  tree2->SetBranchAddress("nHitsPIXEL", &nHitsPIXEL_CosmicTF);
  tree2->SetBranchAddress("nHitsBPIX", &nHitsBPIX_CosmicTF);
  tree2->SetBranchAddress("nHitsFPIX", &nHitsFPIX_CosmicTF);
  tree2->SetBranchAddress("nHitsTIB", &nHitsTIB_CosmicTF);
  tree2->SetBranchAddress("nHitsTOB", &nHitsTOB_CosmicTF);
  tree2->SetBranchAddress("nHitsTID", &nHitsTID_CosmicTF);
  tree2->SetBranchAddress("nHitsTEC", &nHitsTEC_CosmicTF);
  tree2->SetBranchAddress("ResBPIXxPrime", &ResBPIXxPrime_CosmicTF);
  tree2->SetBranchAddress("ResFPIXxPrime", &ResFPIXxPrime_CosmicTF);
  tree2->SetBranchAddress("ResTIBxPrime", &ResTIBxPrime_CosmicTF);
  tree2->SetBranchAddress("ResTOBxPrime", &ResTOBxPrime_CosmicTF);
  tree2->SetBranchAddress("ResTIDxPrime", &ResTIDxPrime_CosmicTF);
  tree2->SetBranchAddress("ResTECxPrime", &ResTECxPrime_CosmicTF);
  tree2->SetBranchAddress("ResBPIXyPrime", &ResBPIXyPrime_CosmicTF);
  tree2->SetBranchAddress("ResFPIXyPrime", &ResFPIXyPrime_CosmicTF);
  tree2->SetBranchAddress("ResTIByPrime", &ResTIByPrime_CosmicTF);
  tree2->SetBranchAddress("ResTOByPrime", &ResTOByPrime_CosmicTF);
  tree2->SetBranchAddress("ResTIDyPrime", &ResTIDyPrime_CosmicTF);
  tree2->SetBranchAddress("ResTECyPrime", &ResTECyPrime_CosmicTF); 


  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx READING INCIDCES and Plotting xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
   
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  PLOTTING  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
  

  TCanvas c("c","c",800,600);
  TH1D h_ResBPIXxPrime_CTF("h_ResBPIXxPrime_CTF", "BPIX Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResFPIXxPrime_CTF("h_ResFPIXxPrime_CTF", "FPIX Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIBxPrime_CTF("h_ResTIBxPrime_CTF", "TIB Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIDxPrime_CTF("h_ResTIDxPrime_CTF", "TID Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTOBxPrime_CTF("h_ResTOBxPrime_CTF", "TOB Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTECxPrime_CTF("h_ResTECxPrime_CTF", "TEC Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResBPIXyPrime_CTF("h_ResBPIXyPrime_CTF", "BPIX Track Y-residuals;Res_{Y'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResFPIXyPrime_CTF("h_ResFPIXyPrime_CTF", "FPIX Track Y-residuals;Res_{Y'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIByPrime_CTF("h_ResTIByPrime_CTF", "TIB Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTIDyPrime_CTF("h_ResTIDyPrime_CTF", "TID Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTOByPrime_CTF("h_ResTOByPrime_CTF", "TOB Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTECyPrime_CTF("h_ResTECyPrime_CTF", "TEC Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);

  TH1D h_ResBPIXxPrime_CosmicTF("h_ResBPIXxPrime_CosmicTF", "BPIX Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResFPIXxPrime_CosmicTF("h_ResFPIXxPrime_CosmicTF", "FPIX Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIBxPrime_CosmicTF("h_ResTIBxPrime_CosmicTF", "TIB Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIDxPrime_CosmicTF("h_ResTIDxPrime_CosmicTF", "TID Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTOBxPrime_CosmicTF("h_ResTOBxPrime_CosmicTF", "TOB Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTECxPrime_CosmicTF("h_ResTECxPrime_CosmicTF", "TEC Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResBPIXyPrime_CosmicTF("h_ResBPIXyPrime_CosmicTF", "BPIX Track Y-residuals;Res_{Y'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResFPIXyPrime_CosmicTF("h_ResFPIXyPrime_CosmicTF", "FPIX Track Y-residuals;Res_{Y'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIByPrime_CosmicTF("h_ResTIByPrime_CosmicTF", "TIB Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTIDyPrime_CosmicTF("h_ResTIDyPrime_CosmicTF", "TID Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTOByPrime_CosmicTF("h_ResTOByPrime_CosmicTF", "TOB Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTECyPrime_CosmicTF("h_ResTECyPrime_CosmicTF", "TEC Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.); 
 
  DeltaREventIndices = fopen("DeltaREventIndices.csv","r");
  int Idx_Event=0, Idx_Track_CosmicTF=0, Idx_Track_CTF=0;
  int jentry=0;
  while(!feof(DeltaREventIndices))
    //  Long64_t n1 = tree1->GetEntriesFast();  
  //for (int jentry=0; jentry<10000; jentry++) //Event Loop
    {
      int HitsPIXEL=0,HitsBPIX=0,ResBPIX=0,HitsFPIX=0,ResFPIX=0,HitsTIB=0,ResTIB=0,HitsTOB=0,ResTOB=0,HitsTID=0,ResTID=0,HitsTEC=0,ResTEC=0,ValidHits=0,TotalHits=0,TotalRes=0,residual=0;

      jentry++;
      fscanf(DeltaREventIndices,"%i, %i ,%i \n",&Idx_Event,&Idx_Track_CosmicTF,&Idx_Track_CTF);
      
      //std::cout<<"Analysing event: "<<jentry<<std::endl;      
      tree1->GetEntry(Idx_Event); //Get first Event of tree 1
      tree2->GetEntry(Idx_Event);
                
      int x,y; //Variables for getting getting the index diving the tracks in Residual Branch
      //   nHitsBPIX Branch for event 1:  | 2 | 3 | where 2 hits in Tk1 and 3 in Tk2
      //   Res Branch: | Res1 Tk1 | Res2 Tk1 | Res1 Tk2 | Res2 Tk2 | Res3 Tk2 |  
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS BPIX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResBPIXxPrime_CTF->size()!=0)
	{
	  if(Idx_Track_CTF==0) {x=0;}
	  else { x=nHitsBPIX_CTF->at(Idx_Track_CTF-1); }
	  y=nHitsBPIX_CTF->at(Idx_Track_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResBPIXxPrime_CTF.Fill(ResBPIXxPrime_CTF->at(res));
	      h_ResBPIXyPrime_CTF.Fill(ResBPIXyPrime_CTF->at(res));
	    }	  
	}

       if(ResBPIXxPrime_CosmicTF->size()!=0)
	{
	  if(Idx_Track_CosmicTF==0) {x=0;}
	  else { x=nHitsBPIX_CosmicTF->at(Idx_Track_CosmicTF-1); }
	  y=nHitsBPIX_CosmicTF->at(Idx_Track_CosmicTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResBPIXxPrime_CosmicTF.Fill(ResBPIXxPrime_CosmicTF->at(res));
	      h_ResBPIXyPrime_CosmicTF.Fill(ResBPIXyPrime_CosmicTF->at(res));
	    }	  
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS FPIX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResFPIXxPrime_CTF->size()!=0)
	{
	  if(Idx_Track_CTF==0) {x=0;}
	  else { x=nHitsFPIX_CTF->at(Idx_Track_CTF-1); }
	  y=nHitsFPIX_CTF->at(Idx_Track_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResFPIXxPrime_CTF.Fill(ResFPIXxPrime_CTF->at(res));
	      h_ResFPIXyPrime_CTF.Fill(ResFPIXyPrime_CTF->at(res));
	    }  
	}

        if(ResFPIXxPrime_CosmicTF->size()!=0)
	{
	  if(Idx_Track_CosmicTF==0) {x=0;}
	  else { x=nHitsFPIX_CosmicTF->at(Idx_Track_CosmicTF-1); }
	  y=nHitsFPIX_CosmicTF->at(Idx_Track_CosmicTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResFPIXxPrime_CosmicTF.Fill(ResFPIXxPrime_CosmicTF->at(res));
	      h_ResFPIXyPrime_CosmicTF.Fill(ResFPIXyPrime_CosmicTF->at(res));
	    }  
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TIB XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTIBxPrime_CTF->size()!=0)
	{
	  if(Idx_Track_CTF==0) {x=0;}
	  else { x=nHitsTIB_CTF->at(Idx_Track_CTF-1); }
	  y=nHitsTIB_CTF->at(Idx_Track_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTIBxPrime_CTF.Fill(ResTIBxPrime_CTF->at(res));
	      h_ResTIByPrime_CTF.Fill(ResTIByPrime_CTF->at(res));
	    }
	}

      if(ResTIBxPrime_CosmicTF->size()!=0)
	{
	  if(Idx_Track_CosmicTF==0) {x=0;}
	  else { x=nHitsTIB_CosmicTF->at(Idx_Track_CosmicTF-1); }
	  y=nHitsTIB_CosmicTF->at(Idx_Track_CosmicTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTIBxPrime_CosmicTF.Fill(ResTIBxPrime_CosmicTF->at(res));
	      h_ResTIByPrime_CosmicTF.Fill(ResTIByPrime_CosmicTF->at(res));
	    }
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TID XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTIDxPrime_CTF->size()!=0)
	{
	  if(Idx_Track_CTF==0) {x=0;}
	  else { x=nHitsTID_CTF->at(Idx_Track_CTF-1); }
	  y=nHitsTID_CTF->at(Idx_Track_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTIDxPrime_CTF.Fill(ResTIDxPrime_CTF->at(res));
	      h_ResTIDyPrime_CTF.Fill(ResTIDyPrime_CTF->at(res));
	    }
	}

      if(ResTIDxPrime_CosmicTF->size()!=0)
	{
	  if(Idx_Track_CosmicTF==0) {x=0;}
	  else { x=nHitsTID_CosmicTF->at(Idx_Track_CosmicTF-1); }
	  y=nHitsTID_CosmicTF->at(Idx_Track_CosmicTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTIDxPrime_CosmicTF.Fill(ResTIDxPrime_CosmicTF->at(res));
	      h_ResTIDyPrime_CosmicTF.Fill(ResTIDyPrime_CosmicTF->at(res));
	    }
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TOB XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTOBxPrime_CTF->size()!=0)
	{
	  if(Idx_Track_CTF==0) {x=0;}
	  else { x=nHitsTOB_CTF->at(Idx_Track_CTF-1); }
	  y=nHitsTOB_CTF->at(Idx_Track_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTOBxPrime_CTF.Fill(ResTOBxPrime_CTF->at(res));
	      h_ResTOByPrime_CTF.Fill(ResTOByPrime_CTF->at(res));
	    }
	}

      if(ResTOBxPrime_CosmicTF->size()!=0)
	{
	  if(Idx_Track_CosmicTF==0) {x=0;}
	  else { x=nHitsTOB_CosmicTF->at(Idx_Track_CosmicTF-1); }
	  y=nHitsTOB_CosmicTF->at(Idx_Track_CosmicTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTOBxPrime_CosmicTF.Fill(ResTOBxPrime_CosmicTF->at(res));
	      h_ResTOByPrime_CosmicTF.Fill(ResTOByPrime_CosmicTF->at(res));
	    }
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TEC XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTECxPrime_CTF->size()!=0)
	{
	  if(Idx_Track_CTF==0) {x=0;}
	  else { x=nHitsTEC_CTF->at(Idx_Track_CTF-1); }
	  y=nHitsTEC_CTF->at(Idx_Track_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTECxPrime_CTF.Fill(ResTECxPrime_CTF->at(res));
	      h_ResTECyPrime_CTF.Fill(ResTECyPrime_CTF->at(res));
	    }
	}

      if(ResTECxPrime_CosmicTF->size()!=0)
	{
	  if(Idx_Track_CosmicTF==0) {x=0;}
	  else { x=nHitsTEC_CosmicTF->at(Idx_Track_CosmicTF-1); }
	  y=nHitsTEC_CosmicTF->at(Idx_Track_CosmicTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTECxPrime_CosmicTF.Fill(ResTECxPrime_CosmicTF->at(res));
	      h_ResTECyPrime_CosmicTF.Fill(ResTECyPrime_CosmicTF->at(res));
	    }
	}

    }// Event Loop
  fclose(DeltaREventIndices);
  
  c.SetGrid();
  h_ResBPIXxPrime_CTF.SetLineColor(kBlue);
  h_ResBPIXxPrime_CTF.SetLineWidth(3); 
  h_ResBPIXxPrime_CTF.Draw();
  h_ResBPIXxPrime_CosmicTF.SetLineColor(kRed);
  h_ResBPIXxPrime_CosmicTF.SetLineWidth(3);
  h_ResBPIXxPrime_CosmicTF.Draw("same");
  c.SaveAs("ResBPIXxPrime.png");
  gSystem->Exec("mv ResBPIXxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResFPIXxPrime_CTF.SetLineColor(kBlue);
  h_ResFPIXxPrime_CTF.SetLineWidth(3); 
  h_ResFPIXxPrime_CTF.Draw();
  h_ResFPIXxPrime_CosmicTF.SetLineColor(kRed);
  h_ResFPIXxPrime_CosmicTF.SetLineWidth(3);
  h_ResFPIXxPrime_CosmicTF.Draw("same");
  c.SaveAs("ResFPIXxPrime.png");
  gSystem->Exec("mv ResFPIXxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTIBxPrime_CTF.SetLineColor(kBlue);
  h_ResTIBxPrime_CTF.SetLineWidth(3); 
  h_ResTIBxPrime_CTF.Draw();
  h_ResTIBxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIBxPrime_CosmicTF.SetLineWidth(3);
  h_ResTIBxPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTIBxPrime.png");
  gSystem->Exec("mv ResTIBxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTOBxPrime_CTF.SetLineColor(kBlue);
  h_ResTOBxPrime_CTF.SetLineWidth(3); 
  h_ResTOBxPrime_CTF.Draw();
  h_ResTOBxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTOBxPrime_CosmicTF.SetLineWidth(3);
  h_ResTOBxPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTOBxPrime.png");
  gSystem->Exec("mv ResTOBxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTIDxPrime_CTF.SetLineColor(kBlue);
  h_ResTIDxPrime_CTF.SetLineWidth(3); 
  h_ResTIDxPrime_CTF.Draw();
  h_ResTIDxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIDxPrime_CosmicTF.SetLineWidth(3);
  h_ResTIDxPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTIDxPrime.png");
  gSystem->Exec("mv ResTIDxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTECxPrime_CTF.SetLineColor(kBlue);
  h_ResTECxPrime_CTF.SetLineWidth(3); 
  h_ResTECxPrime_CTF.Draw();
  h_ResTECxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTECxPrime_CosmicTF.SetLineWidth(3);
  h_ResTECxPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTECxPrime.png");
  gSystem->Exec("mv ResTECxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResBPIXyPrime_CTF.SetLineColor(kBlue);
  h_ResBPIXyPrime_CTF.SetLineWidth(3); 
  h_ResBPIXyPrime_CTF.Draw();
  h_ResBPIXyPrime_CosmicTF.SetLineColor(kRed);
  h_ResBPIXyPrime_CosmicTF.SetLineWidth(3);
  h_ResBPIXyPrime_CosmicTF.Draw("same");
  c.SaveAs("ResBPIXyPrime.png");
  gSystem->Exec("mv ResBPIXyPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResFPIXyPrime_CTF.SetLineColor(kBlue);
  h_ResFPIXyPrime_CTF.SetLineWidth(3); 
  h_ResFPIXyPrime_CTF.Draw("same");
  h_ResFPIXyPrime_CosmicTF.SetLineColor(kRed);
  h_ResFPIXyPrime_CosmicTF.SetLineWidth(3);
  h_ResFPIXyPrime_CosmicTF.Draw();
  c.SaveAs("ResFPIXyPrime.png");
  gSystem->Exec("mv ResFPIXyPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTIByPrime_CTF.SetLineColor(kBlue);
  h_ResTIByPrime_CTF.SetLineWidth(3); 
  h_ResTIByPrime_CTF.Draw();
  h_ResTIByPrime_CosmicTF.Draw("same");
  h_ResTIByPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIByPrime_CosmicTF.SetLineWidth(3);
  c.SaveAs("ResTIByPrime.png");
  gSystem->Exec("mv ResTIByPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTOByPrime_CTF.SetLineColor(kBlue);
  h_ResTOByPrime_CTF.SetLineWidth(3); 
  h_ResTOByPrime_CTF.Draw();
  h_ResTOByPrime_CosmicTF.SetLineColor(kRed);
  h_ResTOByPrime_CosmicTF.SetLineWidth(3);
  h_ResTOByPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTOByPrime.png");
  gSystem->Exec("mv ResTOByPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTIDyPrime_CTF.SetLineColor(kBlue);
  h_ResTIDyPrime_CTF.SetLineWidth(3); 
  h_ResTIDyPrime_CTF.Draw();
  h_ResTIDyPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIDyPrime_CosmicTF.SetLineWidth(3);
  h_ResTIDyPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTIDyPrime.png");
  gSystem->Exec("mv ResTIDyPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid();
  h_ResTECyPrime_CTF.SetLineColor(kBlue);
  h_ResTECyPrime_CTF.SetLineWidth(3); 
  h_ResTECyPrime_CTF.Draw();
  h_ResTECyPrime_CosmicTF.SetLineColor(kRed);
  h_ResTECyPrime_CosmicTF.SetLineWidth(3);
  h_ResTECyPrime_CosmicTF.Draw("same");
  c.SaveAs("ResTECyPrime.png");
  gSystem->Exec("mv ResTECyPrime.png Kinematical_Plots");
  c.Clear();

 
}
