#include "TotalEvent.h"

TH1F *h1;
TH1F *h2;
TH1F *h3;
TH1F *h4;
TH1F *dummy;

Double_t
ftotal (Double_t * x, Double_t * par)
{

  Double_t xx = x[0];
  Int_t bin1 = h3->GetXaxis ()->FindBin (xx);	// Simulation 0%
  Int_t bin2 = h4->GetXaxis ()->FindBin (xx);	// Simulation 100%
//  if(xx==0) bin2 = 0;
  Int_t bin3 = dummy->GetXaxis ()->FindBin (xx);	// Prompt Peak
  Double_t ar = par[1] * (1 - par[0]) * h3->GetBinContent (bin1);	// p0 as Vacuum Yield
  Double_t br = par[1] * par[0] * h4->GetBinContent (bin2);	// p1 as Normalization
  Double_t cr = par[2] * dummy->GetBinContent (bin3);	// p2 as Peak Ratio of Porous/Suprasil

  return ar + br + cr;

}

void
TimeSpectrumFit ()
{

  gStyle->SetCanvasColor (0);
  gStyle->SetFrameBorderMode (0);
  gStyle->SetStatBorderSize (1);
  gStyle->SetFrameFillColor (0);
  gStyle->SetTitleFillColor (0);
  gStyle->SetOptFit (1111);

  TCanvas *c1 = new TCanvas ("c1", "c1");
  char run1418[100], run1419[100];
  char run1420[100], run1421[100], run1422[100], run1423[100], run1424[100],
    run1425[100], run1426[100], run1427[100], run1428[100], run1429[100];
  char run1430[100], run1431[100], run1432[100], run1433[100], run1434[100],
    run1435[100], run1436[100], run1437[100], run1438[100], run1439[100];
  char run1440[100], run1441[100], run1442[100], run1443[100], run1444[100],
    run1445[100], run1446[100], run1447[100], run1448[100], run1449[100];
  char run1450[100], run1451[100], run1452[100], run1453[100], run1454[100],
    run1455[100], run1456[100], run1457[100], run1458[100], run1459[100];
  char run1460[100], run1461[100], run1462[100], run1463[100], run1464[100];
  char run1631[100], run1632[100], run1633[100], run1634[100], run1635[100],
    run1636[100], run1637[100], run1638[100], run1639[100];
  char run1640[100], run1641[100], run1642[100], run1643[100], run1644[100],
    run1645[100], run1646[100], run1647[100], run1648[100], run1649[100];
  char run1650[100], run1651[100], run1652[100], run1653[100];


  sprintf (run1418, "run1418_B100G_T100K_E5keV.root");
  sprintf (run1419, "run1419_B100G_T100K_E14keV.root");
  sprintf (run1420, "run1420_B100G_T100K_E19keV.root");
  sprintf (run1421, "run1421_B100G_T250K_E5keV.root");
  sprintf (run1422, "run1422_B100G_T250K_E14keV.root");
  sprintf (run1423, "run1423_B100G_T250K_E19keV.root");
  sprintf (run1424, "run1424_B100G_T250K_E5keV.root");
  sprintf (run1425, "run1425_B100G_T174K_E5keV.root");
  sprintf (run1426, "run1426_B100G_T99K_E5keV.root");
  sprintf (run1427, "run1427_B100G_T49K_E5keV.root");
  sprintf (run1428, "run1428_B1498G_T50K_E14keV.root");
  sprintf (run1429, "run1429_B1498G_T50K_E5keV.root");
  sprintf (run1430, "run1430_B1498G_T250K_E5keV.root");
  sprintf (run1431, "run1431_B6G_T250K_E5keV.root");
  sprintf (run1432, "run1432_B6G_T250K_E19keV.root");
  sprintf (run1433, "run1433_B6G_T250K_E14keV.root");
  sprintf (run1434, "run1434_B6G_T175K_E5keV.root");
  sprintf (run1435, "run1435_B6G_T99K_E5keV.root");
  sprintf (run1436, "run1436_B6G_T50K_E5keV.root");
  sprintf (run1437, "run1437_B6G_T20K_E20keV.root");
  sprintf (run1438, "run1438_B6G_T20K_E14keV.root");
  sprintf (run1439, "run1439_B6G_T20K_E5keV.root");
  sprintf (run1440, "run1440_B6G_T20K_E19keV.root");
  sprintf (run1441, "run1441_B6G_T250K_E2keV.root");
  sprintf (run1442, "run1442_B6G_T250K_E2keV.root");
  sprintf (run1443, "run1443_B100G_T250K_E2keV.root");
  sprintf (run1444, "run1444_B100G_T250K_E14keV.root");
  sprintf (run1445, "run1445_B6G_T250K_E5keV.root");
  sprintf (run1446, "run1446_B6G_T74K_E5keV.root");
  sprintf (run1447, "run1447_B6G_T49K_E5keV.root");
  sprintf (run1448, "run1448_B100G_T250K_E5keV.root");
  sprintf (run1449, "run1449_B100G_T250K_E3keV.root");
  sprintf (run1450, "run1450_B100G_T250K_E10keV.root");
  sprintf (run1451, "run1451_B100G_T250K_E14keV.root");
  sprintf (run1452, "run1452_B6G_T250K_E3keV.root");
  sprintf (run1453, "run1453_B6G_T250K_E5keV.root");
  sprintf (run1454, "run1454_B6G_T250K_E10keV.root");
  sprintf (run1455, "run1455_B6G_T250K_E14keV.root");
  sprintf (run1456, "run1456_B6G_T100K_E3keV.root");
  sprintf (run1457, "run1457_B6G_T100K_E5keV.root");
  sprintf (run1458, "run1458_B6G_T250K_E6keV.root");
  sprintf (run1459, "run1459_B6G_T174K_E3keV.root");
  sprintf (run1460, "run1460_B6G_T175K_E2keV.root");
  sprintf (run1461, "run1461_B6G_T175K_E5keV.root");
  sprintf (run1462, "run1462_B6G_T175K_E5keV.root");
  sprintf (run1463, "run1463_B6G_T49K_E5keV.root");
  sprintf (run1464, "run1464_B6G_T50K_E3keV.root");
  sprintf (run1631, "run1631_B100G_T49K_E5keV.root");
  sprintf (run1632, "run1632_B100G_T50K_E14keV.root");
  sprintf (run1633, "run1633_B100G_T50K_E19keV.root");
  sprintf (run1634, "run1634_B5G_T50K_E5keV.root");
  sprintf (run1635, "run1635_B6G_T50K_E14keV.root");
  sprintf (run1636, "run1636_B5G_T50K_E19keV.root");
  sprintf (run1637, "run1637_B6G_T100K_E5keV.root");
  sprintf (run1638, "run1638_B6G_T100K_E14keV.root");
  sprintf (run1639, "run1639_B6G_T100K_E19keV.root");
  sprintf (run1640, "run1640_B6G_T175K_E5keV.root");
  sprintf (run1641, "run1641_B6G_T175K_E14keV.root");
  sprintf (run1642, "run1642_B6G_T175K_E19keV.root");
  sprintf (run1643, "run1643_B6G_T250K_E5keV.root");
  sprintf (run1644, "run1644_B6G_T250K_E14keV.root");
  sprintf (run1645, "run1645_B6G_T250K_E19keV.root");
  sprintf (run1646, "run1646_B100G_T250K_E5keV.root");
  sprintf (run1647, "run1647_B6G_T270K_E5keV.root");
  sprintf (run1648, "run1648_B6G_T270K_E14keV.root");
  sprintf (run1649, "run1649_B6G_T270K_E19keV.root");
  sprintf (run1650, "run1650_B33G_T270K_E19keV.root");
  sprintf (run1651, "run1651_B6G_T19K_E19keV.root");
  sprintf (run1652, "run1652_B6G_T20K_E14keV.root");
  sprintf (run1653, "run1653_B6G_T20K_E5keV.root");

  char run_5keV[200], run_14keV[200], run_19keV[200];

  sprintf (run_5keV,
	   "mu+_cos_T250K_B0.0G_Offset4.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac0.root");
  sprintf (run_14keV,
	   "mu+_cos_T250K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac0.root");
  sprintf (run_19keV,
	   "mu+_cos_T250K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac0.root");

  char run_20K_5keV[200], run_20K_14keV[200], run_20K_19keV[200];
  char run_50K_5keV[200], run_50K_14keV[200], run_50K_19keV[200];
  char run_75K_5keV[200], run_75K_14keV[200], run_75K_19keV[200];
  char run_100K_5keV[200], run_100K_14keV[200], run_100K_19keV[200];
  char run_175K_5keV[200], run_175K_14keV[200], run_175K_19keV[200];
  char run_250K_5keV[200], run_250K_14keV[200], run_250K_19keV[200];

  sprintf (run_20K_5keV,
	   "Mu_cos_T20K_B0.0G_Offset0.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_20K_14keV,
	   "Mu_cos_T20K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_20K_19keV,
	   "Mu_cos_T20K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");

  sprintf (run_50K_5keV,
	   "Mu_cos_T50K_B0.0G_Offset0.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_50K_14keV,
	   "Mu_cos_T50K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_50K_19keV,
	   "Mu_cos_T50K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");

  sprintf (run_75K_5keV,
	   "Mu_cos_T75K_B0.0G_Offset0.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_75K_14keV,
	   "Mu_cos_T75K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_75K_19keV,
	   "Mu_cos_T75K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");

  sprintf (run_100K_5keV,
	   "Mu_cos_T100K_B0.0G_Offset0.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_100K_14keV,
	   "Mu_cos_T100K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_100K_19keV,
	   "Mu_cos_T100K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");

  sprintf (run_175K_5keV,
	   "Mu_cos_T175K_B0.0G_Offset0.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_175K_14keV,
	   "Mu_cos_T175K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_175K_19keV,
	   "Mu_cos_T175K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");

  sprintf (run_250K_5keV,
	   "Mu_cos_T250K_B0.0G_Offset4.0mm_FWHM23.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_250K_14keV,
	   "Mu_cos_T250K_B0.0G_Offset0.0mm_FWHM17.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");
  sprintf (run_250K_19keV,
	   "Mu_cos_T250K_B0.0G_Offset0.0mm_FWHM15.0mm_Polar1_Nose30.0mm_Nrun4_Fvac100.root");



  sprintf (run_14keV,
	//   "mu+_cos_T250K_B0.0G_Offset0.0mm_FWHM9.5mm_Polar1_Nose30.0mm_Nrun999_Fvac0.root");
	   "mu+_cos_T250K_B0.0G_Offset1.0mm_FWHM7.5mm_Polar1_Nose30.0mm_Nrun999_Fvac0.root");
  sprintf (run_250K_14keV,
	//  "Mu_cos_T250K_B0.0G_Offset0.0mm_FWHM9.5mm_Polar1_Nose30.0mm_Nrun999_Fvac100.root");
	   "Mu_cos_T250K_B0.0G_Offset1.0mm_FWHM7.5mm_Polar1_Nose30.0mm_Nrun999_Fvac100.root");

  char title1[100], title2[100], title3[100], title4[100];
  int n_pp=11;

  // F-sample (1418-1447), C-sample (1448-1464) and Suprasil (1631-1653)
  for (int run = 1422; run < 1423; ++run)
    {
    for (int pp = 10; pp < n_pp; ++pp)
 {
      if (run == 1418)
	{
	  sprintf (title1, run1637);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1418);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_100K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1419)
	{
	  sprintf (title1, run1638);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1419);	// title 2 : SiO2 Porous
	  sprintf (title3, run_14keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_100K_14keV);	// title 4 : Simulation 100%
	}

      if (run == 1420)
	{
	  sprintf (title1, run1639);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1420);	// title 2 : SiO2 Porous
	  sprintf (title3, run_19keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_100K_19keV);	// title 4 : Simulation 100%
	}

      if (run == 1421)
	{
	  sprintf (title1, run1646);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1421);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1422)
	{
	  sprintf (title1, run1644);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1422);	// title 2 : SiO2 Porous
	  sprintf (title3, run_14keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_14keV);	// title 4 : Simulation 100%
	}

      if (run == 1423)
	{
	  sprintf (title1, run1645);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1423);	// title 2 : SiO2 Porous
	  sprintf (title3, run_19keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_19keV);	// title 4 : Simulation 100%
	}

      if (run == 1424)
	{
	  sprintf (title1, run1646);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1424);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1425)
	{
	  sprintf (title1, run1640);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1425);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_175K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1426)
	{
	  sprintf (title1, run1637);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1426);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_100K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1427)
	{
	  sprintf (title1, run1634);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1427);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_50K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1428)
	{
	  sprintf (title1, run1635);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1428);	// title 2 : SiO2 Porous
	  sprintf (title3, run_14keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_50K_14keV);	// title 4 : Simulation 100%
	}

      if (run == 1429)
	{
	  sprintf (title1, run1634);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1429);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_50K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1430) continue;
      if (run == 1431)
	{
	  sprintf (title1, run1646);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1431);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1432)
	{
	  sprintf (title1, run1645);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1432);	// title 2 : SiO2 Porous
	  sprintf (title3, run_19keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_19keV);	// title 4 : Simulation 100%
	}

      if (run == 1433)
	{
	  sprintf (title1, run1644);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1433);	// title 2 : SiO2 Porous
	  sprintf (title3, run_14keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_14keV);	// title 4 : Simulation 100%
	}

      if (run == 1434)
	{
	  sprintf (title1, run1640);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1434);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_175K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1435)
	{
	  sprintf (title1, run1637);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1435);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_100K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1436)
	{
	  sprintf (title1, run1634);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1436);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_50K_5keV);	// title 4 : Simulation 100%
	}
      if (run == 1437) continue;

      if (run == 1438)
	{
	  sprintf (title1, run1652);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1438);	// title 2 : SiO2 Porous
	  sprintf (title3, run_14keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_20K_14keV);	// title 4 : Simulation 100%
	}

      if (run == 1439)
	{
	  sprintf (title1, run1653);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1439);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_20K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1440)
	{
	  sprintf (title1, run1651);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1440);	// title 2 : SiO2 Porous
	  sprintf (title3, run_19keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_20K_19keV);	// title 4 : Simulation 100%
	}

      if (run == 1441) continue;
      if (run == 1442) continue;
      if (run == 1443) continue;
      if (run == 1444)
	{
	  sprintf (title1, run1644);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1444);	// title 2 : SiO2 Porous
	  sprintf (title3, run_14keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_14keV);	// title 4 : Simulation 100%
	}

      if (run == 1445)
	{
	  sprintf (title1, run1646);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1445);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_250K_5keV);	// title 4 : Simulation 100%
	}
      if (run == 1446) 
	{
	  sprintf (title1, run1634);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1446);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_75K_5keV);	// title 4 : Simulation 100%
	}

      if (run == 1447)
	{
	  sprintf (title1, run1634);	// title 1 : SiO2 Suprasil
	  sprintf (title2, run1447);	// title 2 : SiO2 Porous
	  sprintf (title3, run_5keV);	// title 3 : Simulation 0%
	  sprintf (title4, run_50K_5keV);	// title 4 : Simulation 100%
	}

      TFile *f1 = new TFile(title1);
      TFile *f2 = new TFile(title2);
      TFile *f3 = new TFile(title3);
      TFile *f4 = new TFile(title4);

      h1 = (TH1F *) f1->FindObjectAny ("Forward");
      h2 = (TH1F *) f2->FindObjectAny ("Forward");
      h3 = (TH1F *) f3->FindObjectAny ("Forward");
      h4 = (TH1F *) f4->FindObjectAny ("Forward");

      h1->SetTitle (title1);
      h2->SetTitle (title2);
      h3->SetTitle (title3);
      h4->SetTitle (title4);

/*  cout << TotalEvent (h1) << endl;
  cout << TotalEvent (h2) << endl;
  cout << TotalEvent (h3) << endl;
  cout << TotalEvent (h4) << endl;
*/

      c1->Clear();
  if(pp==3){cout << title2 << endl;}

      c1->Clear();
      // fit the SiO2 suprasil time spectrum with exponential
      TF1 *fit1 = new TF1 ("fit1", "expo", 2.0, 4.0);
      h1->Fit ("fit1", "REMQN");

      double a0 = fit1->GetParameter (0);
      double a1 = fit1->GetParameter (1);

      // shape for mu+ decay in flight and backscattering 
      dummy = new TH1F ("dummy", "dummy", 1230, 0, 12);

      for (int i = 1; i < pp; i++)	// takes only the first 4 bins ~ 40 ns
	{			// subtract exponential decay from signal
	  dummy->SetBinContent (i,
				h1->GetBinContent (i) - exp (a0 +
							     a1 *
							     h1->GetBinCenter
							     (i)));
	}

      h2->GetXaxis ()->SetRangeUser (0, 12);
      h2->GetXaxis ()->SetTitle ("time (#mus)");
      h2->GetYaxis ()->SetTitle ("count/0.01#mus");
      h2->Sumw2 ();

      TF1 *ftot = new TF1 ("ftot", ftotal, 0.0, 12.0, 3);
      ftot->SetParName (0, "Vacuum Yield");
      ftot->SetParLimits (0, 0, 1);
      ftot->SetParameter (0, 0.2);
      ftot->SetParName (1, "Normalization");
      ftot->SetParameter (1, 0.05);
      ftot->SetParName (2, "Prompt ratio(Por/Sup)");
      ftot->SetParameter (2, 1);
      ftot->SetNpx (10000);
      // Fit SiO2 Porous with "Simulation 0%", "100%" and "SiO2 Suprasil Prompt Peak"
      h2->Fit ("ftot", "QREM");
      cout << "n_pp : "<<pp<<", Vacuum Yield is " << ftot->GetParameter (0) <<"("<<ftot->GetParError (0)<<")"
 << ", Chi2/NDF is "<< ftot->GetChisquare ()/ftot->GetNDF ()<< endl;
ftot->GetParError (0); 
      // Make an inset and show the early time part
      TPad *npad = new TPad ("npad", "", 0.26, 0.52, 0.61, 0.87);
      npad->Draw ();
      gPad->SetGridx (1);
      gPad->SetGridy (1);
      npad->cd ();

      TH1F *clone = (TH1F *) h2->Clone ("clone");
      clone->Draw ();
      clone->SetTitle ("0 to 0.2#mus");
      clone->GetXaxis ()->SetRangeUser (0, 0.2);;
      clone->SetStats (0);

      // Print output as an eps file
      strcat (title2, ".eps");
      cout<<title2<<endl;
      c1->Print (title2);

    }
}
}
