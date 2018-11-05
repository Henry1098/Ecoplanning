//---------------------------------------------------------------------------

#ifndef modUnitFormH
#define modUnitFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFDUnitForm : public TForm
{
__published:	// IDE-managed Components
        TComboBox *cbUnit;
        TLabel *Label1;
        TComboBox *cbForm;
        TLabel *Label2;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        void __fastcall cbUnitClick(TObject *Sender);
        void __fastcall cbFormClick(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations
        AnsiString format;
        AnsiString unite;

        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        int __fastcall Load_cb(AnsiString Unt);
public:		// User declarations
        __fastcall TFDUnitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDUnitForm *FDUnitForm;
//---------------------------------------------------------------------------
#endif
