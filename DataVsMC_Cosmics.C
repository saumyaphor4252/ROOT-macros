{
  /*
The following macro compares the normaized histograms in 2 different root files having similar heirarchy structures.

Running the script in ROOT:
1) .x DataVsMC_Cosmics.C

This will create a folder "Comparison_Plots" with png formats of the comparison Histograms.
By default the x-axis labels are from the histograms in the root files itself and the y-axis labels are normalized.

*/
   gStyle->SetOptStat(0);   
   TString Allfiles[2] = {"Cosmics.root","millepedemonitor_Cosmics3.8T_Prompt.root"};
   Int_t colors[8]  = {kBlack,kBlue,kRed,kGreen+2,kOrange,kMagenta,kCyan,kViolet};
   
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
   
   //==========Setting Up Canvas==========//
   TCanvas *c = new TCanvas("c", "c",754,169,800,756);
   gStyle->SetOptStat(0); // Dont show stats
   gStyle->SetOptTitle(0); // Dont show Title
   c->SetFillColor(0);  
   c->SetBorderSize(2);
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetLeftMargin(0.17);
   c->SetRightMargin(0.04761905);
   c->SetTopMargin(0.07152683);
   c->SetBottomMargin(0.1224209);
   c->SetFrameLineWidth(3);
   c->SetFrameFillStyle(0);
   c->SetFrameLineWidth(2);
   c->SetFrameLineWidth(3);
   
   gSystem->Exec("mkdir Comparison_Plots"); 
   TLegend *legend;
   
   while ((key_data=(TKey*)next_data.Next())) 
   {
       key_mc=(TKey*)next_mc.Next();
     
       TString s_data = key_data->GetName();
       TString s_mc = key_mc->GetName();
 
       h_data = (TH1F*)folder1->Get(s_data.Data());
       h_mc = (TH1F*)folder2->Get(s_mc.Data());

       // =========== Histogram Details =========== //
       h_data->GetXaxis()->SetLabelFont(42);
       h_data->GetXaxis()->SetLabelSize(0.05);
       h_data->GetXaxis()->SetTitleSize(0.05);
       h_data->GetXaxis()->SetTickLength(0.05);
       h_data->GetXaxis()->SetTitleFont(42);
       h_data->GetYaxis()->SetTitle("a.u.");
       h_data->GetYaxis()->SetLabelFont(42);
       h_data->GetYaxis()->SetLabelSize(0.05);
       h_data->GetYaxis()->SetTitleSize(0.06);
       h_data->GetYaxis()->SetTickLength(0.05);
       h_data->GetYaxis()->SetTitleFont(42);

       h_data->SetLineColor(colors[1]);
       h_data->SetLineWidth(3);
    
       h_mc->SetLineColor(colors[2]);
       h_mc->SetLineWidth(3);
          
       //----------------------Setting Axes Titles----------------------------//
               //--Histogram Title--//
       s_data.ReplaceAll("used",""); s_data.ReplaceAll("Track","");
       h_data->SetTitle(s_data.Data());
       h_mc->SetTitle(s_data.Data());
       
               //------Y Axis-------//
       h_data->GetYaxis()->SetTitle("a.u.");
       h_mc->GetYaxis()->SetTitle("a.u.");

       TGaxis::SetMaxDigits(3); //Setting the digit limits of axis labels

       //--------------------------Plotting-----------------------------------//
       h_data->DrawNormalized("EHIST");
       h_mc->DrawNormalized("EHISTSame");
     
       //------------------------------legend---------------------------------//
       TLegend *leg = new TLegend(0.74,0.70,0.90,0.88);
       leg->SetHeader("Campaign","C");
       leg->SetBorderSize(1);
       leg->SetTextFont(62);
       leg->SetTextSize(0.04);
       leg->SetLineColor(0);
       leg->SetLineStyle(1);
       leg->SetLineWidth(1);
       leg->SetFillColor(0);
       leg->SetFillStyle(0);
       TLegendEntry *entry=leg->AddEntry(h_data,"Data");
       entry->SetFillStyle(1001);
       entry->SetLineColor(colors[1]);
       entry->SetLineStyle(1);
       entry->SetLineWidth(3);
       entry->SetMarkerColor(colors[1]);
       entry->SetMarkerStyle(1);
       entry->SetMarkerSize(1);
       entry->SetTextFont(42);
       leg->Draw();
       entry=leg->AddEntry(h_mc,"MC");
       entry->SetFillStyle(1001);
       entry->SetLineColor(colors[2]);
       entry->SetLineStyle(1);
       entry->SetLineWidth(3);
       entry->SetMarkerColor(colors[2]);
       entry->SetMarkerStyle(1);
       entry->SetMarkerSize(1);
       entry->SetTextFont(42);
       leg->Draw();
  
       //----------------------------Saving Plots-----------------------------//
       TString filename = s_data + ".png";
       c->SaveAs(filename.Data());
       c->Clear();
       TString cmd = "mv " + filename + " Comparison_Plots";
       gSystem->Exec(cmd.Data());
    }
   c->Close();
}



   

