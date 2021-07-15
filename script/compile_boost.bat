: Compile the boost binaries.

@echo off
cd ../lib/boost_1_76_0
bootstrap.bat
b2.exe
@echo on

