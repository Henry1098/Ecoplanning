//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modPreview.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TPreview::TPreview(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPreview::Button1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TPreview::Draw_Cadre(TImage *img,int epaiss,TColor cool)
{
 int left,top,width,height;

  width=img->Width-2; height=img->Height-2;


 img->Canvas->Pen->Width = epaiss;
 img->Canvas->Pen->Color = cool;
 img->Canvas->MoveTo(0,0);
 img->Canvas->LineTo(width,0);
 img->Canvas->LineTo(width,height);
 img->Canvas->LineTo(0,height);
 img->Canvas->LineTo(0,0);

 img->Canvas->Pen->Width = 1;
 img->Canvas->Pen->Color = clBlack;
}
void __fastcall TPreview::FormShow(TObject *Sender)
{

 // compute imP size
 int h,w;
 h=imP->Height;
 w=imP->Width;

 MODE=1;
 // choix de imP1p ou imP1l;
 ExtractValue(orientation,m_exchange,"or",0);
 if (strcmp(orientation,"Portrait")==0)
     { Vim=imP1p; imP1l->Visible=false;  }
 else { Vim=imP1l; imP1p->Visible=false; }

 imP1p->Picture->Assign(imP);
 imP1l->Picture->Assign(imP);

 // Vim->Picture->Assign(imP);
 // ZoomP1->Position = MemPos; //OlpPos;
 ZoomCopy1(Vim,0,0);
 }
//---------------------------------------------------------------------------

// *************************************
//   EXTRACTVALUE
// *************************************
int __fastcall TPreview::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{ char tmp[250];char *p,*p1,*p2; int pos,l;

 result[0]=0; strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">"); p = strstr(buff,tmp);
 l=0;
 if (p)
   {strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">");p1= strstr(buff,tmp);
    if (p1) {p2=p + strlen(tag)+2; l= p1-p2; strncpy(result,p2,l); result[l]=0; }
   }
 return l;
}

void __fastcall TPreview::ZoomCopy1(TImage *i,int X,int Y)
{

TRect Dst,Src;int imx; int imy; int ext;
//int rx1,rx2,ry1,ry2;
if (!imP) return;

 TRect Diagram = Rect(0,0, Image1->Width,Image1->Height);
 Image1->Canvas->Brush->Color = clWhite; // BgColor;
 Image1->Canvas->FillRect(Diagram);

if (i==NULL) return;
if (imP==NULL)return;
imx=imP->Width;
imy=imP->Height;
ext = (11-ZoomP1->Position)*imx/22; // 220   22 = 11 * 2

rx1= (imx * X / i->Width) -ext;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > imP->Width) {rx2=imP->Width; rx1=rx2-2*ext; }
ry1= (imy * Y / i->Height) - ext;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > imP->Height) {ry2=imP->Height; ry1=ry2-2*ext; }


Dst = Rect(0,0,Image1->Width,Image1->Height);
Src = Rect(rx1,ry1,rx2,ry2);
Image1->Canvas->CopyRect(Dst,imP->Canvas,Src);
}

void __fastcall TPreview::imP1pMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

 ZoomCopy1(imP1p,X,Y);
 MODE=1;
 OldXP1P=X; OldYP1P=Y;

}
//---------------------------------------------------------------------------
void __fastcall TPreview::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 int XR,YR,XI,YI;
 XR = (rx2-rx1)*X/Image1->Width + rx1;    // XR Coordonnées dans IMP
 YR = (ry2-ry1)*Y/Image1->Height + ry1;   // YR Coordonnées dans imP
 XI= Vim->Width * XR /imP->Width;
 YI= Vim->Height * YR / imP->Height;
 ZoomCopy1(Vim,XI,YI);
}
//---------------------------------------------------------------------------
void __fastcall TPreview::ZoomP1Change(TObject *Sender)
{
// OldPos=ZoomP1->Position;
if (MODE==1) ZoomCopy1(Vim,OldXP1P,OldYP1P);
 else ZoomCopy1(Vim,OldXP1L,OldYP1L);
}
//---------------------------------------------------------------------------
void __fastcall TPreview::imP1lMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ZoomCopy1(imP1l,X,Y);
  MODE=2;
  OldXP1L=X; OldYP1L=Y;
}
//---------------------------------------------------------------------------







