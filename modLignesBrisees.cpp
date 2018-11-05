//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modLignesBrisees.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TLBrisee *LBrisee;
//---------------------------------------------------------------------------
__fastcall TLBrisee::TLBrisee(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLBrisee::AAdvLBClickCell(TObject *Sender,
      int ARow, int ACol)
{
 char tmp[500];   TColor XColor;
if (ACol==2)
  {
    if (ColorDialog1->Execute())
        {
         XColor = ColorDialog1->Color;
         AAdvLB->Cells[ACol][ARow]=AnsiString(XColor);
         strcpy(tmp,AAdvLB->Cells[ACol][ARow].c_str());
         AAdvLB->Colors[ACol][ARow]=XColor;

        }
   }


}
//---------------------------------------------------------------------------
void __fastcall TLBrisee::Button1Click(TObject *Sender)
{
 // maj des variables globales
 int i,cnt; char tmp[50];

 cnt = AAdvLB->RowCount;
 for (i=1;i<cnt;i++)
   {
    if (i>19) break;
    if (AAdvLB->Cells[4][i]=="Oui") L_BRISEES[pc][i]=true;
        else L_BRISEES[pc][i]=false;
    strcpy(tmp,AAdvLB->Cells[3][i].c_str());
    E_BRISEES[pc][i] = atoxx(tmp);
    strcpy(tmp,AAdvLB->Cells[2][i].c_str());
    C_BRISEES[pc][i] = atoi(tmp);

   }


 Close();
}
//---------------------------------------------------------------------------

void __fastcall TLBrisee::Button2Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------


float __fastcall TLBrisee::atoxx(char *tout)
{

 int l,i,lg; char *endptr;
 char *p; float f; char extra[50];

 l=strlen(tout);
 lg=0;
 for (i=0;i<l;i++)
   {
    if (tout[i] == ',')  tout[i]='.';
    if (tout[i] != ' ') { extra[lg]=tout[i]; lg++; }
   }
 extra[lg]=0; // strcat(extra," ");
 f=(float) atof(extra);
 //f = strtod(extra,NULL);

 return (f);
}


void __fastcall TLBrisee::AAdvLBGetEditorType(TObject *Sender, int ACol,
      int ARow, TEditorType &AEditor)
{
 if (ARow==0) return;
 if (ACol==4)
  {
   AEditor = edComboList;
   AAdvLB->ClearComboString();
   AAdvLB->AddComboString("Oui"); // Titre
   AAdvLB->AddComboString("Oui"); // Sous Titre
  }
 if (ACol==3)
  {
   AEditor = edComboList;
   AAdvLB->ClearComboString();
   AAdvLB->AddComboString("0.5"); // Titre
   AAdvLB->AddComboString("0.8");
   AAdvLB->AddComboString("1.0"); // Titre
   AAdvLB->AddComboString("1.5");
   AAdvLB->AddComboString("2.0"); // Titre
   AAdvLB->AddComboString("3.0");
   AAdvLB->AddComboString("4.0"); // Titre
   AAdvLB->AddComboString("5.0");
  }
}
//---------------------------------------------------------------------------

void __fastcall TLBrisee::FormShow(TObject *Sender)
{
 // alimenter Grid avec les données globales
 int r,c;
 int rr,cc; int i,cnt;

 rr=AAdvLB->RowCount; cc=AAdvLB->ColCount;
 for (r=1;r<rr;r++) { for (c=1;c<cc;c++) AAdvLB->Cells[c][r]=""; }
 AAdvLB->RowCount=2;

 cnt = Explode('@',dateavanc);
 for (i=0;i<cnt;i++)
   {
    if (i>0) AAdvLB->RowCount++;
    AAdvLB->Cells[1][i+1]= AnsiString(params[i]);

    AAdvLB->Cells[2][i+1]= AnsiString(C_BRISEES[pc][i+1]);
    AAdvLB->Colors[2][i+1]=TColor(C_BRISEES[pc][i+1]);
    AAdvLB->Cells[3][i+1]= AnsiString(E_BRISEES[pc][i+1]);

    if (AAdvLB->Cells[3][i+1] == "0")
      {
        AAdvLB->Cells[2][i+1]= AAdvLB->Cells[2][i];
        AAdvLB->Colors[2][i+1]=AAdvLB->Colors[2][i]; //TColor(C_BRISEES[pc][i+1]);
        AAdvLB->Cells[3][i+1]= AAdvLB->Cells[3][i];  //AnsiString(E_BRISEES[pc][i+1]);
        AAdvLB->Cells[4][i+1]= AAdvLB->Cells[4][i];
      }
    if (L_BRISEES[pc][i+1]== true) AAdvLB->Cells[4][i+1]= "Oui";
    else AAdvLB->Cells[4][i+1]= "Oui";

   }



}
//---------------------------------------------------------------------------


int __fastcall TLBrisee::Explode(char sep,char *str)
{
 int i, l, count, ip;
 char c,cpred;
 l = strlen(str);
 if (l==0) return 0;
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
