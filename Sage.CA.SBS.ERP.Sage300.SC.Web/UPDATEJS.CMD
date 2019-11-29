@XCOPY %~dp0\Areas\SC\Scripts\*.* "C:\Sage\Sage 300\Programs\Online\Web\Areas\SC\Scripts" /E/F/R/Y
@IF NOT ["%errorlevel%"]==["0"] PAUSE