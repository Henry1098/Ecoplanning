//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "modExcel.h"
#include<utilcls.h>
#include <vcl\comobj.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Excel_97_SRVR"
#pragma resource "*.dfm"

TFExcel *FExcel;
//---------------------------------------------------------------------------
__fastcall TFExcel::TFExcel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFExcel::FormCreate(TObject *Sender)
{
/*
Put an OleContainer in it, call it OleContainer1.
Put also a TExcelApplication, call it xlsAp.
Put a TExcelWorkbook. Call it xlsWB.
Put a TExcelWorksheet. Call it xlsWS.

Put an edit and button to open a file.
*/
}
//---------------------------------------------------------------------------
void __fastcall TFExcel::Button1Click(TObject *Sender)
{

 int lcid;
 int K, R, X, Y;
 Variant RangeMatrix;
 AnsiString emptyParam;
/*

 OleContainer1->CreateLinkToFile("test.xls",false);
 // { No need to start Excel ourselves, since the ExcelApplication's AutoConnect
 //   property is True }
  lcid = GetUserDefaultLCID();
  xlsApp->Visible[lcid]=true;



    // Excel öffnen
    lcid = GetUserDefaultLCID();

    //xlsApp = TExcelApplication->Create();
    xlsApp->Connect();

    emptyParam="";
    // Exceldatei laden (test.xls)

    xlsWB = xlsApp->Workbooks->Open("test.xls", emptyParam, emptyParam,
          emptyParam, emptyParam, emptyParam, emptyParam, emptyParam,
          emptyParam, emptyParam, emptyParam, emptyParam, emptyParam,
          lcid);

    // erstes Worksheet auswählen
    ws := wb.Sheets[1] as _WorkSheet;

    ShowMessage(ws.Cells.Item[1,a].value);  //Fehlermeldung "a" undefinierter Bezeichner
    */
}
//---------------------------------------------------------------------------
void __fastcall TFExcel::Button2Click(TObject *Sender)
{
TExcelApplication *Excel;


TExcelWorksheet *ExcelWS = new TExcelWorksheet(this);
TExcelWorkbook *ExcelWB = new TExcelWorkbook(this);
/*
Excel->Connect();
Excel->Workbooks->Add(EmptyParam,LOCALE_USER_DEFAULT);
Excel->set_SheetsInNewWorkbook(LOCALE_USER_DEFAULT, 1);
ExcelWB->ConnectTo(Excel->ActiveWorkbook);
ExcelWS->ConnectTo(Excel->ActiveSheet);

// Filling Workbook... OK

// Saving file... OK

// OK,now break all connections with Excel

Excel->set_Visible(LOCALE_USER_DEFAULT,xlSheetVisible);
Excel->set_UserControl(true);
ExcelWS->Disconnect();
ExcelWB->Disconnect();
delete ExcelWS;
delete ExcelWB;
Excel->Disconnect();
*/
}
//---------------------------------------------------------------------------
void __fastcall TFExcel::Button3Click(TObject *Sender)
{
  OleVariant Template = EmptyParam;
  OleVariant NewTemplate = False;
  OleVariant ItemIndex = 1;

  try
  {
    try
      {
        xlsApp->Connect();
      }
    catch (Exception &exception)
      {
        MessageDlg("Excel may not be installed", mtError, TMsgDlgButtons() << mbYes, 0);
        Abort;
      }
    //xlsApp->Visible = True;
    xlsApp->Caption = StringToOleStr("Borland automation");
    //Create new document
/*
    if (ChkBoxNewDoc->Checked)
    {
      WordApplication->Documents->Add(Template, NewTemplate);
      //Assign WordDocument component
      WordDocument->ConnectTo(WordApplication->Documents->Item(ItemIndex));
    }
    //Turn Spell checking off because it takes a long time if enabled and slows down Winword
    WordApplication->Options->CheckSpellingAsYouType = False;
    WordApplication->Options->CheckGrammarAsYouType = False;
    //Insert data
    DBImgFishImg->CopyToClipboard();
    WordDocument->Sentences->Last->Paste();
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("Common Name: " + Table->Fields->Fields[2]->AsString + '\n'));
    SetFont();
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("Species Name:" + Table->Fields->Fields[3]->AsString + '\n'));
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("Length: " + Table->Fields->Fields[4]->AsString + '\n'));
    WordDocument->Range(EmptyParam, EmptyParam)->InsertAfter(StringToOleStr("===\n"));
    btnCloseWord->Enabled = True;
    btnPrint->Enabled = True;
    btnPreview->Enabled = True;
*/
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
    xlsApp->Disconnect();
  }

}
//---------------------------------------------------------------------------
void __fastcall TFExcel::Button4Click(TObject *Sender)
{
   Variant V;

     V = CreateOleObject("Excel.Basic");
     V.Exec(Procedure("AppShow"));
     V.Exec(Procedure("FileNew") << "Normal");
     V.Exec(Procedure("Insert") << "Hello from Borland");

}
//---------------------------------------------------------------------------

void __fastcall TFExcel::Button5Click(TObject *Sender)
{
  Variant XL;
  XL = XL.CreateObject("Excel.Application");
  //CASE 1: You have to create a new excel file then write your output there
//declare variables
Variant v0,v1,v2,v3;
double x=3.14;

//open excel application
XL=Variant::CreateObject("excel.application");

//set the application as invisible, you can reverse "false" to "true" to make it visible
XL.OlePropertySet("Visible",false);

//Get workbook
v0=XL.OlePropertyGet("Workbooks");

//add one work book
v0.OleProcedure("Add");

//select workbook number 1
v1=v0.OlePropertyGet("Item",1);

//Get worksheet
v2=v1.OlePropertyGet("WorkSheets");

// add one work sheet
v2.OleFunction("Add");

//select worksheet number 1
v3=v2.OlePropertyGet("Item",1);


//rename worksheet it to "example1"
v3.OlePropertySet("Name","example1");

// at last, write your output at row 2 column 3
char temp[10];
sprintf(temp,"%lf",x);
v3.OlePropertyGet("Cells").OlePropertyGet("Item",2,3).OlePropertySet("Value",temp);

//this will stop asking you where you want to same your excel file or not
XL.OlePropertySet("DisplayAlerts",false);

//save your excel file at "d" and name it as "case1.xls"
XL.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs","d:\\case1.xls");

//Close the work book
v1.OleProcedure("Close");

//quite the excel application
XL.OleProcedure("Quit");

//unassign variable
XL=Unassigned;

/*
CASE 2: You want to write your output in an existing excel file named "case1.xls" located at "D:"

double x=3.14;
//declare variables
Variant XL,v0,v1,v2,v3;

//open excel application
XL=Variant::CreateObject("excel.application");

//set the application as invisible, you can reverse "false" to "true" to make it visible
XL.OlePropertySet("Visible",false);

//open the workbook "named case1.xls"
XL.OlePropertyGet("Workbooks").OleProcedure("Open","d:\\case1.xls");

//open the worksheet "example1"
v0=XL.OlePropertyGet("Sheets","example1");

//get a cell
v1=v0.OlePropertyGet("Cells");

// at last, write your output at row 2 column 3
char temp[10];
sprintf(temp,"%lf",x);
v1.OlePropertyGet("Item",2,3).OlePropertySet("Value",temp);

//this will stop asking you where you want to same your excel file or not
XL.OlePropertySet("DisplayAlerts",false);

//save what you have done
XL.OleProcedure("Save");

//quite the excel application
XL.OleProcedure("Quit");

//unassign variable
XL=Unassigned;
*/
//That's it. Though long, the procedure is still standard and simple.

}
//---------------------------------------------------------------------------

