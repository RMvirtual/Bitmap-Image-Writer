:cls

@echo off

for /R tests\ %%f in (*.bat) do (
    call "%%f"
)

@echo on
