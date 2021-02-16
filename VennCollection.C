void VennCollection()
{

  // TString Allfiles[3] = {"Cosmic_rate_tuple1.root","Cosmic_rate_tuple2.root","Cosmic_rate_tuple3.root"};

 
  TFile *file1 = new TFile("Cosmic_rate_tuple_2018_A.root");
  TFile *file2 = new TFile("Cosmic_rate_tuple_2018_B.root");
  TFile *file3 = new TFile("Cosmic_rate_tuple_2018_C.root");
  
  TTree *tree1;
  TTree *tree2;
  TTree *tree3;

  tree1 = (TTree*)file1->Get("cosmicRateAnalyzer/Event");
  tree2 = (TTree*)file2->Get("cosmicRateAnalyzer/Event");
  tree3 = (TTree*)file3->Get("cosmicRateAnalyzer/Event");  

  int ntrk1,ntrk2,ntrk3;
  int n1Only=0,n2Only=0,n3Only=0,n1Andn2=0,n2Andn3=0,n1Andn3=0,n1n2Andn3=0,nTotal=0,none=0;
  
  tree1->SetBranchAddress("ntrk", &ntrk1);
  tree2->SetBranchAddress("ntrk", &ntrk2);
  tree3->SetBranchAddress("ntrk", &ntrk3);

  vector<double>  v_ntrk1;
  vector<double>  v_ntrk2;
  vector<double>  v_ntrk3;
  
  //------------------------------------------------1st Vector v_ntrck1----------------------------------------------    
  Long64_t n1 = tree1->GetEntriesFast();
  for (Long64_t jentry=0; jentry<n1; jentry++) 
    {
      tree1->GetEntry(jentry); 
      v_ntrk1.push_back(ntrk1);
      tree2->GetEntry(jentry); 
      v_ntrk2.push_back(ntrk2);
      tree3->GetEntry(jentry); 
      v_ntrk3.push_back(ntrk3);
    }
  
  std::cout<<v_ntrk1.size()<<endl;
  std::cout<<v_ntrk2.size()<<endl;
  std::cout<<v_ntrk3.size()<<endl;
  
  for (Long64_t jentry=0; jentry<n1; jentry++) 
    {
      if(v_ntrk1.at(jentry)>0 && v_ntrk2.at(jentry)==0 && v_ntrk3.at(jentry)==0  )
	{
	  n1Only++;
	}
      if(v_ntrk1.at(jentry)==0 && v_ntrk2.at(jentry)>0 && v_ntrk3.at(jentry)==0  )
	{
	  n2Only++;
	}
      if(v_ntrk1.at(jentry)==0 && v_ntrk2.at(jentry)==0 && v_ntrk3.at(jentry)>0  )
	{
	  n2Only++;
	}
      if(v_ntrk1.at(jentry)>0 && v_ntrk2.at(jentry)>0 && v_ntrk3.at(jentry)==0  )
	{
	  n1Andn2++;
	}
      if(v_ntrk1.at(jentry)>0 && v_ntrk2.at(jentry)==0 && v_ntrk3.at(jentry)>0  )
	{
	  n1Andn3++;
	}
      if(v_ntrk1.at(jentry)==0 && v_ntrk2.at(jentry)>0 && v_ntrk3.at(jentry)>0  )
	{
	  n2Andn3++;
	}
       if(v_ntrk1.at(jentry)>0 && v_ntrk2.at(jentry)>0 && v_ntrk3.at(jentry)>0  )
	{
	  n1n2Andn3++;
	}
        if(v_ntrk1.at(jentry)==0 && v_ntrk2.at(jentry)==0 && v_ntrk3.at(jentry)==0  )
	{
	  none++;
	}
       nTotal++;     
    }

  std::cout<<"Total Events"<<nTotal<<endl;
  std::cout<<"Events with tracks from CTF Only: "<<n1Only<<endl;
  std::cout<<"Events with tracks from CosmicTF Only: "<<n2Only<<endl;
  std::cout<<"Events with tracks from Regional Only: "<<n3Only<<endl;
  std::cout<<"Events with tracks from CTF and CosmicTF but not Regional: "<<n1Andn2<<endl;
  std::cout<<"Events with tracks from CTF and Regional but not CosmicTF: "<<n1Andn3<<endl;
  std::cout<<"Events with tracks from CosmicTF and Regional but not CTF: "<<n2Andn3<<endl;
  std::cout<<"Events with tracks from All 3 collections: "<<n1n2Andn3<<endl;
  std::cout<<"Events with tracks from no collections: "<<none<<endl;
 
}
