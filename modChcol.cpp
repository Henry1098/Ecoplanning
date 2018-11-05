//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modChcol.h"
#include "globals.h"
#include "stdio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChCol *ChCol;
//---------------------------------------------------------------------------
__fastcall TChCol::TChCol(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChCol::btOKClick(TObject *Sender)
{
 char tmp[2000]; int count,i;

  strcpy(m_exchange,"<champs>");
 count = lbSel->Items->Count;

 if (count==0)
   {

     strcat(m_exchange,"</champs>");
    Close();
   }


 for (i=0;i<count;i++)
   {
    strcpy(tmp,lbSel->Items->Strings[i].c_str());
    strcat(m_exchange,tmp);
    strcat(m_exchange,"|");
   }
  strcat(m_exchange,"</champs>");
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TChCol::btAnnulClick(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();        
}
//---------------------------------------------------------------------------
void __fastcall TChCol::btRightClick(TObject *Sender)
{
 // right transfer
 int indx;
 char tmp[250];

indx = lbTout->ItemIndex;
if (indx==-1) return;
strcpy(tmp,lbTout->Items->Strings[indx].c_str());
// strcat(tmp,"_"); strcat(tmp,abb[indx]);
lbSel->Items->Add(AnsiString(tmp));

}
//---------------------------------------------------------------------------
void __fastcall TChCol::btLeftClick(TObject *Sender)
{
// Left Transfer
 int indx;
 indx = lbSel->ItemIndex;
 if (indx==-1) return;
 lbSel->Items->Delete(indx);
}
//---------------------------------------------------------------------------
void __fastcall TChCol::btUpClick(TObject *Sender)
{
 // Up Move
  int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbSel->ItemIndex;
 if (indx == -1) return;
 count = lbSel->Items->Count;
 if (indx == 0) { lbSel->Items->Move(indx,count-1); lbSel->ItemIndex=count-1; }
 else { lbSel->Items->Move(indx,indx-1);  lbSel->ItemIndex=indx-1; }
}
//---------------------------------------------------------------------------
void __fastcall TChCol::btDownClick(TObject *Sender)
{
 // Down Move
 int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbSel->ItemIndex;
 if (indx == -1) return;
 count = lbSel->Items->Count;
 if (indx == count-1) { lbSel->Items->Move(indx,0); lbSel->ItemIndex=0; }

 else { lbSel->Items->Move(indx,indx+1); lbSel->ItemIndex=indx + 1; }
}
//---------------------------------------------------------------------------


int __fastcall TChCol::Explode(char sep,char *str)
{
 int i, count, ip;
 char c,cpred;
 if (strlen(str)==0) return 0;
 count = 0; params[count][0]=0; // indice params
 c=str[0]; cpred=0;
 i=0; ip=0;
 while (c)
  { cpred=c;
   if (c==sep)
     { params[count][ip]=0; count++; ip=0; if (count > 49) count=49; }
   else
     { params[count][ip]=c;  ip++; }
   i++; c=str[i];
  }
 if (cpred==sep) count--; return (count+1);
}

void __fastcall TChCol::FormCreate(TObject *Sender)
{
 char tmp[550];  FILE *fp;
 char buff[2000]; int count;
 char c1[200],c2[200],c3[200],c4[200],des[200];

 /*
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
          lbTout->Items->Add(AnsiString(tmp));
         }
      }

     fgets(buff,250,fp);
     count++;
     //if (count>8) break;
    }
   fclose(fp);
  }
 */

 strcpy(tmp,m_directory); strcat(tmp,"\\ecochamp.txt");
 fp=fopen(tmp,"rt");
 fgets(buff,550,fp); count=-1;
 while (!feof(fp))
  {
   if (strstr(buff,"//")) {}
   else
   {
   if (strlen(buff)> 5)
    {count++;
     ExtractValue(tmp,buff,"L",0);
     lbTout->Items->Add(AnsiString(tmp));
     ExtractValue(tmp,buff,"C",0);
     strcpy(cnt[count],tmp);
     ExtractValue(tmp,buff,"P",0);  // Abbrev
     strcpy(abb[count],tmp);
     ExtractValue(tmp,buff,"N",0);
     strcpy(cln[count],tmp);
    }
   }
   fgets(buff,250,fp);
  }
 fclose(fp);


 lbSel->Clear();
 if (strlen(m_exchange))
   {
    // remplir lbSel
    Strip(m_exchange);

   }

}
//---------------------------------------------------------------------------

void __fastcall TChCol::Strip(char *s)
{
 char tmp[2500];
 int Row;   int count,i;

 ExtractValue(tmp,s,"champs",0);
 count = Explode('|',tmp);
 if (count)
   {
    for (i=1; i<=count;i++)
      {
      lbSel->Items->Add(AnsiString(params[i-1]));
      }
   }
}


int __fastcall TChCol::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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
void __fastcall TChCol::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl51");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

