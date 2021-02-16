void TracksMultiplicity()
{
//=========Macro generated from canvas: c/c
//=========  (Fri Dec  4 00:19:20 2020) by ROOT version6.10/04
  TCanvas *c = new TCanvas("c", "c",800,600);
   gStyle->SetOptStat(0);
   // c->Range(-1.112738,-1299363,10.57101,1.324841e+07);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(3);
   c->SetGridx();
   c->SetGridy();
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetRightMargin(0.04887218);
   c->SetTopMargin(0.08581436);
   c->SetBottomMargin(0.08931699);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH1D *h1_copy__1__4 = new TH1D("h1_copy__1__4","Tracks per Event",10,0,10);
   h1_copy__1__4->SetBinContent(1,4973999);
   h1_copy__1__4->SetBinContent(2,7564635);
   h1_copy__1__4->SetBinContent(3,77947);
   h1_copy__1__4->SetBinContent(4,685);
   h1_copy__1__4->SetBinContent(5,61);
   h1_copy__1__4->SetBinContent(6,6);
   h1_copy__1__4->SetBinContent(7,1);
   h1_copy__1__4->SetMinimum(0);
   h1_copy__1__4->SetMaximum(1.2e+07);
   h1_copy__1__4->SetEntries(1.261733e+07);
   h1_copy__1__4->SetDirectory(0);
   h1_copy__1__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3113ba");
   h1_copy__1__4->SetLineColor(ci);
   h1_copy__1__4->SetLineWidth(3);
   h1_copy__1__4->GetXaxis()->SetTitle("Tracks [#]");
   h1_copy__1__4->GetXaxis()->SetLabelFont(42);
   h1_copy__1__4->GetXaxis()->SetLabelSize(0.035);
   h1_copy__1__4->GetXaxis()->SetTitleSize(0.035);
   h1_copy__1__4->GetXaxis()->SetTitleFont(42);
   h1_copy__1__4->GetYaxis()->SetTitle("Entries [#]");
   h1_copy__1__4->GetYaxis()->SetLabelFont(42);
   h1_copy__1__4->GetYaxis()->SetLabelSize(0.035);
   h1_copy__1__4->GetYaxis()->SetTitleSize(0.035);
   h1_copy__1__4->GetYaxis()->SetTitleOffset(0);
   h1_copy__1__4->GetYaxis()->SetTitleFont(42);
   h1_copy__1__4->GetZaxis()->SetLabelFont(42);
   h1_copy__1__4->GetZaxis()->SetLabelSize(0.035);
   h1_copy__1__4->GetZaxis()->SetTitleSize(0.035);
   h1_copy__1__4->GetZaxis()->SetTitleFont(42);
   h1_copy__1__4->Draw("");
   
   TH1D *h2_copy__2__5 = new TH1D("h2_copy__2__5","Tracks per Event",10,0,10);
   h2_copy__2__5->SetBinContent(1,1092011);
   h2_copy__2__5->SetBinContent(2,1.152532e+07);
   h2_copy__2__5->SetEntries(1.261733e+07);
   h2_copy__2__5->SetDirectory(0);
   h2_copy__2__5->SetStats(0);

   ci = TColor::GetColor("#de0b1d");
   h2_copy__2__5->SetLineColor(ci);
   h2_copy__2__5->SetLineWidth(3);
   h2_copy__2__5->GetXaxis()->SetTitle("Tracks [#]");
   h2_copy__2__5->GetXaxis()->SetLabelFont(42);
   h2_copy__2__5->GetXaxis()->SetLabelSize(0.035);
   h2_copy__2__5->GetXaxis()->SetTitleSize(0.035);
   h2_copy__2__5->GetXaxis()->SetTitleFont(42);
   h2_copy__2__5->GetYaxis()->SetLabelFont(42);
   h2_copy__2__5->GetYaxis()->SetLabelSize(0.035);
   h2_copy__2__5->GetYaxis()->SetTitleSize(0.035);
   h2_copy__2__5->GetYaxis()->SetTitleOffset(0);
   h2_copy__2__5->GetYaxis()->SetTitleFont(42);
   h2_copy__2__5->GetZaxis()->SetLabelFont(42);
   h2_copy__2__5->GetZaxis()->SetLabelSize(0.035);
   h2_copy__2__5->GetZaxis()->SetTitleSize(0.035);
   h2_copy__2__5->GetZaxis()->SetTitleFont(42);
   h2_copy__2__5->Draw("same");
   
   TH1D *h3_copy__3__6 = new TH1D("h3_copy__3__6","Tracks per Event",10,0,10);
   h3_copy__3__6->SetBinContent(1,6017356);
   h3_copy__3__6->SetBinContent(2,6502709);
   h3_copy__3__6->SetBinContent(3,97184);
   h3_copy__3__6->SetBinContent(4,77);
   h3_copy__3__6->SetBinContent(5,4);
   h3_copy__3__6->SetBinContent(6,3);
   h3_copy__3__6->SetBinContent(10,1);
   h3_copy__3__6->SetEntries(1.261733e+07);
   h3_copy__3__6->SetDirectory(0);
   h3_copy__3__6->SetStats(0);

   ci = TColor::GetColor("#33cc33");
   h3_copy__3__6->SetLineColor(ci);
   h3_copy__3__6->SetLineWidth(3);
   h3_copy__3__6->GetXaxis()->SetTitle("Tracks [#]");
   h3_copy__3__6->GetXaxis()->SetLabelFont(42);
   h3_copy__3__6->GetXaxis()->SetLabelSize(0.035);
   h3_copy__3__6->GetXaxis()->SetTitleSize(0.035);
   h3_copy__3__6->GetXaxis()->SetTitleFont(42);
   h3_copy__3__6->GetYaxis()->SetLabelFont(42);
   h3_copy__3__6->GetYaxis()->SetLabelSize(0.035);
   h3_copy__3__6->GetYaxis()->SetTitleSize(0.035);
   h3_copy__3__6->GetYaxis()->SetTitleOffset(0);
   h3_copy__3__6->GetYaxis()->SetTitleFont(42);
   h3_copy__3__6->GetZaxis()->SetLabelFont(42);
   h3_copy__3__6->GetZaxis()->SetLabelSize(0.035);
   h3_copy__3__6->GetZaxis()->SetTitleSize(0.035);
   h3_copy__3__6->GetZaxis()->SetTitleFont(42);
   h3_copy__3__6->Draw("same");
   
   TPaveText *pt = new TPaveText(0.343985,0.9299475,0.656015,0.9912434,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   TText *pt_LaTex = pt->AddText("Tracks per Event");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.6265664,0.6532399,0.9273183,0.8633975,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.05604203);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("h1_copy__1","CTF","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#3113ba");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h2_copy__2","CosmicTF","lpflpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#de0b1d");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h3_copy__3","Regional","lpflpflpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#33cc33");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
