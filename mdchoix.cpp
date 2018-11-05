//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mdchoix.h"
#include "globals.h"
#include "modFilter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmodChoix *modChoix;
//---------------------------------------------------------------------------
__fastcall TmodChoix::TmodChoix(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TmodChoix::Button1Click(TObject *Sender)
{
TxFilter *filt;
 char tmp[250];
 char strfilter[100];

 strcpy(m_exchange,"utiliser");

 strcpy(m_project,DatabaseName);
 filt = new TxFilter(Application);
 filt->Height = 705;
 filt->Width = 774;

//  filt->Visible=true;
 m_filtre[0]=0;
 filt->Show(); //Modal();
 //delete filt;
}
//---------------------------------------------------------------------------

void __fastcall TmodChoix::Button2Click(TObject *Sender)
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
void __fastcall TmodChoix::Button5Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
