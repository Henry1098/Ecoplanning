//---------------------------------------------------------------------------

#ifndef num_predH
#define num_predH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TNum_Tache_Pred : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TEdit *Edit1;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TLabel *Label2;
        TEdit *Edit2;
        TUpDown *UpDown1;
        TButton *Button3;
        TRadioButton *RadioButton4;
        TLabel *Label3;
        TLabel *Label4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNum_Tache_Pred(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNum_Tache_Pred *Num_Tache_Pred;

//---------------------------------------------------------------------------
#endif
