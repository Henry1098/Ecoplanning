		iKey Driver Version <32-Bit> 4.1.1.1006
		README.TXT
		Copyright © 2010 SafeNet, Inc.
		All Rights Reserved.
---------------------------------------------------------------------------- 

Thank you for choosing the iKey Driver from SafeNet, Inc. 
The iKey Driver contains the drivers and libraries used for SafeNet's
iKey Security Tokens.

This README file provides information on product installation and 
uninstallation, new features, last-minute news and where to go  
for more information or to report problems.

-----------------------------
 Table of Contents
-----------------------------

1.0 Installing iKey Driver
    1.1 Compatibility
    1.2 Installation	
	1.2.1 Installation by CD for MSI Installer
        1.2.2 Installation by Windows Group Policy
	1.2.3 Installation by CD for EXE Installer
2.0 What's New in This Release?
	2.1 Problems Fixed in This Release
3.0 Late-Breaking Information
4.0 Reporting Problems

----------------------------------------------------------
 1.0 INSTALLING IKEY DRIVER
----------------------------------------------------------

-----------------------------
 1.1 Compatibility
-----------------------------

IMPORTANT! Please read this section completely BEFORE running the
iKey Driver setup program to ensure that you are aware of any installation 
issues that may pertain to your system and environment.

 1. A Windows-based installation program is provided to 
    make installation of the iKey Driver quick and easy.
    The installation program runs only on the following operating
    systems:

    for IKEYDRVR:
    - Windows XP 
    - Windows 2000 Server
    - Windows 2003 Server
    - Windows Vista
    - Windows 2008 Server
    - Windows 7

   All systems require a functional USB controller to be installed prior
    to installation of the iKey Driver.

 2. On Toshiba Model T440 CDX laptops, iKey Security Tokens will not 
     be recognized. This is due to an incompatibility with the USB 
     controller used in the iKey Security Tokens. Currently, there is no 
     known workaround for this issue.

 3. Windows 2003/XP/Vista

    - When uninstalling the iKey Driver, all iKey Security Tokens must 
      be removed PRIOR to uninstallation. This prevents you from being 
      logged off during driver uninstallation if you are using an iKey Security 
      Token for Smart Card logon.

 4. Windows Vista

    - iKey Driver MSI installer works on Windows Vista with administrator rights only.

 5. Windows 7

    - Follow the steps given below to install iKey driver on Windows 7 using msi installer/package:

    a. Start command prompt with administrator privileges using “Run as administrator”.

    b. Execute the command, Msiexec /i IKEYDRVR2KXP.MSI 
    NOTE: Please provide the full path of the msi package

 6. If you are planning to upgrade your operating system, uninstall the iKey 
     Driver BEFORE you perform the system upgrade. After you have
     upgraded your system, you can then re-install the iKey Driver.

-----------------------------
 1.2 Installation
-----------------------------

---------------------------------------------
   1.2.1 Installation by CD for MSI Installer
---------------------------------------------

The following instructions assume you are installing the iKey software 
using a CD, and  that you are installing from CD-ROM drive D. If a drive 
other than drive D is used,  substitute D: with the appropriate drive letter. 
(If installing from the Internet,  double-click the file you downloaded to 
start the installation process.)

 - Insert the CD into the CD-ROM drive.

  - If CD autorun is set, the installation should start. If not, from the Start 
    menu, select Run. The Run dialog box appears. 

    Type msiexec /I D:\IKEYDRVR.MSI at the Open prompt and click OK, where
    D is the CD Drive.
       
  - Follow the on-screen instructions to complete the installation. 
     
  - You can access this readme file from the 
    %SystemDrive%\Program Files\SafeNet\iKey Driver folder, where
    %SystemDrive% is the system drive later of where Windows is installed. 

----------------------------------------------------------------
   1.2.2 Installation by Windows Group Policy for MSI Installer
----------------------------------------------------------------

 Assumption: Client machine is part of a domain using a Windows 2000 machine 
 as domain controller.

 Go to the domain controller machine and perform the following steps:

  1. Start mmc.exe.
  2. Using the option from the main menu of the mmc window open the "Add/Remove 
     Snap-in" dialog. Select the "Group Policy" Object, click on Add
  3. Expand the Default Domain Policy object in the MMC Console window to 
     select the Software installation node under Computer Configuration - Software 
     Settings.
  4. Right click on Software Installation and select New->Package option.
  5. Browse to open the iKeyDriver MSI installer IKEYDRVR.MSI and click on 
     Open. (By default the deployment method will be "Assign.")
  6. Select the new package created in Step 5 above and right-click to view the 
     package properties.
  7. Select the "Uninstall this application when it falls outside the scope of 
     management" 
     option from the Deploy Software tab and click OK.
  8. The package will now be installed and available in the Add/Remove Programs 
     applet in the control panel on the client system on the next logon.

 Now the client machine only needs a reboot to install or remove the software.


---------------------------------------------
   1.2.3 Installation by CD for EXE Installer
---------------------------------------------

The following instructions assume you are installing the iKey software 
using a CD, and  that you are installing from CD-ROM drive D. If a drive 
other than drive D is used,  substitute D: with the appropriate drive letter. 
(If installing from the Internet,  double-click the file you downloaded to 
start the installation process.)

  - Insert the CD into the CD-ROM drive.

  - If CD autorun is set, the installation should start. If not, from the Start 
    menu, select Run. The Run dialog box appears. 

    Type IKEYDRVR.EXE at the Open prompt and click OK, where D is the CD Drive.
       
  - Follow the on-screen instructions to complete the installation. 
     
  - Following is the command line option list which will be supported for installer.

	1) Silent Installation :
		iKeyDrvr.msi /quiet
			or
		msiexec /I iKeyDrvr.msi /qn

	2) Display Options:
		For ReducedUI -->  iKeyDrvr.msi /qr
		For Basic UI --> iKeyDrvr.msi /qb
		For No UI --> iKeyDrvr.msi /qn
		For Full UI --> iKeyDrvr.msi /qf
	3) Restart Options
		iKeyDrvr.msi /forcerestart"
		iKeyDrvr.msi /norestart"

	4) LogPath:
		iKeyDrvr.msi /L* <LOGPATH>
			or
		msiexec /I iKeyDrvr.msi /L* <LOGPATH>
	 (Here <LOGPATH> refers to name of text file in which logs to be stored)


	5) Virtual Readers:
		iKeyDrvr.msi VR=ON READERS=2
			or
		msiexec /I iKeyDrvr.msi VR=ON READERS=2

	6) No Virtual readers
		iKeyDrvr.msi VR=OFF
			or
		msiexec /I iKeyDrvr.msi VR=OFF

	7) Uninstall
		msiexec.exe /x iKeyDrvr.msi

	8) Silent Uninstall
		msiexec.exe /x iKeyDrvr.msi /qn

	9) DRVR_FLAGS
		msiexec.exe /i iKeyDrvr.msi DRVR_FLAGS=RSON

	10) LED FLASH
		msiexec.exe /i iKeyDrvr.msi LED_FLASH_DURATION=255
		msiexec.exe /i iKeyDrvr.msi LED_FLASH_CYCLE=255

Note: Sequence of command line options and space matters while installing through EXE. Use the command “msiexec \?” to view the supported MSI command line installation options on Windows 2003 and XP.
 
  - You can access this readme file from the 
    %SystemDrive%\Program Files\SafeNet\iKey Driver folder, where
    %SystemDrive% is the system drive later of where Windows is installed. 

----------------------------------------------------------
 2.0 WHAT'S NEW IN THIS RELEASE?
----------------------------------------------------------

This release of the iKey Driver is for supporting iKey 1000 SDK which is now a
single installer for 32-bit and 64-bit platforms.
The iKeyDriver can be installed along with ikey1000 SDK intelligently depending
upon the platform detected by the ikey1000 SDK

-----------------------------------
 2.1 Problems Fixed in This Release
-----------------------------------

v4.1.1.1006 Release fixes:

- MKS 93237 - On XP 64,General Information displayed in iKey Token Utility is incomplete.

- MKS 93011# Unable to initialize iKey 1000 when the default value of certificate password retry counter is changed.

- MKS 93260 - Inconsistent behavior of iKey Driver un-installation in the case of 32-bit & 64-bit OSes.

v4.1.1.1005 Release fixes:

- MKS 88951# Creating File of size more than whatever memory left in a directory leads to memory corruption.

v4.1.1.1003 Release fixes:

- MKS 84395# Command Line Option "VR=off" not working with msi driver package.
- MKS 83851# Installation proceeds and does not prompt any error message on installing older version of iKey driver MSI installer on newer version of iKey driver EXE installer.

v4.1.1.1002 Release fixes:

- MKS 83846# Unable to uninstall iKey driver. Exe (4.1.1.1) using command line options.
- MKS 83758# Installation of BSec Client with "iKey driver" option enabled fails if iKey driver is already installed through EXE installer’ 

v4.1.1.1001 Release fixes:

- iKey driver binaries are WHQL certified by Microsoft for Windows 7.
- Task# 66034: VR=OFF not working with iKey driver v4.1.0.x.

v4.1.0.6 Release fixes:

- Task# 42515: Unable to install ikey driver (v 4.1.0.0005 exe version) on Win 2000 Professional and Win 2000 server.

V4.1.0.5 Release fixes:

- Task# 37303: iKey Driver installer returns warning message "iKey driver has not passed Windows Logo Testing" while upgrading iKeydriver from older version to latest 4.0.1.2 version. 
- Task# 37197: inconsistency present in iKeydriver's repair option behavior when token is inserted into system.
- Task# 41834: iKey driver installer (32bit msi version) get unknown error message and leaves the installer partially loaded.
- Task# 41833: ikeydriver installer (32bit exe version) get unknown error message.
- Task# 41832: Readme.txt for 64bit driver (exe version) has a typo in the options section.

v4.1.0.4 Release fixes:

- Task#37151: Readme Files are not updated with command line option supported for installing 32 bit and 64 bit ikey driver.
- Task#37110: Fix the BSOD when iKey is connected and system is awaken from sleep/hibernate state.
- Task#39478: Customer’s Custom Service is failed to get loaded because the iKeyDriver doesn’t get loaded timely.
- TASK#41173: License and ReadMe information are not shown properly in iKey driver installer both 32 bit and 64 bit.
- Task#37153: Silent installation asking for .iss file path when done using command line. 
- Task#35036: Change 32bit and 64bit ikeydriver installer to allow to repair.
- Task#35012: Add the functionality to install 64-bit iKey driver installer in silent mode. 

v4.0.1.1002 Release fixes:
- Correct the ReadME versioning information.

v4.0.1.0002 Release fixes:
- Support the repair option in iKeyDriver installer. 

v4.0.0.1018:
 - 64 bit version of the Driver Installer must be identified as 64 bit version.  

v4.0.0.1017:
 -  Add the command line options to be used with EXE INstaller in ReadMe file.

v4.0.0.1016:
 - Replace driver files with WHQLed driver files.


------------------------------------------------------
 3.0 LATE-BREAKING INFORMATION
------------------------------------------------------

Go to SafeNet web site at http://www.safenet-inc.com for the most 
up-to-date product information.

===============================================
SafeNet, Inc. Customer Connection Center (C3)
http://c3.safenet-inc.com


-------------------------------------------------------
 4.0 REPORTING PROBLEMS
-------------------------------------------------------

If you find any problems while using the iKey Driver, please contact 
SafeNet Technical Support using any of the following methods:


Americas
=================================
Internet - http://www.safenet-inc.com/support/index.asp
E-mail - support@safenet-inc.com


United States
---------------------------------------------------------
Telephone - (800) 545-6608, (410) 931-7520 


Europe
=================================
E-mail - support@safenet-inc.com


France
---------------------------------------------------------
Telephone - 0825 341000


Germany
---------------------------------------------------------
Telephone - 01803 7246269


United Kingdom
---------------------------------------------------------
Telephone -  +44 (0) 1276 608000, +1 410 931-7520 (Intl)


Pacific Rim
=================================
E-mail - support@safenet-inc.com


Australia and New Zealand
---------------------------------------------------------

Telephone - +1 410 931-7520(Intl)


China
---------------------------------------------------------

Telephone - (86) 10 8851 9191


India
---------------------------------------------------------

Telephone - +1 410 931-7520 (Intl)


Taiwan and Southeast Asia
---------------------------------------------------------

Telephone - (886) 2 27353736,+1 410 931-7520 (Intl)


OTHER COUNTRIES
---------------
Customers not in countries listed above, please contact your local
distributor.



Readme.txt July 16, 2010, V. 4.1.1.1006