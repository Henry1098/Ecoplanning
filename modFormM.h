//---------------------------------------------------------------------------

#ifndef modFormMH
#define modFormMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDformM : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
private:	// User declarations
public:		// User declarations
        __fastcall TFDformM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDformM *FDformM;
//---------------------------------------------------------------------------
#endif
