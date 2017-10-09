@echo off
echo.
REM https://github.com/glennlopez/MCSE.RRC/tree/master/Scripts
netsh advfirewall set all state off
netsh advfirewall show currentprofile
echo.
echo [!] DISABLED the following firewall profiles:
echo        - Domain
echo        - Private 
echo        - Public
echo.
pause
