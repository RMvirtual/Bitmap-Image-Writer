: Compile the script in Windows.
cd ../src

g++ -g helloworld.cpp -o ../build/helloworld.exe -I ../lib/boost_1_76_0

cd ../test

g++ -g test.cpp -o ../build/test/test.exe -I ../lib/boost_1_76_0

cd ../script