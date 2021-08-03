void PIXEL_timing(const char *fileName, unsigned int runLow = 0, unsigned int runUp = 0) {
  TString InputFile = Form("%s", fileName);
  TFile *file = new TFile(InputFile);

  bool IsFileExist;
  IsFileExist = file->IsZombie();
  if (IsFileExist) {
    cout << endl
         << "====================================================================================================="
         << endl;
    cout << fileName << " is not found. Check the file!" << endl;
    cout << "====================================================================================================="
         << endl
         << endl;
    exit(EXIT_FAILURE);
  }

  TTree *tree;
  tree = (TTree *)file->Get("cosmicRateAnalyzer/Run");

  std::vector<int> v1={343772, 343774};
  std::vector<int> v2={343854, 343860, 343862, 343864, 343866, 343932, 343934, 343936, 343937};
  std::vector<int> v3={343644, 343648, 343650, 343652, 343654, 343659, 343663};
  std::vector<int> v4={343673, 343677, 343680, 343638, 343668, 343670};
  std::vector<int> v5={343642, 343640};
  std::vector<int> v6={343623, 343625, 343627, 343629, 343635};
  std::vector<int> v7={343611, 343613, 343615, 343617, 343619, 343621};
  std::vector<int> v8={343484, 343486, 343488, 343490, 343492, 343494, 343496, 343498, 343501};
  std::vector<int> vec;
  std::vector<int>::iterator it;
  
  FILE *pFile;
  pFile = fopen("tracksInfo.txt", "w");

  double run_time;
  unsigned int runnum;
  int number_of_events;
  int number_of_tracks;
  int number_of_tracks_PIX;
  int number_of_tracks_FPIX;
  int number_of_tracks_BPIX;
  int number_of_tracks_TID;
  int number_of_tracks_TIDM;
  int number_of_tracks_TIDP;
  int number_of_tracks_TIB;
  int number_of_tracks_TEC;
  int number_of_tracks_TECP;
  int number_of_tracks_TECM;
  int number_of_tracks_TOB;

  tree->SetBranchAddress("run_time", &run_time);
  tree->SetBranchAddress("runnum", &runnum);
  tree->SetBranchAddress("number_of_events", &number_of_events);
  tree->SetBranchAddress("number_of_tracks", &number_of_tracks);
  tree->SetBranchAddress("number_of_tracks_PIX", &number_of_tracks_PIX);
  tree->SetBranchAddress("number_of_tracks_FPIX", &number_of_tracks_FPIX);
  tree->SetBranchAddress("number_of_tracks_BPIX", &number_of_tracks_BPIX);
  tree->SetBranchAddress("number_of_tracks_TID", &number_of_tracks_TID);
  tree->SetBranchAddress("number_of_tracks_TIDM", &number_of_tracks_TIDM);
  tree->SetBranchAddress("number_of_tracks_TIDP", &number_of_tracks_TIDP);
  tree->SetBranchAddress("number_of_tracks_TIB", &number_of_tracks_TIB);
  tree->SetBranchAddress("number_of_tracks_TEC", &number_of_tracks_TEC);
  tree->SetBranchAddress("number_of_tracks_TECP", &number_of_tracks_TECP);
  tree->SetBranchAddress("number_of_tracks_TECM", &number_of_tracks_TECM);
  tree->SetBranchAddress("number_of_tracks_TOB", &number_of_tracks_TOB);
  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //		Various Rates Declerations
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  vector<double> event_rate;
  vector<double> event_rate_err;
  vector<double> track_rate;
  vector<double> track_rate_err;
  vector<double> runNumber;
  vector<double> runNumber_err;
  vector<double> track_rate_PIX;
  vector<double> track_rate_PIX_err;
  vector<double> track_rate_FPIX;
  vector<double> track_rate_FPIX_err;
  vector<double> track_rate_BPIX;
  vector<double> track_rate_BPIX_err;
  vector<double> track_rate_TOB;
  vector<double> track_rate_TOB_err;
  vector<double> track_rate_TIB;
  vector<double> track_rate_TIB_err;
  vector<double> track_rate_TID;
  vector<double> track_rate_TID_err;
  vector<double> track_rate_TIDP;
  vector<double> track_rate_TIDP_err;
  vector<double> track_rate_TIDM;
  vector<double> track_rate_TIDM_err;
  vector<double> track_rate_TEC;
  vector<double> track_rate_TEC_err;
  vector<double> track_rate_TECP;
  vector<double> track_rate_TECP_err;
  vector<double> track_rate_TECM;
  vector<double> track_rate_TECM_err;
  vector<double> tracks;
  vector<double> tracks_err;
  vector<double> tracks_bpix;
  vector<double> tracks_fpix;
  vector<double> tracks_pix;
  vector<double> tracks_tec;
  vector<double> weight;

  TMultiGraph mg_event_rate("event rate", ""); 
  TMultiGraph mg_track_rate("track rate", "");
  TMultiGraph mg_track_rate_PIX("track rate PIX", "");
  TMultiGraph mg_track_rate_FPIX("track rate FPIX", "");
  TMultiGraph mg_track_rate_BPIX("track rate BPIX", "");
  TMultiGraph mg_track_rate_TIB("track rate TIB", "");
  TMultiGraph mg_track_rate_TOB("track rate TOB", "");
  TMultiGraph mg_track_rate_TID("track rate TID", "");
  TMultiGraph mg_track_rate_TIDM("track rate TID-", "");
  TMultiGraph mg_track_rate_TIDP("track rate TID+", "");
  TMultiGraph mg_track_rate_TEC("track rate TEC", "");    
  TMultiGraph mg_track_rate_TECM("track rate TEC-", "");
  TMultiGraph mg_track_rate_TECP("track rate TEC+", "");

  TCanvas c("c1", "c1", 604, 82, 856, 836);  // Declare canvas
  gStyle->SetOptStat(0);
  c.Range(298434.4, -0.2989256, 299381.3, 2.010954);
  c.SetFillColor(0);
  c.SetBorderMode(0);
  c.SetBorderSize(2);
  c.SetTickx(1);
  c.SetTicky(1);
  c.SetGrid();
  c.SetLeftMargin(0.1883886);
  c.SetRightMargin(0.03909953);
  c.SetTopMargin(0.0875817);
  c.SetBottomMargin(0.1294118);
  c.SetFrameLineWidth(3);
  c.SetFrameBorderMode(0);
  
  //============  Text  =============//
  TLatex top_right_Title = TLatex();
  top_right_Title.SetTextFont(42);
  top_right_Title.SetTextSize(0.03717);
  
  TLatex detector = TLatex();
  detector.SetTextFont(62);
  detector.SetTextSize(0.047);
  
  int j = 0;
  int nTotalEvents = 0, nTotalTracks = 0, nRuns = 0;
  
  gSystem->Exec("mkdir -p Rate_Plots");
  
  for(int i=0;i<8;i++) // Loop over vectors
    {
      if(i==0) vec=v1;
      else if(i==1) vec=v2;
      else if(i==2) vec=v3;
      else if(i==3) vec=v4;
      else if(i==4) vec=v5;
      else if(i==5) vec=v6;
      else if(i==6) vec=v7;
      else if(i==7) vec=v8;

      //DEFILE COLORS FOR EACH VECTOR FOR PLOTTING
      Int_t ci;
      if(i==0) { ci=TColor::GetColor("#f5601b"); }
      else if(i==1) { ci=TColor::GetColor("#196F3D"); }
      else if(i==2) { ci=TColor::GetColor("#e317ba"); }
      else if(i==3) { ci=TColor::GetColor("#0BF9F4"); }
      else if(i==4) { ci=TColor::GetColor("#2CF90B"); }
      else if(i==5) { ci=TColor::GetColor("#F90B28"); }
      else if(i==6) { ci=TColor::GetColor("#1B38F5"); }
      else if(i==7) { ci=TColor::GetColor("#FFC300"); }
      
      Long64_t n = tree->GetEntriesFast();
      std::cout << "Total Runs in this file: " << n << endl;
      for (Long64_t jentry = 0; jentry < n; jentry++)  // Loop over Runs
	{
	  tree->GetEntry(jentry);
	  if (run_time == 0 || run_time < 0)
	    continue;
	  
	  if (runLow != 0 && runUp != 0) {
	    if (runnum < runLow)
	      continue;
	    if (runnum > runUp)
	      break;
	  }

	  int key=runnum;
	  it = std::find(vec.begin(), vec.end(), key);
	  if (it != vec.end())	// element or runnum found 
	    {
	      std::cout << "Run No " << key <<" found at in vector "<<i<<" at position" << it - vec.begin() <<" (counting from zero) in vector"<< i<<std::endl;
	      event_rate.push_back(number_of_events / run_time);
	      runNumber.push_back(runnum);
	      track_rate.push_back(number_of_tracks / run_time);
	      track_rate_PIX.push_back(number_of_tracks_PIX / run_time);
	      track_rate_FPIX.push_back(number_of_tracks_FPIX / run_time);
	      track_rate_BPIX.push_back(number_of_tracks_BPIX / run_time);
	      track_rate_TOB.push_back(number_of_tracks_TOB / run_time);
	      track_rate_TIB.push_back(number_of_tracks_TIB / run_time);
	      track_rate_TID.push_back(number_of_tracks_TID / run_time);
	      track_rate_TIDP.push_back(number_of_tracks_TIDP / run_time);
	      track_rate_TIDM.push_back(number_of_tracks_TIDM / run_time);
	      track_rate_TEC.push_back(number_of_tracks_TEC / run_time);
	      track_rate_TECP.push_back(number_of_tracks_TECP / run_time);
	      track_rate_TECM.push_back(number_of_tracks_TECM / run_time);
	      tracks.push_back(number_of_tracks);

	      event_rate_err.push_back(sqrt(float(number_of_events)) / run_time);
	      track_rate_err.push_back(sqrt(float(number_of_tracks)) / run_time);
	      track_rate_PIX_err.push_back(sqrt(float(number_of_tracks_PIX)) / run_time);
	      track_rate_FPIX_err.push_back(sqrt(float(number_of_tracks_FPIX)) / run_time);
	      track_rate_BPIX_err.push_back(sqrt(float(number_of_tracks_BPIX)) / run_time);
	      track_rate_TOB_err.push_back(sqrt(float(number_of_tracks_TOB)) / run_time);
	      track_rate_TIB_err.push_back(sqrt(float(number_of_tracks_TIB)) / run_time);
	      track_rate_TID_err.push_back(sqrt(float(number_of_tracks_TID)) / run_time);
	      track_rate_TIDP_err.push_back(sqrt(float(number_of_tracks_TIDP)) / run_time);
	      track_rate_TIDM_err.push_back(sqrt(float(number_of_tracks_TIDM)) / run_time);
	      track_rate_TEC_err.push_back(sqrt(float(number_of_tracks_TEC)) / run_time);
	      track_rate_TECP_err.push_back(sqrt(float(number_of_tracks_TECP)) / run_time);
	      track_rate_TECM_err.push_back(sqrt(float(number_of_tracks_TECM)) / run_time);
	      
	      runNumber_err.push_back(0);  
	      std::cout<<"Run No. : "<<runnum<<" : "<<"Run time : "<<run_time<<std::endl;
	      j++; nRuns++;
	    }
	  else {
	    continue;
	  }
	  
	}// Loop over runs
      
      //----------------------------------------------------------------------------------------------
      
      //============  Declaring TVectors for TGraphs  =============//
      TVectorD event_rate_VecD;
      TVectorD event_rate_err_VecD;
      TVectorD track_rate_VecD;
      TVectorD track_rate_err_VecD;
      TVectorD runNumber_VecD;
      TVectorD runNumber_err_VecD;
      TVectorD track_rate_PIX_VecD;
      TVectorD track_rate_PIX_err_VecD;
      TVectorD track_rate_FPIX_VecD;
      TVectorD track_rate_FPIX_err_VecD;
      TVectorD track_rate_BPIX_VecD;
      TVectorD track_rate_BPIX_err_VecD;
      TVectorD track_rate_TOB_VecD;
      TVectorD track_rate_TOB_err_VecD;
      TVectorD track_rate_TIB_VecD;
      TVectorD track_rate_TIB_err_VecD;
      TVectorD track_rate_TID_VecD;
      TVectorD track_rate_TID_err_VecD;
      TVectorD track_rate_TIDP_VecD;
      TVectorD track_rate_TIDP_err_VecD;
      TVectorD track_rate_TIDM_VecD;
      TVectorD track_rate_TIDM_err_VecD;
      TVectorD track_rate_TEC_VecD;
      TVectorD track_rate_TEC_err_VecD;
      TVectorD track_rate_TECP_VecD;
      TVectorD track_rate_TECP_err_VecD;
      TVectorD track_rate_TECM_VecD;
      TVectorD track_rate_TECM_err_VecD;
      
      runNumber_VecD.Use(runNumber.size(), &(runNumber[0]));
      runNumber_err_VecD.Use(runNumber_err.size(), &(runNumber_err[0]));
      event_rate_VecD.Use(event_rate.size(), &(event_rate[0]));
      event_rate_err_VecD.Use(event_rate_err.size(), &(event_rate_err[0]));
      
      track_rate_VecD.Use(track_rate.size(), &(track_rate[0]));
      track_rate_err_VecD.Use(track_rate_err.size(), &(track_rate_err[0]));
      
      track_rate_PIX_VecD.Use(track_rate_PIX.size(), &(track_rate_PIX[0]));
      track_rate_PIX_err_VecD.Use(track_rate_PIX_err.size(), &(track_rate_PIX_err[0]));
      track_rate_FPIX_VecD.Use(track_rate_FPIX.size(), &(track_rate_FPIX[0]));
      track_rate_FPIX_err_VecD.Use(track_rate_FPIX_err.size(), &(track_rate_FPIX_err[0]));
      track_rate_BPIX_VecD.Use(track_rate_BPIX.size(), &(track_rate_BPIX[0]));
      track_rate_BPIX_err_VecD.Use(track_rate_BPIX_err.size(), &(track_rate_BPIX_err[0]));
      track_rate_TOB_VecD.Use(track_rate_TOB.size(), &(track_rate_TOB[0]));
      track_rate_TOB_err_VecD.Use(track_rate_TOB_err.size(), &(track_rate_TOB_err[0]));
      track_rate_TIB_VecD.Use(track_rate_TIB.size(), &(track_rate_TIB[0]));
      track_rate_TIB_err_VecD.Use(track_rate_TIB_err.size(), &(track_rate_TIB_err[0]));
      track_rate_TID_VecD.Use(track_rate_TID.size(), &(track_rate_TID[0]));
      track_rate_TID_err_VecD.Use(track_rate_TID_err.size(), &(track_rate_TID_err[0]));
      track_rate_TIDP_VecD.Use(track_rate_TIDP.size(), &(track_rate_TIDP[0]));
      track_rate_TIDP_err_VecD.Use(track_rate_TIDP_err.size(), &(track_rate_TIDP_err[0]));
      track_rate_TIDM_VecD.Use(track_rate_TIDM.size(), &(track_rate_TIDM[0]));
      track_rate_TIDM_err_VecD.Use(track_rate_TIDM_err.size(), &(track_rate_TIDM_err[0]));
      track_rate_TEC_VecD.Use(track_rate_TEC.size(), &(track_rate_TEC[0]));
      track_rate_TEC_err_VecD.Use(track_rate_TEC_err.size(), &(track_rate_TEC_err[0]));
      track_rate_TECP_VecD.Use(track_rate_TECP.size(), &(track_rate_TECP[0]));
      track_rate_TECP_err_VecD.Use(track_rate_TECP_err.size(), &(track_rate_TECP_err[0]));
      track_rate_TECM_VecD.Use(track_rate_TECM.size(), &(track_rate_TECM[0]));
      track_rate_TECM_err_VecD.Use(track_rate_TECM_err.size(), &(track_rate_TECM_err[0]));
      
      //+++++++++++++++++++++++++++++  Overall event event rate  +++++++++++++++++++++++++++++++++++++    
      TGraphErrors *gr_event_rate = new TGraphErrors(runNumber_VecD, event_rate_VecD, runNumber_err_VecD, event_rate_err_VecD);
      gr_event_rate->SetMarkerStyle(20);
      gr_event_rate->SetMarkerSize(1.8);
      gr_event_rate->SetMarkerColor(ci);
      gr_event_rate->GetXaxis()->SetTitle("Run Number");
      gr_event_rate->GetXaxis()->SetLabelSize(0.04);
      gr_event_rate->GetXaxis()->SetNoExponent();
      gr_event_rate->GetXaxis()->SetNdivisions(5);
      gr_event_rate->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_event_rate->GetXaxis()->SetTitleSize(0.05);
      gr_event_rate->GetYaxis()->SetLabelSize(0.05);
      gr_event_rate->GetYaxis()->SetTitleSize(0.05);
      gr_event_rate->SetTitle("");      

      TGraphErrors *gr_track_rate = new TGraphErrors(runNumber_VecD, track_rate_VecD, runNumber_err_VecD, track_rate_err_VecD);
      gr_track_rate->SetMarkerStyle(20);
      gr_track_rate->SetMarkerSize(1.8);
      gr_track_rate->SetMarkerColor(ci);
      gr_track_rate->GetXaxis()->SetTitle("Run Number");
      gr_track_rate->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate->GetXaxis()->SetNoExponent();
      gr_track_rate->GetXaxis()->SetNdivisions(5);
      gr_track_rate->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate->SetTitle("");
      
      TGraphErrors *gr_track_rate_PIX = new TGraphErrors(runNumber_VecD, track_rate_PIX_VecD, runNumber_err_VecD, track_rate_PIX_err_VecD);
      gr_track_rate_PIX->SetMarkerStyle(20);
      gr_track_rate_PIX->SetMarkerSize(1.8);
      gr_track_rate_PIX->SetMarkerColor(ci);
      gr_track_rate_PIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_PIX->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_PIX->GetXaxis()->SetNoExponent();
      gr_track_rate_PIX->GetXaxis()->SetNdivisions(5);
      gr_track_rate_PIX->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_PIX->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_PIX->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_PIX->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_PIX->SetTitle("");
      
      TGraphErrors *gr_track_rate_FPIX = new TGraphErrors(runNumber_VecD, track_rate_FPIX_VecD, runNumber_err_VecD, track_rate_FPIX_err_VecD);
      gr_track_rate_FPIX->SetMarkerStyle(20);
      gr_track_rate_FPIX->SetMarkerSize(1.8);
      gr_track_rate_FPIX->SetMarkerColor(ci);
      gr_track_rate_FPIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_FPIX->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_FPIX->GetXaxis()->SetNoExponent();
      gr_track_rate_FPIX->GetXaxis()->SetNdivisions(5);
      gr_track_rate_FPIX->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_FPIX->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_FPIX->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_FPIX->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_FPIX->SetTitle("");
      
      TGraphErrors *gr_track_rate_BPIX = new TGraphErrors(runNumber_VecD, track_rate_BPIX_VecD, runNumber_err_VecD, track_rate_BPIX_err_VecD);
      gr_track_rate_BPIX->SetMarkerStyle(20);
      gr_track_rate_BPIX->SetMarkerSize(1.8);
      gr_track_rate_BPIX->SetMarkerColor(ci);
      gr_track_rate_BPIX->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_BPIX->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_BPIX->GetXaxis()->SetNoExponent();
      gr_track_rate_BPIX->GetXaxis()->SetNdivisions(5);
      gr_track_rate_BPIX->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_BPIX->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_BPIX->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_BPIX->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_BPIX->SetTitle("");
      
      TGraphErrors *gr_track_rate_TOB = new TGraphErrors(runNumber_VecD, track_rate_TOB_VecD, runNumber_err_VecD, track_rate_TOB_err_VecD);
      gr_track_rate_TOB->SetMarkerStyle(20);
      gr_track_rate_TOB->SetMarkerSize(1.8);
      gr_track_rate_TOB->SetMarkerColor(ci);
      gr_track_rate_TOB->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TOB->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TOB->GetXaxis()->SetNoExponent();
      gr_track_rate_TOB->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TOB->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TOB->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TOB->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TOB->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TOB->SetTitle("");
      
      TGraphErrors *gr_track_rate_TIB = new TGraphErrors(runNumber_VecD, track_rate_TIB_VecD, runNumber_err_VecD, track_rate_TIB_err_VecD);
      gr_track_rate_TIB->SetMarkerStyle(20);
      gr_track_rate_TIB->SetMarkerSize(1.8);
      gr_track_rate_TIB->SetMarkerColor(ci);
      gr_track_rate_TIB->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIB->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TIB->GetXaxis()->SetNoExponent();
      gr_track_rate_TIB->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TIB->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TIB->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TIB->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TIB->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TIB->SetTitle("");
      
      TGraphErrors *gr_track_rate_TIDM = new TGraphErrors(runNumber_VecD, track_rate_TIDM_VecD, runNumber_err_VecD, track_rate_TIDM_err_VecD);
      gr_track_rate_TIDM->SetMarkerStyle(20);
      gr_track_rate_TIDM->SetMarkerSize(1.8);
      gr_track_rate_TIDM->SetMarkerColor(ci);
      gr_track_rate_TIDM->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIDM->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TIDM->GetXaxis()->SetNoExponent();
      gr_track_rate_TIDM->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TIDM->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TIDM->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TIDM->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TIDM->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TIDM->SetTitle("");
      
      TGraphErrors *gr_track_rate_TIDP = new TGraphErrors(runNumber_VecD, track_rate_TIDP_VecD, runNumber_err_VecD, track_rate_TIDP_err_VecD);
      gr_track_rate_TIDP->SetMarkerStyle(20);
      gr_track_rate_TIDP->SetMarkerSize(1.8);
      gr_track_rate_TIDP->SetMarkerColor(ci);
      gr_track_rate_TIDP->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TIDP->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TIDP->GetXaxis()->SetNoExponent();
      gr_track_rate_TIDP->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TIDP->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TIDP->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TIDP->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TIDP->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TIDP->SetTitle("");
      
      TGraphErrors *gr_track_rate_TID = new TGraphErrors(runNumber_VecD, track_rate_TID_VecD, runNumber_err_VecD, track_rate_TID_err_VecD);
      gr_track_rate_TID->SetMarkerStyle(20);
      gr_track_rate_TID->SetMarkerSize(1.8);
      gr_track_rate_TID->SetMarkerColor(ci);
      gr_track_rate_TID->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TID->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TID->GetXaxis()->SetNoExponent();
      gr_track_rate_TID->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TID->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TID->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TID->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TID->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TID->SetTitle("");

      TGraphErrors *gr_track_rate_TEC = new TGraphErrors(runNumber_VecD, track_rate_TEC_VecD, runNumber_err_VecD, track_rate_TEC_err_VecD);
      gr_track_rate_TEC->SetMarkerStyle(20);
      gr_track_rate_TEC->SetMarkerSize(1.8);
      gr_track_rate_TEC->SetMarkerColor(ci);
      gr_track_rate_TEC->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TEC->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TEC->GetXaxis()->SetNoExponent();
      gr_track_rate_TEC->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TEC->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TEC->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TEC->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TEC->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TEC->SetTitle("");
      
      TGraphErrors *gr_track_rate_TECM = new TGraphErrors(runNumber_VecD, track_rate_TECM_VecD, runNumber_err_VecD, track_rate_TECM_err_VecD);
      gr_track_rate_TECM->SetMarkerStyle(20);
      gr_track_rate_TECM->SetMarkerSize(1.8);
      gr_track_rate_TECM->SetMarkerColor(ci);
      gr_track_rate_TECM->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TECM->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TECM->GetXaxis()->SetNoExponent();
      gr_track_rate_TECM->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TECM->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TECM->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TECM->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TECM->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TECM->SetTitle("");
      
      TGraphErrors *gr_track_rate_TECP = new TGraphErrors(runNumber_VecD, track_rate_TECP_VecD, runNumber_err_VecD, track_rate_TECP_err_VecD);
      gr_track_rate_TECP->SetMarkerStyle(20);
      gr_track_rate_TECP->SetMarkerSize(1.8);
      gr_track_rate_TECP->SetMarkerColor(ci);
      gr_track_rate_TECP->GetXaxis()->SetTitle("Run Number");
      gr_track_rate_TECP->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate_TECP->GetXaxis()->SetNoExponent();
      gr_track_rate_TECP->GetXaxis()->SetNdivisions(5);
      gr_track_rate_TECP->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate_TECP->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate_TECP->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate_TECP->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate_TECP->SetTitle("");
      
      // Add the graphs to MultiGraphs
      mg_event_rate.Add(gr_event_rate);
      mg_track_rate.Add(gr_track_rate);
      mg_track_rate_PIX.Add(gr_track_rate_PIX);
      mg_track_rate_FPIX.Add(gr_track_rate_FPIX);
      mg_track_rate_BPIX.Add(gr_track_rate_BPIX);
      mg_track_rate_TIB.Add(gr_track_rate_TIB);
      mg_track_rate_TID.Add(gr_track_rate_TID);
      mg_track_rate_TIDM.Add(gr_track_rate_TIDM);
      mg_track_rate_TIDP.Add(gr_track_rate_TIDP);
      mg_track_rate_TOB.Add(gr_track_rate_TOB);
      mg_track_rate_TEC.Add(gr_track_rate_TEC);
      mg_track_rate_TECP.Add(gr_track_rate_TECP);
      mg_track_rate_TECM.Add(gr_track_rate_TECM);
  
      //Clear TVectors
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

      event_rate_VecD.Clear();
      event_rate_err_VecD.Clear();
      track_rate_VecD.Clear();
      track_rate_err_VecD.Clear();
      runNumber_VecD.Clear();
      runNumber_err_VecD.Clear();
      track_rate_PIX_VecD.Clear();
      track_rate_PIX_err_VecD.Clear();
      track_rate_FPIX_VecD.Clear();
      track_rate_FPIX_err_VecD.Clear();
      track_rate_BPIX_VecD.Clear();
      track_rate_BPIX_err_VecD.Clear();
      track_rate_TOB_VecD.Clear();
      track_rate_TOB_err_VecD.Clear();
      track_rate_TIB_VecD.Clear();
      track_rate_TIB_err_VecD.Clear();
      track_rate_TID_VecD.Clear();
      track_rate_TID_err_VecD.Clear();
      track_rate_TIDP_VecD.Clear();
      track_rate_TIDP_err_VecD.Clear();
      track_rate_TIDM_VecD.Clear();
      track_rate_TIDM_err_VecD.Clear();
      track_rate_TEC_VecD.Clear();
      track_rate_TEC_err_VecD.Clear();
      track_rate_TECP_VecD.Clear();
      track_rate_TECP_err_VecD.Clear();
      track_rate_TECM_VecD.Clear();
      track_rate_TECM_err_VecD.Clear();
      
    }  //Loop over vectors
  
  //Plot multigraphs

  //------------------------------------------------ EVENT RATE -----------------------------------------------
  mg_event_rate.Draw("AP");
  mg_event_rate.GetXaxis()->SetTitle("Run Number");
  mg_event_rate.GetXaxis()->SetLabelSize(0.04);
  mg_event_rate.GetXaxis()->SetNoExponent();
  mg_event_rate.GetXaxis()->SetNdivisions(5);
  mg_event_rate.GetYaxis()->SetTitle("Event Rate (Hz)");
  mg_event_rate.GetXaxis()->SetTitleSize(0.05);
  mg_event_rate.GetYaxis()->SetLabelSize(0.05);
  mg_event_rate.GetYaxis()->SetTitleSize(0.05);
  mg_event_rate.SetTitle("");
  //mg_event_rate.GetYaxis()->SetRangeUser(0,7);
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "Event Rate");
  c.SetGrid();
  c.SaveAs("event_rate.png");
  c.SaveAs("event_rate.pdf");
  c.SaveAs("event_rate.C");
  c.Clear();
  gSystem->Exec("mv event_rate.png Rate_Plots");
  gSystem->Exec("mv event_rate.pdf Rate_Plots");
  gSystem->Exec("mv event_rate.C Rate_Plots");
  
  //------------------------------------------------ Total TRACK RATE ----------------------------------------------- 
  mg_track_rate.Draw("AP");
  mg_track_rate.GetXaxis()->SetTitle("Run Number");
  mg_track_rate.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate.GetXaxis()->SetNoExponent();
  mg_track_rate.GetXaxis()->SetNdivisions(5);
  mg_track_rate.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "Track Rate");
  c.SetGrid();
  c.SaveAs("track_rate.png");
  c.SaveAs("track_rate.pdf");
  c.SaveAs("track_rate.C");
  c.Clear();
  gSystem->Exec("mv track_rate.png Rate_Plots");
  gSystem->Exec("mv track_rate.pdf Rate_Plots");
  gSystem->Exec("mv track_rate.C Rate_Plots");
  
  //--------------------------------------------------- PIX TRACK RATE --------------------------------------------
  mg_track_rate_PIX.Draw("AP");
  mg_track_rate_PIX.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_PIX.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_PIX.GetXaxis()->SetNoExponent();
  mg_track_rate_PIX.GetXaxis()->SetNdivisions(5);
  mg_track_rate_PIX.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_PIX.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_PIX.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_PIX.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_PIX.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "PIXEL");
  c.SetGrid();
  c.SaveAs("pixel_track_rate.png");
  c.SaveAs("pixel_track_rate.pdf");
  c.SaveAs("pixel_track_rate.C");
  c.Clear();
  gSystem->Exec("mv pixel_track_rate.png Rate_Plots");
  gSystem->Exec("mv pixel_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv pixel_track_rate.C Rate_Plots");

  //----------------------------------------------------- FPIX TRACK RATE ------------------------------------------
  mg_track_rate_FPIX.Draw("AP");
  mg_track_rate_FPIX.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_FPIX.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_FPIX.GetXaxis()->SetNoExponent();
  mg_track_rate_FPIX.GetXaxis()->SetNdivisions(5);
  mg_track_rate_FPIX.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_FPIX.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_FPIX.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_FPIX.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_FPIX.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX");
  c.SetGrid();
  c.SaveAs("fpix_track_rate.png");
  c.SaveAs("fpix_track_rate.pdf");
  c.SaveAs("fpix_track_rate.C");
  c.Clear();
  gSystem->Exec("mv fpix_track_rate.png Rate_Plots");
  gSystem->Exec("mv fpix_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv fpix_track_rate.C Rate_Plots");
  
  //--------------------------------------------------- BPIX TRACK RATE --------------------------------------------
  mg_track_rate_BPIX.Draw("AP");
  mg_track_rate_BPIX.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_BPIX.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_BPIX.GetXaxis()->SetNoExponent();
  mg_track_rate_BPIX.GetXaxis()->SetNdivisions(5);
  mg_track_rate_BPIX.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_BPIX.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_BPIX.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_BPIX.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_BPIX.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "BPIX");
  c.SetGrid();
  c.SaveAs("bpix_track_rate.png");
  c.SaveAs("bpix_track_rate.pdf");
  c.SaveAs("bpix_track_rate.C");
  c.Clear();
  gSystem->Exec("mv bpix_track_rate.png Rate_Plots");
  gSystem->Exec("mv bpix_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv bpix_track_rate.C Rate_Plots");
  
  //---------------------------------------------------- TIB TRACK RATE -------------------------------------------
  mg_track_rate_TIB.Draw("AP");
  mg_track_rate_TIB.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TIB.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TIB.GetXaxis()->SetNoExponent();
  mg_track_rate_TIB.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TIB.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TIB.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TIB.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TIB.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TIB.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TIB");
  c.SetGrid();
  c.SaveAs("tib_track_rate.png");
  c.SaveAs("tib_track_rate.pdf");
  c.SaveAs("tib_track_rate.C");
  c.Clear();
  gSystem->Exec("mv tib_track_rate.png Rate_Plots");
  gSystem->Exec("mv tib_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv tib_track_rate.C Rate_Plots");
  
  //------------------------------------------------------ TID TRACK RATE -----------------------------------------
  mg_track_rate_TID.Draw("AP");
  mg_track_rate_TID.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TID.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TID.GetXaxis()->SetNoExponent();
  mg_track_rate_TID.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TID.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TID.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TID.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TID.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TID.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TID");
  c.SetGrid();
  c.SaveAs("tid_track_rate.png");
  c.SaveAs("tid_track_rate.pdf");
  c.SaveAs("tid_track_rate.C");
  c.Clear();
  gSystem->Exec("mv tid_track_rate.png Rate_Plots");
  gSystem->Exec("mv tid_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv tid_track_rate.C Rate_Plots");
  
  //------------------------------------------------------- TID- TRACK RATE ----------------------------------------
  mg_track_rate_TIDM.Draw("AP");
  mg_track_rate_TIDM.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TIDM.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TIDM.GetXaxis()->SetNoExponent();
  mg_track_rate_TIDM.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TIDM.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TIDM.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TIDM.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TIDM.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TIDM.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TID-");
  c.SetGrid();
  c.SaveAs("TIDM_track_rate.png");
  c.SaveAs("TIDM_track_rate.pdf");
  c.SaveAs("TIDM_track_rate.C");
  c.Clear();
  gSystem->Exec("mv TIDM_track_rate.png Rate_Plots");
  gSystem->Exec("mv TIDM_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv TIDM_track_rate.C Rate_Plots");
    
  //-------------------------------------------------------- TID+ TRACK RATE ---------------------------------------
  mg_track_rate_TIDP.Draw("AP");
  mg_track_rate_TIDP.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TIDP.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TIDP.GetXaxis()->SetNoExponent();
  mg_track_rate_TIDP.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TIDP.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TIDP.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TIDP.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TIDP.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TIDP.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TID+");
  c.SetGrid();
  c.SaveAs("TIDP_track_rate.png");
  c.SaveAs("TIDP_track_rate.pdf");
  c.SaveAs("TIDP_track_rate.C");
  c.Clear();
  gSystem->Exec("mv TIDP_track_rate.png Rate_Plots");
  gSystem->Exec("mv TIDP_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv TIDP_track_rate.C Rate_Plots");
  
  //-------------------------------------------------------- TOB TRACK RATE ---------------------------------------
  mg_track_rate_TOB.Draw("AP");
  mg_track_rate_TOB.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TOB.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TOB.GetXaxis()->SetNoExponent();
  mg_track_rate_TOB.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TOB.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TOB.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TOB.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TOB.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TOB.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TOB");
  c.SetGrid();
  c.SaveAs("tob_track_rate.png");
  c.SaveAs("tob_track_rate.pdf");
  c.SaveAs("tob_track_rate.C");
  c.Clear();
  gSystem->Exec("mv tob_track_rate.png Rate_Plots");
  gSystem->Exec("mv tob_track_rate.C Rate_Plots");
  gSystem->Exec("mv tob_track_rate.pdf Rate_Plots");
  
  //------------------------------------------------------ TEC TRACK RATE -----------------------------------------
  mg_track_rate_TEC.Draw("AP");
  mg_track_rate_TEC.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TEC.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TEC.GetXaxis()->SetNoExponent();
  mg_track_rate_TEC.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TEC.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TEC.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TEC.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TEC.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TEC.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TEC");
  c.SetGrid();
  c.SaveAs("tec_track_rate.png");
  c.SaveAs("tec_track_rate.pdf");
  c.SaveAs("tec_track_rate.C");
  c.Clear();
  gSystem->Exec("mv tec_track_rate.png Rate_Plots");
  gSystem->Exec("mv tec_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv tec_track_rate.C Rate_Plots");
  
  //-------------------------------------------------------- TEC + TRACK RATE ---------------------------------------
  mg_track_rate_TECP.Draw("AP");
  mg_track_rate_TECP.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TECP.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TECP.GetXaxis()->SetNoExponent();
  mg_track_rate_TECP.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TECP.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TECP.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TECP.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TECP.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TECP.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TEC+");
  c.SetGrid();
  c.SaveAs("TECP_track_rate.png");
  c.SaveAs("TECP_track_rate.pdf");
  c.SaveAs("TECP_track_rate.C");
  c.Clear();
  gSystem->Exec("mv TECP_track_rate.png Rate_Plots");
  gSystem->Exec("mv TECP_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv TECP_track_rate.C Rate_Plots");
  
  //------------------------------------------------------- TEC - TRACK RATE ----------------------------------------
  mg_track_rate_TECM.Draw("AP");
  mg_track_rate_TECM.GetXaxis()->SetTitle("Run Number");
  mg_track_rate_TECM.GetXaxis()->SetLabelSize(0.04);
  mg_track_rate_TECM.GetXaxis()->SetNoExponent();
  mg_track_rate_TECM.GetXaxis()->SetNdivisions(5);
  mg_track_rate_TECM.GetYaxis()->SetTitle("Track Rate (Hz)");
  mg_track_rate_TECM.GetXaxis()->SetTitleSize(0.05);
  mg_track_rate_TECM.GetYaxis()->SetLabelSize(0.05);
  mg_track_rate_TECM.GetYaxis()->SetTitleSize(0.05);
  mg_track_rate_TECM.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "TEC-");
  c.SetGrid();
  c.SaveAs("TECM_track_rate.png");
  c.SaveAs("TECM_track_rate.pdf");
  c.SaveAs("TECM_track_rate.C");
  c.Clear();
  gSystem->Exec("mv TECM_track_rate.png Rate_Plots");
  gSystem->Exec("mv TECM_track_rate.pdf Rate_Plots");
  gSystem->Exec("mv TECM_track_rate.C Rate_Plots");
  
  //-----------------------------------------------------------------------------------------------

  c.Close();
}
