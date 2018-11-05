//---------------------------------------------------------------------------

#ifndef modFormAH
#define modFormAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDformA : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
private:	// User declarations
public:		// User declarations
        __fastcall TFDformA(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDformA *FDformA;
//---------------------------------------------------------------------------
#endif
