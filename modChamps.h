//---------------------------------------------------------------------------

#ifndef modChampsH
#define modChampsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TChamps : public TForm
{
__published:	// IDE-managed Components
        TListBox *lbChamps;
        TListBox *lbRelation;
        TEdit *eDe;
        TEdit *eA;
        TListBox *lbAction;
        TLabel *Label1;
        TLabel *Label2;
        TButton *btExec;
        TButton *btCancel;
        TButton *btHelp;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btExecClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btCancelClick(TObject *Sender);
        void __fastcall btHelpClick(TObject *Sender);
        void __fastcall lbRelationClick(TObject *Sender);
private:	// User declarations
        char champ[150];
        char oper[50];
        char val1[150];
        char val2[150];
        char action[50];

        char c1[50],c2[50],c3[50],c4[50],des[100];

        char cnt[200][10];
        char abb[200][10];
        char cln[200][10];

        char ecoplan[250];

        int __fastcall Control();
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TChamps(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChamps *Champs;
//---------------------------------------------------------------------------
#endif
