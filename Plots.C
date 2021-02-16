void Plots()
{
        
  //  TString InputFile= Form("%s",fileName); 
  

  /*  bool IsFileExist;
   IsFileExist = file->IsZombie();
   if(IsFileExist)
   {   
      cout<<endl<<"====================================================================================================="<<endl;
      cout<<" File not found. Check the file!"<<endl;
      cout<<"====================================================================================================="<<endl<<endl;
      exit (EXIT_FAILURE);
      }*/

  /* TFile *file = new TFile("MC_Zmumu_2018.root");
   TDirectory *folder = (TDirectory*)file->Get("demo");
   TTree *tree = (TTree*)folder->Get("Event");
   TIter next(tree->GetListOfBranches());
   TKey *key;
   
   //TFile f("demo.root");
   //  TIter next(tree->GetListOfKeys());
   //TObjArray *brnchs = GetListOfBranches();
   //  tree->GetListOfBranches();
  
   //TKey *key;
   int temp=0;
   while ((key=(TKey*)next()))
     {
      temp++;
      printf("Branch %i \n",temp);
       }
  */

  
  TCanvas *c = new TCanvas("c", "c",800,800);

  gStyle->SetOptStat("0");
  
  gSystem->Exec("mkdir Plots");
  
  TFile *file = TFile::Open("MC_Zmumu_2018.root");
  TDirectory *folder = (TDirectory*)file->Get("demo");
  TTree *tree = (TTree*)folder->Get("Event");
  TIter next(tree->GetListOfBranches());
  TKey *key;
  
  FILE *fp = fopen("HistParameters.csv","r");
  int Bins; float xMin,xMax; char variable[80];
    
  while ((key=(TKey*)next())) {
    printf("key: %s \n", key->GetName());
    TString BranchName=key->GetName();
    printf("Branch Name: %s \n",BranchName.Data());
    fscanf(fp," %i, %f ,%f \n",&Bins,&xMin,&xMax);
    std::cout<<Bins<<" | "<<xMin<<" | "<<xMax<<std::endl;
    /*   if( !(BranchName.Data()==variable) )
      { std::cout<<" Branch Name doesn't match with the Parameter variable in the Parameter CSV File!"<<std::endl;
	exit(0);
	}*/
    // tree->Draw(BranchName.Data());
    TString PlotBranchHist = BranchName +Form(">>(%i,%f,%f)",Bins,xMin,xMax); 
    tree->Draw(PlotBranchHist.Data());
    
    TString filename = BranchName + ".png";
    c->SaveAs(filename.Data());
    TString cmd = "mv  " + filename + "  Plots";
    gSystem->Exec(cmd.Data());
    
    c->Clear();  
  }
  fclose(fp);
  
}
