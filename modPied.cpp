//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modPied.h"
#include "globals.h"
#include "modJust.h"
#include "modHelp.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TFDpied *FDpied;
//---------------------------------------------------------------------------
__fastcall TFDpied::TFDpied(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDpied::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDpied::Button1Click(TObject *Sender)
{
 char tmp[512];  int val; int i;
 // Couleur de fond
  if (Edit1->Text=="") Edit1->Text="FFFFFF";
  strcpy(tmp,Edit1->Text.c_str());
  P_PD_BKG[pc]=(TColor) atoi(tmp);

 // Remplir les 9 zones pied  (indices 25 a 33)
 for (i=25;i<34;i++) FillData(i);


Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDpied::FillColor(int color,TImage *im)
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




void __fastcall TFDpied::avlClickCell(TObject *Sender, int ARow, int ACol)
{
 int X,Y; char tmp[500],temp[120];int lg;

 TFont *Fonte;
  int Color;
  AnsiString Name;
  int Size;

  char bold[50],italic[50];
  TFontStyles  Style;
   TJust *Just;



 if (ARow==0) return;
 OldRow = ARow;
 OldCol = ACol;



 if ((OldRow<0) || ((OldRow > avl->RowCount-1))) return;

 int cool;

 strcpy(tmp,avl->Cells[3][OldRow].c_str());
 cool=atoi(tmp);
 FillColor(cool,imFColor);
 
 if (OldCol>1 && OldCol<7)
   {
     FontDialog1->Options;
      FontDialog1->Font->Name = avl->Cells[2][OldRow];
     FontDialog1->Font->Color = StrToInt(avl->Cells[3][OldRow]);
     FontDialog1->Font->Size = StrToInt(avl->Cells[6][OldRow]);

     if (avl->Cells[5][OldRow]=="Gras" && avl->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (avl->Cells[5][OldRow]=="Gras" && avl->Cells[4][OldRow]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (avl->Cells[5][OldRow]!="Gras" && avl->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles() << fsItalic;

     strcpy(m_exchange,"");
     if (FontDialog1->Execute())
      { Fonte = FontDialog1->Font;
      Color = Fonte->Color;
      Size = Fonte->Size;
      Name = Fonte->Name;
      Style = Fonte->Style;
      // recherche si bold et italique

      if (Style.Contains(fsBold))  strcpy(bold,"Gras"); else strcpy(bold,"Standard");
      if (Style.Contains(fsItalic))  strcpy(italic,"Italique"); else strcpy(italic,"Standard");

      
      avl->Cells[2][OldRow]=Name;
      avl->Cells[3][OldRow]=AnsiString(Color);
      avl->Cells[4][OldRow]=AnsiString(italic);
      avl->Cells[5][OldRow]=AnsiString(bold);
      avl->Cells[6][OldRow]=AnsiString(Size);

      avl->Cells[9][OldRow]=AnsiString(Size*15/10);
       strcpy(tmp,avl->Cells[3][OldRow].c_str());
       cool=atoi(tmp);
       FillColor(cool,imFColor);

      }
   }

 /*
 if (OldCol==7)
   {
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      avl->Cells[7][OldRow]=AnsiString(Color);
      strcpy(tmp,avl->Cells[7][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imBColor);
    }
   }
 */

 if (OldCol==7)
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,avl->Cells[7][OldRow].c_str());
    strcat(m_exchange,"</jh>");


    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        ExtractValue(tmp,m_exchange,"jh",0);
        avl->Cells[7][OldRow]=AnsiString(tmp);

      }

    delete Just;
   }

  if (OldCol==8)
   {

    strcpy(m_exchange,"<jv>"); strcat(m_exchange,avl->Cells[8][OldRow].c_str());
    strcat(m_exchange,"</jv>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        
        ExtractValue(tmp,m_exchange,"jv",0);
        avl->Cells[8][OldRow]=AnsiString(tmp);
      }

    delete Just;
   }

}
//---------------------------------------------------------------------------

int __fastcall TFDpied::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TFDpied::btBackGroundClick(TObject *Sender)
{
TColor Color;    int c;  char tmp[100];
strcpy(tmp,Edit1->Text.c_str());
c=atoi(tmp);
ColorDialog1->Color=c;



if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      c = (int)(Color);
      Edit1->Text=AnsiString(Color);
      FillColor(c,imBColor);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFDpied::FillData(int ind)
{
 TColor Color; int val; char tmp[250];

 PACTIF[pc][ind]='O';
 P_ORIENT[pc][ind]='L';
 PTYPE[pc][ind]='L';

 PT[pc][ind]= avl->Cells[1][ind-24];
 PF[pc][ind]= avl->Cells[2][ind-24];

 PB[pc][ind]= P_PD_BKG[pc];

 strcpy(tmp,avl->Cells[3][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"0");
 val= atoi(tmp); PC[pc][ind]=TColor(val);

/*
 strcpy(tmp,avl->Cells[7][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"0");
 val= atoi(tmp); PB[pc][ind]=TColor(val);
*/

 strcpy(tmp,avl->Cells[4][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Standard");
 if (strcmp(tmp,"Standard")==0)  PN[pc][ind]="Standard";
  else PN[pc][ind]="Italique";

 strcpy(tmp,avl->Cells[5][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Standard");
 if (strcmp(tmp,"Standard")==0)  PX[pc][ind]="Standard";
  else PX[pc][ind]="Gras";

 strcpy(tmp,avl->Cells[7][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Centre");
 if (strcmp(tmp,"Gauche")==0)  PJH[pc][ind]="Gauche";
 else if (strcmp(tmp,"Centre")==0)  PJH[pc][ind]="Centre";
  else PJH[pc][ind]="Droite";

 /*
 strcpy(tmp,avl->Cells[8][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Centre");
 if (strcmp(tmp,"Haut")==0)  PJV[pc][ind]='H';
 else if (strcmp(tmp,"Centre")==0)  PJV[pc][ind]='C';
  else PJV[pc][ind]='B';
 */
 strcpy(tmp,avl->Cells[6][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"12");
 val= atoi(tmp); PH[pc][ind]=val;

 strcpy(tmp,avl->Cells[9][ind-24].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"16");
 val= atoi(tmp); PHH[pc][ind]=val;
}




void __fastcall TFDpied::FillGrid(int ind)
{
 avl->Cells[1][ind-24] = PT[pc][ind];
 avl->Cells[2][ind-24] = PF[pc][ind];
 avl->Cells[3][ind-24] = PC[pc][ind];

 if (PN[pc][ind]=="Standard") avl->Cells[4][ind-24] = "Standard";
   else  avl->Cells[4][ind-24] = "Italique";
 if (PX[pc][ind]=="Standard") avl->Cells[5][ind-24] = "Standard";
   else  avl->Cells[5][ind-24] = "Gras";
 avl->Cells[6][ind-24] = PH[pc][ind];

 /*if (PJH[pc][ind]=="Centre") avl->Cells[7][ind-24]="Centre";
 else if (PJH[pc][ind]=="Gauche") avl->Cells[7][ind-24]="Gauche";
 else avl->Cells[7][ind-24]="Droite";
 */

 avl->Cells[7][ind-24]="Gauche";

 /*
 if (PJV[pc][ind]=='C') avl->Cells[8][ind-24]="Centre";
 else if (PJV[pc][ind]=='H') avl->Cells[8][ind-24]="Haut";
 else avl->Cells[8][ind-24]="Bas";
 */
 avl->Cells[9][ind-24] = PHH[pc][ind];

 Edit1->Text = AnsiString(P_PD_BKG[pc]);

}

void __fastcall TFDpied::FormShow(TObject *Sender)
{
int ind;
 for (ind=25;ind<34;ind++) FillGrid(ind);
 Edit1->Text=AnsiString(P_PD_BKG[pc]);
 int c=StrToInt(Edit1->Text);
 FillColor(c,imBColor);
 avl->ColWidths[7]=0;
 avl->ColWidths[8]=0;
 avl->RowHeights[4]=0;
 avl->RowHeights[5]=0;
 avl->RowHeights[6]=0;
 avl->RowHeights[7]=0;
 avl->RowHeights[8]=0;
 avl->RowHeights[9]=0;
}
//---------------------------------------------------------------------------

void __fastcall TFDpied::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl49");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

