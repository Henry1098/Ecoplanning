//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modregistr.h"
// #include "blowfish.h"
#include "globals.h"

#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegist *Regist;
//---------------------------------------------------------------------------
__fastcall TRegist::TRegist(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TRegist::Enum_MAC()
{
  int nb,retc;
  LANA_ENUM AdapterList;
  NCB Ncb;
  //  AnsiString mac_addr;

  memset(&Ncb, 0, sizeof(NCB));
  Ncb.ncb_command = NCBENUM;
  Ncb.ncb_buffer = (unsigned char *)&AdapterList;
  Ncb.ncb_length = sizeof(AdapterList);
  retc = Netbios(&Ncb);
  if( retc != NRC_GOODRET)
    {
     Application->MessageBoxA("Command NCBENUM not Accepted","AVSA",MB_OK);
     return;
    }
  // Get all of the local ethernet addresses

   nb = AdapterList.length;

  for (int i = 0; i < AdapterList.length ; ++i)
  {
    if (GetAdapterInfo(AdapterList.lana[i], mac_addr))
    {

      if (i==0)  {  edMAC->Text = mac_addr;   strcpy(MAC_ADDR,mac_addr.c_str()); }
      //  Application->MessageBoxA(mac_addr.c_str(),m_toptel,MB_OK);

    }
    else
    {
      Application->MessageBoxA("MAC Address not Found (Netbios Not Installed ?)","AVSA",MB_OK);

      break;
    }
  }
}

bool __fastcall TRegist::GetAdapterInfo(int adapter_num, AnsiString &mac_addr)
{
    // Reset the LAN adapter so that we can begin querying it
  NCB Ncb;
  memset(&Ncb, 0, sizeof(Ncb));
  Ncb.ncb_command = NCBRESET;
  Ncb.ncb_lana_num = adapter_num;
  if (Netbios(&Ncb) != NRC_GOODRET) {
    mac_addr = "bad (NCBRESET): ";
    mac_addr += AnsiString(Ncb.ncb_retcode);
    return false;
  }

  // Prepare to get the adapter status block
  memset(&Ncb,0,sizeof(Ncb));
  // bzero(&Ncb,sizeof(Ncb);
  Ncb.ncb_command = NCBASTAT;
  Ncb.ncb_lana_num = adapter_num;
  strcpy((char *) Ncb.ncb_callname, "*");
  struct ASTAT
  {
    ADAPTER_STATUS adapt;
    NAME_BUFFER NameBuff[30];
  } Adapter;
  memset(&Adapter,0,sizeof(Adapter));
  Ncb.ncb_buffer = (unsigned char *)&Adapter;
  Ncb.ncb_length = sizeof(Adapter);

  // Get the adapter's info and, if this works, return it in standard,
  // colon-delimited form.
  if (Netbios(&Ncb) == 0)
  {
    char acMAC[18];
    sprintf(acMAC, "%02X:%02X:%02X:%02X:%02X:%02X",
            int (Adapter.adapt.adapter_address[0]),
            int (Adapter.adapt.adapter_address[1]),
            int (Adapter.adapt.adapter_address[2]),
            int (Adapter.adapt.adapter_address[3]),
            int (Adapter.adapt.adapter_address[4]),
            int (Adapter.adapt.adapter_address[5]));
    mac_addr = acMAC;
    return true;
  }
  else
  {
    mac_addr = "bad (NCBASTAT): ";
    mac_addr += AnsiString(Ncb.ncb_retcode);
    return false;
  }
}

void __fastcall TRegist::FormShow(TObject *Sender)
{
 Enum_MAC();                   

}
//---------------------------------------------------------------------------

// Inp and out should at least 512 chars
void __fastcall TRegist::EncodeHexa(char *inp, char *out)
{


}

void __fastcall TRegist::DecodeHexa(char *inp, char *out)
{



}









void __fastcall TRegist::Button1Click(TObject *Sender)
{
 int i,l;   char tmp[500];
 FILE *fp; char *p;  char str[50];
 int year,month, day;
 char filename[MAX_PATH];
 AnsiString HomeDir;
 char HomeDirectory[MAX_PATH];
 char mess[250];
 int shift;

 strcpy(LK,edLK->Text.c_str());
 if (strlen(LK)==0)
    {
     Application->MessageBox("Clé de licence non trouvée","Ecoplanning",MB_OK);
     return;
    }
 l=strlen(LK);

 shift=LK[0] - 65;


 for (i=1;i<=l;i++)  LK[i]=LK[i]-shift;
 Label5->Caption = AnsiString(LK);
 ExtractValue(tmp,LK,"m",0);

 Label6->Caption = AnsiString(MAC_ADDR);
 if (strcmp(MAC_ADDR,tmp) != 0)
    {
     Application->MessageBox("Clé de licence pas compatible","Ecoplanning",MB_OK); // "Licence key doesn't match your Client Code"
     return;
    }
 ExtractValue(EXPDATE,LK,"e",0);   // Expiration date
 if (strlen(EXPDATE) != 10)
     {
      Application->MessageBox("Format de la date incorrect","Ecoplanning",MB_OK);  // "Invalid date format"
      return;
     }
  strcpy(tmp,EXPDATE);
  p=tmp;
  tmp[4]=0; tmp[7]=0;
  strcpy(str,p);   year = atoi(str);

  p=p+5; strcpy(str,p);   month = atoi(str);

  p=p+3; strcpy(str,p);   day = atoi(str);


  if (year < 2010)
      {
      Application->MessageBox("Année incorrecte","Ecoplanning",MB_OK);    // "Invalid year"
      return;
      }
  if (month < 1 || month>13)
      {
      Application->MessageBox("Mois incorrect","Ecoplanning",MB_OK);  // "Invalid Month"
      return;
      }
  if (day < 1 || day>31)
      {
      Application->MessageBox("Jour incorrect","Ecoplanning",MB_OK);   // "Invalid Day"
      return;
      }

// Write LK in a file
  strcpy(LK,edLK->Text.c_str());
  strcat(LK,"\n");
  HomeDir= GetCurrentDir();
  strcpy(HomeDirectory,HomeDir.c_str());
  strcpy(filename,HomeDirectory); strcat (filename,"\\cst.sys");

  fp = fopen(filename,"wb");
  if (fp==NULL)
     {
      Application->MessageBox("Erreur à l'ouverture du fichier CST.SYS","Ecoplanning",MB_OK);  // "Error opening CST.SYS file"
      return;
     }
  fputs(LK,fp);
  fclose(fp);


  strcpy(mess,"Votre logiciel est correctement enregistré ");
  strcpy(mess,"\n");                 // "Your software is correctly registered
  strcat(mess,"Votre date d'expiration est : ");  // "Your expiration date is (YYYY/MM/DD): "
  strcat(mess,EXPDATE);
 Application->MessageBox(mess,"Ecoplanning",MB_OK);
 LICKEY=true;
 Close();
 return;
}
//---------------------------------------------------------------------------


int __fastcall TRegist::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{ char tmp[250];char *p,*p1,*p2; int pos,l;

 result[0]=0; strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">"); p = strstr(buff,tmp);
 l=0;
 if (p)
   {strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">");p1= strstr(buff,tmp);
    if (p1) {p2=p + strlen(tag)+2; l= p1-p2; strncpy(result,p2,l); result[l]=0; }
   }
 return l;
}
void __fastcall TRegist::FormCreate(TObject *Sender)
{
 // Lecture des labels
 Button1->Caption = "Enregistrez votre clé";
 Label1->Caption = "Notez votre code client";
 Label2->Caption = "Veuillez transmettre ce code client à Ecoplanning";
 Label3->Caption = "En retour, vous recevrez une clé de licence";
 Label4->Caption = "Entrez la clé de licence";
 LICKEY=false;


}
//---------------------------------------------------------------------------

void __fastcall TRegist::Button2Click(TObject *Sender)
{
LICKEY=false;
Close();        
}
//---------------------------------------------------------------------------

