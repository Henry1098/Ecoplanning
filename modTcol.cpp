//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modTcol.h"
#include "modJust.h"
#include "modEpaisseur.h"
#include "modHelp.h"
#include "modStyle.h"
#include "modGhost.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TFDTcol *FDTcol;
//---------------------------------------------------------------------------
__fastcall TFDTcol::TFDTcol(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TFDTcol::FillColor(int color,TImage *im)
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

//---------------------------------------------------------------------------
void __fastcall TFDTcol::avlClickCell(TObject *Sender, int ARow, int ACol)
{
  char tmp[250]; int cool;
  TFont *Fonte;
  int Color;
  AnsiString Name;
  int Size;

  char bold[50],italic[50];
  TFontStyles  Style;
 TJust *Just;

  if (ARow==0) return; 

  if (ACol==0)
    {
     strcpy(tmp,avl->Cells[2][1].c_str());
     cool=atoi(tmp);
     FillColor(cool,imFColor);

     strcpy(tmp,avl->Cells[8][1].c_str());
     cool=atoi(tmp);
     FillColor(cool,imBColor);
    }

  if (ACol>0 && ACol<6)
   {
      
     FontDialog1->Font->Name = avl->Cells[1][1];

     strcpy(tmp,avl->Cells[2][1].c_str());
     FontDialog1->Font->Color = atoi(tmp);  // StrToInt(avl->Cells[2][1]);
     strcpy(tmp,avl->Cells[5][1].c_str());
     FontDialog1->Font->Size = atoi(tmp); // StrToInt(avl->Cells[5][1]);

     if (avl->Cells[4][1]=="Gras" && avl->Cells[3][1]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (avl->Cells[4][1]=="Gras" && avl->Cells[3][1]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (avl->Cells[4][1]!="Gras" && avl->Cells[3][1]=="Italique")
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

      avl->Cells[1][1]=Name;
      avl->Cells[2][1]=AnsiString(Color);
      avl->Cells[3][1]=AnsiString(italic);
      avl->Cells[4][1]=AnsiString(bold);
      avl->Cells[5][1]=AnsiString(Size);
       strcpy(tmp,avl->Cells[2][1].c_str());
       cool=atoi(tmp);
       FillColor(cool,imFColor);

      }
   }


  if (ACol==6)
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,avl->Cells[6][1].c_str());
    strcat(m_exchange,"</jh>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        ExtractValue(tmp,m_exchange,"jh",0);
        avl->Cells[6][1]=AnsiString(tmp);

      }

    delete Just;
  }


  if (ACol==7)
   {

    strcpy(m_exchange,"<jv>"); strcat(m_exchange,avl->Cells[7][1].c_str());
    strcat(m_exchange,"</jv>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        
        ExtractValue(tmp,m_exchange,"jv",0);
        avl->Cells[7][1]=AnsiString(tmp);
      }

    delete Just;
  }

 if (ACol==8)
   {
    strcpy(tmp,avl->Cells[8][1].c_str()); cool=atoi(tmp);
    ColorDialog1->Color = (TColor) cool;
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      avl->Cells[8][1]=AnsiString(Color);
      strcpy(tmp,avl->Cells[8][1].c_str());
      cool=atoi(tmp);
      FillColor(cool,imBColor);
    }
   }


}
//---------------------------------------------------------------------------

int __fastcall TFDTcol::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TFDTcol::Button2Click(TObject *Sender)
{
strcpy(m_exchange,"");
 Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::FormCreate(TObject *Sender)
{
char tmp[250]; int cool;
 // recupere les donnees dans m_exchange


}





//---------------------------------------------------------------------------

void __fastcall TFDTcol::Edit2Click(TObject *Sender)
{
  TColor Color;
  int cool; char tmp[200];

  strcpy(tmp,Edit2->Text.c_str()); cool=atoi(tmp);
   FillColor(cool,imFColor);
  ColorDialog1->Color = (TColor) cool;
  if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      Edit2->Text=AnsiString(Color);
      strcpy(tmp,Edit2->Text.c_str());
      cool=atoi(tmp);
      FillColor(cool,imLSep);
     }
}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::Edit4Click(TObject *Sender)
{
   TColor Color;
  int cool;
  char tmp[200];

  strcpy(tmp,Edit4->Text.c_str()); cool=atoi(tmp);
  ColorDialog1->Color = (TColor) cool;
   FillColor(cool,imFColor);
  if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      Edit4->Text=AnsiString(Color);
      strcpy(tmp,Edit4->Text.c_str());
      cool=atoi(tmp);
      FillColor(cool,imLVert);
     }        
}
//---------------------------------------------------------------------------


void __fastcall TFDTcol::Edit1Click(TObject *Sender)
{
 char tmp[50];

 TFDEpaisseur *Ep;
 strcpy(m_exchange,"<ep>");  strcat(m_exchange,Edit1->Text.c_str());
 strcat(m_exchange,"</ep>");

 Ep=new TFDEpaisseur(Application);
 Ep->ShowModal();
 delete Ep;
 ExtractValue(tmp,m_exchange,"ep",0);
 Edit1->Text=AnsiString(tmp);

}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::Edit3Click(TObject *Sender)
{
char tmp[50];

 TFDEpaisseur *Ep;
 strcpy(m_exchange,"<ep>");  strcat(m_exchange,Edit3->Text.c_str());
 strcat(m_exchange,"</ep>");

 Ep=new TFDEpaisseur(Application);
 Ep->ShowModal();
 delete Ep;
 ExtractValue(tmp,m_exchange,"ep",0);
 Edit3->Text=AnsiString(tmp);

}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::Button1Click(TObject *Sender)
{
//if (avl->Cells[1][1]=="" || avl->Cells[2][1]=="" || avl->Cells[3][1]=="" || avl->Cells[4][1]=="" ||
//     avl->Cells[5][1]=="" || avl->Cells[6][1]=="" || avl->Cells[7][1]=="" || avl->Cells[8][1]=="" ||
//     avl->Cells[9][1]=="" )
     if (avl->Cells[3][1]=="") avl->Cells[3][1]="Standard";
     if (avl->Cells[4][1]=="") avl->Cells[4][1]="Standard";

   //  { Application->MessageBoxA("Données Police Caractères Incomplètes",m_ecoplan,MB_OK);
   //    return;
   //  }
 if (Edit1->Text=="" || Edit2->Text=="")
     { Application->MessageBoxA("Données Ligne Séparatrice Haute Incomplètes",m_ecoplan,MB_OK);
       return;
     }
 if (Edit3->Text=="" || Edit4->Text=="")
     { Application->MessageBoxA("Données Ligne Séparatrice Basse Incomplètes",m_ecoplan,MB_OK);
       return;
     }


 strcpy(m_exchange,"");
 // Prepare m_exchange and Exit
strcat(m_exchange,"<pol>");strcat(m_exchange,avl->Cells[1][1].c_str()); strcat(m_exchange,"</pol>");
strcat(m_exchange,"<ct>");strcat(m_exchange,avl->Cells[2][1].c_str()); strcat(m_exchange,"</ct>");
strcat(m_exchange,"<it>");strcat(m_exchange,avl->Cells[3][1].c_str()); strcat(m_exchange,"</it>");
strcat(m_exchange,"<bd>");strcat(m_exchange,avl->Cells[4][1].c_str()); strcat(m_exchange,"</bd>");
strcat(m_exchange,"<ht>");strcat(m_exchange,avl->Cells[5][1].c_str()); strcat(m_exchange,"</ht>");
strcat(m_exchange,"<jh>");strcat(m_exchange,avl->Cells[6][1].c_str()); strcat(m_exchange,"</jh>");
strcat(m_exchange,"<jv>");strcat(m_exchange,avl->Cells[7][1].c_str()); strcat(m_exchange,"</jv>");
strcat(m_exchange,"<cb>");strcat(m_exchange,avl->Cells[8][1].c_str()); strcat(m_exchange,"</cb>");
strcat(m_exchange,"<lg>");strcat(m_exchange,avl->Cells[9][1].c_str()); strcat(m_exchange,"</lg>");
strcat(m_exchange,"<ls1>");
if (cbLSepNiv->Checked==true) strcat(m_exchange,"Oui");  //
strcat(m_exchange,"</ls1>");

strcat(m_exchange,"<ep1>");strcat(m_exchange,Edit1->Text.c_str()); strcat(m_exchange,"</ep1>");
strcat(m_exchange,"<cl1>");strcat(m_exchange,Edit2->Text.c_str()); strcat(m_exchange,"</cl1>");
strcat(m_exchange,"<st1>");strcat(m_exchange,Edit5->Text.c_str()); strcat(m_exchange,"</st1>");


strcat(m_exchange,"<ls2>");
if (cbLVert->Checked==true) strcat(m_exchange,"Oui");  //
strcat(m_exchange,"</ls2>");
strcat(m_exchange,"<ep2>");strcat(m_exchange,Edit3->Text.c_str()); strcat(m_exchange,"</ep2>");
strcat(m_exchange,"<cl2>");strcat(m_exchange,Edit4->Text.c_str()); strcat(m_exchange,"</cl2>");
 strcat(m_exchange,"<st2>");strcat(m_exchange,Edit6->Text.c_str()); strcat(m_exchange,"</st2>");
// Maj des données

//ExtractValue(tmp,m_exchange,"ct",0);
/*
 PC_CTEXT[pc]=avl->Cells[2][1];

 //ExtractValue(tmp,m_exchange,"it",0);
 PC_ITAL[pc]= avl->Cells[3][1];

 //ExtractValue(tmp,m_exchange,"bd",0);
 PC_BOLD[pc]=avl->Cells[4][1];

 //ExtractValue(tmp,m_exchange,"ht",0);
 PC_HAUTEUR[pc]=avl->Cells[5][1];

 //ExtractValue(tmp,m_exchange,"jh",0);
 PC_JSH[pc]=avl->Cells[6][1];

 //ExtractValue(tmp,m_exchange,"jv",0);
PC_JSV[pc]=avl->Cells[7][1];

 //ExtractValue(tmp,m_exchange,"cb",0);
 PC_CBKG[pc]=avl->Cells[8][1];

 //ExtractValue(tmp,m_exchange,"lg",0);
 PC_LARG[pc]=avl->Cells[9][1];

 //ExtractValue(tmp,m_exchange,"ep1",0);
 PC_LS1EP[pc]=Edit1->Text;

 //ExtractValue(tmp,m_exchange,"cl1",0);
 PC_LS1CL[pc]=Edit2->Text;
 //ExtractValue(tmp,m_exchange,"ls2",0);

 //ExtractValue(tmp,m_exchange,"ep2",0);
 PC_LS2EP[pc]=Edit3->Text;

 //ExtractValue(tmp,m_exchange,"cl2",0);
 PC_LS2CL[pc]=Edit4->Text;
*/


Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::FormShow(TObject *Sender)
{
 char tmp[250];   int cool;

 //if (strlen(m_exchange))
 //{
 ExtractValue(tmp,m_exchange,"pol",0);
 avl->Cells[1][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"ct",0);
 avl->Cells[2][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"it",0);
 avl->Cells[3][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"bd",0);
 avl->Cells[4][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"ht",0);
 avl->Cells[5][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"jh",0);
 avl->Cells[6][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"jv",0);
 avl->Cells[7][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"cb",0);
 avl->Cells[8][1]=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"lg",0);
 avl->Cells[9][1]=AnsiString(tmp);

 ExtractValue(tmp,m_exchange,"ls1",0);
 if (strlen(tmp)==0) cbLSepNiv->Checked=false; else  cbLSepNiv->Checked=true;
 Edit1->Text=AnsiString(tmp);


 ExtractValue(tmp,m_exchange,"ep1",0);
 if (strlen(tmp)==0) strcpy(tmp,"0.1");
 Edit1->Text=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"cl1",0);
 if (strlen(tmp)==0) strcpy(tmp,"0");
 Edit2->Text=AnsiString(tmp);

 ExtractValue(tmp,m_exchange,"st1",0);
 Edit5->Text=AnsiString(tmp);


 ExtractValue(tmp,m_exchange,"ls2",0);
 if (strlen(tmp)==0) cbLVert->Checked=false; else  cbLVert->Checked=true;

 ExtractValue(tmp,m_exchange,"ep2",0);
 if (strlen(tmp)==0) strcpy(tmp,"0.1");
 Edit3->Text=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"cl2",0);
 if (strlen(tmp)==0) strcpy(tmp,"0");
 Edit4->Text=AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"st2",0);
 Edit6->Text=AnsiString(tmp);

 strcpy(m_exchange,"");

 /*
 else
  {
   avl->Cells[1][1]=PC_POL[pc];
   avl->Cells[2][1]=PC_CTEXT[pc];
   avl->Cells[3][1]=PC_ITAL[pc];
   avl->Cells[4][1]=PC_BOLD[pc];
   avl->Cells[5][1]=PC_HAUTEUR[pc];
   avl->Cells[6][1]=PC_JSH[pc];
   avl->Cells[7][1]=PC_JSV[pc];
   avl->Cells[8][1]=PC_CBKG[pc];
   avl->Cells[9][1]=PC_LARG[pc];
   Edit1->Text=PC_LS1EP[pc];
   Edit2->Text=PC_LS1CL[pc];
   Edit3->Text=PC_LS2EP[pc];
   Edit4->Text=PC_LS2CL[pc];

 }
*/

     strcpy(tmp,avl->Cells[2][1].c_str());
     cool=atoi(tmp);
     FillColor(cool,imFColor);

     strcpy(tmp,avl->Cells[8][1].c_str());
     cool=atoi(tmp);
     FillColor(cool,imBColor);

     strcpy(tmp,Edit2->Text.c_str());
     cool=atoi(tmp);
     FillColor(cool,imLSep);

     strcpy(tmp,Edit4->Text.c_str());
     cool=atoi(tmp);
     FillColor(cool,imLVert);

}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl49A");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::Edit5Click(TObject *Sender)
{
TFDStyle *Style;
 char tmp[50];
 Style= new TFDStyle(Application);
 Style->ShowModal();
 delete Style;
 if (strlen(m_exchange)==0) return;
 Ghost->ExtractValue(tmp,m_exchange,"style",0);
 Edit5->Text=AnsiString(tmp);
}
//---------------------------------------------------------------------------

void __fastcall TFDTcol::Edit6Click(TObject *Sender)
{
TFDStyle *Style;
 char tmp[50];
 Style= new TFDStyle(Application);
 Style->ShowModal();
 delete Style;
 if (strlen(m_exchange)==0) return;
 Ghost->ExtractValue(tmp,m_exchange,"style",0);
 Edit6->Text=AnsiString(tmp);
}
//---------------------------------------------------------------------------

