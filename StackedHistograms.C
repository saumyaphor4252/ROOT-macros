{
   TFile f_data("mergeMC.root");
   TDirectory *folder = (TDirectory*)f_data.Get("usedTrackHists;1");
   TH1F *h_BPIX,*h_FPIX,*h_PIXEL,*h_TIB,*h_TOB,*h_TID,*h_TEC,*h_ENDCAP;  
   
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
  
   THStack *hs = new THStack("hs","CDC");
   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   
   h_BPIX = (TH1F*)folder->Get("usednHitBPIXTrack");
   h_FPIX = (TH1F*)folder->Get("usednHitFPIXTrack");
   h_PIXEL = (TH1F*)folder->Get("usednHitPIXELTrack");  
   h_TIB = (TH1F*)folder->Get("usednHitTIBTrack");
   h_TOB = (TH1F*)folder->Get("usednHitTOBTrack");
   h_TID = (TH1F*)folder->Get("usednHitTIDTrack");
   h_TEC = (TH1F*)folder->Get("usednHitTECTrack");
   h_ENDCAP = (TH1F*)folder->Get("usednHitENDCAPTrack");

   h_BPIX->Scale(1.0/h_BPIX->Integral(), "width");
   h_FPIX->Scale(1.0/h_FPIX->Integral(), "width");
   h_PIXEL->Scale(1.0/h_PIXEL->Integral(), "width");
   h_TIB->Scale(1.0/h_TIB->Integral(), "width");
   h_TOB->Scale(1.0/h_TOB->Integral(), "width");
   h_TID->Scale(1.0/h_TID->Integral(), "width");
   h_TEC->Scale(1.0/h_TEC->Integral(), "width");
   h_ENDCAP->Scale(1.0/h_ENDCAP->Integral(), "width");

   h_BPIX->SetLineColor(TColor::GetColor("#000099"));
   h_BPIX->SetFillColor(TColor::GetColor("#e60909"));
   h_BPIX->GetXaxis()->SetTitle("N_{Hits}");
   h_BPIX->GetXaxis()->SetLabelFont(42);
   h_BPIX->GetXaxis()->SetLabelSize(0.035);
   h_BPIX->GetXaxis()->SetTitleSize(0.035);
   h_BPIX->GetXaxis()->SetTitleFont(42);
   h_BPIX->GetYaxis()->SetTitle("Probabilty Density");
   h_BPIX->GetYaxis()->SetLabelFont(42);
   h_BPIX->GetYaxis()->SetLabelSize(0.035);
   h_BPIX->GetYaxis()->SetTitleSize(0.035);
   h_BPIX->GetYaxis()->SetTitleOffset(0);
   h_BPIX->GetYaxis()->SetTitleFont(42);

   h_FPIX->SetLineColor(TColor::GetColor("#000099"));
   h_FPIX->SetFillColor(kOrange+1);
   h_FPIX->GetXaxis()->SetTitle("N_{Hits}");
   h_FPIX->GetXaxis()->SetLabelFont(42);
   h_FPIX->GetXaxis()->SetLabelSize(0.035);
   h_FPIX->GetXaxis()->SetTitleSize(0.035);
   h_FPIX->GetXaxis()->SetTitleFont(42);
   h_FPIX->GetYaxis()->SetTitle("Probabilty Density");
   h_FPIX->GetYaxis()->SetLabelFont(42);
   h_FPIX->GetYaxis()->SetLabelSize(0.035);
   h_FPIX->GetYaxis()->SetTitleSize(0.035);
   h_FPIX->GetYaxis()->SetTitleOffset(0);
   h_FPIX->GetYaxis()->SetTitleFont(42);

   h_PIXEL->SetLineColor(TColor::GetColor("#000099"));
   h_PIXEL->SetFillColor(kYellow);
   h_PIXEL->GetXaxis()->SetTitle("N_{Hits}");
   h_PIXEL->GetXaxis()->SetLabelFont(42);
   h_PIXEL->GetXaxis()->SetLabelSize(0.035);
   h_PIXEL->GetXaxis()->SetTitleSize(0.035);
   h_PIXEL->GetXaxis()->SetTitleFont(42);
   h_PIXEL->GetYaxis()->SetTitle("Probabilty Density");
   h_PIXEL->GetYaxis()->SetLabelFont(42);
   h_PIXEL->GetYaxis()->SetLabelSize(0.035);
   h_PIXEL->GetYaxis()->SetTitleSize(0.035);
   h_PIXEL->GetYaxis()->SetTitleOffset(0);
   h_PIXEL->GetYaxis()->SetTitleFont(42);

   h_TIB->SetLineColor(TColor::GetColor("#000099"));
   h_TIB->SetFillColor(TColor::GetColor("#4be609"));
   h_TIB->GetXaxis()->SetTitle("N_{Hits}");
   h_TIB->GetXaxis()->SetLabelFont(42);
   h_TIB->GetXaxis()->SetLabelSize(0.035);
   h_TIB->GetXaxis()->SetTitleSize(0.035);
   h_TIB->GetXaxis()->SetTitleFont(42);
   h_TIB->GetYaxis()->SetTitle("Probabilty Density");
   h_TIB->GetYaxis()->SetLabelFont(42);
   h_TIB->GetYaxis()->SetLabelSize(0.035);
   h_TIB->GetYaxis()->SetTitleSize(0.035);
   h_TIB->GetYaxis()->SetTitleOffset(0);
   h_TIB->GetYaxis()->SetTitleFont(42);

   h_TOB->SetLineColor(TColor::GetColor("#000099"));
   h_TOB->SetFillColor(TColor::GetColor("#14802f"));
   h_TOB->GetXaxis()->SetTitle("N_{Hits}");
   h_TOB->GetXaxis()->SetLabelFont(42);
   h_TOB->GetXaxis()->SetLabelSize(0.035);
   h_TOB->GetXaxis()->SetTitleSize(0.035);
   h_TOB->GetXaxis()->SetTitleFont(42);
   h_TOB->GetYaxis()->SetTitle("Probabilty Density");
   h_TOB->GetYaxis()->SetLabelFont(42);
   h_TOB->GetYaxis()->SetLabelSize(0.035);
   h_TOB->GetYaxis()->SetTitleSize(0.035);
   h_TOB->GetYaxis()->SetTitleOffset(0);
   h_TOB->GetYaxis()->SetTitleFont(42);

   h_TID->SetLineColor(TColor::GetColor("#000099"));
   h_TID->SetFillColor(TColor::GetColor("#6df2ee"));
   h_TID->GetXaxis()->SetTitle("N_{Hits}");
   h_TID->GetXaxis()->SetLabelFont(42);
   h_TID->GetXaxis()->SetLabelSize(0.035);
   h_TID->GetXaxis()->SetTitleSize(0.035);
   h_TID->GetXaxis()->SetTitleFont(42);
   h_TID->GetYaxis()->SetTitle("Probabilty Density");
   h_TID->GetYaxis()->SetLabelFont(42);
   h_TID->GetYaxis()->SetLabelSize(0.035);
   h_TID->GetYaxis()->SetTitleSize(0.035);
   h_TID->GetYaxis()->SetTitleOffset(0);
   h_TID->GetYaxis()->SetTitleFont(42);

   h_TEC->SetLineColor(TColor::GetColor("#000099"));
   h_TEC->SetFillColor(TColor::GetColor("#1118d6"));
   h_TEC->GetXaxis()->SetTitle("N_{Hits}");
   h_TEC->GetXaxis()->SetLabelFont(42);
   h_TEC->GetXaxis()->SetLabelSize(0.035);
   h_TEC->GetXaxis()->SetTitleSize(0.035);
   h_TEC->GetXaxis()->SetTitleFont(42);
   h_TEC->GetYaxis()->SetTitle("Probabilty Density");
   h_TEC->GetYaxis()->SetLabelFont(42);
   h_TEC->GetYaxis()->SetLabelSize(0.035);
   h_TEC->GetYaxis()->SetTitleSize(0.035);
   h_TEC->GetYaxis()->SetTitleOffset(0);
   h_TEC->GetYaxis()->SetTitleFont(42);

   h_ENDCAP->SetLineColor(TColor::GetColor("#000099"));
   h_ENDCAP->SetFillColor(TColor::GetColor("#d611b9"));
   h_ENDCAP->GetXaxis()->SetTitle("N_{Hits}");
   h_ENDCAP->GetXaxis()->SetLabelFont(42);
   h_ENDCAP->GetXaxis()->SetLabelSize(0.035);
   h_ENDCAP->GetXaxis()->SetTitleSize(0.035);
   h_ENDCAP->GetXaxis()->SetTitleFont(42);
   h_ENDCAP->GetYaxis()->SetTitle("Probabilty Density");
   h_ENDCAP->GetYaxis()->SetLabelFont(42);
   h_ENDCAP->GetYaxis()->SetLabelSize(0.035);
   h_ENDCAP->GetYaxis()->SetTitleSize(0.035);
   h_ENDCAP->GetYaxis()->SetTitleOffset(0);
   h_ENDCAP->GetYaxis()->SetTitleFont(42);
   
   hs->Add(h_BPIX);
   hs->Add(h_FPIX);
   hs->Add(h_PIXEL);
   hs->Add(h_TIB);
   hs->Add(h_TOB);
   hs->Add(h_TID);
   hs->Add(h_TEC);
   hs->Add(h_ENDCAP);

   TPaveText *pt = new TPaveText(0.4540123,0.94,0.5459877,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->Draw();
  
   TLegend *leg = new TLegend(0.7894334,0.5173238,0.924196,0.8709677,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   
   TLegendEntry *entry=leg->AddEntry("h_BPIX","BPIX","lpf");
   ci = TColor::GetColor("#e60909");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   
   entry=leg->AddEntry("h_FPIX","FPIX","lpf");
   entry->SetFillColor(TColor::GetColor("#ff9933"));
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   
   entry=leg->AddEntry("h_PIXEL","PIXEL","lpf");
   entry->SetFillColor(TColor::GetColor("#ffff00"));
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);

   entry=leg->AddEntry("h_TIB","TIB","lpf");
   ci = TColor::GetColor("#4be609");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   
   entry=leg->AddEntry("h_TOB","TOB","lpf");
   entry->SetFillColor(TColor::GetColor("14802f"));
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);

   entry=leg->AddEntry("h_TID","TID","lpf");
   entry->SetFillColor(TColor::GetColor("#6df2ee"));
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);

   entry=leg->AddEntry("h_TEC","TEC","lpf");
   entry->SetFillColor(TColor::GetColor("#1118d6"));
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);

   entry=leg->AddEntry(h_ENDCAP,"ENDCAP","lpf");
   entry->SetFillColor(TColor::GetColor("#d611b9"));
   entry->SetFillStyle(1001);
   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();

   hs->Draw("HIST");
   
   TLatex *   tex = new TLatex(2.990896,4.962392,"Iso Mu Hits in different Subdetectors");
   tex->SetLineWidth(2);
   tex->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
   c->ToggleToolBar();
}
