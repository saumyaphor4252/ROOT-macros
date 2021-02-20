using namespace ROOT::VecOps;

void CheckResiduals()
{
    
  TCanvas c("c","c",800,600);
  TFile *file1 = new TFile("CTF_Residuals.root");
   
   TTree *tree1;
   tree1 = (TTree*)file1->Get("demo/Event");

   vector<double>  *pt_CTF;
   vector<int>  *nHitsValid_CTF;
   pt_CTF=0;
   //nHitsValid_CTF=0;

   tree1->SetBranchAddress("pt", &pt_CTF);
   tree1->SetBranchAddress("nHitsValid", &nHitsValid_CTF);

   TH1D h_pt_CTF 		("h_pt_CTF","h_pt",200,0,200);
   TH1D h_nHitsValid_CTF("h_nHitsValid", "Valid Hits;Hits (#); Tracks", 50, 0, 50);

   Long64_t n1 = tree1->GetEntriesFast();
   std::cout<<"Total Events: "<<n1<<std::endl;
   for (int jentry=0; jentry<10000; jentry++) //Event Loop
     {

       tree1->GetEntry(jentry);
       for (int i = 0; i < pt_CTF->size() ; i++)  	//Track Loop CosmicTF
	 {
	   h_pt_CTF.Fill(pt_CTF->at(i));
	   h_nHitsValid_CTF.Fill(nHitsValid_CTF->at(i));
	 }
     }

   //h_pt_CTF.Draw();
   h_nHitsValid_CTF.Draw();
   c.SaveAs("ValidHits.png");


}

   
