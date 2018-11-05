//---------------------------------------------------------------------------

#ifndef modAffTCH
#define modAffTCH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAffData : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *eVal;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TListBox *ListBox1;
        TLabel *Label3;
        TLabel *lChamp;
        TListBox *ListBox2;
        TLabel *Label4;
        TLabel *Label5;
        TCheckBox *CheckBox1;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        int  cln[200];
        int  Col;
        char LCrit[10][100];
        char Champs[200][150];
        int  Ccount;

        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        int __fastcall RechCol(char *des);
        int __fastcall RechColCrit(char *cod);

public:		// User declarations
        __fastcall TAffData(TComponent* Owner);
AnsiString var;
        };
//---------------------------------------------------------------------------
extern PACKAGE TAffData *AffData;
//---------------------------------------------------------------------------
#endif
