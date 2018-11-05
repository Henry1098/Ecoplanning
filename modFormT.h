//---------------------------------------------------------------------------

#ifndef modFormTH
#define modFormTH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDformT : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
private:	// User declarations
public:		// User declarations
        __fastcall TFDformT(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDformT *FDformT;
//---------------------------------------------------------------------------
#endif
