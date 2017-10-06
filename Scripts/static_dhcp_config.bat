@echo off
REM UPDATED: 06/10/17
SETLOCAL EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)
echo.

REM START HERE
echo.
call :colorEcho 02 "Glenns' Network Config"
echo.
call :colorEcho 0e "(because using the mouse is a waste of time)"
echo.
echo [A] Set Static IP 
echo [B] Set DHCP 
echo. 

:choice 
SET /P C=Choose A or B: 
for %%? in (A) do if /I "%C%"=="%%?" goto A 
for %%? in (B) do if /I "%C%"=="%%?" goto B 
goto choice 
:A 

@echo off 
cls
call :colorEcho 19 "Please enter Static IP Address Information"
echo.
echo Static IP Address: 
set /p IP_Addr=

cls
echo [!] WARNING: Script doesnt work if Gateway is left blank 
echo Default Gateway:
set /p D_Gate=

echo [!] WARNING: Script doesnt work if Subnet Mast is left blank
echo Subnet Mask: 
set /p Sub_Mask=

echo Setting Static IP Information 
netsh interface ip set address "mcse" static %IP_Addr% %Sub_Mask% %D_Gate% 1 
netsh int ip show config 
pause 
goto end

:B 
@ECHO OFF 
ECHO Resetting IP Address and Subnet Mask For DHCP 
netsh int ip set address name = "mcse" source = dhcp

ipconfig /renew

ECHO Here are the new settings for %computername%: 
netsh int ip show config

pause 
goto end 
:end

REM COLOR ECHO FUNCTION
:colorEcho
echo off
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i

