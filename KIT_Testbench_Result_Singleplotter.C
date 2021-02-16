void KIT_Testbench_Result_Singleplotter()
{
        
  TH1D *h= new TH1D("h"," R1 = 1.6MOhms;Resistance (MOhms);Number ",30,1.6,1.68);
	FILE*fp=NULL;
        fp=fopen("data.txt","r");
        float v;
	for(int n=0;n<1000;n++)
	 {
	   fscanf(fp,"%e \n",&v);
	   h->Fill(v);
	  }
	fclose(fp);
	gStyle->SetOptStat(111111);
	h->SetStats(1);	
       	h->SetMarkerStyle(21);
	h->SetMarkerSize(0.8);
	h->SetFillColor(kYellow);
	h->DrawCopy("P");
}
