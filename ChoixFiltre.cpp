//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChoixFiltre.h"
#include "globals.h"
#include "modFilter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChoix *Choix;
//---------------------------------------------------------------------------
__fastcall TChoix::TChoix(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChoix::Button1Click(TObject *Sender)
{
 TxFilter *filt;
 char tmp[250];
 char strfilter[100];

 strcpy(m_exchange,"utiliser");

 strcpy(m_project,DatabaseName);
 filt = new TxFilter(Application);

//  filt->Visible=true;
 m_filtre[0]=0;
 filt->Show(); //Modal();
 //delete filt;
 }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TChoix::Button5Click(TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------
void __fastcall TChoix::Button2Click(TObject *Sender)
{
 TxFilter *filt;
 char tmp[250];
 char strfilter[100];

 strcpy(m_exchange,"completer");

 strcpy(m_project,DatabaseName);
 filt = new TxFilter(Application);

//  filt->Visible=true;
 m_filtre[0]=0;
 filt->Show();  //Modal();
 // delete filt;
}
//---------------------------------------------------------------------------
