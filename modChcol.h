//---------------------------------------------------------------------------

#ifndef modChcolH
#define modChcolH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TChCol : public TForm
{
__published:	// IDE-managed Components
        TListBox *lbTout;
        TListBox *lbSel;
        TBitBtn *btRight;
        TBitBtn *btLeft;
        TBitBtn *btUp;
        TBitBtn *btDown;
        TLabel *Label1;
        TLabel *Label2;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        TLabel *Label3;
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btRightClick(TObject *Sender);
        void __fastcall btLeftClick(TObject *Sender);
        void __fastcall btUpClick(TObject *Sender);
        void __fastcall btDownClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations
        char cnt[200][100];
        char abb[200][100];
        char cln[200][100];

        char params[50][200];

        //char codcriter[10][100];
        //char c[100],c1[50],c2[50],c3[50],c4[50],des[100];

        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        int __fastcall Explode(char sep,char *str);
        void __fastcall Strip(char *s);

public:		// User declarations
        __fastcall TChCol(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChCol *ChCol;
//---------------------------------------------------------------------------
#endif
