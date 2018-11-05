//---------------------------------------------------------------------------

#ifndef modRemplH
#define modRemplH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TRemplTC : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *eMask;
        TLabel *Label3;
        TEdit *eMot;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TRemplTC(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRemplTC *RemplTC;
//---------------------------------------------------------------------------
#endif
