//---------------------------------------------------------------------------

#ifndef modColonnesH
#define modColonnesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include "AdvGrid.h"
//#include "BaseGrid.h"
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include "globals.h"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *AdvE;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall AdvECanEditCell(TObject *Sender, int ARow,
          int ACol, bool &CanEdit);
        void __fastcall AdvEGetEditorType(TObject *Sender, int ACol,
          int ARow, TEditorType &AEditor);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
