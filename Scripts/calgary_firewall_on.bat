@echo off
echo.
REM https://github.com/glennlopez/MCSE.RRC/tree/master/Scripts
netsh advfirewall set all state on
netsh advfirewall show currentprofile
echo.
echo [!] ENABLED the following firewall profiles:
echo        - Domain
echo        - Private 
echo        - Public
echo.
pause
