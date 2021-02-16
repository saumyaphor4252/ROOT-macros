TString ToString( int num )
{
  ostringstream start;
  start<<num;
  TString start1=start.str();
  return start1;
}

void CombinedRatePlots()
{
  TString Allfiles[3] = {"CTF_2018.root","CosmicTF_2018.root","Regional_2018.root"};
  
  Int_t ci;      // for color index setting
  TColor *color; // for color definition with alpha

  TCanvas* Canvas[13];
  for(int i=0; i<13; i++)
   {
       TString numstr=ToString(i);
       TString canvasName="Canvas"+numstr; 
       Canvas[i]= new TCanvas(canvasName,canvasName,226,57,1308,893);    // Declare canvas
       gStyle->SetOptStat(0);
       Canvas[i]->Range(-3.209404,-0.0221648,2.884637,0.2547346);
       Canvas[i]->SetFillColor(0);
       Canvas[i]->SetBorderMode(0);
       Canvas[i]->SetBorderSize(2);
       Canvas[i]->SetTickx(1);
       Canvas[i]->SetTicky(1);
       Canvas[i]->SetGrid();
       Canvas[i]->SetRightMargin(0.0467075);
       Canvas[i]->SetTopMargin(0.08932715);
       Canvas[i]->SetBottomMargin(0.0800464);
       Canvas[i]->SetFrameBorderMode(0);
    }

  TMultiGraph mg_event_rate("event rate","Event Rate");
  TMultiGraph mg_track_rate("track rate","Track Rate");
  TMultiGraph mg_track_rate_PIX("track rate pixel","Track Rate PIXEL");
  TMultiGraph mg_track_rate_FPIX("track rate fpix","Track Rate FPIX");
  TMultiGraph mg_track_rate_BPIX("track rate bpix","Track Rate BPIX");
  TMultiGraph mg_track_rate_TIB("track rate tib","Track Rate TIB");
  TMultiGraph mg_track_rate_TID("track rate tid","Track Rate TID");
  TMultiGraph mg_track_rate_TIDM("track rate tidm","Track Rate TIDM");
  TMultiGraph mg_track_rate_TIDP("track rate tidp","Track Rate TIDP");
  TMultiGraph mg_track_rate_TOB("track rate tob","Track Rate TOB");
  TMultiGraph mg_track_rate_TEC("track rate tec","Track Rate TEC");
  TMultiGraph mg_track_rate_TECM("track rate tecm","Track Rate TECM");
  TMultiGraph mg_track_rate_TECP("track rate tecp","Track Rate TECP");

  for(int nFile=0; nFile<3 ;nFile++)
    {
      TString fileName = Allfiles[nFile].Data();
      TFile *file = new TFile(fileName.Data());
      TTree *tree;
      tree = (TTree*)file->Get("cosmicRateAnalyzer/Run");

      int j=0;
      double total_tracks = 0;
      
      double  run_time;
      unsigned int runnum;
      int     number_of_events;
      int     number_of_tracks;
      int     number_of_tracks_FPIX;
      int     number_of_tracks_BPIX;
      int     number_of_tracks_PIX;
      int     number_of_tracks_TIB;
      int     number_of_tracks_TID;
      int     number_of_tracks_TIDM;
      int     number_of_tracks_TIDP;
      int     number_of_tracks_TOB;
      int     number_of_tracks_TEC;
      int     number_of_tracks_TECP;    
      int     number_of_tracks_TECM;
      
      tree->SetBranchAddress("run_time", &run_time);
      tree->SetBranchAddress("runnum", &runnum);
      tree->SetBranchAddress("number_of_events", &number_of_events);
      tree->SetBranchAddress("number_of_tracks", &number_of_tracks);
      tree->SetBranchAddress("number_of_tracks_PIX", &number_of_tracks_PIX);
      tree->SetBranchAddress("number_of_tracks_FPIX", &number_of_tracks_FPIX);
      tree->SetBranchAddress("number_of_tracks_BPIX", &number_of_tracks_BPIX);
      tree->SetBranchAddress("number_of_tracks_TIB", &number_of_tracks_TIB);
      tree->SetBranchAddress("number_of_tracks_TID", &number_of_tracks_TID);
      tree->SetBranchAddress("number_of_tracks_TIDM", &number_of_tracks_TIDM);
      tree->SetBranchAddress("number_of_tracks_TIDP", &number_of_tracks_TIDP);
      tree->SetBranchAddress("number_of_tracks_TOB", &number_of_tracks_TOB);
      tree->SetBranchAddress("number_of_tracks_TEC", &number_of_tracks_TEC);
      tree->SetBranchAddress("number_of_tracks_TECP", &number_of_tracks_TECP);
      tree->SetBranchAddress("number_of_tracks_TECM", &number_of_tracks_TECM);     
      
      //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      //		Various Rates Declerations				
      //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
      vector<double>  event_rate 		;
      vector<double>  event_rate_err	        ;
      vector<double>  track_rate 		;
      vector<double>  track_rate_err     	;
      vector<double>  runNumber  		;
      vector<double>  runNumber_err      	;
      vector<double>  tracks	  	        ;
      vector<double>  tracks_err		;
      vector<double>  weight	          	;
      vector<double>  track_rate_PIX 	        ;
      vector<double>  track_rate_PIX_err 	;
      vector<double>  track_rate_FPIX    	;
      vector<double>  track_rate_FPIX_err	;
      vector<double>  track_rate_BPIX     	;
      vector<double>  track_rate_BPIX_err	;
      vector<double>  track_rate_TIB     	;
      vector<double>  track_rate_TIB_err 	;
      vector<double>  track_rate_TID     	;
      vector<double>  track_rate_TID_err 	;
      vector<double>  track_rate_TIDM     	;
      vector<double>  track_rate_TIDM_err 	;
      vector<double>  track_rate_TIDP     	;
      vector<double>  track_rate_TIDP_err 	;
      vector<double>  track_rate_TOB 	        ;
      vector<double>  track_rate_TOB_err 	;
      vector<double>  track_rate_TEC     	;
      vector<double>  track_rate_TEC_err 	;
      vector<double>  track_rate_TECP     	;
      vector<double>  track_rate_TECP_err	;
      vector<double>  track_rate_TECM    	;
      vector<double>  track_rate_TECM_err	;

      vector<double>  tracks_bpix		;
      vector<double>  tracks_fpix		;
      vector<double>  tracks_pix		;
      vector<double>  tracks_tec		;
 
      
      Long64_t n = tree->GetEntriesFast();
      for (Long64_t jentry=0; jentry<n;jentry++) 
	{
	  tree->GetEntry(jentry);
	  if (run_time == 0 || run_time < 0 ) continue;
	  if (runnum == 319327) continue;

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
	  track_rate_TIDM	        .push_back( number_of_tracks_TIDM/run_time );
	  track_rate_TIDM_err     	.push_back( sqrt(float(number_of_tracks_TIDM))/run_time );
	  track_rate_TIDP	        .push_back( number_of_tracks_TIDP/run_time );
	  track_rate_TIDP_err     	.push_back( sqrt(float(number_of_tracks_TIDP))/run_time );
	  track_rate_TOB	        .push_back( number_of_tracks_TOB/run_time );  
	  track_rate_TOB_err     	.push_back( sqrt(float(number_of_tracks_TOB))/run_time );
	  track_rate_TEC	        .push_back( number_of_tracks_TEC/run_time );
	  track_rate_TEC_err    	.push_back( sqrt(float(number_of_tracks_TEC))/run_time );
	  track_rate_TECP               .push_back( number_of_tracks_TECP/run_time );
	  track_rate_TECP_err   	.push_back( sqrt(float(number_of_tracks_TECP))/run_time );
	  track_rate_TECM	        .push_back( number_of_tracks_TECM/run_time );
	  track_rate_TECM_err   	.push_back( sqrt(float(number_of_tracks_TECM))/run_time );
	  
	  total_tracks+= tracks[j];
	  j++;
	}

      if(nFile==0) { ci=TColor::GetColor("#3113ba"); }
      else if(nFile==1) { ci=TColor::GetColor("#de0b1d"); }
      else if(nFile==2) { ci=TColor::GetColor("#33cc33"); }
      
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
      TVectorD  track_rate_TIDM_VecD 	        ;
      TVectorD  track_rate_TIDM_err_VecD 	;
      TVectorD  track_rate_TIDP_VecD 	        ;
      TVectorD  track_rate_TIDP_err_VecD 	;
      TVectorD  track_rate_TOB_VecD     	;
      TVectorD  track_rate_TOB_err_VecD 	;
      TVectorD  track_rate_TEC_VecD 	        ;
      TVectorD  track_rate_TEC_err_VecD 	;
      TVectorD  track_rate_TECP_VecD    	;
      TVectorD  track_rate_TECP_err_VecD	;
      TVectorD  track_rate_TECM_VecD    	;
      TVectorD  track_rate_TECM_err_VecD	;
           
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
      track_rate_TIDM_VecD.Use(track_rate_TIDM.size(),&(track_rate_TIDM[0]));
      track_rate_TIDM_err_VecD.Use(track_rate_TIDM_err.size(),&(track_rate_TIDM_err[0]));
      track_rate_TIDP_VecD.Use(track_rate_TIDP.size(),&(track_rate_TIDP[0]));
      track_rate_TIDP_err_VecD.Use(track_rate_TIDP_err.size(),&(track_rate_TIDP_err[0]));   
      track_rate_TOB_VecD.Use(track_rate_TOB.size(),&(track_rate_TOB[0]));
      track_rate_TOB_err_VecD.Use(track_rate_TOB_err.size(),&(track_rate_TOB_err[0]));
      track_rate_TEC_VecD.Use(track_rate_TEC.size(),&(track_rate_TEC[0]));
      track_rate_TEC_err_VecD.Use(track_rate_TEC_err.size(),&(track_rate_TEC_err[0]));
      track_rate_TECP_VecD.Use(track_rate_TECP.size(),&(track_rate_TECP[0]));
      track_rate_TECP_err_VecD.Use(track_rate_TECP_err.size(),&(track_rate_TECP_err[0]));
      track_rate_TECM_VecD.Use(track_rate_TECM.size(),&(track_rate_TECM[0]));
      track_rate_TECM_err_VecD.Use(track_rate_TECM_err.size(),&(track_rate_TECM_err[0]));      
      
      //+++++++++++++++++++++++++++++  Overall event event rate  +++++++++++++++++++++++++++++++++++++ 
      Canvas[0]->cd();
      TGraphErrors *gr_event_rate = new TGraphErrors(runNumber_VecD,event_rate_VecD,runNumber_err_VecD,event_rate_err_VecD);
      gr_event_rate->GetXaxis()->SetTitle("Run Number");
      gr_event_rate->GetXaxis()->SetLabelSize(0.03);
      gr_event_rate->GetXaxis()->SetNoExponent();
      gr_event_rate->GetYaxis()->SetTitle("Event Rate (in Hz)");
      gr_event_rate->SetMarkerStyle(20);
      gr_event_rate->SetMarkerSize(1.2);
      gr_event_rate->SetMarkerColor(ci);
      gr_event_rate->SetTitle("Event Rate");
      mg_event_rate.Add(gr_event_rate);
      mg_event_rate.Draw("AP");
      //-----------------------------------------------------------------------------------------------
      
      //++++++++++++++++++++++++++++++  Overall track rate  +++++++++++++++++++++++++++++++++++++++++++ 
      Canvas[1]->cd();
      TGraphErrors *gr_track_rate = new TGraphErrors(runNumber_VecD,track_rate_VecD,runNumber_err_VecD,track_rate_err_VecD);
      gr_track_rate->GetXaxis()->SetTitle("Run Number");
      gr_track_rate->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate->GetXaxis()->SetNoExponent();
      gr_track_rate->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate->SetMarkerStyle(20);
      gr_track_rate->SetMarkerSize(1.2);
      gr_track_rate->SetMarkerColor(ci);
      gr_track_rate->SetTitle("Track Rate");
      mg_track_rate.Add(gr_track_rate);
      mg_track_rate.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //+++++++++++++++++++++++++++++++  Total Pixel track rate +++++++++++++++++++++++++++++++++++++++
      Canvas[2]->cd();
      TGraphErrors *gr_track_rate_PIX = new TGraphErrors(runNumber_VecD,track_rate_PIX_VecD,runNumber_err_VecD,track_rate_PIX_err_VecD);
      gr_track_rate_PIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_PIX->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_PIX->GetXaxis()->SetNoExponent();
      gr_track_rate_PIX->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_PIX->SetMarkerStyle(20);
      gr_track_rate_PIX->SetMarkerSize(1.2);
      gr_track_rate_PIX->SetMarkerColor(ci);
      gr_track_rate_PIX->SetTitle("Pixel Track Rate");
      mg_track_rate_PIX.Add(gr_track_rate_PIX);
      mg_track_rate_PIX.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  FPIX track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[3]->cd();
      TGraphErrors *gr_track_rate_FPIX = new TGraphErrors(runNumber_VecD,track_rate_FPIX_VecD,runNumber_err_VecD,track_rate_FPIX_err_VecD);
      gr_track_rate_FPIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_FPIX->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_FPIX->GetXaxis()->SetNoExponent();
      gr_track_rate_FPIX->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_FPIX->SetMarkerStyle(20);
      gr_track_rate_FPIX->SetMarkerSize(1.2);
      gr_track_rate_FPIX->SetMarkerColor(ci);
      gr_track_rate_FPIX->SetTitle("FPIX Track Rate");
      mg_track_rate_FPIX.Add(gr_track_rate_FPIX);
      mg_track_rate_FPIX.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  BPIX track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[4]->cd();
      TGraphErrors *gr_track_rate_BPIX = new TGraphErrors(runNumber_VecD,track_rate_BPIX_VecD,runNumber_err_VecD,track_rate_BPIX_err_VecD);
      gr_track_rate_BPIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_BPIX->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_BPIX->GetXaxis()->SetNoExponent();
      gr_track_rate_BPIX->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_BPIX->SetMarkerStyle(20);
      gr_track_rate_BPIX->SetMarkerSize(1.2);
      gr_track_rate_BPIX->SetMarkerColor(ci);
      gr_track_rate_BPIX->SetTitle("BPIX Track Rate");
      mg_track_rate_BPIX.Add(gr_track_rate_BPIX);
      mg_track_rate_BPIX.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TIB track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[5]->cd();
      TGraphErrors *gr_track_rate_TIB = new TGraphErrors(runNumber_VecD,track_rate_TIB_VecD,runNumber_err_VecD,track_rate_TIB_err_VecD);
      gr_track_rate_TIB->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIB->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TIB->GetXaxis()->SetNoExponent();
      gr_track_rate_TIB->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TIB->SetMarkerStyle(20);
      gr_track_rate_TIB->SetMarkerSize(1.2);
      gr_track_rate_TIB->SetMarkerColor(ci);
      gr_track_rate_TIB->SetTitle("TIB Track Rate");
      mg_track_rate_TIB.Add(gr_track_rate_TIB);
      mg_track_rate_TIB.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TID track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[6]->cd();
      TGraphErrors *gr_track_rate_TID = new TGraphErrors(runNumber_VecD,track_rate_TID_VecD,runNumber_err_VecD,track_rate_TID_err_VecD);
      gr_track_rate_TID->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TID->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TID->GetXaxis()->SetNoExponent();
      gr_track_rate_TID->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TID->SetMarkerStyle(20);
      gr_track_rate_TID->SetMarkerSize(1.2);
      gr_track_rate_TID->SetMarkerColor(ci);
      gr_track_rate_TID->SetTitle("TID Track Rate");
      mg_track_rate_TID.Add(gr_track_rate_TID);
      mg_track_rate_TID.Draw("AP");
      //-----------------------------------------------------------------------------------------------

       //++++++++++++++++++++++++++++++++  TID- track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[7]->cd();
      TGraphErrors *gr_track_rate_TIDM = new TGraphErrors(runNumber_VecD,track_rate_TIDM_VecD,runNumber_err_VecD,track_rate_TIDM_err_VecD);
      gr_track_rate_TIDM->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIDM->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TIDM->GetXaxis()->SetNoExponent();
      gr_track_rate_TIDM->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TIDM->SetMarkerStyle(20);
      gr_track_rate_TIDM->SetMarkerSize(1.2);
      gr_track_rate_TIDM->SetMarkerColor(ci);
      gr_track_rate_TIDM->SetTitle("TID- Track Rate");
      mg_track_rate_TIDM.Add(gr_track_rate_TIDM);
      mg_track_rate_TIDM.Draw("AP");
      //-----------------------------------------------------------------------------------------------

       //++++++++++++++++++++++++++++++++  TID+ track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[8]->cd();
      TGraphErrors *gr_track_rate_TIDP = new TGraphErrors(runNumber_VecD,track_rate_TIDP_VecD,runNumber_err_VecD,track_rate_TIDP_err_VecD);
      gr_track_rate_TIDP->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIDP->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TIDP->GetXaxis()->SetNoExponent();
      gr_track_rate_TIDP->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TIDP->SetMarkerStyle(20);
      gr_track_rate_TIDP->SetMarkerSize(1.2);
      gr_track_rate_TIDP->SetMarkerColor(ci);
      gr_track_rate_TIDP->SetTitle("TID+ Track Rate");
      mg_track_rate_TIDP.Add(gr_track_rate_TIDP);
      mg_track_rate_TIDP.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TOB track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[9]->cd();
      TGraphErrors *gr_track_rate_TOB = new TGraphErrors(runNumber_VecD,track_rate_TOB_VecD,runNumber_err_VecD,track_rate_TOB_err_VecD);
      gr_track_rate_TOB->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TOB->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TOB->GetXaxis()->SetNoExponent();
      gr_track_rate_TOB->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TOB->SetMarkerStyle(20);
      gr_track_rate_TOB->SetMarkerSize(1.2);
      gr_track_rate_TOB->SetMarkerColor(ci);
      gr_track_rate_TOB->SetTitle("TOB Track Rate");
      mg_track_rate_TOB.Add(gr_track_rate_TOB);
      mg_track_rate_TOB.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  Total TEC track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[10]->cd();
      TGraphErrors *gr_track_rate_TEC = new TGraphErrors(runNumber_VecD,track_rate_TEC_VecD,runNumber_err_VecD,track_rate_TEC_err_VecD);
      gr_track_rate_TEC->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TEC->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TEC->GetXaxis()->SetNoExponent();
      gr_track_rate_TEC->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TEC->SetMarkerStyle(20);
      gr_track_rate_TEC->SetMarkerSize(1.2);
      gr_track_rate_TEC->SetMarkerColor(ci);
      gr_track_rate_TEC->SetTitle("TEC Track Rate");
      mg_track_rate_TEC.Add(gr_track_rate_TEC);
      mg_track_rate_TEC.Draw("AP");
      //-----------------------------------------------------------------------------------------------

      //++++++++++++++++++++++++++++++++  TEC+/- track rate  ++++++++++++++++++++++++++++++++++++++++++++
      Canvas[11]->cd();
      TGraphErrors *gr_track_rate_TECP = new TGraphErrors(runNumber_VecD,track_rate_TECP_VecD,runNumber_err_VecD,track_rate_TECP_err_VecD);
      gr_track_rate_TECP->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TECP->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TECP->GetXaxis()->SetNoExponent();
      gr_track_rate_TECP->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TECP->SetMarkerStyle(20);
      gr_track_rate_TECP->SetMarkerSize(1.2);
      gr_track_rate_TECP->SetMarkerColor(ci);
      gr_track_rate_TECP->SetTitle("TEC+ Track Rate");
      mg_track_rate_TECP.Add(gr_track_rate_TECP);
      mg_track_rate_TECP.Draw("AP");

      TGraphErrors *gr_track_rate_TECM = new TGraphErrors(runNumber_VecD,track_rate_TECM_VecD,runNumber_err_VecD,track_rate_TECM_err_VecD);
      Canvas[12]->cd();
      gr_track_rate_TECM->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TECM->GetXaxis()->SetLabelSize(0.03);
      gr_track_rate_TECM->GetXaxis()->SetNoExponent();
      gr_track_rate_TECM->GetYaxis()->SetTitle("Track Rate (in Hz)");
      gr_track_rate_TECM->SetMarkerStyle(20);
      gr_track_rate_TECM->SetMarkerSize(1.2);
      gr_track_rate_TECM->SetMarkerColor(ci);
      gr_track_rate_TECM->SetTitle("TEC- Track Rate");
      mg_track_rate_TECM.Add(gr_track_rate_TECM);
      mg_track_rate_TECM.Draw("AP");

      /*
      //-----------------------------------------------------------------------------------------------
      //					Weighted Mean calculation
      //-----------------------------------------------------------------------------------------------				
      double total_weight		= 0;
      double weighted_mean_track_rate;
      double weighted_mean_event_rate;
      
      for (int k = 0; k < j; k++)
      {
      weight.push_back( tracks.at(k)/total_tracks );
	  }
	  
	  for (int a = 0; a < j ; a++)
	  {
	  weighted_mean_track_rate 		+= track_rate.at(a)     * weight.at(a) ; 		    	
	  weighted_mean_event_rate 		+= event_rate.at(a)     * weight.at(a) ; 		
	  total_weight			    	+= weight.at(a) ;
	  }
	  
	  //-----------------------------------------------------------------------------------------------
	  //			Summary Plot for track rate in each Subdetector				 
	  //-----------------------------------------------------------------------------------------------
	  
	  TH1F h1b("h1b","rate summary",2,0,2);
	  h1b.SetFillColor(4);
	  h1b.SetBarWidth(0.3);
	  h1b.SetBarOffset(0.35);
	  h1b.SetStats(0);
	  
	  Bar_Ytitle[0] = weighted_mean_event_rate;     
	  Bar_Ytitle[1] = weighted_mean_track_rate;     
	  
	  for (int i=1; i<=2; i++)
	  {
	  h1b.SetBinContent(i, Bar_Ytitle[i-1]);
	  h1b.GetXaxis()->SetBinLabel(i,Bar_Xtitle[i-1].c_str());
	  }
	  
	  gStyle->SetPaintTextFormat("1.4f");
	  h1b.LabelsOption("d");
	  h1b.SetLabelSize(0.04);
	  h1b.GetYaxis()->SetTitle("Average Rate (Hz)");
	  h1b.Draw("bTEXT");
	  c.SaveAs("Summary_Chart.png");
	  c.Close();
	  gSystem->Exec("mv Summary_Chart.png Rate_Plots");*/

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
      track_rate_TIDM.clear();
      track_rate_TIDM_err.clear();
      track_rate_TIDP.clear();
      track_rate_TIDP_err.clear();
      track_rate_TOB.clear();
      track_rate_TOB_err.clear();
      track_rate_TEC.clear();
      track_rate_TEC_err.clear();
      track_rate_TECM.clear();
      track_rate_TECM_err.clear();
      track_rate_TECP.clear();
      track_rate_TECP_err.clear();
      weight.clear();
      file->Close();
    }
  
  //+++++++++++++++++++++++++++++       Make Directories     +++++++++++++++++++++++++++++++++++++
  gSystem->Exec("mkdir -p Rate_Plots_try");
  
  Canvas[0]->SaveAs("event_rate.png");
  Canvas[1]->SaveAs("track_rate.png");
  Canvas[2]->SaveAs("track_rate_PIX.png");
  Canvas[3]->SaveAs("track_rate_FPIX.png");
  Canvas[4]->SaveAs("track_rate_BPIX.png");
  Canvas[5]->SaveAs("track_rate_TIB.png");
  Canvas[6]->SaveAs("track_rate_TID.png");
  Canvas[7]->SaveAs("track_rate_TIDM.png");
  Canvas[8]->SaveAs("track_rate_TIDP.png");
  Canvas[9]->SaveAs("track_rate_TOB.png");
  Canvas[10]->SaveAs("track_rate_TEC.png");
  Canvas[11]->SaveAs("track_rate_TECP.png");
  Canvas[12]->SaveAs("track_rate_TECM.png");  
  
  gSystem->Exec("mv event_rate.png Rate_Plots_try");
  gSystem->Exec("mv track_rate.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_PIX.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_FPIX.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_BPIX.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIB.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TID.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIDP.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIDM.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TOB.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TEC.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TECP.png Rate_Plots_try");
  gSystem->Exec("mv track_rate_TECM.png Rate_Plots_try");/*

  Canvas[0]->SaveAs("event_rate.C");
  Canvas[1]->SaveAs("track_rate.C");
  Canvas[2]->SaveAs("track_rate_PIX.C");
  Canvas[3]->SaveAs("track_rate_FPIX.C");
  Canvas[4]->SaveAs("track_rate_BPIX.C");
  Canvas[5]->SaveAs("track_rate_TIB.C");
  Canvas[6]->SaveAs("track_rate_TID.C");
  Canvas[7]->SaveAs("track_rate_TIDM.C");
  Canvas[8]->SaveAs("track_rate_TIDP.C");
  Canvas[9]->SaveAs("track_rate_TOB.C");
  Canvas[10]->SaveAs("track_rate_TEC.C");
  Canvas[11]->SaveAs("track_rate_TECP.C");
  Canvas[12]->SaveAs("track_rate_TECM.C");  
  
  gSystem->Exec("mv event_rate.C Rate_Plots_try");
  gSystem->Exec("mv track_rate.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_PIX.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_FPIX.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_BPIX.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIB.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TID.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIDP.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TIDM.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TOB.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TEC.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TECP.C Rate_Plots_try");
  gSystem->Exec("mv track_rate_TECM.C Rate_Plots_try");*/
   
  //TBranch *brnch = tree->GetBranch("number_of_tracks_PIX");
  //int number_of_tracks_PIX;
  //brnch->SetAddress(&number_of_tracks_PIX);
}
