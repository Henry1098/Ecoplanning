//---------------------------------------------------------------------------

#ifndef modUnitH
#define modUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDunit : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBox1;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        TLabel *Label1;
private:	// User declarations
public:		// User declarations
        __fastcall TFDunit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDunit *FDunit;
//---------------------------------------------------------------------------
#endif
