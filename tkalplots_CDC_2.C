{
   gStyle->SetOptStat(0);   

   TFile f_data("millepedemonitor_CDC.root");
   TDirectory *folder = (TDirectory*)f_data.Get("usedTrackHists;1");
   TIter next_data(folder->GetListOfKeys());
   TH1F *h_data;   
   TKey *key_data;

   TCanvas *c = new TCanvas("c", "c",226,57,1308,893);
   gStyle->SetOptStat(0);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetRightMargin(0.04211332);
   c->SetTopMargin(0.08932715);
   c->SetBottomMargin(0.0800464);
   c->SetFrameBorderMode(0);
   
   gSystem->Exec("mkdir CDC_Plots_D"); 
   TLegend *legend;
   
   while ((key_data=(TKey*)next_data.Next())) 
   {          
       TString s_data = key_data->GetName();       
       h_data = (TH1F*)folder->Get(s_data.Data());
     
       // h_data->SetLineColor(1);
       h_data->SetMarkerStyle(21);
       h_data->SetMarkerSize(1);
           
       //----------------------Setting Axes Titles----------------------------//
               //--Histogram Title--//
       s_data.ReplaceAll("used",""); s_data.ReplaceAll("Track","");
       h_data->SetTitle(s_data.Data());
         
              //------Y Axis-------//
       h_data->GetYaxis()->SetTitle("Probabilty Density");

       //--------------------------Plotting-----------------------------------//
      
       h_data->DrawNormalized("E1");
   
       //------------------------------legend---------------------------------//
       legend = new TLegend(0.78,0.84,0.94,0.94);
       legend->AddEntry(h_data,"Data");
       legend->Draw();

       //----------------------------Saving Plots-----------------------------//
       TString filename = s_data + ".png";
       c->SaveAs(filename.Data());
       c->Clear();
       TString cmd = "mv  " + filename + "  CDC_Plots_D";
       gSystem->Exec(cmd.Data());
    }
}



   

