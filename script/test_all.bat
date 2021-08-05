cls

@echo off

for /R %%x in (tests\*.bat) do (
    if not "%%x" == "%~0" call "%%x"
)

@echo on