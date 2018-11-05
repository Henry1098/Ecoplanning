//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "globals.h"
#include <stdio.h>
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent *Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------
void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
 char tmp[MAX_PATH],fname[MAX_PATH];
 AnsiString Dir;

Dir = GetCurrentDir();

strcpy(fname,Dir.c_str()); strcat(fname,"\\Ecoplanning.exe");

/*
LPTSTR lpszFilePath = fname;  // (WideString)FN;

DWORD dwDummy;
DWORD dwFVISize = GetFileVersionInfoSize( lpszFilePath , &dwDummy );
LPBYTE lpVersionInfo = new BYTE[dwFVISize];
GetFileVersionInfo( lpszFilePath , 0 , dwFVISize , lpVersionInfo );
UINT uLen;
VS_FIXEDFILEINFO *lpFfi;
VerQueryValue( lpVersionInfo , _T("\\") , (LPVOID *)&lpFfi , &uLen );
DWORD dwFileVersionMS = lpFfi->dwFileVersionMS;
DWORD dwFileVersionLS = lpFfi->dwFileVersionLS;
delete [] lpVersionInfo;
//printf( "Higher: %x\n" , dwFileVersionMS );
//printf( "Lower: %x\n" , dwFileVersionLS );
DWORD dwLeftMost = HIWORD(dwFileVersionMS);
DWORD dwSecondLeft = LOWORD(dwFileVersionMS);
DWORD dwSecondRight = HIWORD(dwFileVersionLS);
DWORD dwRightMost = LOWORD(dwFileVersionLS);
sprintf(tmp,"Version: %d.%d.%d.%d\n" , dwLeftMost, dwSecondLeft,
dwSecondRight, dwRightMost );
*/
Label1->Caption = "Version 5.0.0.1850";  // AnsiString(tmp);

}
//---------------------------------------------------------------------------

