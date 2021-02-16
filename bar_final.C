
{

    Int_t ci;      // for color index setting
  TColor *color; // for color definition with alpha

 TCanvas *Canvas0 = new TCanvas("Canvas0", "Canvas0",505,158,808,635);
   gStyle->SetOptStat(0);
   Canvas0->Range(299775.5,-3.45001,300763.4,30.71075);
   Canvas0->SetFillColor(0);
   Canvas0->SetBorderMode(0);
   Canvas0->SetBorderSize(2);
   Canvas0->SetGridx();
   Canvas0->SetGridy();
   Canvas0->SetTickx(1);
   Canvas0->SetTicky(1);
   Canvas0->SetLeftMargin(0.1153846);
   Canvas0->SetRightMargin(0.0483871);
   Canvas0->SetTopMargin(0.08774834);
   Canvas0->SetFrameLineWidth(2);
   Canvas0->SetFrameBorderMode(0);
   Canvas0->SetFrameLineWidth(2);
   Canvas0->SetFrameBorderMode(0);

   
   	TH1F h1b("h1b","rate summary",8,0,8);
	ci=TColor::GetColor("#3113ba");
   	h1b.SetFillColor(ci);
   	h1b.SetMarkerColor(ci);
   	h1b.SetMarkerSize(1.5);
   	h1b.SetBarWidth(0.25);
   	h1b.SetBarOffset(0.15);
   	h1b.SetStats(0);

   	TH1F h2b("h2b","rate summary",8,0,8);
	 ci=TColor::GetColor("#de0b1d");
   	h2b.SetFillColor(ci);
   	h2b.SetMarkerColor(ci);
   	h2b.SetMarkerSize(1.5);
   	h2b.SetBarWidth(0.25);
   	h2b.SetBarOffset(0.4);
   	h2b.SetStats(0);


    TH1F h3b("h3b","rate summary",8,0,8);
     ci=TColor::GetColor("#33cc33");
   	h3b.SetFillColor(ci);
   	h3b.SetMarkerColor(ci);
   	h3b.SetMarkerSize(1.5);
   	h3b.SetBarWidth(0.25);
   	h3b.SetBarOffset(0.65);
   	h3b.SetStats(0);


	string Bar_Xtitle[8] = {"Event","Track","FPIX","BPIX","TIB","TID","TOB","TEC"};

   	double Rate_CTF[8] = {3.774928, 2.314349, 0.044304, 0.096355, 1.022419, 0.411294, 2.174468, 0.547039};
   	double Rate_CosmicTF[8] = {3.800028, 3.483958, 0.073156, 0.130044, 1.578258, 0.788245, 3.224758, 1.155440};
   	double Rate_Regional[8] = {3.812371, 2.109545, 0.042559, 0.105501, 1.031319, 0.313258, 2.107201, 0.333975};

   	//double error_2016[8] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

	//	TString test[8] = {"3.316", "2.020", "0.032", "0.072", "0.856", "0.392", "1.885", "0.509"}; 


    for (int i=1; i<=8; i++)
    {
      	h1b.SetBinContent(i, Rate_CTF[i-1]);
      //	TText th1(i,h1b.GetBinContent(i),test[i].Data());
   		//th1.SetTextAlign(11); th1.SetTextSize(0.12);
   		//th1.Draw();
      	//h1b.SetBinError(i, 0.1);
      	h1b.GetXaxis()->SetBinLabel(i,Bar_Xtitle[i-1].c_str());
      	h2b.SetBinContent(i, Rate_CosmicTF[i-1]);
      	//h2b.SetBinError(i, 0.1);
      	h3b.SetBinContent(i, Rate_Regional[i-1]);
      	//h3b.SetBinError(i, 0.1);
  	}

  	//gPad->DrawFrame(-1,0,9,4.5);
  	//TH1 *h1 = h1b.DrawCopy("bar TEXT HIST");
  	//TH1 *h2 = h2b.DrawCopy("bar TEXT  HIST same ");
  	//TH1 *h3 = h3b.DrawCopy("bar TEXT  HIST same ");

  	TH1 *h1 = (TH1*)h1b.Clone();
  	TH1 *h2 = (TH1*)h2b.Clone();
  	TH1 *h3 = (TH1*)h3b.Clone();

  	//h1->SetError(error_2016);
  	h1 -> Draw("bar  TEXT");
  	h2 -> Draw("bar  TEXT same ");
  	h3 -> Draw("bar  TEXT same ");

  	h1->SetBarOffset(0.27);
  	h2->SetBarOffset(0.445);
  	h3->SetBarOffset(0.62);


  	h1->SetBarWidth(0.175);
  	h2->SetBarWidth(0.175);
  	h3->SetBarWidth(0.175);

	gStyle->SetPaintTextFormat("1.3f");
	h1->LabelsOption("d");
	h1->GetYaxis()->SetTitle("Average Rate (Hz)");
	h1->GetYaxis()->SetRangeUser(0,4.5);

	cout<<"range: "<<h1->GetXaxis()->GetXmin()<<endl;
	cout<<"range: "<<h1->GetXaxis()->GetXmax()<<endl;

   TLegend *legend = new TLegend(0.65,0.75,0.8,0.88);
   legend->AddEntry(h1,"CTF","f");
   legend->AddEntry(h2,"CosmicTF","f");
   legend->AddEntry(h3,"Regional","f");
   legend->SetBorderSize(0);
   legend->Draw();

 
}
