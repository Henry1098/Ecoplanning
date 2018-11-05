//---------------------------------------------------------------------------

#ifndef copytaskH
#define copytaskH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <stdio.h>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TCopy : public TForm
{
__published:	// IDE-managed Components
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label1;
        TEdit *Edit1;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TUpDown *UpDown1;
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TCopy(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCopy *Copy;
//---------------------------------------------------------------------------
#endif
