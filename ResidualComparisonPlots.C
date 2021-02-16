void ResidualComparisonPlots()
{
        
  TCanvas *c = new TCanvas("c", "c",800,800);

  gStyle->SetOptStat("0");
  
  gSystem->Exec("mkdir Plots");
  
  TFile *file = TFile::Open("CTF_Residuals.root");
  TDirectory *folder = (TDirectory*)file->Get("demo");
  TTree *tree = (TTree*)folder->Get("Event");
  TIter next(tree->GetListOfBranches());
  TKey *key;
  
  FILE *fp = fopen("CRTparameters.csv","r");
  int Bins; float xMin,xMax; char variable[80]; TString variable;
    
  while ((key=(TKey*)next())) {
    printf("key: %s \n", key->GetName());
    TString BranchName=key->GetName();
    printf("Branch Name: %s \n",BranchName.Data());
    fscanf(fp," *%s, %i, %f ,%f \n",variable.Data(), &Bins,&xMin,&xMax);
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
