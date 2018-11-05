//---------------------------------------------------------------------------

#ifndef modTriElemH
#define modTriElemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TTriCrit : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TMemo *mDesc;
        TLabel *Label3;
        TListBox *lbTout;
        TBitBtn *btRight;
        TBitBtn *btLeft;
        TListBox *lbSel;
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        TBitBtn *btUp;
        TBitBtn *btDown;
        TBitBtn *btOrder;
        TLabel *Label4;
        TLabel *Label1;
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btRightClick(TObject *Sender);
        void __fastcall btLeftClick(TObject *Sender);
        void __fastcall btUpClick(TObject *Sender);
        void __fastcall btDownClick(TObject *Sender);
        void __fastcall btOrderClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations

        char cnt[200][10];
        char abb[200][10];
        char cln[200][10];
        
        char params[50][100];

        char codcriter[10][100];
        char c[100],c1[50],c2[50],c3[50],c4[50],des[100];

        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        int __fastcall Explode(char sep,char *str);
        void __fastcall Strip(char *s);
        
         
public:		// User declarations
        __fastcall TTriCrit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTriCrit *TriCrit;
//---------------------------------------------------------------------------
#endif
