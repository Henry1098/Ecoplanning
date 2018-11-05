//---------------------------------------------------------------------------

#ifndef modPiedH
#define modPiedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFDpied : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label1;
        TImage *imFColor;
        TLabel *Label2;
        TImage *imBColor;
        TLabel *Label3;
        TAdvStringGrid *avl;
        TEdit *Edit1;
        TButton *btBackGround;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TLabel *Label4;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall avlClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall btBackGroundClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations

        int OldCol,OldRow;


        void __fastcall FillColor(int color,TImage *im);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        void __fastcall FillData(int ind);
        void __fastcall FillGrid(int ind);

public:		// User declarations
        __fastcall TFDpied(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDpied *FDpied;
//---------------------------------------------------------------------------
#endif
