@echo off
echo.
REM updated 10/08/2017 - Glenn
netsh advfirewall set all state off
echo [!] DISABLED the following firewall profiles:
echo        - Domain
echo        - Private 
echo        - Public
echo.
pause
