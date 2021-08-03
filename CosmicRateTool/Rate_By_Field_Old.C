TString ToString( int num )
{
  ostringstream start;
  start<<num;
  TString start1=start.str();
  return start1;
}

void Rate_By_Field_Old()
{

  TFile *file = new TFile("Prompt2017_Bv2.root");
  vector<double> available_Mag_Field = {3.8112, 2.02203};

  TTree *tree;
  tree = (TTree*)file->Get("cosmicRateAnalyzer/Run");
  
  TCanvas* Canvas[9];
  for(int i=0; i<9; i++)
    {
      TString numstr=ToString(i);
      TString canvasName="Canvas"+numstr; 
      Canvas[i]= new TCanvas(canvasName,canvasName,604,82,856,836);    // Declare canvas
      gStyle->SetOptStat(0);
      Canvas[i]->Range(298434.4,-0.2989256,299381.3,2.010954);
      Canvas[i]->SetFillColor(0);
      Canvas[i]->SetBorderMode(0);
      Canvas[i]->SetBorderSize(2);
      Canvas[i]->SetTickx(1);
      Canvas[i]->SetTicky(1);
      Canvas[i]->SetGrid();
      Canvas[i]->SetLeftMargin(0.1883886);
      Canvas[i]->SetRightMargin(0.03909953);
      Canvas[i]->SetTopMargin(0.0875817);
      Canvas[i]->SetBottomMargin(0.1294118);
      Canvas[i]->SetFrameLineWidth(3);
      Canvas[i]->SetFrameBorderMode(0);
    }
  Int_t ci;      // for color index setting
  TColor *color; // for color definition with alpha
  
  int Color[3]={1,632,880};
  
  TMultiGraph mg_event_rate("event rate","Event Rate");
  TMultiGraph mg_track_rate("track rate","Track Rate");
  TMultiGraph mg_track_rate_PIX("track rate pixel","Track Rate PIXEL");
  TMultiGraph mg_track_rate_FPIX("track rate fpix","Track Rate FPIX");
  TMultiGraph mg_track_rate_BPIX("track rate bpix","Track Rate BPIX");
  TMultiGraph mg_track_rate_TIB("track rate tib","Track Rate TIB");
  TMultiGraph mg_track_rate_TID("track rate tid","Track Rate TID");
  TMultiGraph mg_track_rate_TOB("track rate tob","Track Rate TOB");
  TMultiGraph mg_track_rate_TEC("track rate tec","Track Rate TEC");
    
  double  run_time;
  unsigned int runnum;
  int     number_of_events;
  int     number_of_tracks;
  int     number_of_tracks_PIX;
  int     number_of_tracks_FPIX;
  int     number_of_tracks_BPIX;
  int     number_of_tracks_TID;
  int     number_of_tracks_TIB;
  int     number_of_tracks_TEC;
  int     number_of_tracks_TOB;
  
  tree->SetBranchAddress("run_time", &run_time);
  tree->SetBranchAddress("runnum", &runnum);
  tree->SetBranchAddress("number_of_events", &number_of_events);
  tree->SetBranchAddress("number_of_tracks", &number_of_tracks);
  tree->SetBranchAddress("number_of_tracks_PIX", &number_of_tracks_PIX);
  tree->SetBranchAddress("number_of_tracks_FPIX", &number_of_tracks_FPIX);
  tree->SetBranchAddress("number_of_tracks_BPIX", &number_of_tracks_BPIX);
  tree->SetBranchAddress("number_of_tracks_TID", &number_of_tracks_TID);
  tree->SetBranchAddress("number_of_tracks_TIB", &number_of_tracks_TIB);
  tree->SetBranchAddress("number_of_tracks_TEC", &number_of_tracks_TEC);
  tree->SetBranchAddress("number_of_tracks_TOB", &number_of_tracks_TOB);
  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //		Various Rates Declerations				
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  vector<double>  events               ;
  vector<double>  event_rate 		;
  vector<double>  event_rate_err	;
  vector<double>  track_rate 		;
  vector<double>  track_rate_err	;
  vector<double>  runNumber  		;
  vector<double>  runNumber_err	;
  vector<double>  track_rate_PIX 	;
  vector<double>  track_rate_PIX_err 	;
  vector<double>  track_rate_FPIX	;
  vector<double>  track_rate_FPIX_err	;
  vector<double>  track_rate_BPIX 	;
  vector<double>  track_rate_BPIX_err	;
  vector<double>  track_rate_TOB 	;
  vector<double>  track_rate_TOB_err 	;
  vector<double>  track_rate_TIB 	;
  vector<double>  track_rate_TIB_err 	;
  vector<double>  track_rate_TID 	;
  vector<double>  track_rate_TID_err 	;
  vector<double>  track_rate_TEC 	;
  vector<double>  track_rate_TEC_err 	;
  vector<double>  tracks		;
  vector<double>  tracks_err		;
  vector<double>  tracks_bpix		;
  vector<double>  tracks_fpix		;
  vector<double>  tracks_pix		;
  vector<double>  tracks_tec		;
  vector<double>  weight		;
  
  
  string Bar_Xtitle[8] = {"Event","Track","FPIX","BPIX","TIB","TID","TOB","TEC"};
  double Bar_Ytitle[8] = {0};
  
  double total_tracks = 0;
  double bpix_tracks = 0;
  double fpix_tracks = 0;
  double pix_tracks = 0;
  double tracks_TECoff = 0;
  
  int Run_Number, Events_in_Run; float Mag_Field;
  
  Long64_t n = tree->GetEntriesFast();
  std::cout<<"Total Runs in this files: "<<n<<endl;
  
  int i=0;
  // int Color[3]={1,632,880};
  
  for(auto& it : available_Mag_Field)
    {
      std::cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx value o f i xxxxxxxxxxxxxxxxxxxxxxxx"<<i<<std::endl;
      if(i==0) { ci=TColor::GetColor("#3113ba"); }
      else if(i==1) { ci=TColor::GetColor("#de0b1d"); }
      else { ci=TColor::GetColor("#33cc33"); }
      
      i++;
      
      std::cout<<"Magnetic Field for this loop is: "<<it<<std::endl;
      FILE *MagFields_for_Run = fopen("Events_per_Run.csv","r");
      
      Long64_t n = tree->GetEntriesFast();
      for (Long64_t jentry=0; jentry<n;jentry++)  // Loop over all Runs
	{
	  tree->GetEntry(jentry);
	  if (run_time == 0 || run_time < 0 ) continue;
	  
	  //=================  Get the magnetic field for that Run ==================//
	  fscanf(MagFields_for_Run,"%i,%i,%f\n",&Run_Number,&Events_in_Run,&Mag_Field);
	  std::cout<<" Run No: "<<Run_Number<<" : "<<"Events: "<<Events_in_Run<<" : "<<"M Field: "<<Mag_Field<<std::endl;
	  std::cout<<"Run no from CSV: "<<Run_Number<<" : From loop : "<<runnum<<std::endl;
	  
	  if(Run_Number!=runnum)
	    {
	      std::cout<<"CAUTION: Run numbers don't match !!!"<<std::endl;
	      continue;
	    }
	  
	  // Caluculate rate only for field 3.8T by removing 0T runs
	  if( (Mag_Field-it)>1e-3 ) 
	    {
	      std::cout<<"Mag Filed is not equal to "<<it<<std::endl;
	      continue;
	    }
	  
	  std::cout<<"Mag Filed is equal to "<<it<<std::endl;
	  
	  runNumber 	                .push_back( runnum );
	  runNumber_err                 .push_back(0);
	  event_rate	                .push_back( number_of_events/run_time );
	  event_rate_err	 	.push_back( sqrt(float(number_of_events))/run_time );
	  tracks	 	        .push_back( number_of_tracks );	  
	  track_rate	                .push_back( number_of_tracks/run_time );  	 
	  track_rate_err	 	.push_back( sqrt(float(number_of_tracks))/run_time );
	  track_rate_PIX                .push_back( number_of_tracks_PIX/run_time );
	  track_rate_PIX_err     	.push_back( sqrt(float(number_of_tracks_PIX))/run_time );
	  track_rate_FPIX	        .push_back( number_of_tracks_FPIX/run_time );
	  track_rate_FPIX_err   	.push_back( sqrt(float(number_of_tracks_FPIX))/run_time );
	  track_rate_BPIX       	.push_back( number_of_tracks_BPIX/run_time );
	  track_rate_BPIX_err   	.push_back( sqrt(float(number_of_tracks_BPIX))/run_time );
          track_rate_TIB	        .push_back( number_of_tracks_TIB/run_time );
	  track_rate_TIB_err    	.push_back( sqrt(float(number_of_tracks_TIB))/run_time );
	  track_rate_TID	        .push_back( number_of_tracks_TID/run_time );
	  track_rate_TID_err     	.push_back( sqrt(float(number_of_tracks_TID))/run_time );
	  track_rate_TOB	        .push_back( number_of_tracks_TOB/run_time );  
	  track_rate_TOB_err     	.push_back( sqrt(float(number_of_tracks_TOB))/run_time );
	  track_rate_TEC	        .push_back( number_of_tracks_TEC/run_time );
	  track_rate_TEC_err    	.push_back( sqrt(float(number_of_tracks_TEC))/run_time );

	}// Loop over runs
      
      //----------------------------------------TGraphs------------------------------------------------------
      TVectorD  runNumber_VecD 	        	;
      TVectorD  runNumber_err_VecD		;
      TVectorD  event_rate_VecD 		;
      TVectorD  event_rate_err_VecD    	        ;
      TVectorD  track_rate_VecD 		;
      TVectorD  track_rate_err_VecD	        ;
      TVectorD  track_rate_PIX_VecD      	;
      TVectorD  track_rate_PIX_err_VecD 	;
      TVectorD  track_rate_FPIX_VecD    	;
      TVectorD  track_rate_FPIX_err_VecD	;
      TVectorD  track_rate_BPIX_VecD    	;
      TVectorD  track_rate_BPIX_err_VecD	;
      TVectorD  track_rate_TIB_VecD     	;
      TVectorD  track_rate_TIB_err_VecD 	;
      TVectorD  track_rate_TID_VecD 	        ;
      TVectorD  track_rate_TID_err_VecD 	;
      TVectorD  track_rate_TOB_VecD     	;
      TVectorD  track_rate_TOB_err_VecD 	;
      TVectorD  track_rate_TEC_VecD 	        ;
      TVectorD  track_rate_TEC_err_VecD 	;
            
      runNumber_VecD.Use(runNumber.size(),&(runNumber[0]));
      runNumber_err_VecD.Use(runNumber_err.size(),&(runNumber_err[0]));
      event_rate_VecD.Use(event_rate.size(),&(event_rate[0]));
      event_rate_err_VecD.Use(event_rate_err.size(),&(event_rate_err[0]));	
      track_rate_VecD.Use(track_rate.size(),&(track_rate[0]));
      track_rate_err_VecD.Use(track_rate_err.size(),&(track_rate_err[0]));
      track_rate_PIX_VecD.Use(track_rate_PIX.size(),&(track_rate_PIX[0]));
      track_rate_PIX_err_VecD.Use(track_rate_PIX_err.size(),&(track_rate_PIX_err[0]));
      track_rate_FPIX_VecD.Use(track_rate_FPIX.size(),&(track_rate_FPIX[0]));
      track_rate_FPIX_err_VecD.Use(track_rate_FPIX_err.size(),&(track_rate_FPIX_err[0]));
      track_rate_BPIX_VecD.Use(track_rate_BPIX.size(),&(track_rate_BPIX[0]));
      track_rate_BPIX_err_VecD.Use(track_rate_BPIX_err.size(),&(track_rate_BPIX_err[0]));
      track_rate_TIB_VecD.Use(track_rate_TIB.size(),&(track_rate_TIB[0]));
      track_rate_TIB_err_VecD.Use(track_rate_TIB_err.size(),&(track_rate_TIB_err[0]));
      track_rate_TID_VecD.Use(track_rate_TID.size(),&(track_rate_TID[0]));
      track_rate_TID_err_VecD.Use(track_rate_TID_err.size(),&(track_rate_TID_err[0]));
      track_rate_TOB_VecD.Use(track_rate_TOB.size(),&(track_rate_TOB[0]));
      track_rate_TOB_err_VecD.Use(track_rate_TOB_err.size(),&(track_rate_TOB_err[0]));
      track_rate_TEC_VecD.Use(track_rate_TEC.size(),&(track_rate_TEC[0]));
      track_rate_TEC_err_VecD.Use(track_rate_TEC_err.size(),&(track_rate_TEC_err[0]));
 
      //===========  Legend  ============//
      TLegend *leg = new TLegend(0.6978923,0.7320513,0.9262295,0.874359,NULL,"brNDC");
      leg->SetBorderSize(1);
      leg->SetTextSize(0.03660131);
      leg->SetLineColor(1);
      leg->SetLineStyle(1);
      leg->SetLineWidth(2);
      leg->SetTextFont(62);
      leg->SetFillColor(0);
      leg->SetFillStyle(0);
      
      TLegendEntry *entry=leg->AddEntry("NULL","Magnetic Field","h");
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(1);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(21);
      entry->SetMarkerSize(1);
      entry->SetTextFont(42);
      
      entry=leg->AddEntry("NULL","3.8 T","lpf");
      entry->SetFillColor(0);
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(1);    
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(20);
      entry->SetMarkerSize(1.4);
      entry->SetTextFont(42);
      
      entry=leg->AddEntry("NULL","2 T","lpf");
      entry->SetFillColor(0);
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(1);     
      entry->SetMarkerColor(632);
      entry->SetMarkerStyle(20);
      entry->SetMarkerSize(1.4);
      entry->SetTextFont(42);

      //============  Text  =============//
      TLatex top_right_Title = TLatex();
      top_right_Title.SetTextFont(42);
      top_right_Title.SetTextSize(0.035);

      TLatex detector = TLatex();
      detector.SetTextFont(62);
      detector.SetTextSize(0.047);
            
      //+++++++++++++++++++++++++++++  Overall event event rate  +++++++++++++++++++++++++++++++++++++ 
      Canvas[0]->cd();
      TGraphErrors *gr_event_rate = new TGraphErrors(runNumber_VecD,event_rate_VecD,runNumber_err_VecD,event_rate_err_VecD);
      gr_event_rate->GetXaxis()->SetTitle("Run Number");
      gr_event_rate->GetXaxis()->SetLabelSize(0.03);
      gr_event_rate->GetXaxis()->SetNoExponent();
      gr_event_rate->GetYaxis()->SetTitle("Event Rate (Hz)");
      gr_event_rate->SetMarkerStyle(20);
      gr_event_rate->SetMarkerSize(1.4);
      gr_event_rate->SetMarkerColor(ci);
      mg_event_rate.Add(gr_event_rate);
      mg_event_rate.Draw("AP");
      mg_event_rate.SetTitle("");
      mg_event_rate.GetXaxis()->SetTitle("Run Number");
      mg_event_rate.GetXaxis()->SetLabelSize(0.03);
      mg_event_rate.GetXaxis()->SetTitleSize(0.05);
      mg_event_rate.GetXaxis()->SetNoExponent();
      mg_event_rate.GetYaxis()->SetTitle("Event Rate (Hz)");
      mg_event_rate.GetYaxis()->SetLabelSize(0.05);
      mg_event_rate.GetYaxis()->SetTitleSize(0.05);
      mg_event_rate.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "Event Rate");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------
      
      //++++++++++++++++++++++++++++++  Overall track rate  +++++++++++++++++++++++++++++++++++++++++++ 
      Canvas[1]->cd();
      TGraphErrors *gr_track_rate = new TGraphErrors(runNumber_VecD,track_rate_VecD,runNumber_err_VecD,track_rate_err_VecD);
      gr_track_rate->GetXaxis()->SetTitle("Run Number");
      gr_track_rate->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate->GetXaxis()->SetNoExponent();
      gr_track_rate->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate->SetMarkerStyle(20);
      gr_track_rate->SetMarkerSize(1.4);
      gr_track_rate->SetMarkerColor(ci);
      mg_track_rate.Add(gr_track_rate);
      mg_track_rate.Draw("AP");
      mg_track_rate.SetTitle("");
      mg_track_rate.GetXaxis()->SetTitle("Run Number");
      mg_track_rate.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate.GetXaxis()->SetNoExponent();
      mg_track_rate.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "Track Rate");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //+++++++++++++++++++++++++++++++  Total Pixel track rate +++++++++++++++++++++++++++++++++++++++
      Canvas[2]->cd();
      TGraphErrors *gr_track_rate_PIX = new TGraphErrors(runNumber_VecD,track_rate_PIX_VecD,runNumber_err_VecD,track_rate_PIX_err_VecD);
      gr_track_rate_PIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_PIX->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_PIX->GetXaxis()->SetNoExponent();
      gr_track_rate_PIX->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_PIX->SetMarkerStyle(20);
      gr_track_rate_PIX->SetMarkerSize(1.4);
      gr_track_rate_PIX->SetMarkerColor(ci);
      mg_track_rate_PIX.Add(gr_track_rate_PIX);
      mg_track_rate_PIX.Draw("AP");
      mg_track_rate_PIX.SetTitle("");
      mg_track_rate_PIX.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_PIX.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_PIX.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_PIX.GetXaxis()->SetNoExponent();
      mg_track_rate_PIX.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_PIX.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_PIX.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_PIX.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "PIXEL");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  FPIX track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[3]->cd();
      TGraphErrors *gr_track_rate_FPIX = new TGraphErrors(runNumber_VecD,track_rate_FPIX_VecD,runNumber_err_VecD,track_rate_FPIX_err_VecD);
      gr_track_rate_FPIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_FPIX->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_FPIX->GetXaxis()->SetNoExponent();
      gr_track_rate_FPIX->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_FPIX->SetMarkerStyle(20);
      gr_track_rate_FPIX->SetMarkerSize(1.4);
      gr_track_rate_FPIX->SetMarkerColor(ci);
      mg_track_rate_FPIX.Add(gr_track_rate_FPIX);
      mg_track_rate_FPIX.Draw("AP");
      mg_track_rate_FPIX.SetTitle("");
      mg_track_rate_FPIX.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_FPIX.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_FPIX.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_FPIX.GetXaxis()->SetNoExponent();
      mg_track_rate_FPIX.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_FPIX.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_FPIX.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_FPIX.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "FPIX");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  BPIX track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[4]->cd();
      TGraphErrors *gr_track_rate_BPIX = new TGraphErrors(runNumber_VecD,track_rate_BPIX_VecD,runNumber_err_VecD,track_rate_BPIX_err_VecD);
      gr_track_rate_BPIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_BPIX->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_BPIX->GetXaxis()->SetNoExponent();
      gr_track_rate_BPIX->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_BPIX->SetMarkerStyle(20);
      gr_track_rate_BPIX->SetMarkerSize(1.4);
      gr_track_rate_BPIX->SetMarkerColor(ci);
      mg_track_rate_BPIX.Add(gr_track_rate_BPIX);
      mg_track_rate_BPIX.Draw("AP");
      mg_track_rate_BPIX.SetTitle("");
      mg_track_rate_BPIX.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_BPIX.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_BPIX.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_BPIX.GetXaxis()->SetNoExponent();
      mg_track_rate_BPIX.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_BPIX.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_BPIX.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_BPIX.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "BPIX");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TIB track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[5]->cd();
      TGraphErrors *gr_track_rate_TIB = new TGraphErrors(runNumber_VecD,track_rate_TIB_VecD,runNumber_err_VecD,track_rate_TIB_err_VecD);
      gr_track_rate_TIB->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIB->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TIB->GetXaxis()->SetNoExponent();
      gr_track_rate_TIB->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TIB->SetMarkerStyle(20);
      gr_track_rate_TIB->SetMarkerSize(1.4);
      gr_track_rate_TIB->SetMarkerColor(ci);
      mg_track_rate_TIB.Add(gr_track_rate_TIB);
      mg_track_rate_TIB.Draw("AP");
      mg_track_rate_TIB.SetTitle("");
      mg_track_rate_TIB.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_TIB.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_TIB.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_TIB.GetXaxis()->SetNoExponent();
      mg_track_rate_TIB.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_TIB.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_TIB.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_TIB.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "TIB");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TID track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[6]->cd();
      TGraphErrors *gr_track_rate_TID = new TGraphErrors(runNumber_VecD,track_rate_TID_VecD,runNumber_err_VecD,track_rate_TID_err_VecD);
      gr_track_rate_TID->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TID->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TID->GetXaxis()->SetNoExponent();
      gr_track_rate_TID->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TID->SetMarkerStyle(20);
      gr_track_rate_TID->SetMarkerSize(1.4);
      gr_track_rate_TID->SetMarkerColor(ci);
      mg_track_rate_TID.Add(gr_track_rate_TID);
      mg_track_rate_TID.Draw("AP");
      mg_track_rate_TID.SetTitle("");
      mg_track_rate_TID.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_TID.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_TID.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_TID.GetXaxis()->SetNoExponent();
      mg_track_rate_TID.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_TID.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_TID.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_TID.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "TID");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TOB track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[7]->cd();
      TGraphErrors *gr_track_rate_TOB = new TGraphErrors(runNumber_VecD,track_rate_TOB_VecD,runNumber_err_VecD,track_rate_TOB_err_VecD);
      gr_track_rate_TOB->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TOB->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TOB->GetXaxis()->SetNoExponent();
      gr_track_rate_TOB->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TOB->SetMarkerStyle(20);
      gr_track_rate_TOB->SetMarkerSize(1.4);
      gr_track_rate_TOB->SetMarkerColor(ci);
      mg_track_rate_TOB.Add(gr_track_rate_TOB);
      mg_track_rate_TOB.Draw("AP");
      mg_track_rate_TOB.SetTitle("");
      mg_track_rate_TOB.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_TOB.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_TOB.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_TOB.GetXaxis()->SetNoExponent();
      mg_track_rate_TOB.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_TOB.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_TOB.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_TOB.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "TOB");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  Total TEC track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[8]->cd();
      TGraphErrors *gr_track_rate_TEC = new TGraphErrors(runNumber_VecD,track_rate_TEC_VecD,runNumber_err_VecD,track_rate_TEC_err_VecD);
      gr_track_rate_TEC->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TEC->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TEC->GetXaxis()->SetNoExponent();
      gr_track_rate_TEC->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TEC->SetMarkerStyle(20);
      gr_track_rate_TEC->SetMarkerSize(1.4);
      gr_track_rate_TEC->SetMarkerColor(ci);
      mg_track_rate_TEC.Add(gr_track_rate_TEC);
      mg_track_rate_TEC.Draw("AP");
      mg_track_rate_TEC.SetTitle("");
      mg_track_rate_TEC.GetXaxis()->SetTitle("Run Number");
      mg_track_rate_TEC.GetXaxis()->SetLabelSize(0.03);
      mg_track_rate_TEC.GetXaxis()->SetTitleSize(0.05);
      mg_track_rate_TEC.GetXaxis()->SetNoExponent();
      mg_track_rate_TEC.GetYaxis()->SetTitle("Track Rate (Hz)");
      mg_track_rate_TEC.GetYaxis()->SetLabelSize(0.05);
      mg_track_rate_TEC.GetYaxis()->SetTitleSize(0.05);
      mg_track_rate_TEC.GetYaxis()->SetTitleFont(42);
      top_right_Title.DrawLatexNDC(0.49, 0.94, "Cosmic rays 2017 (Commissioning)");
      detector.DrawLatexNDC(0.23, 0.83, "TEC");
      leg->Draw();
      //-----------------------------------------------------------------------------------------------

      runNumber.clear();
      runNumber_err.clear();
      event_rate.clear();		
      event_rate_err.clear();	        ;
      track_rate.clear();
      track_rate_err.clear();
      track_rate_PIX.clear();
      track_rate_PIX_err.clear();
      track_rate_FPIX.clear();
      track_rate_FPIX_err.clear();
      track_rate_BPIX.clear();
      track_rate_BPIX_err.clear();
      track_rate_TIB.clear();
      track_rate_TIB_err.clear();
      track_rate_TID.clear();
      track_rate_TID_err.clear();
      track_rate_TOB.clear();
      track_rate_TOB_err.clear();
      track_rate_TEC.clear();
      track_rate_TEC_err.clear();
      weight.clear();

      fclose(MagFields_for_Run); 
    }


  //+++++++++++++++++++++++++++++       Make Directories and store plots there    +++++++++++++++++++++++++++++++++++++
  gSystem->Exec("mkdir -p Rate_Plots_try");
  
  Canvas[0]->SaveAs("event_rate.png");
  Canvas[1]->SaveAs("track_rate.png");
  Canvas[2]->SaveAs("track_rate_PIX.png");
  Canvas[3]->SaveAs("track_rate_FPIX.png");
  Canvas[4]->SaveAs("track_rate_BPIX.png");
  Canvas[5]->SaveAs("track_rate_TIB.png");
  Canvas[6]->SaveAs("track_rate_TID.png");
  Canvas[7]->SaveAs("track_rate_TOB.png");
  Canvas[8]->SaveAs("track_rate_TEC.png");
  
  gSystem->Exec("mv event_rate.png Rate_Plots_try");
  gSystem->Exec("mv track_rate.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_PIX.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_FPIX.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_BPIX.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIB.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TID.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TOB.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TEC.png Rate_Plots_try");
 
  Canvas[0]->SaveAs("event_rate.pdf");
  Canvas[1]->SaveAs("track_rate.pdf");
  Canvas[2]->SaveAs("track_rate_PIX.pdf");
  Canvas[3]->SaveAs("track_rate_FPIX.pdf");
  Canvas[4]->SaveAs("track_rate_BPIX.pdf");
  Canvas[5]->SaveAs("track_rate_TIB.pdf");
  Canvas[6]->SaveAs("track_rate_TID.pdf");
  Canvas[7]->SaveAs("track_rate_TOB.pdf");
  Canvas[8]->SaveAs("track_rate_TEC.pdf");
  
  gSystem->Exec("mv event_rate.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_PIX.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_FPIX.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_BPIX.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIB.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_TID.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_TOB.pdf Rate_Plots_try");
  gSystem->Exec("mv track_rate_TEC.pdf Rate_Plots_try");

  Canvas[0]->SaveAs("event_rate.C");
  Canvas[1]->SaveAs("track_rate.C");
  Canvas[2]->SaveAs("track_rate_PIX.C");
  Canvas[3]->SaveAs("track_rate_FPIX.C");
  Canvas[4]->SaveAs("track_rate_BPIX.C");
  Canvas[5]->SaveAs("track_rate_TIB.C");
  Canvas[6]->SaveAs("track_rate_TID.C");
  Canvas[7]->SaveAs("track_rate_TOB.C");
  Canvas[8]->SaveAs("track_rate_TEC.C");
  
  gSystem->Exec("mv event_rate.C Rate_Plots_try");
  gSystem->Exec("mv track_rate.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_PIX.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_FPIX.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_BPIX.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIB.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TID.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TOB.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TEC.C Rate_Plots_try");
 
  for(int i=0; i<9; i++)
    {
      
      Canvas[i]->Close();
      
    }
  
}
