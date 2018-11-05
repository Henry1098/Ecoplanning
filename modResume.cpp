//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "globals.h"
#include "modResume.h"
#include "modCriteres.h"
#include "modHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResume *Resume;
//---------------------------------------------------------------------------
__fastcall TResume::TResume(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TResume::btAnnulClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TResume::btOKClick(TObject *Sender)
{
 char tmp[2500];
 strcpy(TITRE,Edit1->Text.c_str());
 Memo1->GetTextBuf(tmp,1800);
 strcpy(OBSERV,tmp);
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TResume::btCriteresClick(TObject *Sender)
{
 TCriteres *Criteres;
 Criteres = new TCriteres(Application);
 Criteres->Height=652;
 Criteres->Width=882;
 Criteres->Show(); //Modal();
 // delete Criteres;
}
//---------------------------------------------------------------------------

void __fastcall TResume::FormShow(TObject *Sender)
{
 char tmp[100];
 Label21->Caption=CRITERES[0];
 Label22->Caption=CRITERES[1];
 Label23->Caption=CRITERES[2];
 Label24->Caption=CRITERES[3];
 Label25->Caption=CRITERES[4];
 Label26->Caption=CRITERES[5];
 Label27->Caption=CRITERES[6];
 Label28->Caption=CRITERES[7];

 Label36->Caption=LIB_CRITERES[0];
 Label37->Caption=LIB_CRITERES[1];
 Label38->Caption=LIB_CRITERES[2];
 Label39->Caption=LIB_CRITERES[3];
 Label40->Caption=LIB_CRITERES[4];
 Label41->Caption=LIB_CRITERES[5];
 Label42->Caption=LIB_CRITERES[6];
 Label43->Caption=LIB_CRITERES[7];

 Label13->Visible = false;
 Label14->Visible = false;
 Label15->Visible = false;
 Label16->Visible = false;
 Label17->Visible = false;
 Label24->Visible = false;
 Label25->Visible = false;
 Label26->Visible = false;
 Label27->Visible = false;
 Label28->Visible = false;
 Label39->Visible = false;
 Label40->Visible = false;
 Label41->Visible = false;
 Label42->Visible = false;
 Label43->Visible = false;

 // Date de Debut Previ
 sprintf(tmp,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 Label32->Caption = AnsiString(tmp);
 // Date de Fin Prev
sprintf(tmp,"%02d/%02d/%02d",JourFin,MoisFin,AnFin%100);
 Label33->Caption = AnsiString(tmp);
 lnbT->Caption = NB_TACHES;

 Label34->Caption=Label32->Caption;
 Label35->Caption=DTFINREEL; // Label33->Caption;



 Edit1->Text = AnsiString(TITRE);
 Memo1->SetTextBuf(OBSERV);

 sprintf(tmp,"%.2f",TOTAL_NEG);
 Label29->Caption = AnsiString(tmp);
 sprintf(tmp,"%.2f",TOTAL_POS);
 Label30->Caption = AnsiString(tmp);
}
//---------------------------------------------------------------------------

void __fastcall TResume::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreateModif.html#Cre7");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

