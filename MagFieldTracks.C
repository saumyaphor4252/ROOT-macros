#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
void MagFieldTracks() 
{ 

    TFile *file = new TFile("InterfillAllPrompt2018.root");
    //Map container 
    map<double, int> magTracks;
    
    TTree *tree;
    tree = (TTree*)file->Get("cosmicRateAnalyzer/Event");
    vector<double> *MagField;
    int ntrk;
    tree->SetBranchAddress("MagField", &MagField);
    tree->SetBranchAddress("ntrk", &ntrk);
    MagField=0;
  
    Long64_t n = tree->GetEntriesFast();
    //std::cout<<"Events: "<<n<<std::endl;
    
    for (Long64_t jentry=0; jentry<n; jentry++) 
    {
      tree->GetEntry(jentry);
      //std::cout<<MagField->size()<<std::endl;

      for (int k = 0; k < MagField->size() ; k++)			// Loop to calculate Kinematical distributions
      {
	//std::cout<<MagField->at(k)<<std::endl;
	auto search = magTracks.find(MagField->at(k));
        if (search!= magTracks.end())   //Key found
        {
	  magTracks[MagField->at(k)]=magTracks[MagField->at(k)]+ntrk;  
        }
        else                         //Key not found
        {
	  magTracks[MagField->at(k)]=ntrk;
        }
      }	
           
    }
 
    cout << "The Tracks map is : \n"; 
    cout << "\t KEY \t ELEMENT\n"; 
    for (auto itr2 = magTracks.begin(); itr2!= magTracks.end(); ++itr2)
    { 
        cout << '\t' << itr2->first 
             << '\t' << itr2->second << '\n'; 
    } 
    cout << endl;
    
  
} 
