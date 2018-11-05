//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AffCal.h"
#include <stdio.h>
#include "modHelp.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAffectCal *AffectCal;
//---------------------------------------------------------------------------
__fastcall TAffectCal::TAffectCal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TAffectCal::AnnulClick(TObject *Sender)
{
 strcpy(m_exchange,"<null>TRUE</null>");
 Close();
}
//---------------------------------------------------------------------------

int __fastcall TAffectCal::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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



void __fastcall TAffectCal::AffectClick(TObject *Sender)
{
char tmp[250]; int i;

i = ComboBox1->ItemIndex;
if (i<0 || i>4)
   {
   Application->MessageBoxA("Pas de Calendrier sélectionné","Ecoplanning",MB_OK);
   return;
   }
 // sprintf(tmp,"%d",i+1);
 itoa(i+1,tmp,10);
 strcpy(m_exchange,"<ncal>"); strcat(m_exchange,tmp); strcat(m_exchange,"</ncal>");
 if (CheckBox1->Checked==true) strcat(m_exchange,"<decoch>O</decoch>");
      else strcat (m_exchange,"<decoch>N</decoch>");
 // WriteExchange(1);
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TAffectCal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 cals->CloseEngine(); cals->~realisam();
 Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TAffectCal::ComboBox1Change(TObject *Sender)
{
 int i;
 i = ComboBox1->ItemIndex + 1;
 Memo1->SetTextBuf(comments[i]);
}
//---------------------------------------------------------------------------

void __fastcall TAffectCal::Timer1Timer(TObject *Sender)
{
int tach,rc,nbk;
 char ikey[20];
 char RetKey[100];
 int recdata;
 char buffer[2000];
 int num_cal;
 char tmp[2000];

  if (step==0)
    {
     Timer1->Enabled=false;
      step=0;
      cals = new realisam();
      strcpy(tmp,m_directory); strcat(tmp,"\\calend");
      rc = cals->OpenEngine(tmp,56,"ndx","dat");   //64 - 8
      //rc = cals->OpenEngine("calend",56,"ndx","dat");   //64 - 8
      rc = cals->SetIndexMode(0,0);
      nbk = cals->NumberOfKeys(0);
     for (num_cal=1;num_cal <= 5; num_cal++)
     {
      sprintf(ikey,"%02d-0000-00-00",num_cal);   // clef pour determiner WE
      rc = cals->ReadDirectKey(0,ikey,RetKey,&recdata);
      if (rc)  //
        {
          rc = cals->ReadRecord(buffer,recdata);
          buffer[rc]=0;
          rc = ExtractValue(tmp,buffer,"COM",0);
          strcpy(comments[num_cal],tmp);
          //  Memo1->SetTextBuf(tmp);
          sprintf (tmp,"Calendrier %d",num_cal);
          ComboBox1->Items->Add(AnsiString(tmp));

        }
     }
  }





}
//---------------------------------------------------------------------------

void __fastcall TAffectCal::FormCreate(TObject *Sender)
{
 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TAffectCal::AideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre531");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

