//---------------------------------------------------------------------------

#ifndef modXLSH
#define modXLSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TTableCSV : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *AdvE;
        TEdit *Edit1;
        TEdit *Edit2;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        void __fastcall AdvECanEditCell(TObject *Sender, int ARow,
          int ACol, bool &CanEdit);
        void __fastcall AdvEGetEditorType(TObject *Sender, int ACol,
          int ARow, TEditorType &AEditor);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TTableCSV(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTableCSV *TableCSV;
//---------------------------------------------------------------------------
#endif
