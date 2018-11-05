//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modChamps.h"
#include <stdio.h>
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChamps *Champs;
//---------------------------------------------------------------------------
__fastcall TChamps::TChamps(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChamps::FormCreate(TObject *Sender)
{
 FILE *fp; char *p;
 char buff[255];
 int count,lg,indx;
 char tmp[250],tmp1[250];

strcpy(ecoplan,m_ecoplan);


for (count=0;count <150;count++)
 { cnt[count][0]=0; abb[count][0]=0; }

Champs->Caption = AnsiString(m_exchange);
 lbChamps->Clear();
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

       if (!strstr(des,"Critère"))
         {
          strcpy(tmp,"*");
          strcat(tmp,des);
          lbChamps->Items->Add(AnsiString(tmp));
         }
      }

     fgets(buff,250,fp);
     count++;
     if (count>8) break;
    }
   fclose(fp);
  }

 strcpy(tmp,m_directory); strcat(tmp,"\\ecochamp.txt");
 fp=fopen(tmp,"rt");
 fgets(buff,250,fp); count=-1;
 while (!feof(fp))
  {
    if (strstr(buff,"//"))
    {
    }
    else
     {
     if (strlen(buff)> 5)
      {count++;
       ExtractValue(tmp,buff,"L",0);
       lbChamps->Items->Add(AnsiString(tmp));
       ExtractValue(tmp,buff,"C",0);
       strcpy(cnt[count],tmp);
       ExtractValue(tmp,buff,"A",0);
       strcpy(abb[count],tmp);
       ExtractValue(tmp,buff,"N",0);
       strcpy(cln[count],tmp);
      }
     }  
   fgets(buff,250,fp);
  }
 fclose(fp);


 strcpy(tmp,m_pasapas);

 lg = ExtractValue(champ,tmp,"C",0);
 lg = ExtractValue(oper,tmp,"R",0);
 lg = ExtractValue(val1,tmp,"V1",0);
 lg = ExtractValue(val2,tmp,"V2",0);
 lg = ExtractValue(action,tmp,"A",0);

 // mettre le focus sur les listboxes.
 count = lbChamps->Items->Count;
 for (lg=0;lg<count;lg++)
   { strcpy(tmp1,lbChamps->Items->Strings[lg].c_str());
    if (strcmp(champ,tmp1)==0)
      lbChamps->ItemIndex = lg;
   }

 count = lbRelation->Items->Count;
 for (lg=0;lg<count;lg++)
   { strcpy(tmp1,lbRelation->Items->Strings[lg].c_str());
    if (strcmp(oper,tmp1)==0)
      lbRelation->ItemIndex = lg;
   }

  count = lbAction->Items->Count;
 for (lg=0;lg<count;lg++)
   { strcpy(tmp1,lbAction->Items->Strings[lg].c_str());
    if (strcmp(action,tmp1)==0)
      lbAction->ItemIndex = lg;
   }
 eDe->Text = AnsiString(val1);
 eA->Text= AnsiString(val2);

}
//---------------------------------------------------------------------------

int __fastcall TChamps::Control()
{
int indx_champ,indx_relation,indx_action;
 indx_champ=lbChamps->ItemIndex;
 char ed1[100],ed2[100];
 char champ[255],relation[255],val1[100],val2[100],action[50];
 char criter[255];

 indx_champ = lbChamps->ItemIndex;
 if (indx_champ == -1)
   {
    Application->MessageBoxA("Champ non Sélectionné",ecoplan,MB_OK);
    return 1;
   }

 indx_relation=lbRelation->ItemIndex;
 if (indx_relation == -1)
   {
    Application->MessageBoxA("Opérateur non Sélectionné",ecoplan,MB_OK);
    return 1;
   }
 indx_action=lbAction->ItemIndex;
 if (indx_action == -1)
   {
    Application->MessageBoxA("Action non Sélectionnée",ecoplan,MB_OK);
    return 1;
   }
 strcpy(ed1,eDe->Text.c_str());
 strcpy(ed2,eA->Text.c_str());
 if (strlen(ed1)==0)
   {
    Application->MessageBoxA("Valeur 1 non Renseignée",ecoplan,MB_OK);
    return 1;
   }

 if ((indx_relation >=6) && (indx_relation <=9))
   {
    if (strlen(ed2)==0)
     {
      Application->MessageBoxA("Valeur 2 non Renseignée",ecoplan,MB_OK);
      return 1;
     }
   }
return 0;
}
void __fastcall TChamps::btExecClick(TObject *Sender)
{
int indx_champ,indx_relation,indx_action;
 indx_champ=lbChamps->ItemIndex;
 char ed1[100],ed2[100];
 char champ[255],relation[255],val1[100],val2[100],action[50];
 char criter[255];

 if (Control()) return;

 indx_champ=lbChamps->ItemIndex;
 indx_relation = lbRelation->ItemIndex;
 indx_action=lbAction->ItemIndex;
 strcpy(ed1,eDe->Text.c_str());
 strcpy(ed2,eA->Text.c_str());

// enfin, on peut preparer la ligne
 strcpy(criter,"<C>"); strcat(criter,lbChamps->Items->Strings[indx_champ].c_str()); strcat(criter,"</C>");
 strcat(criter," <R>"); strcat(criter,lbRelation->Items->Strings[indx_relation].c_str()); strcat(criter,"</R>");
 strcat(criter," <V1>"); strcat(criter,ed1); strcat(criter,"</V1>");
 strcat(criter," <V2>"); strcat(criter,ed2); strcat(criter,"</V2>");
 strcat(criter," <A>"); strcat(criter,lbAction->Items->Strings[indx_action].c_str()); strcat(criter,"</A>");
 strcpy(m_exchange,criter);
 Close();        
}
//---------------------------------------------------------------------------
void __fastcall TChamps::FormClose(TObject *Sender, TCloseAction &Action)
{
Action = caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TChamps::btCancelClick(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();        
}
//---------------------------------------------------------------------------
void __fastcall TChamps::btHelpClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Filtrer.html#Filt1");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------


int __fastcall TChamps::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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
void __fastcall TChamps::lbRelationClick(TObject *Sender)
{
 int indx;
 indx=lbRelation->ItemIndex;
 if (indx==-1) return;
 if (indx > 5 && indx <8)
   {
    eA->Visible=true;
    Label2->Visible=true;
   }
 else
   {
    eA->Text="";
    eA->Visible=false;
    Label2->Visible=false;
   }
}
//---------------------------------------------------------------------------

