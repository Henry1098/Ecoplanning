//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modeCadre.h"
#include "globals.h"
#include "modEpaisseur.h"
#include "modHelp.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCadre *Cadre;
//---------------------------------------------------------------------------
__fastcall TCadre::TCadre(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TCadre::FillColor(int color,TImage *im)
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
void __fastcall TCadre::Button2Click(TObject *Sender)
{
 //int n;
 char tmp[250]; float ff;
 //n = cbEpaiss->ItemIndex;
/* if (n==-1)
  {
   Application->MessageBoxA("Selectionnez une épaisseur du trait",m_ecoplan,MB_OK);
   return;
  }
*/
 if (cbEpaiss->Text=="")
  {
  Application->MessageBoxA("Selectionnez une épaisseur du trait",m_ecoplan,MB_OK);
   return;
  }

 P_ELC[pc]=cbEpaiss->Text;
 ff =AnsiToFloat(P_ELC[pc]); ff=ff*COEFMM;
 P_ELCF[pc] = (int) ff;
 P_CLC[pc]=Edit1->Text;
 //if (P_CLC[pc]=="") P_CLC[pc]=0;
 //P_CLCC[pc]= StrToInt(P_CLC[pc]);

Close();
}


float __fastcall TCadre::AnsiToFloat(AnsiString str)
{
 char tmp[200]; char *p;
 float f;
 strcpy(tmp,str.c_str());

 p=strchr(tmp,',');
 if (p) *p='.';
 f=atof(tmp);
 return f;

}
//---------------------------------------------------------------------------

void __fastcall TCadre::Button3Click(TObject *Sender)
{
 strcpy(m_exchange,"");
Close();
}
//---------------------------------------------------------------------------


void __fastcall TCadre::Button1Click(TObject *Sender)
{
 int Color;
 char tmp[50];
 int cool;
 if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      Edit1->Text = AnsiString(Color);
      strcpy(tmp,Edit1->Text.c_str());
      cool = atoi(tmp);
      FillColor(cool,Image1);
    }
}
//---------------------------------------------------------------------------


void __fastcall TCadre::FormShow(TObject *Sender)
{
 int cool; char tmp[50];
 cbEpaiss->Text=P_ELC[pc];
 Edit1->Text = P_CLC[pc];
 strcpy(tmp,P_ELC[pc].c_str());
 cool = atoi(tmp);
 FillColor(cool,Image1);

}
//---------------------------------------------------------------------------

void __fastcall TCadre::Button4Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl42");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

