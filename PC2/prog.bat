@echo off

ECHO INICIO DO ARQUIVO DE LOTE

REM  Verificar se foi passado algum parâmetro via linha de comando
IF "%1" == "" goto msg_erro  


REM Executar prog1 passando como parâmetro para ele o parâmetro digitado via linha de comando pelo usuário 
ECHO    Executando prog1...
prog1 %1 


REM Se prog1 tiver retornado com um código de erro
if NOT %errorlevel% == 0 goto proximo_prog
   ECHO.
   ECHO    Prog1 encerrado devido a um erro!!!
   goto end


REM Executar prog2 passando como parâmetro para ele o código de retorno de Prog1 
:proximo_prog
ECHO.
ECHO    Executando prog2...
prog2 %errorlevel%
ECHO.
if %errorlevel% == 0 goto end




:msg_erro
ECHO Deve ser passado algum caracter como parametro. Ex.: prog A

:end
ECHO FIM DO ARQUIVO DE LOTE
