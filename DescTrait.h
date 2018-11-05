//---------------------------------------------------------------------------

#ifndef DescTraitH
#define DescTraitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFDTrait : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TImage *Image1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TComboBox *ComboBox1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TColorDialog *ColorDialog1;
        TLabel *Label4;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
        TColor cool;

   void __fastcall FillColor(int color,TImage *im);

public:		// User declarations
        __fastcall TFDTrait(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDTrait *FDTrait;
//---------------------------------------------------------------------------
#endif
