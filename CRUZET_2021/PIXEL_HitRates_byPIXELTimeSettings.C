void PIXEL_HitRates_byPIXELTimeSettings(const char *fileName, unsigned int runLow = 0, unsigned int runUp = 0){

  TString InputFile = Form("%s", fileName);
  TFile *file = new TFile(InputFile);
  
  bool IsFileExist;
  IsFileExist = file->IsZombie();
  if (IsFileExist) {
    cout << endl
         << "====================================================================================================="
         << endl;
    cout << fileName << " not found. Check the file!" << endl;
    cout << "====================================================================================================="
         << endl
         << endl;
    exit(EXIT_FAILURE);
  }
  
  TTree *tree = (TTree *)file->Get("cosmicRateAnalyzer/Run");
  
  std::vector<int> v1={343772, 343774};
  std::vector<int> v2={343854, 343860, 343862, 343864, 343866, 343932, 343934, 343936, 343937};
  std::vector<int> v3={343644, 343648, 343650, 343652, 343654, 343659, 343663};
  std::vector<int> v4={343673, 343677, 343680, 343638, 343668, 343670};
  std::vector<int> v5={343642, 343640, 343638};
  std::vector<int> v6={343623, 343625, 343627, 343629, 343635};
  std::vector<int> v7={343611, 343613, 343615, 343617, 343619, 343621};
  std::vector<int> v8={343484, 343486, 343488, 343490, 343492, 343494, 343496, 343498, 343501};
  std::vector<int> v9={344068};
  std::vector<int> v10={344067, 344066, 344065, 344064, 344063, 344062, 344058};
  std::vector<int> vec;
  std::vector<int>::iterator it;

  double run_time;
  unsigned int runnum;
  int number_of_events;
  int number_of_tracks;
  int number_of_hits_Total;
  int number_of_hits_PIX;
  int number_of_hits_BPIX;
  int number_of_hits_BPIX_layer1;
  int number_of_hits_BPIX_layer2;
  int number_of_hits_BPIX_layer3;
  int number_of_hits_BPIX_layer4;
  int number_of_hits_FPIX;
  int number_of_hits_FPIX_disk1;
  int number_of_hits_FPIX_disk2;
  int number_of_hits_FPIX_disk3;
  int number_of_hits_FPIX_disk1_plus;
  int number_of_hits_FPIX_disk1_minus;
  int number_of_hits_FPIX_disk2_plus;
  int number_of_hits_FPIX_disk2_minus;
  int number_of_hits_FPIX_disk3_plus;
  int number_of_hits_FPIX_disk3_minus;

  tree->SetBranchAddress("run_time", &run_time);
  tree->SetBranchAddress("runnum", &runnum);
  tree->SetBranchAddress("number_of_events", &number_of_events);
  tree->SetBranchAddress("number_of_tracks", &number_of_tracks);
  tree->SetBranchAddress("number_of_hits_Total", &number_of_hits_Total);
  tree->SetBranchAddress("number_of_hits_PIX", &number_of_hits_PIX);
  tree->SetBranchAddress("number_of_hits_BPIX", &number_of_hits_BPIX);
  tree->SetBranchAddress("number_of_hits_BPIX_layer1", &number_of_hits_BPIX_layer1);
  tree->SetBranchAddress("number_of_hits_BPIX_layer2", &number_of_hits_BPIX_layer2);
  tree->SetBranchAddress("number_of_hits_BPIX_layer3", &number_of_hits_BPIX_layer3);
  tree->SetBranchAddress("number_of_hits_BPIX_layer4", &number_of_hits_BPIX_layer4);
  tree->SetBranchAddress("number_of_hits_FPIX", &number_of_hits_FPIX);
  tree->SetBranchAddress("number_of_hits_FPIX_disk1", &number_of_hits_FPIX_disk1);
  tree->SetBranchAddress("number_of_hits_FPIX_disk2", &number_of_hits_FPIX_disk2);
  tree->SetBranchAddress("number_of_hits_FPIX_disk3", &number_of_hits_FPIX_disk3);
  tree->SetBranchAddress("number_of_hits_FPIX_disk1_plus", &number_of_hits_FPIX_disk1_plus);
  tree->SetBranchAddress("number_of_hits_FPIX_disk1_minus", &number_of_hits_FPIX_disk1_minus);
  tree->SetBranchAddress("number_of_hits_FPIX_disk2_plus", &number_of_hits_FPIX_disk2_plus);
  tree->SetBranchAddress("number_of_hits_FPIX_disk2_minus", &number_of_hits_FPIX_disk2_minus);
  tree->SetBranchAddress("number_of_hits_FPIX_disk3_plus", &number_of_hits_FPIX_disk3_plus);
  tree->SetBranchAddress("number_of_hits_FPIX_disk3_minus", &number_of_hits_FPIX_disk3_minus);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //		Various Rates Declerations
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  vector<double> events;
  vector<double> event_rate;
  vector<double> event_rate_err;
  vector<double> track_rate;
  vector<double> track_rate_err;
  vector<double> runNumber;
  vector<double> runNumber_err;
  vector<double> tracks;
  vector<double> tracks_err;
  vector<double> weight;

  vector<double> hits;
  vector<double> hit_rate_Total;
  vector<double> hit_rate_Total_err;
  vector<double> hit_rate_PIX;
  vector<double> hit_rate_PIX_err;
  vector<double> hit_rate_BPIX;
  vector<double> hit_rate_BPIX_err;
  vector<double> hit_rate_BPIX_layer1;
  vector<double> hit_rate_BPIX_layer1_err;
  vector<double> hit_rate_BPIX_layer2;
  vector<double> hit_rate_BPIX_layer2_err;
  vector<double> hit_rate_BPIX_layer3;
  vector<double> hit_rate_BPIX_layer3_err;
  vector<double> hit_rate_BPIX_layer4;
  vector<double> hit_rate_BPIX_layer4_err;
  vector<double> hit_rate_FPIX;
  vector<double> hit_rate_FPIX_err;
  vector<double> hit_rate_FPIX_disk1;
  vector<double> hit_rate_FPIX_disk1_err;
  vector<double> hit_rate_FPIX_disk2;
  vector<double> hit_rate_FPIX_disk2_err;
  vector<double> hit_rate_FPIX_disk3;
  vector<double> hit_rate_FPIX_disk3_err;
  vector<double> hit_rate_FPIX_disk1_plus;
  vector<double> hit_rate_FPIX_disk1_plus_err;
  vector<double> hit_rate_FPIX_disk1_minus;
  vector<double> hit_rate_FPIX_disk1_minus_err;
  vector<double> hit_rate_FPIX_disk2_plus;
  vector<double> hit_rate_FPIX_disk2_plus_err;
  vector<double> hit_rate_FPIX_disk2_minus;
  vector<double> hit_rate_FPIX_disk2_minus_err;
  vector<double> hit_rate_FPIX_disk3_plus;
  vector<double> hit_rate_FPIX_disk3_plus_err;
  vector<double> hit_rate_FPIX_disk3_minus;
  vector<double> hit_rate_FPIX_disk3_minus_err;

  //DEFINE TMULTIGRAPHS
  TMultiGraph mg_event_rate("event rate","");
  TMultiGraph mg_track_rate("track rate","");
  TMultiGraph mg_hit_rate("hit rate","");
  TMultiGraph mg_hit_rate_PIX("pixel hit rate","");
  TMultiGraph mg_hit_rate_FPIX("fpix hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk1("fpix disk1 hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk2("fpix disk2 hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk3("fpix disk3 hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk1_plus("fpix disk1 plus hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk1_minus("fpix disk1 minus hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk2_plus("fpix disk2 plus hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk2_minus("fpix disk2 minus hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk3_plus("fpix disk3 plus hit rate","");
  TMultiGraph mg_hit_rate_FPIX_disk3_minus("fpix disk3 minus hit rate","");
  TMultiGraph mg_hit_rate_BPIX("bpix hit rate","");
  TMultiGraph mg_hit_rate_BPIX_layer1("bpix1 hit rate","");
  TMultiGraph mg_hit_rate_BPIX_layer2("bpix2 hit rate","");
  TMultiGraph mg_hit_rate_BPIX_layer3("bpix3 rate","");
  TMultiGraph mg_hit_rate_BPIX_layer4("bpix4 rate","");

  //Defining canvas and tex data for plots labelling
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

  //+++++++++++++++++++++++++++++       Make Directory     +++++++++++++++++++++++++++++++++++++
  gSystem->Exec("mkdir -p Hit_Rate_Plots");
  
  int j = 0;
  double total_tracks = 0, nTotalEvents = 0, nTotalTracks = 0, nTotalHits = 0, nZeroRunTimeRuns = 0;

  for(int i=0;i<10;i++) // Loop over vectors
    {
      if(i==0) vec=v1;
      else if(i==1) vec=v2;
      else if(i==2) vec=v3;
      else if(i==3) vec=v4;
      else if(i==4) vec=v5;
      else if(i==5) vec=v6;
      else if(i==6) vec=v7;
      else if(i==7) vec=v8;
      else if(i==8) vec=v9;
      else if(i==9) vec=v10;

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
      else if(i==8) { ci=TColor::GetColor("#000000"); }
      else if(i==9) { ci=TColor::GetColor("#2FA4E1"); }
        
      Long64_t n = tree->GetEntriesFast();
      for (Long64_t jentry = 0; jentry < n; jentry++) {
	tree->GetEntry(jentry);
	if (run_time == 0 || run_time < 0) {
	  nZeroRunTimeRuns++;
	  continue;
	}
	
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
	    events.push_back(number_of_events);
	    event_rate.push_back(number_of_events / run_time);
	    runNumber.push_back(runnum);
	    track_rate.push_back(number_of_tracks / run_time);
	    tracks.push_back(number_of_tracks);
	    
	    nTotalEvents += number_of_events;
	    nTotalTracks += number_of_tracks;
	    nTotalHits += number_of_hits_Total;
	    
	    hits.push_back(number_of_hits_Total);
	    hit_rate_Total.push_back(number_of_hits_Total / run_time);
	    hit_rate_Total_err.push_back(sqrt(float(number_of_hits_Total)) / run_time);
	    hit_rate_PIX.push_back(number_of_hits_PIX / run_time);
	    hit_rate_PIX_err.push_back(sqrt(float(number_of_hits_PIX)) / run_time);
	    hit_rate_BPIX.push_back(number_of_hits_BPIX / run_time);
	    hit_rate_BPIX_err.push_back(sqrt(float(number_of_hits_BPIX)) / run_time);
	    hit_rate_BPIX_layer1.push_back(number_of_hits_BPIX_layer1 / run_time);
	    hit_rate_BPIX_layer1_err.push_back(sqrt(float(number_of_hits_BPIX_layer1)) / run_time);
	    hit_rate_BPIX_layer2.push_back(number_of_hits_BPIX_layer2 / run_time);
	    hit_rate_BPIX_layer2_err.push_back(sqrt(float(number_of_hits_BPIX_layer2)) / run_time);
	    hit_rate_BPIX_layer3.push_back(number_of_hits_BPIX_layer3 / run_time);
	    hit_rate_BPIX_layer3_err.push_back(sqrt(float(number_of_hits_BPIX_layer3)) / run_time);
	    hit_rate_BPIX_layer4.push_back(number_of_hits_BPIX_layer4 / run_time);
	    hit_rate_BPIX_layer4_err.push_back(sqrt(float(number_of_hits_BPIX_layer4)) / run_time);
	    hit_rate_FPIX.push_back(number_of_hits_FPIX / run_time);
	    hit_rate_FPIX_err.push_back(sqrt(float(number_of_hits_FPIX)) / run_time);
	    hit_rate_FPIX_disk1.push_back(number_of_hits_FPIX_disk1 / run_time);
	    hit_rate_FPIX_disk1_err.push_back(sqrt(float(number_of_hits_FPIX_disk1)) / run_time);
	    hit_rate_FPIX_disk2.push_back(number_of_hits_FPIX_disk2 / run_time);
	    hit_rate_FPIX_disk2_err.push_back(sqrt(float(number_of_hits_FPIX_disk2)) / run_time);
	    hit_rate_FPIX_disk3.push_back(number_of_hits_FPIX_disk3 / run_time);
	    hit_rate_FPIX_disk3_err.push_back(sqrt(float(number_of_hits_FPIX_disk3)) / run_time);
	    hit_rate_FPIX_disk1_plus.push_back(number_of_hits_FPIX_disk1_plus / run_time);
	    hit_rate_FPIX_disk1_plus_err.push_back(sqrt(float(number_of_hits_FPIX_disk1_plus)) / run_time);
	    hit_rate_FPIX_disk1_minus.push_back(number_of_hits_FPIX_disk1_minus / run_time);
	    hit_rate_FPIX_disk1_minus_err.push_back(sqrt(float(number_of_hits_FPIX_disk1_minus)) / run_time);
	    hit_rate_FPIX_disk2_plus.push_back(number_of_hits_FPIX_disk2_plus / run_time);
	    hit_rate_FPIX_disk2_plus_err.push_back(sqrt(float(number_of_hits_FPIX_disk2_plus)) / run_time);
	    hit_rate_FPIX_disk2_minus.push_back(number_of_hits_FPIX_disk2_minus / run_time);
	    hit_rate_FPIX_disk2_minus_err.push_back(sqrt(float(number_of_hits_FPIX_disk2_minus)) / run_time);
	    hit_rate_FPIX_disk3_plus.push_back(number_of_hits_FPIX_disk3_plus / run_time);
	    hit_rate_FPIX_disk3_plus_err.push_back(sqrt(float(number_of_hits_FPIX_disk3_plus)) / run_time);
	    hit_rate_FPIX_disk3_minus.push_back(number_of_hits_FPIX_disk3_minus / run_time);
	    hit_rate_FPIX_disk3_minus_err.push_back(sqrt(float(number_of_hits_FPIX_disk3_minus)) / run_time);
	    
	    track_rate_err.push_back(sqrt(float(number_of_tracks)) / run_time);
	    event_rate_err.push_back(sqrt(float(number_of_events)) / run_time);
	    runNumber_err.push_back(0);
	    
	    j++;
	  }
	else{
	  continue;
	}

      }//Loop over Runs

      //-------- TVectors to be taken as input in TGraphs for plotting ---------//
      TVectorD event_rate_VecD;
      TVectorD event_rate_err_VecD;
      TVectorD track_rate_VecD;
      TVectorD track_rate_err_VecD;
      TVectorD runNumber_VecD;
      TVectorD runNumber_err_VecD;
      TVectorD hit_rate_VecD;
      TVectorD hit_rate_err_VecD;
      TVectorD hit_rate_PIX_VecD;
      TVectorD hit_rate_PIX_err_VecD;
      TVectorD hit_rate_BPIX_VecD;
      TVectorD hit_rate_BPIX_err_VecD;
      TVectorD hit_rate_BPIX_layer1_VecD;
      TVectorD hit_rate_BPIX_layer1_err_VecD;
      TVectorD hit_rate_BPIX_layer2_VecD;
      TVectorD hit_rate_BPIX_layer2_err_VecD;
      TVectorD hit_rate_BPIX_layer3_VecD;
      TVectorD hit_rate_BPIX_layer3_err_VecD;
      TVectorD hit_rate_BPIX_layer4_VecD;
      TVectorD hit_rate_BPIX_layer4_err_VecD;
      TVectorD hit_rate_FPIX_VecD;
      TVectorD hit_rate_FPIX_err_VecD;
      TVectorD hit_rate_FPIX_disk1_VecD;
      TVectorD hit_rate_FPIX_disk1_err_VecD;
      TVectorD hit_rate_FPIX_disk2_VecD;
      TVectorD hit_rate_FPIX_disk2_err_VecD;
      TVectorD hit_rate_FPIX_disk3_VecD;
      TVectorD hit_rate_FPIX_disk3_err_VecD;
      TVectorD hit_rate_FPIX_disk1_plus_VecD;
      TVectorD hit_rate_FPIX_disk1_plus_err_VecD;
      TVectorD hit_rate_FPIX_disk1_minus_VecD;
      TVectorD hit_rate_FPIX_disk1_minus_err_VecD;
      TVectorD hit_rate_FPIX_disk2_plus_VecD;
      TVectorD hit_rate_FPIX_disk2_plus_err_VecD;
      TVectorD hit_rate_FPIX_disk2_minus_VecD;
      TVectorD hit_rate_FPIX_disk2_minus_err_VecD;
      TVectorD hit_rate_FPIX_disk3_plus_VecD;
      TVectorD hit_rate_FPIX_disk3_plus_err_VecD;
      TVectorD hit_rate_FPIX_disk3_minus_VecD;
      TVectorD hit_rate_FPIX_disk3_minus_err_VecD;

      runNumber_VecD.Use(runNumber.size(), &(runNumber[0]));
      runNumber_err_VecD.Use(runNumber_err.size(), &(runNumber_err[0]));
      event_rate_VecD.Use(event_rate.size(), &(event_rate[0]));
      event_rate_err_VecD.Use(event_rate_err.size(), &(event_rate_err[0]));
      track_rate_VecD.Use(track_rate.size(), &(track_rate[0]));
      track_rate_err_VecD.Use(track_rate_err.size(), &(track_rate_err[0]));
      hit_rate_VecD.Use(hit_rate_Total.size(), &(hit_rate_Total[0]));
      hit_rate_err_VecD.Use(hit_rate_Total_err.size(), &(hit_rate_Total_err[0]));
      hit_rate_PIX_VecD.Use(hit_rate_PIX.size(), &(hit_rate_PIX[0]));
      hit_rate_PIX_err_VecD.Use(hit_rate_PIX_err.size(), &(hit_rate_PIX_err[0]));
      hit_rate_BPIX_VecD.Use(hit_rate_BPIX.size(), &(hit_rate_BPIX[0]));
      hit_rate_BPIX_err_VecD.Use(hit_rate_BPIX_err.size(), &(hit_rate_BPIX_err[0]));
      hit_rate_BPIX_layer1_VecD.Use(hit_rate_BPIX_layer1.size(), &(hit_rate_BPIX_layer1[0]));
      hit_rate_BPIX_layer1_err_VecD.Use(hit_rate_BPIX_layer1_err.size(), &(hit_rate_BPIX_layer1_err[0]));
      hit_rate_BPIX_layer2_VecD.Use(hit_rate_BPIX_layer2.size(), &(hit_rate_BPIX_layer2[0]));
      hit_rate_BPIX_layer2_err_VecD.Use(hit_rate_BPIX_layer2_err.size(), &(hit_rate_BPIX_layer2_err[0]));
      hit_rate_BPIX_layer3_VecD.Use(hit_rate_BPIX_layer3.size(), &(hit_rate_BPIX_layer3[0]));
      hit_rate_BPIX_layer3_err_VecD.Use(hit_rate_BPIX_layer3_err.size(), &(hit_rate_BPIX_layer3_err[0]));
      hit_rate_BPIX_layer4_VecD.Use(hit_rate_BPIX_layer4.size(), &(hit_rate_BPIX_layer4[0]));
      hit_rate_BPIX_layer4_err_VecD.Use(hit_rate_BPIX_layer4_err.size(), &(hit_rate_BPIX_layer4_err[0]));
      hit_rate_FPIX_VecD.Use(hit_rate_FPIX.size(), &(hit_rate_FPIX[0]));
      hit_rate_FPIX_err_VecD.Use(hit_rate_FPIX_err.size(), &(hit_rate_FPIX_err[0]));
      hit_rate_FPIX_disk1_VecD.Use(hit_rate_FPIX_disk1.size(), &(hit_rate_FPIX_disk1[0]));
      hit_rate_FPIX_disk1_err_VecD.Use(hit_rate_FPIX_disk1_err.size(), &(hit_rate_FPIX_disk1_err[0]));
      hit_rate_FPIX_disk2_VecD.Use(hit_rate_FPIX_disk2.size(), &(hit_rate_FPIX_disk2[0]));
      hit_rate_FPIX_disk2_err_VecD.Use(hit_rate_FPIX_disk2_err.size(), &(hit_rate_FPIX_disk2_err[0]));
      hit_rate_FPIX_disk3_VecD.Use(hit_rate_FPIX_disk3.size(), &(hit_rate_FPIX_disk3[0]));
      hit_rate_FPIX_disk3_err_VecD.Use(hit_rate_FPIX_disk3_err.size(), &(hit_rate_FPIX_disk3_err[0]));
      hit_rate_FPIX_disk1_plus_VecD.Use(hit_rate_FPIX_disk1_plus.size(), &(hit_rate_FPIX_disk1_plus[0]));
      hit_rate_FPIX_disk1_plus_err_VecD.Use(hit_rate_FPIX_disk1_plus_err.size(), &(hit_rate_FPIX_disk1_plus_err[0]));
      hit_rate_FPIX_disk1_minus_VecD.Use(hit_rate_FPIX_disk1_minus.size(), &(hit_rate_FPIX_disk1_minus[0]));
      hit_rate_FPIX_disk1_minus_err_VecD.Use(hit_rate_FPIX_disk1_minus_err.size(), &(hit_rate_FPIX_disk1_minus_err[0]));
      hit_rate_FPIX_disk2_plus_VecD.Use(hit_rate_FPIX_disk2_plus.size(), &(hit_rate_FPIX_disk2_plus[0]));
      hit_rate_FPIX_disk2_plus_err_VecD.Use(hit_rate_FPIX_disk2_plus_err.size(), &(hit_rate_FPIX_disk2_plus_err[0]));
      hit_rate_FPIX_disk2_minus_VecD.Use(hit_rate_FPIX_disk2_minus.size(), &(hit_rate_FPIX_disk2_minus[0]));
      hit_rate_FPIX_disk2_minus_err_VecD.Use(hit_rate_FPIX_disk2_minus_err.size(), &(hit_rate_FPIX_disk2_minus_err[0]));
      hit_rate_FPIX_disk3_plus_VecD.Use(hit_rate_FPIX_disk3_plus.size(), &(hit_rate_FPIX_disk3_plus[0]));
      hit_rate_FPIX_disk3_plus_err_VecD.Use(hit_rate_FPIX_disk3_plus_err.size(), &(hit_rate_FPIX_disk3_plus_err[0]));
      hit_rate_FPIX_disk3_minus_VecD.Use(hit_rate_FPIX_disk3_minus.size(), &(hit_rate_FPIX_disk3_minus[0]));
      hit_rate_FPIX_disk3_minus_err_VecD.Use(hit_rate_FPIX_disk3_minus_err.size(), &(hit_rate_FPIX_disk3_minus_err[0]));
      
      //+++++++++++++++++++++++++++++  Overall event rate  +++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_event_rate = new TGraphErrors(runNumber_VecD, event_rate_VecD, runNumber_err_VecD, event_rate_err_VecD);
      gr_event_rate->GetXaxis()->SetTitle("Run Number");
      gr_event_rate->GetXaxis()->SetLabelSize(0.04);
      gr_event_rate->GetXaxis()->SetNoExponent();
      gr_event_rate->GetXaxis()->SetNdivisions(5);
      gr_event_rate->GetYaxis()->SetTitle("Event Rate (Hz)");
      gr_event_rate->GetXaxis()->SetTitleSize(0.05);
      gr_event_rate->GetYaxis()->SetLabelSize(0.05);
      gr_event_rate->GetYaxis()->SetTitleSize(0.05);
      gr_event_rate->SetMarkerStyle(20);
      gr_event_rate->SetMarkerSize(1.8);
      gr_event_rate->SetMarkerColor(ci);
      gr_event_rate->SetTitle("");
       
      //++++++++++++++++++++++++++++++  Overall track rate  +++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_track_rate = new TGraphErrors(runNumber_VecD, track_rate_VecD, runNumber_err_VecD, track_rate_err_VecD);
      gr_track_rate->GetXaxis()->SetTitle("Run Number");
      gr_track_rate->GetXaxis()->SetLabelSize(0.04);
      gr_track_rate->GetXaxis()->SetNoExponent();
      gr_track_rate->GetXaxis()->SetNdivisions(5);
      gr_track_rate->GetYaxis()->SetTitle("Track Rate (Hz)");
      gr_track_rate->GetXaxis()->SetTitleSize(0.05);
      gr_track_rate->GetYaxis()->SetLabelSize(0.05);
      gr_track_rate->GetYaxis()->SetTitleSize(0.05);
      gr_track_rate->SetMarkerStyle(20);
      gr_track_rate->SetMarkerSize(1.8);
      gr_track_rate->SetMarkerColor(ci);
      gr_track_rate->SetTitle("");
      
      //++++++++++++++++++++++++++++++  Overall hit rate  +++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate = new TGraphErrors(runNumber_VecD, hit_rate_VecD, runNumber_err_VecD, hit_rate_err_VecD);
      gr_hit_rate->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate->GetXaxis()->SetNoExponent();
      gr_hit_rate->GetXaxis()->SetNdivisions(5);
      gr_hit_rate->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate->SetMarkerStyle(20);
      gr_hit_rate->SetMarkerSize(1.8);
      gr_hit_rate->SetMarkerColor(ci);
      gr_hit_rate->SetTitle("");
      
      //+++++++++++++++++++++++++++++++  Total Pixel hit rate +++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_PIX = new TGraphErrors(runNumber_VecD, hit_rate_PIX_VecD, runNumber_err_VecD, hit_rate_PIX_err_VecD);
      gr_hit_rate_PIX->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_PIX->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_PIX->GetXaxis()->SetNoExponent();
      gr_hit_rate_PIX->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_PIX->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_PIX->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_PIX->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_PIX->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_PIX->SetMarkerStyle(20);
      gr_hit_rate_PIX->SetMarkerSize(1.8);
      gr_hit_rate_PIX->SetMarkerColor(ci);
      gr_hit_rate_PIX->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX = new TGraphErrors(runNumber_VecD, hit_rate_FPIX_VecD, runNumber_err_VecD, hit_rate_FPIX_err_VecD);
      gr_hit_rate_FPIX->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX->SetMarkerStyle(20);
      gr_hit_rate_FPIX->SetMarkerSize(1.8);
      gr_hit_rate_FPIX->SetMarkerColor(ci);
      gr_hit_rate_FPIX->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX Disk1 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk1 = new TGraphErrors(
					  runNumber_VecD, hit_rate_FPIX_disk1_VecD, runNumber_err_VecD, hit_rate_FPIX_disk1_err_VecD);
      gr_hit_rate_FPIX_disk1->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk1->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk1->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk1->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk1->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk1->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk1->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk1->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk1->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk1->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk1->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk1->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX Disk2 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk2 = new TGraphErrors(
					  runNumber_VecD, hit_rate_FPIX_disk2_VecD, runNumber_err_VecD, hit_rate_FPIX_disk2_err_VecD);
      gr_hit_rate_FPIX_disk2->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk2->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk2->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk2->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk2->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk2->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk2->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk2->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk2->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk2->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk2->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk2->SetTitle("");
       
      //++++++++++++++++++++++++++++++++  FPIX Disk3 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk3 = new TGraphErrors(
					  runNumber_VecD, hit_rate_FPIX_disk3_VecD, runNumber_err_VecD, hit_rate_FPIX_disk3_err_VecD);
      gr_hit_rate_FPIX_disk3->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk3->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk3->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk3->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk3->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk3->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk3->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk3->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk3->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk3->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk3->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk3->SetTitle("");

      //++++++++++++++++++++++++++++++++  FPIX Disk1+ hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk1_plus = new TGraphErrors(
					       runNumber_VecD, hit_rate_FPIX_disk1_plus_VecD, runNumber_err_VecD, hit_rate_FPIX_disk1_plus_err_VecD);
      gr_hit_rate_FPIX_disk1_plus->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk1_plus->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk1_plus->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk1_plus->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk1_plus->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk1_plus->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk1_plus->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk1_plus->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk1_plus->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk1_plus->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk1_plus->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk1_plus->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX Disk1- hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk1_minus = new TGraphErrors(
						runNumber_VecD, hit_rate_FPIX_disk1_minus_VecD, runNumber_err_VecD, hit_rate_FPIX_disk1_minus_err_VecD);
      gr_hit_rate_FPIX_disk1_minus->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk1_minus->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk1_minus->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk1_minus->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk1_minus->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk1_minus->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk1_minus->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk1_minus->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk1_minus->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk1_minus->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk1_minus->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk1_minus->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX Disk2+ hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk2_plus = new TGraphErrors(
					       runNumber_VecD, hit_rate_FPIX_disk2_plus_VecD, runNumber_err_VecD, hit_rate_FPIX_disk2_plus_err_VecD);
      gr_hit_rate_FPIX_disk2_plus->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk2_plus->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk2_plus->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk2_plus->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk2_plus->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk2_plus->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk2_plus->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk2_plus->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk2_plus->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk2_plus->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk2_plus->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk2_plus->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX Disk2- hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk2_minus = new TGraphErrors(
						runNumber_VecD, hit_rate_FPIX_disk2_minus_VecD, runNumber_err_VecD, hit_rate_FPIX_disk2_minus_err_VecD);
      gr_hit_rate_FPIX_disk2_minus->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk2_minus->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk2_minus->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk2_minus->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk2_minus->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk2_minus->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk2_minus->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk2_minus->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk2_minus->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk2_minus->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk2_minus->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk2_minus->SetTitle("");
       
      //++++++++++++++++++++++++++++++++  FPIX Disk3+ hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk3_plus = new TGraphErrors(
					       runNumber_VecD, hit_rate_FPIX_disk3_plus_VecD, runNumber_err_VecD, hit_rate_FPIX_disk3_plus_err_VecD);
      gr_hit_rate_FPIX_disk3_plus->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk3_plus->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk3_plus->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk3_plus->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk3_plus->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk3_plus->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk3_plus->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk3_plus->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk3_plus->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk3_plus->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk3_plus->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk3_plus->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  FPIX Disk3- hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_FPIX_disk3_minus = new TGraphErrors(
						runNumber_VecD, hit_rate_FPIX_disk3_minus_VecD, runNumber_err_VecD, hit_rate_FPIX_disk3_minus_err_VecD);
      gr_hit_rate_FPIX_disk3_minus->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_FPIX_disk3_minus->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_FPIX_disk3_minus->GetXaxis()->SetNoExponent();
      gr_hit_rate_FPIX_disk3_minus->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_FPIX_disk3_minus->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_FPIX_disk3_minus->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk3_minus->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_FPIX_disk3_minus->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_FPIX_disk3_minus->SetMarkerStyle(20);
      gr_hit_rate_FPIX_disk3_minus->SetMarkerSize(1.8);
      gr_hit_rate_FPIX_disk3_minus->SetMarkerColor(ci);
      gr_hit_rate_FPIX_disk3_minus->SetTitle("");
       
      //++++++++++++++++++++++++++++++++  BPIX hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_BPIX = new TGraphErrors(runNumber_VecD, hit_rate_BPIX_VecD, runNumber_err_VecD, hit_rate_BPIX_err_VecD);
      gr_hit_rate_BPIX->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_BPIX->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_BPIX->GetXaxis()->SetNoExponent();
      gr_hit_rate_BPIX->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_BPIX->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_BPIX->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_BPIX->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX->SetMarkerStyle(20);
      gr_hit_rate_BPIX->SetMarkerSize(1.8);
      gr_hit_rate_BPIX->SetMarkerColor(ci);
      gr_hit_rate_BPIX->SetTitle("");
       
      //++++++++++++++++++++++++++++++++  BPIX layer 1 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_BPIX_layer1 = new TGraphErrors(
					   runNumber_VecD, hit_rate_BPIX_layer1_VecD, runNumber_err_VecD, hit_rate_BPIX_layer1_err_VecD);
      gr_hit_rate_BPIX_layer1->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_BPIX_layer1->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_BPIX_layer1->GetXaxis()->SetNoExponent();
      gr_hit_rate_BPIX_layer1->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_BPIX_layer1->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_BPIX_layer1->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer1->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_BPIX_layer1->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer1->SetMarkerStyle(20);
      gr_hit_rate_BPIX_layer1->SetMarkerSize(1.8);
      gr_hit_rate_BPIX_layer1->SetMarkerColor(ci);
      gr_hit_rate_BPIX_layer1->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  BPIX layer 2 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_BPIX_layer2 = new TGraphErrors(
					   runNumber_VecD, hit_rate_BPIX_layer2_VecD, runNumber_err_VecD, hit_rate_BPIX_layer2_err_VecD);
      gr_hit_rate_BPIX_layer2->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_BPIX_layer2->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_BPIX_layer2->GetXaxis()->SetNoExponent();
      gr_hit_rate_BPIX_layer2->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_BPIX_layer2->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_BPIX_layer2->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer2->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_BPIX_layer2->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer2->SetMarkerStyle(20);
      gr_hit_rate_BPIX_layer2->SetMarkerSize(1.8);
      gr_hit_rate_BPIX_layer2->SetMarkerColor(ci);
      gr_hit_rate_BPIX_layer2->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  BPIX layer 3 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_BPIX_layer3 = new TGraphErrors(
					   runNumber_VecD, hit_rate_BPIX_layer3_VecD, runNumber_err_VecD, hit_rate_BPIX_layer3_err_VecD);
      gr_hit_rate_BPIX_layer3->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_BPIX_layer3->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_BPIX_layer3->GetXaxis()->SetNoExponent();
      gr_hit_rate_BPIX_layer3->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_BPIX_layer3->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_BPIX_layer3->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer3->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_BPIX_layer3->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer3->SetMarkerStyle(20);
      gr_hit_rate_BPIX_layer3->SetMarkerSize(1.8);
      gr_hit_rate_BPIX_layer3->SetMarkerColor(ci);
      gr_hit_rate_BPIX_layer3->SetTitle("");
      
      //++++++++++++++++++++++++++++++++  BPIX layer 4 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
      
      TGraphErrors *gr_hit_rate_BPIX_layer4 = new TGraphErrors(
					   runNumber_VecD, hit_rate_BPIX_layer4_VecD, runNumber_err_VecD, hit_rate_BPIX_layer4_err_VecD);
      gr_hit_rate_BPIX_layer4->GetXaxis()->SetTitle("Run Number");
      gr_hit_rate_BPIX_layer4->GetXaxis()->SetLabelSize(0.04);
      gr_hit_rate_BPIX_layer4->GetXaxis()->SetNoExponent();
      gr_hit_rate_BPIX_layer4->GetXaxis()->SetNdivisions(5);
      gr_hit_rate_BPIX_layer4->GetYaxis()->SetTitle("Hit Rate (Hz)");
      gr_hit_rate_BPIX_layer4->GetXaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer4->GetYaxis()->SetLabelSize(0.05);
      gr_hit_rate_BPIX_layer4->GetYaxis()->SetTitleSize(0.05);
      gr_hit_rate_BPIX_layer4->SetMarkerStyle(20);
      gr_hit_rate_BPIX_layer4->SetMarkerSize(1.8);
      gr_hit_rate_BPIX_layer4->SetMarkerColor(ci);
      gr_hit_rate_BPIX_layer4->SetTitle("");

      // Add the graphs to MultiGraphs
      mg_event_rate.Add(gr_event_rate);
      mg_track_rate.Add(gr_track_rate);
      mg_hit_rate.Add(gr_hit_rate);
      mg_hit_rate_PIX.Add(gr_hit_rate_PIX);
      mg_hit_rate_FPIX.Add(gr_hit_rate_FPIX);
      mg_hit_rate_FPIX_disk1.Add(gr_hit_rate_FPIX_disk1);
      mg_hit_rate_FPIX_disk2.Add(gr_hit_rate_FPIX_disk2);
      mg_hit_rate_FPIX_disk3.Add(gr_hit_rate_FPIX_disk3);
      mg_hit_rate_FPIX_disk1_plus.Add(gr_hit_rate_FPIX_disk1_plus);
      mg_hit_rate_FPIX_disk1_minus.Add(gr_hit_rate_FPIX_disk1_minus);
      mg_hit_rate_FPIX_disk2_plus.Add(gr_hit_rate_FPIX_disk2_plus);
      mg_hit_rate_FPIX_disk2_minus.Add(gr_hit_rate_FPIX_disk2_minus);
      mg_hit_rate_FPIX_disk3_plus.Add(gr_hit_rate_FPIX_disk3_plus);
      mg_hit_rate_FPIX_disk3_minus.Add(gr_hit_rate_FPIX_disk3_minus);
      mg_hit_rate_BPIX.Add(gr_hit_rate_BPIX);
      mg_hit_rate_BPIX_layer1.Add(gr_hit_rate_BPIX_layer1);
      mg_hit_rate_BPIX_layer2.Add(gr_hit_rate_BPIX_layer2);
      mg_hit_rate_BPIX_layer3.Add(gr_hit_rate_BPIX_layer3);
      mg_hit_rate_BPIX_layer4.Add(gr_hit_rate_BPIX_layer4);

      //clear vectors
      event_rate;
      event_rate_err.clear();
      track_rate.clear();
      track_rate_err.clear();
      runNumber.clear();
      runNumber_err.clear();
      tracks.clear();
      tracks_err.clear();
      hits.clear();
      hit_rate_Total.clear();
      hit_rate_Total_err.clear();
      hit_rate_PIX.clear();
      hit_rate_PIX_err.clear();
      hit_rate_BPIX.clear();
      hit_rate_BPIX_err.clear();
      hit_rate_BPIX_layer1.clear();
      hit_rate_BPIX_layer1_err.clear();
      hit_rate_BPIX_layer2.clear();
      hit_rate_BPIX_layer2_err.clear();
      hit_rate_BPIX_layer3.clear();
      hit_rate_BPIX_layer3_err.clear();
      hit_rate_BPIX_layer4.clear();
      hit_rate_BPIX_layer4_err.clear();
      hit_rate_FPIX.clear();
      hit_rate_FPIX_err.clear();
      hit_rate_FPIX_disk1.clear();
      hit_rate_FPIX_disk1_err.clear();
      hit_rate_FPIX_disk2.clear();
      hit_rate_FPIX_disk2_err.clear();
      hit_rate_FPIX_disk3.clear();
      hit_rate_FPIX_disk3_err.clear();
      hit_rate_FPIX_disk1_plus.clear();
      hit_rate_FPIX_disk1_plus_err.clear();
      hit_rate_FPIX_disk1_minus.clear();
      hit_rate_FPIX_disk1_minus_err.clear();
      hit_rate_FPIX_disk2_plus.clear();
      hit_rate_FPIX_disk2_plus_err.clear();
      hit_rate_FPIX_disk2_minus.clear();
      hit_rate_FPIX_disk2_minus_err.clear();
      hit_rate_FPIX_disk3_plus.clear();
      hit_rate_FPIX_disk3_plus_err.clear();
      hit_rate_FPIX_disk3_minus.clear();
      hit_rate_FPIX_disk3_minus_err.clear();      
      
      //Clear TVectors
      event_rate_VecD.Clear();
      event_rate_err_VecD.Clear();
      track_rate_VecD.Clear();
      track_rate_err_VecD.Clear();
      runNumber_VecD.Clear();
      runNumber_err_VecD.Clear();
      hit_rate_VecD.Clear();
      hit_rate_err_VecD.Clear();
      hit_rate_PIX_VecD.Clear();
      hit_rate_PIX_err_VecD.Clear();
      hit_rate_BPIX_VecD.Clear();
      hit_rate_BPIX_err_VecD.Clear();
      hit_rate_BPIX_layer1_VecD.Clear();
      hit_rate_BPIX_layer1_err_VecD.Clear();
      hit_rate_BPIX_layer2_VecD.Clear();
      hit_rate_BPIX_layer2_err_VecD.Clear();
      hit_rate_BPIX_layer3_VecD.Clear();
      hit_rate_BPIX_layer3_err_VecD.Clear();
      hit_rate_BPIX_layer4_VecD.Clear();
      hit_rate_BPIX_layer4_err_VecD.Clear();
      hit_rate_FPIX_VecD.Clear();
      hit_rate_FPIX_err_VecD.Clear();
      hit_rate_FPIX_disk1_VecD.Clear();
      hit_rate_FPIX_disk1_err_VecD.Clear();
      hit_rate_FPIX_disk2_VecD.Clear();
      hit_rate_FPIX_disk2_err_VecD.Clear();
      hit_rate_FPIX_disk3_VecD.Clear();
      hit_rate_FPIX_disk3_err_VecD.Clear();
      hit_rate_FPIX_disk1_plus_VecD.Clear();
      hit_rate_FPIX_disk1_plus_err_VecD.Clear();
      hit_rate_FPIX_disk1_minus_VecD.Clear();
      hit_rate_FPIX_disk1_minus_err_VecD.Clear();
      hit_rate_FPIX_disk2_plus_VecD.Clear();
      hit_rate_FPIX_disk2_plus_err_VecD.Clear();
      hit_rate_FPIX_disk2_minus_VecD.Clear();
      hit_rate_FPIX_disk2_minus_err_VecD.Clear();
      hit_rate_FPIX_disk3_plus_VecD.Clear();
      hit_rate_FPIX_disk3_plus_err_VecD.Clear();
      hit_rate_FPIX_disk3_minus_VecD.Clear();
      hit_rate_FPIX_disk3_minus_err_VecD.Clear();

    } //Loop over the vectors with different time settings

  //Plot Multigraphs
  
  //+++++++++++++++++++++++++++++  Overall event rate  +++++++++++++++++++++++++++++++++++++
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
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "Event Rate");
  c.SetGrid();
  c.SaveAs("event_rate.png");
  c.SaveAs("event_rate.pdf");
  c.SaveAs("event_rate.C");
  c.Clear();
  gSystem->Exec("mv event_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv event_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv event_rate.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++  Overall track rate  +++++++++++++++++++++++++++++++++++++++++++
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
  gSystem->Exec("mv track_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv track_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv track_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++  Overall hit rate  +++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate.Draw("AP");
  mg_hit_rate.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate.GetXaxis()->SetNoExponent();
  mg_hit_rate.GetXaxis()->SetNdivisions(5);
  mg_hit_rate.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "Hit Rate");
  c.SetGrid();
  c.SaveAs("hit_rate.png");
  c.SaveAs("hit_rate.pdf");
  c.SaveAs("hit_rate.C");
  c.Clear();
  gSystem->Exec("mv hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv hit_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++  Total Pixel hit rate +++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_PIX.Draw("AP");
  mg_hit_rate_PIX.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_PIX.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_PIX.GetXaxis()->SetNoExponent();
  mg_hit_rate_PIX.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_PIX.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_PIX.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_PIX.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_PIX.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_PIX.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "PIXEL");
  c.SetGrid();
  c.SaveAs("pixel_hit_rate.png");
  c.SaveAs("pixel_hit_rate.pdf");
  c.SaveAs("pixel_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv pixel_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv pixel_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv pixel_hit_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX.Draw("AP");
  mg_hit_rate_FPIX.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate.png");
  c.SaveAs("fpix_hit_rate.pdf");
  c.SaveAs("fpix_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk1 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk1.Draw("AP");
  mg_hit_rate_FPIX_disk1.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk1.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk1.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk1.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk1.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk1.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk1.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk1.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk1.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 1");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk1.png");
  c.SaveAs("fpix_hit_rate_disk1.pdf");
  c.SaveAs("fpix_hit_rate_disk1.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk1.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk1.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk1.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk2 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk2.Draw("AP");
  mg_hit_rate_FPIX_disk2.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk2.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk2.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk2.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk2.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk2.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk2.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk2.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk2.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 2");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk2.png");
  c.SaveAs("fpix_hit_rate_disk2.pdf");
  c.SaveAs("fpix_hit_rate_disk2.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk2.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk2.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk2.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk3 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk3.Draw("AP");
  mg_hit_rate_FPIX_disk3.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk3.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk3.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk3.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk3.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk3.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk3.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk3.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk3.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 3");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk3.png");
  c.SaveAs("fpix_hit_rate_disk3.pdf");
  c.SaveAs("fpix_hit_rate_disk3.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk3.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk3.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk3.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk1+ hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk1_plus.Draw("AP");
  mg_hit_rate_FPIX_disk1_plus.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk1_plus.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk1_plus.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk1_plus.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk1_plus.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk1_plus.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk1_plus.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk1_plus.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk1_plus.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 1+");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk1_plus.png");
  c.SaveAs("fpix_hit_rate_disk1_plus.C");
  c.SaveAs("fpix_hit_rate_disk1_plus.pdf");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk1_plus.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk1_plus.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk1_plus.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk1- hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk1_minus.Draw("AP");
  mg_hit_rate_FPIX_disk1_minus.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk1_minus.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk1_minus.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk1_minus.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk1_minus.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk1_minus.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk1_minus.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk1_minus.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk1_minus.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 1-");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk1_minus.png");
  c.SaveAs("fpix_hit_rate_disk1_minus.pdf");
  c.SaveAs("fpix_hit_rate_disk1_minus.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk1_minus.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk1_minus.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk1_minus.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk2+ hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk2_plus.Draw("AP");
  mg_hit_rate_FPIX_disk2_plus.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk2_plus.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk2_plus.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk2_plus.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk2_plus.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk2_plus.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk2_plus.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk2_plus.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk2_plus.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 2+");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk2_plus.png");
  c.SaveAs("fpix_hit_rate_disk2_plus.pdf");
  c.SaveAs("fpix_hit_rate_disk2_plus.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk2_plus.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk2_plus.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk2_plus.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk2- hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk2_minus.Draw("AP");
  mg_hit_rate_FPIX_disk2_minus.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk2_minus.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk2_minus.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk2_minus.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk2_minus.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk2_minus.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk2_minus.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk2_minus.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk2_minus.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 2-");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk2_minus.png");
  c.SaveAs("fpix_hit_rate_disk2_minus.pdf");
  c.SaveAs("fpix_hit_rate_disk2_minus.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk2_minus.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk2_minus.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk2_minus.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk3+ hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk3_plus.Draw("AP");
  mg_hit_rate_FPIX_disk3_plus.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk3_plus.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk3_plus.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk3_plus.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk3_plus.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk3_plus.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk3_plus.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk3_plus.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk3_plus.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 3+");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk3_plus.png");
  c.SaveAs("fpix_hit_rate_disk3_plus.pdf");
  c.SaveAs("fpix_hit_rate_disk3_plus.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk3_plus.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk3_plus.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk3_plus.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  FPIX Disk3- hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_FPIX_disk3_minus.Draw("AP");
  mg_hit_rate_FPIX_disk3_minus.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_FPIX_disk3_minus.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_FPIX_disk3_minus.GetXaxis()->SetNoExponent();
  mg_hit_rate_FPIX_disk3_minus.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_FPIX_disk3_minus.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_FPIX_disk3_minus.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk3_minus.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_FPIX_disk3_minus.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_FPIX_disk3_minus.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "FPIX disk 3-");
  c.SetGrid();
  c.SaveAs("fpix_hit_rate_disk3_minus.png");
  c.SaveAs("fpix_hit_rate_disk3_minus.pdf");
  c.SaveAs("fpix_hit_rate_disk3_minus.C");
  c.Clear();
  gSystem->Exec("mv fpix_hit_rate_disk3_minus.png Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk3_minus.pdf Hit_Rate_Plots");
  gSystem->Exec("mv fpix_hit_rate_disk3_minus.C Hit_Rate_Plots");
  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  BPIX hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_BPIX.Draw("AP");
  mg_hit_rate_BPIX.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_BPIX.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_BPIX.GetXaxis()->SetNoExponent();
  mg_hit_rate_BPIX.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_BPIX.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_BPIX.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_BPIX.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "BPIX");
  c.SetGrid();
  c.SaveAs("bpix_hit_rate.png");
  c.SaveAs("bpix_hit_rate.pdf");
  c.SaveAs("bpix_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv bpix_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv bpix_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv bpix_hit_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  BPIX layer 1 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_BPIX_layer1.Draw("AP");
  mg_hit_rate_BPIX_layer1.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_BPIX_layer1.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_BPIX_layer1.GetXaxis()->SetNoExponent();
  mg_hit_rate_BPIX_layer1.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_BPIX_layer1.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_BPIX_layer1.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer1.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_BPIX_layer1.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer1.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "BPIX layer 1");
  c.SetGrid();
  c.SaveAs("bpix_layer1_hit_rate.png");
  c.SaveAs("bpix_layer1_hit_rate.pdf");
  c.SaveAs("bpix_layer1_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv bpix_layer1_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer1_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer1_hit_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  BPIX layer 2 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_BPIX_layer2.Draw("AP");
  mg_hit_rate_BPIX_layer2.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_BPIX_layer2.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_BPIX_layer2.GetXaxis()->SetNoExponent();
  mg_hit_rate_BPIX_layer2.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_BPIX_layer2.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_BPIX_layer2.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer2.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_BPIX_layer2.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer2.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "BPIX layer 2");
  c.SetGrid();
  c.SaveAs("bpix_layer2_hit_rate.png");
  c.SaveAs("bpix_layer2_hit_rate.pdf");
  c.SaveAs("bpix_layer2_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv bpix_layer2_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer2_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer2_hit_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  BPIX layer 3 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_BPIX_layer3.Draw("AP");
  mg_hit_rate_BPIX_layer3.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_BPIX_layer3.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_BPIX_layer3.GetXaxis()->SetNoExponent();
  mg_hit_rate_BPIX_layer3.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_BPIX_layer3.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_BPIX_layer3.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer3.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_BPIX_layer3.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer3.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "BPIX layer 3");
  c.SetGrid();
  c.SaveAs("bpix_layer3_hit_rate.png");
  c.SaveAs("bpix_layer3_hit_rate.pdf");
  c.SaveAs("bpix_layer3_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv bpix_layer3_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer3_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer3_hit_rate.C Hit_Rate_Plots");

  //-----------------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++  BPIX layer 4 hit rate  ++++++++++++++++++++++++++++++++++++++++++++
  mg_hit_rate_BPIX_layer4.Draw("AP");
  mg_hit_rate_BPIX_layer4.GetXaxis()->SetTitle("Run Number");
  mg_hit_rate_BPIX_layer4.GetXaxis()->SetLabelSize(0.04);
  mg_hit_rate_BPIX_layer4.GetXaxis()->SetNoExponent();
  mg_hit_rate_BPIX_layer4.GetXaxis()->SetNdivisions(5);
  mg_hit_rate_BPIX_layer4.GetYaxis()->SetTitle("Hit Rate (Hz)");
  mg_hit_rate_BPIX_layer4.GetXaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer4.GetYaxis()->SetLabelSize(0.05);
  mg_hit_rate_BPIX_layer4.GetYaxis()->SetTitleSize(0.05);
  mg_hit_rate_BPIX_layer4.SetTitle("");
  top_right_Title.DrawLatexNDC(0.64, 0.94, "0T cosmic rays (2021)");
  detector.DrawLatexNDC(0.23, 0.83, "BPIX layer 4");
  c.SetGrid();
  c.SaveAs("bpix_layer4_hit_rate.png");
  c.SaveAs("bpix_layer4_hit_rate.pdf");
  c.SaveAs("bpix_layer4_hit_rate.C");
  c.Clear();
  gSystem->Exec("mv bpix_layer4_hit_rate.png Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer4_hit_rate.pdf Hit_Rate_Plots");
  gSystem->Exec("mv bpix_layer4_hit_rate.C Hit_Rate_Plots");

  //----------------------------------------------------------------------------------------------- 
      
  c.Close();
     
}
