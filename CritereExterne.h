//---------------------------------------------------------------------------

#ifndef CritereExterneH
#define CritereExterneH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *asCrit;
        TButton *btEraseCrit;
        TButton *btCrit1;
        TButton *btCrit2;
        TButton *btCrit3;
        TButton *btCrit4;
        TButton *btSaveAffect;
        TButton *btAccCrit;
        TButton *btAideCrit;
        TBevel *Bevel1;
        TLabel *Label73;
        TLabel *Label72;
        TLabel *Label8;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        void __fastcall asCritCanEditCell(TObject *Sender, int ARow,
          int ACol, bool &CanEdit);
        void __fastcall asCritClickCell(TObject *Sender, int ARow,
          int ACol);
        void __fastcall btAccCritClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
