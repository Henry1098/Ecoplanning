//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modDescEnvelop.h"
#include "globals.h"
#include "modStyle.h"
#include "modEpaisseur.h"
#include "modGhost.h"
#include "modHelp.h"
#include "modJust.h"
#include <stdio.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TDescEnvelop *DescEnvelop;
//---------------------------------------------------------------------------
__fastcall TDescEnvelop::TDescEnvelop(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDescEnvelop::Image1Click(TObject *Sender)
{
  TColor Color;
 if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      FillColor(Color,Image1);
      coultrait = Color;
    }
}
//---------------------------------------------------------------------------


void __fastcall TDescEnvelop::FillColor(int color,TImage *im)
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

void __fastcall TDescEnvelop::btCancelClick(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TDescEnvelop::FormShow(TObject *Sender)
{
 char tmp[100];
 int coul;

  Ghost->ExtractValue(tmp,m_exchange,"pol",0);
  avl->Cells[1][1]=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"ct",0);
 avl->Cells[2][1]=AnsiString(tmp);
 coultext = atoi(tmp);
 FillColor(coultext,Image3);

 Ghost->ExtractValue(tmp,m_exchange,"it",0);
 avl->Cells[3][1]=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"bd",0);
 avl->Cells[4][1]=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"ht",0);
 avl->Cells[5][1]=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"jh",0);
 avl->Cells[6][1]=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"jv",0);
 avl->Cells[7][1]=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"cb",0);
 avl->Cells[8][1]=AnsiString(tmp);
 coulbackg = atoi(tmp);
 FillColor(coulbackg,Image2);

 Ghost->ExtractValue(tmp,m_exchange,"lg",0);
 avl->Cells[9][1]=AnsiString(tmp);

 Ghost->ExtractValue(tmp,m_exchange,"coult",0);
 coultrait = atoi(tmp);
 FillColor(coultrait,Image1);


 Ghost->ExtractValue(tmp,m_exchange,"style",0);
 Edit2->Text=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"ep",0);
 Edit1->Text=AnsiString(tmp);

 Ghost->ExtractValue(tmp,m_exchange,"design",0);
 if (strcmp(tmp,"X")==0) cb2->Checked = true; else cb2->Checked = false;
 Ghost->ExtractValue(tmp,m_exchange,"encadr",0);
 if (strcmp(tmp,"X")==0) cb1->Checked = true; else cb1->Checked = false;

 strcpy(m_exchange,"");
 avl->ColWidths[6]=0;
 avl->ColWidths[7]=0;




}
//---------------------------------------------------------------------------

void __fastcall TDescEnvelop::btOKClick(TObject *Sender)
{
 char tmp[500];
 char str[30];
strcpy(tmp,"<lc>");strcat(tmp,"X"); strcat(tmp,"</lc>");
strcat(tmp,"<pol>");strcat(tmp,avl->Cells[1][1].c_str()); strcat(tmp,"</pol>");
strcat(tmp,"<ct>");strcat(tmp,avl->Cells[2][1].c_str()); strcat(tmp,"</ct>");
strcat(tmp,"<it>");strcat(tmp,avl->Cells[3][1].c_str()); strcat(tmp,"</it>");
strcat(tmp,"<bd>");strcat(tmp,avl->Cells[4][1].c_str()); strcat(tmp,"</bd>");
strcat(tmp,"<ht>");strcat(tmp,avl->Cells[5][1].c_str()); strcat(tmp,"</ht>");
strcat(tmp,"<jh>");strcat(tmp,avl->Cells[6][1].c_str()); strcat(tmp,"</jh>");
strcat(tmp,"<jv>");strcat(tmp,avl->Cells[7][1].c_str()); strcat(tmp,"</jv>");
strcat(tmp,"<cb>");strcat(tmp,avl->Cells[8][1].c_str()); strcat(tmp,"</cb>");
strcat(tmp,"<lg>");strcat(tmp,avl->Cells[9][1].c_str()); strcat(tmp,"</lg>");


sprintf(str,"%d",coultrait);
strcat(tmp,"<coult>");strcat(tmp,str); strcat(tmp,"</coult>");
strcat(tmp,"<ep>");strcat(tmp,Edit1->Text.c_str()); strcat(tmp,"</ep>");
strcat(tmp,"<style>");strcat(tmp,Edit2->Text.c_str()); strcat(tmp,"</style>");

if (cb2->Checked == true) strcpy(str,"X"); else strcpy(str," ");
strcat(tmp,"<design>");strcat(tmp,str); strcat(tmp,"</design>");
if (cb1->Checked == true) strcpy(str,"X"); else strcpy(str," ");
strcat(tmp,"<encadr>");strcat(tmp,str); strcat(tmp,"</encadr>");

strcpy(m_exchange,tmp);

Close();
}
//---------------------------------------------------------------------------

void __fastcall TDescEnvelop::Edit1Click(TObject *Sender)
{
 TFDEpaisseur *Ep;
 char tmp[50];
   strcpy(m_exchange,"<ep>");  strcat(m_exchange,Edit1->Text.c_str());
   strcat(m_exchange,"</ep>");

   Ep=new TFDEpaisseur(Application);
   Ep->ShowModal();
   delete Ep;
   Ghost->ExtractValue(tmp,m_exchange,"ep",0);
   Edit1->Text=AnsiString(tmp);

}
//---------------------------------------------------------------------------

void __fastcall TDescEnvelop::Edit2Click(TObject *Sender)
{
 TFDStyle *Style;
 char tmp[50];
 Style= new TFDStyle(Application);
 Style->ShowModal();
 delete Style;
 if (strlen(m_exchange)==0) return;
 Ghost->ExtractValue(tmp,m_exchange,"style",0);
 Edit2->Text=AnsiString(tmp);

}
//---------------------------------------------------------------------------


void __fastcall TDescEnvelop::avlClickCell(TObject *Sender, int ARow,
      int ACol)
{
char tmp[250]; int cool;
  TFont *Fonte;
  int Color;
  AnsiString Name;
  int Size,hsize;

  char bold[50],italic[50];
  TFontStyles  Style;
  TJust *Just;

  if (ARow==0) return;

  if (ACol==0)
    {
     strcpy(tmp,avl->Cells[2][1].c_str());
     cool=atoi(tmp);
     FillColor(cool,Image3);

     strcpy(tmp,avl->Cells[8][1].c_str());
     cool=atoi(tmp);
     FillColor(cool,Image2);
     FillColor(coultrait,Image1);

    }

  if (ACol>0 && ACol<6)
   {

      FontDialog1->Font->Name =  avl->Cells[1][1];
      FontDialog1->Font->Color =   StrToInt(avl->Cells[2][1]);
      FontDialog1->Font->Size =   StrToInt(avl->Cells[5][1]);
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

      hsize = Size*12/10;
      avl->Cells[9][1] = AnsiString(hsize);

       strcpy(tmp,avl->Cells[2][1].c_str());
       cool=atoi(tmp);
       FillColor(cool,Image3);

      }
   }



  if (ACol==6) // || ACol==7)
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,avl->Cells[6][1].c_str());
    strcat(m_exchange,"</jh>");


    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        Ghost->ExtractValue(tmp,m_exchange,"jh",0);
        avl->Cells[6][1]=AnsiString(tmp);

      }

    delete Just;
 }

 if (ACol==7) // || ACol==7)
   {

    strcpy(m_exchange,"<jv>"); strcat(m_exchange,avl->Cells[7][1].c_str());
    strcat(m_exchange,"</jv>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        
        Ghost->ExtractValue(tmp,m_exchange,"jv",0);
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
      FillColor(cool,Image2);
    }
   }


}
//---------------------------------------------------------------------------

void __fastcall TDescEnvelop::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"AffectCriteres.html#Affect2");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

