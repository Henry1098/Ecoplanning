//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DescTrait.h"
#include "globals.h"
#include "modGhost.h"
#include "modHelp.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDTrait *FDTrait;
//---------------------------------------------------------------------------
__fastcall TFDTrait::TFDTrait(TComponent* Owner)
        : TForm(Owner)
{
}


void __fastcall TFDTrait::FillColor(int color,TImage *im)
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
void __fastcall TFDTrait::Button2Click(TObject *Sender)
{
strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDTrait::FormShow(TObject *Sender)
{
 char tmp[100];
  // style
  Ghost->ExtractValue(tmp,m_exchange,"pol",0);
  if (strstr(tmp,"Arial")) strcpy(tmp,"_________");
  ComboBox1->Text=AnsiString(tmp);
  Ghost->ExtractValue(tmp,m_exchange,"ct",0);
  //avl->Cells[2][1]=AnsiString(tmp);
 cool = atoi(tmp);
 FillColor(cool,Image1);
 Ghost->ExtractValue(tmp,m_exchange,"ht",0);
 Edit1->Text = AnsiString(tmp);



}
//---------------------------------------------------------------------------
void __fastcall TFDTrait::Image1Click(TObject *Sender)
{
 TColor Color;
 if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      FillColor(Color,Image1);
      cool = Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFDTrait::Button1Click(TObject *Sender)
{
 char tmp[500];
 char str[30];
//strcpy(tmp,"<lc>");strcat(tmp,"X"); strcat(tmp,"</lc>");
strcat(tmp,"<pol>");strcat(tmp,ComboBox1->Text.c_str()); strcat(tmp,"</pol>");
sprintf(str,"%d",cool);
strcat(tmp,"<ct>");strcat(tmp,str); strcat(tmp,"</ct>");
strcat(tmp,"<ht>");strcat(tmp,Edit1->Text.c_str()); strcat(tmp,"</ht>");

strcpy(m_exchange,tmp);

Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDTrait::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl49A");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

