{
   gStyle->SetOptStat(0);   
   TString Allfiles[2] = {"Cosmics.root","millepedemonitor_Cosmics38T.root"};
   //First data second MC
   TFile f_data(Allfiles[0].Data());
   TFile f_mc(Allfiles[1].Data());
   
   TDirectory *folder1 = (TDirectory*)f_data.Get("usedTrackHists;1");
   TDirectory *folder2 = (TDirectory*)f_mc.Get("usedTrackHists;1");
   
   TIter next_data(folder1->GetListOfKeys());
   TIter next_mc(folder2->GetListOfKeys());
   
   TH1F *h_data;
   TH1F *h_mc;
     
   TKey *key_data;
   TKey *key_mc;
   
   TCanvas *c = new TCanvas("c", "c",226,57,1308,893);
   gStyle->SetOptStat(0);
   //c->Range(-1.748483,-0.4743621,15.73634,5.451727);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetRightMargin(0.04211332);
   c->SetTopMargin(0.08932715);
   c->SetBottomMargin(0.0800464);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);

   gSystem->Exec("mkdir Cosmic_Plots_MD"); 
   TLegend *legend;
   
   while ((key_data=(TKey*)next_data.Next())) 
   {
       key_mc=(TKey*)next_mc.Next();
     
       TString s_data = key_data->GetName();
       TString s_mc = key_mc->GetName();
 
       h_data = (TH1F*)folder1->Get(s_data.Data());
       h_mc = (TH1F*)folder2->Get(s_mc.Data());
   
       h_data->SetMarkerStyle(21);
       h_mc->SetLineColor(2);
       h_data->SetMarkerSize(1);
       h_mc->SetLineWidth(2);
           
       //----------------------Setting Axes Titles----------------------------//
               //--Histogram Title--//
       s_data.ReplaceAll("used",""); s_data.ReplaceAll("Track","");
       h_data->SetTitle(s_data.Data());
       h_mc->SetTitle(s_data.Data());
       
               //------Y Axis-------//
       h_data->GetYaxis()->SetTitle("Probabilty Density");
       h_mc->GetYaxis()->SetTitle("Probabilty Density");

       //--------------------------Plotting-----------------------------------//
    
       h_mc->DrawNormalized();
          h_data->DrawNormalized("E1same");

       //------------------------------legend---------------------------------//
       legend = new TLegend(0.78,0.84,0.94,0.94);
       legend->AddEntry(h_data,"Data");
       legend->AddEntry(h_mc,"MC");
       legend->Draw();
   
       //----------------------------Saving Plots-----------------------------//
       TString filename = s_data + ".png";
       c->SaveAs(filename.Data());
       c->Clear();
       TString cmd = "mv  " + filename + "  Cosmic_Plots_MD";
       gSystem->Exec(cmd.Data());
    }
}



   

