//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modResProj.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResProj *ResProj;
//---------------------------------------------------------------------------
__fastcall TResProj::TResProj(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------