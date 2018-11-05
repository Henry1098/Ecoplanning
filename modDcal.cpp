//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modDcal.h"
#include "modJust.h"
#include "globals.h"
#include "modHelp.h"
#include "modUnitForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TFDcal *FDcal;
//---------------------------------------------------------------------------
__fastcall TFDcal::TFDcal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDcal::Button1Click(TObject *Sender)
{
  int val;char tmp[50]; AnsiString s;

 //  il faut juste affecter les variables liees au calendrier
 s=avh->Cells[1][1];
 if (s=="O") P_ECHH[pc]="O"; else P_ECHH[pc]="N";
 P_UNIT1[pc]=avh->Cells[2][1];
 P_FORMATCAL1[pc]=avh->Cells[3][1];
 P_FREQ1[pc]=avh->Cells[4][1];
 PF[pc][9]=avh->Cells[5][1];
 strcpy(tmp,avh->Cells[6][1].c_str()); val=atoi(tmp);
 PC[pc][9]=TColor(val);
 s=avh->Cells[7][1];
 if (s=="Italique") PN[pc][9]="Italique"; else PN[pc][9]="Standard";
 s=avh->Cells[8][1];
 if (s=="Gras") PX[pc][9]="Gras"; else PX[pc][9]="Standard";
 strcpy(tmp,avh->Cells[9][1].c_str()); val=atoi(tmp);
 PH[pc][9]=val;
 strcpy(tmp,avh->Cells[10][1].c_str()); val=atoi(tmp);
 PB[pc][9]=TColor(val);
 s=avh->Cells[11][1];
 if (s=="Gauche") PJH[pc][9]="Gauche";
 else if (s=="Centre") PJH[pc][9]="Centre";
 else PJH[pc][9]="Droite";
 s=avh->Cells[12][1];
// if (s=="Haut") PJV[pc][9]='G';
// if (s=="Centre") PJV[pc][9]='C';
// else PJV[pc][9]='B';
 strcpy(tmp,avh->Cells[13][1].c_str()); val=atoi(tmp);
 PHH[pc][9]=val;
 s=avh->Cells[14][1];
 if (s=="O") PTYPE[pc][9]='O'; else PTYPE[pc][9]='N';

 s=avh->Cells[1][2];
 if (s=="O") P_ECHB[pc]="O"; else P_ECHB[pc]="N";
 P_UNIT2[pc]=avh->Cells[2][2];
 P_FORMATCAL2[pc]=avh->Cells[3][2];
 P_FREQ2[pc]=avh->Cells[4][2];
 PF[pc][10]=avh->Cells[5][2];
 strcpy(tmp,avh->Cells[6][2].c_str()); val=atoi(tmp);
 PC[pc][10]=TColor(val);
 s=avh->Cells[7][2];
 if (s=="Italique") PN[pc][10]="Italique"; else PN[pc][10]="Standard";
 s=avh->Cells[8][2];
 if (s=="Gras") PX[pc][10]="Gras"; else PX[pc][10]="Standard";
 strcpy(tmp,avh->Cells[9][2].c_str()); val=atoi(tmp);
 PH[pc][10]=val;
 strcpy(tmp,avh->Cells[10][2].c_str()); val=atoi(tmp);
 PB[pc][10]=TColor(val);
 s=avh->Cells[11][2];
 if (s=="Gauche") PJH[pc][10]="Gauche";
 else if (s=="Centre") PJH[pc][10]="Centre";
 else PJH[pc][10]="Droite";
 s=avh->Cells[12][2];
 if (s=="Haut") PJV[pc][10]='H';
 if (s=="Centre") PJV[pc][10]='C';
 else PJV[pc][10]='B';
 strcpy(tmp,avh->Cells[13][2].c_str()); val=atoi(tmp);
 PHH[pc][10]=val;
 s=avh->Cells[14][2];
 if (s=="O") PTYPE[pc][10]='O'; else PTYPE[pc][10]='N';

 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDcal::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall TFDcal::FillColor(int color,TImage *im)
{
 TRect Diagram;  TColor coul;

 coul=TColor(color);
 Diagram = Rect(0,0, im->Width,im->Height);
 im->Canvas->Brush->Color = coul; // BgColor;
 im->Canvas->FillRect(Diagram);
 im->Canvas->Pen->Color = clBlack;
 im->Canvas->MoveTo(0,0);
 im->Canvas->LineTo(0,im->Height-1);
 im->Canvas->LineTo(im->Width-1,im->Height-1);
 im->Canvas->LineTo(im->Width-1,0);
 im->Canvas->LineTo(0,0);

}



int __fastcall TFDcal::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{
 char tmp[250];
 char *p,*p1,*p2;
 int pos,l;

 result[0]=0;
 strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">");
 p = strstr(buff,tmp);
 l=0;
 if (p)
   {
    strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">");
    p1= strstr(buff,tmp);
    if (p1)
      {
       p2=p + strlen(tag)+2; l= p1-p2;
       strncpy(result,p2,l);
       result[l]=0;
      }
   }
 return l;
}




void __fastcall TFDcal::avhClickCell(TObject *Sender, int ARow, int ACol)
{
 //

 if (ARow==0) return;
 int X,Y; char tmp[500],temp[120];int lg;

 TFont *Fonte;
  int Color,cool;
  AnsiString Name;
  int Size;

  char bold[50],italic[50];
  TFontStyles  Style;
   TJust *Just;
   TFDUnitForm *UF;
  char unt[50],fmt[50];

 int cnt, hsize;

 cnt = avh->ColCount;
 OldRow=ARow; OldCol=ACol;
 if ((ARow<0) || (ARow >2)) return;

 if (ACol==0)
   {
    strcpy(tmp,avh->Cells[10][OldRow].c_str());
    cool=atoi(tmp);
    FillColor(cool,imBColor);
    strcpy(tmp,avh->Cells[6][OldRow].c_str());
    cool=atoi(tmp);
    FillColor(cool,imFColor);
    return;
   }



 if (ACol==1)
   {
    if (avh->Cells[ACol][ARow]=="O") avh->Cells[ACol][ARow]="N";
    else avh->Cells[ACol][ARow]="O";
   }

 if (ACol==14)
   {
    if (avh->Cells[ACol][ARow]=="O") avh->Cells[ACol][ARow]="N";
    else avh->Cells[ACol][ARow]="O";
   }

 if (OldCol>4 && OldCol<10)
   {
    
     FontDialog1->Options;
     strcpy(m_exchange,"");
     FontDialog1->Font->Name = avh->Cells[5][OldRow];
     FontDialog1->Font->Color = StrToInt(avh->Cells[6][OldRow]);
     FontDialog1->Font->Size = StrToInt(avh->Cells[9][OldRow]);

     if (avh->Cells[8][OldRow]=="Gras" && avh->Cells[7][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (avh->Cells[8][OldRow]=="Gras" && avh->Cells[7][OldRow]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (avh->Cells[8][OldRow]!="Gras" && avh->Cells[7][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles() << fsItalic;



     if (FontDialog1->Execute())
      { Fonte = FontDialog1->Font;
      Color = Fonte->Color;
      Size = Fonte->Size;
      Name = Fonte->Name;
      Style = Fonte->Style;
      // recherche si bold et italique

      if (Style.Contains(fsBold))  strcpy(bold,"Gras"); else strcpy(bold,"Standard");
      if (Style.Contains(fsItalic))  strcpy(italic,"Italique"); else strcpy(italic,"Standard");
      
      avh->Cells[5][OldRow]=Name;
      avh->Cells[6][OldRow]=AnsiString(Color);
      avh->Cells[7][OldRow]=AnsiString(italic);
      avh->Cells[8][OldRow]=AnsiString(bold);
      avh->Cells[9][OldRow]=AnsiString(Size);

      hsize = Size*14/10;
      avh->Cells[13][OldRow] = AnsiString(hsize);



       strcpy(tmp,avh->Cells[6][OldRow].c_str());
       cool=atoi(tmp);
       FillColor(cool,imFColor);
     }
  }

 if (OldCol==10)
   {
    ColorDialog1->Color = PC[pc][10];
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      avh->Cells[10][OldRow]=AnsiString(Color);
      strcpy(tmp,avh->Cells[10][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imBColor);
      PC[pc][10]=cool;
    }
   }

  if (OldCol==11)
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,avh->Cells[11][OldRow].c_str());
    strcat(m_exchange,"</jh>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        ExtractValue(tmp,m_exchange,"jh",0);
        avh->Cells[11][OldRow]=AnsiString(tmp);

      }

    delete Just;
   }

   if (OldCol==12)
   {

    strcpy(m_exchange,"<jv>"); strcat(m_exchange,avh->Cells[12][OldRow].c_str());
    strcat(m_exchange,"</jv>");
    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        
        ExtractValue(tmp,m_exchange,"jv",0);
        avh->Cells[12][OldRow]=AnsiString(tmp);
      }

    delete Just;
   }

 


   if ((OldCol==2) || (OldCol==3))
   {
    strcpy(m_exchange,"<unit>");
    if (OldRow==1) strcat(m_exchange,avh->Cells[2][1].c_str());
    else strcat(m_exchange,avh->Cells[2][2].c_str());
    strcat(m_exchange,"</unit>");
    strcat(m_exchange,"<form>");
    if (OldRow==1) strcat(m_exchange,avh->Cells[3][1].c_str());
    else strcat(m_exchange,avh->Cells[3][2].c_str());
    strcat(m_exchange,"</form>");

    UF = new TFDUnitForm(Application);
    UF->ShowModal();
    delete UF;
    if (strlen(m_exchange))
     {
      ExtractValue(unt,m_exchange,"unit",0);
      ExtractValue(fmt,m_exchange,"form",0);
      avh->Cells[2][OldRow]=AnsiString(unt);
      avh->Cells[3][OldRow]=AnsiString(fmt);

     }


   }

}
//---------------------------------------------------------------------------


void __fastcall TFDcal::FormShow(TObject *Sender)
{
// Mettre les données dans les deux Row
 avh->Cells[1][1] = P_ECHH[pc];
 avh->Cells[2][1] = P_UNIT1[pc];
 avh->Cells[3][1] = P_FORMATCAL1[pc];
 avh->Cells[4][1] = P_FREQ1[pc];
 avh->Cells[5][1] = PF[pc][9];
 avh->Cells[6][1] = PC[pc][9];
 if (PN[pc][9]=="Italique") avh->Cells[7][1]="Italique"; else avh->Cells[7][1]="Standard";
 if (PX[pc][9]=="Gras") avh->Cells[8][1]="Gras"; else avh->Cells[8][1]="Standard";
 avh->Cells[9][1] = PH[pc][9];
 avh->Cells[10][1] = PB[pc][9];
 if (PJH[pc][9]=="Gauche") avh->Cells[11][1]="Gauche";
 else if (PJH[pc][9]=="Centre") avh->Cells[11][1]="Centre";
 else avh->Cells[11][1]="Droite";
 if (PJV[pc][9]=="Haut") avh->Cells[12][1]="Haut";
 else if (PJH[pc][9]=="Centre") avh->Cells[12][1]="Centre";
 else avh->Cells[12][1]="Bas";
 avh->Cells[13][1] = PHH[pc][9];
 avh->Cells[14][1] = PTYPE[pc][9];  // PTYPE pour stocker LSep ou non (O/N)

 avh->Cells[1][2] = P_ECHB[pc];
 avh->Cells[2][2] = P_UNIT2[pc];
 avh->Cells[3][2] = P_FORMATCAL2[pc];
 avh->Cells[4][2] = P_FREQ2[pc];
 avh->Cells[5][2] = PF[pc][10];
 avh->Cells[6][2] = PC[pc][10];
 if (PN[pc][10]=="Standard") avh->Cells[7][2]="Standard"; else avh->Cells[7][2]="Italique";
 if (PX[pc][10]=="Standard") avh->Cells[8][2]="Standard"; else avh->Cells[8][2]="Gras";
 avh->Cells[9][2] = PH[pc][10];
 avh->Cells[10][2] = PB[pc][10];
 if (PJH[pc][10]=="Gauche") avh->Cells[11][2]="Gauche";
 else if (PJH[pc][10]=="Centre") avh->Cells[11][2]="Centre";
 else avh->Cells[11][2]="Droite";
 if (PJV[pc][10]=="Haut") avh->Cells[12][2]="Haut";
 else if (PJH[pc][10]=="Centre") avh->Cells[12][2]="Centre";
 else avh->Cells[12][2]="Bas";
 avh->Cells[13][2] = PHH[pc][10];
 avh->Cells[14][2] = PTYPE[pc][10];  // PTYPE pour stocker LSep ou non (O/N)

 avh->ColWidths[12]=0;
}
//---------------------------------------------------------------------------

void __fastcall TFDcal::avhCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
  char tmp[50]; int hsize, Size;
   if (OldCol==13)
    {
     strcpy(tmp,avh->Cells[13][ARow].c_str());
     hsize=atoi(tmp);
     if (hsize ==0) {Valid=false; return; }

     /*
     strcpy(tmp,avh->Cells[9][1].c_str());
    Size=atoi(tmp);
    if (hsize < (Size*12/10))
       {
        hsize =  Size*12/10;
        avh->Cells[13][1] = AnsiString(hsize);

       }


     strcpy(tmp,avh->Cells[9][1].c_str());
     Size=atoi(tmp);
     Size = hsize*12/10;
     avh->Cells[9][ARow]=AnsiString(Size);
     */
    }
 Valid=true;
}
//---------------------------------------------------------------------------

void __fastcall TFDcal::Button3Click(TObject *Sender)
{
 Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl44");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

