#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
void MagFieldPIXELtracks() 
{ 

    TFile *file = new TFile("Hits_Commissioning2016.root");
  
    TTree *tree;
    tree = (TTree*)file->Get("cosmicRateAnalyzer/Event");
    vector<double> *MagField,*HitsPIXEL,*HitsBPIX,*HitsFPIX;
    int ntrk;
    tree->SetBranchAddress("MagField", &MagField);
    tree->SetBranchAddress("ntrk", &ntrk);
    tree->SetBranchAddress("nHitsPIXEL",&HitsPIXEL);
    tree->SetBranchAddress("nHitsBPIX",&HitsBPIX);
    tree->SetBranchAddress("nHitsFPIX",&HitsFPIX);
    MagField=0; HitsPIXEL=0; HitsBPIX=0; HitsFPIX=0;

    int tracksWith0MF=0, tracksNotwith0MF=0, PIXELtracks=0, NonPIXELtracks=0, NegativePIXELtracks=0, BFPIXtracks=0, noPIXtracks=0;
  
    Long64_t n = tree->GetEntriesFast();
    //std::cout<<"Events: "<<n<<std::endl;
    
    for (Long64_t jentry=0; jentry<n; jentry++) 
    {
      tree->GetEntry(jentry);
     
      for (int k = 0; k < MagField->size() ; k++)			// Loop to calculate Kinematical distributions
      {
        if(MagField->at(k)==0)
	  {
	    tracksWith0MF++;
	    for(int trk=0 ; trk<ntrk ; trk++)
            {
                    if(HitsPIXEL->at(trk)>0){ PIXELtracks++; }
	            if(HitsPIXEL->at(trk)==0){ NonPIXELtracks++; }
	            if(HitsPIXEL->at(trk)<0){ NegativePIXELtracks++; }
	            if(HitsBPIX->at(trk)>0 || HitsFPIX->at(trk)>0) { BFPIXtracks++; }
	            else if(HitsBPIX->at(trk)<=0 || HitsFPIX->at(trk)<=0) { noPIXtracks++; }
		  
	     }  //Tracks	    
	  }
	else if(MagField->at(k)!=0){ tracksNotwith0MF++; }
      }

      /*	//----------PIXEL Hits---------------//
	if(MagField->at(k)==0)
	{
	 for (int hits = 0; hits < HitsPIXEL->size() ; hits++)
	  {
            if(HitsPIXEL->at(hits)>0){ PIXELtracks++; }
	    if(HitsPIXEL->at(hits)==0){ NonPIXELtracks++; }
	    if(HitsPIXEL->at(hits)<0){ NegativePIXELtracks++; }
	    if(HitsBPIX->at(hits)>0 || HitsFPIX->at(hits)>0) { BFPIXtracks++; }
	    else if(HitsBPIX->at(hits)<=0 || HitsFPIX->at(hits)<=0) { noPIXtracks++; }
	  }// PIXEL Hits
	  }*/          
    }
 
    std::cout<<"---------PIX Tracks---------"<<std::endl;
    std::cout<<"USING PIXEL Tracks"<<std::endl;
    std::cout<<"Tracks with PIXEL Hits>0 :"<<PIXELtracks<<std::endl;
    std::cout<<"Tracks with PIXEL hits=0 :"<<NonPIXELtracks<<std::endl;
    std::cout<<"TRacks with negative PIXEL Hits :"<<NegativePIXELtracks<<std::endl;
    std::cout<<"Using BPIX and FPIX separately"<<std::endl;
    std::cout<<"Tracks with either BPIX or FPIX hit: "<<BFPIXtracks<<std::endl;
    std::cout<<"Tracks with no BPIX or FPIX hit: "<<noPIXtracks<<std::endl;
} 
