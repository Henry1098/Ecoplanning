//---------------------------------------------------------------------------

#ifndef modAffSuccH
#define modAffSuccH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAffSucc : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TButton *Button3;
        TEdit *Edit1;
        TRadioGroup *RadioGroup1;
        TRadioButton *rb1;
        TRadioButton *rb2;
        TRadioButton *rb3;
        TLabel *Label2;
        TEdit *Edit2;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAffSucc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAffSucc *AffSucc;
//---------------------------------------------------------------------------
#endif
