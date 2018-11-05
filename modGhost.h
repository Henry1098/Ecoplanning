//---------------------------------------------------------------------------

#ifndef modGhostH
#define modGhostH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "FinalIsam.h"
//---------------------------------------------------------------------------
class TGhost : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *PopupTL;
        TMenuItem *TitreenLigne1;
        TMenuItem *N2;
        TMenuItem *PoliceTexte1;
        TMenuItem *HauteurTitreenLigne1;
        TMenuItem *LigneSparatriceHaute1;
        TMenuItem *LigneSparatriceBasse1;
        TMenuItem *CouleurFond1;
        TMenuItem *JustificationTexte1;
        TMenuItem *RetraitHorizontalTitre1;
        TPopupMenu *PopupTC;
        TMenuItem *TitreenColonne1;
        TMenuItem *N1;
        TMenuItem *PoliceetCouleurTexte1;
        TMenuItem *HauteurTitreenLigne2;
        TMenuItem *LigneSparatriceHaute2;
        TMenuItem *LigneSparatriceBasse2;
        TMenuItem *CouleurFond2;
        TMenuItem *JustificationTexte2;
        TMenuItem *RetraitHorizontalTitre2;
        TPopupMenu *PopupST;
        TMenuItem *SansTitre1;
        TMenuItem *LigneSparatrice1;
        TPopupMenu *PLigne;
        TMenuItem *Ligne1;
        TMenuItem *CouleurLigne1;
        TMenuItem *StyleLigne1;
        TMenuItem *EpaisseurLigne1;
        TLabel *Label1;
        TPopupMenu *PEpaiss;
        TMenuItem *EpaisseurLigne2;
        TMenuItem *N00mm1;
        TMenuItem *N010mm1;
        TMenuItem *N020mm1;
        TMenuItem *N050mm1;
        TMenuItem *N080mm1;
        TMenuItem *N100mm1;
        TMenuItem *N150mm1;
        TMenuItem *N200mm1;
        TMenuItem *N250mm1;
        TPopupMenu *PStyle;
        TMenuItem *StyleLigne2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TFontDialog *TFontDialog1;
        TColorDialog *CD;
        TMenuItem *Libell1;
        TMenuItem *Libell2;
        TPopupMenu *PopupCol;
        TMenuItem *PoliceetCouleurTexte2;
        TMenuItem *Hauteur1;
        TMenuItem *CouleurdeFond1;
        TMenuItem *Justification1;
        void __fastcall TitreenLigne1Click(TObject *Sender);
        void __fastcall LigneSparatriceHaute1Click(TObject *Sender);
        void __fastcall PoliceTexte1Click(TObject *Sender);
        void __fastcall CouleurFond1Click(TObject *Sender);
        void __fastcall LigneSparatriceBasse1Click(TObject *Sender);
        void __fastcall JustificationTexte1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall RetraitHorizontalTitre1Click(TObject *Sender);
        void __fastcall CouleurLigne1Click(TObject *Sender);
        void __fastcall StyleLigne1Click(TObject *Sender);
        void __fastcall EpaisseurLigne1Click(TObject *Sender);
        void __fastcall LigneSparatrice1Click(TObject *Sender);
        void __fastcall TitreenColonne1Click(TObject *Sender);
        void __fastcall HauteurTitreenLigne2Click(TObject *Sender);
        void __fastcall HauteurTitreenLigne1Click(TObject *Sender);
        void __fastcall PoliceetCouleurTexte1Click(TObject *Sender);
        void __fastcall LigneSparatriceBasse2Click(TObject *Sender);
        void __fastcall CouleurFond2Click(TObject *Sender);
        void __fastcall Libell2Click(TObject *Sender);
        void __fastcall Libell1Click(TObject *Sender);
        void __fastcall LigneSparatriceHaute2Click(TObject *Sender);
        void __fastcall JustificationTexte2Click(TObject *Sender);
        void __fastcall RetraitHorizontalTitre2Click(TObject *Sender);
        void __fastcall N00mm1Click(TObject *Sender);
        void __fastcall N010mm1Click(TObject *Sender);
        void __fastcall N020mm1Click(TObject *Sender);
        void __fastcall N050mm1Click(TObject *Sender);
        void __fastcall N080mm1Click(TObject *Sender);
        void __fastcall N100mm1Click(TObject *Sender);
        void __fastcall N150mm1Click(TObject *Sender);
        void __fastcall N200mm1Click(TObject *Sender);
        void __fastcall N250mm1Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall PoliceetCouleurTexte2Click(TObject *Sender);
        //void __fastcall New_Planning();


private:	// User declarations

        realisam *plannings;

#define BUFSIZE 10000
        char comment[10000];
        char buffer[10000];
        char str[5000];
        char params[30][2000];
        char current_planning[250];
        char filename[250];

        char buf_marges[BUFSIZE];
        char buf_entete[BUFSIZE];
        char buf_cal[BUFSIZE];
        char buf_cadre[BUFSIZE];
        char buf_gen[BUFSIZE];
        char buf_taches[BUFSIZE];
        char buf_corps[BUFSIZE];
        char buf_pied[BUFSIZE];
        char buf_tligne[BUFSIZE];
        char buf_tcol[BUFSIZE];

        char buf_colonnes[BUFSIZE];

        void __fastcall StripC(char *s);
        int __fastcall Explode(char sep,char *str);
        void __fastcall StripT(char *s);
        void __fastcall Strip(char *s);
        void __fastcall LoadData(char *cp);
        void __fastcall LoadRapport(char *cp);
        void __fastcall LoadGen();
        void __fastcall LoadCadre();
        void __fastcall LoadMarges();
        void __fastcall LoadEntete();
        void __fastcall LoadCalendrier();
        void __fastcall LoadTaches();
        void __fastcall LoadCorps();
        void __fastcall LoadPied();
        //void __fastcall LoadBandes();
        void __fastcall LoadTLigne();
        void __fastcall LoadTCol();
        void __fastcall LoadBrise();

        //   Special             


        void __fastcall Ftaches(char *buf,int indice);
        float __fastcall AnsiToFloat(AnsiString str);
        void __fastcall  LoadMem(char *s,int indx);



public:		// User declarations
        __fastcall TGhost(TComponent* Owner);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        void __fastcall New_Planning();
        void __fastcall Global_Col(char *s);
        void __fastcall Global_Filtre(char *s);
        void __fastcall Global_Tri(char *s);
        void __fastcall Global_Planning(char *s);
        void __fastcall Global_Report(char *s);
        void __fastcall Help(char *url);
        void __fastcall Save_GlobColonnes(char *s);
        void __fastcall Save_GlobTri(char *s);      
        void __fastcall LoadPlanningFromFile(char *pl);
        void __fastcall StripEnvelop(char *s);


};
//---------------------------------------------------------------------------
extern PACKAGE TGhost *Ghost;
//---------------------------------------------------------------------------
#endif
