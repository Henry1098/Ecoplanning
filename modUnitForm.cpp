//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modUnitForm.h"
#include "globals.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDUnitForm *FDUnitForm;
//---------------------------------------------------------------------------
__fastcall TFDUnitForm::TFDUnitForm(TComponent* Owner)
        : TForm(Owner)
{

}

int __fastcall TFDUnitForm::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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


int __fastcall TFDUnitForm::Load_cb(AnsiString Unt)
{

 cbForm->Clear();
 cbUnit->Text=unite;
 cbForm->Text=format;


 if (Unt=="Jour")
   {
    cbForm->Items->Add("Vendredi");
    cbForm->Items->Add("Ven");
    cbForm->Items->Add("V");
    cbForm->Items->Add("31/01/05");
    cbForm->Items->Add("31/01");
    cbForm->Items->Add("1,2...");
    cbForm->Items->Add("Jour 1, Jour 2...");
    cbForm->Items->Add("Aucun");
   }


 if (Unt=="Semaine")
   {
    cbForm->Items->Add("31 Janvier 05");
    cbForm->Items->Add("31 Jan 05");
    cbForm->Items->Add("31 Janvier");

    cbForm->Items->Add("31 J");
    cbForm->Items->Add("31/01/05");
    cbForm->Items->Add("31/01");
    cbForm->Items->Add("1,2,...52");
    cbForm->Items->Add("Semaine 1,Semaine 2,..");
    cbForm->Items->Add("Aucun");
   }


 if (Unt=="Mois")
   {
    cbForm->Items->Add("Janvier 05");
    cbForm->Items->Add("Jan 05");
    cbForm->Items->Add("Jan");
    cbForm->Items->Add("J 05");
    cbForm->Items->Add("J");
    cbForm->Items->Add("1,2,3...");
    cbForm->Items->Add("1-12,1-12..");
    cbForm->Items->Add("1-12,13,...");
    cbForm->Items->Add("Mois 1, Mois 2...");
    cbForm->Items->Add("Mois 1 - Mois 12, Mois 13...");
    cbForm->Items->Add("Aucun");
   }

 if (Unt=="Trimestre")
   {
    cbForm->Items->Add("Tri 1 05");
    cbForm->Items->Add("Tri 1");
    cbForm->Items->Add("T1 05");
    cbForm->Items->Add("1T 05");
    cbForm->Items->Add("1,2,3,4");
    cbForm->Items->Add("1..4,1..4");
    cbForm->Items->Add("Trimestre 1, Trimestre 2,...");
    cbForm->Items->Add("Aucun");
   }

 if (Unt=="Année")
   {
    cbForm->Items->Add("2005");
    cbForm->Items->Add("05");
    cbForm->Items->Add("Année 1-Année 2...");
    cbForm->Items->Add("Aucun");
   }
 return 0;
}


//---------------------------------------------------------------------------
void __fastcall TFDUnitForm::cbUnitClick(TObject *Sender)
{
 if (cbUnit->ItemIndex==-1) return;
 cbUnit->Text=cbUnit->Items->Strings[cbUnit->ItemIndex];
 Load_cb(cbUnit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFDUnitForm::cbFormClick(TObject *Sender)
{
 if (cbForm->ItemIndex==-1) return;
 cbForm->Text=cbForm->Items->Strings[cbForm->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TFDUnitForm::btAnnulClick(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDUnitForm::btOKClick(TObject *Sender)
{
 char tmp[200];
 char unt[50];
 char fmt[50];
 strcpy(unt,cbUnit->Text.c_str());
 if (strlen(unt)==0)
  {
   Application->MessageBoxA("Pas d'unité définie",m_ecoplan,MB_OK);
   return;
  }

 strcpy(fmt,cbForm->Text.c_str());
 if (strlen(fmt)==0)
  {
   Application->MessageBoxA("Pas de format défini",m_ecoplan,MB_OK);
   return;
  }

 strcpy(tmp,"<unit>"); strcat(tmp,unt); strcat(tmp,"</unit>");
 strcat(tmp,"<form>"); strcat(tmp,fmt); strcat(tmp,"</form>");
 strcpy(m_exchange,tmp);
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDUnitForm::FormShow(TObject *Sender)
{
 char tmp[250];

 ExtractValue(tmp,m_exchange,"unit",0);
 unite = AnsiString(tmp);
 ExtractValue(tmp,m_exchange,"form",0);
 format = AnsiString(tmp);
 cbUnit->Text=unite;
 cbForm->Text=format;
 Load_cb(unite);

}
//---------------------------------------------------------------------------

void __fastcall TFDUnitForm::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl44");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

