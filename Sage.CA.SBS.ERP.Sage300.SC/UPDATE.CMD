@XCOPY %~dp0\BUILD32\RUNTIME\*.* "C:\Sage\Sage 300\Programs\SC63A" /E/F/R/Y
@IF NOT ["%errorlevel%"]==["0"] PAUSE