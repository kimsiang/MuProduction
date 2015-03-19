void
reprocess2012()
{

  gStyle->SetCanvasColor (0);
  gStyle->SetFrameBorderMode (0);
  gStyle->SetStatBorderSize (1);
  gStyle->SetFrameFillColor (0);
  gStyle->SetTitleFillColor (0);
  gStyle->SetOptFit (1111);

// Insert file name here
//char *name = "lem12_his_0556.root"; // Ag plate
  char name[100];
  int run = 576;
  cout <<
    "Please insert the run# of data that you want to analyze. Enter 0 and ENTER to quit!"
    << endl;
//  cin >> run;

  if (run == 0)
    {
      gROOT->ProcessLine (".q");
    }

  for (run = 3427; run < 3512; run++) // SiO2-f 3427-3429, SiO2-f14 3430-3453, SiO2-b 3454-3480, Ag 3481-351-3453, SiO2-b 3454-3480, Ag 3481-3511
    {

      if (run < 1000)
	{
	  sprintf (name, "../../musrfit/data/lem12_his_0%u.root", run);
	}
      if (run > 1000)
	{
	  sprintf (name, "../../musrfit/data/lem12_his_%u.root", run);
	}

      TFile *f1 = new TFile (name);

      cout <<
	"                                                                  "
	<< endl;
      cout <<
	"------------------------------------------------------------------"
	<< endl;
      cout << "## Reading rootfile with the name......" << name << " ##" <<
	endl;
      cout <<
	"------------------------------------------------------------------"
	<< endl;

      cout << "## Looking for histos" << endl;
      TFolder *histos = (TFolder *) (f1->FindObjectAny ("histos"));
      histos->GetListOfFolders ()->Print ();
      cout <<
	"------------------------------------------------------------------"
	<< endl;

      cout << "## Looking for RunHeader" << endl;
      TFolder *runheader = (TFolder *) (f1->FindObjectAny ("RunHeader"));
      runheader->GetListOfFolders ()->Print ();

      cout <<
	"------------------------------------------------------------------"
	<< endl;
      cout << "## End of reading file ##" << endl;
      TObjArray *runsummary =
	(TObjArray *) (runheader->FindObjectAny ("RunSummary"));
//runsummary->Dump();
      int t0;
      double Bfield;
      double Temp;
      double Eplant;

      int n = runsummary->GetEntries ();
      cout << "nentries : " << n << endl;
      for (int i = 0; i < n; i++)
	{
//if(i>4&&i<53){continue;}
//if(i>66){continue;}

	  TObject *object = runsummary->At (i);
cout<<"object : "<<object->GetName();
//      cout << object->GetName ();
	  char *t = object->GetName ();
	  string str = object->GetName ();
	  if (i == 3)
	    {
	      int c = str.find ("T=");
	      int d = str.find ("(K)");
	      int a = str.find ("B=~");
	      int b = str.find ("(G)");
	      int e = str.find ("E=");
	      int fi = str.find ("(keV)");

// find temperature
	      string s1 (t, c + 2, d - c - 1);
	      Temp = atoi (s1.c_str ());
	      cout << "Temp : " << Temp << " K" << endl;

// find magnetic field
	      string s2 (t, a + 3, b - a - 2);
	      Bfield = atoi (s2.c_str ());
	      cout << "Bfield : " << Bfield << " G" << endl;

// find E implantation
	      string s3 (t, e + 2, fi - e - 2);
	      Eplant = atoi (s3.c_str ());
	      cout << "Eplant : " << Eplant << " keV" << endl;
	    }


// then find t0 of each run
// with correction for 16mm nearer nose
//	  int corr =
//	    16 / (sqrt (2 * Eplant / 105600) * 3 * 10 ** 2 * 0.1953125);
  int corr = 18;
//cout<<"corr : "<<corr<<endl;

	  if (i == 66)
	    {
	      string s5 (t, 28, 4);
//	      t0 = atoi (s5.c_str ()) ;
	      t0 = atoi (s5.c_str ()) - corr;
	      cout << "t0 : " << t0 << " ch" << endl;
	    }

	}

      cout <<
	"------------------------------------------------------------------"
	<< endl;
//gROOT->ProcessLine(".q");

//pre pile up rejection
      TH1F *h1;
      TH1F *h2;
      TH1F *h3;
      TH1F *h4;
      TH1F *h5;
      TH1F *h6;
      TH1F *h7;
      TH1F *h8;

//post pile up rejection
      TH1F *h21;
      TH1F *h22;
      TH1F *h23;
      TH1F *h24;
      TH1F *h25;
      TH1F *h26;
      TH1F *h27;
      TH1F *h28;

      h1 = (TH1F *) histos->FindObjectAny ("hDecay001");
      h2 = (TH1F *) histos->FindObjectAny ("hDecay002");
      h3 = (TH1F *) histos->FindObjectAny ("hDecay003");
      h4 = (TH1F *) histos->FindObjectAny ("hDecay004");
      h5 = (TH1F *) histos->FindObjectAny ("hDecay005");
      h6 = (TH1F *) histos->FindObjectAny ("hDecay006");
      h7 = (TH1F *) histos->FindObjectAny ("hDecay007");
      h8 = (TH1F *) histos->FindObjectAny ("hDecay008");

      h21 = (TH1F *) histos->FindObjectAny ("hDecay021");
      h22 = (TH1F *) histos->FindObjectAny ("hDecay022");
      h23 = (TH1F *) histos->FindObjectAny ("hDecay023");
      h24 = (TH1F *) histos->FindObjectAny ("hDecay024");
      h25 = (TH1F *) histos->FindObjectAny ("hDecay025");
      h26 = (TH1F *) histos->FindObjectAny ("hDecay026");
      h27 = (TH1F *) histos->FindObjectAny ("hDecay027");
      h28 = (TH1F *) histos->FindObjectAny ("hDecay028");

      double Bin=2600; 

      TH1F *plot1 =
	new TH1F ("Forward_Full", "Forward_Full", Bin, -1.0, 12.0);
      TH1F *plot2 =
	new TH1F ("Backward_Full", "Backward_Full", Bin, -1.0, 12.0);
      TH1F *plot3 =
	new TH1F ("Forward_Left_Full", "Forward_Left_Full", Bin, -1.0, 12.0);
      TH1F *plot4 =
	new TH1F ("Forward_Top_Full", "Forward_Top_Full", Bin, -1.0, 12.0);
      TH1F *plot5 =
	new TH1F ("Forward_Right_Full", "Forward_Right_Full", Bin, -1.0,
		  12.0);
      TH1F *plot6 =
	new TH1F ("Forward_Bottom_Full", "Forward_Bottom_Full", Bin, -1.0,
		  12.0);
      TH1F *plot7 =
	new TH1F ("Backward_Left_Full", "Backward_Left_Full", Bin, -1.0,
		  12.0);
      TH1F *plot8 =
	new TH1F ("Backward_Top_Full", "Backward_Top_Full", Bin, -1.0, 12.0);
      TH1F *plot9 =
	new TH1F ("Backward_Right_Full", "Backward_Right_Full", Bin, -1.0,
		  12.0);
      TH1F *plot10 =
	new TH1F ("Backward_Bottom_Full", "Backward_Bottom_Full", Bin, -1.0,
		  12.0);

      for (int i = 1; i < 66601; i++)
	{
//for(int i=t0;i<x;i++){

	  int y1 = h21->GetBinContent (i);
	  int y2 = h22->GetBinContent (i);
	  int y3 = h23->GetBinContent (i);
	  int y4 = h24->GetBinContent (i);
	  int y5 = h25->GetBinContent (i);
	  int y6 = h26->GetBinContent (i);
	  int y7 = h27->GetBinContent (i);
	  int y8 = h28->GetBinContent (i);
	  double time = (i - t0) * 0.1951325 / 1000;
//cout<<"time : "<<time<<", corrected time : "<<time/exp(-time/2.2)<<", bin content : "<<y<<endl;
	  for (int j = 0; j < y1; j++)
	    {
	      plot1->Fill (time);
	      plot3->Fill (time);
	    }
	  for (int j = 0; j < y2; j++)
	    {
	      plot1->Fill (time);
	      plot4->Fill (time);
	    }
	  for (int j = 0; j < y3; j++)
	    {
	      plot1->Fill (time);
	      plot5->Fill (time);
	    }
	  for (int j = 0; j < y4; j++)
	    {
	      plot1->Fill (time);
	      plot6->Fill (time);
	    }
	  for (int k = 0; k < y5; k++)
	    {
	      plot2->Fill (time);
	      plot7->Fill (time);
	    }
	  for (int k = 0; k < y6; k++)
	    {
	      plot2->Fill (time);
	      plot8->Fill (time);
	    }
	  for (int k = 0; k < y7; k++)
	    {
	      plot2->Fill (time);
	      plot9->Fill (time);
	    }
	  for (int k = 0; k < y8; k++)
	    {
	      plot2->Fill (time);
             plot10->Fill (time);
	    }
	}


      TF1 *findbg1 = new TF1 ("findbg1", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg2 = new TF1 ("findbg2", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg3 = new TF1 ("findbg3", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg4 = new TF1 ("findbg4", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg5 = new TF1 ("findbg5", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg6 = new TF1 ("findbg6", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg7 = new TF1 ("findbg7", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg8 = new TF1 ("findbg8", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg9 = new TF1 ("findbg9", "[0]+expo(1)", 10., 12.2);
      TF1 *findbg10 = new TF1 ("findbg10", "[0]+expo(1)", 10., 12.2);
/*
      TF1 *findbg1 = new TF1 ("findbg1", "expo", 10., 12.2);
      TF1 *findbg2 = new TF1 ("findbg2", "expo", 10., 12.2);
      TF1 *findbg3 = new TF1 ("findbg3", "expo", 10., 12.2);
      TF1 *findbg4 = new TF1 ("findbg4", "expo", 10., 12.2);
      TF1 *findbg5 = new TF1 ("findbg5", "expo", 10., 12.2);
      TF1 *findbg6 = new TF1 ("findbg6", "expo", 10., 12.2);
      TF1 *findbg7 = new TF1 ("findbg7", "expo", 10., 12.2);
      TF1 *findbg8 = new TF1 ("findbg8", "expo", 10., 12.2);
      TF1 *findbg9 = new TF1 ("findbg9", "expo", 10., 12.2);
      TF1 *findbg10 = new TF1 ("findbg10", "expo", 10., 12.2);
*/

      findbg1->SetParLimits(0,0,40);
      findbg2->SetParLimits(0,0,40);
      findbg3->SetParLimits(0,0,10);
      findbg4->SetParLimits(0,0,10);
      findbg5->SetParLimits(0,0,10);
      findbg6->SetParLimits(0,0,10);
      findbg7->SetParLimits(0,0,10);
      findbg8->SetParLimits(0,0,10);
      findbg9->SetParLimits(0,0,10);
      findbg10->SetParLimits(0,0,10);

      findbg1->FixParameter(2,-0.455);
      findbg2->FixParameter(2,-0.455);
      findbg3->FixParameter(2,-0.455);
      findbg4->FixParameter(2,-0.455);
      findbg5->FixParameter(2,-0.455);
      findbg6->FixParameter(2,-0.455);
      findbg7->FixParameter(2,-0.455);
      findbg8->FixParameter(2,-0.455);
      findbg9->FixParameter(2,-0.455);
      findbg10->FixParameter(2,-0.455);

      plot1->Fit (findbg1, "REMNQ");
      plot2->Fit (findbg2, "REMNQ");
      plot3->Fit (findbg3, "REMNQ");
      plot4->Fit (findbg4, "REMNQ");
      plot5->Fit (findbg5, "REMNQ");
      plot6->Fit (findbg6, "REMNQ");
      plot7->Fit (findbg7, "REMNQ");
      plot8->Fit (findbg8, "REMNQ");
      plot9->Fit (findbg9, "REMNQ");
      plot10->Fit (findbg10, "REMNQ");
//  cout<<"bg1 : "<<findbg1->GetParameter(0)<<endl;
//  cout<<"bg2 : "<<findbg2->GetParameter(0)<<endl;

      double bg1 = findbg1->GetParameter (0);
      double bg2 = findbg2->GetParameter (0);
      double bg3 = findbg3->GetParameter (0);
      double bg4 = findbg4->GetParameter (0);
      double bg5 = findbg5->GetParameter (0);
      double bg6 = findbg6->GetParameter (0);
      double bg7 = findbg7->GetParameter (0);
      double bg8 = findbg8->GetParameter (0);
      double bg9 = findbg9->GetParameter (0);
      double bg10 = findbg10->GetParameter (0);

      cout << "bg1 : " << bg1 << ", tau1 : " << -1/findbg1->GetParameter (2) << endl;
      cout << "bg2 : " << bg2 << ", tau2 : " << -1/findbg2->GetParameter (2) << endl;

    for (int i = 1; i < Bin+1; i++)
	{
	  plot1->SetBinContent (i, plot1->GetBinContent (i) - bg1);
	  plot2->SetBinContent (i, plot2->GetBinContent (i) - bg2);
	  plot3->SetBinContent (i, plot3->GetBinContent (i) - bg3);
	  plot4->SetBinContent (i, plot4->GetBinContent (i) - bg4);
	  plot5->SetBinContent (i, plot5->GetBinContent (i) - bg5);
	  plot6->SetBinContent (i, plot6->GetBinContent (i) - bg6);
	  plot7->SetBinContent (i, plot7->GetBinContent (i) - bg7);
	  plot8->SetBinContent (i, plot8->GetBinContent (i) - bg8);
	  plot9->SetBinContent (i, plot9->GetBinContent (i) - bg9);
         plot10->SetBinContent (i, plot10->GetBinContent (i) - bg10);
        }	

      int bin = 2400;

// musr spectrum fitting
      TH1F *Forward_Left =
	new TH1F ("Forward_Left", "Forward_Left", bin, 0, 12.0);
      TH1F *Forward_Top =
	new TH1F ("Forward_Top", "Forward_Top", bin, 0, 12.0);
      TH1F *Forward_Right =
	new TH1F ("Forward_Right", "Forward_Right", bin, 0, 12.0);
      TH1F *Forward_Bottom =
	new TH1F ("Forward_Bottom", "Forward_Bottom", bin, 0, 12.0);
      TH1F *Backward_Left =
	new TH1F ("Backward_Left", "Backward_Left", bin, 0, 12.0);
      TH1F *Backward_Top =
	new TH1F ("Backward_Top", "Backward_Top", bin, 0, 12.0);
      TH1F *Backward_Right =
	new TH1F ("Backward_Right", "Backward_Right", bin, 0, 12.0);
      TH1F *Backward_Bottom =
	new TH1F ("Backward_Bottom", "Backward_Bottom", bin, 0, 12.0);

      TH1F *Forward = new TH1F ("Forward", "Forward", bin, 0, 12.0);
      TH1F *Backward = new TH1F ("Backward", "Backward", bin, 0, 12.0);

      TH1F *Forward_AsymLR = new TH1F ("Forward_AsymLR", "Forward_AsymLR", bin, 0, 12.0);
      TH1F *Forward_AsymTB = new TH1F ("Forward_AsymTB", "Forward_AsymTB", bin, 0, 12.0);
      TH1F *Backward_AsymLR = new TH1F ("Backward_AsymLR", "Backward_AsymLR", bin, 0, 12.0);
      TH1F *Backward_AsymTB = new TH1F ("Backward_AsymTB", "Backward_AsymTB", bin, 0, 12.0);
      
      TH1F *AsymLR = new TH1F ("AsymLR", "AsymLR", bin, 0, 12.0);
      TH1F *AsymTB = new TH1F ("AsymTB", "AsymTB", bin, 0, 12.0);
      
      TH1F *AsymFB = new TH1F ("AsymFB", "AsymFB", bin, 0, 12.0);
  
      for (int i = t0; i < 66601; i++)
	{

	  int y1 = h21->GetBinContent (i);
	  int y2 = h22->GetBinContent (i);
	  int y3 = h23->GetBinContent (i);
	  int y4 = h24->GetBinContent (i);
	  int y5 = h25->GetBinContent (i);
	  int y6 = h26->GetBinContent (i);
	  int y7 = h27->GetBinContent (i);
	  int y8 = h28->GetBinContent (i);


	  double time = (i - t0) * 0.1951325 / 1000;

//      cout<<"time: "<<time<<"y1-y4: "<<y1+y2+y3+y4<<"y5-y8: "<<y5+y6+y7+y8<<endl;

	  for (int k = 0; k < y1; k++)
	    {
	      Forward_Left->Fill (time);
	    }
	  for (int k = 0; k < y2; k++)
	    {
	      Forward_Top->Fill (time);
	    }
	  for (int k = 0; k < y3; k++)
	    {
	      Forward_Right->Fill (time);
	    }
	  for (int k = 0; k < y4; k++)
	    {
	      Forward_Bottom->Fill (time);
	    }
	  for (int k = 0; k < y5; k++)
	    {
	      Backward_Left->Fill (time);
	    }
	  for (int k = 0; k < y6; k++)
	    {
	      Backward_Top->Fill (time);
	    }
	  for (int k = 0; k < y7; k++)
	    {
	      Backward_Right->Fill (time);
	    }
	  for (int k = 0; k < y8; k++)
	    {
	      Backward_Bottom->Fill (time);
	    }

	  // fill "calibrated" forward and backward

	  for (int k = 0; k < y1 + y2 + y3 + y4; k++)
	    {
	      Forward->Fill (time);
	    }

	  for (int k = 0; k < y5 + y6 + y7 + y8; k++)
	    {
	      Backward->Fill (time);
	    }

	}

      for (int i = 1; i < bin+1; i++)
	{
	  Forward->SetBinContent (i, Forward->GetBinContent (i) - bg1);
	  Backward->SetBinContent (i, Backward->GetBinContent (i) - bg2);
	  Forward_Left->SetBinContent (i, Forward_Left->GetBinContent (i) - bg3);
	  Forward_Top->SetBinContent (i, Forward_Top->GetBinContent (i) - bg4);
	  Forward_Right->SetBinContent (i, Forward_Right->GetBinContent (i) - bg5);
	  Forward_Bottom->SetBinContent (i, Forward_Bottom->GetBinContent (i) - bg6);
	  Backward_Left->SetBinContent (i, Backward_Left->GetBinContent (i) - bg7);
	  Backward_Top->SetBinContent (i, Backward_Top->GetBinContent (i) - bg8);
	  Backward_Right->SetBinContent (i, Backward_Right->GetBinContent (i) - bg9);
	  Backward_Bottom->SetBinContent (i, Backward_Bottom->GetBinContent (i) - bg10);
	 
          double FL = Forward_Left->GetBinContent(i); 
          double FR = Forward_Right->GetBinContent(i); 
          double FT = Forward_Top->GetBinContent(i); 
          double FB = Forward_Bottom->GetBinContent(i); 
          Forward_AsymLR->SetBinContent(i,(FL-FR)/(FL+FR));
          Forward_AsymLR->SetBinError(i,2*sqrt(FL*FR/pow(FL+FR,3)));
          Forward_AsymTB->SetBinContent(i,(FT-FB)/(FT+FB));
          Forward_AsymTB->SetBinError(i,2*sqrt(FT*FB/pow(FT+FB,3)));
         
          double BL = Backward_Left->GetBinContent(i); 
          double BR = Backward_Right->GetBinContent(i); 
          double BT = Backward_Top->GetBinContent(i); 
          double BB = Backward_Bottom->GetBinContent(i); 
          Backward_AsymLR->SetBinContent(i,(BL-BR)/(BL+BR));
          Backward_AsymLR->SetBinError(i,2*sqrt(BL*BR/pow(BL+BR,3)));
          Backward_AsymTB->SetBinContent(i,(BT-BB)/(BT+BB));
          Backward_AsymTB->SetBinError(i,2*sqrt(BT*BB/pow(BT+BB,3)));
          
          double L=Forward_Left->GetBinContent(i)+Backward_Left->GetBinContent(i);
	  double R=Forward_Right->GetBinContent(i)+Backward_Right->GetBinContent(i);
	  double T=Forward_Top->GetBinContent(i)+Backward_Top->GetBinContent(i);
	  double B=Forward_Bottom->GetBinContent(i)+Backward_Bottom->GetBinContent(i);
          AsymLR->SetBinContent(i,(L-R)/(L+R));
          AsymLR->SetBinError(i,2*sqrt(L*R/pow(L+R,3)));
          AsymTB->SetBinContent(i,(T-B)/(T+B));
          AsymTB->SetBinError(i,2*sqrt(T*B/pow(T+B,3)));
                
          double forward=FL+FR+FT+FB;
          double backward=BL+BR+BT+BB;
     //     cout<<"i="<<i<<", AsymFB : "<<(forward-backward)/(forward+backward)<<endl;
          AsymFB->SetBinContent(i,(forward-backward)/(forward+backward));
          AsymFB->SetBinError(i,2*sqrt(forward*backward/pow(forward+backward,3)));
        }

 
      AsymLR->SetLineColor(1);
      AsymLR->SetMarkerStyle(4);
      AsymTB->SetLineColor(1);
      AsymTB->SetMarkerStyle(4);
      AsymFB->SetLineColor(1);
      AsymFB->SetMarkerStyle(4);

      TF1 *asymfit = new TF1 ("asymfit", "[0]*cos(2*3.1419*[1]*x*0.0135538817+[2]*3.1419/180)*exp(-[3]*x)+[4]*cos([5]*x*2*3.1419*0.0135538817*102.88+[6]*3.1419/180)*exp(-[7]*x)", 0.05, 8.0);
 
      asymfit->SetParNames("Asym1","field1","phase1","rate1","Asym2","field2","phase2","rate2");
      asymfit->SetParLimits(0,0,0.2);
      asymfit->SetParameter(0,0.12);
      asymfit->FixParameter(1,Bfield);
      asymfit->SetParLimits(2,-180,180);
      asymfit->SetParameter(2,0);
      asymfit->SetParLimits(3,0.,1);
      asymfit->SetParameter(3,0.05);
      asymfit->SetParLimits(4,0.,0.2);
      asymfit->SetParameter(4,0.03);
      asymfit->FixParameter(5,Bfield);
      asymfit->SetParLimits(6,-180,180);
      asymfit->FixParameter(6,0);
      asymfit->SetParLimits(7,0.,1);
      asymfit->SetParameter(7,0.2);
      AsymLR->Fit(asymfit,"RQEMN");     

      ofstream examplefile("output.txt",ios::app);
  
  if (examplefile.is_open())
  {
    examplefile << run <<" "<<
    Temp<<" "<<
    Bfield<<" "<<
    Eplant<<" "<<
    asymfit->GetParameter(0)<<" "<< 
    asymfit->GetParameter(1)<<" "<< 
    asymfit->GetParameter(2)<<" "<< 
    asymfit->GetParameter(3)<<" "<< 
    asymfit->GetParameter(4)<<" "<< 
    asymfit->GetParameter(5)<<" "<< 
    asymfit->GetParameter(6)<<" "<< 
    asymfit->GetParameter(7)<<'\n'; 
   

   examplefile.close();
  }


 
      // write all the histogram into rootfile 
      char naming[60];
      sprintf (naming, "run%u_B%uG_T%uK_E%ukeV.root", run, Bfield, Temp, Eplant);
      TFile *treefile = new TFile (naming, "recreate");

      treefile->mkdir ("rawdata");
      treefile->cd ("rawdata");

      h1->Write ();
      h2->Write ();
      h3->Write ();
      h4->Write ();
      h5->Write ();
      h6->Write ();
      h7->Write ();
      h8->Write ();

      treefile->mkdir ("pileuprejection");
      treefile->cd ("pileuprejection");

      h21->Write ();
      h22->Write ();
      h23->Write ();
      h24->Write ();
      h25->Write ();
      h26->Write ();
      h27->Write ();
      h28->Write ();

      treefile->mkdir ("timespec");
      treefile->cd ("timespec");

      Forward_Left->Write ();
      Forward_Top->Write ();
      Forward_Right->Write ();
      Forward_Bottom->Write ();
      Backward_Left->Write ();
      Backward_Top->Write ();
      Backward_Right->Write ();
      Backward_Bottom->Write ();
      Forward->Write ();
      Backward->Write ();

      treefile->mkdir ("timespec_full");
      treefile->cd ("timespec_full");
      plot1->Write ();
      plot2->Write ();
      plot3->Write ();
      plot4->Write ();
      plot5->Write ();
      plot6->Write ();
      plot7->Write ();
      plot8->Write ();
      plot9->Write ();
      plot10->Write ();

      treefile->mkdir ("asymmetry");
      treefile->cd ("asymmetry");
      Forward_AsymLR->Write ();
      Forward_AsymTB->Write ();
      Backward_AsymLR->Write ();
      Backward_AsymTB->Write ();
      AsymLR->Write ();
      AsymTB->Write ();
      AsymFB->Write ();
      
      // add run summary
      TObjArray *objarray = new TObjArray (300);
      for (int i = 0; i < n; i++)
	{
	  TObject *object = runsummary->At (i);
	  objarray->Add (object);
	}
      treefile->mkdir ("runsummary");
      treefile->cd ("runsummary");
      objarray->Write ();

      treefile->Write ();
      treefile->Close ();

      cout << "End of processing run " << run << endl;
//gROOT->ProcessLine(".x plot.C");
    }

}
