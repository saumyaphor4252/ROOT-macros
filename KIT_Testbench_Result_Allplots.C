void  KIT_Testbench_Result_Allplots()
{
        
        TH1D *h1= new TH1D("h1"," C1 = 47pF at 1kHz;Capacitance (pF);Number",33,46.6270,46.66);
	TH1D *h2= new TH1D("h2"," C2 = 0.5pF at 1MHz;Capacitance (pF);Number",23,0.573,0.576);
	TH1D *h3= new TH1D("h3"," C3 = 30pF at 1kHz;Capacitance (pF);Number",22,27.412,27.441);
	TH1D *h4= new TH1D("h4"," C4 = 47pF at 1kHz;Capacitance (pF);Number",19,46.217,46.242);
	TH1D *h5= new TH1D("h5"," C5 = 100pF at 1kHz;Capacitance (pF);Number",17,102.567,102.60);
	TH1D *h6= new TH1D("h6"," C6 = 2.7nF at 1kHz;Capacitance (nF);Number",18,2.485,2.4925);
	TH1D *h7= new TH1D("h7","C7 = 2.7 nF at 1kHz;Capacitance (nF);Number ",19,2.4193,2.4197);
	TH1D *h8= new TH1D("h8"," R1 = 1.6 MOhms;Resistance (MOhms);Number",30,46.6270,46.6599);
	TH1D *h9= new TH1D("h9"," R1 = 1 GOhms;Resistance (GOhms);Number",30,46.6270,46.6599);
	TH1D *h10= new TH1D("h10"," R1 = 50 MOhms;Resistance (MOhms);Number",30,46.6270,46.6599);
	TH1D *h11= new TH1D("h11"," R1 = 500 MOhms;Resistance (MOhms);Number",30,46.6270,46.6599);
	
	FILE*fp=NULL;
        fp=fopen("data.txt","r");
        float c1,c2,c3,c4,c5,c6,c7,r1,r2,r3,r4;
	for(int n=0;n<1000;n++)
	 {
	   fscanf(fp,"%e \t %e \t %e \t %e \t %e \t %e \t %e \n ",&c1,&c2,&c3,&c4,&c5,&c6,&c7);
	   h1->Fill(c1);
	   h2->Fill(c2);
	   h3->Fill(c3);
	   h4->Fill(c4);
	   h5->Fill(c5);
	   h6->Fill(c6);
	   h7->Fill(c7);
	   h8->Fill(r1);
	   h9->Fill(r2);
	   h10->Fill(r3);
	   h11->Fill(r4);
	   
	  }
	fclose(fp);
	h1->SetStats(1);
       	h1->SetMarkerStyle(21);
	h1->SetMarkerSize(0.8);
	h1->SetFillColor(kYellow);
	h1->DrawCopy("P");

	h2->SetStats(1);
       	h2->SetMarkerStyle(21);
	h2->SetMarkerSize(0.8);
	h2->SetFillColor(kYellow);
	h2->DrawCopy("P");

	h3->SetStats(1);
       	h3->SetMarkerStyle(21);
	h3->SetMarkerSize(0.8);
	h3->SetFillColor(kYellow);
	h3->DrawCopy("P");

	h4->SetStats(1);
       	h4->SetMarkerStyle(21);
	h4->SetMarkerSize(0.8);
	h4->SetFillColor(kYellow);
	h4->DrawCopy("P");

	h5->SetStats(1);
       	h5->SetMarkerStyle(21);
	h5->SetMarkerSize(0.8);
	h5->SetFillColor(kYellow);
	h5->DrawCopy("P");

	h6->SetStats(1);
       	h6->SetMarkerStyle(21);
	h6->SetMarkerSize(0.8);
	h6->SetFillColor(kYellow);
	h6->DrawCopy("P");

	h7->SetStats(1);
       	h7->SetMarkerStyle(21);
	h7->SetMarkerSize(0.8);
	h7->SetFillColor(kYellow);
	h7->DrawCopy("P");
	
	h8->SetStats(1);
       	h8->SetMarkerStyle(21);
	h8->SetMarkerSize(0.8);
	h8->SetFillColor(kYellow);
	h8->DrawCopy("P");

	h9->SetStats(1);
       	h9->SetMarkerStyle(21);
	h9->SetMarkerSize(0.8);
	h9->SetFillColor(kYellow);
	h9->DrawCopy("P");

	h10->SetStats(1);
       	h10->SetMarkerStyle(21);
	h10->SetMarkerSize(0.8);
	h10->SetFillColor(kYellow);
	h10->DrawCopy("P");

	h11->SetStats(1);
       	h11->SetMarkerStyle(21);
	h11->SetMarkerSize(0.8);
	h11->SetFillColor(kYellow);
	h11->DrawCopy("P");*/
       
	//Legend
        TLegend	*legend=new TLegend(0.6,0.65,0.88,0.85);
	legend->SetTextFont(72);
	legend->SetTextSize(0.04);
	legend->AddEntry(h,"Data","lpe");
	legend->Draw();
	
}
