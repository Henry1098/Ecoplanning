//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modRetrait.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRetrait *Retrait;
//---------------------------------------------------------------------------
__fastcall TRetrait::TRetrait(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall TRetrait::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TRetrait::FormCreate(TObject *Sender)
{
 ExtractValue(Mem,m_params,"rh",0);
 Edit1->Text=AnsiString(Mem);
}
//---------------------------------------------------------------------------
void __fastcall TRetrait::Button1Click(TObject *Sender)
{
char tmp[250];

 strcpy(tmp,"<rh>");
 strcat(tmp,Edit1->Text.c_str());
 strcat(tmp,"</rh>");

 strcpy(m_reports,tmp);
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TRetrait::Button2Click(TObject *Sender)
{
 char tmp[250];

 strcpy(tmp,"<rh>");
 strcat(tmp,Mem);
 strcat(tmp,"</rh>");

 strcpy(m_reports,tmp);
 Close();
}
//---------------------------------------------------------------------------
