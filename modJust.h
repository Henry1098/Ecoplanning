//---------------------------------------------------------------------------

#ifndef modJustH
#define modJustH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TJust : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations
        char jh[250],jv[250];
        int  mod;

        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TJust(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TJust *Just;
//---------------------------------------------------------------------------
#endif
