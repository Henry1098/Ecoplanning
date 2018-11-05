#ifndef __MODTSLISAM_H
#define __MODTSLISAM_H


class TSLIsam
{




 #define MAX_DATA  65000

 private:

   TStringList   *TSL;
   int           CurrentPointer;
   char          DBLockKey[200];
   char          databuf[100000];  // max 64 K ??
   char          recordbuf[100000];

   AnsiString    Index[256];


   bool __fastcall Locked(AnsiString S,char *lk);
   AnsiString __fastcall IsRecordLocked(char *Key);
   int __fastcall  ExtractValue(char *result, char *buff, char *tag, int posdeb);
   void __fastcall Remove_CRLF(char *text);
   void __fastcall Insert_CRLF(char *text);
   void __fastcall Update_Index(char *Key,char OP);
   AnsiString __fastcall GoUP(AnsiString SK,int idx);


  public:
  TSLIsam(bool dup);
 ~TSLIsam(void);
 int  OpenEngine(char *FileName,char *lockkey);
 int  CloseEngine(char *FileName,char *lockkey);
 int  WriteRecord(char *pdata,char *Key,char *lockkey);
 int  DeleteRecord(char *Key,char *lockkey);
 int  ReadRecord(char *pdata,char *Key, char *RetKey,char *lockkey);
 int  ReadFirstKey(char *pdata, char *RetKey,char *lockkey);
 int  ReadNextKey(char *pdata,char *ReturnKey,char *lockkey);
 int  ReadLastKey(char *pdata,char *ReturnKey,char *lockkey);
 int  ReadPrevKey(char *pdata,char *ReturnKey,char *lockkey);
 int  GetNextKey(char *ReturnKey);
 int  NumberOfKeys();
 int  RecordLength(char *Key,char *lockkey);
 int  Version(char *p);
 int  LockRecord(char *RecKey, char *lockkey);
 int  UnlockRecord(char *RecKey, char *lockkey);
 int  LockDB(char *lockkey);
 int  UnlockDB(char *lockkey);
 int  GetIndexValue(int i, char *ind);

};

#endif