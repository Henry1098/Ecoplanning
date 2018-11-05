//---------------------------------------------------------------------------

#ifndef modCriteresH
#define modCriteresH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Buttons.hpp>
#include <Grids.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------



class TCriteres : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TAdvStringGrid *asDetail;
        TButton *btAffecter;
        TButton *btAide;
        TButton *btSave;
        TButton *btOK;
        TLabel *Label2;
        TButton *Button1;
        TLabel *Label1;
        TButton *btHier;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TMemo *Memo3;
        TAdvStringGrid *asCrit;
        TMemo *Memo2;
        TMemo *Memo1;
        TAdvStringGrid *AdvX;
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btSaveClick(TObject *Sender);
        void __fastcall asCritCanEditCell(TObject *Sender, int ARow,
          int ACol, bool &CanEdit);
        void __fastcall asCritClickCell(TObject *Sender, int ARow,
          int ACol);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall asDetailKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall asDetailClickCell(TObject *Sender, int ARow,
          int ACol);
        void __fastcall asDetailCanEditCell(TObject *Sender, int ARow,
          int ACol, bool &CanEdit);
        void __fastcall btAffecterClick(TObject *Sender);
        void __fastcall asDetailCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall asCritCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
        void __fastcall btHierClick(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations

#define NB_CRIT 8

        FILE *fp;
        char buffer[5000];
        bool change;
        int  OldCol,OldRow,memRow,memCol;
        int  OldC,OldR;
        int  DRow,DCol;
        AnsiString OldCriter;

        AnsiString cr[5];
        AnsiString xr[5];
        AnsiString prx[5];
        AnsiString lb;

        typedef struct // stch
          {
                int t_numtache;
                AnsiString t_design;
                int t_duree;
                //TStringList *t_pred;
                //TStringList *t_succ;
                //TStringList *t_amont;
                AnsiString t_crit[8];
                AnsiString t_libcrit[8];

          } T_tch;

        T_tch  *stt;
        AnsiString OldValue;

        void __fastcall Update_TSL(AnsiString O1, AnsiString O2, AnsiString U1,AnsiString U2);
        void __fastcall Init_Crit();
        void __fastcall Affecter_Crit(bool disp);
        void __fastcall Hierarchie(bool disp);
        void __fastcall HeightsAndColors();
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        void __fastcall SaveData();
        void __fastcall Exec_Tri();
        int  __fastcall LookRupt(int col);
        void __fastcall Compte_Taches();
        int __fastcall CalcNum(int col,int deb,int fin,int a);
        AnsiString __fastcall SC(int row,int col);




public:		// User declarations
        __fastcall TCriteres(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCriteres *Criteres;
//---------------------------------------------------------------------------
#endif
