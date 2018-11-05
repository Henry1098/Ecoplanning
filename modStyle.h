//---------------------------------------------------------------------------

#ifndef modStyleH
#define modStyleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDStyle : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TComboBox *cbStyle;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFDStyle(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDStyle *FDStyle;
//---------------------------------------------------------------------------
#endif
