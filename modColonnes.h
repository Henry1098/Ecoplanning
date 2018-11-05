//---------------------------------------------------------------------------

#ifndef modColonnesH
#define modColonnesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Buttons.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "FinalIsam.h"
#include "modGhost.h"

//---------------------------------------------------------------------------
class TColonnes : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label4;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TButton *Button4;
        TButton *Button5;
        TEdit *eMemoire;
        TMemo *mCol;
        TLabel *Label3;
        TLabel *Label5;
        TListBox *lbCol;
        TLabel *Label6;
        TButton *Button6;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label1;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TButton *btNew;
        TButton *btLigne;
        TButton *btMod;
        TButton *btEffacer;
        TButton *btOK;
        TTimer *Timer1;
        TAdvStringGrid *asFCC;
        TAdvStringGrid *asFD;
        TLabel *Label2;
        TImage *imFColor;
        TImage *imBColor;
        TLabel *Label7;
        TLabel *Label8;
        TButton *btDefaut;
        TButton *btCreer;
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall btNewClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall asFCCContextPopup(TObject *Sender, TPoint &MousePos,
          bool &Handled);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall lbColClick(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall btEffacerClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall asFCCClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall btLigneClick(TObject *Sender);
        void __fastcall btModClick(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall asFDClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall btDefautClick(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall btCreerClick(TObject *Sender);
        void __fastcall asFDCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall asFCCCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations

        int OldRow,OldCol;

        bool  change;
        realisam *col;
        char  buffer[8000];
        char filename[250];
        char params[50][1000];
        char current_col[250];
        char mode[250];

//        int __fastcall Exec_Reports();
        int __fastcall SaveData();
        int __fastcall check_data(char *s);
        void __fastcall FillColor(int color,TImage *im);
        void __fastcall Strip(char *s);
        void __fastcall CStrip(char *s);
        void __fastcall Save_Preseance();
        int  __fastcall Explode(char sep,char *str);
        void __fastcall Clean(TAdvStringGrid *adv,int n);
        void __fastcall CleanRow(int row);
        void __fastcall Assign_Globals();
        void __fastcall Adjust_Titre();
        void __fastcall Defaut_Champs(int Row);
        void __fastcall Defaut_Titres(int Row);
        void __fastcall Init_Titre();
        void __fastcall Init_Champ();
        void __fastcall Display_Col(char *s);
        void __fastcall Modify();
        void __fastcall Load_From_Globals();

public:		// User declarations
        __fastcall TColonnes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TColonnes *Colonnes;
//---------------------------------------------------------------------------
#endif
