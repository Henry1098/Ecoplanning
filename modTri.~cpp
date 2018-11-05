//---------------------------------------------------------------------------

#include <vcl.h>
#include <Windows.h>
#pragma hdrstop

#include "modTri.h"
#include "globals.h"
#include "modTriElem.h"
#include "plstd.h"
#include "modPrepPlanning.h"
#include "modTcol.h"
#include "modTligne.h"
#include "modDescEnvelop.h"
#include "DescEsp.h"
#include "modHelp.h"
#include "descTrait.h"
#include "globals.h"
#include "globalvars.h"

#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TTri *Tri;
static int etat;
AnsiString nomTri;
AnsiString direct;
AnsiString nomFile;
std::vector<std::string> tridonnee;
int etata, etatb;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TTri::TTri(TComponent* Owner)
        : TForm(Owner)
{
}

int __fastcall TTri::SaveData(int disp)
{
 //
 char name[100];
 char Key[100],RetKey[100];
 int rc,recdata,i,j,nbitems;
 char tmp[10000];
 char filename[250];

 FILE *fp;
 int count;

 strcpy(Key,eMemoire->Text.c_str());
 if (strlen(Key) == 0)
   {
    Application->MessageBoxA("Pas de Nom de Tri",m_ecoplan,MB_OK);
    return 0;
   }

strcpy(tmp,m_directory); strcat(tmp,"\\Reference\\Tris\\"); strcat(tmp,Key);
strcat(tmp,".tri");
fp = fopen(tmp,"wt");

 strcpy(filename,m_directory); strcat(filename,"\\eco_tri");
 rc = tri->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = tri->SetIndexMode(0,0);

 // preparer buffer
 strcpy(buffer,"<l>"); strcat(buffer,Key); strcat(buffer,"</l>");
 strcat(buffer,"<des>");
 strcat(buffer,mTri->Lines->GetText());
 strcat(buffer,"</des>");
 strcat(buffer,"<detail>");
 if (cb1->Checked==true) strcat(buffer,"O"); else strcat(buffer,"N");
 strcat(buffer,"</detail>");

 strcat(buffer,"<champs>");
 nbitems=asFC->RowCount-1;  // lbDetail->Items->Count;
 if (nbitems>8)  nbitems=8;
 for (i=0;i<nbitems;i++)
   {
     j=i+1;
     strcpy(tmp,"<CH>"); strcat(tmp,asFC->Cells[1][j].c_str()); strcat(tmp,"</CH>");
     strcat(tmp,"<N0>"); strcat(tmp,asFC->Cells[3][j].c_str()); strcat(tmp,"</N0>");
     strcat(tmp,"<N1>"); strcat(tmp,asFC->Cells[4][j].c_str()); strcat(tmp,"</N1>");
     strcat(tmp,"<N2>"); strcat(tmp,asFC->Cells[5][j].c_str()); strcat(tmp,"</N2>");
     strcat(tmp,"<N3>"); strcat(tmp,asFC->Cells[6][j].c_str()); strcat(tmp,"</N3>");
     strcat(tmp,"<DT>"); strcat(tmp,asFC->Cells[8][j].c_str()); strcat(tmp,"</DT>");
     strcat(tmp,"<TR>"); strcat(tmp,asFC->Cells[12][j].c_str()); strcat(tmp,"</TR>");
     strcat(tmp,"<BL>"); strcat(tmp,asFC->Cells[13][j].c_str()); strcat(tmp,"</BL>");
     ///////////////////////////////////
     //  les 3 descriptions  Titre Ligne, Col et detail ??

     if (asFC->Cells[10][j]=="X")  T_LLCC[pc][i]="L";
     if (asFC->Cells[11][j]=="X")  T_LLCC[pc][i]="C";
     if (asFC->Cells[12][j]=="X")  T_LLCC[pc][i]="T";
     if (asFC->Cells[13][j]=="X")  T_LLCC[pc][i]="B";

     strcat(tmp,"<lc>"); strcat(tmp,T_LLCC[pc][i].c_str()); strcat(tmp,"</lc>");
     strcat(tmp,"<pol>"); strcat(tmp,T_POL[pc][i].c_str()); strcat(tmp,"</pol>");
     strcat(tmp,"<ct>"); strcat(tmp,T_CTEXT[pc][i].c_str()); strcat(tmp,"</ct>");
     strcat(tmp,"<it>"); strcat(tmp,T_TITAL[pc][i].c_str()); strcat(tmp,"</it>");
     strcat(tmp,"<bd>"); strcat(tmp,T_TBOLD[pc][i].c_str()); strcat(tmp,"</bd>");
     strcat(tmp,"<ht>"); strcat(tmp,T_HAUTEUR[pc][i].c_str()); strcat(tmp,"</ht>");
     strcat(tmp,"<jh>"); strcat(tmp,T_JSH[pc][i].c_str()); strcat(tmp,"</jh>");
     strcat(tmp,"<jv>"); strcat(tmp,T_JSV[pc][i].c_str()); strcat(tmp,"</jv>");
     strcat(tmp,"<cb>"); strcat(tmp,T_CBKG[pc][i].c_str()); strcat(tmp,"</cb>");
     strcat(tmp,"<lg>"); strcat(tmp,T_TLARG[pc][i].c_str()); strcat(tmp,"</lg>");

     strcat(tmp,"<ls1>"); strcat(tmp,T_LS1[pc][i].c_str()); strcat(tmp,"</ls1>");
     strcat(tmp,"<ep1>"); strcat(tmp,T_LS1EP[pc][i].c_str()); strcat(tmp,"</ep1>");
     strcat(tmp,"<cl1>"); strcat(tmp,T_LS1CL[pc][i].c_str()); strcat(tmp,"</cl1>");
     strcat(tmp,"<st1>"); strcat(tmp,T_LS1ST[pc][i].c_str()); strcat(tmp,"</st1>");

     strcat(tmp,"<ls2>"); strcat(tmp,T_LS2[pc][i].c_str()); strcat(tmp,"</ls2>");
     strcat(tmp,"<ep2>"); strcat(tmp,T_LS2EP[pc][i].c_str()); strcat(tmp,"</ep2>");
     strcat(tmp,"<cl2>"); strcat(tmp,T_LS2CL[pc][i].c_str()); strcat(tmp,"</cl2>");
     strcat(tmp,"<st2>"); strcat(tmp,T_LS2ST[pc][i].c_str()); strcat(tmp,"</st2>");

     strcat(buffer,tmp); strcat(buffer,"|");   // | as separator
   }
 strcat(buffer,"</champs>");

 strcat(buffer,"<envelop>");

 for (i=0;i<MAX_COL;i++) P_ENV[pc][i]=0;
 for (i=0;i<nbitems;i++)
   {
     j=i+1;

     if (asFC->Cells[8][j]=="X")
       {E_ENV[pc][i]="X"; P_ENV[pc][i] = 1; }

       else { E_ENV[pc][i]=" "; P_ENV[pc][i] = 0; }


     strcpy(tmp,"<lc>"); strcat(tmp,E_ENV[pc][i].c_str()); strcat(tmp,"</lc>");
     strcat(tmp,"<pol>"); strcat(tmp,E_POL[pc][i].c_str()); strcat(tmp,"</pol>");
     strcat(tmp,"<ct>"); strcat(tmp,E_CTEXT[pc][i].c_str()); strcat(tmp,"</ct>");
     strcat(tmp,"<it>"); strcat(tmp,E_TITAL[pc][i].c_str()); strcat(tmp,"</it>");
     strcat(tmp,"<bd>"); strcat(tmp,E_TBOLD[pc][i].c_str()); strcat(tmp,"</bd>");
     strcat(tmp,"<ht>"); strcat(tmp,E_HAUTEUR[pc][i].c_str()); strcat(tmp,"</ht>");
     strcat(tmp,"<jh>"); strcat(tmp,E_JSH[pc][i].c_str()); strcat(tmp,"</jh>");
     strcat(tmp,"<jv>"); strcat(tmp,E_JSV[pc][i].c_str()); strcat(tmp,"</jv>");
     strcat(tmp,"<cb>"); strcat(tmp,E_CBKG[pc][i].c_str()); strcat(tmp,"</cb>");
     strcat(tmp,"<lg>"); strcat(tmp,E_TLARG[pc][i].c_str()); strcat(tmp,"</lg>");
     strcat(tmp,"<coult>"); strcat(tmp,E_COULTRAIT[pc][i].c_str()); strcat(tmp,"</coult>");
     strcat(tmp,"<style>"); strcat(tmp,E_STYLE[pc][i].c_str()); strcat(tmp,"</style>");
     strcat(tmp,"<epaiss>"); strcat(tmp,E_EPAISS[pc][i].c_str()); strcat(tmp,"</epaiss>");
     strcat(tmp,"<design>"); strcat(tmp,E_DESIGN[pc][i].c_str()); strcat(tmp,"</design>");
     strcat(tmp,"<encadr>"); strcat(tmp,E_ENCADR[pc][i].c_str()); strcat(tmp,"</encadr>");

     strcat(buffer,tmp); strcat(buffer,"|");   // | as separator
   }
 strcat(buffer,"</envelop>");


 rc = tri->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = tri->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=tri->GetNewRecordNumber();
       rc = tri->WriteKey(0,Key,recdata);
       rc = tri->WriteRecord(buffer,strlen(buffer)+1);
       lbTri->Items->Add(AnsiString(Key));
     }
Save_Preseance();
change = false;

tri->CloseEngine();
 //strcpy(tmp,DatabaseName);
 //strcat(tmp,"_reports");
// strcpy(tmp,m_directory); strcat(tmp,"\\eco_tri");
// rc = tri->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
// rc = tri->SetIndexMode(0,0);
strcat(buffer,"\n");
fputs(buffer,fp);
fclose(fp);

if (disp>0)
Application->MessageBoxA("Sauvegarde Effectuée",m_ecoplan,MB_OK);

return 0;
}

void __fastcall TTri::CleanMemory()
{
 int i;
 for (i=0;i<MAX_TCHP;i++)
   {
    T_LLCC[pc][i] = "Z";  // valeur L ou C   T ou B
    T_POL[pc][i] = "Arial"; // police
    T_CTEXT[pc][i] = "0"; // couleur Texte
    T_TITAL[pc][i] = "Standard";
    T_TBOLD[pc][i] = "Standard";
    T_HAUTEUR[pc][i] = "14";
    T_JSH[pc][i] = "Centre";
    T_JSV[pc][i] = "Haut";
    T_CBKG[pc][i] = "";
    T_TLARG[pc][i] = "200";
    T_LS1[pc][i] = "";
    T_LS1EP[pc][i] = "";    // Epaisseur
    T_LS1CL[pc][i] = "";    // Couleur
    T_LS1ST[pc][i] = "";
    T_LS2[pc][i] = "";      // Oui/Non (pour titre en ligne)
    T_LS2EP[pc][i] = "";
    T_LS2CL[pc][i] = "";
    T_LS2ST[pc][i] = "";
    }
}

//---------------------------------------------------------------------------
void __fastcall TTri::Modify()
{
 if (strcmp(mode,"utiliser")==0)
   {
    Label10->Caption = "Trier - Grouper : Utiliser.";
    cb1->Visible = true;
    btLigne->Visible=false;
    btMod->Visible=false;
    btDelete->Visible=false;
    btNew->Visible=false;
    btSupprimer->Visible=false;
    btAppliquer->Visible=true;
    btAffPlann->Visible=true;
    // Button1->Visible=true;
    btMemor->Visible=true;
   }
 else
   {
    Label10->Caption = "Trier - Grouper : Créer, Modifier, Supprimer.";
    cb1->Visible = true;
    btLigne->Visible=true;
    btMod->Visible=true;
    btDelete->Visible=true;
    btNew->Visible=true;
    btSupprimer->Visible=true;
    btAppliquer->Visible=false;
    btAffPlann->Visible=false;
    //Button1->Visible=false;
    btMemor->Visible=true;

   }


}

//---------------------------------------------------------------------------
void __fastcall TTri::btLigneClick(TObject *Sender)
{

 TTriCrit *TriCrit;
 int n,i; char tmp[2500];
// remplir m_exchange avec les anciennes données

n=asFC->RowCount;

strcpy(m_exchange,"");
 TriCrit= new TTriCrit(Application);
 TriCrit->ShowModal();
 delete TriCrit;

 if (strlen(m_exchange)==0) return;

 CStrip(m_exchange);
 //NB_ITEMSTRI = asFC->RowCount-1;

}
//---------------------------------------------------------------------------

void __fastcall TTri::Strip(char *s)
{
 char tmp[5000];
 int Row;   int count;
 Row = asFC->RowCount-1;
 if ((Row>=1) && (asFC->Cells[0][Row] != "")) asFC->RowCount++;
 Row=asFC->RowCount-1;

 asFC->Cells[0][Row]=Row;

 //Ghost->ExtractValue(tmp,s,"CH",0);
 Ghost->ExtractValue(tmp,s,"champs",0);
 Clean(asFC);
 count = Explode('|',s);
 NB_ITEMS_TRI[pc] = count;
 if (count)
   {
    for (Row=1; Row<=count; Row++)
      {

       if (Row>1) asFC->RowCount++;
       asFC->Cells[0][Row]=IntToStr(Row);
       Ghost->ExtractValue(tmp,params[Row-1],"CH",0);
       asFC->Cells[1][Row]=AnsiString(tmp);

       asFC->Colors[2][Row]=RGB(0,0,0);
       Ghost->ExtractValue(tmp,params[Row-1],"N0",0);
       asFC->Cells[3][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"N1",0);
       asFC->Cells[4][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"N2",0);
       asFC->Cells[5][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"N3",0);
       asFC->Cells[6][Row]=AnsiString(tmp);

       asFC->Colors[8][Row] = RGB(255,255,153);
       asFC->Colors[10][Row] = RGB(255,255,153);
       asFC->Colors[11][Row] = RGB(255,255,153);
       asFC->Colors[12][Row] = RGB(255,255,153);
       asFC->Colors[13][Row] = RGB(255,255,153);

       asFC->Colors[7][Row]=RGB(0,0,0);
       Ghost->ExtractValue(tmp,params[Row-1],"DT",0);
       asFC->Cells[8][Row]=AnsiString(tmp);
       asFC->Colors[9][Row]=RGB(0,0,0);
       Ghost->ExtractValue(tmp,params[Row-1],"TR",0);
       asFC->Cells[12][Row]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"BL",0);
       asFC->Cells[13][Row]=AnsiString(tmp);


       // Zone memoires a remplir
       Ghost->ExtractValue(tmp,params[Row-1],"lc",0);
       T_LLCC[pc][Row-1]=AnsiString(tmp);

       asFC->Cells[10][Row]=" ";
       asFC->Cells[11][Row]=" ";
       asFC->Cells[12][Row]=" ";
       asFC->Cells[13][Row]=" ";

       if (T_LLCC[pc][Row-1]=="L") asFC->Cells[10][Row]="X";
       if (T_LLCC[pc][Row-1]=="C") asFC->Cells[11][Row]="X";
       if (T_LLCC[pc][Row-1]=="T") asFC->Cells[12][Row]="X";
       if (T_LLCC[pc][Row-1]=="B") asFC->Cells[13][Row]="X";
       //j = Row-1;
       Ghost->ExtractValue(tmp,params[Row-1],"pol",0);
       T_POL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ct",0);
       T_CTEXT[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"it",0);
       T_TITAL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"bd",0);
       T_TBOLD[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ht",0);
       T_HAUTEUR[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"jh",0);
       T_JSH[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"jv",0);
       T_JSV[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"cb",0);
       T_CBKG[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"lg",0);
       T_TLARG[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ls1",0);
       T_LS1[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ep1",0);
       T_LS1EP[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"cl1",0);
       T_LS1CL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"st1",0);
       T_LS1ST[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ls2",0);
       T_LS2[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"ep2",0);
       T_LS2EP[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"cl2",0);
       T_LS2CL[pc][Row-1]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[Row-1],"st2",0);
       T_LS2ST[pc][Row-1]=AnsiString(tmp);

      }
   }
}


void __fastcall TTri::Assign_Globals()
{
int Row,cnt,i,j;
cnt=asFC->RowCount-1;

if (cb1->Checked == true) P_DETAIL[pc]=1; else P_DETAIL[pc]=0;
for (Row=1;Row<=cnt;Row++)
  {
    for (j=0;j<8;j++)
      {
       P_NIV0[pc][Row-1] = 0;
       P_NIV1[pc][Row-1] = 0;
       P_NIV2[pc][Row-1] = 0;
       P_NIV3[pc][Row-1] = 0;
      }


    if (asFC->Cells[3][Row]=="X") P_NIV0[pc][Row-1]=1;
    if (asFC->Cells[4][Row]=="X") P_NIV1[pc][Row-1]=1;
    if (asFC->Cells[5][Row]=="X") P_NIV2[pc][Row-1]=1;
    if (asFC->Cells[6][Row]=="X") P_NIV3[pc][Row-1]=1;



    P_FIELD[pc][Row-1] = asFC->Cells[1][Row];

    if (asFC->Cells[10][Row] == "X") { T_LLCC[pc][Row-1] = "L";  P_ATTR[pc][Row-1]='L'; }
    if (asFC->Cells[11][Row] == "X") { T_LLCC[pc][Row-1] = "C";  P_ATTR[pc][Row-1]='C'; }
    if (asFC->Cells[12][Row] == "X") { T_LLCC[pc][Row-1] = "T";  P_ATTR[pc][Row-1]='T'; }
    if (asFC->Cells[13][Row] == "X") { T_LLCC[pc][Row-1] = "B";  P_ATTR[pc][Row-1]='B'; }

    if (asFC->Cells[8][Row]=="X") {E_ENV[pc][Row-1]="X"; P_ENV[pc][Row-1] = 1; }
       else { E_ENV[pc][Row-1]=" "; P_ENV[pc][Row-1] = 0; }
  }
}


void __fastcall TTri::CStrip(char *s)
{
 char tmp[2500];
 int Row;   int count; int ins;
 Row = asFC->RowCount;
// if ((Row>=1) && (asFC->Cells[0][Row] != "")) asFC->RowCount++;
 Row=asFC->RowCount;


 Ghost->ExtractValue(tmp,s,"des",0);
 mTri->SetTextBuf(tmp);

 Ghost->ExtractValue(tmp,s,"champs",0);
 // Clean(asFC);
 count = Explode('|',tmp);
 if (count)
   {
    Row=asFC->RowCount;
    if (Row==2 && asFC->Cells[1][1]=="") Row=1;
    for (ins=0; ins<count; ins++)
      {
       if ((Row+ins)>1) asFC->RowCount++;
       asFC->Cells[0][ins+Row]=IntToStr(ins+Row);
       asFC->Cells[1][ins+Row]=AnsiString(params[ins]);
       asFC->Colors[2][ins+Row]=RGB(0,0,0);
       asFC->Colors[8][ins+Row] = RGB(255,255,153);
       asFC->Colors[10][ins+Row] = RGB(255,255,153);
       asFC->Colors[11][ins+Row] = RGB(255,255,153);
       asFC->Colors[12][ins+Row] = RGB(255,255,153);
       asFC->Colors[13][ins+Row] = RGB(255,255,153);
       asFC->Colors[7][ins+Row]=RGB(0,0,0);
       asFC->Colors[9][ins+Row]=RGB(0,0,0);
      }
   }
}


void __fastcall TTri::Clean(TAdvStringGrid *adv)
{
 int row,col,nrow,ncol;
 nrow=adv->RowCount;
 ncol=adv->ColCount;

 for (row=1;row<nrow;row++)
   {
    for (col=1;col<ncol;col++) adv->Cells[col][row]="";
   }
 adv->RowCount=2;
}


int __fastcall TTri::Explode(char sep,char *str)
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

void __fastcall TTri::FormClose(TObject *Sender, TCloseAction &Action)
{
/*
SaveData(0);
strcpy(P_TRI[pc],current_tri);
RELOADTRI[pc]=true;
Save_Preseance();
if (strcmp(mode,"utiliser")==0) { strcpy(m_mode,"orgtri"); Close(); }

 else
  {
   strcpy(mode,"utiliser");
   Modify();
  }
*/
Button3->Visible=false;
Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TTri::btAnnulClick(TObject *Sender)
{
 etat =0;
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TTri::asFCContextPopup(TObject *Sender, TPoint &MousePos,
      bool &Handled)
{
TFDTligne *TLigne;
TFDTcol   *TCol;
TDescEnvelop *TDE;
TFDEspace  *TEsp;
TFDTrait   *TTrait;

int X,Y; int ACol,ARow;
 X = MousePos.x;
 Y = MousePos.y;
 asFC->MouseToCell(X, Y, ACol, ARow);

 if ((ARow<1) || ((ARow>asFC->RowCount-1))) return;
 if (ACol==8)
   {
    if (asFC->Cells[ACol][ARow]=="X")
      {
       TDE= new TDescEnvelop(Application);
       Params_Env(ARow);
       TDE->ShowModal();
       delete TDE;
       if (strlen(m_exchange)==0) return;
       Recup_Env(ARow);
      }
    }


 if (ACol==10)
   {
     if (asFC->Cells[ACol][ARow]=="X")
      {
    //Envoi_Params(ARow);
     TLigne = new TFDTligne(Application);
     Envoi_Params(ARow); // $$$$ preparer les données a passer dans m_exchange
    TLigne->ShowModal();
    delete TLigne;
    if (strlen(m_exchange)==0) return;
    // recuperer les donnees
    Recupere_Params(ARow);
    }
   }

 if (ACol==11)
   {
     if (asFC->Cells[ACol][ARow]=="X")
      {
       TCol = new TFDTcol(Application);
       Envoi_Params(ARow);// $$$$ preparer les données a passer dans m_exchange
       TCol->ShowModal();
     delete TCol;
      if (strlen(m_exchange)==0) return;
    // recuperer les donnees
    Recupere_Params(ARow);
    }
   }

 if (ACol==12)
   {
     if (asFC->Cells[ACol][ARow]=="X")
      {
    TTrait= new TFDTrait(Application);
    Envoi_Params_TE(ARow);
    TTrait->ShowModal();
    delete TTrait;
    if (strlen(m_exchange)==0) return;
    Recupere_Params_TE(ARow);
    }
   }

 if (ACol==13)
   {
     if (asFC->Cells[ACol][ARow]=="X")
      {
     // Occulter le style
    TEsp= new TFDEspace(Application);
    Envoi_Params_TE(ARow);
    TEsp->ShowModal();
    delete TEsp;
    if (strlen(m_exchange)==0) return;
    Recupere_Params_TE(ARow);
    }
   }

 OldRow = ARow;
 OldCol = ACol;


}
//---------------------------------------------------------------------------

int __fastcall TTri::Exec_Reports()
{
 int col,row;
 char tmp[250];


 col=OldCol;
 row=OldRow;
 strcpy(tmp,m_reports);

 strcpy(m_reports,"");
 return 0;
}


void __fastcall TTri::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled = false;
 if (strcmp(m_sender,"modtri")==0)
  {
   if (strlen(m_reports))
       Exec_Reports();
  }

 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TTri::btModClick(TObject *Sender)
{
TTriCrit *TriCrit;
int n,i; char tmp[2500];
// remplir m_exchange avec les anciennes données

n=asFC->RowCount;
if (OldRow==0) return;
strcpy(m_exchange,"");

 TriCrit= new TTriCrit(Application);
 TriCrit->ShowModal();
 delete TriCrit;

 if (strlen(m_exchange)==0) return;

 // Extraire Le Premier champ et le mettre dans OldROW
Ghost->ExtractValue(tmp,m_exchange,"des",0);
 mTri->SetTextBuf(tmp);

 Ghost->ExtractValue(tmp,m_exchange,"champs",0);
 // Clean(asFC);
 int count = Explode('|',tmp);
 if (count==0) return;
 if (count > 1)
   {
    Application->MessageBoxA("Seul le 1er champ sera sélectionné",m_ecoplan,MB_OK);
   }
       // asFC->Cells[0][OldRow]=IntToStr(ins);
       asFC->Cells[1][OldRow]=AnsiString(params[0]);

}
//---------------------------------------------------------------------------
void __fastcall TTri::Save_Preseance()
{
FILE *fp;
int i,count;  char tmp[250];
//strcpy(filename,DatabaseName);
//strcat(filename,"_reports.txt");
strcpy(tmp,m_directory); strcat(tmp,"\\eco_tri.txt");
count=lbTri->Items->Count;
fp = fopen(tmp,"wt");
for (i=0;i<count;i++)
  {
   sprintf(tmp,"<l>%s</l>\n",lbTri->Items->Strings[i].c_str());
   fputs(tmp,fp);
  }
fclose(fp);
}

void __fastcall TTri::Envoi_Params_TE(int row)
{
 int xrow;

 xrow = row-1;
// HAUTEUR est l'epaisseur
if (T_POL[pc][xrow] == "Arial")  T_POL[pc][xrow] == "__________";
strcpy(m_exchange,"<pol>");strcat(m_exchange,T_POL[pc][xrow].c_str()); strcat(m_exchange,"</pol>");
strcat(m_exchange,"<ct>");strcat(m_exchange,T_CTEXT[pc][xrow].c_str()); strcat(m_exchange,"</ct>");
strcat(m_exchange,"<ht>");strcat(m_exchange,T_HAUTEUR[pc][xrow].c_str()); strcat(m_exchange,"</ht>");
}

void __fastcall TTri::Recupere_Params_TE(int Row)
{
 char tmp[250];
 int xRow;
 xRow = Row-1;


       Ghost->ExtractValue(tmp,m_exchange,"pol",0);
       T_POL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ct",0);
       T_CTEXT[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ht",0);
       T_HAUTEUR[pc][xRow]=AnsiString(tmp);
}

void __fastcall TTri::Envoi_Params(int row)
{
int xrow;
xrow = row-1;
if (T_POL[pc][xrow]==NULL) T_POL[pc][xrow]=="Arial";

strcpy(m_exchange,"<lc>");strcat(m_exchange,T_LLCC[pc][xrow].c_str()); strcat(m_exchange,"</lc>");
strcat(m_exchange,"<pol>");strcat(m_exchange,T_POL[pc][xrow].c_str()); strcat(m_exchange,"</pol>");
strcat(m_exchange,"<ct>");strcat(m_exchange,T_CTEXT[pc][xrow].c_str()); strcat(m_exchange,"</ct>");
strcat(m_exchange,"<it>");strcat(m_exchange,T_TITAL[pc][xrow].c_str()); strcat(m_exchange,"</it>");
strcat(m_exchange,"<bd>");strcat(m_exchange,T_TBOLD[pc][xrow].c_str()); strcat(m_exchange,"</bd>");
strcat(m_exchange,"<ht>");strcat(m_exchange,T_HAUTEUR[pc][xrow].c_str()); strcat(m_exchange,"</ht>");
strcat(m_exchange,"<jh>");strcat(m_exchange,T_JSH[pc][xrow].c_str()); strcat(m_exchange,"</jh>");
strcat(m_exchange,"<jv>");strcat(m_exchange,T_JSV[pc][xrow].c_str()); strcat(m_exchange,"</jv>");
strcat(m_exchange,"<cb>");strcat(m_exchange,T_CBKG[pc][xrow].c_str()); strcat(m_exchange,"</cb>");
strcat(m_exchange,"<lg>");strcat(m_exchange,T_TLARG[pc][xrow].c_str()); strcat(m_exchange,"</lg>");
strcat(m_exchange,"<ls1>");strcat(m_exchange,T_LS1[pc][xrow].c_str()); strcat(m_exchange,"</ls1>");
strcat(m_exchange,"<ep1>");strcat(m_exchange,T_LS1EP[pc][xrow].c_str()); strcat(m_exchange,"</ep1>");
strcat(m_exchange,"<cl1>");strcat(m_exchange,T_LS1CL[pc][xrow].c_str()); strcat(m_exchange,"</cl1>");
strcat(m_exchange,"<st1>");strcat(m_exchange,T_LS1ST[pc][xrow].c_str()); strcat(m_exchange,"</st1>");
strcat(m_exchange,"<ls2>");strcat(m_exchange,T_LS2[pc][xrow].c_str()); strcat(m_exchange,"</ls2>");
strcat(m_exchange,"<ep2>");strcat(m_exchange,T_LS2EP[pc][xrow].c_str()); strcat(m_exchange,"</ep2>");
strcat(m_exchange,"<cl2>");strcat(m_exchange,T_LS2CL[pc][xrow].c_str()); strcat(m_exchange,"</cl2>");
strcat(m_exchange,"<st2>");strcat(m_exchange,T_LS2ST[pc][xrow].c_str()); strcat(m_exchange,"</st2>");
}

void __fastcall TTri::Recupere_Params(int Row)
{
 char tmp[250];
 int xRow;
 xRow = Row-1;

       Ghost->ExtractValue(tmp,m_exchange,"lc",0);
       T_LLCC[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"pol",0);
       T_POL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ct",0);
       T_CTEXT[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"it",0);
       T_TITAL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"bd",0);
       T_TBOLD[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ht",0);
       T_HAUTEUR[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"jh",0);
       T_JSH[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"jv",0);
       T_JSV[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"cb",0);
       T_CBKG[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"lg",0);
       T_TLARG[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ls1",0);
       T_LS1[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ep1",0);
       T_LS1EP[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"cl1",0);
       T_LS1CL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"st1",0);
       T_LS1ST[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ls2",0);
       T_LS2[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ep2",0);
       T_LS2EP[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"cl2",0);
       T_LS2CL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"st2",0);
       T_LS2ST[pc][xRow]=AnsiString(tmp);
}


void __fastcall TTri::Params_Env(int Row)
{
int xrow;
xrow = Row-1;
strcpy(m_exchange,"<lc>");strcat(m_exchange,E_ENV[pc][xrow].c_str()); strcat(m_exchange,"</lc>");
strcat(m_exchange,"<pol>");strcat(m_exchange,E_POL[pc][xrow].c_str()); strcat(m_exchange,"</pol>");
strcat(m_exchange,"<ct>");strcat(m_exchange,E_CTEXT[pc][xrow].c_str()); strcat(m_exchange,"</ct>");
strcat(m_exchange,"<it>");strcat(m_exchange,E_TITAL[pc][xrow].c_str()); strcat(m_exchange,"</it>");
strcat(m_exchange,"<bd>");strcat(m_exchange,E_TBOLD[pc][xrow].c_str()); strcat(m_exchange,"</bd>");
strcat(m_exchange,"<ht>");strcat(m_exchange,E_HAUTEUR[pc][xrow].c_str()); strcat(m_exchange,"</ht>");
strcat(m_exchange,"<jh>");strcat(m_exchange,E_JSH[pc][xrow].c_str()); strcat(m_exchange,"</jh>");
strcat(m_exchange,"<jv>");strcat(m_exchange,E_JSV[pc][xrow].c_str()); strcat(m_exchange,"</jv>");
strcat(m_exchange,"<cb>");strcat(m_exchange,E_CBKG[pc][xrow].c_str()); strcat(m_exchange,"</cb>");
strcat(m_exchange,"<lg>");strcat(m_exchange,E_TLARG[pc][xrow].c_str()); strcat(m_exchange,"</lg>");

strcat(m_exchange,"<coult>");strcat(m_exchange,E_COULTRAIT[pc][xrow].c_str()); strcat(m_exchange,"</coult>");
strcat(m_exchange,"<ep>");strcat(m_exchange,E_EPAISS[pc][xrow].c_str()); strcat(m_exchange,"</ep>");
strcat(m_exchange,"<style>");strcat(m_exchange,E_STYLE[pc][xrow].c_str()); strcat(m_exchange,"</style>");
strcat(m_exchange,"<design>");strcat(m_exchange,E_DESIGN[pc][xrow].c_str()); strcat(m_exchange,"</design>");
strcat(m_exchange,"<encadr>");strcat(m_exchange,E_ENCADR[pc][xrow].c_str()); strcat(m_exchange,"</encadr>");
}
void __fastcall TTri::Recup_Env(int Row)
{
char tmp[250]; int xRow;
xRow = Row-1;
       Ghost->ExtractValue(tmp,m_exchange,"lc",0);
       E_ENV[pc][xRow]=AnsiString(tmp);
       if (E_ENV[pc][xRow]=="X") P_ENV[pc][xRow]=1; else P_ENV[pc][xRow]=0;
       Ghost->ExtractValue(tmp,m_exchange,"pol",0);
       E_POL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ct",0);
       E_CTEXT[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"it",0);
       E_TITAL[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"bd",0);
       E_TBOLD[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ht",0);
       E_HAUTEUR[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"jh",0);
       E_JSH[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"jv",0);
       E_JSV[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"cb",0);
       E_CBKG[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"lg",0);
       E_TLARG[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"coult",0);
       E_COULTRAIT[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"ep",0);
       E_EPAISS[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"style",0);
       E_STYLE[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"design",0);
       E_DESIGN[pc][xRow]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,m_exchange,"encadr",0);
       E_ENCADR[pc][xRow]=AnsiString(tmp);
}


//---------------------------------------------------------------------------

void __fastcall TTri::asFCClickCell(TObject *Sender, int ARow, int ACol)
{


 if (ARow==0) return;
 if (ACol==3)
    {
     asFC->Cells[3][ARow]="X";
     asFC->Cells[4][ARow]="";
     asFC->Cells[5][ARow]="";
     asFC->Cells[6][ARow]="";
     P_NIV0[pc][ARow-1] == 1;
     P_NIV1[pc][ARow-1] == 0;
     P_NIV2[pc][ARow-1] == 0;
     P_NIV3[pc][ARow-1] == 0;
    }
 if (ACol==4)
    {
     asFC->Cells[3][ARow]="";
     asFC->Cells[4][ARow]="X";
     asFC->Cells[5][ARow]="";
     asFC->Cells[6][ARow]="";
     P_NIV0[pc][ARow-1] == 0;
     P_NIV1[pc][ARow-1] == 1;
     P_NIV2[pc][ARow-1] == 0;
     P_NIV3[pc][ARow-1] == 0;
    }
 if (ACol==5)
    {
     asFC->Cells[3][ARow]="";
     asFC->Cells[4][ARow]="";
     asFC->Cells[5][ARow]="X";
     asFC->Cells[6][ARow]="";
     P_NIV0[pc][ARow-1] == 0;
     P_NIV1[pc][ARow-1] == 0;
     P_NIV2[pc][ARow-1] == 1;
     P_NIV3[pc][ARow-1] == 0;
    }

 if (ACol==6)
    {
     asFC->Cells[3][ARow]="";
     asFC->Cells[4][ARow]="";
     asFC->Cells[5][ARow]="";
     asFC->Cells[6][ARow]="X";
     P_NIV0[pc][ARow-1] == 0;
     P_NIV1[pc][ARow-1] == 0;
     P_NIV2[pc][ARow-1] == 0;
     P_NIV3[pc][ARow-1] == 1;
    }

 if (ACol==8)  // Enveloppe
   {
    //if (P_GENRE[pc] == 'C')
    //  { Application->MessageBoxA("Planning en Mode Compressé : Pas d'Enveloppes",m_ecoplan,MB_OK);
    //    return;
    //  }
    if (asFC->Cells[ACol][ARow]=="X")  { asFC->Cells[ACol][ARow]=" "; P_ENV[pc][ARow-1]=0; }
     else { asFC->Cells[ACol][ARow]="X";  P_ENV[pc][ARow-1] = 1; }


   }

 if (ACol==10)
   {
    if (asFC->Cells[1][ARow]=="") return;
    asFC->Cells[10][ARow]="X";
    asFC->Cells[11][ARow]="";
    asFC->Cells[12][ARow]="";
    asFC->Cells[13][ARow]="";
    T_LLCC[pc][ARow-1]="L";
    /*
    Envoi_Params(ARow);

    TLigne = new TFDTligne(Application);
    // $$$$ preparer les données a passer dans m_exchange
    TLigne->ShowModal();
    delete TLigne;
    if (strlen(m_exchange)==0) return;
    // recuperer les donnees
    Recupere_Params(ARow);
    */
   }

 if (ACol==11)
   {
    if (asFC->Cells[1][ARow]=="") return;
    asFC->Cells[10][ARow]="";
    asFC->Cells[11][ARow]="X";
    asFC->Cells[12][ARow]="";
    asFC->Cells[13][ARow]="";
    T_LLCC[pc][ARow-1]="C";
    /*
    TCol = new TFDTcol(Application);
    // $$$$ preparer les données a passer dans m_exchange
    TCol->ShowModal();
    delete TCol;
    if (strlen(m_exchange)==0) return;
    // recuperer les donnees
    */
   }


   if (ACol==12)
   {
    if (asFC->Cells[1][ARow]=="") return;
    asFC->Cells[10][ARow]="";
    asFC->Cells[11][ARow]="";
    asFC->Cells[12][ARow]="X";
    asFC->Cells[13][ARow]="";
    T_LLCC[pc][ARow-1]="T";  // Traits
   }

   if (ACol==13)
   {
    if (asFC->Cells[1][ARow]=="") return;
    asFC->Cells[10][ARow]="";
    asFC->Cells[11][ARow]="";
    asFC->Cells[12][ARow]="";
    asFC->Cells[13][ARow]="X";
    T_LLCC[pc][ARow-1]="B";  // Blancs
   }
 Assign_Globals();

 OldRow = ARow;
 OldCol = ACol;
}
//---------------------------------------------------------------------------

void __fastcall TTri::lbTriClick(TObject *Sender)
{
 int indx; char tmp[5000];  AnsiString Content;
 int rc,recdata; char Key[100],RetKey[100];
 char filename[250]; int result;

 Clean(asFC);

 indx = lbTri->ItemIndex;
 if (indx == -1) return;

 strcpy(tmp,lbTri->Items->Strings[indx].c_str());

 Content = lbTri->Items->Strings[indx];
 //lbTri->Items->Delete(indx);
 //lbTri->Items->Insert(0,Content);


 Display_Tri(tmp);

 /*
 result = Display_Tri(tmp);
 if (result == 0)
  {
   // effacement de la ligne dans lbTRi
   lbTri->Items->Delete(indx);

  }
 else
 {
 lbTri->Items->Move(indx,0);
 lbTri->ItemIndex=0;
 Save_Preseance();
 }
 */

 nomTri = eMemoire->Text;
 nomFile = direct+"\\Ref\\";
 AdvStringGrid1->LoadFromFile(nomFile+nomTri);

 for(int i = 0; i<asFC->RowCount; i++)
 {


 asFC->Cells[1][i] = AdvStringGrid1->Cells[1][i];
 asFC->Cells[2][i] = AdvStringGrid1->Cells[2][i];
 asFC->Cells[3][i] = AdvStringGrid1->Cells[3][i];
 asFC->Cells[4][i] = AdvStringGrid1->Cells[4][i];
 asFC->Cells[5][i] = AdvStringGrid1->Cells[5][i];
 asFC->Cells[6][i] = AdvStringGrid1->Cells[6][i];
 asFC->Cells[7][i] = AdvStringGrid1->Cells[7][i];
 asFC->Cells[8][i] = AdvStringGrid1->Cells[8][i];
 asFC->Cells[9][i] = AdvStringGrid1->Cells[9][i];
 asFC->Cells[10][i] = AdvStringGrid1->Cells[10][i];
 asFC->Cells[11][i] = AdvStringGrid1->Cells[11][i];
 asFC->Cells[12][i] = AdvStringGrid1->Cells[12][i];
 asFC->Cells[13][i] = AdvStringGrid1->Cells[13][i];

 }

 AdvStringGrid2->RowCount = asFC->RowCount;


}

int __fastcall TTri::Display_Tri(char *s)
{
 int indx; char tmp[5000];
 int rc,recdata; char Key[100],RetKey[100];
 char filename[250];

 if (strlen(s)==0) return 1;
 eMemoire->Text=AnsiString(s);
 strcpy(current_tri,s);
 // Read Data and display it

 strcpy(filename,m_directory); strcat(filename,"\\eco_tri");
 rc = tri->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = tri->SetIndexMode(0,0);

  strcpy(Key,current_tri);
  rc=tri->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
   { Application->MessageBoxA("Tri non trouvé dans la base de données",m_ecoplan,MB_OK);
    return 0;
   }

 rc=tri->ReadRecord(buffer,recdata);
 if (rc)
   { // extract

    Ghost->ExtractValue(tmp,buffer,"l",0);
    eMemoire->SetTextBuf(tmp);
    Ghost->ExtractValue(tmp,buffer,"des",0);
    mTri->Clear();
    mTri->SetTextBuf(tmp);
    Ghost->ExtractValue(tmp,buffer,"detail",0);
    cb1->Checked=true; if (strcmp(tmp,"N")==0) cb1->Checked=false;
    Ghost->ExtractValue(tmp,buffer,"champs",0);
    if (strlen(tmp)) Strip(tmp);
    Ghost->ExtractValue(tmp,buffer,"envelop",0);
    if (strlen(tmp)) StripEnvelop(tmp);
    /////////////////
    Assign_Globals();
   }
 tri->CloseEngine();
 return 1;
}

void __fastcall TTri::StripEnvelop(char *s)
{
 char tmp[5000];
 int count,i;
 count = Explode('|',s);
 if (count>8) count=8;
 //NB_ITEMSTRI;
 if (count)
   {
    for (i=0; i<count; i++)
      {
       Ghost->ExtractValue(tmp,params[i],"lc",0);
       // $$$$ if (P_GENRE[pc]=='C') strcpy(tmp," ");
       if (strcmp(tmp,"X")==0) { P_ENV[pc][i]=1; E_ENV[pc][i]="X"; asFC->Cells[8][i+1] = "X"; }
       else { P_ENV[pc][i]=0; E_ENV[pc][i] = " ";asFC->Cells[8][i+1] = " "; }


       Ghost->ExtractValue(tmp,params[i],"pol",0);   // ft
       E_POL[pc][i]= P_FONT[pc][i];
       Ghost->ExtractValue(tmp,params[i],"ct",0);
       E_CTEXT[pc][i]= P_CFCOLOR[pc][i];
       Ghost->ExtractValue(tmp,params[i],"it",0);
       E_TITAL[pc][i]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"bd",0);
       E_TBOLD[pc][i]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"ht",0);
       E_HAUTEUR[pc][i]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"cb",0);
       E_CBKG[pc][i]=AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"jh",0);
       E_JSH[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"jv",0);
       E_JSV[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"lg",0);      // largeur
       E_TLARG[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"coult",0);
       E_COULTRAIT[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"style",0);
       E_STYLE[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"epaiss",0);
       E_EPAISS[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"design",0);
       E_DESIGN[pc][i] = AnsiString(tmp);
       Ghost->ExtractValue(tmp,params[i],"encadr",0);
       E_ENCADR[pc][i] = AnsiString(tmp);
      }
   }


}

//---------------------------------------------------------------------------

void __fastcall TTri::btHautClick(TObject *Sender)
{
 int XRow;
 int i,count;
 AnsiString l0,l1,l2,l3,l4,l5,l8,l9,l10,l11,l12,l13;
 AnsiString L[14];
 if (OldRow==0)
   {Application->MessageBoxA("Pas de ligne sélectionnée",m_ecoplan,MB_OK);
    return;
   }
 count=asFC->RowCount-1;
 if(OldRow == 1) return;
 // l0= asFC->Cells[0][OldRow];
 for (i=1;i<asFC->ColCount;i++)  L[i] = asFC->Cells[i][OldRow];

/*
 l1= asFC->Cells[1][OldRow];
 l2= asFC->Cells[3][OldRow];
 l3= asFC->Cells[4][OldRow];
 l4= asFC->Cells[5][OldRow];
 l5= asFC->Cells[6][OldRow];
 */
 XRow=OldRow-1;
 for (i=1; i<asFC->ColCount; i++) { asFC->Cells[i][OldRow]= asFC->Cells[i][XRow];
  asFC->Cells[i][XRow] = L[i];
  }

 /*
 // asFC->Cells[0][OldRow]=asFC->Cells[0][XRow]; asFC[0][XRow]=l0;
 asFC->Cells[1][OldRow]=asFC->Cells[1][XRow]; asFC->Cells[1][XRow]=l1;
 asFC->Cells[3][OldRow]=asFC->Cells[3][XRow]; asFC->Cells[3][XRow]=l2;
 asFC->Cells[4][OldRow]=asFC->Cells[4][XRow]; asFC->Cells[4][XRow]=l3;
 asFC->Cells[5][OldRow]=asFC->Cells[5][XRow]; asFC->Cells[5][XRow]=l4;
 asFC->Cells[6][OldRow]=asFC->Cells[6][XRow]; asFC->Cells[6][XRow]=l5;
 */
 OldRow=XRow;
}
//---------------------------------------------------------------------------

void __fastcall TTri::btBasClick(TObject *Sender)
{
int XRow;
 int i,indx,count;
 AnsiString l0,l1,l2,l3,l4,l5;
 AnsiString L[14];

 if (OldRow==0)
   {Application->MessageBoxA("Pas de ligne sélectionnée",m_ecoplan,MB_OK);
    return;
   }
 count = asFC->RowCount-1;
 if(OldRow == count) return;
 if (OldRow ==0) return;

 for (i=1;i<asFC->ColCount;i++)  L[i] = asFC->Cells[i][OldRow];
 /*
 // l0= asFC->Cells[0][OldRow];
 l1= asFC->Cells[1][OldRow];
 l2= asFC->Cells[3][OldRow];
 l3= asFC->Cells[4][OldRow];
 l4= asFC->Cells[5][OldRow];
 l5= asFC->Cells[6][OldRow];
 */
 XRow=OldRow+1;
 for (i=1; i<asFC->ColCount; i++) { asFC->Cells[i][OldRow]= asFC->Cells[i][XRow];
  asFC->Cells[i][XRow] = L[i];
  }
 /*
 //asFC->Cells[0][OldRow]=asFC->Cells[0][XRow]; asFC[0][XRow]=l0;
 asFC->Cells[1][OldRow]=asFC->Cells[1][XRow]; asFC->Cells[1][XRow]=l1;
 asFC->Cells[3][OldRow]=asFC->Cells[3][XRow]; asFC->Cells[3][XRow]=l2;
 asFC->Cells[4][OldRow]=asFC->Cells[4][XRow]; asFC->Cells[4][XRow]=l3;
 asFC->Cells[5][OldRow]=asFC->Cells[5][XRow]; asFC->Cells[5][XRow]=l4;
 asFC->Cells[6][OldRow]=asFC->Cells[6][XRow]; asFC->Cells[6][XRow]=l5;
 */
 OldRow=XRow;

}
//---------------------------------------------------------------------------

void __fastcall TTri::CleanRow(int row)
{
 int i;
 for (i=0;i<asFC->ColCount;i++)  asFC->Cells[i][row]="";
}

void __fastcall TTri::btDeleteClick(TObject *Sender)
{
 int row,col,i,j;
 if (OldRow == 0)
   {
    Application->MessageBoxA("Aucun élément sélectionné",m_ecoplan,MB_OK);
    return;
   }
 if (Application->MessageBoxA("Confirmer l'effacement",m_ecoplan,MB_YESNO)==IDNO) return;

 if (asFC->RowCount==2)  { CleanRow(1); OldRow=0; return; }
 if (OldRow == (asFC->RowCount-1)){CleanRow(OldRow); asFC->RowCount--; OldRow--; return; }

 row = asFC->RowCount;
 for (i = OldRow; i<row;i++)
   {

    for (j=1;j<asFC->RowCount;j++) asFC->Cells[j][i] = asFC->Cells[j][i+1];

   }
//  renumeroter la colonne 0

asFC->RowCount--;  row= asFC->RowCount;
//NB_ITEMSTRI = asFC->RowCount-1;

for (i=1;i<row;i++)  asFC->Cells[0][i]=IntToStr(i);
}
//---------------------------------------------------------------------------

void __fastcall TTri::btSupprimerClick(TObject *Sender)
{

 int indx; int rc,recdata; char Key[100],RetKey[100];
 char filename[250];
AnsiString directory;
 AnsiString namefichier;
indx = lbTri->ItemIndex;

directory = "Reference\\Tris\\";
if (lbTri->Items->Count==0) return;

//indx=0;
if (lbTri->Items->Strings[indx]=="") return;

// if (indx == -1)
//    {
//     Application->MessageBoxA("Pas de Tri Sélectionné",m_ecoplan,MB_OK);
//     return;
//    }
 if (Application->MessageBoxA("Confirmer l'effacement du Tri",m_ecoplan,MB_YESNO)==IDNO)
    return;

 strcpy(filename,m_directory);
 strcat(filename,"\\eco_tri");
 rc = tri->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = tri->SetIndexMode(0,0);
 strcpy(Key,lbTri->Items->Strings[indx].c_str());
 rc = tri->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc)
  {
   rc=tri->DeleteKey(0,Key,recdata);
   rc=tri->DeleteRecord(recdata);
  }
 else { Application->MessageBoxA("Record Not Found",m_ecoplan,MB_OK);
        return;
      }

  int r,c,xc,cc;
 cc=asFC->ColCount; xc=asFC->RowCount;
 for (r=0;r<xc;r++)
  {
   for (c=1;c<cc;c++)  asFC->Cells[c][r]="";
  }

 asFC->RowCount=2;

 namefichier = lbTri->Items->Strings[indx];
 AppendStr(namefichier,".tri");
 AppendStr(directory,namefichier);

 // indx=0;
 lbTri->Items->Delete(indx);
if(FileExists(namefichier))
{
  DeleteFile(namefichier);
}


 Save_Preseance();

 mTri->Clear();
// lFiltre->Caption = "";
 eMemoire->Clear();
 change = true;
 tri->CloseEngine();
 }
//---------------------------------------------------------------------------

void __fastcall TTri::btOkClick(TObject *Sender)
{
etat =0;
SaveData(0);
strcpy(P_TRI[pc],current_tri);
RELOADTRI[pc]=true;
Save_Preseance();
if (strcmp(mode,"utiliser")==0) { strcpy(m_mode,"orgtri"); Close(); }

 else
  {
   strcpy(mode,"utiliser");
   Modify();
  }

}
//---------------------------------------------------------------------------

void __fastcall TTri::btMemorClick(TObject *Sender)
{
  AnsiString ae = eMemoire->Text;
 AnsiString cc=direct+"\\Ref2\\"+ae+".txt";



 if(ae != ""){
 char str_ = ae[1];
    if(isdigit(str_))
    {
     ShowMessage("Veuillez changer de nom! Pour enregistrer un Tri, il faut que la désignation commence obligatoirement par une lettre !!!");
     return;
    }
  }
  if(ae=="")
  {
   ShowMessage("Veuillez entrer un nom pour le filtre");
   return;
  }

 for(int i =0; i< AdvStringGrid1->RowCount; i++)
 {
  AdvStringGrid2->Cells[0][i] = AdvStringGrid1->Cells[1][i];
  AdvStringGrid2->Cells[1][i] = AdvStringGrid1->Cells[3][i];
  AdvStringGrid2->Cells[2][i] = AdvStringGrid1->Cells[4][i];
  AdvStringGrid2->Cells[3][i] = AdvStringGrid1->Cells[5][i];
  AdvStringGrid2->Cells[4][i] = AdvStringGrid1->Cells[6][i];
  AdvStringGrid2->Cells[5][i] = AdvStringGrid1->Cells[8][i];
  AdvStringGrid2->Cells[6][i] = AdvStringGrid1->Cells[10][i];
  AdvStringGrid2->Cells[7][i] = AdvStringGrid1->Cells[11][i];
  AdvStringGrid2->Cells[8][i] = AdvStringGrid1->Cells[12][i];
  AdvStringGrid2->Cells[9][i] = AdvStringGrid1->Cells[13][i];
 }

 AdvStringGrid2->SaveToFile(cc);
 if(lbTri->Items->IndexOf(ae) > -1)
 {
     etat =0;

 }else{
 etat=1;

 }

 // Ghost->Glob_Tri(P_TRI[pc]);
 if(etat==0){
  TStringList *list= new TStringList;

  for (int rowint=0;rowint<AdvStringGrid1->RowCount;rowint++)
  {
    for (int colint=1;colint<AdvStringGrid1->ColCount;colint++)
    {
        if(colint == 2|| colint ==7|| colint == 9){}else{
       list->Add(AdvStringGrid1->Cells[rowint][colint]); }
    }
  }


 list->SaveToFile(eMemoire->Text);
 delete list;

AnsiString  nomTri = eMemoire->Text;
AnsiString nomFile = direct+"\\Ref\\";
 AdvStringGrid1->SaveToFile(nomFile+nomTri);}else{
  nomTri = eMemoire->Text;
 nomFile = direct+"\\Ref\\";
  asFC->SaveToFile(nomFile+nomTri);



 }
  SaveData(1);
  RELOADTRI[pc]=true;
}
//---------------------------------------------------------------------------

void __fastcall TTri::btNewClick(TObject *Sender)
{
 etat = 1;
 if (change)
   {
    if (Application->MessageBoxA("Voulez Vous Sauvegarder les Données en Cours ?",
        m_ecoplan,MB_YESNO)==IDYES) return;
   }

 Clean(asFC);
 asFC->RowCount=2;
 mTri->Clear();
 //lTri->Caption = "";
 eMemoire->Clear();

 TTriCrit *TriCrit;

 strcpy(m_exchange,"");   // m_exchange est vide, pour un nouveau

 TriCrit= new TTriCrit(Application);
 TriCrit->ShowModal();
 delete TriCrit;

 if (strlen(m_exchange)==0) return;

 CStrip(m_exchange);



}
//---------------------------------------------------------------------------

void __fastcall TTri::btAppliquerClick(TObject *Sender)
{
 int i,count;
 char tmp[1000];
 // preparer le traitement des tris
 strcpy(m_sort,"");
 // Copier les Elements a partir de la grille
 if (asFC->Cells[1][1]=="")
   {
    Application->MessageBoxA("Pas d'élément de tri",m_ecoplan,MB_OK);
    return;
   }

 //strcpy(tmp,"<pl></pl>");
 strcpy(P_TRI[pc],current_tri);
 RELOADTRI[pc] = true;


 for (i=0;i<8;i++) { P_TRICOL[pc][i]=0;
       P_ATTR[pc][i]='Z';
       P_ENV[pc][i]=0;
       P_NIV1[pc][i]=0;
       P_NIV2[pc][i]=0;
       P_NIV0[pc][i]=0;
       P_NIV3[pc][i]=0;
      }

 if (cb1->Checked == true) P_DETAIL[pc]=1; else P_DETAIL[pc]=0;
 strcpy(tmp,"<champs>");
 count = asFC->RowCount;
 for (i=1;i<count;i++)     // concatener les criteres de champs
   {
    strcat(tmp,asFC->Cells[1][i].c_str());
    strcat(tmp,"|");
    // P_TRICOL[pc][]  a calculer dans plstd
    if (asFC->Cells[10][i]=="X") P_ATTR[pc][i-1]='L';
    if (asFC->Cells[11][i]=="X") P_ATTR[pc][i-1]='C';
    if (asFC->Cells[12][i]=="X") P_ATTR[pc][i-1]='T';
    if (asFC->Cells[13][i]=="X") P_ATTR[pc][i-1]='B';

    P_FIELD[pc][i-1]= asFC->Cells[1][i];
    if (asFC->Cells[3][i]=="X") P_NIV0[pc][i-1]=1;
    if (asFC->Cells[4][i]=="X") P_NIV1[pc][i-1]=2;
    if (asFC->Cells[5][i]=="X") P_NIV2[pc][i-1]=3;
    if (asFC->Cells[6][i]=="X") P_NIV3[pc][i-1]=4;
    if (asFC->Cells[8][i]=="X") P_ENV[pc][i-1]=1;
   }
 strcat (tmp,"</champs>");
 strcpy(m_sort,tmp);


AdvStringGrid1->SaveToFile("Trimodifie.ecfg");
for(int i =1; i< AdvStringGrid1->RowCount; i++)
{if(AdvStringGrid1->Cells[1][i] != AdvStringGrid2->Cells[1][i] && etata ==0 )
  {etata =1;
  }
 if(AdvStringGrid1->Cells[2][i] != AdvStringGrid2->Cells[2][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[3][i] != AdvStringGrid2->Cells[3][i] && etata ==0 )
{etata =1;
  }
 if(AdvStringGrid1->Cells[4][i] != AdvStringGrid2->Cells[4][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[5][i] != AdvStringGrid2->Cells[5][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[6][i] != AdvStringGrid2->Cells[6][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[7][i] != AdvStringGrid2->Cells[7][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[8][i] != AdvStringGrid2->Cells[8][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[9][i] != AdvStringGrid2->Cells[9][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[10][i] != AdvStringGrid2->Cells[10][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[11][i] != AdvStringGrid2->Cells[11][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[12][i] != AdvStringGrid2->Cells[12][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[13][i] != AdvStringGrid2->Cells[13][i] && etata ==0 )
{etata =1;
  }

}


  if(etata == 1)
  {
   ListBox1->Items->Add("1");
   ListBox1->Items->SaveToFile("modif.inc");
  }else{
  ListBox1->Items->Add("0");
   ListBox1->Items->SaveToFile("modif.inc");


  }


 Close();


}
//---------------------------------------------------------------------------


void __fastcall TTri::Button1Click(TObject *Sender)
{

 char Key[100]; char str[5000];
// Assigner Tri
m_assign[0]=0;
strcpy(Key,eMemoire->Text.c_str());
 if (strlen(Key) == 0)
   {
    Application->MessageBoxA("Aucun Tri Sélectionné",m_ecoplan,MB_OK);
    return;
   }


///////

strcpy(P_TRI[pc],eMemoire->Text.c_str());
strcpy(m_assign,"<tri>"); strcat(m_assign,P_TRI[pc]); strcat(m_assign,"</tri>");
strcat(m_assign,"<org>ModTri:Button1</org>");
RELOADTRI[pc]=true;
Close();




}
//---------------------------------------------------------------------------


void __fastcall TTri::BitBtn1Click(TObject *Sender)
{
 // Up Move
  int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbTri->ItemIndex;
 if (indx == -1) return;
 count = lbTri->Items->Count;
 if (indx == 0) { lbTri->Items->Move(indx,count-1); lbTri->ItemIndex=count-1; }
 else { lbTri->Items->Move(indx,indx-1);  lbTri->ItemIndex=indx-1; }
 Save_Preseance();
}
//---------------------------------------------------------------------------

void __fastcall TTri::BitBtn2Click(TObject *Sender)
{
 // Down Move
 int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbTri->ItemIndex;
 if (indx == -1) return;
 count = lbTri->Items->Count;
 if (indx == count-1) { lbTri->Items->Move(indx,0); lbTri->ItemIndex=0; }

 else { lbTri->Items->Move(indx,indx+1); lbTri->ItemIndex=indx + 1; }
 Save_Preseance();

}
//---------------------------------------------------------------------------

void __fastcall TTri::btAffPlannClick(TObject *Sender)
{
 char Key[100]; char str[5000];
// Assigner Tri
m_assign[0]=0;
strcpy(Key,eMemoire->Text.c_str());
 if (strlen(Key) == 0)
   {
    Application->MessageBoxA("Aucun Tri Sélectionné",m_ecoplan,MB_OK);
    return;
   }


///////
for(int i =1; i< AdvStringGrid1->RowCount; i++)
{if(AdvStringGrid1->Cells[1][i] != AdvStringGrid2->Cells[1][i] && etata ==0 )
  {etata =1;
  }
 if(AdvStringGrid1->Cells[2][i] != AdvStringGrid2->Cells[2][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[3][i] != AdvStringGrid2->Cells[3][i] && etata ==0 )
{etata =1;
  }
 if(AdvStringGrid1->Cells[4][i] != AdvStringGrid2->Cells[4][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[5][i] != AdvStringGrid2->Cells[5][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[6][i] != AdvStringGrid2->Cells[6][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[7][i] != AdvStringGrid2->Cells[7][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[8][i] != AdvStringGrid2->Cells[8][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[9][i] != AdvStringGrid2->Cells[9][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[10][i] != AdvStringGrid2->Cells[10][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[11][i] != AdvStringGrid2->Cells[11][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[12][i] != AdvStringGrid2->Cells[12][i] && etata ==0 )
 {etata =1;
  }
 if(AdvStringGrid1->Cells[13][i] != AdvStringGrid2->Cells[13][i] && etata ==0 )
{etata =1;
  }

}


  if(etata == 1)
  {
   ListBox1->Items->Add("1");
   ListBox1->Items->SaveToFile("modif.inc");
  }else{
  ListBox1->Items->Add("0");
   ListBox1->Items->SaveToFile("modif.inc");


  }




strcpy(P_TRI[pc],eMemoire->Text.c_str());
strcpy(m_assign,"<tri>"); strcat(m_assign,P_TRI[pc]); strcat(m_assign,"</tri>");
strcat(m_assign,"<org>ModTri:AffecterPL</org>");
RELOADTRI[pc] = true;
etat = 0;
asFC->SaveToFile("Trimodifie.ecfg");
  if(etata == 1 || etatb ==1)
  {
   ListBox1->Items->Add("0");
   ListBox1->Items->SaveToFile("modif.inc");
  }

  etata=0;
  etatb=0;


Close();


}
//---------------------------------------------------------------------------



void __fastcall TTri::FormShow(TObject *Sender)
{
int i;
char tmp[250];
char buffer[2000];
 int rc,recdata;
 char Key[100],RetKey[100];

FILE *fp;
 Timer1->Enabled = false;

 change = false;

 strcpy(tmp,m_directory); strcat(tmp,"\\eco_tri.txt");
 tri = new realisam;
 asFC->RowCount=2;
 OldRow=0; OldCol=0;

 fp=fopen(tmp,"rt");
 lbTri->Clear();
 if (fp == NULL)
   {
    change = true;
   }
 else  // lire et remplir le tableau
   {
    buffer[0]=0;
    fgets(buffer,512,fp);
    while (!feof(fp))
      {
       if (strlen(buffer)>5)
        {
         Ghost->ExtractValue(tmp,buffer,"l",0);
         lbTri->Items->Add(AnsiString(tmp));
        }
       fgets(buffer,512,fp);
      }
    fclose(fp);
   }

   strcpy(mode,"utiliser");
  Ghost->ExtractValue(mode,m_exchange,"util",0);

  if (strcmp(m_mode,"orgplanning")!=0)
    {
    if (strlen(m_exchange))
     {
      Ghost->ExtractValue(tmp,m_exchange,"tri",0);
      if (strlen(tmp)) Display_Tri(tmp);
     }
    }
  else Load_From_Globals();


   Modify();

 Timer1->Enabled=true;
}

void __fastcall TTri::Load_From_Globals()
{
 int i;
 int row;

 eMemoire->Text = AnsiString(P_TRI[pc]);
 Clean(asFC);
 row = 1;

 // for (i=0;i < 8; i++)
 for (i=0;i<NB_ITEMS_TRI[pc];i++)
   {
    if (P_ATTR[pc][i] != 'Z')
      {
       if (row > 1) asFC->RowCount++;
       if (P_ATTR[pc][i] == 'L') asFC->Cells[10][row] = "X";
       if (P_ATTR[pc][i] == 'C') asFC->Cells[11][row] = "X";
       if (P_ATTR[pc][i] == 'T') asFC->Cells[12][row] = "X";
       if (P_ATTR[pc][i] == 'B') asFC->Cells[13][row] = "X";

       asFC->Cells[0][row] = IntToStr(row);
       asFC->Cells[1][row] = P_FIELD[pc][i];
       if (P_NIV0[pc][i] == 1) asFC->Cells[3][row] = "X"; else asFC->Cells[3][row]=" ";
       if (P_NIV1[pc][i] == 1) asFC->Cells[4][row] = "X"; else asFC->Cells[4][row]=" ";
       if (P_NIV2[pc][i] == 1) asFC->Cells[5][row] = "X"; else asFC->Cells[5][row]=" ";
       if (P_NIV3[pc][i] == 1) asFC->Cells[6][row] = "X"; else asFC->Cells[6][row]=" ";

       // if (P_GENRE[pc] == 'C') { E_ENV[pc][i] = " "; P_ENV[pc][i] = 0; }
       if (E_ENV[pc][i] == "X")
          { asFC->Cells[8][row] = "X";
            P_ENV[pc][i] = 1;
           }
           else
           { asFC->Cells[8][row]=" ";
             P_ENV[pc][i] = 0;
           }
        row++;
       }
     if (P_DETAIL[pc] == 1) cb1->Checked = true; else cb1->Checked = false;
    }

}


//---------------------------------------------------------------------------

void __fastcall TTri::cb1Click(TObject *Sender)
{
 if (cb1->Checked == true) P_DETAIL[pc] = 1;
   else P_DETAIL[pc]=0;
}
//---------------------------------------------------------------------------

void __fastcall TTri::btAideClick(TObject *Sender)
{
if(eMemoire->Text == "Rivoiron")
{
 Button3->Visible= true;
 return;
}
Thelp *Aide;
 strcpy(m_help,"TrierGrouper.html#TG0");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TTri::Button2Click(TObject *Sender)
{

lbTri->Sorted = false;
AnsiString element;
AnsiString elementunique;
TStringList *ListeChiffres = new TStringList;
TStringList *ListeLettres = new TStringList;
TStringList *ListeComplete = new TStringList;


for(int i = 0; i< lbTri->Items->Count; i++)
{
element= lbTri->Items->Strings[i];
if(element == "")
{
return;}else{
 elementunique=element[1];
 if(elementunique == '0' || elementunique == '1' || elementunique == '2' || elementunique == '3' || elementunique == '4' ||elementunique == '5' ||elementunique == '6' ||elementunique == '7' ||elementunique == '8' ||elementunique == '9')
 {
   ListeChiffres->Add(element);
 }else{
   ListeLettres->Add(element);

 }

}

}

lbTri->Clear();
ListeLettres->Sorted= true;
 ListeChiffres->Sorted = true;

 for(int j = 0; j < ListeLettres->Count; j++)
 {
 ListeComplete->Add(ListeLettres->Strings[j]);

 }

 for(int k = 0; k < ListeChiffres->Count; k++)
 {
 ListeComplete->Add(ListeChiffres->Strings[k]);

 }



 lbTri->Items->Assign(ListeComplete);


ListeChiffres->Clear();
ListeLettres->Clear();
ListeComplete->Clear();
 delete ListeLettres;
delete ListeChiffres;
delete ListeComplete;
Save_Preseance();

}
//---------------------------------------------------------------------------



void __fastcall TTri::FormCreate(TObject *Sender)
{
  etat = 0;
  etata =0;
  etatb = 0;
  AdvStringGrid1->Clear();
  AdvStringGrid1->Visible = false;
direct = ExtractFileDir(ParamStr(0));
}
//---------------------------------------------------------------------------





void __fastcall TTri::Button3Click(TObject *Sender)
{
  AnsiString ae = eMemoire->Text;
 AnsiString cc=direct+"\\Ref2\\"+ae+".txt";

  if(ae=="")
  {
   ShowMessage("Veuillez entrer un nom pour le filtre");
   return;
  }

 for(int i =0; i< AdvStringGrid1->RowCount; i++)
 {
  AdvStringGrid2->Cells[0][i] = AdvStringGrid1->Cells[1][i];
  AdvStringGrid2->Cells[1][i] = AdvStringGrid1->Cells[3][i];
  AdvStringGrid2->Cells[2][i] = AdvStringGrid1->Cells[4][i];
  AdvStringGrid2->Cells[3][i] = AdvStringGrid1->Cells[5][i];
  AdvStringGrid2->Cells[4][i] = AdvStringGrid1->Cells[6][i];
  AdvStringGrid2->Cells[5][i] = AdvStringGrid1->Cells[8][i];
  AdvStringGrid2->Cells[6][i] = AdvStringGrid1->Cells[10][i];
  AdvStringGrid2->Cells[7][i] = AdvStringGrid1->Cells[11][i];
  AdvStringGrid2->Cells[8][i] = AdvStringGrid1->Cells[12][i];
  AdvStringGrid2->Cells[9][i] = AdvStringGrid1->Cells[13][i];
 }

 AdvStringGrid2->SaveToFile(cc);
 if(lbTri->Items->IndexOf(ae) > -1)
 {
     etat =0;

 }else{
 etat=1;

 }

 // Ghost->Glob_Tri(P_TRI[pc]);
 if(etat==0){
  TStringList *list= new TStringList;

  for (int rowint=0;rowint<AdvStringGrid1->RowCount;rowint++)
  {
    for (int colint=1;colint<AdvStringGrid1->ColCount;colint++)
    {
        if(colint == 2|| colint ==7|| colint == 9){}else{
       list->Add(AdvStringGrid1->Cells[rowint][colint]); }
    }
  }


 list->SaveToFile(eMemoire->Text);
 delete list;

AnsiString  nomTri = eMemoire->Text;
AnsiString nomFile = direct+"\\Ref\\";
 AdvStringGrid1->SaveToFile(nomFile+nomTri);}else{
  nomTri = eMemoire->Text;
 nomFile = direct+"\\Ref\\";
  asFC->SaveToFile(nomFile+nomTri);



 }
  SaveData(1);
  RELOADTRI[pc]=true;

}
//---------------------------------------------------------------------------

