//---------------------------------------------------------------------------

#ifndef modHauteurH
#define modHauteurH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class THauteur : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TButton *btOK;
        TButton *btAnnul;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
private:	// User declarations
        char Mem[250];
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
public:		// User declarations
        __fastcall THauteur(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THauteur *Hauteur;
//---------------------------------------------------------------------------
#endif
