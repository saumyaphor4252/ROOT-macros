void VennCollection()
{

  // TString Allfiles[3] = {"Cosmic_rate_tuple1.root","Cosmic_rate_tuple2.root","Cosmic_rate_tuple3.root"};

 
  TFile *file1 = new TFile("CTF_Diana_1_WithoutR.root");
  TFile *file2 = new TFile("CosmicTF_Diana_1_WithoutR.root");
  TFile *file3 = new TFile("Regional_Diana_1_WithoutR.root");
  
  TTree *tree1;
  TTree *tree2;
  TTree *tree3;

  tree1 = (TTree*)file1->Get("demo/Event");
  tree2 = (TTree*)file2->Get("demo/Event");
  tree3 = (TTree*)file3->Get("demo/Event");  

  int ntrk_CTF, ntrk_CosmicTF, ntrk_Regional;
  int n1Only=0,n2Only=0,n3Only=0,n1Andn2=0,n2Andn3=0,n1Andn3=0,n1n2Andn3=0,nTotal=0,none=0;
 
  tree1->SetBranchAddress("nTracks", &ntrk_CTF);
  tree2->SetBranchAddress("nTracks", &ntrk_CosmicTF);
  tree3->SetBranchAddress("nTracks", &ntrk_Regional);
  
  //------------------------------------------------1st Vector v_ntrck1----------------------------------------------    
  Long64_t n1 = tree1->GetEntriesFast();
  Long64_t n2 = tree2->GetEntriesFast();
  Long64_t n3 = tree3->GetEntriesFast();
  for (Long64_t jentry=0; jentry<n1; jentry++) 
    {
      tree1->GetEntry(jentry); 
      tree2->GetEntry(jentry); 
      tree3->GetEntry(jentry);

      if( ntrk_CTF>0 &&  ntrk_CosmicTF==0 &&  ntrk_Regional==0 )
	{
	  n1Only++;
	}
      if( ntrk_CTF==0 &&  ntrk_CosmicTF>0 &&  ntrk_Regional==0 )
	{
	  n2Only++;
	}
      if( ntrk_CTF==0 &&  ntrk_CosmicTF==0 &&  ntrk_Regional>0 )
	{
	  n3Only++;
	}
      if( ntrk_CTF>0 &&  ntrk_CosmicTF>0 &&  ntrk_Regional==0 )
	{
	  n1Andn2++;
	}
      if( ntrk_CTF>0 &&  ntrk_CosmicTF==0 &&  ntrk_Regional>0 )
	{
	  n1Andn3++;
	}
      if( ntrk_CTF==0 &&  ntrk_CosmicTF>0 &&  ntrk_Regional>0 )
	{
	  n2Andn3++;
	}
       if( ntrk_CTF>0 &&  ntrk_CosmicTF>0 &&  ntrk_Regional>0 )
	{
	  n1n2Andn3++;
	}
        if( ntrk_CTF==0 &&  ntrk_CosmicTF==0 &&  ntrk_Regional==0 )
	{
	  none++;
	}
       nTotal++;
      
    }
  
  std::cout<<"Events CTF: "<<n1<<std::endl;
  std::cout<<"Events CosmicTF: "<<n2<<std::endl;
  std::cout<<"Events Regional: "<<n3<<std::endl;
  
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
