//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modCriteres.h"
#include "globals.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TCriteres *Criteres;
//---------------------------------------------------------------------------
__fastcall TCriteres::TCriteres(TComponent* Owner)
        : TForm(Owner)
{

}

void __fastcall TCriteres::Compte_Taches()
{
 int i,j,k,t, ctach,ccrit,countache;
 AnsiString CR,CR1,CR2,CR3,CR4;
 char XR[50],XR1[50], XR2[50],XR3[50],XR4[50],tmp[100];
 ccrit =  asDetail->RowCount;

 if (ccrit == 2 && asDetail->Cells[1][2]=="") return;

 for (i=1;i<ccrit;i++)
   {
    CR1 = asDetail->Cells[1][i]+ "-";           strcpy(XR1,CR1.c_str());
    CR2 = CR1 + asDetail->Cells[2][i]+ "-";     strcpy(XR2,CR2.c_str());
    CR3 = CR2 + asDetail->Cells[3][i]+ "-";     strcpy(XR3,CR3.c_str());
    CR4 = CR3 + asDetail->Cells[4][i]+ "-";     strcpy(XR4,CR4.c_str());

    CR="";
    /*

    CR = asDetail->Cells[1][i]+ "-";
    CR = CR + asDetail->Cells[2][i]+ "-";
    CR = CR + asDetail->Cells[3][i]+ "-";
    CR = CR + asDetail->Cells[4][i]+ "-";
    */
    if (asDetail->Cells[1][i] != "") CR = CR + asDetail->Cells[1][i]+ "-";
    if (asDetail->Cells[2][i] != "") CR = CR + asDetail->Cells[2][i]+ "-";
    if (asDetail->Cells[3][i] != "") CR = CR + asDetail->Cells[3][i]+ "-";
    if (asDetail->Cells[4][i] != "") CR = CR + asDetail->Cells[4][i]+ "-";
    countache = 0;
    strcpy(XR,CR.c_str());

    for (j=0;j<TSL->Count; j++)
      {
       stt = (T_tch *) TSL->Objects[j];
       for (k=0;k<8;k++)
        {

          strcpy(tmp,stt->t_crit[k].c_str());
          if (strstr(tmp,XR)) countache++;

        }
      }
    asDetail->Cells[8][i] = AnsiString(countache);
  }

}

void __fastcall TCriteres::SaveData()
{
 int i,cnt;
 char tmp[250];

 strcpy(tmp,DatabaseName);
 strcat(tmp,"_crit.txt");
 fp = fopen(tmp,"wt");
 for (i=1;i<=NB_CRIT;i++)
   {
    sprintf(buffer,"<c>%d</c><l>%s</l><d>%s</d><t>%s</t>",i,asCrit->Cells[1][i],
         asCrit->Cells[2][i],asCrit->Cells[3][i]);
    strcat(buffer,"\n");
    fputs(buffer,fp);
   }

 cnt = asDetail->RowCount;
 for (i=1;i<cnt;i++)
   {
     sprintf(buffer,"<c1>%s</c1><c2>%s</c2><c3>%s</c3><c4>%s</c4><d>%s</d><r>%s</r><t>%s</t>",
     asDetail->Cells[1][i].c_str(),
     asDetail->Cells[2][i].c_str(),
     asDetail->Cells[3][i].c_str(),
     asDetail->Cells[4][i].c_str(),
     asDetail->Cells[6][i].c_str(),
     asDetail->Cells[7][i].c_str(),
     asDetail->Cells[8][i].c_str());
     
     strcat(buffer,"\n");
     fputs(buffer,fp);
   }

 fclose(fp);
 change=false;
 Compte_Taches();
 // Application->MessageBoxA("Sauvegarde du Fichier Critères Effectuée",m_ecoplan,MB_OK);

}
//---------------------------------------------------------------------------

int __fastcall TCriteres::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TCriteres::btOKClick(TObject *Sender)
{
 /*
 if (change)
   {
    if (Application->MessageBoxA("Sauvegarde de vos données ?",m_ecoplan,MB_YESNO)==IDYES)
       SaveData();

   }
 */
 Exec_Tri();
 SaveData();
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::btSaveClick(TObject *Sender)
{
  Exec_Tri();
  SaveData();
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::asCritCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 CanEdit = true; //false;
 if (ACol==1) CanEdit=false;
}
//---------------------------------------------------------------------------


void __fastcall TCriteres::asCritClickCell(TObject *Sender, int ARow,
      int ACol)
{

 OldCriter = asCrit->Cells[1][ARow];
 OldRow=ARow;
 OldCol=ACol;
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::FormClose(TObject *Sender, TCloseAction &Action)
{
 /*change=true;
 if (change)
   {
    if (Application->MessageBoxA("Voulez vous sauvegarder les modifications",m_ecoplan,MB_YESNO)==IDYES)
        SaveData();
   }
 */
 Exec_Tri();
  SaveData();

 change=0;
 Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::BitBtn1Click(TObject *Sender)
{
 // bouton UP
 AnsiString Label; int XRow;
 AnsiString XLab;
 AnsiString Design;
 int indx,count;

 if (OldRow==0)
   {Application->MessageBoxA("Pas de ligne sélectionnée",m_ecoplan,MB_OK);
    return;
   }
 //indx=OldRow; //count=asCrit->RowCount-1;
 if(OldRow == 1) return;
 Label = asCrit->Cells[1][OldRow];
 Design = asCrit->Cells[2][OldRow];
 XRow=OldRow-1;
 asCrit->Cells[1][OldRow]=asCrit->Cells[1][XRow];
 asCrit->Cells[1][XRow]=Label;
 asCrit->Cells[2][OldRow]=asCrit->Cells[2][XRow];
 asCrit->Cells[2][XRow]=Design;
 OldRow=XRow;
 Exec_Tri();
 }
//---------------------------------------------------------------------------

void __fastcall TCriteres::BitBtn2Click(TObject *Sender)
{
 // bouton DOWN
 AnsiString Label; int XRow;
 AnsiString XLab;
 AnsiString Design;

 if (OldRow==0)
   {Application->MessageBoxA("Pas de ligne sélectionnée",m_ecoplan,MB_OK);
    return;
   }

 Label = asCrit->Cells[1][OldRow];
 Design = asCrit->Cells[2][OldRow];
 if (OldRow==NB_CRIT) return;
 XRow=OldRow+1;
 asCrit->Cells[1][OldRow]=asCrit->Cells[1][XRow];
 asCrit->Cells[1][XRow]=Label;

 asCrit->Cells[2][OldRow]=asCrit->Cells[2][XRow];
 asCrit->Cells[2][XRow]=Design;

 OldRow=XRow;
 Exec_Tri();

}
//---------------------------------------------------------------------------

int  __fastcall TCriteres::LookRupt(int col)
{
 int i; int cnt; int j,ins,a; char tmp[50];

 cnt=asDetail->RowCount;

 prx[1]=asDetail->Cells[1][memRow];
 prx[2]=asDetail->Cells[2][memRow];
 prx[3]=asDetail->Cells[3][memRow];
 prx[4]=asDetail->Cells[4][memRow];

 for (i=memRow+1;i<cnt;i++)
   {
    xr[1]=asDetail->Cells[1][i];
    xr[2]=asDetail->Cells[2][i];
    xr[3]=asDetail->Cells[3][i];
    xr[4]=asDetail->Cells[4][i];
    if (col==2)
      {
       if (xr[1]!=prx[1])
         {// rupture niveau 0
          a=atoi(prx[col].c_str()); //a++;
          a =CalcNum(col,memRow+1,i,a);
          //a=atoi(prx[col].c_str()); a++;
          sprintf(tmp,"%02d",a); prx[col]=AnsiString(tmp);
          prx[3]=""; prx[4]="";
          return i;
         }
      }
    if (col==3)
      {
       if (xr[1]!=prx[1])
        {
          a=atoi(prx[col].c_str()); //a++;
          a =CalcNum(col,memRow+1,i,a);
          sprintf(tmp,"%02d",a); prx[col]=AnsiString(tmp);
          prx[4]="";
          return i;
         }

       if (xr[1]==prx[1] && xr[2]!=prx[2])
         {
          a=atoi(prx[col].c_str()); //a++;
          a =CalcNum(col,memRow+1,i,a);
          sprintf(tmp,"%02d",a); prx[col]=AnsiString(tmp);
          prx[4]="";
          return i;
         }
      }
    if (col==4)
      {
       if (xr[1]==prx[1] && xr[2]==prx[2] && xr[3]!=prx[3])
         {
          a=atoi(prx[col].c_str()); //a++;
          a =CalcNum(col,memRow+1,i,a);
          sprintf(tmp,"%02d",a); prx[col]=AnsiString(tmp);
          return i;
         }
       if ((xr[1]!=prx[1] || xr[2]!=prx[2])  && (xr[3]!=prx[3]))
         {
          a=atoi(prx[col].c_str()); //a++;
          a =CalcNum(col,memRow+1,i,a);
          sprintf(tmp,"%02d",a); prx[col]=AnsiString(tmp);
          return i;
         }
      }
    //  continuer
    prx[1]=xr[1];
    prx[2]=xr[2];
    prx[3]=xr[3];
    prx[4]=xr[4];
   }
return 0;
}

 int __fastcall TCriteres::CalcNum(int col,int deb,int fin,int a)

{
 int ret,i;   AnsiString Val;
 char tmp[100]; int vmax;
 ret = 0;
vmax=0;
for (i=deb;i<fin;i++)
{
  Val = asDetail->Cells[col][i];
  strcpy(tmp,Val.c_str());
  ret = atoi(tmp);
  if (ret>vmax)  vmax=ret;
}
if (vmax>=a) vmax++;
return vmax;
}


void __fastcall TCriteres::asDetailKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 int i,cnt;  bool flag;
 int insrow;
 AnsiString C1,C2,C3,C4,D1,D2,D3,D4;

 if (Key == VK_INSERT)
    {

      if ((memCol==1)|| (memCol>4)) return;
      cnt=asDetail->RowCount;
      if (asDetail->Cells[memCol-1][memRow]=="") return;
      if(asDetail->Cells[memCol][memRow]!="") return;
      // chercher la ligne ou inserer
      lb=asDetail->Cells[6][memRow];
      insrow= LookRupt(memCol);
      if (insrow==0) return;
      if (insrow==cnt-1)
        {
         Beep();
        }
      else  // tout decaler
        {


         asDetail->RowCount++;
         cnt=asDetail->RowCount;
         cnt++;
        // cleaner la derniere ligne
         for (i=1;i<asDetail->ColCount;i++)  asDetail->Cells[i][cnt-1]="";
         while (cnt >= insrow)
           {
            asDetail->Cells[1][cnt]=asDetail->Cells[1][cnt-1];
            asDetail->Cells[2][cnt]=asDetail->Cells[2][cnt-1];
            asDetail->Cells[3][cnt]=asDetail->Cells[3][cnt-1];
            asDetail->Cells[4][cnt]=asDetail->Cells[4][cnt-1];
            asDetail->Cells[6][cnt]=asDetail->Cells[6][cnt-1];
            asDetail->Cells[7][cnt]=asDetail->Cells[7][cnt-1];
            asDetail->Cells[8][cnt]=asDetail->Cells[8][cnt-1];
            asDetail->Cells[9][cnt]=asDetail->Cells[9][cnt-1];
            cnt--;
            }
         asDetail->Cells[1][insrow]=prx[1];
         asDetail->Cells[2][insrow]=prx[2];
         asDetail->Cells[3][insrow]=prx[3];
         asDetail->Cells[4][insrow]=prx[4];
         asDetail->Cells[6][insrow]=lb;
        }

     //   memRow++;

     Exec_Tri();
     Compte_Taches();
     change = true;
    }

 if (Key==VK_DELETE)
    {
     flag=true;

     C1= asDetail->Cells[1][memRow]; C2= asDetail->Cells[2][memRow];
     C3= asDetail->Cells[3][memRow]; C4= asDetail->Cells[4][memRow];
     D1= asDetail->Cells[1][memRow+1]; D2= asDetail->Cells[2][memRow+1];
     D3= asDetail->Cells[3][memRow+1]; D4= asDetail->Cells[4][memRow+1];

     if (C2=="")
       {
        Application->MessageBoxA("Les critères principaux (P,I,T) ne peuvent être effacés"
        ,"Ecoplanning",MB_OK);
        return;

       }

     if (D1==C1)  // meme N-0
      {
       if (C2=="") flag=false;
       else
        {
         if (C2==D2)
         { if (C3=="")  flag=false;
           if (C3==D3)
             {
              if (C4=="") flag=false;
             }
         }
        } 
       if (flag==false)
         {
          Application->MessageBoxA("Effacez d'abord les sous-niveaux",m_ecoplan,MB_OK);
          return;
         }
      }




     if (Application->MessageBox("Comfirmez la Suppression de la Ligne",m_ecoplan,MB_YESNO)== IDNO)
     return;



     cnt = asDetail->RowCount;
     for (i=memRow;i<cnt;i++)
      {
         asDetail->Cells[1][i]=asDetail->Cells[1][i+1];
         asDetail->Cells[2][i]=asDetail->Cells[2][i+1];
         asDetail->Cells[3][i]=asDetail->Cells[3][i+1];
         asDetail->Cells[4][i]=asDetail->Cells[4][i+1];
         asDetail->Cells[6][i]=asDetail->Cells[6][i+1];
         asDetail->Cells[7][i]=asDetail->Cells[7][i+1];
         asDetail->Cells[8][i]=asDetail->Cells[8][i+1];
         asDetail->Cells[9][i]=asDetail->Cells[9][i+1];
      }
     asDetail->RowCount--;
     Exec_Tri();
     Compte_Taches();
     change = true;
    }

 if (Key==VK_UP)
   {
    OldRow = OldRow-1;
    if (OldRow<1) OldRow=1;
    OldCriter = asCrit->Cells[1][OldRow];
    }

 if (Key==VK_DOWN)
   {
    OldRow = OldRow+1;
    if (OldRow>3) OldRow=3;
    OldCriter = asCrit->Cells[1][OldRow];
    }


  if (Key==VK_LEFT)
   {
    OldCol = OldCol-1;
    if (OldCol<1) OldCol=1;
    OldCriter = asCrit->Cells[1][OldRow];
    }

  if (Key==VK_RIGHT)
   {
    OldCol = OldCol+1;
    if (OldCol>23) OldCol=2;
    OldCriter = asCrit->Cells[1][OldRow];
    }


 }

AnsiString __fastcall TCriteres::SC(int row,int col)
{
 char tmp[50]; int a,i,n ,max;
 bool ok;

 max= asDetail->RowCount;
 // col = 2,3 ou 4
 ok = true; n=row; a=0;
 if (row >= max-1)
      ok = false;
 while (ok)
   {
    switch (col)
      {
       case 2:
          if (asDetail->Cells[1][n+1]==asDetail->Cells[1][row])
            a=atoi(asDetail->Cells[2][n+1].c_str());
            else ok=false;
          break;

       case 3:
          if (asDetail->Cells[1][n+1]==asDetail->Cells[1][row])
           {
             if (asDetail->Cells[2][n+1]==asDetail->Cells[2][row])
             a=atoi(asDetail->Cells[3][n+1].c_str());
             else ok=false;
           }
            else ok=false;
          break;

       case 4:
          if (asDetail->Cells[1][n+1]==asDetail->Cells[1][row])
           {
             if (asDetail->Cells[2][n+1]==asDetail->Cells[2][row])
              {
                if (asDetail->Cells[3][n+1]==asDetail->Cells[3][row])
                a=atoi(asDetail->Cells[4][n+1].c_str());
                else ok=false;
              }
             else ok=false;

           }
          else ok=false;
          break;

      }
    n++;
    if (n>=max) ok=false;
   }




 //strcpy(tmp,asDetail->Cells[col][row].c_str());
 Compte_Taches();
 a++;
 sprintf(tmp,"%02d",a);
 return AnsiString(tmp);
}

//---------------------------------------------------------------------------

void __fastcall TCriteres::asDetailClickCell(TObject *Sender, int ARow,
      int ACol)
{
 memRow = ARow;
 memCol = ACol;
 if (ACol < 5)
  {
 OldValue = asDetail->Cells[1][ARow] + "-";
 OldValue = OldValue + asDetail->Cells[2][ARow] + "-";
 OldValue = OldValue + asDetail->Cells[3][ARow] + "-";
 OldValue = OldValue + asDetail->Cells[4][ARow] + "-";
  }
 else OldValue = asDetail->Cells[6][ARow]; // memcol
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::asDetailCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 if ((ARow < 1) || (ARow >= asDetail->RowCount)) { CanEdit=false; return; }
 if ((ACol < 1) || (ACol >=7)) {CanEdit=false; return; }
 if (ACol>0 && ACol<5) CanEdit = false;
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::btAffecterClick(TObject *Sender)
{
 // Affecter ->Preparer m_criteres
 int indx;   char buff[250];
 // memRow et MemCol
 //


 sprintf(buff,"<c1>%s-</c1><c2>%s-</c2><c3>%s-</c3><c4>%s-</c4><lib>%s-</lib>",
         asDetail->Cells[1][memRow].c_str(),
         asDetail->Cells[2][memRow].c_str(),
         asDetail->Cells[3][memRow].c_str(),
         asDetail->Cells[4][memRow].c_str(),
         asDetail->Cells[6][memRow].c_str());

 strcpy(m_criteres,buff);

 Exec_Tri();
 SaveData();

 Close();
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::asDetailCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
  AnsiString NewValue;
 char tmp[500];
 char scol[50],scrit[50];
 int crit,col,i;

 // Recherche Numero de crit

 crit=0;
 for (i=1;i<8;i++)
   {
    if (asDetail->Cells[1][ARow] == asCrit->Cells[1][i])
       { sprintf(scrit,"%d",i);
         break;
       }
   }
  crit = atoi(scrit);
  if (crit==0) strcpy(scrit,"1");

 if (ACol >0 && ACol <5)
   {
     NewValue = asDetail->Cells[1][ARow] + "-";
     NewValue = NewValue + asDetail->Cells[2][ARow] + "-";
     NewValue = NewValue + asDetail->Cells[3][ARow] + "-";
     NewValue = NewValue + asDetail->Cells[4][ARow] + "-";
     strcpy(scol,"CR");
    }
  else { NewValue = asDetail->Cells[6][ARow]; strcpy(scol,"DES");  }


 strcpy(tmp,"<crit>");strcat(tmp,scrit); strcat(tmp,"</crit>");
 strcat(tmp,"<col>"); strcat(tmp,scol); strcat(tmp,"</col><old>");
 strcat(tmp,OldValue.c_str()); strcat(tmp,"</old><new>");
 strcat(tmp,NewValue.c_str()); strcat(tmp,"</new>");
 // if (Application->MessageBoxA("Modifications pour les tâches concernées ?",m_ecoplan,MB_YESNO) == IDYES)
 //  { strcpy (m_modcrit,tmp);  }  // traiter dans plstd
 change=true;
 Valid = true;
 // Exec_Tri();

}
//---------------------------------------------------------------------------

void __fastcall TCriteres::Exec_Tri()
{
 int cr,i,j,x;
 AnsiString S;

 cr=asDetail->RowCount-1; //cc=asDetail->ColCount-1;
 for (i=1;i<=cr;i++)
   {
    // d'abord trouver la preseance du critere
    S="";
    for (x=1;x<=8;x++)
      {
       if (asDetail->Cells[1][i]==asCrit->Cells[1][x])
         S = asCrit->Cells[0][x];
      }
    // on concat CR et sc1,sc2,sc3
    S = S + asDetail->Cells[1][i] + asDetail->Cells[2][i];
    S = S + asDetail->Cells[3][i] + asDetail->Cells[4][i];
    asDetail->Cells[9][i] =  S;
   }

/*
asDetail->SortSettings->Direction=sdAscending;
asDetail->QSort();
*/
Compte_Taches();
HeightsAndColors();

}

void __fastcall TCriteres::HeightsAndColors()
{
 int i,j,cnt; AnsiString mc; AnsiString V1,V2;
 cnt=asDetail->RowCount;
 for (i=1;i<cnt;i++)
   {
    mc=asDetail->Cells[1][i];
    if (mc == "C4" || mc=="C5" || mc=="C6" || mc=="C7" || mc=="C8")
      asDetail->RowHeights[i]=0;
      else asDetail->RowHeights[i]=21;
    for (j=2;j<5;j++)
      {
       V1 = asDetail->Cells[j-1][i];
       V2 = asDetail->Cells[j][i];
       if (V2=="" && V1 != "") asDetail->Colors[j][i] = clYellow;
        else  asDetail->Colors[j][i] = clWhite;
      }
    if (asDetail->Cells[2][i] != "" && asDetail->Cells[3][i]=="")

       asDetail->Colors[2][i] = clRed;
        else  asDetail->Colors[2][i] = clWhite;
    if (asDetail->Cells[1][i] != "" && asDetail->Cells[2][i]=="")
       asDetail->Colors[2][i] = clYellow;
   }

}



void __fastcall TCriteres::asCritCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
 int cnt,i; char tmp[100];
 AnsiString Num;
 //  Remplacer partout Criteres
 cnt = asDetail->RowCount;
 Valid=true;

 if (ACol==1)
  {
   for (i=1;i<cnt;i++)
     {
       if (asDetail->Cells[1][i] == OldCriter)
       asDetail->Cells[1][i]=StringReplace(asDetail->Cells[1][i],OldCriter,
       asCrit->Cells[1][OldRow],TReplaceFlags() << rfReplaceAll);
     }
   if (Application->MessageBoxA("Sauvegarder le Remplacement ?",m_ecoplan,MB_YESNO)==IDYES)
     {
       SaveData();
       Compte_Taches();
       strcpy(tmp,"<old>"); strcat(tmp,OldCriter.c_str());
       strcat(tmp,"</old><new>");
       strcat(tmp,asCrit->Cells[1][OldRow].c_str());
       strcat(tmp,"</new>");
       strcpy(m_chcrit,tmp);
     }
  }

 if (ACol==2)   // designation
  {
    Num = asCrit->Cells[1][ARow];
    //Boucle pour remplacer Désignation
   for (i=1;i<cnt;i++)
     {
      if  ((asDetail->Cells[1][i] == Num) && (asDetail->Cells[2][i]==""))
        {
         asDetail->Cells[6][i]=Value;
        }

     }
  }
Exec_Tri();

}
//---------------------------------------------------------------------------


void __fastcall TCriteres::Button1Click(TObject *Sender)
{
 Exec_Tri();
 SaveData();
 //strcpy(m_criteres,"");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::FormShow(TObject *Sender)
{
 int i,ctr;
 char tmp[250];   AnsiString S;
 int size;

 change = false;
 OldRow = 0;

 strcpy(tmp,DatabaseName);
 strcat(tmp,"_crit.txt");
 //Limitation a trois Criteres

 HeightsAndColors();

 fp=fopen(tmp,"rt");
 if (fp == NULL)
   {

    Init_Crit();

   }
 else  // lire et remplir le tableau
   {
    fseek(fp,0,SEEK_END);
    size = ftell(fp);
    if (size < 100)
     {
      Init_Crit();
      fseek(fp,0,SEEK_SET);
     }
    else
     {
     fseek(fp,0,SEEK_SET);
     buffer[0]=0; ctr=0;
    fgets(buffer,512,fp);
    while (!feof(fp))   // lire les 8 premiers records;
      {
       ctr++;
       ExtractValue(tmp,buffer,"l",0);
       if (strcmp(tmp,"C1")==0) strcpy(tmp,"P");
       if (strcmp(tmp,"C4")==0) strcpy(tmp,"R");


       asCrit->Cells[1][ctr]=tmp;
       ExtractValue(tmp,buffer,"d",0);
       if (strcmp(tmp,"Désignation 1")==0) strcpy(tmp,"PHASES");
       if (strcmp(tmp,"Critère 4")==0) strcpy(tmp,"RESSOURCES");
       if (strcmp(tmp,"Désignation 4")==0) strcpy(tmp,"RESSOURCES");

       asCrit->Cells[2][ctr]=tmp;
       ExtractValue(tmp,buffer,"t",0);
       asCrit->Cells[3][ctr]=tmp;

       if (ctr==NB_CRIT) break;
       fgets(buffer,512,fp);
      }


     fgets(buffer,512,fp);
     ctr = 0;
     asDetail->RowCount=2;
     for (i=1;i<asDetail->ColCount;i++) asDetail->Cells[i][1]="";
     while (!feof(fp))
      {
       ctr++;
       if (strlen(buffer) > 5)
       {

       ExtractValue(tmp,buffer,"c1",0);
       if (strcmp(tmp,"C1")==0) strcpy(tmp,"P");
       if (strcmp(tmp,"C4")==0) strcpy(tmp,"R");
       if (ctr>1) asDetail->RowCount++;
        asDetail->Cells[1][ctr]=tmp;

       //if (strcmp(tmp,"C4")==0 || strcmp(tmp,"C5")==0 || strcmp(tmp,"C6")==0
       if (strcmp(tmp,"C5")==0 || strcmp(tmp,"C6")==0
           || strcmp(tmp,"C7")==0 || strcmp(tmp,"C8")==0)
         asDetail->RowHeights[ctr]=0;


       ExtractValue(tmp,buffer,"c2",0);
       asDetail->Cells[2][ctr]=tmp;
       ExtractValue(tmp,buffer,"c3",0);
       asDetail->Cells[3][ctr]=tmp;
       ExtractValue(tmp,buffer,"c4",0);
       asDetail->Cells[4][ctr]=tmp;

       asDetail->Cells[5][ctr]="";

       ExtractValue(tmp,buffer,"d",0);
       if (strcmp(tmp,"Désignation 1")==0) strcpy(tmp,"PHASES");
       if (strcmp(tmp,"Critère 4")==0) strcpy(tmp,"RESSOURCES");
       if (strcmp(tmp,"Désignation 4")==0) strcpy(tmp,"RESSOURCES");
       asDetail->Cells[6][ctr]=tmp;
       ExtractValue(tmp,buffer,"r",0);
       asDetail->Cells[7][ctr]=tmp;
       ExtractValue(tmp,buffer,"t",0);
       asDetail->Cells[8][ctr]=tmp;

       // Special Valeur d'origine

       S="";

       S = S + asDetail->Cells[1][ctr] + "-" + asDetail->Cells[2][ctr] + "-" ;
       S = S + asDetail->Cells[3][ctr] + "-" + asDetail->Cells[4][ctr] + "-";
       asDetail->Cells[10][ctr] =  S;
       asDetail->Cells[11][ctr] =  asDetail->Cells[6][ctr]; // designation

       }
       fgets(buffer,512,fp);
      }
     } // else size
    //asDetail->RowCount;
    fclose (fp);
   }
  Exec_Tri();
  Compte_Taches();

}
//---------------------------------------------------------------------------

void __fastcall TCriteres::Init_Crit()
{
 asDetail->RowCount=NB_CRIT+1;
    asCrit->Cells[1][1]="P"; asDetail->Cells[1][1]=asCrit->Cells[1][1];
    asCrit->Cells[2][1]="PHASES"; asDetail->Cells[6][1]=asCrit->Cells[2][1];
    asCrit->Cells[1][2]="I"; asDetail->Cells[1][2]=asCrit->Cells[1][2];
    asCrit->Cells[2][2]="INTERVENANTS"; asDetail->Cells[6][2]=asCrit->Cells[2][2];
    asCrit->Cells[1][3]="T"; asDetail->Cells[1][3]=asCrit->Cells[1][3];
    asCrit->Cells[2][3]="TRIS"; asDetail->Cells[6][3]=asCrit->Cells[2][3];
    asCrit->Cells[1][4]="R"; asDetail->Cells[1][4]=asCrit->Cells[1][4];
    asCrit->Cells[2][4]="RESSOURCES"; asDetail->Cells[6][4]=asCrit->Cells[2][4];
    asCrit->Cells[1][5]="C5"; asDetail->Cells[1][5]=asCrit->Cells[1][5];
    asCrit->Cells[2][5]="Désignation 5"; asDetail->Cells[6][5]=asCrit->Cells[2][5];
    asCrit->Cells[1][6]="C6"; asDetail->Cells[1][6]=asCrit->Cells[1][6];
    asCrit->Cells[2][6]="Désignation 6"; asDetail->Cells[6][6]=asCrit->Cells[2][6];
    asCrit->Cells[1][7]="C7"; asDetail->Cells[1][7]=asCrit->Cells[1][7];
    asCrit->Cells[2][7]="Désignation 7"; asDetail->Cells[6][7]=asCrit->Cells[2][7];
    asCrit->Cells[1][8]="C8"; asDetail->Cells[1][8]=asCrit->Cells[1][8];
    asCrit->Cells[2][8]="Désignation 8"; asDetail->Cells[6][8]=asCrit->Cells[2][8];
    change = true;

}


void __fastcall TCriteres::btAideClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"AffectCriteres.html#Affect3");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------







void __fastcall TCriteres::btHierClick(TObject *Sender)
{
 Hierarchie(true);

}
//---------------------------------------------------------------------------

void __fastcall TCriteres::Hierarchie(bool disp)
{
int i,cnt; int ct1,ct2,ct3;
 char fmt1[20],fmt2[20],fmt3[20];  AnsiString cr,crt,crd;

 if (disp)
  {
   if (Application->MessageBoxA("Cette nouvelle hierarchie peut avoir des conséquences sur les critères déja affectés aux tâches. Voulez-vous continuer?",m_ecoplan,MB_YESNO)==IDNO) return;
  }
 cr = ""; cnt = asDetail->RowCount;
 ct1=0; ct2=0; ct3=0;

 for (i=1;i<cnt;i++)
   {
    crt = asDetail->Cells[1][i];
    if (crt != cr)
      {

       ct1=0;ct2=0;ct3=0;
       asDetail->Cells[2][i]="";
       asDetail->Cells[3][i]="";
       asDetail->Cells[4][i]="";
       cr=crt;
      }
    else
      {
       crd = asDetail->Cells[1][i];
       if (crd == crt)
         {
          if (asDetail->Cells[3][i]=="")
            {
             ct1++; sprintf(fmt1,"%02d",ct1); asDetail->Cells[2][i]= AnsiString(fmt1);
             ct2=0; ct3=0;
            }
          else if (asDetail->Cells[3][i] != "" && asDetail->Cells[4][i]=="")
           {
            asDetail->Cells[2][i]=AnsiString(fmt1);
            ct2++; sprintf(fmt2,"%02d",ct2); asDetail->Cells[3][i]= AnsiString(fmt2);
            ct3=0;
           }
          else if (asDetail->Cells[4][i] != "" && asDetail->Cells[5][i]=="")
           {
            asDetail->Cells[2][i]=AnsiString(fmt1);
            asDetail->Cells[3][i]=AnsiString(fmt2);
            ct3++; sprintf(fmt3,"%02d",ct3); asDetail->Cells[4][i]= AnsiString(fmt3);
           }

         }

      }
   }
 HeightsAndColors();
 SaveData();
 Affecter_Crit(false);


}


void __fastcall TCriteres::Affecter_Crit(bool disp)
{
 AnsiString S,Result;
 int i,cnt; AnsiString Col6,Col10,Col11;
  bool modif;

 if (disp)
   {
    if (Application->MessageBoxA("Voulez-vous réaffecter les nouveaux critères aux  tâches ?",
     m_ecoplan,MB_YESNO) == IDNO) return;
   }

 TSLCRIT->Clear();

  cnt = asDetail->RowCount;
  for (i=1;i<cnt;i++)
   {
    modif = false;
    Result="<cr>" + asDetail->Cells[1][i] + "</cr>";
    S = asDetail->Cells[1][i] + "-" + asDetail->Cells[2][i] + "-" ;
    S = S + asDetail->Cells[3][i] + "-" + asDetail->Cells[4][i] + "-";

    Col10= asDetail->Cells[10][i];
    if (S != Col10)
      {
       Result = Result + "<oc>" + Col10 + "</oc>";
       Result = Result + "<nc>" + S + "</nc>";
       asDetail->Cells[10][i] = S;     // memorise nlle valeur
       modif=true;
      }
    Col11=asDetail->Cells[11][i];
    Col6=asDetail->Cells[6][i];
    if (Col6 != Col11)
     {
      Result = Result + "<od>" + Col11 + "</od>";
      Result = Result + "<nd>" + Col6 + "</nd>";
      asDetail->Cells[11][i] = Col6;  // memorise nlle valeur
      modif = true;
     }
    if (modif)
     {
      TSLCRIT->Add(Result);
     }
   }
 strcpy(m_affect_crit,"Exec_Affect");
 // traitement dans plstd

}


void __fastcall TCriteres::BitBtn3Click(TObject *Sender)
{
 // memRow   row d'origine
 AnsiString ocol1,ocol2,ocol3,ocol4;
 AnsiString ucol1,ucol2,ucol3,ucol4;
 int rowbloc;  int i,j; int XA,XB;
 char mess[200];  int cnt;

 if (memRow==0) return;

 ocol1= asDetail->Cells[1][memRow];
 ocol2= asDetail->Cells[2][memRow];
 ocol3= asDetail->Cells[3][memRow];
 ocol4= asDetail->Cells[4][memRow];
 if (ocol2=="")
   {
    strcpy(mess,"Le bloc "); strcat(mess,ocol1.c_str()); strcat(mess," ne peut être déplacé");
    Application->MessageBoxA(mess,m_ecoplan,MB_OK);
    return;
   }
 if (ocol3!="")
   {
    strcpy(mess,"Déplacement seulement pour blocs de niveau -1");
    Application->MessageBoxA(mess,m_ecoplan,MB_OK);
    return;
   }
 // recherche d'un bloc devant
 rowbloc=0;
 for (i=memRow-1;i>1;i--)
   {
    ucol1= asDetail->Cells[1][i];
    ucol2= asDetail->Cells[2][i];
    ucol3= asDetail->Cells[3][i];
    ucol4= asDetail->Cells[4][i];

    if (ucol1==ocol1 && ucol2 != "" && ucol3=="")   // delimite le bloc devant
      {
       rowbloc=i;
       break;
      }
   }
 if (rowbloc==0) {Beep(); return; }
 strcpy(mess,"Echange entre le bloc ");
 strcat(mess,ocol1.c_str()); strcat(mess,"-");
 strcat(mess,ocol2.c_str()); strcat(mess," et le bloc ");
 strcat(mess,ucol1.c_str()); strcat(mess,"-");
 strcat(mess,ucol2.c_str()); strcat(mess," ? Une hierarchisation sera effectuée ");

 if (Application->MessageBoxA(mess,m_ecoplan,MB_YESNO)==IDNO) return;

 AdvX->Clear(); AdvX->RowCount=1;
 XB=memRow-1;  XA=memRow;
 for (i=memRow;i<asDetail->RowCount;i++)
   {
    if (asDetail->Cells[1][i]!=ocol1 || asDetail->Cells[2][i] !=ocol2)
        break;
    XA = i;
   }

//  transferer les données dans AdvX

 cnt=1;
 for (i=rowbloc; i<=XA; i++)
  {
   AdvX->RowCount++;
   for (j=1;j<asDetail->ColCount;j++) AdvX->Cells[j][cnt]=asDetail->Cells[j][i];
   cnt++;
  }

 cnt = rowbloc;   // transfert bloc origine
 for (i= (memRow-rowbloc +1); i<=(XA-rowbloc+1); i++)
  {
   for (j=1;j<asDetail->ColCount;j++) asDetail->Cells[j][cnt]=AdvX->Cells[j][i];
   cnt++;
  }
 for (i=1; i<=(XB-rowbloc+1); i++)
  {
   for (j=1;j<asDetail->ColCount;j++) asDetail->Cells[j][cnt]=AdvX->Cells[j][i];
   cnt++;
  }

 Update_TSL(ocol1,ocol2,ucol1,ucol2);
 Compte_Taches();

 Hierarchie(false);
 change=true;
}
//---------------------------------------------------------------------------

void __fastcall TCriteres::Update_TSL(AnsiString O1, AnsiString O2, AnsiString U1,AnsiString U2)
{
  char tmp[200];  int j,k,col;    int l1,l2;
  char ref1[150],ref2[150];
 // dans TSL, remplacer les No de critères
 // 1ere boucle pour marquer les taches
  strcpy(ref1,O1.c_str()); strcat(ref1,"-"); strcat(ref1,O2.c_str());  strcat(ref1,"-");
  strcpy(ref2,U1.c_str()); strcat(ref2,"-"); strcat(ref2,U2.c_str());  strcat(ref2,"-");
  l1=strlen(ref1);
  l2=strlen(ref2);

  if (O1=="P") col = 1;
  if (O1=="I") col = 2;
  if (O1=="T") col = 3;

  for (j=0;j<TSL->Count; j++)
      {
       stt = new T_tch;
       stt = (T_tch *) TSL->Objects[j];
       strcpy(tmp,stt->t_crit[col-1].c_str());
       if (strstr(tmp,ref1))
          {
           strncpy(tmp,ref2,l2);
           stt->t_crit[col-1] = AnsiString(tmp);

          }
       else if (strstr(tmp,ref2))
          {
           strncpy(tmp,ref1,l1);
           stt->t_crit[col-1] = AnsiString(tmp);
          }

      }


}






void __fastcall TCriteres::FormCreate(TObject *Sender)
{
 asDetail->Refresh();
}
//---------------------------------------------------------------------------

