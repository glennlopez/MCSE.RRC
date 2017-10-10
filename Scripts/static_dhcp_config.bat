@echo off 
echo.
REM https://github.com/glennlopez/MCSE.RRC/tree/master/Scripts
echo Glenns Network Config-er:
echo (because using the mouse to configure your network is a waste of time)
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
echo [!] Please enter Static IP Address Information
echo Static IP Address: 
set /p IP_Addr=

cls
echo [!] WARNING: Script doesnt work if Gateway is left blank 
echo Default Gateway:
set /p D_Gate=

cls
echo [!] WARNING: Script doesnt work if Subnet Mask is left blank
echo Subnet Mask: 
set /p Sub_Mask=

cls
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
ipconfig /all

pause 
goto end 
:end

