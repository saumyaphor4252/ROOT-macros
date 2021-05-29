void GetNormalizedResidualPlots()
{
  TFile *file1 = new TFile("CRAB_CTF_Residuals.root");
  TFile *file2 = new TFile("CRAB_CosmicTF_Residuals.root");
  TTree *tree1, *tree2;
  tree1 = (TTree*)file1->Get("demo/Event");
  tree2 = (TTree*)file2->Get("demo/Event");

  //========================Local varibles to store parameters from tree===================//
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

  nHitsValid_CTF=0; nHitsBPIX_CTF=0;  nHitsFPIX_CTF=0;  nHitsTIB_CTF=0;  nHitsTID_CTF=0;  nHitsTOB_CTF=0;  nHitsTEC_CTF=0;
  ResBPIXxPrime_CTF=0; ResFPIXxPrime_CTF=0; ResTIBxPrime_CTF=0; ResTOBxPrime_CTF=0; ResTIDxPrime_CTF=0;  ResTECxPrime_CTF=0;
  ResBPIXyPrime_CTF=0; ResFPIXyPrime_CTF=0; ResTIByPrime_CTF=0; ResTOByPrime_CTF=0; ResTIDyPrime_CTF=0;  ResTECyPrime_CTF=0;

  //=======tree2======//
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

  nHitsValid_CosmicTF=0; nHitsPIXEL_CosmicTF=0; nHitsBPIX_CosmicTF=0;  nHitsFPIX_CosmicTF=0;  nHitsTIB_CosmicTF=0;  nHitsTID_CosmicTF=0;  nHitsTOB_CosmicTF=0;  nHitsTEC_CosmicTF=0;
  ResBPIXxPrime_CosmicTF=0; ResFPIXxPrime_CosmicTF=0; ResTIBxPrime_CosmicTF=0; ResTOBxPrime_CosmicTF=0; ResTIDxPrime_CosmicTF=0;  ResTECxPrime_CosmicTF=0;
  ResBPIXyPrime_CosmicTF=0; ResFPIXyPrime_CosmicTF=0; ResTIByPrime_CosmicTF=0; ResTOByPrime_CosmicTF=0; ResTIDyPrime_CosmicTF=0;  ResTECyPrime_CosmicTF=0;
  
  //==============================Setting tree branches to local varibles================//
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

  Long64_t n1 = tree1->GetEntriesFast();
  Long64_t n2 = tree2->GetEntriesFast();
  std::cout<<"Events :"<<n1<<std::endl;
  std::cout<<"Events :"<<n2<<std::endl;

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx READING INCIDCES and Plotting xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
   
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  PLOTTING  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
  TH1D h_ResBPIXxPrime_CTF("h_ResBPIXxPrime_CTF", "BPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResFPIXxPrime_CTF("h_ResFPIXxPrime_CTF", "FPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTIBxPrime_CTF("h_ResTIBxPrime_CTF", "TIB Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTIDxPrime_CTF("h_ResTIDxPrime_CTF", "TID Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTOBxPrime_CTF("h_ResTOBxPrime_CTF", "TOB Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTECxPrime_CTF("h_ResTECxPrime_CTF", "TEC Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResBPIXyPrime_CTF("h_ResBPIXyPrime_CTF", "BPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResFPIXyPrime_CTF("h_ResFPIXyPrime_CTF", "FPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTIByPrime_CTF("h_ResTIByPrime_CTF", "TIB Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);
  TH1D h_ResTIDyPrime_CTF("h_ResTIDyPrime_CTF", "TID Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);
  TH1D h_ResTOByPrime_CTF("h_ResTOByPrime_CTF", "TOB Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);
  TH1D h_ResTECyPrime_CTF("h_ResTECyPrime_CTF", "TEC Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);

  TH1D h_ResBPIXxPrime_CosmicTF("h_ResBPIXxPrime_CosmicTF", "BPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResFPIXxPrime_CosmicTF("h_ResFPIXxPrime_CosmicTF", "FPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTIBxPrime_CosmicTF("h_ResTIBxPrime_CosmicTF", "TIB Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTIDxPrime_CosmicTF("h_ResTIDxPrime_CosmicTF", "TID Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTOBxPrime_CosmicTF("h_ResTOBxPrime_CosmicTF", "TOB Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTECxPrime_CosmicTF("h_ResTECxPrime_CosmicTF", "TEC Track X-residuals;Res_{X'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResBPIXyPrime_CosmicTF("h_ResBPIXyPrime_CosmicTF", "BPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResFPIXyPrime_CosmicTF("h_ResFPIXyPrime_CosmicTF", "FPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -10., 10.);
  TH1D h_ResTIByPrime_CosmicTF("h_ResTIByPrime_CosmicTF", "TIB Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);
  TH1D h_ResTIDyPrime_CosmicTF("h_ResTIDyPrime_CosmicTF", "TID Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);
  TH1D h_ResTOByPrime_CosmicTF("h_ResTOByPrime_CosmicTF", "TOB Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);
  TH1D h_ResTECyPrime_CosmicTF("h_ResTECyPrime_CosmicTF", "TEC Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -40., 40.);

  //xxxxxx zoomed up residuals xxxxxx//
  TH1D h_ResBPIXxPrime_CTF_Zoom("h_ResBPIXxPrime_CTF_Zoom", "BPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResBPIXyPrime_CTF_Zoom("h_ResBPIXyPrime_CTF_Zoom", "BPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResFPIXxPrime_CTF_Zoom("h_ResFPIXxPrime_CTF_Zoom", "FPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResFPIXyPrime_CTF_Zoom("h_ResFPIXyPrime_CTF_Zoom", "FPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResTIBxPrime_CTF_Zoom("h_ResTIBxPrime_CTF_Zoom", "TIB Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResTOBxPrime_CTF_Zoom("h_ResTOBxPrime_CTF_Zoom", "TOB Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResBPIXxPrime_CosmicTF_Zoom("h_ResBPIXxPrime_CosmicTF_Zoom", "BPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResFPIXxPrime_CosmicTF_Zoom("h_ResFPIXxPrime_CosmicTF_Zoom", "FPIX Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResBPIXyPrime_CosmicTF_Zoom("h_ResBPIXyPrime_CosmicTF_Zoom", "BPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResFPIXyPrime_CosmicTF_Zoom("h_ResFPIXyPrime_CosmicTF_Zoom", "FPIX Track Y-residuals;Res_{Y'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResTIBxPrime_CosmicTF_Zoom("h_ResTIBxPrime_CosmicTF_Zoom", "TIB Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2);
  TH1D h_ResTOBxPrime_CosmicTF_Zoom("h_ResTOBxPrime_CosmicTF_Zoom", "TOB Track X-residuals;Res_{X'} (mm);a.u.", 100, -0.2, 0.2); 

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
              //xxxxx zoomed version xxxxx//
	      h_ResBPIXxPrime_CTF_Zoom.Fill(ResBPIXxPrime_CTF->at(res));
	      h_ResBPIXyPrime_CTF_Zoom.Fill(ResBPIXyPrime_CTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResBPIXxPrime_CosmicTF_Zoom.Fill(ResBPIXxPrime_CosmicTF->at(res));
	      h_ResBPIXyPrime_CosmicTF_Zoom.Fill(ResBPIXyPrime_CosmicTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResFPIXxPrime_CTF_Zoom.Fill(ResFPIXxPrime_CTF->at(res));
	      h_ResFPIXyPrime_CTF_Zoom.Fill(ResFPIXyPrime_CTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResFPIXxPrime_CosmicTF_Zoom.Fill(ResFPIXxPrime_CosmicTF->at(res));
	      h_ResFPIXyPrime_CosmicTF_Zoom.Fill(ResFPIXyPrime_CosmicTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResTIBxPrime_CTF_Zoom.Fill(ResTIBxPrime_CTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResTIBxPrime_CosmicTF_Zoom.Fill(ResTIBxPrime_CosmicTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResTOBxPrime_CTF_Zoom.Fill(ResTOBxPrime_CTF->at(res));
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
	      //xxxxx zoomed version xxxxx//
	      h_ResTOBxPrime_CosmicTF_Zoom.Fill(ResTOBxPrime_CosmicTF->at(res));
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

    } //while Event Loop
  std::cout<<"Matched Events: "<<nMatchedEvents<<std::endl;
  fclose(DeltaRIndices);

  gSystem->Exec("mkdir -p Normalized_Residual_Plots");


  //===============================================  PLOTTING  ==============================================//
  // TCanvas c("c", "c",556,244,486,668);
  TCanvas c("c", "c",556,214,661,641);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0); // Dont show Title
  c.Range(-14.31373,-72406.18,11.52941,442384.1);
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

  TGaxis::SetMaxDigits(3); //Setting the digit limits of axis labels

  TLegend *leg = new TLegend(0.6509863,0.6584967,0.9059181,0.879085,NULL,"brNDC");
  leg->SetBorderSize(1);
  leg->SetTextFont(42);
  leg->SetTextSize(0.03);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  
  TLegendEntry *entry=leg->AddEntry("NULL","CTF","lpf");
  entry->SetFillStyle(1001);
  entry->SetLineColor(4);
  entry->SetLineStyle(1);
  entry->SetLineWidth(3);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(1);
  entry->SetMarkerSize(1);
  entry->SetTextFont(62);
  
  entry=leg->AddEntry("NULL",TString::Format("Mean: %.4f mm",0.9999),"");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry->SetTextSize(0.025);
  
  entry=leg->AddEntry("NULL",TString::Format("RMS: %.3f mm",-0.9999),"");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry->SetTextSize(0.025);
  
  entry=leg->AddEntry("NULL","CosmicTF","lpflpf");
  entry->SetFillStyle(1001);
  entry->SetLineColor(2);
  entry->SetLineStyle(1);
  entry->SetLineWidth(3);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(1);
  entry->SetMarkerSize(1);
  entry->SetTextFont(62);
  entry->SetTextSize(0.03);
  
  entry=leg->AddEntry("NULL",TString::Format("Mean: %.4f mm",0.9999),"");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry->SetTextSize(0.025);
  
  entry=leg->AddEntry("NULL",TString::Format("RMS: %.3f mm",-0.9999),"");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry->SetTextSize(0.025); 
  
  TLatex Title = TLatex();
  Title.SetTextFont(42);
  Title.SetTextSize(0.04);

  TLatex detector = TLatex();
  detector.SetTextFont(62);
  detector.SetTextSize(0.06);
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  BPIX x' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResBPIXxPrime_CTF.SetLineColor(kBlue);
  h_ResBPIXxPrime_CTF.SetLineWidth(3);
  h_ResBPIXxPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResBPIXxPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResBPIXxPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResBPIXxPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResBPIXxPrime_CTF.DrawNormalized();
  
  h_ResBPIXxPrime_CosmicTF.SetLineColor(kRed);
  h_ResBPIXxPrime_CosmicTF.SetLineWidth(3);
  h_ResBPIXxPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "BPIX");
  
  c.SaveAs("ResBPIXxPrime_Normalized.png");
  c.SaveAs("ResBPIXxPrime_Normalized.C");
  gSystem->Exec("mv ResBPIXxPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResBPIXxPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  FPIX x' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResFPIXxPrime_CTF.SetLineColor(kBlue);
  h_ResFPIXxPrime_CTF.SetLineWidth(3);
  h_ResFPIXxPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResFPIXxPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResFPIXxPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResFPIXxPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResFPIXxPrime_CTF.DrawNormalized();
  
  h_ResFPIXxPrime_CosmicTF.SetLineColor(kRed);
  h_ResFPIXxPrime_CosmicTF.SetLineWidth(3);
  h_ResFPIXxPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "FPIX");
  
  c.SaveAs("ResFPIXxPrime_Normalized.png");
  c.SaveAs("ResFPIXxPrime_Normalized.C");
  gSystem->Exec("mv ResFPIXxPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResFPIXxPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TIB x' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTIBxPrime_CTF.SetLineColor(kBlue);
  h_ResTIBxPrime_CTF.SetLineWidth(3);
  h_ResTIBxPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTIBxPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTIBxPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTIBxPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTIBxPrime_CTF.DrawNormalized();
  
  h_ResTIBxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIBxPrime_CosmicTF.SetLineWidth(3);
  h_ResTIBxPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TIB");
  
  c.SaveAs("ResTIBxPrime_Normalized.png");
  c.SaveAs("ResTIBxPrime_Normalized.C");
  gSystem->Exec("mv ResTIBxPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTIBxPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TOB x' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTOBxPrime_CTF.SetLineColor(kBlue);
  h_ResTOBxPrime_CTF.SetLineWidth(3);
  h_ResTOBxPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTOBxPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTOBxPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTOBxPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTOBxPrime_CTF.DrawNormalized();
  
  h_ResTOBxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTOBxPrime_CosmicTF.SetLineWidth(3);
  h_ResTOBxPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TOB");
  
  c.SaveAs("ResTOBxPrime_Normalized.png");
  c.SaveAs("ResTOBxPrime_Normalized.C");
  gSystem->Exec("mv ResTOBxPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTOBxPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TID x' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTIDxPrime_CTF.SetLineColor(kBlue);
  h_ResTIDxPrime_CTF.SetLineWidth(3);
  h_ResTIDxPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTIDxPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTIDxPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTIDxPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTIDxPrime_CTF.DrawNormalized();
  
  h_ResTIDxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIDxPrime_CosmicTF.SetLineWidth(3);
  h_ResTIDxPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TID");
  
  c.SaveAs("ResTIDxPrime_Normalized.png");
  c.SaveAs("ResTIDxPrime_Normalized.C");
  gSystem->Exec("mv ResTIDxPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTIDxPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TEC x' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTECxPrime_CTF.SetLineColor(kBlue);
  h_ResTECxPrime_CTF.SetLineWidth(3);
  h_ResTECxPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTECxPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTECxPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTECxPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTECxPrime_CTF.DrawNormalized();
  
  h_ResTECxPrime_CosmicTF.SetLineColor(kRed);
  h_ResTECxPrime_CosmicTF.SetLineWidth(3);
  h_ResTECxPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TEC");
  
  c.SaveAs("ResTECxPrime_Normalized.png");
  c.SaveAs("ResTECxPrime_Normalized.C");
  gSystem->Exec("mv ResTECxPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTECxPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  BPIX y' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResBPIXyPrime_CTF.SetLineColor(kBlue);
  h_ResBPIXyPrime_CTF.SetLineWidth(3);
  h_ResBPIXyPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResBPIXyPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResBPIXyPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResBPIXyPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResBPIXyPrime_CTF.DrawNormalized();
  
  h_ResBPIXyPrime_CosmicTF.SetLineColor(kRed);
  h_ResBPIXyPrime_CosmicTF.SetLineWidth(3);
  h_ResBPIXyPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "BPIX");
  
  c.SaveAs("ResBPIXyPrime_Normalized.png");
  c.SaveAs("ResBPIXyPrime_Normalized.C");
  gSystem->Exec("mv ResBPIXyPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResBPIXyPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  FPIX y' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResFPIXyPrime_CTF.SetLineColor(kBlue);
  h_ResFPIXyPrime_CTF.SetLineWidth(3);
  h_ResFPIXyPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResFPIXyPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResFPIXyPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResFPIXyPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResFPIXyPrime_CTF.DrawNormalized();
  
  h_ResFPIXyPrime_CosmicTF.SetLineColor(kRed);
  h_ResFPIXyPrime_CosmicTF.SetLineWidth(3);
  h_ResFPIXyPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "FPIX");
  
  c.SaveAs("ResFPIXyPrime_Normalized.png");
  c.SaveAs("ResFPIXyPrime_Normalized.C");
  gSystem->Exec("mv ResFPIXyPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResFPIXyPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TIB y' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTIByPrime_CTF.SetLineColor(kBlue);
  h_ResTIByPrime_CTF.SetLineWidth(3);
  h_ResTIByPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTIByPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTIByPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTIByPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTIByPrime_CTF.DrawNormalized();
  
  h_ResTIByPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIByPrime_CosmicTF.SetLineWidth(3);
  h_ResTIByPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TIB");
  
  c.SaveAs("ResTIByPrime_Normalized.png");
  c.SaveAs("ResTIByPrime_Normalized.C");
  gSystem->Exec("mv ResTIByPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTIByPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TOB y' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTOByPrime_CTF.SetLineColor(kBlue);
  h_ResTOByPrime_CTF.SetLineWidth(3);
  h_ResTOByPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTOByPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTOByPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTOByPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTOByPrime_CTF.DrawNormalized();
  
  h_ResTOByPrime_CosmicTF.SetLineColor(kRed);
  h_ResTOByPrime_CosmicTF.SetLineWidth(3);
  h_ResTOByPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TOB");
  
  c.SaveAs("ResTOByPrime_Normalized.png");
  c.SaveAs("ResTOByPrime_Normalized.C");
  gSystem->Exec("mv ResTOByPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTOByPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TID y' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTIDyPrime_CTF.SetLineColor(kBlue);
  h_ResTIDyPrime_CTF.SetLineWidth(3);
  h_ResTIDyPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTIDyPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTIDyPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTIDyPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTIDyPrime_CTF.DrawNormalized();
  
  h_ResTIDyPrime_CosmicTF.SetLineColor(kRed);
  h_ResTIDyPrime_CosmicTF.SetLineWidth(3);
  h_ResTIDyPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TID");
  
  c.SaveAs("ResTIDyPrime_Normalized.png");
  c.SaveAs("ResTIDyPrime_Normalized.C");
  gSystem->Exec("mv ResTIDyPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTIDyPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TEC y' xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTECyPrime_CTF.SetLineColor(kBlue);
  h_ResTECyPrime_CTF.SetLineWidth(3);
  h_ResTECyPrime_CTF.GetXaxis()->SetLabelSize(0.05);
  h_ResTECyPrime_CTF.GetXaxis()->SetTitleSize(0.05); 
  h_ResTECyPrime_CTF.GetYaxis()->SetLabelSize(0.05);
  h_ResTECyPrime_CTF.GetYaxis()->SetTitleSize(0.06);
  h_ResTECyPrime_CTF.DrawNormalized();
  
  h_ResTECyPrime_CosmicTF.SetLineColor(kRed);
  h_ResTECyPrime_CosmicTF.SetLineWidth(3);
  h_ResTECyPrime_CosmicTF.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TEC");
  
  c.SaveAs("ResTECyPrime_Normalized.png");
  c.SaveAs("ResTECyPrime_Normalized.C");
  gSystem->Exec("mv ResTECyPrime_Normalized.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTECyPrime_Normalized.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  // ================================ ZOOMED UP RESIDUALS ==================================== // 

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  BPIX x' Zoom xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResBPIXxPrime_CTF_Zoom.SetLineColor(kBlue);
  h_ResBPIXxPrime_CTF_Zoom.SetLineWidth(3);
  h_ResBPIXxPrime_CTF_Zoom.GetXaxis()->SetLabelSize(0.05);
  h_ResBPIXxPrime_CTF_Zoom.GetXaxis()->SetTitleSize(0.05); 
  h_ResBPIXxPrime_CTF_Zoom.GetYaxis()->SetLabelSize(0.05);
  h_ResBPIXxPrime_CTF_Zoom.GetYaxis()->SetTitleSize(0.06);
  h_ResBPIXxPrime_CTF_Zoom.DrawNormalized();
  
  h_ResBPIXxPrime_CosmicTF_Zoom.SetLineColor(kRed);
  h_ResBPIXxPrime_CosmicTF_Zoom.SetLineWidth(3);
  h_ResBPIXxPrime_CosmicTF_Zoom.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "BPIX");
  
  c.SaveAs("ResBPIXxPrime_Normalized_Zoom.png");
  c.SaveAs("ResBPIXxPrime_Normalized_Zoom.C");
  gSystem->Exec("mv ResBPIXxPrime_Normalized_Zoom.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResBPIXxPrime_Normalized_Zoom.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  FPIX x' Zoom xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResFPIXxPrime_CTF_Zoom.SetLineColor(kBlue);
  h_ResFPIXxPrime_CTF_Zoom.SetLineWidth(3);
  h_ResFPIXxPrime_CTF_Zoom.GetXaxis()->SetLabelSize(0.05);
  h_ResFPIXxPrime_CTF_Zoom.GetXaxis()->SetTitleSize(0.05); 
  h_ResFPIXxPrime_CTF_Zoom.GetYaxis()->SetLabelSize(0.05);
  h_ResFPIXxPrime_CTF_Zoom.GetYaxis()->SetTitleSize(0.06);
  h_ResFPIXxPrime_CTF_Zoom.DrawNormalized();
  
  h_ResFPIXxPrime_CosmicTF_Zoom.SetLineColor(kRed);
  h_ResFPIXxPrime_CosmicTF_Zoom.SetLineWidth(3);
  h_ResFPIXxPrime_CosmicTF_Zoom.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "FPIX");
  
  c.SaveAs("ResFPIXxPrime_Normalized_Zoom.png");
  c.SaveAs("ResFPIXxPrime_Normalized_Zoom.C");
  gSystem->Exec("mv ResFPIXxPrime_Normalized_Zoom.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResFPIXxPrime_Normalized_Zoom.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  BPIX y' Zoom xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResBPIXyPrime_CTF_Zoom.SetLineColor(kBlue);
  h_ResBPIXyPrime_CTF_Zoom.SetLineWidth(3);
  h_ResBPIXyPrime_CTF_Zoom.GetXaxis()->SetLabelSize(0.05);
  h_ResBPIXyPrime_CTF_Zoom.GetXaxis()->SetTitleSize(0.05); 
  h_ResBPIXyPrime_CTF_Zoom.GetYaxis()->SetLabelSize(0.05);
  h_ResBPIXyPrime_CTF_Zoom.GetYaxis()->SetTitleSize(0.06);
  h_ResBPIXyPrime_CTF_Zoom.DrawNormalized();
  
  h_ResBPIXyPrime_CosmicTF_Zoom.SetLineColor(kRed);
  h_ResBPIXyPrime_CosmicTF_Zoom.SetLineWidth(3);
  h_ResBPIXyPrime_CosmicTF_Zoom.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "BPIX");
  
  c.SaveAs("ResBPIXyPrime_Normalized_Zoom.png");
  c.SaveAs("ResBPIXyPrime_Normalized_Zoom.C");
  gSystem->Exec("mv ResBPIXyPrime_Normalized_Zoom.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResBPIXyPrime_Normalized_Zoom.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  FPIX y' Zoom  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResFPIXyPrime_CTF_Zoom.SetLineColor(kBlue);
  h_ResFPIXyPrime_CTF_Zoom.SetLineWidth(3);
  h_ResFPIXyPrime_CTF_Zoom.GetXaxis()->SetLabelSize(0.05);
  h_ResFPIXyPrime_CTF_Zoom.GetXaxis()->SetTitleSize(0.05); 
  h_ResFPIXyPrime_CTF_Zoom.GetYaxis()->SetLabelSize(0.05);
  h_ResFPIXyPrime_CTF_Zoom.GetYaxis()->SetTitleSize(0.06);
  h_ResFPIXyPrime_CTF_Zoom.DrawNormalized();
  
  h_ResFPIXyPrime_CosmicTF_Zoom.SetLineColor(kRed);
  h_ResFPIXyPrime_CosmicTF_Zoom.SetLineWidth(3);
  h_ResFPIXyPrime_CosmicTF_Zoom.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "FPIX");
  
  c.SaveAs("ResFPIXyPrime_Normalized_Zoom.png");
  c.SaveAs("ResFPIXyPrime_Normalized_Zoom.C");
  gSystem->Exec("mv ResFPIXyPrime_Normalized_Zoom.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResFPIXyPrime_Normalized_Zoom.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TIB x' Zoom xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTIBxPrime_CTF_Zoom.SetLineColor(kBlue);
  h_ResTIBxPrime_CTF_Zoom.SetLineWidth(3);
  h_ResTIBxPrime_CTF_Zoom.GetXaxis()->SetLabelSize(0.05);
  h_ResTIBxPrime_CTF_Zoom.GetXaxis()->SetTitleSize(0.05); 
  h_ResTIBxPrime_CTF_Zoom.GetYaxis()->SetLabelSize(0.05);
  h_ResTIBxPrime_CTF_Zoom.GetYaxis()->SetTitleSize(0.06);
  h_ResTIBxPrime_CTF_Zoom.DrawNormalized();
  
  h_ResTIBxPrime_CosmicTF_Zoom.SetLineColor(kRed);
  h_ResTIBxPrime_CosmicTF_Zoom.SetLineWidth(3);
  h_ResTIBxPrime_CosmicTF_Zoom.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TIB");
  
  c.SaveAs("ResTIBxPrime_Normalized_Zoom.png");
  c.SaveAs("ResTIBxPrime_Normalized_Zoom.C");
  gSystem->Exec("mv ResTIBxPrime_Normalized_Zoom.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTIBxPrime_Normalized_Zoom.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TOB x' Zoom xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
  c.SetGrid();
  h_ResTOBxPrime_CTF_Zoom.SetLineColor(kBlue);
  h_ResTOBxPrime_CTF_Zoom.SetLineWidth(3);
  h_ResTOBxPrime_CTF_Zoom.GetXaxis()->SetLabelSize(0.05);
  h_ResTOBxPrime_CTF_Zoom.GetXaxis()->SetTitleSize(0.05); 
  h_ResTOBxPrime_CTF_Zoom.GetYaxis()->SetLabelSize(0.05);
  h_ResTOBxPrime_CTF_Zoom.GetYaxis()->SetTitleSize(0.06);
  h_ResTOBxPrime_CTF_Zoom.DrawNormalized();
  
  h_ResTOBxPrime_CosmicTF_Zoom.SetLineColor(kRed);
  h_ResTOBxPrime_CosmicTF_Zoom.SetLineWidth(3);
  h_ResTOBxPrime_CosmicTF_Zoom.DrawNormalized("same");
  
  leg->Draw();
  Title.DrawLatexNDC(0.65, 0.94, "cosmic rays (2018)");
  detector.DrawLatexNDC(0.25, .8, "TOB");
  
  c.SaveAs("ResTOBxPrime_Normalized_Zoom.png");
  c.SaveAs("ResTOBxPrime_Normalized_Zoom.C");
  gSystem->Exec("mv ResTOBxPrime_Normalized_Zoom.png Normalized_Residual_Plots");
  gSystem->Exec("mv ResTOBxPrime_Normalized_Zoom.C Normalized_Residual_Plots");
  c.Clear();
  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//

}

