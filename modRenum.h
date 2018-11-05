//---------------------------------------------------------------------------

#ifndef modRenumH
#define modRenumH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TRenum : public TForm
{
__published:	// IDE-managed Components
        TButton *btYes;
        TButton *Annuler;
        TMemo *Memo1;
        void __fastcall AnnulerClick(TObject *Sender);
        void __fastcall btYesClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TRenum(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRenum *Renum;
//---------------------------------------------------------------------------
#endif
