if (count)
   {
    for (Row=1; Row<=count; Row++)
      {

       if (Row>1) asFC->RowCount++;
       asFC->Cells[0][Row]=IntToStr(Row);
       Ghost->ExtractValue(tmp,params[Row-1],"CH",0);
       asFC->Cells[1][Row]=AnsiString(tmp);
       asFC->Colors[2][Row]=RGB(0,0,0);
       Ghost->ExtractValue(tmp,params[Row-1],"N0",0);
       asFC->Cells[3][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"N1",0);
       asFC->Cells[4][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"N2",0);
       asFC->Cells[5][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"N3",0);
       asFC->Cells[6][Row]=AnsiString(tmp);

       asFC->Colors[8][Row] = RGB(255,255,153);
       asFC->Colors[10][Row] = RGB(255,255,153);
       asFC->Colors[11][Row] = RGB(255,255,153);
       asFC->Colors[12][Row] = RGB(255,255,153);
       asFC->Colors[13][Row] = RGB(255,255,153);

       asFC->Colors[7][Row]=RGB(0,0,0);
       Ghost->ExtractValue(tmp,params[Row-1],"DT",0);
       asFC->Cells[8][Row]=AnsiString(tmp);
       asFC->Colors[9][Row]=RGB(0,0,0);
       Ghost->ExtractValue(tmp,params[Row-1],"TR",0);
       asFC->Cells[12][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"BL",0);
       asFC->Cells[13][Row]=AnsiString(tmp);


       // Zone memoires a remplir
       Ghost->ExtractValue(tmp,params[Row-1],"lc",0);
       T_LLCC[pc][Row-1]=AnsiString(tmp);

       asFC->Cells[10][Row]=" ";
       asFC->Cells[11][Row]=" ";
       asFC->Cells[12][Row]=" ";
       asFC->Cells[13][Row]=" ";

       if (T_LLCC[pc][Row-1]=="L") asFC->Cells[10][Row]="X";
       if (T_LLCC[pc][Row-1]=="C") asFC->Cells[11][Row]="X";
       if (T_LLCC[pc][Row-1]=="T") asFC->Cells[12][Row]="X";
       if (T_LLCC[pc][Row-1]=="B") asFC->Cells[13][Row]="X";
       //j = Row-1;
       Ghost->ExtractValue(tmp,params[Row-1],"pol",0);
       T_POL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ct",0);
       T_CTEXT[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"it",0);
       T_TITAL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"bd",0);
       T_TBOLD[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ht",0);
       T_HAUTEUR[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"jh",0);
       T_JSH[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"jv",0);
       T_JSV[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"cb",0);
       T_CBKG[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"lg",0);
       T_TLARG[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ep1",0);
       T_LS1EP[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"cl1",0);
       T_LS1CL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ls2",0);
       T_LS2[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ep2",0);
       T_LS2EP[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"cl2",0);
       T_LS2CL[pc][Row-1]=AnsiString(tmp);
      }
   }
 