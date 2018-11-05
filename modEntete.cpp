//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modEntete.h"
#include "globals.h"
#include "modJust.h"
#include "modHelp.h"

#include <stdio.h>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TEntete *Entete;
//---------------------------------------------------------------------------
__fastcall TEntete::TEntete(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TEntete::FillData(int ind)
{
 TColor Color; int val; char tmp[250];

 PACTIF[pc][ind]='O';
 P_ORIENT[pc][ind]='L';
 PTYPE[pc][ind]='L';

 PB[pc][ind] = P_ET_BKG[pc];

 PT[pc][ind]= avl->Cells[1][ind+1];
 PF[pc][ind]= avl->Cells[2][ind+1];

 strcpy(tmp,avl->Cells[3][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"0");
 val= atoi(tmp); PC[pc][ind]=TColor(val);

/*
 strcpy(tmp,avl->Cells[7][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"0");
 val= atoi(tmp); PB[pc][ind]=TColor(val);
*/

 strcpy(tmp,avl->Cells[4][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Standard");
 if ((strcmp(tmp,"Standard")==0) || (strlen(tmp)==0))  PN[pc][ind]="Standard";
  else PN[pc][ind]="Italique";

 strcpy(tmp,avl->Cells[5][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Standard");
 if ((strcmp(tmp,"Standard")==0) || (strlen(tmp)==0))  PX[pc][ind]="Standard";
  else PX[pc][ind]="Gras";

 strcpy(tmp,avl->Cells[7][ind+1].c_str());
 PJH[pc][ind] = AnsiString(tmp);
 //if (strlen(tmp)==0) strcpy(tmp,"Centre");
 //if (strcmp(tmp,"Gauche")==0)  PJH[pc][ind]="Gauche";
 //else if (strcmp(tmp,"Centre")==0)  PJH[pc][ind]="Centre";
 // else PJH[pc][ind]="Droite";

 strcpy(tmp,avl->Cells[8][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"Centre");
 if (strcmp(tmp,"Haut")==0)  PJV[pc][ind]="Haut";
 else if (strcmp(tmp,"Centre")==0)  PJV[pc][ind]="Haut";
  else PJV[pc][ind]="Haut";

 strcpy(tmp,avl->Cells[6][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"24");
 val= atoi(tmp); PH[pc][ind]=val;

 strcpy(tmp,avl->Cells[9][ind+1].c_str());
 if (strlen(tmp)==0) strcpy(tmp,"30");
 val= atoi(tmp); PHH[pc][ind]=val;
}


//---------------------------------------------------------------------------
void __fastcall TEntete::Button1Click(TObject *Sender)
{
  char tmp[512];  int val; int i;
 // Couleur de fond
  if (Edit1->Text=="") Edit1->Text="FFFFFF";
  strcpy(tmp,Edit1->Text.c_str());
  P_ET_BKG[pc]=(TColor) atoi(tmp);

 // Remplir les 9 zones en-tete
//$$$$$ for (i=0;i<=4;i++) FillData(i);
//$$$$  for (i=6;i<=8;i++) FillData(i);

  for (i=0;i<9;i++) FillData(i);
  if (RadioButton1->Checked == true)  LOGOPOS[pc]="G";
    else LOGOPOS[pc]="D";
  LOGONAME[pc]=eLogo->Text;

Close();
}
//---------------------------------------------------------------------------

void __fastcall TEntete::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TEntete::FillColor(int color,TImage *im)
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




void __fastcall TEntete::avlClickCell(TObject *Sender, int ARow, int ACol)
{
  int X,Y; char tmp[500],temp[120];int lg;

 TFont *Fonte;
  int Color;
  AnsiString Name;
  int Size;

  char bold[50],italic[50];
  TFontStyles  Style;
   TJust *Just;

 if (ARow==0 || ARow==6) return;
// if (ARow==0) return;
 OldRow = ARow;
 OldCol = ACol;

 if ((OldRow<0) || ((OldRow > avl->RowCount-1))) return;

 int cool;
 strcpy(tmp,avl->Cells[3][OldRow].c_str());
 cool=atoi(tmp);
 FillColor(cool,imFColor);

 /*strcpy(tmp,avl->Cells[7][OldRow].c_str());
 cool=atoi(tmp);
 FillColor(cool,imBColor);
 */
 if (OldCol>1 && OldCol<7)
   {
      //FontDialog1->Options.Clear();
      FontDialog1->Font->Name =  avl->Cells[2][OldRow];
      FontDialog1->Font->Color =   StrToInt(avl->Cells[3][OldRow]);
      FontDialog1->Font->Size =   StrToInt(avl->Cells[6][OldRow]);
     if (avl->Cells[5][OldRow]=="Gras" && avl->Cells[4][OldRow]=="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold << fsItalic;
     else if (avl->Cells[5][OldRow]=="Gras" && avl->Cells[4][OldRow]!="Italique")
       FontDialog1->Font->Style = TFontStyles()<< fsBold;
     else if (avl->Cells[5][OldRow]!="Gras" && avl->Cells[4][OldRow]=="Italique")
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


      avl->Cells[2][OldRow]=Name;
      avl->Cells[3][OldRow]=AnsiString(Color);
      avl->Cells[4][OldRow]=AnsiString(italic);
      avl->Cells[5][OldRow]=AnsiString(bold);
      avl->Cells[6][OldRow]=AnsiString(Size);
       strcpy(tmp,avl->Cells[3][OldRow].c_str());
       cool=atoi(tmp);
       FillColor(cool,imFColor);

      }
   }

 /*
 if (OldCol==7)
   {
    if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      avl->Cells[7][OldRow]=AnsiString(Color);
      strcpy(tmp,avl->Cells[7][OldRow].c_str());
      cool=atoi(tmp);
      FillColor(cool,imBColor);
    }
   }
 */

 if (OldCol==7)
   {
    strcpy(m_exchange,"<jh>"); strcat(m_exchange,avl->Cells[7][OldRow].c_str());
    strcat(m_exchange,"</jh>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        ExtractValue(tmp,m_exchange,"jh",0);
        avl->Cells[7][OldRow]=AnsiString(tmp);

      }

    delete Just;
   }

 if (OldCol==8)
   {

    strcpy(m_exchange,"<jv>"); strcat(m_exchange,avl->Cells[8][OldRow].c_str());
    strcat(m_exchange,"</jv>");

    Just = new TJust(Application);
    Just->ShowModal();
    // Donnees dans m_exchange
    if (strlen(m_exchange))
      {
        ExtractValue(tmp,m_exchange,"jv",0);
        avl->Cells[8][OldRow]=AnsiString(tmp);
      }

    delete Just;
   }

}
//---------------------------------------------------------------------------

int __fastcall TEntete::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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



void __fastcall TEntete::btBackGroundClick(TObject *Sender)
{
 TColor Color; int c;
 char tmp[50];

strcpy(tmp,Edit1->Text.c_str());
c = atoi(tmp);
ColorDialog1->Color =  c;
if (ColorDialog1->Execute())
     {
      Color = ColorDialog1->Color;
      c = (int)(Color);
      Edit1->Text=AnsiString(Color);
      FillColor(c,imBColor);
    }


}
//---------------------------------------------------------------------------


void __fastcall TEntete::FillGrid(int ind)
{
 int i;
 if (ind==5)
   {
    for (i=0;i<avl->ColCount;i++) avl->Cells[i][ind+1]="";
    return;
   }

 avl->Cells[1][ind+1] = PT[pc][ind];
 avl->Cells[2][ind+1] = PF[pc][ind];
 avl->Cells[3][ind+1] = PC[pc][ind];

 if (PN[pc][ind]=="Standard") avl->Cells[4][ind+1] = "Standard";
   else  avl->Cells[4][ind+1] = "Italique";
 if (PX[pc][ind]=="Standard") avl->Cells[5][ind+1] = "Standard";
   else  avl->Cells[5][ind+1] = "Gras";
 avl->Cells[6][ind+1] = PH[pc][ind];
 //avl->Cells[7][ind+1] = PB[pc][ind];

 avl->Cells[7][ind+1] = PJH[pc][ind];
// if (PJH[pc][ind]=="Centre") avl->Cells[7][ind+1]="Centre";
// else if (PJH[pc][ind]=="Gauche") avl->Cells[7][ind+1]="Gauche";
// else avl->Cells[7][ind+1]="Droite";

 /*
 if (PJV[pc][ind]=='C') avl->Cells[8][ind+1]="Centre";
 else if (PJV[pc][ind]=='H') avl->Cells[8][ind+1]="Haut";
 else avl->Cells[8][ind+1]="Bas";
 */
 avl->Cells[9][ind+1] = PHH[pc][ind];

 Edit1->Text = AnsiString(P_ET_BKG[pc]);

}



void __fastcall TEntete::FormCreate(TObject *Sender)
{
  // remplir la grille d'apres les données dans la memoire globale

}
//---------------------------------------------------------------------------

void __fastcall TEntete::FormShow(TObject *Sender)
{
 int i,ind;
 for (ind=0;ind<9;ind++) FillGrid(ind);
 Edit1->Text=AnsiString(P_ET_BKG[pc]);
 int c=StrToInt(Edit1->Text);
 FillColor(c,imBColor);
 for (i=0;i<avl->ColCount;i++) avl->Cells[i][6]="";
 avl->ColWidths[8]=0;
 eLogo->Text = LOGONAME[pc];
 if (eLogo->Text != "")
   {
    if (FileExists(LOGONAME[pc]))
     {
       iLogo->Picture->Bitmap->LoadFromFile(eLogo->Text);
     }  
   }
 if (LOGOPOS[pc]=="D") RadioButton2->Checked = true;
  else RadioButton1->Checked = true;

}
//---------------------------------------------------------------------------


void __fastcall TEntete::avlCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 if (ARow==6) CanEdit = false;
 else CanEdit = true;
}
//---------------------------------------------------------------------------



void __fastcall TEntete::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl43");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TEntete::Button4Click(TObject *Sender)
{


OpenDialog1->FileName = "*.bmp";
OpenDialog1->InitialDir = AnsiString(DatabaseName);
    if (OpenDialog1->Execute())
     {
      eLogo->Text = OpenDialog1->FileName;
      iLogo->Picture->Bitmap->LoadFromFile(eLogo->Text);



     }
}
//---------------------------------------------------------------------------

