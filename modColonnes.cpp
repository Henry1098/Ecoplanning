//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modColonnes.h"
#include "globals.h"
#include "modChCol.h"
#include "modJust.h"
#include "modHelp.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TColonnes *Colonnes;
//---------------------------------------------------------------------------
__fastcall TColonnes::TColonnes(TComponent* Owner)
        : TForm(Owner)
{
}


void __fastcall TColonnes::FillColor(int color,TImage *im)
{
 TRect Diagram;  TColor coul;

 coul=TColor(color);
 Diagram = Rect(0,0, im->Width,im->Height);
 im->Canvas->Brush->Color = coul; // BgColor;
 im->Canvas->FillRect(Diagram);
 im->Canvas->Pen->Color = clBlack;
 im->Canvas->MoveTo(0,0);
 im->Canvas->LineTo(0,im->Height-1);
 im->Canvas->LineTo(im->Width-1,im->Height-1);
 im->Canvas->LineTo(im->Width-1,0);
 im->Canvas->LineTo(0,0);

}


int __fastcall TColonnes::SaveData()
{
 //
 char name[100];
 char Key[100],RetKey[100];
 int rc,recdata,i,nbitems;
 char tmp[5000];
 FILE *fp;
 int count;
 AnsiString xx;

 strcpy(Key,eMemoire->Text.c_str());
 if (strlen(Key) == 0)
   {
    Application->MessageBoxA("Colonnes Non Sélectionnées : Pas de Nom Indiqué",m_ecoplan,MB_OK);
    return 0;
   }

 strcpy(tmp,m_directory); strcat(tmp,"\\Reference\\Colonnes\\"); strcat(tmp,Key);
strcat(tmp,".col");
fp = fopen(tmp,"wt");

 // preparer buffer
 strcpy(buffer,"<l>"); strcat(buffer,Key); strcat(buffer,"</l>");
 strcat(buffer,"<des>");
 strcat(buffer,mCol->Lines->GetText());
 strcat(buffer,"</des>");
 strcat(buffer,"<champs>");
 nbitems=asFCC->RowCount-1;  // lbDetail->Items->Count;

 xx = asFCC->Cells[4][i];
 if (xx != "Italique" && xx!= "Standard") asFCC->Cells[4][i]="Standard";
 xx = asFCC->Cells[5][i];
 if (xx != "Gras" && xx!= "Standard") asFCC->Cells[5][i]="Standard";




 for (i=2;i<=nbitems+1;i++)  // i=2 :: on ne sauve pas la rangée 1 !!
   {

     xx = asFCC->Cells[4][i];
     if (xx != "Italique" && xx!= "Standard") asFCC->Cells[4][i]="Standard";
     xx = asFCC->Cells[5][i];
     if (xx != "Gras" && xx!= "Standard") asFCC->Cells[5][i]="Standard";
     xx = asFCC->Cells[8][i];
     if (xx != "Gauche" && xx!= "Droite" && xx!= "Centre") asFCC->Cells[8][i]="Centre";

     xx = asFD->Cells[4][i];
     if (xx != "Italique" && xx!= "Standard") asFD->Cells[4][i]="Standard";
     xx = asFD->Cells[5][i];
     if (xx != "Gras" && xx!= "Standard") asFD->Cells[5][i]="Standard";
     xx = asFD->Cells[8][i];
     if (xx != "Gauche" && xx!= "Droite" && xx!= "Centre") asFD->Cells[8][i]="Centre";


     strcpy(tmp,"<ch>"); strcat(tmp,asFCC->Cells[1][i].c_str()); strcat(tmp,"</ch>");
     strcat(tmp,"<ft>"); strcat(tmp,asFCC->Cells[2][i].c_str()); strcat(tmp,"</ft>");
     strcat(tmp,"<cl>"); strcat(tmp,asFCC->Cells[3][i].c_str()); strcat(tmp,"</cl>");
     strcat(tmp,"<it>"); strcat(tmp,asFCC->Cells[4][i].c_str()); strcat(tmp,"</it>");
     strcat(tmp,"<gr>"); strcat(tmp,asFCC->Cells[5][i].c_str()); strcat(tmp,"</gr>");
     strcat(tmp,"<ta>"); strcat(tmp,asFCC->Cells[6][i].c_str()); strcat(tmp,"</ta>");
     strcat(tmp,"<cf>"); strcat(tmp,asFCC->Cells[7][i].c_str()); strcat(tmp,"</cf>");
     strcat(tmp,"<jh>"); strcat(tmp,asFCC->Cells[8][i].c_str()); strcat(tmp,"</jh>");
     strcat(tmp,"<jv>"); strcat(tmp,asFCC->Cells[9][i].c_str()); strcat(tmp,"</jv>");
     strcat(tmp,"<ht>"); strcat(tmp,asFCC->Cells[10][i].c_str()); strcat(tmp,"</ht>");

     strcat(tmp,"<tch>"); strcat(tmp,asFD->Cells[1][i].c_str()); strcat(tmp,"</tch>");
     strcat(tmp,"<tft>"); strcat(tmp,asFD->Cells[2][i].c_str()); strcat(tmp,"</tft>");
     strcat(tmp,"<tcl>"); strcat(tmp,asFD->Cells[3][i].c_str()); strcat(tmp,"</tcl>");
     strcat(tmp,"<tit>"); strcat(tmp,asFD->Cells[4][i].c_str()); strcat(tmp,"</tit>");
     strcat(tmp,"<tgr>"); strcat(tmp,asFD->Cells[5][i].c_str()); strcat(tmp,"</tgr>");
     strcat(tmp,"<tta>"); strcat(tmp,asFD->Cells[6][i].c_str()); strcat(tmp,"</tta>");
     strcat(tmp,"<tcf>"); strcat(tmp,asFD->Cells[7][i].c_str()); strcat(tmp,"</tcf>");
     strcat(tmp,"<tjh>"); strcat(tmp,asFD->Cells[8][i].c_str()); strcat(tmp,"</tjh>");
     strcat(tmp,"<tjv>"); strcat(tmp,asFD->Cells[9][i].c_str()); strcat(tmp,"</tjv>");
     strcat(tmp,"<tht>"); strcat(tmp,asFD->Cells[10][i].c_str()); strcat(tmp,"</tht>");
     ///////////////////////////////////
     //  les 3 descriptions  Titre Ligne, Col et Detail
    strcat(buffer,tmp); strcat(buffer,"|");   // | as separator
   }
 strcat(buffer,"</champs>");
 strcpy(tmp,m_directory);   //DatabaseName);
 strcat(tmp,"\\eco_col");
 rc = col->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
 rc = col->SetIndexMode(0,0);

 rc = col->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = col->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=col->GetNewRecordNumber();
       rc = col->WriteKey(0,Key,recdata);
       rc = col->WriteRecord(buffer,strlen(buffer)+1);
       lbCol->Items->Add(AnsiString(Key));
     }
Save_Preseance();
change = false;

 col->CloseEngine();

strcat(buffer,"\n");
fputs(buffer,fp);
fclose(fp);

Application->MessageBoxA("Sauvegarde Effectuée",m_ecoplan,MB_OK);
P_COL[pc] = 8 + asFCC->RowCount-2;
return 0;
}


//---------------------------------------------------------------------------
void __fastcall TColonnes::Button4Click(TObject *Sender)
{
 char Key[100];
strcpy(Key,eMemoire->Text.c_str());
 if (strlen(Key) == 0)
   {
    Application->MessageBoxA("Aucun groupe de Colonnes Sélectionné",m_ecoplan,MB_OK);
    return;
   }
strcpy(m_assign,"<col>"); strcat(m_assign,eMemoire->Text.c_str());
strcat(m_assign,"</col>");
strcat(m_assign,"<org>ModColonnes:AffPl</org>");
strcpy(P_COLONNES[pc],eMemoire->Text.c_str());
strcpy(m_exchange,m_assign);
// Assigner les colonnes dans variables globales;
Assign_Globals();
Close();

}
//---------------------------------------------------------------------------

void __fastcall TColonnes::Assign_Globals()
{
 int i,j,cnt;
 char tmp[500];

 //P_COL[pc]=0;
 cnt = asFD->RowCount;
 if (cnt==2 && asFCC->Cells[1][2]=="") return;

 // les 8 premieres reservées pour les Titre en Lignes
 for (i=8;i<MAX_COL;i++) {P_ATTR[pc][i]='Z';  }   // rien

 P_COL[pc]=8;
  for (i=2;i<cnt;i++)   //    2 a cause de DEFAUT !!!
  {
   j=i+6;   // PAS 7 !!
   P_ATTR[pc][j]='C';
   P_FIELD[pc][j]=asFCC->Cells[1][i];
   P_FONT[pc][j]= asFCC->Cells[2][i];  // Nom de la fonte  dans la colonne
   strcpy(tmp,asFCC->Cells[6][i].c_str()); P_HAUT[pc][j]=atoi(tmp);   // Hauteur du texte dans la colonne
   strcpy(tmp,asFCC->Cells[10][i].c_str()); P_LARG[pc][j]=atoi(tmp);   // Largeur du Texte
   strcpy(tmp,asFCC->Cells[3][i].c_str()); P_CFCOLOR[pc][j]=atoi(tmp);
   strcpy(tmp,asFCC->Cells[7][i].c_str()); P_CBCOLOR[pc][j]=atoi(tmp);
   strcpy(tmp,asFCC->Cells[4][i].c_str()); P_ITAL[pc][j]=AnsiString(tmp); //[0]; if (tmp[0]==0x00) P_ITAL[pc][j]='N';
   strcpy(tmp,asFCC->Cells[5][i].c_str()); P_BOLD[pc][j]=AnsiString(tmp); //[0]; if (tmp[0]==0x00) P_BOLD[pc][j]='N';
   strcpy(tmp,asFCC->Cells[9][i].c_str()); P_JV[pc][j]=AnsiString(tmp);  //[0]; if (tmp[0]==0x00) P_JV[pc][j]='H';
   strcpy(tmp,asFCC->Cells[8][i].c_str()); P_JH[pc][j]=AnsiString(tmp); //tmp[0]; if (tmp[0]==0x00) P_JC[pc][j]='C';

   T_TITRE_COL[pc][j]=asFD->Cells[1][i];
   T_FONT[pc][j]= asFD->Cells[2][i];  // Nom de la fonte  dans la colonne
   strcpy(tmp,asFD->Cells[6][i].c_str()); T_HAUT[pc][j]=atoi(tmp);   // Hauteur du texte dans la colonne
   strcpy(tmp,asFD->Cells[10][i].c_str()); T_LARG[pc][j]=atoi(tmp);   // Largeur du Texte
   strcpy(tmp,asFD->Cells[3][i].c_str()); T_CFCOLOR[pc][j]=atoi(tmp);
   strcpy(tmp,asFD->Cells[7][i].c_str()); T_CBCOLOR[pc][j]=atoi(tmp);
   strcpy(tmp,asFD->Cells[4][i].c_str()); T_ITAL[pc][j]= AnsiString(tmp); //tmp[0]; if (tmp[0]==0x00) T_ITAL[pc][j]='N';
   strcpy(tmp,asFD->Cells[5][i].c_str()); T_BOLD[pc][j]=AnsiString(tmp); //tmp[0]; if (tmp[0]==0x00) T_BOLD[pc][j]='N';
   strcpy(tmp,asFD->Cells[9][i].c_str()); T_JV[pc][j]=AnsiString(tmp); //tmp[0]; if (tmp[0]==0x00) T_JV[pc][j]='C';
   strcpy(tmp,asFD->Cells[8][i].c_str()); T_JH[pc][j]=AnsiString(tmp); //tmp[0]; if (tmp[0]==0x00) T_JC[pc][j]='C';
   P_COL[pc]++;
  }
 P_COL[pc] = 8 + asFCC->RowCount-2; 
}




void __fastcall TColonnes::btNewClick(TObject *Sender)
{
 if (change)
   {
    if (Application->MessageBoxA("Voulez Vous Sauvegarder les Données en Cours ?",
        m_ecoplan,MB_YESNO)==IDYES) return;
   }

 Clean(asFCC,3);
 Clean(asFD,3);
 Init_Titre(); Init_Champ();
 mCol->Clear();
 eMemoire->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::FormCreate(TObject *Sender)
{
 //

}

void __fastcall TColonnes::Modify()
{
 if (strcmp(mode,"utiliser")==0)
  {
   Button4->Enabled=true;
   Button5->Enabled=true;
   Button6->Enabled=true; //false;
   btNew->Enabled=true; //false;
   btLigne->Enabled=true; //false;
   btMod->Enabled=true; //false;
   btEffacer->Enabled=true; //false;
   btCreer->Caption="Creer/Compléter/Supprimer";

  }
 else
  {
   Button4->Enabled=true; //false;
   Button5->Enabled=true; //false;
   Button6->Enabled=true;
   btNew->Enabled=true;
   btLigne->Enabled=true;
   btMod->Enabled=true;
   btEffacer->Enabled=true;
   btCreer->Caption="Utiliser";

  }
}



void __fastcall TColonnes::Init_Titre()
{
 TColor cl;   int i;

 for (i=1;i<11;i++) asFD->Colors[i][1]=RGB(153,255,153);

 asFD->Cells[1][1]= "Défaut";
 asFD->Cells[2][1]= "Arial";
 cl=0;
 asFD->Cells[3][1]= AnsiString(cl);
 asFD->Cells[4][1]= "Standard";
 asFD->Cells[5][1]= "Standard";
 asFD->Cells[6][1]= 24;
 cl=clWhite;
 asFD->Cells[7][1]= AnsiString (cl);
 asFD->Cells[8][1]= "Centre";
 asFD->Cells[9][1]= "Centre";
 asFD->Cells[10][1]= 120;


}
void __fastcall TColonnes::Init_Champ()
{
 TColor cl;   int i;

 for (i=1;i<11;i++) asFCC->Colors[i][1]=RGB(153,255,153);

 asFCC->Cells[1][1]= "Défaut";

 asFCC->Cells[2][1]= "Arial";
 cl=0;
 asFCC->Cells[3][1]= AnsiString(cl);
 asFCC->Cells[4][1]= "Standard";
 asFCC->Cells[5][1]= "Standard";
 asFCC->Cells[6][1]= 24;
 cl=clWhite;
 asFCC->Cells[7][1]= AnsiString (cl);
 asFCC->Cells[8][1]= "Centre";
 asFCC->Cells[9][1]= "Centre";
 asFCC->Cells[10][1]= 120;

}

//---------------------------------------------------------------------------

void __fastcall TColonnes::Strip(char *s)
{
 char tmp[5000]; char abbrv[300]; char *p;
 int Row;   int count; int colcnt;
 int rr,rs;

 Ghost->ExtractValue(tmp,s,"champs",0);
 Clean(asFCC,3);
 Clean(asFD,3);
 Init_Titre(); Init_Champ();
 count = Explode('|',s);
 if (count)
   {
    for (Row=2; Row<=count+1; Row++)
      {
       Ghost->ExtractValue(tmp,params[Row-2],"ch",0);
       if (strlen(tmp))
         {

          if (Row>2) { asFCC->RowCount++; asFD->RowCount++; }
          rr=Row;   rs=Row-2;

          asFCC->Cells[0][rr]=IntToStr(rr-1);
          asFD->Cells[0][rr]=IntToStr(rr-1);

          Ghost->ExtractValue(tmp,params[rs],"ch",0);
          asFCC->Cells[1][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"ft",0);
          asFCC->Cells[2][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"cl",0);
          asFCC->Cells[3][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"it",0);
          asFCC->Cells[4][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"gr",0);
          asFCC->Cells[5][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"ta",0);
          asFCC->Cells[6][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"cf",0);
          asFCC->Cells[7][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"jh",0);
          asFCC->Cells[8][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"jv",0);
          asFCC->Cells[9][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"ht",0);
          asFCC->Cells[10][rr]=AnsiString(tmp);

          Ghost->ExtractValue(tmp,params[rs],"tch",0);
          p=strstr(tmp,"_");
          if (p) strcpy(abbrv,p+1);
          else strcpy(abbrv,tmp);

          asFD->Cells[1][rr]=AnsiString(abbrv);
          Ghost->ExtractValue(tmp,params[rs],"tft",0);
          asFD->Cells[2][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tcl",0);
          asFD->Cells[3][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tit",0);
          asFD->Cells[4][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tgr",0);
          asFD->Cells[5][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tta",0);
          asFD->Cells[6][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tcf",0);
          asFD->Cells[7][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tjh",0);
          asFD->Cells[8][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tjv",0);
          asFD->Cells[9][rr]=AnsiString(tmp);
          Ghost->ExtractValue(tmp,params[rs],"tht",0);
          asFD->Cells[10][rr]=AnsiString(tmp);
         }
      }
   }
}


void __fastcall TColonnes::CStrip(char *s)
{
 char tmp[2500];
 int Row;   int count; int ins;


 Ghost->ExtractValue(tmp,s,"des",0);
 mCol->SetTextBuf(tmp);

 Ghost->ExtractValue(tmp,s,"champs",0);
 Clean(asFCC,3);
 Clean(asFD,3);
 Init_Titre(); Init_Champ();
 count = Explode('|',tmp);
 if (count)
   {
    for (Row=2; Row<=count+1; Row++)
      {

       if (Row>2) asFCC->RowCount++;
       asFCC->Cells[0][Row]=IntToStr(Row-1);
       asFCC->Cells[1][Row]=AnsiString(params[Row-2]);
       Defaut_Champs(Row);
       if (Row>2) asFD->RowCount++;
       asFD->Cells[0][Row]=IntToStr(Row-1);
       Defaut_Titres(Row);
      }
   }
 P_COL[pc]=8+count;
}

void __fastcall TColonnes::Defaut_Champs(int Row)
{
 int i; AnsiString TMP;
 for (i=2;i<=10;i++)
  {
   TMP = asFCC->Cells[i][1];
   asFCC->Cells[i][Row] = TMP;
  }
}

void __fastcall TColonnes::Defaut_Titres(int Row)
{
int i;
 for (i=2;i<=10;i++)
  {
   asFD->Cells[i][Row] = asFD->Cells[i][1];
  }
 if (asFD->Cells[1][Row] == "") asFD->Cells[1][Row] = asFCC->Cells[1][Row];
}

void __fastcall TColonnes::Clean(TAdvStringGrid *adv,int n)
{
 int row,col,nrow,ncol;
 nrow=adv->RowCount;
 ncol=adv->ColCount;

 for (row=1;row<nrow;row++)
   {
    for (col=1;col<ncol;col++) adv->Cells[col][row]="";
   }
 adv->RowCount=3;
}


int __fastcall TColonnes::Explode(char sep,char *str)
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



void __fastcall TColonnes::FormClose(TObject *Sender, TCloseAction &Action)
{
// if (col) col->CloseEngine();
Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::Button2Click(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::asFCCContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
int X,Y; char tmp[500],temp[120];int lg;

 TFont *Fonte;
  int Color;
  AnsiString Name;
  int Size;
  char bold[50],italic[50];
  TFontStyles  Style;
   TJust *Just;


 X = MousePos.x;
 Y = MousePos.y;
 asFCC->MouseToCell(X, Y, OldCol, OldRow);


 X=350; Y=300;


 if ((OldRow<1) || ((OldRow > asFCC->RowCount-1))) return;

 // conversion en ligne et colonne courantes


 if (OldCol>1 && OldCol<7)
   {
     FontDialog1->Options;
     FontDialog1->Font->Name = asFCC->Cells[2][OldRow];
     FontDialog1->Font->Color = StrToInt(asFCC->Cells[3][OldRow]);
     FontDialog1->Font->Size = StrToInt(asFCC->Cells[6][OldRow]);

     if (asFCC->Cells[5][OldRow]=="Gras" && asFCC->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (asFCC->Cells[5][OldRow]=="Gras" && asFCC->Cells[4][OldRow]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (asFCC->Cells[5][OldRow]!="Gras" && asFCC->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles() << fsItalic;


       strcpy(m_exchange,"");
     if (FontDialog1->Execute())
      { Fonte = FontDialog1->Font;
        Color = Fonte->Color;
        Size = Fonte->Size;
         Name = Fonte->Name;
        Style = Fonte->Style;
      // recherche si bold et italique
      if (Style.Contains(fsBold))
         strcpy(bold,"Gras");
         else strcpy(bold,"Standard");
      if (Style.Contains(fsItalic))
         strcpy(italic,"Italique"); else
         strcpy(italic,"Standard");

      asFCC->Cells[2][OldRow]=Name;
      asFCC->Cells[3][OldRow]=AnsiString(Color);
      asFCC->Cells[4][OldRow]=AnsiString(italic);
      asFCC->Cells[5][OldRow]=AnsiString(bold);
      asFCC->Cells[6][OldRow]=AnsiString(Size);
      }
   }
 if (OldCol==7)
   {
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      asFCC->Cells[7][OldRow]=AnsiString(Color);
    }
   }

 if (OldCol==8)
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,asFCC->Cells[8][OldRow].c_str());
    strcat(m_exchange,"</jh>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        Ghost->ExtractValue(tmp,m_exchange,"jh",0);
        asFCC->Cells[8][OldRow]=AnsiString(tmp);
      }
    delete Just;
   }


  if (OldCol==9)
   {
     strcpy(m_exchange,"<jv>"); strcat(m_exchange,asFCC->Cells[9][OldRow].c_str());
    strcat(m_exchange,"</jv>");
    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        Ghost->ExtractValue(tmp,m_exchange,"jv",0);
        asFCC->Cells[9][OldRow]=AnsiString(tmp);
      }
    delete Just;
   }
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled = false;
 if (strcmp(m_sender,"modtri")==0)
  {
   if (strlen(m_reports)) ;
       //Exec_Reports();
  }
 Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TColonnes::Save_Preseance()
{
FILE *fp;
int i,count;  char tmp[250];
strcpy(filename,m_directory);  // DatabaseName);
strcat(filename,"\\eco_col.txt");
count=lbCol->Items->Count;
fp = fopen(filename,"wt");
for (i=0;i<count;i++)
  {
   sprintf(tmp,"<l>%s</l>\n",lbCol->Items->Strings[i].c_str());
   fputs(tmp,fp);
  }
fclose(fp);
}


void __fastcall TColonnes::lbColClick(TObject *Sender)
{
int indx; char tmp[5000];  AnsiString Content;
 int rc,recdata;
 //char Key[100],RetKey[100];

 Clean(asFCC,3);
 Clean(asFD,3);
 OldRow=0; OldCol=0;


 // Clean(asFCC,2);
 // Clean(asFD,2);
 Init_Titre(); Init_Champ();

 indx = lbCol->ItemIndex;
 if (indx == -1) return;

 strcpy(tmp,lbCol->Items->Strings[indx].c_str());

 Content = lbCol->Items->Strings[indx];
 lbCol->Items->Delete(indx);
 lbCol->Items->Insert(0,Content);


 Display_Col(tmp);
 Assign_Globals();
 //lTri->Caption=AnsiString(tmp);

}
//---------------------------------------------------------------------------

void __fastcall TColonnes::BitBtn3Click(TObject *Sender)
{
 int XRow,i;
 int count,colcnt,indx;
 AnsiString L[20];
 AnsiString M[20];

 //indx=OldRow;
 count=asFCC->RowCount-1;
 if(OldRow < 3) return;
 colcnt=asFCC->ColCount;
 for (indx=1;indx<colcnt;indx++) { L[indx]=asFCC->Cells[indx][OldRow];  M[indx]=asFD->Cells[indx][OldRow];   }

 XRow=OldRow-1;
  for (indx=1;indx<colcnt;indx++)
   {
    asFCC->Cells[indx][OldRow]=asFCC->Cells[indx][XRow]; asFCC->Cells[indx][XRow]=L[indx];
    asFD->Cells[indx][OldRow]=asFD->Cells[indx][XRow]; asFD->Cells[indx][XRow]=M[indx];

   }
 OldRow=XRow;
}


 int __fastcall TColonnes::check_data(char *s)
 {
  int rc,recdata; char Key[100],RetKey[100];
  strcpy(Key,s);
  rc=col->ReadDirectKey(0,Key,RetKey,&recdata);
  return rc;
 }


 void __fastcall TColonnes::Display_Col(char *s)
{
 int indx; char tmp[5000];
 int rc,recdata; char Key[200],RetKey[200];

 Clean(asFCC,3);
 Clean(asFD,3);
 Init_Titre(); Init_Champ();
 eMemoire->Text=AnsiString(s);
 strcpy(current_col,s);
 // Read Data and display it

 strcpy(tmp,m_directory);  //DatabaseName);
 strcat(tmp,"\\eco_col");
 rc = col->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
 rc = col->SetIndexMode(0,0);

  strcpy(Key,current_col);
  rc=col->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
   { Application->MessageBoxA("Description Colonnes non trouvée dans la base de données",m_ecoplan,MB_OK);
    return;
   }

 rc=col->ReadRecord(buffer,recdata);
 if (rc)
   { // extract

    Ghost->ExtractValue(tmp,buffer,"l",0);
    eMemoire->SetTextBuf(tmp);
    Ghost->ExtractValue(tmp,buffer,"des",0);
    mCol->Clear();
    mCol->SetTextBuf(tmp);
    Ghost->ExtractValue(tmp,buffer,"champs",0);

    if (strlen(tmp))
        Strip(tmp);
   }
 col->CloseEngine();
}


//---------------------------------------------------------------------------

void __fastcall TColonnes::BitBtn4Click(TObject *Sender)
{
int XRow,i;
 int indx,count,colcnt;

 AnsiString L[20]; //l0,l1,l2,l3,l4,l5;
 AnsiString M[20];

 count = asFCC->RowCount-1;
 if(OldRow == count) return;
 if (OldRow < 2) return;


 colcnt=asFCC->ColCount;
 for (indx=1;indx<colcnt;indx++) { L[indx]=asFCC->Cells[indx][OldRow];  M[indx]=asFD->Cells[indx][OldRow]; }
  XRow=OldRow+1;
  if (XRow>=count) return;

 for (indx=1;indx<colcnt;indx++)
   {
    asFCC->Cells[indx][OldRow]=asFCC->Cells[indx][XRow]; asFCC->Cells[indx][XRow]=L[indx];
    asFD->Cells[indx][OldRow]=asFD->Cells[indx][XRow]; asFD->Cells[indx][XRow]=M[indx];
   }

 OldRow=XRow;

}
//---------------------------------------------------------------------------

void __fastcall TColonnes::CleanRow(int row)
{
 int i;
 for (i=0;i<asFCC->ColCount;i++) { asFCC->Cells[i][row]=""; asFD->Cells[i][row]="";  }
}

void __fastcall TColonnes::btEffacerClick(TObject *Sender)
{
 int row,col,i,j;
 if (OldRow == 0)
   {
    Application->MessageBoxA("Aucun élément sélectionné",m_ecoplan,MB_OK);
    return;
   }
 if (Application->MessageBoxA("Confirmer l'effacement",m_ecoplan,MB_YESNO)==IDNO) return;

 if (asFCC->RowCount==2)  { CleanRow(1); OldRow=0; return; }
 if (OldRow == (asFCC->RowCount-1)){CleanRow(OldRow); asFCC->RowCount--; OldRow--; return; }

 row = asFCC->RowCount;
 int cnt=asFCC->ColCount;
 for (i = OldRow; i<row;i++)
   {
    for (j=1;j<cnt;j++) { asFCC->Cells[j][i] = asFCC->Cells[j][i+1]; asFD->Cells[j][i] = asFD->Cells[j][i+1]; }
   }
//  renumeroter la colonne 0

asFCC->RowCount--;  row= asFCC->RowCount;
asFD->RowCount--;

for (i=1;i<row;i++) {  asFCC->Cells[0][i]=IntToStr(i);  asFD->Cells[0][i]=IntToStr(i); }
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::Button6Click(TObject *Sender)
{
int indx; int rc,recdata; char Key[100],RetKey[100];
char tmp[250];
indx = lbCol->ItemIndex;
indx=0;
if (lbCol->Items->Count ==0) return;
if (lbCol->Items->Strings[indx]=="")  return;


 if (indx == -1)
    {
     Application->MessageBoxA("Pas de Colonnes Sélectionnées",m_ecoplan,MB_OK);
     return;
    }
 if (Application->MessageBoxA("Confirmer l'effacement du groupe Colonnes",m_ecoplan,MB_YESNO)==IDNO)
    return;

 strcpy(Key,lbCol->Items->Strings[indx].c_str());

 strcpy(tmp,m_directory); //DatabaseName);
 strcat(tmp,"\\eco_col");
 rc = col->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
 rc = col->SetIndexMode(0,0);

 rc = col->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc)
  {
   rc=col->DeleteKey(0,Key,recdata);
   rc=col->DeleteRecord(recdata);
  }
 else { Application->MessageBoxA("Colonnes non trouvé dans le fichier",m_ecoplan,MB_OK);
        return;
      }

 col->CloseEngine();
  int r,c,xc,cc;
 cc=asFCC->ColCount; xc=asFCC->RowCount;
 for (r=0;r<xc;r++)
  {
   for (c=1;c<cc;c++) {  asFCC->Cells[c][r]="";  asFD->Cells[c][r]=""; }
  }

 asFCC->RowCount=2;
 asFD->RowCount=2;


 indx=0;
 lbCol->Items->Delete(indx);

 mCol->Clear();
 //lTri->Caption = "";
 eMemoire->Clear();
 change = true;
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::btOKClick(TObject *Sender)
{
 strcpy(m_exchange,"");
 P_COL[pc] = 8 + asFCC->RowCount-2;

 Close();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::Button1Click(TObject *Sender)
{
 SaveData();
 RELOADCOL[pc]=true;
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::asFCCClickCell(TObject *Sender, int ARow,
      int ACol)
{
  int X,Y; char tmp[500],temp[120];int lg;

 TFont *Fonte;
  int Color,cool;
  AnsiString Name;
  int Size;
  char bold[50],italic[50];
  TFontStyles  Style;
   TJust *Just;
   TChCol *ChCol;



 if (ARow==0) return;
 OldRow = ARow;
 OldCol = ACol;



 if ((OldRow<1) || ((OldRow > asFCC->RowCount-1))) return;

 // conversion en ligne et colonne courantes

 if (OldCol==0)
  {
    strcpy(tmp,asFCC->Cells[7][OldRow].c_str());
    cool=atoi(tmp);
    FillColor(cool,imBColor);
    strcpy(tmp,asFCC->Cells[3][OldRow].c_str());
    cool=atoi(tmp);
    FillColor(cool,imFColor);
  }

 if (OldCol==1)
 {


 strcpy(m_exchange,"");   // m_exchange est vide, pour un nouveau

 ChCol= new TChCol(Application);
 ChCol->ShowModal();
 delete ChCol;

 if (strlen(m_exchange)==0) return;
 CStrip(m_exchange);
 Adjust_Titre();

 }

 if (OldCol>1 && OldCol<7)
   {
          FontDialog1->Options;
     FontDialog1->Font->Name = asFCC->Cells[2][OldRow];
     FontDialog1->Font->Color = StrToInt(asFCC->Cells[3][OldRow]);
     FontDialog1->Font->Size = StrToInt(asFCC->Cells[6][OldRow]);

     if (asFCC->Cells[5][OldRow]=="Gras" && asFCC->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (asFCC->Cells[5][OldRow]=="Gras" && asFCC->Cells[4][OldRow]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (asFCC->Cells[5][OldRow]!="Gras" && asFCC->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles() << fsItalic;

     strcpy(m_exchange,"");
     if (FontDialog1->Execute())
      { Fonte = FontDialog1->Font;
      Color = Fonte->Color;
      Size = Fonte->Size;
      Name = Fonte->Name;
      Style = Fonte->Style;
      // recherche si bold et italique
      if (Style.Contains(fsBold))  strcpy(bold,"Gras"); else strcpy(bold,"Standard");
      if (Style.Contains(fsItalic))  strcpy(italic,"Italique"); else strcpy(italic,"Standard");

      asFCC->Cells[2][OldRow]=Name;
      asFCC->Cells[3][OldRow]=AnsiString(Color);
      asFCC->Cells[4][OldRow]=AnsiString(italic);
      asFCC->Cells[5][OldRow]=AnsiString(bold);
      asFCC->Cells[6][OldRow]=AnsiString(Size);
      strcpy(tmp,asFCC->Cells[3][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imFColor);

      }
   }
 if (OldCol==7)
   {
    strcpy(tmp,asFCC->Cells[7][OldRow].c_str());
    cool=atoi(tmp);
    ColorDialog1->Color=cool;
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      asFCC->Cells[7][OldRow]=AnsiString(Color);
      strcpy(tmp,asFCC->Cells[7][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imBColor);
    }
   }

 if ((OldCol==8) || (OldCol==9))
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,asFCC->Cells[8][OldRow].c_str());
    strcat(m_exchange,"</jh>");
    //strcat(m_exchange,"<jv>"); strcat(m_exchange,asFCC->Cells[9][OldRow].c_str());
    //strcat(m_exchange,"</jv>");
    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        Ghost->ExtractValue(tmp,m_exchange,"jh",0);
        asFCC->Cells[8][OldRow]=AnsiString(tmp);
        //Ghost->ExtractValue(tmp,m_exchange,"jv",0);
        asFCC->Cells[9][OldRow]= ""; //AnsiString(tmp);
      }

    delete Just;
   }

  if (OldCol==10)
   {
   asFD->Cells[10][OldRow] = asFCC->Cells[10][OldRow];
   }
 Assign_Globals();
}
//---------------------------------------------------------------------------

void _fastcall TColonnes::Adjust_Titre()
{
 FILE *ch;
 


}


void __fastcall TColonnes::btLigneClick(TObject *Sender)
{
TChCol *ChCol;
int cnt; int i,j,colcnt;

 strcpy(m_exchange,"");   // m_exchange est vide, pour un nouveau

 ChCol= new TChCol(Application);
 ChCol->ShowModal();
 delete ChCol;

 if (strlen(m_exchange)==0) return;

 CStrip(m_exchange);


 cnt= asFCC->RowCount;
 colcnt=asFCC->ColCount;

 for (i=2;i<=cnt;i++)
   {
    for (j=2;j<colcnt;j++)
     {
      asFCC->Cells[j][i]=asFCC->Cells[j][1];
      asFD->Cells[j][i]=asFD->Cells[j][1];
     }
   }


 //Adjust_Titre();
}
//---------------------------------------------------------------------------


void __fastcall TColonnes::btModClick(TObject *Sender)
{
TChCol *ChCol;
int n,i; char tmp[2500];
// remplir m_exchange avec les anciennes données

n=asFCC->RowCount;

strcpy(m_exchange,"<champs>");

for (i=2;i<n;i++)     // ne pas copier Defaut
  {
   strcpy(tmp,asFCC->Cells[1][i].c_str());
   if (strlen(tmp))
     {
      strcat(m_exchange,tmp);
      strcat(m_exchange,"|");
     }
  }

strcat(m_exchange,"</champs>");

 ChCol= new TChCol(Application);
 ChCol->ShowModal();
 delete ChCol;

 if (strlen(m_exchange)==0) return;

 CStrip(m_exchange);
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::BitBtn1Click(TObject *Sender)
{
// Up Move
  int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbCol->ItemIndex;
 if (indx == -1) return;
 count = lbCol->Items->Count;
 if (indx == 0) { lbCol->Items->Move(indx,count-1); lbCol->ItemIndex=count-1; }
 else { lbCol->Items->Move(indx,indx-1);  lbCol->ItemIndex=indx-1; }
 Save_Preseance();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::BitBtn2Click(TObject *Sender)
{
 // Down Move
 int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbCol->ItemIndex;
 if (indx == -1) return;
 count = lbCol->Items->Count;
 if (indx == count-1) { lbCol->Items->Move(indx,0); lbCol->ItemIndex=0; }

 else { lbCol->Items->Move(indx,indx+1); lbCol->ItemIndex=indx + 1; }
Save_Preseance();
}
//---------------------------------------------------------------------------




void __fastcall TColonnes::asFDClickCell(TObject *Sender, int ARow,
      int ACol)
{
   int X,Y; char tmp[500],temp[120];int lg;

 TFont *Fonte;
  int Color,cool;
  AnsiString Name;
  int Size;
  char bold[50],italic[50];
  TFontStyles  Style;
   TJust *Just;



 if (ARow==0) return;
 OldRow = ARow;
 OldCol = ACol;



 if ((OldRow<1) || ((OldRow > asFCC->RowCount-1))) return;

 // conversion en ligne et colonne courantes

 if (OldCol==0)
  {
    strcpy(tmp,asFD->Cells[7][OldRow].c_str());
    cool=atoi(tmp);
    FillColor(cool,imBColor);
    strcpy(tmp,asFD->Cells[3][OldRow].c_str());
    cool=atoi(tmp);
    FillColor(cool,imFColor);
  }


 if (OldCol>1 && OldCol<7)
   {
     FontDialog1->Options;
     FontDialog1->Font->Name = asFD->Cells[2][OldRow];
     FontDialog1->Font->Color = StrToInt(asFD->Cells[3][OldRow]);
     FontDialog1->Font->Size = StrToInt(asFD->Cells[6][OldRow]);

     if (asFD->Cells[5][OldRow]=="Gras" && asFD->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (asFD->Cells[5][OldRow]=="Gras" && asFD->Cells[4][OldRow]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (asFD->Cells[5][OldRow]!="Gras" && asFD->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles() << fsItalic;

     strcpy(m_exchange,"");
     if (FontDialog1->Execute())
      { Fonte = FontDialog1->Font;
      Color = Fonte->Color;
      Size = Fonte->Size;
      Name = Fonte->Name;
      Style = Fonte->Style;
      // recherche si bold et italique

      if (Style.Contains(fsBold))  strcpy(bold,"Gras"); else strcpy(bold,"Standard");
      if (Style.Contains(fsItalic))  strcpy(italic,"Italique"); else strcpy(italic,"Standard");


      asFD->Cells[2][OldRow]=Name;
      asFD->Cells[3][OldRow]=AnsiString(Color);
      asFD->Cells[4][OldRow]=AnsiString(italic);
      asFD->Cells[5][OldRow]=AnsiString(bold);
      asFD->Cells[6][OldRow]=AnsiString(Size);

      strcpy(tmp,asFD->Cells[3][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imFColor);

      }
   }
 if (OldCol==7)
   {
    strcpy(tmp,asFD->Cells[7][OldRow].c_str());
     cool=atoi(tmp);
     ColorDialog1->Color=cool;
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      asFD->Cells[7][OldRow]=AnsiString(Color);
      strcpy(tmp,asFD->Cells[7][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imBColor);
    }
   }

 if ((OldCol==8) || (OldCol==9))
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,asFD->Cells[8][OldRow].c_str());
    strcat(m_exchange,"</jh>");
    //strcat(m_exchange,"<jv>"); strcat(m_exchange,asFD->Cells[9][OldRow].c_str());
    //strcat(m_exchange,"</jv>");
    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        Ghost->ExtractValue(tmp,m_exchange,"jh",0);
        asFD->Cells[8][OldRow]=AnsiString(tmp);
        //Ghost->ExtractValue(tmp,m_exchange,"jv",0);
        asFD->Cells[9][OldRow]= "";  // AnsiString(tmp);
      }
    delete Just;
   }

 if (OldCol==10)
   {
    asFCC->Cells[10][OldRow] = asFD->Cells[10][OldRow];

   }
 Assign_Globals();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::btDefautClick(TObject *Sender)
{
 int cnt; int i,j,colcnt;
 cnt= asFCC->RowCount;
 colcnt=asFCC->ColCount;

 for (i=2;i<=cnt;i++)
   {
    for (j=2;j<colcnt-1;j++)
     {
      asFCC->Cells[j][i]=asFCC->Cells[j][1];
      asFD->Cells[j][i]=asFD->Cells[j][1];
     }
   }



}
//---------------------------------------------------------------------------



void __fastcall TColonnes::Button5Click(TObject *Sender)
{
 char Key[100];
strcpy(Key,eMemoire->Text.c_str());
 if (strlen(Key) == 0)
   {
    Application->MessageBoxA("Aucun groupe de Colonnes Sélectionné",m_ecoplan,MB_OK);
    return;
   }
strcpy(m_assign,"<col>"); strcat(m_assign,eMemoire->Text.c_str());
strcat(m_assign,"</col>");
strcat(m_assign,"<org>ModColonnes:AffecterRapp</org>");
strcpy(P_COLONNES[pc],eMemoire->Text.c_str());
strcpy(m_exchange,m_assign);
// Assigner les colonnes dans variables globales;

Assign_Globals();

Close();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::btCreerClick(TObject *Sender)
{
 if (strcmp(mode,"utiliser")==0)
   {
      strcpy(mode,"completer");
   }
  else strcpy(mode,"utiliser");

 Modify();
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::asFDCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
 if (ARow==0) return;
 if (ACol==10)
   {
    asFCC->Cells[10][ARow] = asFD->Cells[10][ARow];
    Assign_Globals();
   }
}
//---------------------------------------------------------------------------

void __fastcall TColonnes::asFCCCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
if (ARow==0) return;
if (ACol==10)
   {
   asFD->Cells[10][ARow] = asFCC->Cells[10][ARow];
   Assign_Globals();
   }

}
//---------------------------------------------------------------------------

void __fastcall TColonnes::FormShow(TObject *Sender)
{
 int i;
char tmp[250];
char buffer[2000];
 int rc,recdata;
 char Key[100],RetKey[100];

FILE *fp;
 Timer1->Enabled = false;

 change = false;
 strcpy(tmp,m_directory);  //DatabaseName);
 strcat(tmp,"\\eco_col.txt");
 //Label6->Caption=AnsiString(DatabaseName);
 col = new realisam;

 // asFCC->RowCount=2;
 Clean(asFCC,3);
 Clean(asFD,3);
 OldRow=0; OldCol=0;

 Init_Titre();
 Init_Champ();

 fp=fopen(tmp,"rt");
 //lbCol->Clear();
 if (fp == NULL)
   {
    change = true;
   }
 else  // lire et remplir le tableau
   {

    strcpy(tmp,m_directory);  //DatabaseName);
    strcat(tmp,"\\eco_col");
    rc = col->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
    rc = col->SetIndexMode(0,0);

    buffer[0]=0;
    fgets(buffer,512,fp);
    while (!feof(fp))
      {
       if (strlen(buffer)>5)
        {
         Ghost->ExtractValue(tmp,buffer,"l",0);
         if (check_data(tmp)) lbCol->Items->Add(AnsiString(tmp));
        }
       fgets(buffer,512,fp);
      }
     col->CloseEngine();
    fclose(fp);
    Save_Preseance();

   }


if (strcmp(m_mode,"orgplanning")!=0)
    {
     if (strlen(m_exchange))
     {
      Ghost->ExtractValue(mode,m_exchange,"util",0);
      Modify();
      Ghost->ExtractValue(tmp,m_exchange,"col",0);
      if (strlen(tmp))
        { Display_Col(tmp);
          Assign_Globals();
        }
      else Load_From_Globals();
     }
   }
    else Load_From_Globals();

asFCC->ColWidths[9]=0;
asFD->ColWidths[9]=0;

 Timer1->Enabled=true;

}

 void __fastcall TColonnes::Load_From_Globals()
{
 int i,j;

 Clean(asFCC,3);
 Clean(asFD,3);
 eMemoire->Text = AnsiString(P_COLONNES[pc]);
 Init_Titre(); Init_Champ();


 for (j=8;j<P_COL[pc];j++)
 {
//  if (P_COL[pc][j]=='C')  // uniquement Colonnes de la grille
//   {
    i=j-6;
    if (i >2) { asFCC->RowCount++; asFD->RowCount++; }
   asFCC->Cells[1][i] = P_FIELD[pc][j];
   asFCC->Cells[2][i] = P_FONT[pc][j];  // Nom de la fonte  dans la colonne
   asFCC->Cells[6][i] = AnsiString(P_HAUT[pc][j]);
   asFCC->Cells[10][i] = AnsiString(P_LARG[pc][j]);
   asFCC->Cells[3][i]  = AnsiString(P_CFCOLOR[pc][j]);
   asFCC->Cells[7][i]  = AnsiString(P_CBCOLOR[pc][j]);
   asFCC->Cells[4][i]  = AnsiString(P_ITAL[pc][j]);
   asFCC->Cells[5][i]  = AnsiString(P_BOLD[pc][j]);
   //asFCC->Cells[8][i]  = AnsiString(P_JV[pc][j]);
   asFCC->Cells[8][i]  = AnsiString(P_JH[pc][j]);


   asFD->Cells[1][i] = T_TITRE_COL[pc][j];
   asFD->Cells[2][i] = T_FONT[pc][j];  // Nom de la fonte  dans la colonne
   asFD->Cells[6][i] = AnsiString(T_HAUT[pc][j]);
   asFD->Cells[10][i] = AnsiString(T_LARG[pc][j]);
   asFD->Cells[3][i]  = AnsiString(T_CFCOLOR[pc][j]);
   asFD->Cells[7][i]  = AnsiString(T_CBCOLOR[pc][j]);
   asFD->Cells[4][i]  = AnsiString(T_ITAL[pc][j]);
   asFD->Cells[5][i]  = AnsiString(T_BOLD[pc][j]);
   //asFD->Cells[8][i]  = AnsiString(T_JV[pc][j]);
   asFD->Cells[8][i]  = AnsiString(T_JH[pc][j]);
  //}
 }


}


//---------------------------------------------------------------------------

void __fastcall TColonnes::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl5");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

