//---------------------------------------------------------------------------

#ifndef modTachesH
#define modTachesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFDtaches : public TForm
{
__published:	// IDE-managed Components
        TButton *btOK;
        TButton *btAnnul;
        TButton *btAide;
        TComboBox *cbTache;
        TAdvStringGrid *avt;
        TImage *imFColor;
        TLabel *Label2;
        TLabel *Label3;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TImage *imBColor;
        TLabel *Label4;
        TAdvStringGrid *avv;
        TImage *imTrait;
        TLabel *Label1;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TImage *imMarge;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall avtClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall cbTacheClick(TObject *Sender);
        void __fastcall avvClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations

        int OldRow,OldCol;
        char params[50][100];
        int  indice;

        
        void __fastcall CStrip(char *s);
        int __fastcall Explode(char sep,char *str);
        void __fastcall Display(int indx);
        void __fastcall FillColor(int color,TImage *im);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TFDtaches(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDtaches *FDtaches;
//---------------------------------------------------------------------------
#endif
