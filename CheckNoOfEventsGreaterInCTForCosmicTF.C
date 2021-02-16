//Before perform matching of tracks this script checks that whether it would be more beneficial to match CTF in CosmicTF or other way round.
// Conclusion: For each event having tracks in both CTF & CosmicTF, we find that  

{

  // TString Allfiles[3] = {"Cosmic_rate_tuple1.root","Cosmic_rate_tuple2.root","Cosmic_rate_tuple3.root"};

 
  TFile *file1 = new TFile("CTF_2018.root");
  TFile *file2 = new TFile("CosmicTF_2018.root");
    
  TTree *tree1;
  TTree *tree2;
  
  tree1 = (TTree*)file1->Get("cosmicRateAnalyzer/Event");
  tree2 = (TTree*)file2->Get("cosmicRateAnalyzer/Event");

  int ntrk1,ntrk2,ntrk3;
  int nTotalEvents1=0, nTotalEvents2=0, nCTFmore=0, nCosmicTFmore=0, nEqualTracks=0, Remaining=0,nEventsNotConsidering=0, nTracksInBoth=0;
  
  tree1->SetBranchAddress("ntrk", &ntrk1);
  tree2->SetBranchAddress("ntrk", &ntrk2);
 
  vector<double>  v_ntrk1;
  vector<double>  v_ntrk2;
   
  //------------------------------------------------1st Vector v_ntrck1----------------------------------------------    
  Long64_t n1 = tree1->GetEntriesFast();
  for (Long64_t jentry=0; jentry<n1; jentry++) 
    {
      tree1->GetEntry(jentry); 
      v_ntrk1.push_back(ntrk1);
      tree2->GetEntry(jentry); 
      v_ntrk2.push_back(ntrk2);
      nTotalEvents1;
    }
  
  std::cout<<v_ntrk1.size()<<endl;
  std::cout<<v_ntrk2.size()<<endl;
  
  for (Long64_t jentry=0; jentry<n1; jentry++) //Event Loop
    {
      if(v_ntrk1.at(jentry)>0 && v_ntrk2.at(jentry)>0)
	{
	  nTracksInBoth++;
	  if(v_ntrk1.at(jentry)>v_ntrk2.at(jentry))
	    {nCTFmore++;}
	  else if(v_ntrk1.at(jentry)<v_ntrk2.at(jentry))
	    {nCosmicTFmore++;}
	  else if(v_ntrk1.at(jentry)==v_ntrk2.at(jentry))
	    {nEqualTracks++;}
	  else
	    {Remaining++;}
	}
      else
	{ nEventsNotConsidering++;}
      nTotalEvents2++;
    }

  std::cout<<"Total Events from filling vectors"<<nTotalEvents1<<std::endl;
  std::cout<<"Total Events from vectors"<<nTotalEvents2<<std::endl;
  std::cout<<"Events where CTFtracks&CosmicTF tracks>0: "<<nTracksInBoth<<std::endl;
  std::cout<<"Events where tracks from CTF>CosmicTF : "<<nCTFmore<<std::endl;
  std::cout<<"Events where tracks from CTF<CosmicTF : "<<nCosmicTFmore<<std::endl;
  std::cout<<"Events where tracks from CTF=CosmicTF : "<<nEqualTracks<<std::endl;
  std::cout<<"Events where CTF&CosmicTF not >0 :"<<nEventsNotConsidering<<std::endl;
  std::cout<<"Events Remining with either"<<Remaining<<std::endl;
 
}
