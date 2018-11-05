//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modDump.h"
#include "globals.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TDump *Dump;
//---------------------------------------------------------------------------
__fastcall TDump::TDump(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

AnsiString __fastcall TDump::CharToAnsi(char c)
{
 char tmp[10];
 tmp[0]=c; tmp[1]=0;
 return AnsiString(tmp);

}

void __fastcall TDump::FormCreate(TObject *Sender)
{
 Refresh();


 int row; char tmp[250];
 sprintf(tmp,"Planning en Cours = %d",pc);
 Label61->Caption=AnsiString(tmp);
 // Preparer tous les champs
 // Le General



 p=1;

 // GENERAL
 Label31->Caption = AnsiString(P_NOM[p]);
 Label32->Caption = CharToAnsi(P_GENRE[p]);
 Label33->Caption = CharToAnsi(P_TYPE[p]);
 Label34->Caption = AnsiString(P_TRI[p]);
 Label35->Caption = AnsiString(P_FILTRE[p]);
 Label36->Caption = AnsiString(P_COLONNES[p]);
 Label37->Caption = AnsiString(NB_DETAIL[p]);
 Label38->Caption = CharToAnsi(P_MODE[p]);
 Label39->Caption = AnsiString(P_H[p]);
 Label40->Caption = AnsiString(P_W[p]);


 Label41->Caption = CharToAnsi(P_MARGES[p]);
 Label42->Caption = CharToAnsi(P_CADRE[p]);
 Label43->Caption = CharToAnsi(P_ENTETE[p]);
 Label44->Caption = CharToAnsi(P_CALHAUT[p]);
 Label45->Caption = CharToAnsi(P_CALBAS[p]);
 Label46->Caption = CharToAnsi(P_PIED[p]);

 Label47->Caption = AnsiString(P_MARGH1[p]);
 Label48->Caption = AnsiString(P_MARGH2[p]);
 Label49->Caption = AnsiString(P_MARGV1[p]);
 Label50->Caption = AnsiString(P_MARGV2[p]);

 Label51->Caption = P_MH1[p];
 Label52->Caption = P_MH2[p];
 Label53->Caption = P_MV1[p];
 Label54->Caption = P_MV2[p];

 Label55->Caption = P_ELC[p];
 Label56->Caption = P_CLC[p];
 Label57->Caption = AnsiString(P_ELCF[p]);
 Label58->Caption = AnsiString(P_CLCC[p]);
 Label59->Caption = CharToAnsi(P_GRILLE[p]);
 Label60->Caption = CharToAnsi(P_LBRISE[p]);

 for (row=1;row < avs->RowCount;row++)
   {
    avs->Cells[1][row] = AnsiString(P_TRICOL[p][row-1]);
    avs->Cells[2][row] = CharToAnsi(P_ATTR[p][row-1]);
    avs->Cells[3][row] = AnsiString(P_FONT[p][row-1]);
    avs->Cells[4][row] = AnsiString(P_HAUT[p][row-1]);
    avs->Cells[5][row] = AnsiString(P_LARG[p][row-1]);
    avs->Cells[6][row] = AnsiString(P_ITAL[p][row-1]);
    avs->Cells[7][row] = AnsiString(P_BOLD[p][row-1]);
    avs->Cells[8][row] = P_JH[p][row-1];
    avs->Cells[9][row] = P_JV[p][row-1];
    avs->Cells[10][row] = AnsiString(P_CFCOLOR[p][row-1]);
    avs->Cells[11][row] = AnsiString(P_CBCOLOR[p][row-1]);


   }



}
//---------------------------------------------------------------------------
void __fastcall TDump::Button1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TDump::Clean_Grid(TAdvStringGrid *sgrid, int strow)
{
 int r,c;
 int rr,cc;

 rr=sgrid->RowCount; cc=sgrid->ColCount;
 for (r=1;r<rr;r++)
  {
   for (c=1;c<cc;c++) sgrid->Cells[c][r]="";
  }

  sgrid->RowCount=strow;
}




void __fastcall TDump::Refresh()
{

 int row; char tmp[250];
 sprintf(tmp,"Planning en Cours = %d",pc);
 Label61->Caption=AnsiString(tmp);
 // Preparer tous les champs
 // Le General

 p=pc;

 // GENERAL
 Label31->Caption = AnsiString(P_NOM[p]);
 Label32->Caption = CharToAnsi(P_GENRE[p]);
 Label33->Caption = CharToAnsi(P_TYPE[p]);
 Label34->Caption = AnsiString(P_TRI[p]);
 Label35->Caption = AnsiString(P_FILTRE[p]);
 Label36->Caption = AnsiString(P_COLONNES[p]);
 Label37->Caption = AnsiString(NB_DETAIL[p]);
 Label38->Caption = CharToAnsi(P_MODE[p]);
 Label39->Caption = AnsiString(P_H[p]);
 Label40->Caption = AnsiString(P_W[p]);


 Label41->Caption = CharToAnsi(P_MARGES[p]);
 Label42->Caption = CharToAnsi(P_CADRE[p]);
 Label43->Caption = CharToAnsi(P_ENTETE[p]);
 Label44->Caption = CharToAnsi(P_CALHAUT[p]);
 Label45->Caption = CharToAnsi(P_CALBAS[p]);
 Label46->Caption = CharToAnsi(P_PIED[p]);

 Label47->Caption = AnsiString(P_MARGH1[p]);
 Label48->Caption = AnsiString(P_MARGH2[p]);
 Label49->Caption = AnsiString(P_MARGV1[p]);
 Label50->Caption = AnsiString(P_MARGV2[p]);

 Label51->Caption = P_MH1[p];
 Label52->Caption = P_MH2[p];
 Label53->Caption = P_MV1[p];
 Label54->Caption = P_MV2[p];

 Label55->Caption = P_ELC[p];
 Label56->Caption = P_CLC[p];
 Label57->Caption = AnsiString(P_ELCF[p]);
 Label58->Caption = AnsiString(P_CLCC[p]);
 Label59->Caption = CharToAnsi(P_GRILLE[p]);
 Label60->Caption = CharToAnsi(P_LBRISE[p]);

 Clean_Grid(avs,2);
 Label63->Caption = AnsiString(P_COL[p]);

 for (row=1;row <= P_COL[p];row++)
   {
    if (row>1) avs->RowCount++;
    avs->Cells[1][row] = AnsiString(P_TRICOL[p][row-1]);
    avs->Cells[2][row] = CharToAnsi(P_ATTR[p][row-1]);
    avs->Cells[3][row] = AnsiString(P_FONT[p][row-1]);
    avs->Cells[4][row] = AnsiString(P_HAUT[p][row-1]);
    avs->Cells[5][row] = AnsiString(P_LARG[p][row-1]);
    avs->Cells[6][row] = AnsiString(P_ITAL[p][row-1]);
    avs->Cells[7][row] = AnsiString(P_BOLD[p][row-1]);
    avs->Cells[8][row] = P_JH[p][row-1];
    avs->Cells[9][row] = P_JV[p][row-1];
    avs->Cells[10][row] = AnsiString(P_CFCOLOR[p][row-1]);
    avs->Cells[11][row] = AnsiString(P_CBCOLOR[p][row-1]);
   }

}
void __fastcall TDump::Button2Click(TObject *Sender)
{
 Refresh();
}
//---------------------------------------------------------------------------

