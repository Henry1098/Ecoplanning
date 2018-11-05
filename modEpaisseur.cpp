//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modEpaisseur.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDEpaisseur *FDEpaisseur;
//---------------------------------------------------------------------------
__fastcall TFDEpaisseur::TFDEpaisseur(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDEpaisseur::FormCreate(TObject *Sender)
{
 // extract value in m_exchange
 char tmp[200];
 ExtractValue(tmp,m_exchange,"ep",0);
 cbE->Text=AnsiString(tmp);
}
//---------------------------------------------------------------------------

int __fastcall TFDEpaisseur::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TFDEpaisseur::btAnnulClick(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDEpaisseur::btOKClick(TObject *Sender)
{
 strcpy(m_exchange,"<ep>"); strcat(m_exchange,cbE->Text.c_str());
 strcat(m_exchange,"</ep>");
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDEpaisseur::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl451");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

