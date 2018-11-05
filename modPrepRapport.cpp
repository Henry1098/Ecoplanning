//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modPrepRapport.h"

#include <stdio.h>


#include "globals.h"
#include "modEntete.h"
#include "modecadre.h"
#include "modDcal.h"
#include "modTaches.h"
#include "modCorps.h"
#include "modPied.h"
#include "modBandes.h"
#include "modMarges.h"
#include "modTri.h"
#include "modColonnes.h"
#include "modFilter.h"
#include "modTcol.h"
#include "modTligne.h"
#include "modDump.h"
#include "modGhost.h"
#include "plstd.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrepRapport *PrepRapport;
//---------------------------------------------------------------------------
__fastcall TPrepRapport::TPrepRapport(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::BitBtn1Click(TObject *Sender)
{
 // Up Move
  int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbRapport->ItemIndex;
 if (indx == -1) return;
 count = lbRapport->Items->Count;
 if (indx == 0) { lbRapport->Items->Move(indx,count-1); lbRapport->ItemIndex=count-1; }
 else { lbRapport->Items->Move(indx,indx-1);  lbRapport->ItemIndex=indx-1; }
 Save_Preseance();
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::BitBtn2Click(TObject *Sender)
{
// Down Move
 int indx,count;
 char tmp1[100],tmp2[100];

 indx = lbRapport->ItemIndex;
 if (indx == -1) return;
 count = lbRapport->Items->Count;
 if (indx == count-1) { lbRapport->Items->Move(indx,0); lbRapport->ItemIndex=0; }

 else { lbRapport->Items->Move(indx,indx+1); lbRapport->ItemIndex=indx + 1; }
 Save_Preseance();
}
//---------------------------------------------------------------------------


void __fastcall TPrepRapport::Save_Preseance()
{
FILE *fp;
int i,count;  char tmp[250];
strcpy(filename,m_directory); //DatabaseName);
strcat(filename,"\\eco_rapports.txt");
count=lbRapport->Items->Count;
fp = fopen(filename,"wt");
for (i=0;i<count;i++)
  {
   sprintf(tmp,"<l>%s</l>\n",lbRapport->Items->Strings[i].c_str());
   fputs(tmp,fp);
  }
fclose(fp);
}


void __fastcall TPrepRapport::Button2Click(TObject *Sender)
{
 TTri *Tri;

 strcpy(m_exchange,"<tri>"); strcat(m_exchange,P_TRI[pc]); strcat(m_exchange,"</tri>");
  strcat(m_exchange,"<util>utiliser</util>");
  
 Tri = new TTri(Application);
 Tri->Height=619;
 Tri->Width=754;

 Tri->Show(); //Modal();

  Label3->Caption = AnsiString(P_TRI[pc]);
 Affect_Tri(P_TRI[pc]);

}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::Affect_Tri(char *s)
{
 Label3->Caption = AnsiString(s);
}


void __fastcall TPrepRapport::Button1Click(TObject *Sender)
{
 TxFilter *filt;
 char tmp[250];
 char strfilter[100];

 strcpy(m_exchange,"<util>utiliser</util><filt>");
 strcat(m_exchange,P_FILTRE[pc]); strcat(m_exchange,"</filt>");
 strcpy(m_project,DatabaseName);
 filt = new TxFilter(Application);
 filt->Height = 705;
 filt->Width = 774;

//  filt->Visible=true;
 m_filtre[0]=0;
 filt->ShowModal(); //Modal();
 delete filt;
 //Label3->Caption = AnsiString(P_FILTRE[pc]);
 //delete filt;
 //Affect_Filtre(P_FILTRE[pc]);

}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::Button3Click(TObject *Sender)
{
TColonnes *Col;
 strcpy(m_exchange,"<col>"); strcat(m_exchange,P_COLONNES[pc]); strcat(m_exchange,"</col>");
  strcat(m_exchange,"<util>utiliser</util>");
 Col = new TColonnes(Application);
 Col->Height=705;
 Col->Width=778;

 Col->ShowModal();
 delete Col;
 Label7->Caption= AnsiString(P_COLONNES[pc]);
 if (strlen(m_exchange)) Affect_Colonnes(P_COLONNES[pc]);

}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::cbMargeClick(TObject *Sender)
{
if (cbMarge->Checked==true)
 P_MARGES[pc]='O';
 else P_MARGES[pc]='N';
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btMargesClick(TObject *Sender)
{
TFDmarges *Marges;
 Marges = new TFDmarges(Application);
 Marges->ShowModal();
 delete Marges;
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btTitLigClick(TObject *Sender)
{

TTri *Tri;

 strcpy(m_exchange,"<tri>"); strcat(m_exchange,P_TRI[pc]); strcat(m_exchange,"</tri>");
 strcat(m_exchange,"<util>utiliser</util>");
 Tri = new TTri(Application);
 Tri->Height=619;
 Tri->Width=754;

 Tri->ShowModal();  //Modal();
 delete Tri;
 /*
TFDTligne *TLigne;
 //Envoi_Params(0);
 TLigne = new TFDTligne(Application);
 TLigne->ShowModal();
 delete TLigne;
 //if (strlen(m_exchange)==0) return;
 // recuperer les donnees
 //Recupere_Params(0);
*/
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btDonLigClick(TObject *Sender)
{
//Envoi_Params(1);
 TFDTcol *TCol;
 TCol = new TFDTcol(Application);
 TCol->ShowModal();
 delete TCol;
 //if (strlen(m_exchange)==0) return;
 // recuperer les donnees
 //Recupere_Params(1);
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btSupprClick(TObject *Sender)
{
 int rc,recdata; char Key[100],RetKey[100];
 char tmp[250]; char TempKey[100];
 int indx;

 if (eMemoire->Text == "")
   {
    Application->MessageBoxA("Pas de Rapport Sélectionné",m_ecoplan,MB_OK);
    return;
  }
 if (Application->MessageBoxA("Confirmer l'effacement du rapport",m_ecoplan,MB_YESNO)==IDNO)
    return;
 strcpy(TempKey,eMemoire->Text.c_str());

 strcpy(tmp,m_directory);  //DatabaseName);
 strcat(tmp,"\\eco_rapports");

 rc = rapports->OpenEngine(tmp,1016,"ndx","dat");   //1024 - 8
 rc = rapports->SetIndexMode(0,0);

 strcpy(Key,TempKey); strcat(Key,"-GEN");
 rc=DeleteK(Key);
 strcpy(Key,TempKey); strcat(Key,"-MRG");
 rc=DeleteK(Key);
 strcpy(Key,TempKey); strcat(Key,"-ETT");
 rc=DeleteK(Key);
 //strcpy(Key,TempKey); strcat(Key,"-CAL");
 //rc=DeleteK(Key);
 //strcpy(Key,TempKey); strcat(Key,"-CDR");
 //rc=DeleteK(Key);
 //strcpy(Key,TempKey); strcat(Key,"-TCH");
 //rc=DeleteK(Key);
 //strcpy(Key,TempKey); strcat(Key,"-COR");
 //rc=DeleteK(Key);
 strcpy(Key,TempKey); strcat(Key,"-PIE");
 rc=DeleteK(Key);
 strcpy(Key,TempKey); strcat(Key,"-TLIG");
 rc=DeleteK(Key);
 strcpy(Key,TempKey); strcat(Key,"-TCOL");
 rc=DeleteK(Key);

 rapports->CloseEngine();

 indx = lbRapport->ItemIndex;
 lbRapport->Items->Delete(indx);
 eMemoire->Clear();
 Save_Preseance();
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btCreerClick(TObject *Sender)
{
 eMemoire->Text="";
 mRapport->Clear();
 Label3->Caption="";
 Label5->Caption="";
 Label7->Caption="";
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btAppliquerClick(TObject *Sender)
{
 char tmp[250];
 strcpy(P_NOM[pc],Label23->Caption.c_str());
 sprintf(tmp,"<pl>%d</pl><tri>%s</tri><col>%s</col><filt>%s</filt><exec>Y</exec>",pc,
 P_TRI[pc],P_COLONNES[pc],P_FILTRE[pc]);
 strcpy(m_rapport,tmp);
 Save_Preseance();
 Close();
}
//---------------------------------------------------------------------------




void __fastcall TPrepRapport::Init_Planning()
{
 int i;

 eMemoire->Text="";
 mRapport->Clear();
 Ghost->New_Planning();
}


void __fastcall TPrepRapport::SaveData(void)
{
 char name[100];
 char TempKey[100],Key[100],RetKey[100];
 int rc,recdata,i,nbitems;
 char tmp[2000];
 char filename[250];

 strcpy(TempKey,eMemoire->Text.c_str());
 if (strlen(TempKey) == 0)
   {
    Application->MessageBoxA("Pas de Nom de Rapport",m_ecoplan,MB_OK);
    return;
   }

 // preparer buffer
 BufGen();
 BufMarges();
 BufEntete();
// BufCal();
// BufCadre();
// BufTaches();
 BufCorps();
 BufPied();
 BufTligne();
 BufTcol();

 if (strlen(P_TRI[pc])) Ghost->Save_GlobTri(P_TRI[pc]);
 if (strlen(P_COLONNES[pc])) Ghost->Save_GlobColonnes(P_COLONNES[pc]);

 strcpy(filename,m_directory);  //DatabaseName);
 strcat(filename,"\\eco_rapports");
 rc = rapports->OpenEngine(filename,1016,"ndx","dat");   //1024 - 8
 rc = rapports->SetIndexMode(0,0);

 strcpy(Key,TempKey); strcat(Key,"-GEN");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_gen, strlen(buf_gen)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_gen,strlen(buf_gen)+1);
       lbRapport->Items->Add(AnsiString(TempKey));
     }

 strcpy(Key,TempKey); strcat(Key,"-MRG");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_marges, strlen(buf_marges)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_marges,strlen(buf_marges)+1);
     }


 strcpy(Key,TempKey); strcat(Key,"-ETT");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_entete, strlen(buf_entete)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_entete,strlen(buf_entete)+1);
     }

 /*
 strcpy(Key,TempKey); strcat(Key,"-CAL");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_cal, strlen(buf_cal)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_cal,strlen(buf_cal)+1);
     }

 strcpy(Key,TempKey); strcat(Key,"-CDR");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_cadre, strlen(buf_cadre)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_cadre,strlen(buf_cadre)+1);
     }

 strcpy(Key,TempKey); strcat(Key,"-TCH");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_taches, strlen(buf_taches)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_taches,strlen(buf_taches)+1);
     }

 strcpy(Key,TempKey); strcat(Key,"-COR");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_corps, strlen(buf_corps)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_corps,strlen(buf_corps)+1);
     }

 */

 strcpy(Key,TempKey); strcat(Key,"-COR");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_corps, strlen(buf_corps)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_corps,strlen(buf_corps)+1);
     }

 strcpy(Key,TempKey); strcat(Key,"-PIE");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_pied, strlen(buf_pied)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_pied,strlen(buf_pied)+1);
     }


 strcpy(Key,TempKey); strcat(Key,"-TLIG");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_tligne, strlen(buf_tligne)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_tligne,strlen(buf_tligne)+1);
     }

 strcpy(Key,TempKey); strcat(Key,"-TCOL");
 rc = rapports->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = rapports->RewriteRecord(buf_tcol, strlen(buf_tcol)+1,recdata);
     else
     { recdata=rapports->GetNewRecordNumber();
       rc = rapports->WriteKey(0,Key,recdata);
       rc = rapports->WriteRecord(buf_tcol,strlen(buf_tcol)+1);
     }

Save_Preseance();
rapports->CloseEngine();
change = false;
Application->MessageBoxA("Rapport Sauvegardé",m_ecoplan,MB_OK);
}

void __fastcall TPrepRapport::Bufferize(char *f,int indx)
{
 char tmp[50]; int c;

 strcat(f,"<txt>");
 strcat(f,PT[pc][indx].c_str());
 strcat(f,"</txt>");

 strcat(f,"<act>");
 strcat(f,PACTIF[pc][indx].c_str());
 strcat(f,"</act>");


 strcat(f,"<pol>");
 strcat(f,PF[pc][indx].c_str());
 strcat(f,"</pol>");

 strcat(f,"<fgd>");
 c=(int) PC[pc][indx]; sprintf(tmp,"%d",c); strcat(f,tmp);
 strcat(f,"</fgd>");

 strcat(f,"<ita>");
 strcat(f,PN[pc][indx].c_str());
 //if (PN[pc][indx]=="Standar'N') strcat(f,"N"); else strcat(f,"I");
 strcat(f,"</ita>");

 strcat(f,"<bld>");
 strcat(f,PX[pc][indx].c_str());
 //if (PX[pc][indx]=='N') strcat(f,"N"); else strcat(f,"B");
 strcat(f,"</bld>");

 strcat(f,"<siz>");
 sprintf(tmp,"%d",PH[pc][indx]);  strcat(f,tmp);
 strcat(f,"</siz>");

 strcat(f,"<bkg>");
 c=(int) PB[pc][indx]; sprintf(tmp,"%d",c); strcat(f,tmp);
 strcat(f,"</bkg>");

 strcat(f,"<jsh>");
 strcat(f,PJH[pc][indx].c_str());
 //if (PJH[pc][indx]=='G') strcat(f,"G");
 //else if (PJH[pc][indx]=='C') strcat(f,"C");
 //else strcat(f,"D");
 strcat(f,"</jsh>");

 strcat(f,"<jsv>");
 if (PJV[pc][indx]=='H') strcat(f,"H");
 else if (PJV[pc][indx]=='C') strcat(f,"C");
 else strcat(f,"B");
 strcat(f,"</jsv>");

 strcat(f,"<hgt>");
 sprintf(tmp,"%d",PHH[pc][indx]);  strcat(f,tmp);
 strcat(f,"</hgt>");

 strcat(f,"<lsp>");  // PTYPE  L,C, O/N
 tmp[0]=PTYPE[pc][indx];
 tmp[1]=0; strcat(f,tmp);
 strcat(f,"</lsp>");

}

void __fastcall TPrepRapport::BufCorps()
{
char tmp[250];  int i;
 char str[250];

 strcpy(buf_corps,"");
 strcat(buf_corps,"<COR>");

 for (i=0;i<8;i++)
  {
    sprintf(str,"<c%d>",i);strcat(buf_corps,str);
    strcat(buf_corps,"<cyn>"); strcat(buf_corps,P_CYN[pc][i].c_str()); strcat(buf_corps,"</cyn>");
    strcat(buf_corps,"<ccfg>"); strcat(buf_corps,P_CCFG[pc][i].c_str()); strcat(buf_corps,"</ccfg>");
    //strcat(buf_corps,"<ccbk>"); strcat(buf_corps,P_CCBK[pc][i].c_str()); strcat(buf_corps,"</ccbk>");
    strcat(buf_corps,"<ccst>"); strcat(buf_corps,P_CCST[pc][i].c_str()); strcat(buf_corps,"</ccst>");
    strcat(buf_corps,"<ccep>"); strcat(buf_corps,P_CCEP[pc][i].c_str()); strcat(buf_corps,"</ccep>");
    sprintf(str,"</c%d>",i);strcat(buf_corps,str);
  }


 strcat(buf_corps,"<cjt>"); strcat(buf_corps,P_CJT[pc].c_str()); strcat(buf_corps,"</cjt>");
 strcat(buf_corps,"<cjtfl>"); strcat(buf_corps,P_CJTFLAG[pc].c_str()); strcat(buf_corps,"</cjtfl>");
 strcat(buf_corps,"<cjnt>"); strcat(buf_corps,P_CJNT[pc].c_str()); strcat(buf_corps,"</cjnt>");
 strcat(buf_corps,"<cwent>"); strcat(buf_corps,P_CWENT[pc].c_str()); strcat(buf_corps,"</cwent>");
 strcat(buf_corps,"<cdh>"); strcat(buf_corps,P_CDH[pc].c_str()); strcat(buf_corps,"</cdh>");
 strcat(buf_corps,"<cdv>"); strcat(buf_corps,P_CDV[pc].c_str()); strcat(buf_corps,"</cdv>");

 strcat(buf_corps,"<ccjt>"); strcat(buf_corps,P_CCJT[pc].c_str()); strcat(buf_corps,"</ccjt>");
 strcat(buf_corps,"<ccjnt>"); strcat(buf_corps,P_CCJNT[pc].c_str()); strcat(buf_corps,"</ccjnt>");
 strcat(buf_corps,"<ccwent>"); strcat(buf_corps,P_CCWENT[pc].c_str()); strcat(buf_corps,"</ccwent>");
 strcat(buf_corps,"</COR>");
}

void __fastcall TPrepRapport::BufMarges()
{
 char tmp[50];

 buf_marges[0]=0;
 strcat(buf_marges,"<MRG>");
 strcat(buf_marges,"<mrg>");
 if (P_MARGES[pc]=='O') strcat(buf_marges,"O"); else strcat(buf_marges,"N");
 strcat(buf_marges,"</mrg>");

 strcat(buf_marges,"<mht>");
 strcat(buf_marges,P_MV1[pc].c_str());
 strcat(buf_marges,"</mht>");
 strcat(buf_marges,"<mba>");
 strcat(buf_marges,P_MV2[pc].c_str());
 strcat(buf_marges,"</mba>");
 strcat(buf_marges,"<mga>");
 strcat(buf_marges,P_MH1[pc].c_str());
 strcat(buf_marges,"</mga>");
 strcat(buf_marges,"<mdr>");
 strcat(buf_marges,P_MH2[pc].c_str());
 strcat(buf_marges,"</mdr>");
 strcat(buf_marges,"</MRG>");
}


void __fastcall TPrepRapport::BufTligne()
{
 /*
 char tmp[3000];
 strcpy(buf_tligne,"");
 strcat(buf_tligne,"<TLIG>");
 tmp[0]=0;
 strcat(tmp,"<pol>"); strcat(tmp,PL_POL[pc].c_str()); strcat(tmp,"</pol>");
 strcat(tmp,"<ct>"); strcat(tmp,PL_CTEXT[pc].c_str()); strcat(tmp,"</ct>");
 strcat(tmp,"<it>"); strcat(tmp,PL_ITAL[pc].c_str()); strcat(tmp,"</it>");
 strcat(tmp,"<bd>"); strcat(tmp,PL_BOLD[pc].c_str()); strcat(tmp,"</bd>");
 strcat(tmp,"<ht>"); strcat(tmp,PL_HAUTEUR[pc].c_str()); strcat(tmp,"</ht>");
 strcat(tmp,"<jh>"); strcat(tmp,PL_JSH[pc].c_str()); strcat(tmp,"</jh>");
 strcat(tmp,"<jv>"); strcat(tmp,PL_JSV[pc].c_str()); strcat(tmp,"</jv>");
 strcat(tmp,"<cb>"); strcat(tmp,PL_CBKG[pc].c_str()); strcat(tmp,"</cb>");
 strcat(tmp,"<lg>"); strcat(tmp,PL_LARG[pc].c_str()); strcat(tmp,"</lg>");
 strcat(tmp,"<ep1>"); strcat(tmp,PL_LS1EP[pc].c_str()); strcat(tmp,"</ep1>");
 strcat(tmp,"<cl1>"); strcat(tmp,PL_LS1CL[pc].c_str()); strcat(tmp,"</cl1>");
 strcat(tmp,"<ls2>"); strcat(tmp,PL_LS2[pc].c_str()); strcat(tmp,"</ls2>");
 strcat(tmp,"<ep2>"); strcat(tmp,PL_LS2EP[pc].c_str()); strcat(tmp,"</ep2>");
 strcat(tmp,"<cl2>"); strcat(tmp,PL_LS2CL[pc].c_str()); strcat(tmp,"</cl2>");

 strcat(buf_tligne,tmp);
 strcat(buf_tligne,"</TLIG>");
*/

}

void __fastcall TPrepRapport::BufTcol()
{
/*
 char tmp[3000];
 strcpy(buf_tcol,"");
 strcat(buf_tcol,"<TCOL>");

 tmp[0]=0;
 strcat(tmp,"<pol>"); strcat(tmp,PC_POL[pc].c_str()); strcat(tmp,"</pol>");
 strcat(tmp,"<ct>"); strcat(tmp,PC_CTEXT[pc].c_str()); strcat(tmp,"</ct>");
 strcat(tmp,"<it>"); strcat(tmp,PC_ITAL[pc].c_str()); strcat(tmp,"</it>");
 strcat(tmp,"<bd>"); strcat(tmp,PC_BOLD[pc].c_str()); strcat(tmp,"</bd>");
 strcat(tmp,"<ht>"); strcat(tmp,PC_HAUTEUR[pc].c_str()); strcat(tmp,"</ht>");
 strcat(tmp,"<jh>"); strcat(tmp,PC_JSH[pc].c_str()); strcat(tmp,"</jh>");
 strcat(tmp,"<jv>"); strcat(tmp,PC_JSV[pc].c_str()); strcat(tmp,"</jv>");
 strcat(tmp,"<cb>"); strcat(tmp,PC_CBKG[pc].c_str()); strcat(tmp,"</cb>");
 strcat(tmp,"<lg>"); strcat(tmp,PC_LARG[pc].c_str()); strcat(tmp,"</lg>");
 strcat(tmp,"<ep1>"); strcat(tmp,PC_LS1EP[pc].c_str()); strcat(tmp,"</ep1>");
 strcat(tmp,"<cl1>"); strcat(tmp,PC_LS1CL[pc].c_str()); strcat(tmp,"</cl1>");
 strcat(tmp,"<ls2>"); strcat(tmp,PC_LS2[pc].c_str()); strcat(tmp,"</ls2>");
 strcat(tmp,"<ep2>"); strcat(tmp,PC_LS2EP[pc].c_str()); strcat(tmp,"</ep2>");
 strcat(tmp,"<cl2>"); strcat(tmp,PC_LS2CL[pc].c_str()); strcat(tmp,"</cl2>");

 strcat(buf_tcol,tmp);
 strcat(buf_tcol,"</TCOL>");
*/

}


void __fastcall TPrepRapport::BufGen()
{
 char tmp[250];


  strcpy(buf_gen,"<GEN>");
  strcpy(tmp,eMemoire->Text.c_str());

 strcat(buf_gen,"<nom>"); strcat(buf_gen,tmp); strcat(buf_gen,"</nom>");
 strcat(buf_gen,"<com>");
 strcat(buf_gen,mRapport->Lines->GetText());
 strcat(buf_gen,"</com>");
 strcat(buf_gen,"<fut>");
 strcat(buf_gen,P_FILTRE[pc]);
 strcat(buf_gen,"</fut>");
 strcat(buf_gen,"<tut>");
 strcat(buf_gen,P_TRI[pc]);
 strcat(buf_gen,"</tut>");
 strcat(buf_gen,"<cut>");
 strcat(buf_gen,P_COLONNES[pc]);
 strcat(buf_gen,"</cut>");
 strcat(buf_gen,"<gen>");



// if (rb11->Checked==true)strcat(buf_gen,"C"); else strcat(buf_gen,"G");
// if (P_GENRE[pc]=='C') strcat(buf_gen,"C"); else strcat(buf_gen,"G");
 strcat(buf_gen,"</gen>");


 strcat(buf_gen,"<mrg>");
 if (cbMarge->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</mrg>");



/*
 strcat(buf_gen,"<ggt>");
 if(cb2->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
// if (P_GRILLE[pc]=='O') strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</ggt>");
 strcat(buf_gen,"<tpl>");
 if (rb1->Checked==true) strcat(buf_gen,"P"); else strcat(buf_gen,"R");
// if (P_TYPE[pc]=='P') strcat(buf_gen,"P"); else strcat(buf_gen,"R");
 strcat(buf_gen,"</tpl>");
 strcat(buf_gen,"<lbr>");
 if(cb1->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
// if (P_LBRISE[pc]=='O') strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</lbr>");

 strcat(buf_gen,"<mod>");
 if (rbPortrait->Checked==true) strcat(buf_gen,"P"); else strcat(buf_gen,"L");
 strcat(buf_gen,"</mod>");
 */
 strcat(buf_gen,"<mrg>");
 if (cbMarge->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</mrg>");

 strcat(buf_gen,"<cad>");
 if (cb3->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</cad>");

 strcat(buf_gen,"<ett>");
 if (cb4->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</ett>");
 /*
 strcat(buf_gen,"<cah>");
 if (cb5->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</cah>");

 strcat(buf_gen,"<cab>");
 if (cb6->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</cab>");
 */
 strcat(buf_gen,"<pie>");
 if (cb7->Checked==true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</pie>");

 strcat(buf_gen,"<mpe>");
 if (cbETPage->Checked == true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</mpe>");
 strcat(buf_gen,"<mpp>");
 if (cbPied->Checked == true) strcat(buf_gen,"O"); else strcat(buf_gen,"N");
 strcat(buf_gen,"</mpp>");

 strcat(buf_gen,"</GEN>");

}


void __fastcall TPrepRapport::Affect_Colonnes(char *s)
{
 int recdata,rc; char Key[100],RetKey[100];
 char tmp[5000];

 Label7->Caption = AnsiString(s);
 if (strlen(s)==0) return;

 //Ghost->Global_Col(s);
}

int __fastcall TPrepRapport::DeleteK(char *k)
{
 char RetKey[100]; int recdata, rc;
 rc = rapports->ReadDirectKey(0,k,RetKey,&recdata);
 if (rc)
  {
   rc=rapports->DeleteKey(0,k,recdata);
   rc=rapports->DeleteRecord(recdata);
  }
 return rc;
}
void __fastcall TPrepRapport::Timer1Timer(TObject *Sender)
{
  char x_ghost_prep[500];
  char tmp[2000];
 Timer1->Enabled=false;

 if (strlen(m_assign))
  {
   Ghost->ExtractValue(tmp,m_assign,"tri",0);
   if (strlen(tmp)) { strcpy(P_TRI[pc],tmp); Label3->Caption = AnsiString(tmp);
     Ghost->Global_Tri(tmp); }
   Ghost->ExtractValue(tmp,m_assign,"fil",0);
   if (strlen(tmp)) { strcpy(P_FILTRE[pc],tmp); Label5->Caption = AnsiString(tmp);
     Ghost->Global_Filtre(tmp); }
   Ghost->ExtractValue(tmp,m_assign,"col",0);
   if (strlen(tmp)) { strcpy(P_COLONNES[pc],tmp); Label7->Caption = AnsiString(tmp);
     Ghost->Global_Col(tmp); }

  }
  m_assign[0]=0;

  if (m_ghost_prep[pc] != "")
  {
   strcpy(x_ghost_prep,m_ghost_prep[pc].c_str());
   Ghost->ExtractValue(current_rapport,x_ghost_prep,"pl",0);
   Ghost->ExtractValue(tmp,x_ghost_prep,"com",0);
   mRapport->Clear(); mRapport->SetTextBuf(tmp);
   Maj_Decor();
  }
 m_ghost_prep[pc]="";
 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TPrepRapport::Maj_Decor()
{
 Label5->Caption = AnsiString(P_FILTRE[pc]);
 Label3->Caption = AnsiString(P_TRI[pc]);
 Label7->Caption = AnsiString(P_COLONNES[pc]);
 Label23->Caption = AnsiString(current_rapport);
 eMemoire->Text = AnsiString(current_rapport);


 if (P_MARGES[pc]=='O') cbMarge->Checked=true; else cbMarge->Checked=false;
 if (P_CADRE[pc]=='O') cb3->Checked=true; else cb3->Checked=false;
 if (P_ENTETE[pc]=='O') cb4->Checked=true; else cb4->Checked=false;
  if (P_PIED[pc]=='O') cb7->Checked=true; else cb7->Checked=false;
  if (P_MPPIED[pc]=='O') cbPied->Checked=true; else cbPied->Checked=false;
   if (P_MPENTETE[pc]=='O') cbETPage->Checked=true; else cbETPage->Checked=false;


}

void __fastcall TPrepRapport::Button7Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::Button6Click(TObject *Sender)
{
 SaveData();
 Label23->Caption = eMemoire->Text;
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::lbRapportClick(TObject *Sender)
{
int indx; char tmp[5000];
int rc,recdata; char Key[100],RetKey[100];

indx = lbRapport->ItemIndex;
if (indx == -1) return;

if (change) { SaveData(); change=0; }

 strcpy(tmp,lbRapport->Items->Strings[indx].c_str());
 eMemoire->Text=AnsiString(tmp);
 Label23->Caption = eMemoire->Text;
 strcpy(current_rapport,tmp);
 strcpy(LastPlanning[pc],current_rapport);
 Ghost->Global_Report(LastPlanning[pc]);

 lbRapport->Items->Move(indx,0);
 lbRapport->ItemIndex=0;

// Adapter les radio Button
 P_MODE[pc]=='P';


}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btOKClick(TObject *Sender)
{
Save_Preseance();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::cb3Click(TObject *Sender)
{
 if (cb3->Checked==true)
 P_CADRE[pc]='O';
 else P_CADRE[pc]='N';        
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btCadreClick(TObject *Sender)
{
TCadre *Cadre;
 Cadre = new TCadre(Application);
 Cadre->ShowModal();
 delete Cadre;
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::cb4Click(TObject *Sender)
{
  if (cb4->Checked==true)
 P_ENTETE[pc]='O';
 else { P_ENTETE[pc]='N'; cbETPage->Checked = false; P_MPENTETE[pc]='N'; }
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btEnteteClick(TObject *Sender)
{
 TEntete *Entete;
 Entete = new TEntete(Application);
 Entete->ShowModal();
 delete Entete;        
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::cb7Click(TObject *Sender)
{
 if (cb7->Checked==true)
  P_PIED[pc]='O';
 else { P_PIED[pc]='N'; cbPied->Checked = False; P_MPPIED[pc] = 'N'; }
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::btPiedClick(TObject *Sender)
{
TFDpied *Pied;
 Pied = new TFDpied(Application);
 Pied->ShowModal();
 delete Pied;
}
//---------------------------------------------------------------------------


void __fastcall TPrepRapport::BufEntete()
{

  buf_entete[0]=0;
  strcat(buf_entete,"<ETT>");

  if (cb4->Checked==true) P_ENTETE[pc]='O';

  strcat(buf_entete,"<ett>");
  if (P_ENTETE[pc]=='O') strcat(buf_entete,"O</ett>");
    else strcat(buf_entete,"N</ett>");



  strcat(buf_entete,"<eg1>");
  Bufferize(buf_entete,0);
  strcat(buf_entete,"</eg1>");

  strcat(buf_entete,"<eg2>");
  Bufferize(buf_entete,1);
  strcat(buf_entete,"</eg2>");

  strcat(buf_entete,"<eg3>");
  Bufferize(buf_entete,2);
  strcat(buf_entete,"</eg3>");

  strcat(buf_entete,"<ec1>");
  Bufferize(buf_entete,3);
  strcat(buf_entete,"</ec1>");

  strcat(buf_entete,"<ec2>");
  Bufferize(buf_entete,4);
  strcat(buf_entete,"</ec2>");

  strcat(buf_entete,"<ec3>");
  Bufferize(buf_entete,5);
  strcat(buf_entete,"</ec3>");

  strcat(buf_entete,"<ed1>");
  Bufferize(buf_entete,6);
  strcat(buf_entete,"</ed1>");

  strcat(buf_entete,"<ed2>");
  Bufferize(buf_entete,7);
  strcat(buf_entete,"</ed2>");

  strcat(buf_entete,"<ed3>");
  Bufferize(buf_entete,8);
  strcat(buf_entete,"</ed3>");

  strcat(buf_entete,"</ETT>");

}

void __fastcall TPrepRapport::BufPied()
{
 if (cb7->Checked==true) P_PIED[pc]='O';

 strcpy(buf_pied,"");
 strcat(buf_pied,"<PIE>");

  strcat(buf_pied,"<pg1>");
  Bufferize(buf_pied,25);
  strcat(buf_pied,"</pg1>");

  strcat(buf_pied,"<pg2>");
  Bufferize(buf_pied,26);
  strcat(buf_pied,"</pg2>");

  strcat(buf_pied,"<pg3>");
  Bufferize(buf_pied,27);
  strcat(buf_pied,"</pg3>");

  strcat(buf_pied,"<pc1>");
  Bufferize(buf_pied,28);
  strcat(buf_pied,"</pc1>");

  strcat(buf_pied,"<pc2>");
  Bufferize(buf_pied,29);
  strcat(buf_pied,"</pc2>");

  strcat(buf_pied,"<pc3>");
  Bufferize(buf_pied,30);
  strcat(buf_pied,"</pc3>");

  strcat(buf_pied,"<pd1>");
  Bufferize(buf_pied,31);
  strcat(buf_pied,"</pd1>");

  strcat(buf_pied,"<pd2>");
  Bufferize(buf_pied,32);
  strcat(buf_pied,"</pd2>");

  strcat(buf_pied,"<pd3>");
  Bufferize(buf_pied,33);
  strcat(buf_pied,"</pd3>");

 strcat(buf_pied,"</PIE>");

}

void __fastcall TPrepRapport::FormShow(TObject *Sender)
{

FILE *fp;  char *p;
 char buff[250],tmp[250];
 int rc,recdata;
 char Key[100],RetKey[100];
 int ctr,lg;


  rapports = new realisam;
  change = false;
  strcpy(filename,m_directory);  //DatabaseName);
  strcat(filename,"\\eco_rapports.txt");

  lbRapport->Clear();

  fp=fopen(filename,"rt");
 if (fp == NULL)
   {

   }
 else   //read file pour ordre de préseance
   {
    buff[0]=0; ctr=0;
    fgets(buff,512,fp);
    while (!feof(fp))   // lire les noms dans l'ordre
      {
       ctr++;
       lg = Ghost->ExtractValue(tmp,buff,"l",0);
       if (lg==0) break;
       lbRapport->Items->Add(AnsiString(tmp));
       fgets(buff,512,fp);
      }
    fclose(fp);
   }

 if (pc<4) pc=4;


 P_MODE[pc]='P';
 P_GRILLE[pc]='O';

  if (strlen(P_NOM[pc])==0)
   { Init_Planning();
     if (strlen(LastPlanning[pc]))
      {
        if (change) { SaveData(); change=0; }

        eMemoire->Text=AnsiString(LastPlanning[pc]);
        Label23->Caption = eMemoire->Text;
        strcpy(current_rapport,LastPlanning[pc]);
        Ghost->Global_Report(LastPlanning[pc]);
    // Adapter les radio Button
      }
   }


if (strcmp(m_memoriser,"memo")==0)
    {
     SaveData();
     strcpy(m_memoriser,"");
     Close();
    }

}
//---------------------------------------------------------------------------



void __fastcall TPrepRapport::btDonColClick(TObject *Sender)
{
TColonnes *Col;
 strcpy(m_exchange,"<col>"); strcat(m_exchange,P_COLONNES[pc]); strcat(m_exchange,"</col>");
  strcat(m_exchange,"<util>utiliser</util>");
 Col = new TColonnes(Application);
 Col->Height=705;
 Col->Width=778;

 Col->ShowModal();
 delete Col;
 Label7->Caption= AnsiString(P_COLONNES[pc]);
 if (strlen(m_exchange)) Affect_Colonnes(P_COLONNES[pc]);
        
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::cbETPageClick(TObject *Sender)
{
 if (cbETPage->Checked == true)
   {
    P_MPENTETE[pc] = 'O';
   }
 else
   {
   P_MPENTETE[pc] = 'N';
   }
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::cbPiedClick(TObject *Sender)
{
if (cbPied->Checked == true)
   {
    P_MPPIED[pc] = 'O';
   }
 else
   {
   P_MPPIED[pc] = 'N';
   }
}
//---------------------------------------------------------------------------

void __fastcall TPrepRapport::mRapportChange(TObject *Sender)
{
 CommentPL[pc] = AnsiString(mRapport->Lines->GetText());

}
//---------------------------------------------------------------------------

