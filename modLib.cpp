//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modLib.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLibel *Libel;
//---------------------------------------------------------------------------
__fastcall TLibel::TLibel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLibel::FormCreate(TObject *Sender)
{
 // On extrait le libellé de m_params
 ExtractValue(Mem,m_params,"li",0);
 Edit1->Text=AnsiString(Mem);
}
//---------------------------------------------------------------------------


int __fastcall TLibel::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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
void __fastcall TLibel::btOKClick(TObject *Sender)
{
 char tmp[250];

 strcpy(tmp,"<li>");
 strcat(tmp,Edit1->Text.c_str());
 strcat(tmp,"</li>");

 strcpy(m_reports,tmp);
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TLibel::btAnnulClick(TObject *Sender)
{
  char tmp[250];

 strcpy(tmp,"<li>");
 strcat(tmp,Mem);
 strcat(tmp,"</li>");

 strcpy(m_reports,tmp);
 Close();
}
//---------------------------------------------------------------------------
