//---------------------------------------------------------------------------

#ifndef modeCadreH
#define modeCadreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCadre : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button1;
        TComboBox *cbEpaiss;
        TLabel *Label2;
        TColorDialog *ColorDialog1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TEdit *Edit1;
        TImage *Image1;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
        float __fastcall AnsiToFloat(AnsiString str);
        void __fastcall FillColor(int color,TImage *im);
public:		// User declarations
        __fastcall TCadre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCadre *Cadre;
//---------------------------------------------------------------------------
#endif
