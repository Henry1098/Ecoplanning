//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modCorps.h"
#include "modEpaisseur.h"
#include "modStyle.h"
#include "modHelp.h"
#include "stdio.h"
#include "globals.h"         
#include <windows.h>
#include <Lmcons.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TFDcorps *FDcorps;
//---------------------------------------------------------------------------
__fastcall TFDcorps::TFDcorps(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDcorps::Button1Click(TObject *Sender)
{
char username[UNLEN+1];
DWORD username_len = UNLEN+1;
GetUserName(username, &username_len);
AnsiString c = "C:\\Users\\";
AnsiString d ="\\Desktop\\Rapport";
AnsiString e = AnsiString(username);

int jk = 1;

AppendStr(c,e);
AppendStr(c,d);
 // Remplissage des variables
 int i;   char tmp[100];


 for (i=0;i<8;i++)
   {
    P_CYN[pc][i]=avl->Cells[1][i+1];
    P_CCFG[pc][i]=avl->Cells[2][i+1];
    P_CCST[pc][i]=avl->Cells[3][i+1];
    P_CCEP[pc][i]=avl->Cells[4][i+1];
   }

  P_CYNJT[pc]=avv->Cells[1][1];
  P_CYNJNT[pc]=avv->Cells[1][2];
  P_CYNWENT[pc]=avv->Cells[1][3];

  P_CJT[pc]=avv->Cells[2][1];
  P_CJNT[pc]=avv->Cells[2][2];
  P_CWENT[pc]=avv->Cells[2][3];

  

  P_CDH[pc]=avv->Cells[2][4];
  P_CDV[pc]=avv->Cells[2][5];
  P_CDVV[pc] = StrToInt(P_CDV[pc]);
  P_CCJT[pc]=avv->Cells[3][1];
  P_CCJNT[pc]=avv->Cells[3][2];
  P_CCWENT[pc]=avv->Cells[3][3];

  if (cbForce->Checked)  P_CJTFLAG[pc]="Yes"; else P_CJTFLAG[pc]="";
  
AppendStr(c,IntToStr(jk));
   avl->SaveToFile(c);
   jk++;

AppendStr(c,IntToStr(jk));
   avv->SaveToFile(c);
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDcorps::Button2Click(TObject *Sender)
{
Close();
}

int __fastcall TFDcorps::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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


//---------------------------------------------------------------------------
void __fastcall TFDcorps::avlClickCell(TObject *Sender, int ARow, int ACol)
{
 int cool;
 TColor xcool;
 char tmp[250];
 TFDEpaisseur *Ep;
 TFDStyle *Style;

 if (ARow==0) return;
 if (ACol==0)
   {
    strcpy(tmp,avl->Cells[2][ARow].c_str()); cool=atoi(tmp); FillColor(cool,imFColor);

   }
 if (ACol==1)
   {
    if (avl->Cells[1][ARow]=="Oui")  avl->Cells[1][ARow]="Non";
       else avl->Cells[1][ARow]="Oui";
   }
 if (ACol==2)
   {

     strcpy(tmp,avl->Cells[ACol][ARow].c_str());
     cool=atoi(tmp);
     ColorDialog1->Color = cool;
     if (ColorDialog1->Execute())
        {
         xcool = ColorDialog1->Color;
         avl->Cells[ACol][ARow]=AnsiString(xcool);
         strcpy(tmp,avl->Cells[ACol][ARow].c_str());
         cool=atoi(tmp);
         FillColor(cool,imFColor);
        }

   }

 /*
  if (ACol==3)
   {
     if (ColorDialog1->Execute())
        {
         Color = ColorDialog1->Color;
         avl->Cells[ACol][ARow]=AnsiString(Color);
         strcpy(tmp,avl->Cells[ACol][ARow].c_str());
         cool=atoi(tmp);
         FillColor(cool,imBColor);
        }

   }

 */
 if (ACol==3)
     {
      Style= new TFDStyle(Application);
      Style->ShowModal();
      delete Style;
      if (strlen(m_exchange)==0) return;
      ExtractValue(tmp,m_exchange,"style",0);
      avl->Cells[ACol][ARow]=AnsiString(tmp);
     }
  if (ACol==4)
    { strcpy(m_exchange,"<ep>");  strcat(m_exchange,avl->Cells[ACol][ARow].c_str());
      strcat(m_exchange,"</ep>");

      Ep=new TFDEpaisseur(Application);
      Ep->ShowModal();
      delete Ep;
      ExtractValue(tmp,m_exchange,"ep",0);
      avl->Cells[ACol][ARow]=AnsiString(tmp);
    }

}
//---------------------------------------------------------------------------


void __fastcall TFDcorps::FillColor(int color,TImage *im)
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



void __fastcall TFDcorps::avvClickCell(TObject *Sender, int ARow, int ACol)
{
 int cool; char tmp[250];
 AnsiString valcell;
 TColor xcool;

 if (ARow==0 ) return;

 if (ACol==2 && ARow>3) return;

 if (ARow>0 && ARow<4)
   {
    if (ACol==0) // affiche la couleur
     {
         strcpy(tmp,avv->Cells[3][ARow].c_str());
         cool=atoi(tmp);
         FillColor(cool,Image1);
     }
    if (ACol==1)
     {
      if (avv->Cells[ACol][ARow]=="Oui") avv->Cells[ACol][ARow]="Non";  //
      else avv->Cells[ACol][ARow]="Oui";
      if (ARow==1) avv->Cells[ACol][ARow]="Oui";
     }


    if (ACol==3)
     {
        strcpy(tmp,avv->Cells[ACol][ARow].c_str());
        cool=atoi(tmp);
        ColorDialog1->Color=cool;
          if (ColorDialog1->Execute())
        {
         xcool = ColorDialog1->Color;
         avv->Cells[ACol][ARow]=AnsiString(xcool);
         strcpy(tmp,avv->Cells[ACol][ARow].c_str());
         cool=atoi(tmp);
         FillColor(cool,Image1);
        }
     }
   }


}
//---------------------------------------------------------------------------


void __fastcall TFDcorps::avvCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
/*  AnsiString valcell;
  char tmp[50];
  Valid = false;
  if (ARow<1 || ARow>5) return;

  //if (ACol==2) //  && (ARow==1 || ARow==2 || ARow==3))
  //    {
       Valid=true;
       valcell = avv->Cells[ACol][ARow];
       avv->Cells[2][1]=valcell;
       avv->Cells[2][2]=valcell;
       avv->Cells[2][3]=valcell;
       //strcpy(tmp,valcell.c_str());
      //}
  //else Valid = true;
*/

}
//---------------------------------------------------------------------------

void __fastcall TFDcorps::FormShow(TObject *Sender)
{
int i;
  // remplissage des Grids

 for (i=0;i<8;i++)
   {
    avl->Cells[1][i+1]=P_CYN[pc][i];
    avl->Cells[2][i+1]=P_CCFG[pc][i];
    //avl->Cells[3][i+1]=P_CCBK[pc][i];
    avl->Cells[3][i+1]=P_CCST[pc][i];
    avl->Cells[4][i+1]=P_CCEP[pc][i];
   }

  if (P_CJTFLAG[pc]=="Yes")  cbForce->Checked=true; else cbForce->Checked=false;

  avv->Cells[1][1]=P_CYNJT[pc];
  avv->Cells[1][2]=P_CYNJNT[pc];
  avv->Cells[1][3]=P_CYNWENT[pc];
  avv->Cells[1][4]="";
  avv->Cells[1][5]="";

  avv->Cells[2][1]=P_CJT[pc];
  avv->Cells[2][2]=P_CJNT[pc];
  avv->Cells[2][3]=P_CWENT[pc];
  avv->Cells[2][4]=P_CDH[pc];
  avv->Cells[2][5]=P_CDV[pc];

  avv->Cells[2][2]=P_CJT[pc];
  avv->Cells[2][3]=P_CJT[pc];

  avv->Cells[3][1]=P_CCJT[pc];
  avv->Cells[3][2]=P_CCJNT[pc];
  avv->Cells[3][3]=P_CCWENT[pc];
  avv->Cells[3][4]="";
  avv->Cells[3][5]="";

  avv->RowHeights[3]=0;
  avl->RowHeights[8]=0;
  // ColorDialog1 = new TColorDialog;
}
//---------------------------------------------------------------------------

void __fastcall TFDcorps::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl46");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TFDcorps::avvCellsChanged(TObject *Sender, TRect &R)
{
 AnsiString valcell;
  char tmp[50];
 // Valid = false;
  //if (ARow<1 || ARow>5) return;

  //if (ACol==2) //  && (ARow==1 || ARow==2 || ARow==3))
  //    {
  //     Valid=true;
 valcell = avv->Cells[2][1];
 //avv->Cells[2][1]=valcell;
 avv->Cells[2][2]=valcell;
  avv->Cells[2][3]=valcell;
       //strcpy(tmp,valcell.c_str());
      //}
  //else Valid = true;

}
//---------------------------------------------------------------------------

void __fastcall TFDcorps::avvCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 CanEdit = true;
 if (ACol !=2) return;
 if (ARow==2 || ARow==3) CanEdit = false;
}
//---------------------------------------------------------------------------

