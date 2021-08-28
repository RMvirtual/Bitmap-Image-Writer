:cls

@echo off

for /R tests %%f in (*.bat) do (
    if not "%%x" == "%~0" call "%%x"
)

@echo on

:for /R tests %%f in (*.bat) do Echo %%f