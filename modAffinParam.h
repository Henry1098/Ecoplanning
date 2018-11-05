//---------------------------------------------------------------------------

#ifndef modAffinParamH
#define modAffinParamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAffineParam : public TForm
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
        TButton *Button10;
        TButton *Button11;
private:	// User declarations
public:		// User declarations
        __fastcall TAffineParam(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAffineParam *AffineParam;
//---------------------------------------------------------------------------
#endif
