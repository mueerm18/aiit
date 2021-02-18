@echo off

ue08_argvargc.exe Mueller Krampl Grassmugg

:: %errorLevel%
:: pause


if %errorLevel% == 0 (
        echo Erfolgreich
) else (
	Color 4f
        echo Fehler
)

pause