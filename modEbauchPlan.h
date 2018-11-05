//---------------------------------------------------------------------------

#ifndef modEbauchPlanH
#define modEbauchPlanH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TEbauchePlan : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label2;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
private:	// User declarations
public:		// User declarations
        __fastcall TEbauchePlan(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEbauchePlan *EbauchePlan;
//---------------------------------------------------------------------------
#endif
