//---------------------------------------------------------------------------

#ifndef modResumeH
#define modResumeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TResume : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Edit1;
        TMemo *Memo1;
        TLabel *Label7;
        TLabel *Label8;
        TComboBox *ComboBox1;
        TLabel *Label9;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        TLabel *Label10;
        TButton *btCriteres;
        TButton *btResources;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *lnbtACT;
        TLabel *lnbT;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TLabel *Label40;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btCriteresClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TResume(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResume *Resume;
//---------------------------------------------------------------------------
#endif
