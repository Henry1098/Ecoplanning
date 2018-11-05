//---------------------------------------------------------------------------

#ifndef modPrepPlanningH
#define modPrepPlanningH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

#include "FinalIsam.h"
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>

#define BUFSIZE 10000

//---------------------------------------------------------------------------
class TPrepPlanning : public TForm
{
__published:	// IDE-managed Components
        TListBox *lbPlanning;
        TLabel *Label1;
        TLabel *Label3;
        TButton *Button1;
        TLabel *Label5;
        TButton *Button2;
        TLabel *Label7;
        TButton *Button3;
        TLabel *Label8;
        TEdit *eMemoire;
        TMemo *mPlanning;
        TLabel *Label9;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TGroupBox *GroupBox1;
        TRadioButton *rb1;
        TRadioButton *rb2;
        TGroupBox *GroupBox2;
        TRadioButton *rb11;
        TRadioButton *rb12;
        TCheckBox *cb1;
        TCheckBox *cb2;
        TLabel *Label10;
        TCheckBox *cb4;
        TCheckBox *cb5;
        TCheckBox *cb6;
        TButton *btEntete;
        TButton *btCal;
        TCheckBox *cb7;
        TLabel *Label11;
        TLabel *Label12;
        TButton *btTaches;
        TButton *btCorps;
        TButton *btPied;
        TButton *btOK;
        TButton *btCadre;
        TButton *btM;
        TBevel *Bevel2;
        TBevel *Bevel3;
        TButton *Button9;
        TBevel *Bevel5;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label15;
        TLabel *Label16;
        TButton *btAppliquer;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label21;
        TBevel *Bevel4;
        TButton *btSuppr;
        TTimer *Timer1;
        TCheckBox *cbEbauche;
        TLabel *Label14;
        TLabel *Label17;
        TLabel *Label18;
        TButton *Button4;
        TLabel *Label19;
        TAdvStringGrid *AdvStringGrid1;
        TLabel *Label4;
        TLabel *Label20;
        TButton *Button5;
        TButton *Button10;
        TListBox *ListBox1;
        TButton *Button11;
        TButton *Button12;
        TAdvStringGrid *AdvStringGrid2;
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall btEnteteClick(TObject *Sender);
        void __fastcall btCadreClick(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btCalClick(TObject *Sender);
        void __fastcall btTachesClick(TObject *Sender);
        void __fastcall btCorpsClick(TObject *Sender);
        void __fastcall btPiedClick(TObject *Sender);
        void __fastcall btLignesClick(TObject *Sender);
        void __fastcall btMClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall lbPlanningClick(TObject *Sender);
        void __fastcall rb2Click(TObject *Sender);
        void __fastcall rb1Click(TObject *Sender);
        void __fastcall btAppliquerClick(TObject *Sender);
        void __fastcall btSupprClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall cb4Click(TObject *Sender);
        void __fastcall cb5Click(TObject *Sender);
        void __fastcall cb6Click(TObject *Sender);
        void __fastcall cb7Click(TObject *Sender);
        void __fastcall rb11Click(TObject *Sender);
        void __fastcall rb12Click(TObject *Sender);
        void __fastcall cb2Click(TObject *Sender);
        void __fastcall cb1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall cbEbaucheClick(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall mPlanningKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button2ContextPopup(TObject *Sender,
          TPoint &MousePos, bool &Handled);
        void __fastcall Button1ContextPopup(TObject *Sender,
          TPoint &MousePos, bool &Handled);
        void __fastcall Button3ContextPopup(TObject *Sender,
          TPoint &MousePos, bool &Handled);
        void __fastcall Label3ContextPopup(TObject *Sender,
          TPoint &MousePos, bool &Handled);
        void __fastcall Label5ContextPopup(TObject *Sender,
          TPoint &MousePos, bool &Handled);
        void __fastcall Label7ContextPopup(TObject *Sender,
          TPoint &MousePos, bool &Handled);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall AdvStringGrid2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations

        realisam *plannings;
        char buffer[10000];
        char str[5000];
        char params[30][1000];
        char current_planning[250];
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

        void __fastcall BufBrisees();
        void __fastcall StripC(char *s);
        int __fastcall Explode(char sep,char *str);
        //int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
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
        void __fastcall SaveData(int mode);
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
//        void __fastcall LoadPlanningFromFile(char *pl);
        int __fastcall DeleteK(char *k);

public:		// User declarations
        __fastcall TPrepPlanning(TComponent* Owner);
        void __fastcall PlanningP();
};
//---------------------------------------------------------------------------
extern PACKAGE TPrepPlanning *PrepPlanning;
//---------------------------------------------------------------------------
#endif
