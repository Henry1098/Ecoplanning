//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Choix.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int choix;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(RadioButton1->Checked == true)
    {
        choix = 1;
    }

    if(RadioButton2->Checked == true)
    {
        choix = 2;
    }

    if(RadioButton3->Checked == true)
    {
        choix =3;
    }
    Close();
}
//---------------------------------------------------------------------------
