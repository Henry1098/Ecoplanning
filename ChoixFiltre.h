//---------------------------------------------------------------------------

#ifndef ChoixFiltreH
#define ChoixFiltreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TChoix : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button4;
        TButton *Button5;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TChoix(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChoix *Choix;
//---------------------------------------------------------------------------
#endif
