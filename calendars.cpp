//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop                                                   

#include "modHelp.h"
#include "calendars.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfCalendar *fCalendar;
//---------------------------------------------------------------------------
__fastcall TfCalendar::TfCalendar(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall TfCalendar::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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



void __fastcall TfCalendar::InitCalendar()
{
char Key[30];
int recdata,rc;
char datarec[255];
 // Calendrier 1  Week ends normaux
strcpy(Key,"01-0000-00-00"); recdata=cals->GetNewRecordNumber();
rc = cals->WriteKey(0,Key,recdata);
strcpy(datarec,"<WE>TTTTTNN</WE>");
rc = cals->WriteRecord(datarec,strlen(datarec)+1);


 // Calendrier 2  Pas de Week Ends
strcpy(Key,"02-0000-00-00"); recdata=cals->GetNewRecordNumber();
rc = cals->WriteKey(0,Key,recdata);
strcpy(datarec,"<WE>TTTTTTT</WE>");
rc = cals->WriteRecord(datarec,strlen(datarec)+1);

 // Calendrier 3  Week end normaux
 strcpy(Key,"03-0000-00-00"); recdata=cals->GetNewRecordNumber();
rc = cals->WriteKey(0,Key,recdata);
strcpy(datarec,"<WE>TTTTTNN</WE>");
rc = cals->WriteRecord(datarec,strlen(datarec)+1);

 // Calendrier 4  Week end normaux
 strcpy(Key,"04-0000-00-00"); recdata=cals->GetNewRecordNumber();
rc = cals->WriteKey(0,Key,recdata);
strcpy(datarec,"<WE>TTTTTNN</WE>");
rc = cals->WriteRecord(datarec,strlen(datarec)+1);

 // Calendrier 5  Week en Normaux
strcpy(Key,"05-0000-00-00"); recdata=cals->GetNewRecordNumber();
rc = cals->WriteKey(0,Key,recdata);
strcpy(datarec,"<WE>TTTTTNN</WE>");
rc = cals->WriteRecord(datarec,strlen(datarec)+1);
 // rester sur calendrier 1
 cb1->Checked = false;
 cb2->Checked = false;
 cb3->Checked = false;
 cb4->Checked = false;
 cb5->Checked = false;
 cb6->Checked = true;
 cb7->Checked = true;

}

void __fastcall TfCalendar::FormCreate(TObject *Sender)
{
  int rc,nbk;
  char tmp[250];


  TDateTime dtPresent = Now();
  DecodeDate(dtPresent, Year, Month, Day);
  cals = new realisam();
  strcpy(tmp,m_directory); strcat(tmp,"\\calend");
  rc = cals->OpenEngine(tmp,56,"ndx","dat");   //64 - 8
  rc = cals->SetIndexMode(0,0);
  nbk = cals->NumberOfKeys(0);
  if (nbk==0)
     InitCalendar();

  num_cal=0;
  m_changed=0;
  w_changed=0;
  strcpy(cal_name,"Standard");
  ComboBox1->Text="Standard";
  num_cal=1;
  DisplayCalendar(Year,Month,1,num_cal);
}
//---------------------------------------------------------------------------

void __fastcall TfCalendar::DisplayCalendar(Word Year,Word Month, Word Day,int numc)
{
  TDateTime dtFirst;
  char txt[100];
  char jt[20];
  int recdata,rc;
  char buffer[2000];
  char ikey[50];
  char RetKey[50];
  char OldNT[35];
  char tmp[2000];

  if (num_cal==0) return;
  char days[7][10] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
  "Samedi" };
  char months[12][15] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet",
   "Aout","Septembre","Octobre","Novembre","Décembre"};
  int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  lMonth->Caption = AnsiString(months[Month-1]) + " " +  IntToStr(Year);
  dtFirst = EncodeDate(Year,Month,1);     // first of the month

  sprintf(ikey,"%02d-0000-00-00",num_cal);   // clef pour determiner WE
  rc = cals->ReadDirectKey(0,ikey,RetKey,&recdata);
  if (rc)  // ok : clé trouvée
  {
   cb1->Checked = false;
   cb2->Checked = false;
   cb3->Checked = false;
   cb4->Checked = false;
   cb5->Checked = false;
   cb6->Checked = false;
   cb7->Checked = false;
   rc = cals->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   if (buffer[4]=='N') cb1->Checked=true;
   if (buffer[5]=='N') cb2->Checked=true;
   if (buffer[6]=='N') cb3->Checked=true;
   if (buffer[7]=='N') cb4->Checked=true;
   if (buffer[8]=='N') cb5->Checked=true;
   if (buffer[9]=='N') cb6->Checked=true;
   if (buffer[10]=='N') cb7->Checked=true;
   rc = ExtractValue(tmp,buffer,"COM",0);
   mComment->SetTextBuf(tmp);
   // Edit1->Text=AnsiString(tmp);
  }

  lbCal->Clear();
  int counter = nbdays[Month-1];
  if (Month==2){ if (IsLeapYear(Year)) counter = 29;}
  // on a besoin de savoir le 1er jour du mois
  int firstday = dtFirst.DayOfWeek();
  int i; int dow;  // day of week
  dow = firstday-1;

   for (i=0;i<counter;i++)
     {
      //if (c[i]=='X')
      // {
        strcpy(jt,"");
        // determine si Jour Travaillé ou non
       if ((strcmp(days[dow],"Lundi")==0))
         if (cb1->Checked==false) { strcpy(jt,"\t\t\tJT"); c[i]='T'; }
              else { strcpy(jt,"\t\t\tJNT"); c[i]='N'; }
      if ((strcmp(days[dow],"Mardi")==0))
         if (cb2->Checked==false) { strcpy(jt,"\t\t\tJT"); c[i]='T'; }
              else { strcpy(jt,"\t\t\tJNT"); c[i]='N'; }
     if ((strcmp(days[dow],"Mercredi")==0))
         if (cb3->Checked==false) { strcpy(jt,"\t\tJT"); c[i]='T'; }
              else { strcpy(jt,"\t\tJNT"); c[i]='N'; }
     if ((strcmp(days[dow],"Jeudi")==0))
         if (cb4->Checked==false) { strcpy(jt,"\t\t\tJT"); c[i]='T'; }
              else { strcpy(jt,"\t\t\tJNT"); c[i]='N'; }
     if ((strcmp(days[dow],"Vendredi")==0))
         if (cb5->Checked==false) { strcpy(jt,"\t\tJT"); c[i]='T'; }
              else { strcpy(jt,"\t\tJNT"); c[i]='N'; }
     if ((strcmp(days[dow],"Samedi")==0))
         if (cb6->Checked==false) { strcpy(jt,"\t\tJT"); c[i]='T'; }
              else { strcpy(jt,"\t\tJNT"); c[i]='N'; }
     if ((strcmp(days[dow],"Dimanche")==0))
         if (cb7->Checked==false) { strcpy(jt,"\tJT"); c[i]='T'; }
              else { strcpy(jt,"\tJNT"); c[i]='N'; }
      //   }  // c []==X

      // on verifie si le jour était marqué spécial
       sprintf(ikey,"%02d-%04d-%02d-%02d",num_cal,Year,Month,i+1);
       rc = cals->ReadDirectKey(0,ikey,RetKey,&recdata);
       if (rc)    // il existe des modifs apportées
          {
            rc = cals->ReadRecord(buffer,recdata);
            buffer[rc]=0;
            // format xx-xxxx-xx-xx-T    T ou N
            if (buffer[13]=='T')
              { if ((strcmp(days[dow],"Lundi")==0)) strcpy(jt,"\t\t\tJT");
                if ((strcmp(days[dow],"Mardi")==0)) strcpy(jt,"\t\t\tJT");
                if ((strcmp(days[dow],"Mercredi")==0)) strcpy(jt,"\t\tJT");
                if ((strcmp(days[dow],"Jeudi")==0)) strcpy(jt,"\t\t\tJT");
                if ((strcmp(days[dow],"Vendredi")==0))strcpy(jt,"\t\tJT");
                if ((strcmp(days[dow],"Samedi")==0)) strcpy(jt,"\t\tJT");
                if ((strcmp(days[dow],"Dimanche")==0)) strcpy(jt,"\tJT");
              }
            else
              {
               if ((strcmp(days[dow],"Lundi")==0)) strcpy(jt,"\t\t\tJNT");
                if ((strcmp(days[dow],"Mardi")==0)) strcpy(jt,"\t\t\tJNT");
                if ((strcmp(days[dow],"Mercredi")==0)) strcpy(jt,"\t\tJNT");
                if ((strcmp(days[dow],"Jeudi")==0)) strcpy(jt,"\t\t\tJNT");
                if ((strcmp(days[dow],"Vendredi")==0))strcpy(jt,"\t\tJNT");
                if ((strcmp(days[dow],"Samedi")==0)) strcpy(jt,"\t\tJNT");
                if ((strcmp(days[dow],"Dimanche")==0)) strcpy(jt,"\tJNT");
              }
       }  // RC

     sprintf(txt,"%02d \t%s %s ", i+1,days[dow],jt);
     lbCal->Items->Add(AnsiString(txt));
     dow++; if (dow>6) dow=0;
    }  // for
}
void __fastcall TfCalendar::BitBtn2Click(TObject *Sender)
{
  Month--;
 if (Month==0)
    { Month = 12;
      Year= Year-1;
    }
 DisplayCalendar(Year,Month,1,num_cal);
}
//---------------------------------------------------------------------------
void __fastcall TfCalendar::BitBtn3Click(TObject *Sender)
{
 Month++;
 if (Month > 12)
   {
    Month=1;
    Year++;
   }
 DisplayCalendar(Year,Month,1,num_cal);
}
//---------------------------------------------------------------------------
void __fastcall TfCalendar::BitBtn1Click(TObject *Sender)
{
 Year--;
 DisplayCalendar(Year,Month,1,num_cal);
}
//---------------------------------------------------------------------------
void __fastcall TfCalendar::BitBtn4Click(TObject *Sender)
{
 Year++;
 DisplayCalendar(Year,Month,1,num_cal);
}
//---------------------------------------------------------------------------
void __fastcall TfCalendar::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 cals->CloseEngine(); cals->~realisam();
 Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfCalendar::lbCalDblClick(TObject *Sender)
{
 // determine  l'item   et inverse le  status JNT
 AnsiString Txt;
 char txt[100];
 int indx;
 char *pos;
 char jnt;
 char tmp[120];

 char Key[20],RetKey[20];
 int recdata, rc;

  if (num_cal==0) return;
 indx = lbCal->ItemIndex;
 strcpy(txt,lbCal->Items->Strings[indx].c_str());
 pos = strstr(txt,"JT");
 if (pos) {*pos=0; strcat (txt,"JNT"); jnt='N';}
   else
     { pos = strstr(txt,"JNT");
       if (pos) { *pos=0; strcat(txt,"JT"); jnt='T';}
     }
 lbCal->Items->Strings[indx]= AnsiString(txt);
 // memorisation dans un bloc
 c[indx]=jnt;
 m_changed=1;
 // write modification in the data base
 sprintf(tmp,"%02d-%04d-%02d-%02d",num_cal,Year,Month,indx+1);
 strcpy(Key,tmp);
 strcpy(tmp,Key); if (jnt == 'T') strcat(tmp,"T"); else strcat(tmp,"N");
 rc = cals->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) // rewrite
   {
    rc = cals->RewriteRecord(tmp, strlen(tmp)+1,recdata);
   }
  else
   {
    recdata=cals->GetNewRecordNumber();
    rc = cals->WriteKey(0,Key,recdata);
    rc=cals->WriteRecord(tmp,strlen(tmp)+1);
   }

 }
//---------------------------------------------------------------------------

void __fastcall TfCalendar::ComboBox1Click(TObject *Sender)
{


 cb1->Checked = false;
 cb2->Checked = false;
 cb3->Checked = false;
 cb4->Checked = false;
 cb5->Checked = false;
 cb6->Checked = false;
 cb7->Checked = false;

 strcpy(cal_name,ComboBox1->Text.c_str());
 if (strcmp(cal_name,"Standard")==0)
     {num_cal=1;

     }
if (strcmp(cal_name,"Semaines Continues")==0)
     {
      num_cal=2;
     }

if (strcmp(cal_name,"Calendrier 3")==0)
     {
      num_cal=3;
     }
if (strcmp(cal_name,"Calendrier 4")==0)
     {
      num_cal=4;
     }
if (strcmp(cal_name,"Calendrier 5")==0)
     {
      num_cal=5;
     }
if (num_cal != 0)
 DisplayCalendar(Year,Month,1,num_cal);
}
//---------------------------------------------------------------------------



void __fastcall TfCalendar::update_we()
{
 // lire record WE du calendrier
char Key[30],RetKey[30];
int recdata,rc;
char tmp[255];
int len;
 // Calendrier 1  Week ends normaux

if (num_cal==0) return;

strcpy(tmp,"<WE>TTTTTTT</WE>");
if (cb1->Checked == true) tmp[4]='N';
if (cb2->Checked == true) tmp[5]='N';
if (cb3->Checked == true) tmp[6]='N';
if (cb4->Checked == true) tmp[7]='N';
if (cb5->Checked == true) tmp[8]='N';
if (cb6->Checked == true) tmp[9]='N';
if (cb7->Checked == true) tmp[10]='N';

strcpy(w,tmp+4);
w[7]=0;
strcat(tmp,"<COM>"); strcat(tmp,mComment->Lines->GetText());
strcat(tmp,"</COM> ");
 sprintf(Key,"%02d-0000-00-00",num_cal);
rc = cals->ReadDirectKey(0,Key,RetKey,&recdata);

if (rc) rc = cals->RewriteRecord(tmp, strlen(tmp)+1,recdata);
  else
   {
    recdata=cals->GetNewRecordNumber();
    rc = cals->WriteKey(0,Key,recdata);
    rc=cals->WriteRecord(tmp,strlen(tmp)+1);
   }
 DisplayCalendar(Year,Month,1,num_cal);
}


void __fastcall TfCalendar::Button1Click(TObject *Sender)
{
 update_we();
}
//---------------------------------------------------------------------------

void __fastcall TfCalendar::Button2Click(TObject *Sender)
{
 update_we();
 Application->MessageBoxA("Recharger le Projet en Cours si vous avez Modifié le Calendrier",m_ecoplan,MB_OK);
 Close();
}
//---------------------------------------------------------------------------



void __fastcall TfCalendar::btAideClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCalendar::Button4Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre532");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

