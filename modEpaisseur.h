//---------------------------------------------------------------------------

#ifndef modEpaisseurH
#define modEpaisseurH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDEpaisseur : public TForm
{
__published:	// IDE-managed Components
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        TComboBox *cbE;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations

        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TFDEpaisseur(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDEpaisseur *FDEpaisseur;
//---------------------------------------------------------------------------
#endif
