//---------------------------------------------------------------------------

#ifndef modFormSH
#define modFormSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDformSem : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
private:	// User declarations
public:		// User declarations
        __fastcall TFDformSem(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDformSem *FDformSem;
//---------------------------------------------------------------------------
#endif
