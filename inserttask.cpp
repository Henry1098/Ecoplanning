//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inserttask.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewTask *NewTask;
//---------------------------------------------------------------------------
__fastcall TNewTask::TNewTask(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNewTask::FormCreate(TObject *Sender)
{
 Edit3->SetTextBuf(m_exchange);
 Edit1->SetTextBuf(m_exchange2);
}
//---------------------------------------------------------------------------
void __fastcall TNewTask::Button2Click(TObject *Sender)
{
 m_exchange[0]=0;
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TNewTask::Button1Click(TObject *Sender)
{
 char tmp[200];
 // passage du texte et param dans exchange;
 sprintf(tmp,"<numero>%s</numero><libel>%s</libel><duree>%s</duree>",
     Edit3->Text.c_str(),Edit1->Text.c_str(),Edit2->Text.c_str());
 strcpy(m_exchange,tmp);
 Close();
}
//---------------------------------------------------------------------------


