//---------------------------------------------------------------------------

#ifndef modRetraitH
#define modRetraitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TRetrait : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations

        char Mem[50];
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TRetrait(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRetrait *Retrait;
//---------------------------------------------------------------------------
#endif
