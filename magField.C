#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
void magField() 
{ 

    TFile *file = new TFile("Cosmic_MagFieldDouble.root");
    //Map container 
    map<double, int> magMap;// map<double, int> magTracks;
    
    TTree *tree;
    tree = (TTree*)file->Get("cosmicRateAnalyzer/Event");
     double magField;
    // int ntrk;
    tree->SetBranchAddress("MagField", &magField);
    //  tree->SetBranchAddress("ntrk", &ntrk);
    //MagField=0;
  
    Long64_t n = tree->GetEntriesFast();
    std::cout<<"Events: "<<n<<std::endl;
    
    for (Long64_t jentry=0; jentry<n; jentry++) 
    {
      tree->GetEntry(jentry);
      //std::cout<<MagField->size()<<std::endl;
      if(jentry<20) std::cout<<magField<<std::endl;

      //for (int k = 0; k < MagField->size() ; k++)			// Loop to calculate Kinematical distributions
      // {
	//std::cout<<MagField->at(k)<<std::endl;
	auto search = magMap.find(magField);
        if (search!= magMap.end())   //Key found
        {
	  magMap[magField]=magMap[magField]+1;
	  // magTracks[MagField->at(k)]=magTracks[MagField->at(k)]+ntrk;
	  
        }
        else                         //Key not found
        {
	  magMap[magField]=1;
	  // magTracks[MagField->at(k)]=ntrk;
        }
	// }	
           
    }
 
     // printing map 
    cout << "The map is : \n"; 
    cout << "\t KEY \t ELEMENT\n"; 
    for (auto itr = magMap.begin(); itr!= magMap.end(); ++itr)
    { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl;

    /*   cout << "The Tracks map is : \n"; 
    cout << "\t KEY \t ELEMENT\n"; 
    for (auto itr2 = magTracks.begin(); itr2!= magTracks.end(); ++itr2)
    { 
        cout << '\t' << itr2->first 
             << '\t' << itr2->second << '\n'; 
    } 
    cout << endl;
    */
  
} 
