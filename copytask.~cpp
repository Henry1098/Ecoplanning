//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "copytask.h"
#include "globals.h"
#include "modHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCopy *Copy;
//---------------------------------------------------------------------------
__fastcall TCopy::TCopy(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TCopy::CheckBox1Click(TObject *Sender)
{
/*
if (CheckBox1->Checked == true)
   {
    //CheckBox1->Checked= false;
    GroupBox1->Enabled=true;
    RadioButton1->Enabled=true;
    RadioButton2->Enabled=true;
    RadioButton3->Enabled=true;
    Label1->Enabled=true;
    Edit1->Enabled=true;
    }
 else
   {
    //CheckBox1->Checked= true;
    GroupBox1->Enabled=false;
    RadioButton1->Enabled=false;
    RadioButton2->Enabled=false;
    RadioButton3->Enabled=false;
    Label1->Enabled=false;
    Edit1->Enabled=false;
    }
 */   
}
//---------------------------------------------------------------------------


void __fastcall TCopy::Button1Click(TObject *Sender)
{
char tmp[100],tmp1[10];
int dec;

strcpy(m_exchange,"");

  if (CheckBox1->Checked == true)
    {
     strcpy(m_exchange,"<cascade>T</cascade>");
     strcpy(tmp1,Edit1->Text.c_str()); dec=atoi(tmp1);
     sprintf(tmp,"<decalage>%d</decalage>",dec);
     strcat(m_exchange,tmp);
     if (RadioButton1->Checked == true) strcat(m_exchange,"<tl>0</tl>");
     if (RadioButton2->Checked == true) strcat(m_exchange,"<tl>1</tl>");
     if (RadioButton3->Checked == true) strcat(m_exchange,"<tl>2</tl>");
    }
   else  strcpy(m_exchange,"<cascade>F</cascade>");
   if (CheckBox2->Checked == true) strcat(m_exchange,"<old>T</old>");
                              else strcat(m_exchange,"<old>F</old>");
   if (CheckBox3->Checked == true) strcat(m_exchange,"<new>T</new>");
                              else strcat(m_exchange,"<new>F</new>");


  Close();
}
//---------------------------------------------------------------------------

void __fastcall TCopy::Button2Click(TObject *Sender)
{
 char tmp[10];
 m_exchange[0]=0;
 strcpy(m_exchange,"<null>TRUE</null>");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TCopy::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
 int decal;
 decal = atoi(Edit1->Text.c_str());
 if (Button == Comctrls::btNext)
   {
    decal++;
   }
 else
   { decal--;
     if (decal < 0) decal=0;
   }
 Edit1->Text = IntToStr(decal);
}
//---------------------------------------------------------------------------

void __fastcall TCopy::Button3Click(TObject *Sender)
{
 Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre52");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TCopy::FormShow(TObject *Sender)
{
   CheckBox1->Checked= false;
    GroupBox1->Enabled=true;
    RadioButton1->Enabled=true;
    RadioButton2->Enabled=true;
    RadioButton3->Enabled=true;
    Label1->Enabled=true;
    Edit1->Enabled=true;
    RadioButton1->Checked=true;
}
//---------------------------------------------------------------------------

