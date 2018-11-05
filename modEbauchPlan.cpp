//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modEbauchPlan.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEbauchePlan *EbauchePlan;
//---------------------------------------------------------------------------
__fastcall TEbauchePlan::TEbauchePlan(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
