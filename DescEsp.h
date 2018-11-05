//---------------------------------------------------------------------------

#ifndef DescEspH
#define DescEspH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFDEspace : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TImage *Image1;
        TLabel *Label2;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TColorDialog *ColorDialog1;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
        TColor cool;

   void __fastcall FillColor(int color,TImage *im);
public:		// User declarations
        __fastcall TFDEspace(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDEspace *FDEspace;
//---------------------------------------------------------------------------
#endif
