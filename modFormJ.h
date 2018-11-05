//---------------------------------------------------------------------------

#ifndef modFormJH
#define modFormJH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDformJour : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *bTOK;
        TButton *btAnnul;
        TButton *btAide;
private:	// User declarations
public:		// User declarations
        __fastcall TFDformJour(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDformJour *FDformJour;
//---------------------------------------------------------------------------
#endif
