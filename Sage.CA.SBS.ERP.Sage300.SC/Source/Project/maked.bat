@ECHO OFF
SET __VIEWDEBUG__=%VIEWDEBUG%
SET VIEWDEBUG=1
CALL MAKE %1 %2 %3 %4 %5 %6 %7 %8 %9
SET VIEWDEBUG=%__VIEWDEBUG__%
SET __VIEWDEBUG__=
