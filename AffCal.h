//---------------------------------------------------------------------------

#ifndef AffCalH
#define AffCalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "FinalIsam.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAffectCal : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBox1;
        TLabel *Label5;
        TMemo *Memo1;
        TButton *Affect;
        TButton *Annul;
        TButton *Aide;
        TLabel *Label1;
        TTimer *Timer1;
        TCheckBox *CheckBox1;
        void __fastcall AnnulClick(TObject *Sender);
        void __fastcall AffectClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall AideClick(TObject *Sender);
private:	// User declarations
        realisam *cals;
        char comments[6][5500];
        int  step;
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);


public:		// User declarations
        __fastcall TAffectCal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAffectCal *AffectCal;
//---------------------------------------------------------------------------
#endif
