//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modXLS.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TTableCSV *TableCSV;
//---------------------------------------------------------------------------
__fastcall TTableCSV::TTableCSV(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTableCSV::AdvECanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
CanEdit=false;
 if (ACol==3) CanEdit = true;
}
//---------------------------------------------------------------------------

void __fastcall TTableCSV::AdvEGetEditorType(TObject *Sender, int ACol,
      int ARow, TEditorType &AEditor)
{
int i;

if (ARow==0) return;
if (ACol==3)
  { AEditor = edComboList;
      AdvE->ClearComboString();
      AdvE->AddComboString("");
       AdvE->AddComboString("Absent");
      for (i=1;i<15;i++)
        {
        AdvE->AddComboString(AnsiString(i));
        }
    }        
}
//---------------------------------------------------------------------------

void __fastcall TTableCSV::Button1Click(TObject *Sender)
{
 char tmp[1000]; int i;
 strcpy(tmp,Edit1->Text.c_str()); SEPCHAMPS=tmp[0];
 strcpy(tmp,Edit2->Text.c_str()); SEPPRED=tmp[0];

 if (SEPCHAMPS==SEPPRED)
   {
    if (Application->MessageBoxA("Séparateur de champs, et séparateur LIENS identiques\nVoulez-vous continuer","ECOPLANNING",MB_YESNO)==IDNO)
    return;
   }


 strcpy(tmp,AdvE->Cells[3][1].c_str()); COL1=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][2].c_str()); COL2=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][3].c_str()); COL3=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][4].c_str()); COL4=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][5].c_str()); COL5=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][6].c_str()); COL6=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][7].c_str()); COL7=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][8].c_str()); COL8=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][9].c_str()); COL9=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][10].c_str()); COL10=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][11].c_str()); COL11=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][12].c_str()); COL12=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][13].c_str()); COL13=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][14].c_str()); COL14=atoi(tmp);

 strcpy(tmp,AdvE->Cells[3][15].c_str()); COL15=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][16].c_str()); COL16=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][17].c_str()); COL17=atoi(tmp);
 strcpy(tmp,AdvE->Cells[3][18].c_str()); COL18=atoi(tmp);

 Close();
}
//---------------------------------------------------------------------------

void __fastcall TTableCSV::FormShow(TObject *Sender)
{
AdvE->RowCount=19;
 AdvE->Cells[1][1]="N° de tâche";
 AdvE->Cells[2][1]="Col 1";
 AdvE->Cells[3][1]= "1";

 AdvE->Cells[1][2]="Désignation";
 AdvE->Cells[2][2]="Col 2";
 AdvE->Cells[3][2]= "2";

 AdvE->Cells[1][3]="Durée (Jours)";
 AdvE->Cells[2][3]="Col 3";
 AdvE->Cells[3][3]= "3";

 AdvE->Cells[1][4]="Date Début Souhaité";
 AdvE->Cells[2][4]="Col 4";
 AdvE->Cells[3][4]= "4";

 AdvE->Cells[1][5]="Date de Fin Souhaitée";
 AdvE->Cells[2][5]="Col 5";
 AdvE->Cells[3][5]= "5";

 AdvE->Cells[1][6]="Prédécesseurs";
 AdvE->Cells[2][6]="Col 6";
 AdvE->Cells[3][6]= "6";

 AdvE->Cells[1][7]="Successeurs";
 AdvE->Cells[2][7]="Col 7";
 AdvE->Cells[3][7]= "7";

 AdvE->Cells[1][8]="Crit1";
 AdvE->Cells[2][8]="Col 8";
 AdvE->Cells[3][8]= "8";

 AdvE->Cells[1][9]="Désignation Crit1";
 AdvE->Cells[2][9]="Col 9";
 AdvE->Cells[3][9]= "9";

 AdvE->Cells[1][10]="Crit2";
 AdvE->Cells[2][10]="Col 10";
 AdvE->Cells[3][10]= "10";

 AdvE->Cells[1][11]="Désignation Crit2";
 AdvE->Cells[2][11]="Col 11";
 AdvE->Cells[3][11]= "11";

 AdvE->Cells[1][12]="Crit3";
 AdvE->Cells[2][12]="Col 12";
 AdvE->Cells[3][12]= "12";

 AdvE->Cells[1][13]="Désignation Crit3";
 AdvE->Cells[2][13]="Col 13";
 AdvE->Cells[3][13]= "13";

 AdvE->Cells[1][14]="Crit4";
 AdvE->Cells[2][14]="Col 14";
 AdvE->Cells[3][14]= "14";

  AdvE->Cells[1][15]="Désignation Crit4";
 AdvE->Cells[2][15]="Col 15";
 AdvE->Cells[3][15]= "15";

 AdvE->Cells[1][16]="Code Tâche";
 AdvE->Cells[2][16]="Col 16";
 AdvE->Cells[3][16]= "16";

 AdvE->Cells[1][17]="Cout +";
 AdvE->Cells[2][17]="Col 17";
 AdvE->Cells[3][17]= "17";

 AdvE->Cells[1][18]="Cout -";
 AdvE->Cells[2][18]="Col 18";
 AdvE->Cells[3][18]= "18";


 COL1=1;COL2=2;COL3=3;COL4=4;COL5=5;COL6=6;COL7=7;
 COL8=8;COL9=9;COL10=10;COL11=11;COL12=12;COL13=13;COL14=14;
 COL15=15;COL16=16;COL17=17;COL18=18;

}
//---------------------------------------------------------------------------

void __fastcall TTableCSV::Button2Click(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------

