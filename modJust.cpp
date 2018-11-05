//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modJust.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TJust *Just;
//---------------------------------------------------------------------------
__fastcall TJust::TJust(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall TJust::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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
void __fastcall TJust::FormClose(TObject *Sender, TCloseAction &Action)
{
 Action = caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TJust::FormCreate(TObject *Sender)
{
 char c;
 mod=0;
 ExtractValue(jh,m_exchange,"jh",0);
 if (strlen(jh)) mod = 1;
 ExtractValue(jv,m_exchange,"jv",0);
 if (strlen(jv)) mod=2;

 if (mod==1)
  {
    GroupBox1->Caption = "Horizontal";
    RadioButton1->Caption = "Gauche";
    RadioButton2->Caption = "Centre";
    RadioButton3->Caption = "Droit";
   c=jh[0];
  if (c=='G') RadioButton1->Checked=true;
  else if (c=='C') RadioButton2->Checked=true;
  else if (c=='D') RadioButton3->Checked=true;
   else RadioButton1->Checked=true;
  }
 if (mod==2)
   {
    GroupBox1->Caption = "Vertical";
    RadioButton1->Caption = "Haut";
    RadioButton2->Caption = "Centre";
    RadioButton3->Caption = "Bas";
    c=jv[0];
    
    if (c=='H') RadioButton1->Checked=true;
    else if (c=='C') RadioButton2->Checked=true;
    else if (c=='B') RadioButton3->Checked=true;
    else RadioButton1->Checked=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TJust::btAnnulClick(TObject *Sender)
{
 char tmp[100];
 if (mod==1) { strcpy(tmp,"<jh>");  strcat(tmp,jh); strcat(tmp,"</jh>"); }
 if (mod==2) { strcat(tmp,"<jv>");  strcat(tmp,jv); strcat(tmp,"</jv>"); }
 strcpy(m_exchange,"");
 Close();

}
//---------------------------------------------------------------------------
void __fastcall TJust::btOKClick(TObject *Sender)
{
 char tmp[100];
if (mod==1)
 {
 strcpy (tmp,"<jh>");
 if (RadioButton1->Checked == true) strcat(tmp,"Gauche");
 if (RadioButton2->Checked == true) strcat(tmp,"Centre");
 if (RadioButton3->Checked == true) strcat(tmp,"Droite");
 strcat(tmp,"</jh>");
 }
if (mod==2)
{
 strcat (tmp,"<jv>");
 if (RadioButton1->Checked == true) strcat(tmp,"Haut");
 if (RadioButton2->Checked == true) strcat(tmp,"Centre");
 if (RadioButton3->Checked == true) strcat(tmp,"Bas");
 strcat(tmp,"</jv>");
 }
 strcpy(m_exchange,tmp);
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TJust::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl43");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

