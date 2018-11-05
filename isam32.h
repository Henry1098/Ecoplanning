// ====ISAM32.H  Version 2.1  October 1998 =====
// Copyright Jean-Louis M Gouin
// Depending of your compiler and
// the options you selected, you can
// remove one or more #include
// =====================================
//  ISAM32_H

#ifndef __ISAM32_H
#define __ISAM32_H

//#include <stdio.h>
//#include <stdlib.h>
//#include <dir.h>



#ifdef __cplusplus
extern "C" {
#endif

class _export genbase
{

 public:

  genbase(void);
 ~genbase(void);
 int  OpenEngine(char *FileName,short BlockSize,char *ndx, char*dat);
 int  CloseEngine(void);
 int  SetIndexMode(short Index, short Value);
 int  WriteRecord(char *pdata,int len);
 int  RewriteRecord(char *pdata,int len, int RecNumber);
 int  DeleteRecord(int RecNumber);
 int  ReadRecord(char *pdata,int RecNumber);
 int  GetNewRecordNumber();
 int  WriteKey(short Index,char *Key,int RecNumber);
 int  DeleteKey(short Index,char *Key,int RecNumber);
 int  ReadFirstKey(short Index,char *ReturnKey,int *RecNumber);
 int  ReadNextKey(char *ReturnKey ,int *RecNumber);
 int  ReadLastKey(short Index,char *ReturnKey,int *RecNumber);
 int  ReadPrevKey(char *ReturnKey ,int *RecNumber);
 int  ReadDirectKey(short Index,char *Key, char *ReturnKey, int *RecNumber);
 int  NumberOfKeys(short Index);
 int  RecordLength(int RecNumber);
 int  Version(void);
};

#ifdef __cplusplus
}
#endif

#endif