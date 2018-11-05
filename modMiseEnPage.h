//---------------------------------------------------------------------------

#ifndef modMiseEnPageH
#define modMiseEnPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TMiseEnPage : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *ar;
        TButton *btOK;
        TButton *btSuppr;
        TButton *btAnnul;
        TButton *btInserer;
        TButton *btAide;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall btAnnulClick(TObject *Sender);
        void __fastcall btSupprClick(TObject *Sender);
        void __fastcall btInsererClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMiseEnPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMiseEnPage *MiseEnPage;
//---------------------------------------------------------------------------
#endif
