@echo off

echo.

rem chamar o programa prog2b e passar o caracter digitado como parametro 
if "%1" == ** goto MSG_ERRO_1

prog2b %3

echo.
echo.

echo valor retornado pelo programa: %errorlevel%

GOTO FIM


:MSG_ERRO_1

echo deve-se digitar um parametro. EX.: teste2b 3
GOTO FIM 

:FIM