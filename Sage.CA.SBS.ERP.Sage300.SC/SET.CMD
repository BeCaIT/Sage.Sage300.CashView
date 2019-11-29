REM *************************************************
REM     BATCH FILE TO ESTABLISH ALL ENVIRONMENT
REM     VARIABLES NECESSARY FOR BUILDING TU
REM *************************************************


REM *************************************************
REM    RUN VISUAL STUDIO COMPILER FROM COMMAND LINE
REM *************************************************

CALL "C:\Program Files (x86)\Microsoft Visual Studio 8\VC\vcvarsall.bat"


REM ***************************************************
REM     SPECIFY THE LOCATION OF
REM     - MICROSOFT VISUAL BASIC 6.0 FOLDER
REM     - MICROSOFT CAB SOFTWARE DEVELOPMENT KIT FOLDER
REM     - MICROSOFT AUTHENTICODE FOLDER
REM ***************************************************

PATH "C:\Program Files\Microsoft Visual Studio\Vb98";"C:\Program Files\CabSDK\BIN";"C:\Program Files\AuthCode";%PATH%


REM *************************************************
REM     32-BIT SWITCH - UNCOMMENT FOR 32-BIT
REM *************************************************

SET ACCPAC_WIN32=YES

REM *************************************************
REM     SPECIFY THE PROJECT PATH
REM *************************************************

SET PROJPATH=%CD%



REM *************************************************
REM     SPECIFY THE LOCATION OF ICONS - SELECT ONE
REM *************************************************

SET INCLUDE=C:\PLUSWDEV\ICONS;C:\PLUSWDEV\BITMAPS;C:\PLUSWDEV\INCLUDE;%INCLUDE%
REM SET INCLUDE=C:\PLUSWDEV\ICONS;C:\PLUSWDEV\BITMAPS;C:\PLUSWDEV\INCLUDE



REM ******************************************************
REM     SPECIFY THE LOCATION OF LIBRARY FILES - SELECT ONE
REM ******************************************************

SET LIB=C:\PLUSWDEV\LIB;%LIB%
REM SET LIB=C:\PLUSWDEV\LIB



REM ***********************************************************
REM     SPECIFY THE LOCATION OF SDK TEMPLATE FILES - SELECT ONE
REM ***********************************************************

REM SET TEMPLATE=C:\PLUSWDEV\TEMPLATE;%TEMPLATE%
SET TEMPLATE=C:\PLUSWDEV\TEMPLATE



REM ***********************************************
REM     SPECIFY THE LOCATION OF THE SDK BIN FOLDER
REM ***********************************************

SET PATH=C:\PLUSWDEV\BIN;%PATH%
REM SET PATH=C:\PLUSWDEV\BIN