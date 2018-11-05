//---------------------------------------------------------------------------

#ifndef modPrepRapportH
#define modPrepRapportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>


#include "FinalIsam.h"
#define BUFSIZE 10000


//---------------------------------------------------------------------------
class TPrepRapport : public TForm
{
__published:	// IDE-managed Components
        TListBox *lbRapport;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button1;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button2;
        TLabel *Label6;
        TLabel *Label7;
        TButton *Button3;
        TLabel *Label8;
        TEdit *eMemoire;
        TMemo *mRapport;
        TLabel *Label9;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *btAppliquer;
        TLabel *Label11;
        TBevel *Bevel1;
        TLabel *Label15;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label12;
        TLabel *Label13;
        TButton *btCreer;
        TLabel *Label23;
        TBevel *Bevel2;
        TButton *btOK;
        TLabel *Label14;
        TCheckBox *cbMarge;
        TButton *btMarges;
        TLabel *Label16;
        TLabel *Label17;
        TButton *btDonCol;
        TButton *btTitLig;
        TBevel *Bevel3;
        TButton *btSuppr;
        TTimer *Timer1;
        TCheckBox *cb3;
        TButton *btCadre;
        TCheckBox *cb4;
        TButton *btEntete;
        TCheckBox *cb7;
        TButton *btPied;
        TCheckBox *cbETPage;
        TCheckBox *cbPied;
        TBevel *Bevel5;
        TBevel *Bevel6;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall cbMargeClick(TObject *Sender);
        void __fastcall btMargesClick(TObject *Sender);
        void __fastcall btTitLigClick(TObject *Sender);
        void __fastcall btDonLigClick(TObject *Sender);
        void __fastcall btSupprClick(TObject *Sender);
        void __fastcall btCreerClick(TObject *Sender);
        void __fastcall btAppliquerClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall lbRapportClick(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall cb3Click(TObject *Sender);
        void __fastcall btCadreClick(TObject *Sender);
        void __fastcall cb4Click(TObject *Sender);
        void __fastcall btEnteteClick(TObject *Sender);
        void __fastcall cb7Click(TObject *Sender);
        void __fastcall btPiedClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btDonColClick(TObject *Sender);
        void __fastcall cbETPageClick(TObject *Sender);
        void __fastcall cbPiedClick(TObject *Sender);
        void __fastcall mRapportChange(TObject *Sender);
private:	// User declarations


        realisam *rapports;
        char buffer[10000];
        char str[5000];
        char params[30][1000];
        char current_rapport[250];
        char filename[250];
        int OldRow,OldCol;
        bool change;



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

        void __fastcall StripC(char *s);
        int __fastcall Explode(char sep,char *str);
        
        void __fastcall Save_Preseance();
        void __fastcall BufMarges();
        void __fastcall BufEntete();
        void __fastcall BufCal();
        void __fastcall BufCadre();
        void __fastcall BufGen();
        void __fastcall BufTaches();
        void __fastcall BufCorps();
        void __fastcall BufPied();
        //void __fastcall BufBandes();
        void __fastcall BufTligne();
        void __fastcall BufTcol();
        void __fastcall SaveData();
        void __fastcall LoadData(char *cp);
        void __fastcall Init_Planning();
        void __fastcall Bufferize(char *f,int indx);
        void __fastcall PrepTache(char *f,int indx);
        void __fastcall LoadGen();
        void __fastcall LoadCadre();
        void __fastcall LoadMarges();
        void __fastcall LoadEntete();
        void __fastcall LoadCalendrier();
        void __fastcall LoadTaches();
        void __fastcall LoadCorps();
        void __fastcall LoadPied();
        //void __fastcall LoadBandes();
        void __fastcall Maj_Decor();
        void __fastcall LoadTLigne();
        void __fastcall LoadTCol();
        void __fastcall Affect_Filtre(char *s);
        void __fastcall Affect_Colonnes(char *s);
        void __fastcall Affect_Tri(char *s);
        void __fastcall LoadMem(char *s,int indx);
        void __fastcall Envoi_Params(int ligcol);
        void __fastcall Recupere_Params(int ligcol);
        void __fastcall Ftaches(char *buf,int indice);
        float __fastcall AnsiToFloat(AnsiString str);
        int __fastcall DeleteK(char *k);



public:		// User declarations
        __fastcall TPrepRapport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrepRapport *PrepRapport;
//---------------------------------------------------------------------------
#endif
