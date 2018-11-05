
#ifndef __IKEY_H
#define __IKEY_H

#ifdef __cplusplus
extern "C" {
#endif


        // special for IKEY


#include <stdio.h>
#include "ikeyAPI.h"

                // Sample Application Directory Name and GUID
        unsigned char APP_NAME[256];
        unsigned char APP_GUID_STR[256];
        // Default SO PIN and User PIN set by Rainbow Manufacturing
        unsigned char SO_PIN[32];
        int           SO_PIN_LEN;
        unsigned char USER_PIN[10];
        int           USER_PIN_LEN;
        unsigned char DIOGPW[26];

         void __fastcall DisplayError(IKEY_STATUS   status,char * msg);
         void __fastcall encipher(const unsigned long *const v,unsigned long *const w,
   const unsigned long * const k);
        void __fastcall decipher(const unsigned long *const v,unsigned long *const w,
   const unsigned long * const k);
         void __fastcall DisplayError(IKEY_STATUS   status, char *msg);

        IKEY_DIRINFO    dirInfo;
        IKEY_FILEINFO   fileInfo;
        unsigned char   DATA; //   = {"012345678"};
        int             DATA_LEN; //       = (sizeof(DATA)-sizeof(unsigned char));
        int             request;
        unsigned long  bytesRead;
        int             datalen;
        char            dataf[1024];
        int             number;



        // Global flag used for selecting a device.
        int DeviceSelected;
        #define DIRECTORY_SIZE     5120     // size to reserve for directory = 20x256
        #define NUMBER_OF_FILES    20      // max number of files in directory

        // Callback routine used as a filter for enumerating devices.
        typedef BOOL (*OpenDeviceCallback)( IKEY_HANDLE   handle,
                unsigned long openFlags,
                unsigned char *openData,
                void		  *context,
                IKEY_STATUS   *result
                );
        int __fastcall IsTokenName(
		IKEY_HANDLE   handle,
		unsigned long openFlags,
		unsigned char *openData,
		void	      *context,
		IKEY_STATUS   *result
                );
        int __fastcall IsDeviceInUse(
		IKEY_HANDLE   handle,
		unsigned long openFlags,
		unsigned char *openData,
		void	      *context,
		IKEY_STATUS   *result
                );
        IKEY_STATUS __fastcall OpenFirstDevice(
	IKEY_HANDLE        handle,
	unsigned long      openFlags,
	unsigned char      *openData,
	OpenDeviceCallback callback,
	void			   *context
        );

        IKEY_STATUS __fastcall OpenNextDevice(
	IKEY_HANDLE        handle,
	unsigned long      openFlags,
	unsigned char      *openData,
	OpenDeviceCallback callback,
	void			   *context
        );

        IKEY_STATUS  __fastcall CountDevices(
	IKEY_HANDLE        handle,
	unsigned long      openFlags,
	unsigned char      *openData,
	OpenDeviceCallback callback,
	void		   *context,
	unsigned long      *count
        );


        IKEY_STATUS  __fastcall DisplayDeviceInfo(
	IKEY_HANDLE handle
        );

        IKEY_STATUS __fastcall CreateAppDir(
        IKEY_HANDLE    handle,
        unsigned char *appName,
        unsigned char *appGuidStr,
        int           directorySize,
        int           numberOfFiles
        );

        IKEY_STATUS __fastcall GetTokenName(
	IKEY_HANDLE handle,
	char	    tokenName[64]
        );

        void __cdecl  BlinkTokenLED(
		IKEY_HANDLE handle
        );

        int __fastcall SelectToken(
	IKEY_HANDLE   handle,
	char		  tokenName[64],
	unsigned long sn[2]
        );

        IKEY_HANDLE		handle;
	IKEY_STATUS		status, result;
        unsigned long   devicesAvailable;
	unsigned long   devicesInUse;
        char 	         tokenName[64];
	unsigned long   sn[2];
        unsigned long   ledState;
        //  end for IKEY Area
        char message[256];
        int   pw;
        char  filex[20][256];
        unsigned long   bytesWritten;


IKEY_STATUS  __fastcall CountDevices(
	IKEY_HANDLE        handle,
	unsigned long      openFlags,
	unsigned char      *openData,
	OpenDeviceCallback callback,
	void			   *context,
	unsigned long      *count)
{
	IKEY_STATUS	   status;
	*count	   = 0;

    status = OpenFirstDevice( handle,
                              openFlags,
                              openData,
                              callback,
                              context
                             );

	while ( RB_SUCCESS == status || RB_DEVICE_IN_USE == status )
    {
        if ( RB_SUCCESS == status )
        {
            (*count)++;
        }
        status = OpenNextDevice( handle,
                                 openFlags,
                                 openData,
                                 callback,
                                 context
                                );
    }

	if ( RB_UNIT_NOT_FOUND == status && *count > 0 )
	{
		status = RB_SUCCESS;
	}
	ikey_CloseDevice( handle );
	return( status );
} // CountDevices



IKEY_STATUS __fastcall OpenFirstDevice(
	IKEY_HANDLE        handle,
	unsigned long      openFlags,
	unsigned char      *openData,
	OpenDeviceCallback callback,
	void			   *context
)
{
	IKEY_STATUS status;

	// reset the open flags, turn off IKEY_OPEN_NEXT and turn on IKEY_OPEN_FIRST
	openFlags &= ~(IKEY_OPEN_FIRST | IKEY_OPEN_NEXT);
	openFlags |= IKEY_OPEN_FIRST;

	if ( callback )
	{
		if ( !callback( handle, openFlags,
		      openData,
		      context,
		      &status ) )
		{
			if ( RB_SUCCESS == status )
			{
				// skip this device
				status = RB_DEVICE_IN_USE;
			}
		}
	}
	else
	{
		status = ikey_OpenDevice( handle,		// handle to the device
		  openFlags,	// open flags
		  openData		// open reference data
								);
	}
	return( status );
}


IKEY_STATUS __fastcall OpenNextDevice(
	IKEY_HANDLE        handle,
	unsigned long      openFlags,
	unsigned char      *openData,
	OpenDeviceCallback callback,
	void			   *context
)
{
	IKEY_STATUS status;
	if ( (openFlags & IKEY_OPEN_SPECIFIC) != IKEY_OPEN_SPECIFIC )
	{
	    // reset the open flags, turn off IKEY_OPEN_FIRST and turn on IKEY_OPEN_NEXT
	    openFlags &= ~(IKEY_OPEN_FIRST | IKEY_OPEN_NEXT);
	    openFlags |= IKEY_OPEN_NEXT;

		if ( callback )
		{ if ( !callback( handle,openFlags,openData,context,&status ) )
			{ if ( RB_SUCCESS == status ) status = RB_DEVICE_IN_USE;
			}
		}
		else
		 status = ikey_OpenDevice( handle, openFlags,	openData );

	}
	else // indicate that only one device can be opened by serial number
          status = RB_UNIT_NOT_FOUND;

	return( status );
} // OpenNextDevice


void __fastcall encipher(const unsigned long *const v,unsigned long *const w,
   const unsigned long * const k)
{
   register unsigned long       y=v[0],z=v[1],sum=0,delta=0x9E3779B9,n=32;

   while(n-->0)
      {
      y += (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
      sum += delta;
      z += (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
      }

   w[0]=y; w[1]=z;
}

void __fastcall decipher(const unsigned long *const v,unsigned long *const w,
   const unsigned long * const k)
{
   register unsigned long       y=v[0],z=v[1],sum=0xC6EF3720,
				delta=0x9E3779B9,n=32;

   /* sum = delta<<5, in general sum = delta * n */

   while(n-->0)
      {
      z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
      sum -= delta;
      y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
      }

   w[0]=y; w[1]=z;
}

 void __fastcall DisplayError(
		   IKEY_STATUS   status,
		   char *        msg
		   )
{
    char message[256];

    message[0]=0;
    switch( status )
    {
        case RB_SUCCESS:
			break;

        case RB_CANNOT_OPEN_DRIVER:
         sprintf(message,"\nError (%d): Cannot open the driver.", status );
			break;

        case RB_INVALID_DRVR_VERSION:
         sprintf(message,"\nError (%d): Driver version not supported.", status );
			break;

        case RB_INVALID_COMMAND:
         sprintf(message,"\nError (%d): Invalid command pass to API.", status );
			break;

        case RB_ACCESS_DENIED:
         sprintf(message,"\nError (%d): Access denied.", status );
			break;

        case RB_ALREADY_ZERO:
         sprintf(message,"\nError (%d): Counter already zero.", status );
			break;

        case RB_UNIT_NOT_FOUND:
         sprintf(message,"\nError (%d): Device not found.", status );
			break;

        case RB_DEVICE_REMOVED:
         printf("\nError (%d): Device removed.", status );
			break;

        case RB_COMMUNICATIONS_ERROR:
         sprintf(message,"\nError (%d): Device communication error.", status );
			break;

        case RB_DIR_NOT_FOUND:
         sprintf(message,"\nError (%d): Directory does not exist.", status );
			break;

        case RB_FILE_NOT_FOUND:
         sprintf(message,"\nError (%d): File not found.", status );
			break;

        case RB_MEM_CORRUPT:
         sprintf(message,"\nError (%d): Device memory is corrupted.", status );
			break;

        case RB_INTERNAL_HW_ERROR:
         sprintf(message,"\nError (%d): Internal hardware error.", status );
			break;

        case RB_INVALID_RESP_SIZE:
         sprintf(message,"\nError (%d): Invalid response received from the device.", status );
			break;

        case RB_PIN_EXPIRED:
         sprintf(message,"\nError (%d): PIN retry attempts has expired.", status );
			break;

        case RB_ALREADY_EXISTS:
         sprintf(message,"\nError (%d): Directory or file already exist.", status );
			break;

        case RB_NOT_ENOUGH_MEMORY:
         sprintf(message,"\nError (%d): Not enough memory to perform the operation.", status );
			break;

        case RB_INVALID_PARAMETER:
         sprintf(message,"\nError (%d): Invalid parameter passed to API.", status );
			break;

        case RB_INPUT_TOO_LONG:
         sprintf(message,"\nError (%d): Input data is too long.", status );
			break;

        case RB_ALIGNMENT_ERROR:
         sprintf(message,"\nError (%d): Data alignment error.", status );
			break;

        case RB_INVALID_STATUS:
         sprintf(message,"\nError (%d): Invalid status returned from the device.", status );
			break;

        case RB_INVALID_FILE_SELECTED:
         sprintf(message,"\nError (%d): Invalid file selected or operation.", status );
			break;

        case RB_DEVICE_IN_USE:
         sprintf(message,"\nError (%d): The device is currently in use.", status );
			break;

        case RB_INVALID_API_VERSION:
         sprintf(message,"\nError (%d): The version of this library is not supported.", status );
			break;

        case RB_TIME_OUT_ERROR:
         sprintf(message,"\nError (%d): Communication time-out.", status );
			break;

        case RB_ITEM_NOT_FOUND:
	  sprintf(message,"\nError (%d): Item not found.\n", status );
			break;

        case RB_COMMAND_ABORTED:
         sprintf(message,"\nError (%d): Communication error, command aborted.", status );
			break;

        default:
         sprintf(message, "\nError (%d): An unknown error occurred.", status );
			break;
    }

  strcpy(msg,message);
  //if (strlen(message))
  //   Application->MessageBox(message,"Error Detected",MB_OK);
} // DisplayError






#ifdef __cplusplus
}
#endif

#endif