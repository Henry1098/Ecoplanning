//---------------------------------------------------------------------------

#ifndef modTcolH
#define modTcolH
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
class TFDTcol : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TImage *imFColor;
        TLabel *Label2;
        TImage *imBColor;
        TLabel *Label3;
        TAdvStringGrid *avl;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label15;
        TLabel *Label16;
        TImage *imLSep;
        TImage *imLVert;
        TCheckBox *cbLSepNiv;
        TCheckBox *cbLVert;
        TLabel *Label11;
        TLabel *Label14;
        TLabel *Label18;
        TEdit *Edit5;
        TEdit *Edit6;
        void __fastcall avlClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall Edit4Click(TObject *Sender);
        void __fastcall Edit1Click(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Edit5Click(TObject *Sender);
        void __fastcall Edit6Click(TObject *Sender);
private:	// User declarations


        void __fastcall FillColor(int color,TImage *im);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TFDTcol(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDTcol *FDTcol;
//---------------------------------------------------------------------------
#endif
