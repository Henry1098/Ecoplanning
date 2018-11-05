
              //---------------------------------------------------------------------------

#include <windows.h>
#include <stdio.h>
//   REALISAM MODULE TO BE INCLUDED IN FINAL HELP

// ROOT DESCIPTION   // size 1024
//  ADDR   LEN   VAR
//  0      4     nai    Next available index
//  4      4     fli    First linked index record

//  8      4     root for index 0
//  12     4     root for index 1
//  16     4     root for index 2
//  start address for root = index*4 + 8

//  384    n     attr multikey index 0,1,2,3,...
//  512    4     nkey1  number of key for ain0
//  516    4     nkey2  number of key for ain1

// INDEX32 DESCRIPTION  // size 1024
//  ADDR   LEN   VAR
//  0      2     nkey   Number of key in this index
//  2      2     position Key1
//  4      2     position Key2
//  6      2     position Keyn
//  ......
//  x1     2     ptrbeg  = pointer where linkage (left,above,right) start
//  x2     4     ao      = ptr
//  x3     kl1   Key1 + 4 byte for data1 record pointer
//  x4     kl2   Key2 + 4 bytes pointer
//  xnn    kln   Keyn + 4 bytes pointer

//  x10    4     left pointer
//  x10+4  4     above pointer
//  x10+8  4     right pointer
//  filler


#define Lgr_Index       1024    /* length of an index record    */
#define Nb_Index        64      /* maximum number of indexes    */
#define Cle_Max         250     /* buffer size for key + \0     */
#define Hauteur         20      /* maximum Hauteur of tree       */
#define RECORD_ADDR     4       /* bytes needed to store tiebrk */
#define MODE_READ       "r+b"
#define MODE_WRITE      "w+b"



class isam
{
    public:
    isam();
    ~isam();


     short  Lire( short Index,char *Key,int *DataRec,char  *RKey);
     short  Ecrire( short Index,char *Key,int RecNumber);   //,int *DataRec);
     short  Suivante(char *RKey, int *DataRec);
     short  Precedente(char *RKey, int *DataRec);
     short  Effacer( short Index,char *Key,int delrec);
     short  Premiere( short Index,char *RKey,int *DataRec);
     short  Derniere( short Index,char *RKey, int *DataRec);
     short  Ouvrir(char *FileName);
     short  Fermer(void);
     short  Multi( short Index, short value);
     int    Cles( short Index);
     int    DumpIndex(char *pindex,int ndx);
     int    GetMode(int ndx);
     int    DeleteIndex(char *filename);
     int    FermeReouvre(char *filename);

     int CIN;  // Current Index;

     //int Global_Token;
     //LList list;



    private:

    char nom[MAX_PATH];

    short erreur, compteur;
    char Temp_Key[Cle_Max + 1];

    char abuf[Lgr_Index+100],
	 abuft[Lgr_Index+100],
	 abufl[Lgr_Index+100],
	 abufr[Lgr_Index+100];
    int Prochain_Libre, Lien, P_Suiv, P_Gauche, P_Droit, Sommet[Nb_Index];
    int nbkey[Nb_Index];
    short  Tmp_Lgr_Cle, Lgr_Cle;
    int Ptr_Sys, Ptr_G, Ptr_Haut, Ptr_D, Ptr_Left, Ptr_Droit, Pointeur, iorec, Ptr_Data;
    short  nkey, ptrbeg, ikn, ht, Resultat;
    char key[Cle_Max+6], Cle_Temp[Cle_Max+6], Cle_G[Cle_Max+6];
    short  Mode_Index[Nb_Index];
    int Prof_N[Hauteur], Prof[Hauteur];



    int  comptY,comptN;
    int  var32;
    FILE * findex;


    void  init_var();
    short inter(char index, char ops, char *ikey, int irec);
    void searchidx(char *ikey,  short index);
    void advance(void);
    void retreat(void);
    void getfirst( short index);
    void getlast( short index);
    void allocidx(void);
    void releaseidx(int recno);
    void allocroot( short index);
    void splitidx(char *buffer);
    void insert(char *ikey, int dp, char *buffer);
    void modkids(void);
    void deletex(char *buffer);
    void extract(char *buffer);
    void scan4key(char *buffer, char *Cle_Temp);
    void look4key(char *buffer, char *Cle_Temp);
    void decode(char *buffer);
    void encode(char *buffer);
    void readidx(int iorec, char *buffer);
    void writeidx(int iorec, char *buffer);
    void dupliquer(char *buffer, char *string,  short start,  short len);
    void remplir(char *buffer, char fill,  short len);
    short comparer(char *string1, char *string2,  short len);
    void append(char *buffer, int number);
    void deblank(char *buffer);
    void cherche(char index, char *ikey, int irec);


};




// *************************************************
//  ISAM::ISAM  CONSTRUCTOR
//  SET DEFAULT VALUES
// *************************************************

isam::isam()
{
 init_var();
}

// *************************************************
//  ISAM::~ISAM
// *************************************************

isam::~isam()
{
}

// ****************************************
//
// ****************************************

int isam::DeleteIndex(char *filename)
{
 fclose(findex);
 unlink(filename);
 return 1;
}


// ****************************************
//
// ****************************************
void isam::init_var()
{
short i;
 ////setmult = 1;
 /// multkey=0;
 for (i=0;i<Nb_Index;i++)
     { Sommet[i]=0;
       nbkey[i]=0;
       Mode_Index[i]=0; }
 //strcpy(( char *)nom,"");
 Resultat = 0;  erreur=0;compteur=0;
 Ptr_Data = 0;
 nkey = 0;
 ptrbeg=8;
 _fmemset(Temp_Key,0,Cle_Max);
 _fmemset(abuf,0,Lgr_Index);
 _fmemset(abuft,0,Lgr_Index);
 _fmemset(abufl,0,Lgr_Index);
 _fmemset(abufr,0,Lgr_Index);
 Prochain_Libre=0;Lien=0;P_Suiv=0;P_Gauche=0;P_Droit=0;
 Tmp_Lgr_Cle=0; Lgr_Cle=0;
 Ptr_Sys=0;Ptr_G=0;Ptr_Haut=0;Ptr_D=0; Ptr_Left=0; Ptr_Droit=0; Pointeur=0; iorec=0;Ptr_Data=0;
 nkey=0;ptrbeg=0; ikn=0; ht=0; Resultat=0;
 _fmemset (key,0,Cle_Max);
 _fmemset (Cle_Temp,0,Cle_Max);
 _fmemset (Cle_G,0,Cle_Max);
// _fmemset (Mode_Index,0,Nb_Index);
 for (i=0;i<Hauteur;i++)
     { Prof_N[i]=0;
       Prof[i]=0;
     }
 findex=NULL;
 CIN=0;
}

// *************************************
// ISAM::MULTI
// *************************************

short isam::Multi(short Index,short value)
{
 if ((Index < 0) || (Index>= Nb_Index)) return -1;
 if ((value < 0) || (value>1)) return -2;
 Mode_Index[Index]=value;  // ascii
 return 1;
}

// *************************************
//  ISAM::LIRE
// *************************************

short isam::Lire(short Index,char *Key,int *DataRec, char *Cle_Retournee)
{
 short rc;

 rc=inter(Index,'1',Key,0);       // 'G'
 if (rc<0) return rc;

 if (nbkey[Index]==0) Cle_Retournee[0]=0;
  else strcpy(Cle_Retournee,key);
 *DataRec = Ptr_Data;
 CIN = Index;
 return Resultat;
}


// *************************************
//  ISAM::ECRIRE
// *************************************

short isam::Ecrire(short Index,char *Key,int RNumber)     ///,int *DataRec)

{
 short rc;
 rc = inter(Index,'2',Key,RNumber);          // 'I'
 if (rc<0) return rc;
 //*DataRec = Ptr_Data;
 CIN = Index;
 return Resultat;
}

// *************************************
//  ISAM::NEXTKEY
// *************************************

short isam::Suivante(char *Cle_Retournee, int *DataRec)
{
 short rc;

 if (nbkey[CIN]==0)
    { Cle_Retournee[0]=0;
      *DataRec=0;
      Resultat=0;
      return -1;
    }

 rc=inter(0,'3',"",0);   // 'N'
 if (rc<0) return rc;
    strcpy(Cle_Retournee,key);
      *DataRec=Ptr_Data;
 //    Resultat=1;
 return Resultat;
}

// *************************************
//  ISAM::PRECEDENTE
// *************************************

short isam::Precedente(char *Cle_Retournee,int *DataRec)
{
 short rc;

 if (nbkey[CIN]==0)
    { Cle_Retournee[0]=0;
      *DataRec=0;
      Resultat=0;
      return -1;
    }


 rc=inter(0,'4',"",0);        // 'P'
 if (rc<0) return rc;
 strcpy(Cle_Retournee,key);
 *DataRec=Ptr_Data;
 Resultat=1;
 return Resultat;
}

// *************************************
//  ISAM::EFFACER
// *************************************

// delrec must be significant when index is multi-key

short isam::Effacer(short Index,char *Key,int delrec)
{
 short rc;
 rc = inter(Index,'5',Key,delrec);      // 'D'
 if (rc<0) return rc;
  //strcpy(Cle_Retournee,key);
  //*DataRec= Ptr_Data;
 CIN=Index;
 return Resultat;
}

// *************************************
//  ISAM::PREMIERE
// *************************************

short isam::Premiere(short Index,char *Cle_Retournee, int *DataRec)
{
 short rc;

 if (nbkey[Index]==0)
    { Cle_Retournee[0]=0;
      *DataRec=0;
      Resultat=0;
    }
  rc = inter(Index,'6',"",0);          // 'F'
  if (rc<0) return rc;
  strcpy(Cle_Retournee,key);
  *DataRec=Ptr_Data;
  Resultat=1;
 CIN=Index;
 return Resultat;
}

// *************************************
//  ISAM::LASTKEY
// *************************************

short isam::Derniere(short Index,char *Cle_Retournee,int *DataRec)
{
 short rc;

 if (nbkey[Index]==0)
     { Cle_Retournee[0]=0;
       *DataRec=0;
       Resultat=0;
     }
 rc = inter(Index,'7',"",0);             // 'L'
 if (rc<0) return rc;
 strcpy(Cle_Retournee,key);
 *DataRec=Ptr_Data;
 Resultat=1;
 CIN=Index;
 return Resultat;
}

// *************************************
//  ISAM::Ouvrir
// *************************************

 short isam::Ouvrir(char *FileName)
{
 short rc;
 strcpy(nom,FileName);
 rc = inter(0,'8',"",0);                // 'O'
 if (rc<0) return rc;
 CIN=0;
 return 1;

}

int  isam::FermeReouvre(char *filename)
{
 short rc;
 strcpy(nom,filename);
 rc = inter(0,'a',"",0);                // 'O'
 if (rc<0) return rc;
 CIN=0;
 return 1;
}

// *************************************
//  ISAM::Fermer
// *************************************

short isam::Fermer(void)
{
short rc;
rc = inter(0,'9',"",0);                // 'C'
if (rc<0) return 0;
return 1;
}

// *************************************
//  ISAM::CLES
// *************************************

int isam::Cles(short Index)
{
 if ((Index<0) || (Index >= Nb_Index)) return -1;
 return nbkey[Index];
}

// *************************************
// ISAM DUMP INDEX
//**************************************

int isam::DumpIndex(char *pindex,int ndx)
{
 int i,pos;
 if (ndx<0 || ndx>63) return 0;
 readidx(ndx,pindex);
 return 1;
}


// *************************************
// ISAM GETMODE
//**************************************

int isam::GetMode(int ndx)
{
 if (ndx < 0 || ndx>63)  return -1;
 return Mode_Index[ndx];
}

// *************************************
// ISAM DEBLANK
//**************************************
void isam::deblank(char *buffer)
{
 int l;
 l=strlen(buffer);
 while(buffer[l-1]==' ')
 {
  buffer[l-1]=0;
  l--;
 }
}

// *************************************
// ISAM CHERCHE
//**************************************

void isam::cherche(char index, char *ikey, int irec)
{
  bool ok;
  int MemPtr;
  int noavanc;

    searchidx(ikey, index);
    /*
    if (Resultat != 1)
	   {
             if (ikn > nkey)
	       { ikn = nkey; advance();
		 Resultat = 0; extract(abuf);
	       }
	      else extract(abuf);
           }
    Ptr_Data = Ptr_Droit;
    return;
    */
	 if (Resultat != 1)
	   {
            if (Mode_Index[index]==0)
             {
             if (ikn > nkey)
              { ikn = nkey;
                advance();
                Resultat = 0;
                extract(abuf);
              }
	      else extract(abuf);
             }
            else // ModeIndex=1
             {
              if (nbkey[index]==1)
                {
                 if (ikn > nkey)
	         {
                  ikn = nkey;
                  advance();
		   Resultat = 0; extract(abuf);
	          }  else extract(abuf);
                return;
                }

              retreat();
              ok=false;

              noavanc=0;
              if (strcmp(ikey,key)==0)
               {
                ok=true;  MemPtr=Ptr_Data;
                if (Ptr_Data >2)
                {
                while(ok)
                   {
                     retreat();
                     if (strcmp(ikey,key)==0) ok=true;
                     else ok=false;
                     if (MemPtr==Ptr_Data) { ok=false; noavanc=1; }
                    }
                }
               }
              if (!noavanc)
                advance();
              if (strcmp(ikey,key)==0)
              Resultat=1;
              else Resultat=0;
              erreur=0;
             }
	   }
	 Ptr_Data = Ptr_Droit;
}


// *******************************
//  INTER  $$$$
// *******************************

// Error Code
//   0   OK
//  -2   Index out of range
//  -3   Release index with no root
//  -1   Failed to create
//  -1    Open error
//  -10   Syntax error

short isam::inter(char index, char ops, char *ikey, int irec)
{
 short er;
 short compteur;
 int taille;
 short tiebrk = 0;
 int pos;  bool ok;
 int MemPtr;
 int x;

 erreur = 0;
 if (index>=Nb_Index) return -2;
 key[0] = 0;
 remplir(Cle_Temp, 0, Cle_Max);
 strcpy(Temp_Key, ikey);
 deblank(ikey);
 Tmp_Lgr_Cle =(short) strlen(ikey);

 if (Mode_Index[index] == 1)  // ascii 1
    { append(ikey, irec);  // $$$$
      Tmp_Lgr_Cle += (short) RECORD_ADDR;
      tiebrk=1;
    }

 switch (ops)
   {
    case '1':       /* Get a key from index         */

         cherche(index,ikey,irec);
	 break;

    case '2':       /* Insert key , insert rec        */
	  searchidx(ikey, index);
         //Cherche(index,ikey,irec);
	 if (Resultat == 1 && Mode_Index[index]==0) { erreur = 1; break; }

         // Resultat is 1 if Multi !

	 // Compute space  ptrbeg + left + above + right -1 ==> 11
	 // strlen(ikey) + 4 for record ptr + 2 for position ==> +6
	 // 9/10 Lgr_Index ==. too much lost ==> lose 24 bytes per record
         nbkey[index]++;
	 if (((ptrbeg+11) + strlen(ikey)+6) < (Lgr_Index-24))
	    { insert(ikey, irec, abuf);
	      writeidx(iorec, abuf);
	      break;
	    }
	 /* leaf index needs splitting */
	 allocidx();
	 P_Gauche = iorec;
	 P_Droit = P_Suiv;
	 Ptr_Data = irec;
	 splitidx(abuf);
	 modkids();

	 while (1)
	    { if (ht == 0)
		{ allocroot(index);
		  remplir(abuf, '\0', Lgr_Index);
		  nkey = 0; ptrbeg = 8; Ptr_Sys = P_Gauche;
		  Ptr_G = 0;  Ptr_Haut = 0; Ptr_D = 0;
		  encode(abuf);
		  ikn = 1;
		  insert(Cle_G, P_Droit, abuf);
		  writeidx(Sommet[index], abuf);
		  readidx(P_Gauche, abuf);
		  decode(abuf);
		  Ptr_Haut = Sommet[index];
		  encode(abuf);
		  writeidx(P_Gauche, abuf);
		  readidx(P_Droit, abuf);
		  decode(abuf);
		  Ptr_Haut = Sommet[index];
		  encode(abuf);
		  writeidx(P_Droit, abuf);
		  break;
		}
	     ht--;
	     iorec = Prof_N[ht];
	     ikn = (short) Prof[ht];     // !!!!!! conversion
	     readidx(iorec, abuf);
	     decode(abuf);
	     if (((ptrbeg+11) + strlen(Cle_G)+6) < (Lgr_Index-24))     // ikey £££££
		{
		  insert(Cle_G, P_Droit, abuf);
		  writeidx(iorec, abuf);

		  break;
		 }
		 /* split the branch */
	     allocidx();
	     strcpy(Cle_Temp, Cle_G);
	     Ptr_Data = P_Droit;
	     P_Gauche = iorec;
	     P_Droit = P_Suiv;
	     splitidx(abuf);
	     modkids();
	     decode(abufr);
	     compteur = nkey;
	     for (ikn = 1; ikn <= compteur; ikn++)
	     {
		 extract(abufr);
		 readidx(Ptr_Droit, abuf);
		 decode(abuf);
		 Ptr_Haut = P_Droit;
		 encode(abuf);
		 writeidx(Ptr_Droit, abuf);
	     }
	 }
	 break;

    case '3':       /* Get next after prior Get     */
	 advance();
	 break;

    case '4':       /* Get previous after prior Get */
	 retreat();
	 break;

    case '5':       /* Delete a key from index      */
	 searchidx(ikey, index);
	 if (Resultat == 0) { erreur = 1; break; }
         nbkey[index]--;
	 deletex(abuf);
	 if (nkey > 0) { writeidx(iorec, abuf); break; }
	 /* Code could be allocidxd here to clean up the indexes on a */
	 /* delete.  This author is quite content with a few empty */
	 /* index records to save all the complexity and overhead  */
	 writeidx(iorec, abuf);
	 break;


    case '6':       /* Get 1st key in entire index  */
	 getfirst(index);
	 break;

    case '7':       /* Get last key in entire index */
	 getlast(index);
	 break;

    case '8':       /* Open the index file   */

         init_var();
         errno=0;

         findex = fopen(nom,"r+b");
         var32 = errno;
         if (findex == NULL)
	    {
              Resultat = errno;
              remplir(abuf, '\0', Lgr_Index);
	      var32= 2l; memmove(abuf,&var32,4); // mkl(abuf, 2L);
	      findex = fopen(nom, MODE_WRITE);
	      if (findex == NULL)
		 { // Failed to create nom
		  erreur = -1;
		  break;
		 }
	      writeidx(1, abuf);
	      fclose(findex);
	      findex = fopen(nom, MODE_READ);
	      if (findex == NULL)
		 { // Failed to open nom);
		  erreur = -1;
		  break;
		 }
	     }
	 readidx( 1, abuf);
	 for (compteur = 0; compteur < Nb_Index; compteur++)
	    {
              memmove(&Sommet[compteur],abuf+8+compteur*10,4);
              memmove(&Mode_Index[compteur],abuf+12+(compteur*10),2);
              memmove(&nbkey[compteur],abuf+14+(compteur*10),4);
	    }
	 memmove(&Prochain_Libre,abuf,4);  //$$$$Prochain_Libre = cvl(abuf+0);
	 memmove(&Lien,abuf+4,4);   // $$$$Lien = cvl(abuf+4);
	 break;

    case '9':       /* Close the index file         */
         // update nbkey


         readidx( 1, abuf);
         for (compteur = 0; compteur < Nb_Index; compteur++)
	   {
            memmove(abuf+8+compteur*10,&Sommet[compteur],4);
            memmove(abuf+12+compteur*10,&Mode_Index[compteur],2);
            memmove(abuf+14+compteur*10,&nbkey[compteur],4);
	   }
         writeidx( 1, abuf);
         fseek(findex,0,SEEK_END);
         taille = ftell(findex);
         errno=0;
	 Resultat = fclose(findex);
         x=errno;
         break;

    case 'a' :   // Close Reopen
         readidx( 1, abuf);
         for (compteur = 0; compteur < Nb_Index; compteur++)
	   {
            memmove(abuf+8+compteur*10,&Sommet[compteur],4);
            memmove(abuf+12+compteur*10,&Mode_Index[compteur],2);
            memmove(abuf+14+compteur*10,&nbkey[compteur],4);
	   }
         writeidx( 1, abuf);
         fseek(findex,0,SEEK_END);
         taille = ftell(findex);
         errno=0;
	 Resultat = fclose(findex);
         x=errno;
         findex = freopen(nom,"r+b",findex);
         x=errno;
          break;

    default:
	 erreur = -10;    // command incorrect
	 break;

  }
 if (tiebrk == 1)
    { if (Lgr_Cle > 4) key[Lgr_Cle - RECORD_ADDR] = 0;    // > 1 $$$$
    }
 strcpy(ikey, Temp_Key);
 return(erreur);
}




// *******************************
//  searchidx  $$$$
// *******************************

void isam::searchidx(char *ikey, short Num_Index)
{

  dupliquer(Cle_Temp, ikey, 0, Tmp_Lgr_Cle);
  ht = 0;
  if (Sommet[Num_Index] == 0)
    {
     allocroot(Num_Index);
     remplir(abuf, '\0', Lgr_Index);
     abuf[1] = 0;
     abuf[2] = 8;   // avoid mki
     ikn = 1;
     Resultat = 0;
     iorec = Sommet[Num_Index];
     writeidx(iorec, abuf);
    }
   else
    { iorec = Sommet[Num_Index];
      do {
	   readidx(iorec, abuf);
	   scan4key(abuf, Cle_Temp);
	   Prof_N[ht] = iorec;
	   Prof[ht] = ikn;      // !!!!! conversion inverse
	   ht++;
	   iorec = Pointeur;
	 } while (Ptr_Sys > 0);
      ht--;
      iorec = Prof_N[ht];
   }
}

// *******************************
//  advance $$$$
// *******************************

void isam::advance(void)
{
  Resultat = 1;
  ikn++;
  while (ikn > nkey)
    { if (Ptr_D != 0)
	{ readidx(Ptr_D, abuf);
	  decode(abuf);
	  ikn = 1;
	}
      else
	{ ikn--; Resultat = 0;
	  break;
	}
    }
 extract(abuf);
 Ptr_Data = Ptr_Droit;
}

// *******************************
//  retreat $$$$
// *******************************

void isam::retreat(void)
{
   Resultat = 1;
   ikn--;
   while (ikn < 1)
     {
      if (Ptr_G != 0)
	{ readidx(Ptr_G, abuf);
	  decode(abuf);
	  ikn = nkey;
	}
      else
       { ikn++; Resultat = 0;
	 break;
       }
     }
  extract(abuf);
  Ptr_Data = Ptr_Droit;
}

// *******************************
//  getfirst  $$$$
// *******************************

void isam::getfirst(short Num_Index)
{
  int iorec;

  Resultat = 1;
  ht = 0;
  iorec = Sommet[Num_Index];
  while (iorec != 0)
     { do
	{ readidx(iorec, abuf);
	    decode(abuf);
	    iorec = Ptr_Sys;
	    ht++;
	} while (Ptr_Sys > 0);
       if (nkey == 0)
	  { iorec = Ptr_D;
	    continue;
	  }
       ikn = 1;
       extract(abuf);
       Ptr_Data = Ptr_Droit;
       return;
     }
 Resultat = 0;
}

// *******************************
//  getlast  $$$$
// *******************************

void isam::getlast(short Num_Index)
{
 int iorec;

 Resultat = 1; ht = 0;
 iorec = Sommet[Num_Index];
 while (iorec != 0)
    { do
	{  readidx(iorec, abuf);
	   decode(abuf);
	   ikn = nkey;
	   extract(abuf);
	   iorec =Ptr_Droit;
	   ht++;
	} while (Ptr_Sys > 0);
      if (nkey == 0)
	{ iorec = Ptr_G;
	  continue;
	}
      ikn = nkey;
      extract(abuf);
      Ptr_Data = Ptr_Droit;
      return;
    }
 Resultat = 0;
}

// *******************************
//   allocidx  $$$$
// *******************************

void isam::allocidx()
{
   if (Lien != 0)
     {  P_Suiv = Lien;
	readidx(Lien, abuft);
	memmove(&Lien,abuft,4);  //$$$$Lien = cvl(abuft);
     }
  else
    { P_Suiv = Prochain_Libre;
      Prochain_Libre++;
    }
  readidx( 1, abuft);
  memmove(abuft,&Prochain_Libre,4);  //$$$$mkl(abuft + 0, Prochain_Libre);
  memmove(abuft+4,&Lien,4); //$$$$mkl(abuft + 4, Lien);
  writeidx( 1, abuft);
}


// *******************************
//  allocroot  $$$$
// *******************************

void isam::allocroot(short Num_Index)
{
  allocidx();
  Sommet[Num_Index] = P_Suiv;
  readidx( 1, abuft);

  memmove(abuft+8+(Num_Index*10),&Sommet[Num_Index],4);
  memmove(abuft+12+Num_Index*10,&Mode_Index[Num_Index],2);
  memmove(abuft+14+Num_Index*10,&nbkey[Num_Index],4);

  //if (setmult == 1)
  //  { abuft[ 384 + Num_Index] = multkey;    // #$#$#$#
  //    Mode_Index[Num_Index] = multkey;
  //  }
  //dupliquer(abuft+384,Mode_Index,0,8);
  //mkl(abuft + 8 + (Num_Index * 4), Sommet[Num_Index]);  // #$#$#$
  writeidx( 1, abuft);
}

// *******************************
//  splitidx $$$$
// *******************************
void isam::splitidx(char *buffer)
{
   short nkeyl, nkeyr, keynum, maxlen, Cle_Gl, nbkey;
   short length = Tmp_Lgr_Cle;
   char  CLEG[250]; int leftkeyl;

   ikn = 1;
   nbkey = (unsigned char) (buffer[1]*256) + (unsigned char) buffer[0];

   //ikn = nbkey / 2; // $$$$
   //nkeyl = ikn - 2; // $$$$

   ikn=(short) nbkey*2/3;
   nkeyl = ikn;

   nkeyr = (short) (nbkey-nkeyl);     // $$$$  nkey - nkeyl;
   remplir(abufl, '\0', Lgr_Index);
   abufl[2] = 8;
   abufl[3] = 0;
   for (ikn = 1; ikn <= nkeyl; ikn++)
      { extract(buffer);
	Tmp_Lgr_Cle = Lgr_Cle;
	insert(key, Ptr_Droit, abufl);
      }
   remplir(abufr, '\0', Lgr_Index);
   abufr[2] = 8;
   abufr[3] = 0;
   for (keynum = nkeyl + 1; keynum <= nkeyl + nkeyr; keynum++)
      { ikn = keynum;
	extract(buffer);    //  Extract Ecrasait Cle_G ###############""
	Tmp_Lgr_Cle = Lgr_Cle;
	ikn = keynum - nkeyl;
	insert(key, Ptr_Droit, abufr);
	if (ikn == 1)
	  { //dupliquer(Cle_G, key, 0, Lgr_Cle);
            dupliquer(CLEG, key, 0, Lgr_Cle);
	    //Cle_Gl = Lgr_Cle;
            leftkeyl=Lgr_Cle;
	  }
      }
   Tmp_Lgr_Cle = length;
   if (length > Lgr_Cle) maxlen = length; else maxlen = Lgr_Cle;                                    /* 07-18-87 */
   if (comparer(Cle_Temp, CLEG, maxlen) < 1)
      { scan4key(abufl, Cle_Temp);
	insert(Cle_Temp, Ptr_Data, abufl);
       }
    else
       { scan4key(abufr, Cle_Temp);
	 insert(Cle_Temp, Ptr_Data, abufr);
	}
   Tmp_Lgr_Cle = leftkeyl; //Cle_Gl;
   strcpy(Cle_G,CLEG);
}

// *******************************
//  insert  $$$$
// *******************************

void isam::insert(char *ikey, int dp, char *buffer)
{
  short pn,pk;
  char *ptr1a;char *ptr2a;
  char *ptr1b;char *ptr2b;
  short x,l1;
  char temp[Lgr_Index];

  remplir(temp, '\0', Lgr_Index);  ////
  decode(buffer);             ////

  nkey++;              ////
  //mki(temp,nkey);      // new key number
  memmove(temp,&nkey,2);
  // transfer loop from first key to ikn-1;
  ptr1a = buffer + 2;   //
  ptr1b = buffer + nkey*2 + 6; // buffer + 2 + (nkey-1)*2 + 2 + 4;

  ptr2a = temp +2;
  ptr2b = temp + nkey*2 + 8;
  for (x=1;x<ikn;x++)
      {
       memmove(&pk,ptr1a,2);  //$$$$pk = cvi(ptr1a);
       memmove(&pn,ptr1a+2,2); //$$$$pn = cvi(ptr1a+2);  // pos next key or ptrbeg
       l1 = pn-pk;
       pk = pk + 2;    // to include 1 more position
       //mki(ptr2a,pk);
       memmove(ptr2a,&pk,2);
       memmove(ptr2b,ptr1b,l1); // copy key
       ptr1a+=2; ptr2a+=2;  // next position
       ptr1b+=l1;ptr2b+=l1;  // next key
      }
 // transfer ikn key to be inserted
       memmove(&pk,ptr1a,2);  //$$$$pk = cvi(ptr1a);
       pk=pk+2;
       //mki(ptr2a,pk);
       memmove(ptr2a,&pk,2);
       ptr2a +=2;
       memmove(ptr2b,ikey,Tmp_Lgr_Cle);
       ptr2b+=Tmp_Lgr_Cle;
       //mkl(ptr2b,dp);
       memmove(ptr2b,&dp,4);
       ptr2b+=4;

 // transfer loop from ikn+1 to nkey

  for (x=ikn+1;x<=nkey;x++)
      {
       memmove(&pk,ptr1a,2);    // $$$$pk = cvi(ptr1a);
       memmove(&pn,ptr1a+2,2);   //$$$$pn = cvi(ptr1a+2);  // pos next key or ptrbeg
       l1 = pn-pk;
       pk = pk + 2 + Tmp_Lgr_Cle + 4 ;    // to include 1 more position
       //mki(ptr2a,pk);
       memmove(ptr2a,&pk,2);
       memmove(ptr2b,ptr1b,l1); // copy key
       ptr1a+=2; ptr2a+=2;  // next position
       ptr1b+=l1;ptr2b+=l1;  // next key
      }
  // update ptrbeg
  memmove(&pk,ptr1a,2);    //$$$$pk = cvi(ptr1a);
  pk = pk+2+Tmp_Lgr_Cle+4;
  //mki(ptr2a,pk);
  memmove(ptr2a,&pk,2);
  ptr1a+=2;
  ptr2a+=2;
  // copy Ptr_Sys;
  memmove(ptr2a,ptr1a,4);
  // copy left, above and right pointer

  memmove(ptr2b,ptr1b,12);
  dupliquer(buffer, temp, 0, Lgr_Index);
}

// *******************************
//  modkids  $$$$
// *******************************

void isam::modkids(void)
{
  int llpt, nlpt, rlpt;
  int lrpt, nrpt, nPtr_Haut, parentPtr_Sys;

  decode(abuf);
  llpt = Ptr_G; nlpt = iorec; rlpt = P_Suiv;
  lrpt = P_Suiv; nrpt = Ptr_D;   nPtr_Haut = Ptr_Haut;
  parentPtr_Sys = Ptr_Sys;
  decode(abufl);
  Ptr_G = llpt; Ptr_D = lrpt; Ptr_Haut = nPtr_Haut;
  if (parentPtr_Sys > 0 ) Ptr_Sys = parentPtr_Sys;
     else Ptr_Sys = (-1);
  encode(abufl);
  writeidx(P_Gauche, abufl);
  decode(abufr);
  Ptr_G = nlpt; Ptr_D = nrpt; Ptr_Haut = nPtr_Haut;
  if (parentPtr_Sys > 0 ) Ptr_Sys = parentPtr_Sys;
    else Ptr_Sys = (-1);
  encode(abufr);
  writeidx(P_Droit, abufr);

  if (nrpt != 0)
    { readidx(nrpt, abuft);
      decode(abuft);
      Ptr_G = rlpt;
      encode(abuft);
      writeidx(nrpt, abuft);
    }
}

// *******************************
//   deletex $$$$
// *******************************

void isam::deletex(char *buffer)
{
  short  del = ikn;
  short  keynum = nkey;
  int nlpt, nPtr_Haut, nrpt, parentPtr_Sys;
  short  compteur;
  char temp[Lgr_Index];

  dupliquer(temp, buffer, 0, Lgr_Index);
  remplir(buffer, '\0', Lgr_Index);
  buffer[2] = 8;
  buffer[3] = 0;
  if (nkey == 1)
     {
      nkey = 0;
      ptrbeg = 8;
      encode(buffer);
      return;
     }

  nlpt = Ptr_G;
  nPtr_Haut = Ptr_Haut;
  nrpt = Ptr_D;
  parentPtr_Sys = Ptr_Sys;

  for (ikn = 1; ikn <= del - 1; ikn++)
    { extract(temp);
      Tmp_Lgr_Cle = Lgr_Cle;
      insert(key, Ptr_Droit, buffer);
    }
  for (compteur = del + 1; compteur <= keynum; compteur++)
    { ikn = compteur;
      extract(temp);
      Tmp_Lgr_Cle = Lgr_Cle;
      ikn = compteur - 1;
      insert(key, Ptr_Droit, buffer);
    }
  decode(buffer);
  Ptr_G = nlpt; Ptr_Haut = nPtr_Haut; Ptr_D = nrpt;
  Ptr_Sys = parentPtr_Sys;
  encode(buffer);
}

// *******************************
//  extract $$$$
// *******************************

void isam::extract(char *buffer)
{
  short len;
  short start, end;

  if (ikn < 1)
     { 	key[0] = 0;
	Ptr_Left = 0;  Ptr_Droit = 0;
	return;
     }

  memmove(&start,buffer+ikn*2,2);   // $$$$$start = cvi(buffer+ikn*2);
  memmove(&end,buffer+(ikn+1)*2,2);  // end =   cvi(buffer+(ikn+1)*2);
  len = end - start-4;
  Lgr_Cle = len;
  dupliquer(key, buffer + start, 0, len);
  key[len] = 0;
  memmove(&Ptr_Left,buffer+start-4,4);   //$$$$$Ptr_Left = cvl(buffer + start - 4);
  memmove(&Ptr_Droit,buffer+end-4,4);     // $$$$$Ptr_Droit = cvl(buffer + end - 4);
}

// *******************************
//  scan4key  $$$$
// *******************************

void isam::scan4key(char *buffer, char *Cle_Temp)
{
 short l1 = 1;
 short l2, l3;
 short length = Tmp_Lgr_Cle;
 short rtn, maxlen;

 Resultat = 0;
 ikn = 1;
 decode(buffer);
 l2 = nkey;
 while (l1 <= l2)
   { l3 = (l1 + l2) / 2;
     ikn = l3;
     extract(buffer);
     if (length>Lgr_Cle) maxlen= length; else maxlen = Lgr_Cle;
     if (length == Lgr_Cle)

	{  rtn = comparer(key, Cle_Temp, length);
	   if (rtn == 0)
	      { Resultat = 1;
		Pointeur = Ptr_Droit;
		return;
	      }
	}
     rtn = comparer(Cle_Temp, key, maxlen);
     if (rtn < 0)  l2 = l3 - 1; else l1 = l3 + 1;
     ikn = l1;
    }
    if (ikn == 0) ikn = 1;
    if (comparer(Cle_Temp, key, maxlen) < 0)
    Pointeur = Ptr_Left; else Pointeur = Ptr_Droit;
}

void isam::look4key(char *buffer, char *Cle_Temp)
{
 short l1 = 1;
 short l2, l3;
 short length = Tmp_Lgr_Cle;
 short rtn, maxlen;
 int i;

 Resultat = 0;
 ikn = 1;
 decode(buffer);
 l2 = nkey;

 for (i=1;i<=nkey;i++)
// while (l1 <= l2)
   {
     // l3 = (l1 + l2) / 2;
     ikn = i; //l3;
     extract(buffer);
     if (length>Lgr_Cle) maxlen= length; else maxlen = Lgr_Cle;
     if (length == Lgr_Cle)

	{  rtn = comparer(key, Cle_Temp, length);
	   if (rtn == 0)
	      { Resultat = 1;
		Pointeur = Ptr_Droit;
		return;
	      }
	}
     rtn = comparer(Cle_Temp, key, maxlen);
     if (rtn < 0)
      {
       ikn=i-1;
       break;
      }
     //if (rtn < 0)  l2 = l3 - 1; else l1 = l3 + 1;
     //ikn = l1;
    }
    if (ikn == 0) ikn = 1;
    if (comparer(Cle_Temp, key, maxlen) < 0)
    Pointeur = Ptr_Left; else Pointeur = Ptr_Droit;



}

// *******************************
//  decode $$$$
// *******************************

void isam::decode(char *buffer)
{
  memmove(&nkey,buffer,2);  //$$$$nkey = cvi(buffer+0);
  memmove(&ptrbeg,buffer+nkey*2+2,2);  //$$$$ptrbeg = cvi(buffer + nkey*2 + 2);
  memmove(&Ptr_Sys,buffer+nkey*2+4,4);   //Ptr_Sys  = cvl(buffer + nkey*2 + 4);
  memmove(&Ptr_G,buffer+ptrbeg,4);   //$$$$Ptr_G = cvl(buffer + ptrbeg);
  memmove(&Ptr_Haut,buffer+ptrbeg+4,4);   //$$$$$Ptr_Haut = cvl(buffer + ptrbeg + 4);
  memmove(&Ptr_D,buffer+ptrbeg+8,4);   //$$$$$Ptr_D = cvl(buffer + ptrbeg + 8);
}

// *******************************
//  encode  $$$$
// *******************************
void isam::encode(char *buffer)
{
  memmove(buffer,&nkey,2); //mki (buffer + 0,nkey);
  memmove(buffer+nkey*2+2,&ptrbeg,2);  //mki (buffer + nkey*2 + 2,ptrbeg);

  //mkl (buffer + nkey*2 + 4, Ptr_Sys);
  //mkl (buffer + ptrbeg, Ptr_G);
  //mkl (buffer + ptrbeg + 4, Ptr_Haut);
  //mkl (buffer + ptrbeg + 8, Ptr_D);
  memmove(buffer + nkey*2 + 4, &Ptr_Sys,4);
  memmove(buffer + ptrbeg, &Ptr_G,4);
  memmove(buffer + ptrbeg + 4, &Ptr_Haut,4);
  memmove(buffer + ptrbeg + 8, &Ptr_D,4);
}


// *******************************
//  readidx  $$$$
// *******************************

void isam::readidx(int iorec, char *buffer)
{
  short mode = 0;
  int pos;
  short c = 0;
  pos = ((int) Lgr_Index) * (iorec - 1);
  fseek(findex, pos, mode);
  //while (c < Lgr_Index) buffer[c++] = fgetc(findex);
  fread(buffer,Lgr_Index,1,findex);
}

// *******************************
// writeidx $$$$
// *******************************

void isam::writeidx(int iorec, char *buffer)
{
  short mode = 0;
  int pos;
  short c = 0;
  int rc;

  pos = ((int) Lgr_Index) * (iorec - 1);
  fseek(findex, pos, mode);
  // while (c < Lgr_Index) fputc(buffer[c++], findex);
  fwrite(buffer,Lgr_Index,1,findex);
}



// *******************************
// DUPLIQUER $$$$
// *******************************

void isam::dupliquer(char *buffer, char *string, short start, short len)
{ short compteur = 0;
  while (compteur < len) buffer[start++] = string[compteur++];
}

// *******************************
// STRFILL $$$$                        fillmem
// *******************************

void isam::remplir(char *buffer, char fill, short len)
{ short compteur = 0;
  while (compteur < len) buffer[compteur++] = fill;
}

// *******************************
// STRCMPL $$$$
// *******************************

short isam::comparer(char *string1, char *string2, short len)
{
  short compteur = 0;

  while (compteur < len)
      {  if (string1[compteur] != string2[compteur])
	     return(string1[compteur] - string2[compteur]);
	 compteur++;
      }
 return(0);
}


// *******************************
//  TIEBREAKL $$$$
// *******************************
void isam::append(char *buffer, int number)
{
  char tiebrk[5];  char buff[5];
  int a;

  //mkl(tiebrk, number);
  //memmove(tiebrk,&number,4);
  memmove(buff,&number,4);

  tiebrk[4]=0;
  // strcpy(buff,tiebrk);
  tiebrk[0]=buff[3];
  tiebrk[1]=buff[2];
  tiebrk[2]=buff[1];
  tiebrk[3]=buff[0];
  a=strlen(buffer);
  dupliquer(buffer,tiebrk,a,5);
}


// *********************************************
//
//  VARIABLE DATA LENGTH  FILE MANAGER
//
// *********************************************

// DATA FILE ORGANIZATION

// first record
//    firstfree pointer (int )
//    data bloc size    (int) ==> physical bloc size = databloc size + 8


// Other records
//    next bloc pointer (int)  or 0 if last
//    flag delete       (int)
//    data length       (int)  must be <= databloc size



// To delete a data record, use the Rewrite with a 0 length parameter



class vardata
{
  private :

  int firstfree;
  FILE *fdata;
  char *bufio;   //[BLOCSIZE+1];
  char *buftmp;
  short DATASIZE;
  short BLOCSIZE;
  short var16;
  int var32;

  public:
  vardata(void);
  ~vardata(void);
  short OpenData(char *FileName, short BlocSize);
  short CloseData(void);
  short ReadFirstDataBlock(char *pdata,int record);
  int ReadData(char *pdata,int record);
  int RecordLength(int record);
  int WriteData(char *pdata,int len);
  short RewriteData(char *pdata,int len, int record);
  short DeleteData(int record);
  int  DeleteDataFile(char *filename);
  int GetAvailRecord();
  //int Version(char *p);
  void dupliquer(char *buffer, char *string,  short start,  short len);
  void remplir(char *buffer, char fill,  short len);
   short  comparer(char *string1, char *string2,  short len);
  void readbuf(int iorec, char *buffer);
  void writebuf(int iorec, char *buffer);
};



// **********************************************
// VARDATA::VARDATA
// **********************************************

vardata::vardata(void)
{
 firstfree=1;
 fdata=NULL;
 BLOCSIZE=512;   // default value
 DATASIZE=504;
}

// **********************************************
// VARDATA::~VARDATA
// **********************************************

vardata::~vardata(void)
{
/*
 if (bufio) farfree(bufio);
 if (buftmp) farfree(buftmp);
 if (fdata) fclose(fdata);
*/
}

int vardata::DeleteDataFile(char *filename)
{
 fclose(fdata);
 unlink(filename);
 return 1;
}


// **********************************************
// VARDATA::GETAVAILRECORD
// **********************************************

int vardata::GetAvailRecord()
{
 return (firstfree);
}



// **********************************************
// VARDATA::OPENDATA
// **********************************************

short vardata::OpenData(char *FileName,short BlocSize)
{
 //char tmp[30];

 if (BlocSize <= 8) return -1;
 BLOCSIZE=BlocSize;
 DATASIZE=BlocSize-8;
 bufio = (char *) malloc(BLOCSIZE);
 buftmp=(char *) malloc(BLOCSIZE);
 if (bufio == NULL) return -2;
 // open in read mode to know if exists
 fdata = fopen(FileName,MODE_READ);
 if (fdata == 0)
    {
     remplir(bufio,0,BLOCSIZE);
     firstfree=2l;
     memmove(bufio,&firstfree,4);
     memmove(bufio+4,&DATASIZE,2);
     fdata = fopen(FileName,MODE_WRITE);
     if (fdata == NULL) return -3;
     writebuf(1,bufio);
     fclose(fdata);
     fdata = fopen(FileName,MODE_READ);
    }
 readbuf(1,bufio);
 memmove(&firstfree,bufio,4);   //$$$$$firstfree=cvl(bufio);
 if (firstfree<2l) return -1;

 return 1;
}

// **********************************************
// VARDATA::CLOSEDATA
// **********************************************

short vardata::CloseData(void)
{
 //      fseek
 //  rewrite ptr available and data size

 remplir(bufio,0,BLOCSIZE);
 memmove(bufio,&firstfree,4); //mkl(bufio+0,firstfree);
 memmove(bufio+4,&DATASIZE,2);   ///mki(bufio+4,DATASIZE);
 writebuf(1,bufio);
 fclose(fdata);

 free(bufio);
 free(buftmp);
 //bufio = (char *) malloc(BLOCSIZE);
 //buftmp=(char *) malloc(BLOCSIZE);

 return 1;
}


// **********************************************
// VARDATA::READFIRSTDATABLOC
// **********************************************

 short vardata::ReadFirstDataBlock(char *pdata,int record)
 {
 short blen;  // bloc length
 char *ptr; // ptr read data
 if (record >= firstfree) return -1;
 ptr = pdata;
 readbuf(record,bufio);
 memmove(&blen,bufio+6,2); //$$$$blen = cvi(bufio+6);

 memmove(ptr,bufio+8,blen);
 return blen;
}




// **********************************************
// VARDATA::READDATA
// **********************************************

int vardata::ReadData(char *pdata,int record)
{
 int rlen;  // data length
 short blen;  // bloc length
 char *ptr; // ptr read data
 int next; // ptr file record
 ptr = pdata;
 rlen = 0;
 next = record;
 if (record >= firstfree)  return -1;
 do { readbuf(next,bufio);
      memmove(&next,bufio,4);     //$$$$$next = cvl(bufio);
      memmove(&blen,bufio+6,2);  // $$$$blen = cvi(bufio+6);
      memmove(ptr,bufio+8,blen);
      rlen += blen;  ptr += blen;
    } while (next != 0);
 return rlen;
}


// **********************************************
// VARDATA::RECORDLENGTH
// **********************************************

int vardata::RecordLength(int record)
{
 int rlen;  // data length
 short blen;  // bloc length
 int next; // ptr file record
 
 rlen = 0;
 next = record;
 if (record >= firstfree)  return -1;
 do { readbuf(next,buftmp);
      memmove(&next,buftmp,4);     //
      memmove(&blen,buftmp+6,2);  //
      rlen += blen; 
    } while (next != 0);
 return rlen;
}



// **********************************************
// VARDATA::WRITEDATA
// **********************************************

int vardata::WriteData(char *pdata,int len)
{
 int ptrfirst;
 int next;
 short  blen;
 int totlen;
 char *ptr;
 //char tmp[30];

 ptrfirst = firstfree;
 totlen = len;
 blen = DATASIZE;
 ptr = pdata;
 next = firstfree;
 while (totlen > DATASIZE)
    {
      var32 = next+1;
      memmove(bufio,&var32,4);  //mkl(bufio,next+1);
      var16=0; memmove(bufio+4,&var16,2); //mki(bufio+4,0);
      memmove(bufio+6,&blen,2);   //mki(bufio+6,blen);
      memmove(bufio+8,ptr,blen);
      writebuf(next,bufio);
      totlen -= blen;
      next++; ptr += DATASIZE;
    }

 blen = (short) totlen;
 remplir(bufio,0,BLOCSIZE);
 var32=0;memmove(bufio,&var32,4);  //mkl(bufio,0l);
 var16=0; memmove(bufio+4,&var16,2);   //mki(bufio+4,0);
 memmove(bufio+6,&blen,2);   //mki(bufio+6,blen);
 memmove(bufio+8,ptr,blen);
 writebuf(next,bufio);
 firstfree = next+1;  // update first free

return ptrfirst;
}

// **********************************************
// VARDATA::REWRITEDATA   // and "delete"
// **********************************************

short vardata::RewriteData(char *pdata,int len, int record)
{
 int next;
 short  blen;
 int totlen;
 char *ptr;
 short mode;
 int currptr;

 if (record >= firstfree) return -1;
 totlen = len;
 blen = DATASIZE;
 ptr = pdata;
 currptr = record;
 mode = 0; // mode ptrnext in former record
 while (totlen > DATASIZE)
    {
      if ( mode == 0)
         { readbuf(currptr,bufio);
	   memmove(&next,bufio,4);    //$$$$$next = cvl(bufio+0);
	   if (next == 0)
	     { mode = 1;
	       next = firstfree;
	       firstfree++;
	     }
	 }
      else
         { next = firstfree;
	   firstfree++;
         }  

      memmove(bufio,&next,4); //$$$$mkl(bufio,next);
      var16 = 0; memmove(bufio+4,&var16,2);    ///mki(bufio+4,0);
      memmove(bufio+6,&blen,2);    //mki(bufio+6,blen);
      memmove(bufio+8,ptr,blen);
      writebuf(currptr,bufio);
      totlen -= blen;
      ptr += DATASIZE;
      currptr = next;
    }

 blen = (short) totlen;
 remplir(bufio,0,BLOCSIZE);
 var32=0; memmove(bufio,&var32,4);   //mkl(bufio,0l);
 var16=0;  memmove(bufio+4,&var16,2);  //mki(bufio+4,0);
 memmove(bufio+6,&blen,2);   //mki(bufio+6,blen);
 if (blen>0) memmove(bufio+8,ptr,blen);
 writebuf(currptr,bufio);
 return 1;
}

// *******************************
// DELETEDATA $$$$
// *******************************
short vardata::DeleteData(int record)
{

if (record >= firstfree) return -1;
readbuf(record,bufio);
var32=0; memmove(bufio,&var32,4);  //mkl(bufio,0l);
var16=0;  memmove(bufio+4,&var16,2);   //mki(bufio+4,0);
memmove(bufio,&var16,2);   //mki(bufio+6,0);
writebuf(record,bufio);
return 1;
}


// *******************************
// STRCPYL $$$$
// *******************************

void vardata::dupliquer(char *buffer, char *string, short start, short len)
{ short compteur = 0;
  while (compteur < len) buffer[start++] = string[compteur++];
}

// *******************************
// STRFILL $$$$                        fillmem
// *******************************

void vardata::remplir(char *buffer, char fill, short len)
{ short compteur = 0;
  while (compteur < len) buffer[compteur++] = fill;
}

// *******************************
// STRCMPL $$$$
// *******************************

short vardata::comparer(char *string1, char *string2, short len)
{
  short compteur = 0;
  while (compteur < len)
      {  if (string1[compteur] != string2[compteur])
	     return(string1[compteur] - string2[compteur]);
	 compteur++;
      }
 return(0);
}

// *******************************
//  READBUF  $$$$
// *******************************

void vardata::readbuf(int iorec, char *buffer)
{
  short mode = 0;
  int pos;
  short c = 0;
  pos = ((int) BLOCSIZE) * (iorec - 1);
  fseek(fdata, pos, mode);
  while (c < BLOCSIZE) buffer[c++] = fgetc(fdata);
}

// *******************************
// WRITEBUF $$$$
// *******************************

void vardata::writebuf(int iorec, char *buffer)
{
  short mode = 0;
  int pos;
  short c = 0;
  int status;

  pos = ((int) BLOCSIZE) * (iorec - 1);
  status = fseek(fdata, pos, mode);
  if  (status != 0)
       strcpy(buffer,"Erreur FSEEK");
   else  {  while (c < BLOCSIZE) fputc(buffer[c++], fdata); }
}



//
//
//  realisam.CPP


// ********************************************
// (C) JLGOUIN
// JLG   NOVEMBER 2005

//  realisam.CPP
// realisam is an object that manages 1 set of indexes and
// 1 set of data

// ********************************************


//
//  realisam OBJECT
///


class  realisam
{

 public:

  realisam(void);
 ~realisam(void);

 int  OpenEngine(char *FileName,short BlockSize,char *ndx, char *dat);
 int  CloseEngine(void);
 int  SetIndexMode(short Index, short Value);
 int  WriteRecord(char *pdata,int len);                              // ****
 int  RewriteRecord(char *pdata,int len, int RecNumber);             //*****
 int  DeleteRecord(int RecNumber);                                   //*****
 int  ReadRecord(char *pdata,int RecNumber);                         //*****
 int  GetNewRecordNumber();
 int  WriteKey(short Index,char *Key,int RecNumber);                 //*****
 int  DeleteKey(short Index,char *Key,int RecNumber);                //******
 int  ReadFirstKey(short Index,char *ReturnKey,int *RecNumber);      // ******
 int  ReadNextKey(char *ReturnKey ,int *RecNumber);                  // *******
 int  ReadLastKey(short Index,char *ReturnKey,int *RecNumber);       // ******
 int  ReadPrevKey(char *ReturnKey ,int *RecNumber);                  // ******
 int  ReadDirectKey(short Index,char *Key, char *ReturnKey, int *RecNumber);  // *******
 int  NumberOfKeys(short Index);
 int  RecordLength(int RecNumber);                                   // ********
 int  Version(char *p);
 //int  GetIndexRecord(char *pindex,int ndx);
 int  GetIndexMode(int ndx);
 int  DeleteIsam(char *indexname,char *dataname);
 int  CloseReopen(char *FileName,short BlockSize,char *ndx, char *dat);
// int  LockIsam();
// int  UnlockIsam(int tk);
// int  LockRecord(int recdata);
// int  UnlockRecord(int recdata,int lk);

 private:

 isam     *doctitl;
 vardata  *doc;
 };





// **********************************************
// realisam::realisam
// **********************************************
// PARAMETERS  :   NONE

realisam::realisam(void)
{
 int i;
 doctitl = new isam();   // index for name doc
 doc     = new vardata();  // data for documents
 //doctitl->Global_Token=0;
}

// **********************************************
// realisam::~realisam
// **********************************************
// PARAMETERS  :   NONE

realisam::~realisam(void)
{
 doctitl->~isam();
 doc->~vardata();

}

// *********************************************************
//
//   realisam::WRITEKEY
//
// *********************************************************
// Index  : Index Number (0-99)
// Key    : Key (max length 250) to Insert,
// RecNumber : Associated data record
// DataRec :  Datarec returned
// return code = 0 ==> key inserted
//               1 ==> key already present
//               -1 if Key length > 250
//               -2 if Index number > 99
//               -3 Key Locked by another application


int realisam::WriteKey(short Index,char *Key,int RecNumber)
{
  int result;
  if (strlen(Key)>Cle_Max) return -1;
  if (Index>99) return -2;

  doctitl->CIN=Index;
  result = doctitl->Ecrire(Index,Key,RecNumber);   //,&DataRec);
  //doctitl->list.additem(RecNumber,0);

  return result;
}

// *********************************************************
//
//   realisam::DELETEKEY
//
// *********************************************************
// Index  : Index Number (0-99)
// Key    : Key (max length 250) to Delete,
// RecNumber : Associated data record
// return code = 0 ==> key not found
//               1 ==> key deleted
//               -3 ==> KEY LOCKED BY ANOTHER APPLI

int realisam::DeleteKey(short Index,char *Key,int RecNumber)

{
  int result;
  doctitl->CIN=Index;
  result = doctitl->Effacer(Index,Key,RecNumber);
  return result;
}



// *********************************************************
//
//   realisam::WRITERECORD
//
// *********************************************************
// pdata = poshorter on data
// len   = total length of data to write (text or binary format)
// return code :  rec = record poshorter
//  -3   RECORD BLOCKED

int  realisam::WriteRecord(char *pdata,int len)
{
 int rec;
 rec = doc->WriteData(pdata,len);
 return rec;
}

// *********************************************************
//
//   realisam::REWRITERECORD
//
// *********************************************************
// pdata = poshorter on data
// len = new length of record (can be < = or > than the initial Write)
// recordnum = record starting poshorter
// ret code rc =
// -3 RECORD BLOCKED

int  realisam::RewriteRecord(char *pdata,int len, int recordnum)
{
 int rc;
 rc = doc->RewriteData(pdata,len,recordnum);
 return rc;

}

// *********************************************************
//
//   realisam::DELETERECORD
//
// *********************************************************
// recordnum = record starting poshorter
// ret code rc =
//   -3  RECORD BLOCKED

int  realisam::DeleteRecord(int recordnum)
{
 int rc;

 rc = doc->DeleteData(recordnum);
 return rc;

}



// *********************************************************
//
//   realisam::READRECORD
//
// *********************************************************
// pdata : poshorter on memory to receive data
// record = record poshorter to start reading
//  -3  RECORD BLOCKED

int  realisam::ReadRecord(char *pdata,int record)
{
 int rl;

 rl = doc->ReadData(pdata,record);

 // responsability of the application

 //*(pdata+(unsigned) rl)=0;

 return rl;
}


// **********************************************
// REALISAM::RECORDLENGTH
// **********************************************

//  -3 if RECORD BLOCKED

int realisam::RecordLength(int record)
{
 int rlen;  // data length

 rlen = doc->RecordLength(record);
 return rlen;
}



// *********************************************************
//
//   realisam::GETNEWRECORD
//
// *********************************************************
//  return the first record poshorter available

int realisam::GetNewRecordNumber()
{
 return (doc->GetAvailRecord());
}


// *********************************************************
//
//   realisam::READFIRSTKEY
//
// *********************************************************
// Index = index number (0-63)

// Key   = poshorter on the key returned
// Datarec = poshorter on data record associated to the returned key
// result = 1 if First key found
//        = 0 if Index empty (or error)
// -3 IF RECORD LOCKED

int realisam::ReadFirstKey(short Index,char *Key,int *DataRec)
{
 int result;
 char clef[Cle_Max];
  int nk;
  doctitl->CIN=Index;
 nk=doctitl->Cles(Index);
 if (nk==0) { strcpy(Key,""); return 0; }
 //Current_Index=Index;
 result = doctitl->Premiere(Index,clef,DataRec);
 strcpy(Key,clef);
 return result;
}

// *********************************************************
//
//   realisam::READNEXTKEY
//
// *********************************************************

// Key   = poshorter on the key returned
// Datarec = poshorter on data record associated to the returned key
// result  = 1 if key found
//         = 0 if end of file reached or no record
// Non significant if Insert or Delete just Before
//         -3 IF RECORD LOCKED

int realisam::ReadNextKey(char *Key,int *DataRec)
{
 int result;
 char clef[Cle_Max];
 int nk;
 nk=doctitl->Cles(doctitl->CIN);
 if (nk==0) { strcpy(Key,""); return 0; }
 result = doctitl->Suivante(clef,DataRec);
 strcpy(Key,clef);
 return result;
}


// *********************************************************
//
//   realisam::READLASTKEY
//
// *********************************************************
// Index = index number (0-63)

// Key   = poshorter on the key returned
// Datarec = poshorter on data record associated to the returned key
// result = 1 if Last key found
//        = 0 if Index empty (or error)
//        = -3 IF RECORD LOCKED

int realisam::ReadLastKey(short Index,char *Key,int *DataRec)
{
 int result;
 char clef[Cle_Max];
 int nk;
 nk=doctitl->Cles(doctitl->CIN);
 if (nk==0) { strcpy(Key,""); return 0; }
 result = doctitl->Derniere(Index,clef,DataRec);
 strcpy(Key,clef);
 return result;
}

// *********************************************************
//
//   realisam::READPREVKEY
//
// *********************************************************

// Key   = poshorter on the key returned
// Datarec = poshorter on data record associated to the returned key
// result  = 1 if key found
//         = 0 if begining of file reached or no record
//           = -3 if RECORD LOCKED
// Non significant if Insert or Delete just Before

int realisam::ReadPrevKey(char *Key,int *DataRec)
{
 int result;
 char clef[Cle_Max];
  int nk;
 nk=doctitl->Cles(doctitl->CIN);
 if (nk==0) { strcpy(Key,""); return 0;  }
 result = doctitl->Precedente(clef,DataRec);
 strcpy(Key,clef);
 return result;
}


// *********************************************************
//
//   realisam::READDIRECTKEY
//
// *********************************************************

// Key   = poshorter on the key returned
// Datarec = poshorter on data record associated to the returned key
// Index = index number (0-63)
// Key   = key to retrieve
// Cle_Retournee = key found = exact value or just greater
// Datarec = Data Record number associated to the returned key
//  0 if Not Found
//  1 if Found
// -3 if LOCKED

int realisam::ReadDirectKey(short Index,char *Key, char *Cle_Retournee, int *DataRec)
{
 int result;
 char clef[Cle_Max];
 int nk;
 doctitl->CIN=Index;
 nk=doctitl->Cles(Index);
 if (nk==0) { strcpy(Cle_Retournee,""); return 0; }
 result = doctitl->Lire(Index,Key,DataRec,clef);
 strcpy(Cle_Retournee,clef);
 return result;
}


int realisam::CloseReopen(char *FileName,short BlockSize,char *ndx, char *dat)
{

 char tmp[_MAX_PATH];
 char Drive[_MAX_DRIVE];
 char Dir[_MAX_DIR];
 char FName[_MAX_FNAME];
 char Ext[_MAX_EXT];
 short status;


 // INDEX
 strcpy(tmp,FileName);
 _splitpath(tmp,Drive,Dir,FName,Ext);

 strcpy(Ext,ndx);  //"NDX");      // index for document file
 _makepath(tmp,Drive,Dir,FName,Ext);

 status=doctitl->FermeReouvre(tmp);
 if (status != 1) return -1;

 /// DATA
 doc->CloseData();
 strcpy(tmp,FileName);
 _splitpath(tmp,Drive,Dir,FName,Ext);
 strcpy(Ext,dat); //  "DAT");      // data for document file
 _makepath(tmp,Drive,Dir,FName,Ext);
 status=doc->OpenData(tmp,BlockSize+8);
 if (status != 1) return -2;

return 1;


}


// **********************************************
//
// realisam::OPENENGINE
//
// **********************************************

int realisam::OpenEngine(char *FileName,short DataSize,char *ndx, char *dat)
{
 char tmp[_MAX_PATH];
 char Drive[_MAX_DRIVE];
 char Dir[_MAX_DIR];
 char FName[_MAX_FNAME];
 char Ext[_MAX_EXT];
 short status;


 strcpy(tmp,FileName);
 _splitpath(tmp,Drive,Dir,FName,Ext);

 strcpy(Ext,ndx);  //"NDX");      // index for document file
 _makepath(tmp,Drive,Dir,FName,Ext);

 status=doctitl->Ouvrir(tmp);
 if (status != 1) return -1;

 strcpy(tmp,FileName);
 _splitpath(tmp,Drive,Dir,FName,Ext);
 strcpy(Ext,dat); //  "DAT");      // data for document file
 _makepath(tmp,Drive,Dir,FName,Ext);
 status=doc->OpenData(tmp,DataSize+8);
 if (status != 1) return -2;
doctitl->CIN=0;
return 1;
}

// **********************************************
//
// realisam::SETINDEXMODE
//
// **********************************************

// return value   1 = OK
//               -1   Wrong Index (0-63)
//               -2   Wrong value (0-1)
int  realisam::SetIndexMode(short Index, short Value)
{
 int rc;
 rc = doctitl->Multi(Index,Value);
 return rc;
}

// **********************************************
//
// realisam::CLOSEDATABASE
//
// **********************************************
int realisam::CloseEngine(void)
{
 doctitl->Fermer();
 doc->CloseData();
 return 1;
}

int realisam::DeleteIsam(char *indexname,char *dataname)
{
 doctitl->DeleteIndex(indexname);
 doc->DeleteDataFile(dataname);
 return 1;
}


// **********************************************
//
// realisam::NUMBEROFKEY
//
// **********************************************
int realisam::NumberOfKeys(short Index)
{
 int nk;
 nk=doctitl->Cles(Index);
 return nk;
}



// **********************************************
//
// realisam::VERSION
//
// **********************************************
int realisam::Version(char *p)
{
 char tmp[500];
 strcpy(p,"RealIsam Version 2005.03");
 return 1;
}

/*
// **********************************************
//
// realisam::GETINDEXRECORD
//
// **********************************************
int realisam::GetIndexRecord(char *pindex,int ndx)
{
 doctitl->DumpIndex(pindex,ndx+1);
 return 1;
}
*/

// **********************************************
//
// realisam::GETINDEXMODE
//
// **********************************************
int  realisam::GetIndexMode(int ndx)
{
 return doctitl->GetMode(ndx);
}


/*
int realisam::LockIsam()
{
 int result;
 // ask for locking the database
 // Accepted only if isam::lock value is zero
 // return -3 if already locked
 randomize();
 result=rand();
 if (doctitl->Global_Token != 0) return -3;
 doctitl->Global_Token = result;
 return result;

}

int  realisam::UnlockIsam(int tk)
{
 int result;
 // tk is the lock key returned by Lock Isam
 if (tk==doctitl->Global_Token) { doctitl->Global_Token=0; result=0; }
 else result = -3;
 return result;
}


int  realisam::LockRecord(int recdata)
{
 int result; int rnd;
// result is -3 if already locked
// otherwise result countains the key used for unlocking
 result = doctitl->CheckLock(recdata);
 if (result==0) return -3;   // already locked
 randomize();
 rnd = rand();
 result = doctitl->Lock(recdata,rnd);
 return result;
}

int  realisam::UnlockRecord(int recdata,int tk)
{
 int result;
 // -3 if locked by another ID
 result = doctitl->CheckLock(recdata);
 if (result==0) return -3;
 if (result==1) return -2;

 result = doctitl->Unlock(recdata,tk);
 return result;
 }
*/

///////////////////////////////////////////////////////////


