: Compile the script in Windows.
@echo off
cd ../src

g++ -g helloworld.cpp -o ../build/helloworld.exe

cd ../test

: g++ -g test.cpp -o ../build/test/test.exe -I ../lib/boost_1_76_0
g++ test.cpp -o ../build/test/test.exe -I ../lib/boost_1_76_0 

cd ../script
@echo on