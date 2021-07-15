: Compile the script in Windows.
@echo off
cls
cd ../test

g++ test.cpp -o ../build/test/test.exe -I ../lib/boost_1_76_0 

cd ../script
@echo on