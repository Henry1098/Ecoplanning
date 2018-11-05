//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modAffTC.h"
#include "plstd.h"
#include "globals.h"
#include "modHelp.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAffData *AffData;
TplStandard *plST;
//---------------------------------------------------------------------------
__fastcall TAffData::TAffData(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAffData::Button2Click(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TAffData::FormClose(TObject *Sender, TCloseAction &Action)
{
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TAffData::Button1Click(TObject *Sender)
{
 char champ[200],tmp[200],cod[100],des[200]; char *p;  char col[10];
 strcpy(tmp,lChamp->Caption.c_str());

 if (strcmp(tmp,"__________")==0)
   {
    Application->MessageBoxA("Pas de Champ Sélectionné",m_ecoplan,MB_OK);
    return;

  }

   var =lChamp->Caption;
 strcpy(champ,tmp);
 strcpy(tmp,eVal->Text.c_str());

 strcpy(cod,"");
 p=strstr(tmp," *");
 if (p)
   {
    strcpy(des,p+1);  // on copie l'etoile aussi
    *p=0;
    strcpy(cod,tmp);
    Col=RechColCrit(cod);
   }
 else
   { strcpy(des,tmp);
     Col=RechCol(champ);
   }

 sprintf(col,"%d",Col);
 strcpy(m_exchange,"<champ>"); strcat(m_exchange,champ); strcat(m_exchange,"</champ>");
 strcat(m_exchange,"<cod>"); strcat(m_exchange,cod); strcat(m_exchange,"</cod>");
 strcat(m_exchange,"<col>"); strcat(m_exchange,col); strcat(m_exchange,"</col>");
 strcat(m_exchange,"<des>"); strcat(m_exchange,des); strcat(m_exchange,"</des>");
 if (CheckBox1->Checked == true) strcat(m_exchange,"<decoch>O</decoch>");
    else strcat(m_exchange,"<decoch>N</decoch>");



 Close();
}
//---------------------------------------------------------------------------


int __fastcall TAffData::RechCol(char *des)
{
 int i;    int res;
 res=0;
 for (i=0;i<=Ccount;i++)
   {
    if (strcmp(Champs[i],des)==0)  {  res=cln[i]; break; }
   }
 return res;
}


int __fastcall TAffData::RechColCrit(char *cod)
{
 int i,res;  char *p; char prefix[50];
 res=-1;
 strcpy(prefix,cod);
 p=strstr(prefix,"-");
 if (p) *p=0;

 for (i=1;i<=8;i++)
   {
    if (strcmp(prefix,LCrit[i])==0) { res=i; break; }
   }
 return res;
}


void __fastcall TAffData::ListBox1Click(TObject *Sender)
{
 int indx;
indx = ListBox1->ItemIndex;
if (indx==-1) return;
lChamp->Caption = ListBox1->Items->Strings[indx];

}
//---------------------------------------------------------------------------
int __fastcall TAffData::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TAffData::ListBox2Click(TObject *Sender)
{
  int indx;
indx = ListBox2->ItemIndex;
if (indx==-1) return;
eVal->Text = ListBox2->Items->Strings[indx];
}
//---------------------------------------------------------------------------

void __fastcall TAffData::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre55");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TAffData::FormShow(TObject *Sender)
{
char tmp[200]; FILE *fp;  int cnt,count; int i;
 char buff[500];
 strcpy(m_exchange,"");
 ListBox1->Clear();
 ListBox2->Clear();

  char c1[200],c2[200],c3[200],c4[200],des[200];

 strcpy(tmp,DatabaseName); strcat(tmp,"_crit.txt");
 fp = fopen(tmp,"rt");
 if (fp)
  {
    fgets(buff,250,fp);count=1;
    while (!feof(fp))
    {if (strlen(buff)>5)
      {
       ExtractValue(c1,buff,"c1",0);
       ExtractValue(c2,buff,"c2",0);
       ExtractValue(c3,buff,"c3",0);
       ExtractValue(c4,buff,"c4",0);
       ExtractValue(des,buff,"d",0);

       if (strlen(c1)>0 && !strstr(des,"Critère"))
         {
           strcpy(tmp,c1); strcat(tmp,"-");
           strcat(tmp,c2); strcat(tmp,"-");
           strcat(tmp,c3); strcat(tmp,"-");
           strcat(tmp,c4); strcat(tmp,"-");
           strcat(tmp," *");
           strcat(tmp,des);
           ListBox2->Items->Add(AnsiString(tmp));
         }
       if (!strstr(des,"Critère") && count<8)
         {
          strcpy(tmp,"*");
          strcat(tmp,des);
          if (strlen(c2)==0)
            {
             ExtractValue(c1,buff,"l",0);
             strcpy(LCrit[count],c1);
             ListBox1->Items->Add(AnsiString(tmp));
            }
         }
      }

     fgets(buff,250,fp);
     count++;
     //if (count>8) break;
    }                    
   fclose(fp);
  }
 // else
 //  Application->MessageBoxA("Pas de Fichier Criteres",m_ecoplan,MB_OK);


 strcpy(tmp,m_directory); strcat(tmp,"\\ecochampA.txt");
 fp=fopen(tmp,"rt");
 if (fp==NULL)
   {
    Application->MessageBoxA("Fichier ecochamp.txt absent ou corrompu",m_ecoplan,MB_OK);
    Close();
   }
 for (i=0;i<200;i++)  cln[i]=0;

 fgets(buff,250,fp); Ccount=-1;
 while (!feof(fp))
  {
   if (strstr(buff,"//")) {}
   else
   {
   if (strlen(buff)> 5)
    {Ccount++;
     ExtractValue(tmp,buff,"L",0);
     ListBox1->Items->Add(AnsiString(tmp));
     strcpy(Champs[Ccount],tmp);
     //ExtractValue(tmp,buff,"C",0);
     //strcpy(cnt[count],tmp);
     //ExtractValue(tmp,buff,"A",0);
     //strcpy(abb[count],tmp);

     ExtractValue(tmp,buff,"N",0);
     cln[Ccount]=atoi(tmp);
    }
   }
   fgets(buff,250,fp);
  }
 fclose(fp);

}
//---------------------------------------------------------------------------




