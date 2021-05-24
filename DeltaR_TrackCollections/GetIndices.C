using namespace ROOT::VecOps;

void GetIndices()
{
  //We have a csv file which has the structure "Event idx CosmicTF i, idx Event CTF j"
  //We want to loop over the events in CTF(j) and find a track matching in CosmicTF(i) then plot then store the indices of both in another csv file
  //The reason for looping over CTF is because tracks in CTF>=CosmicTF for every event. 
  //Finally we loop over those track indices to plot the kinematic and residual distributions for the matching tracks"


  TFile *file1 = new TFile("CRAB_CTF_Residuals.root");
  TFile *file2 = new TFile("CRAB_CosmicTF_Residuals.root");
  TTree *tree1, *tree2;
  tree1 = (TTree*)file1->Get("demo/Event");
  tree2 = (TTree*)file2->Get("demo/Event");

   //========================Local varibles to store parameters from tree===================//
  vector<double>  *charge_CTF;
  vector<double>  *eta_CTF;
  vector<double>  *phi_CTF;
 
  charge_CTF=0; eta_CTF=0; phi_CTF=0;
  
  //=======tree2======//
  vector<double>  *charge_CosmicTF;
  vector<double>  *eta_CosmicTF;
  vector<double>  *phi_CosmicTF;
  
  charge_CosmicTF=0; eta_CosmicTF=0; phi_CosmicTF=0;
  
  //=======RVec Definition=======//
  RVec<double> eta1,eta2,phi1,phi2,TempDeltaR;

  //==============================Setting tree branches to local varibles================//
  tree1->SetBranchAddress("charge", &charge_CTF);
  tree1->SetBranchAddress("eta", &eta_CTF);
  tree1->SetBranchAddress("phi", &phi_CTF);
  
  tree2->SetBranchAddress("charge", &charge_CosmicTF);
  tree2->SetBranchAddress("eta", &eta_CosmicTF);
  tree2->SetBranchAddress("phi", &phi_CosmicTF);
  
  //----------Loop for Track matching: At the end of this loop the events no, trackCTF ,trackCosmicTF will be stored in a csv file "DeltaREventIndices":--------------
  Long64_t n1 = tree1->GetEntriesFast();
  Long64_t n2 = tree2->GetEntriesFast();
  std::cout<<"Events in CTF :"<<n1<<std::endl;
  std::cout<<"Events in CosmicTF: "<<n2<<std::endl;
    
  //get file
  //loop over the file to read
  //for each event perform track matching
  
  FILE *EventIndices,*DeltaRIndices;
  EventIndices = fopen("Output_Residuals_CosmicTF_Residuals_CTF.csv","r");
  DeltaRIndices = fopen("Track_Matching_Indices.csv","w");
  int n=0; int Idx_Event_CosmicTF; float Idx_Event_CTF;
  while(!feof(EventIndices))
    {
      fscanf(EventIndices,"%i,%f\n",&Idx_Event_CosmicTF,&Idx_Event_CTF);
      if(n<10) std::cout<<Idx_Event_CosmicTF<<" : "<<Idx_Event_CTF<<std::endl;
      n++;

      tree1->GetEntry(Idx_Event_CTF); //Get first Event CTF
      tree2->GetEntry(Idx_Event_CosmicTF); //CosmicTF

      //xxxxxxxxxxxxxxxxxxxx---Matching a track in CosmicTF with a track in CTF (Tracks in CTF>Tracks in CosmicTF always!!)---xxxxxxxxxxxxxxxxxxxxxx//
      //Check if theres atleast 1 track in both collections
      if(! (phi_CosmicTF->size()>0 && phi_CTF->size()>0) )
	{
	  continue;
	}
      
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
		continue;
	      }                
	    eta2.push_back(eta_CTF->at(j));
	    phi2.push_back(phi_CTF->at(j));

	    //Evaluate DeltaR for a gicen pair of CTF & CosmicTF and store in a temprory vector TempDEltaR
	    TempDeltaR.push_back(DeltaR(eta1,eta2,phi1,phi2)[0]); 	    	    
	  }   //CTF Track Loop j

	//Find Min DeltaR for the CosmicTF track 
        float min=Min(TempDeltaR);
      	if(min>0.4) // Delta R cut 
	  { 
	    continue;
	  }

	int CTF_trk_index=ArgMin(TempDeltaR);
	fprintf(DeltaRIndices,"%i,%i,%f,%i \n",Idx_Event_CosmicTF,i,Idx_Event_CTF, CTF_trk_index);
      }// CosmicTF track Loop i	    
      
    } //while loop for reading event Indices
  
  std::cout<<"TotalEvents: "<<n<<std::endl;
  //5683968 events both in CTF & CosmicTF
  fclose(EventIndices);
  fclose(DeltaRIndices);
}
