using namespace ROOT::VecOps;

void CheckResiduals2()
{
    
  TFile *file1 = new TFile("CTF_Residuals.root");

  FILE *CheckResiduals;
  CheckResiduals = fopen("CheckResiduals.csv","w"); // Information about events passing the cut of DeltaR, charge, matching 
 
  TTree *tree1;
  tree1 = (TTree*)file1->Get("demo/Event");
   
  //========================Local varibles to store parameters from tree===================//
  vector<double>  *pt_CTF;
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
  pt_CTF=0;
  nHitsValid_CTF=0; nHitsBPIX_CTF=0;  nHitsFPIX_CTF=0;  nHitsTIB_CTF=0;  nHitsTID_CTF=0;  nHitsTOB_CTF=0;  nHitsTEC_CTF=0;
  ResBPIXxPrime_CTF=0; ResFPIXxPrime_CTF=0; ResTIBxPrime_CTF=0; ResTOBxPrime_CTF=0; ResTIDxPrime_CTF=0;  ResTECxPrime_CTF=0;
  ResBPIXyPrime_CTF=0; ResFPIXyPrime_CTF=0; ResTIByPrime_CTF=0; ResTOByPrime_CTF=0; ResTIDyPrime_CTF=0;  ResTECyPrime_CTF=0;
  
  //==============================Setting tree branches to local varibles================//
  tree1->SetBranchAddress("pt", &pt_CTF);
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

  TCanvas c("c","c",800,600);
  TH1D h_ResBPIXxPrime_CTF("h_ResBPIXxPrime", "BPIX Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResFPIXxPrime_CTF("h_ResFPIXxPrime", "FPIX Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIBxPrime_CTF("h_ResTIBxPrime", "TIB Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIDxPrime_CTF("h_ResTIDxPrime", "TID Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTOBxPrime_CTF("h_ResTOBxPrime", "TOB Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTECxPrime_CTF("h_ResTECxPrime", "TEC Track X-residuals;Res_{X'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResBPIXyPrime_CTF("h_ResBPIXyPrime", "BPIX Track Y-residuals;Res_{Y'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResFPIXyPrime_CTF("h_ResFPIXyPrime", "FPIX Track Y-residuals;Res_{Y'} (mm);Entries", 100, -10., 10.);
  TH1D h_ResTIByPrime_CTF("h_ResTIByPrime", "TIB Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTIDyPrime_CTF("h_ResTIDyPrime", "TID Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTOByPrime_CTF("h_ResTOByPrime", "TOB Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);
  TH1D h_ResTECyPrime_CTF("h_ResTECyPrime", "TEC Track Y-residuals;Res_{Y'} (mm);Entries", 100, -40., 40.);  
 
  int TrackNo_CTF=0;

  

  fprintf(CheckResiduals,"Event,HitsPIXEL,HitsBPIX,ResBPIX,HitsFPIX,ResFPIX,HitsTIB,ResTIB,HitsTOB,ResTOB,HitsTID,ResTID,HitsTEC,ResTEC,ValidHits,TotalHits,TotalRes,Residual \n");
  Long64_t n1 = tree1->GetEntriesFast();
  for (int jentry=0; jentry<n1; jentry++) //Event Loop
    {
      int HitsPIXEL=0,HitsBPIX=0,ResBPIX=0,HitsFPIX=0,ResFPIX=0,HitsTIB=0,ResTIB=0,HitsTOB=0,ResTOB=0,HitsTID=0,ResTID=0,HitsTEC=0,ResTEC=0,ValidHits=0,TotalHits=0,TotalRes=0,residual=0;
      
      //std::cout<<"Analysing event: "<<jentry<<std::endl;      
      tree1->GetEntry(jentry); //Get first Event of tree 1
      
      //CHECKING IN CSV
      for(TrackNo_CTF=0;TrackNo_CTF< pt_CTF->size();TrackNo_CTF++)
	{	  
	  HitsBPIX=HitsBPIX+nHitsBPIX_CTF->at(TrackNo_CTF);
	  HitsFPIX=HitsFPIX+nHitsFPIX_CTF->at(TrackNo_CTF);
	  HitsTIB=HitsTIB+nHitsTIB_CTF->at(TrackNo_CTF);
	  HitsTOB=HitsTOB+nHitsTOB_CTF->at(TrackNo_CTF);
	  HitsTID=HitsTID+nHitsTID_CTF->at(TrackNo_CTF);
	  HitsTEC=HitsTEC+nHitsTEC_CTF->at(TrackNo_CTF);
	  TotalHits=HitsBPIX+HitsFPIX+HitsTIB+HitsTOB+HitsTID+HitsTEC;
	  ValidHits=ValidHits+nHitsValid_CTF->at(TrackNo_CTF);
	}
      TrackNo_CTF=0;
      
      // std::cout<<"NHITS TIB at 0 "<<nHitsTIB_CTF->at(0)<<std::endl;
      int nTracksinEvent=pt_CTF->size();//No of tracks in event
      
      //std::cout<<"NHITS TIB Size: "<<nHitsTIB_CTF->size()<<std::endl;
      
      int x,y; //Variables for getting getting the index diving the tracks in Residual Branch
      //   nHitsBPIX Branch for event 1:  | 2 | 3 | where 2 hits in Tk1 and 3 in Tk2
      //   Res Branch: | Res1 Tk1 | Res2 Tk1 | Res1 Tk2 | Res2 Tk2 | Res3 Tk2 |  
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS BPIX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResBPIXxPrime_CTF->size()!=0)
	{
	  if(TrackNo_CTF==0) {x=0;}
	  else { x=nHitsBPIX_CTF->at(TrackNo_CTF-1); }
	  y=nHitsBPIX_CTF->at(TrackNo_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResBPIXxPrime_CTF.Fill(ResBPIXxPrime_CTF->at(res));
	      h_ResBPIXyPrime_CTF.Fill(ResBPIXyPrime_CTF->at(res));
	      residual++;
	    }	  
	  ResBPIX=ResBPIXxPrime_CTF->size();
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS FPIX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResFPIXxPrime_CTF->size()!=0)
	{
	  if(TrackNo_CTF==0) {x=0;}
	  else { x=nHitsFPIX_CTF->at(TrackNo_CTF-1); }
	  y=nHitsFPIX_CTF->at(TrackNo_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResFPIXxPrime_CTF.Fill(ResFPIXxPrime_CTF->at(res));
	      h_ResFPIXyPrime_CTF.Fill(ResFPIXyPrime_CTF->at(res));
	      residual++;
	    }  
	  ResFPIX=ResFPIXxPrime_CTF->size();
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TIB XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTIBxPrime_CTF->size()!=0)
	{
	  if(TrackNo_CTF==0) {x=0;}
	  else { x=nHitsTIB_CTF->at(TrackNo_CTF-1); }
	  //    std::cout<<"Before y " <<std::endl;
	  y=nHitsTIB_CTF->at(TrackNo_CTF);
	  //    std::cout<<"x : "<<x<<std::endl;
	  //   std::cout<<"y : "<<y<<std::endl;
	  for(int res=x; res<(x+y) ;res++)
	    {
	      // std::cout<<"Res TIB at "<<res<<" : "<<ResTIBxPrime_CTF->at(res)<<std::endl;
	      h_ResTIBxPrime_CTF.Fill(ResTIBxPrime_CTF->at(res));
	      h_ResTIByPrime_CTF.Fill(ResTIByPrime_CTF->at(res));
	      residual++;
	    }
	  ResTIB=ResTIBxPrime_CTF->size();
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TID XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTIDxPrime_CTF->size()!=0)
	{
	  if(TrackNo_CTF==0) {x=0;}
	  else { x=nHitsTID_CTF->at(TrackNo_CTF-1); }
	  y=nHitsTID_CTF->at(TrackNo_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTIDxPrime_CTF.Fill(ResTIDxPrime_CTF->at(res));
	      h_ResTIDyPrime_CTF.Fill(ResTIDyPrime_CTF->at(res));
	      residual++;
	    }
	  ResTID=ResTIDxPrime_CTF->size();
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TOB XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTOBxPrime_CTF->size()!=0)
	{
	  if(TrackNo_CTF==0) {x=0;}
	  else { x=nHitsTOB_CTF->at(TrackNo_CTF-1); }
	  y=nHitsTOB_CTF->at(TrackNo_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTOBxPrime_CTF.Fill(ResTOBxPrime_CTF->at(res));
	      h_ResTOByPrime_CTF.Fill(ResTOByPrime_CTF->at(res));
	      residual++;
	    }
	  ResTOB=ResTOBxPrime_CTF->size();
	}
      
      //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx RESIDUALS TEC XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
      if(ResTECxPrime_CTF->size()!=0)
	{
	  if(TrackNo_CTF==0) {x=0;}
	  else { x=nHitsTEC_CTF->at(TrackNo_CTF-1); }
	  y=nHitsTEC_CTF->at(TrackNo_CTF);
	  for(int res=x; res<(x+y) ;res++)
	    {
	      h_ResTECxPrime_CTF.Fill(ResTECxPrime_CTF->at(res));
	      h_ResTECyPrime_CTF.Fill(ResTECyPrime_CTF->at(res));
	      residual++;
	    }
	  ResTEC=ResTECxPrime_CTF->size();
	}
      TotalRes=ResBPIX+ResFPIX+ResTIB+ResTOB+ResTID+ResTEC;
      fprintf(CheckResiduals,"%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i \n",jentry,HitsPIXEL,HitsBPIX,ResBPIX,HitsFPIX,ResFPIX,HitsTIB,ResTIB,HitsTOB,ResTOB,HitsTID,ResTID,HitsTEC,ResTEC,ValidHits,TotalHits,TotalRes,residual);
    }// Event Loop 
  
  c.SetGrid();   
  h_ResBPIXxPrime_CTF.Draw();
  c.SaveAs("ResBPIXxPrime.png");
  gSystem->Exec("mv ResBPIXxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResFPIXxPrime_CTF.Draw();
  c.SaveAs("ResFPIXxPrime.png");
  gSystem->Exec("mv ResFPIXxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTIBxPrime_CTF.Draw();
  c.SaveAs("ResTIBxPrime.png");
  gSystem->Exec("mv ResTIBxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTOBxPrime_CTF.Draw();
  c.SaveAs("ResTOBxPrime.png");
  gSystem->Exec("mv ResTOBxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTIDxPrime_CTF.Draw();
  c.SaveAs("ResTIDxPrime.png");
  gSystem->Exec("mv ResTIDxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTECxPrime_CTF.Draw();
  c.SaveAs("ResTECxPrime.png");
  gSystem->Exec("mv ResTECxPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResBPIXyPrime_CTF.Draw();
  c.SaveAs("ResBPIXyPrime.png");
  gSystem->Exec("mv ResBPIXyPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResFPIXyPrime_CTF.Draw();
  c.SaveAs("ResFPIXyPrime.png");
  gSystem->Exec("mv ResFPIXyPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTIByPrime_CTF.Draw();
  c.SaveAs("ResTIByPrime.png");
  gSystem->Exec("mv ResTIByPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTOByPrime_CTF.Draw();
  c.SaveAs("ResTOByPrime.png");
  gSystem->Exec("mv ResTOByPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTIDyPrime_CTF.Draw();
  c.SaveAs("ResTIDyPrime.png");
  gSystem->Exec("mv ResTIDyPrime.png Kinematical_Plots");
  c.Clear();

  c.SetGrid(); 
  h_ResTECyPrime_CTF.Draw();
  c.SaveAs("ResTECyPrime.png");
  gSystem->Exec("mv ResTECyPrime.png Kinematical_Plots");
  c.Clear();

  fclose(CheckResiduals);
 
}
