#include "src/test/cpp/pointer-comparison/fixture.h"

#include <chrono>
#include <thread>
#include <iostream>

#include "src/main/cpp/maths/vector/vector.h"

void takeMe()
{
  Maths::Vector vector {1, 1};
}

void takeMe(Maths::Vector vector)
{
  auto myVector = vector;
}

void takeMe(Maths::Vector* vector)
{
  auto myVector = *vector;
}

TEST_F(PointerComparisonTest, ShouldDisplayPointerStuff)
{
  Maths::Vector vector {1, 1};

  // baseline of around 1250ms for 1,000,000,000 iterations of doing nothing.
  int ms1250 = 1000000000;

  // 1422 ms running takeMe 1,000,000,000 times 
  // with nothing in the body or params other than takeMe();
  
  // Below value takes around 1000ms for 1,000,000 functions calls
  // when taking param by copy.
  int takeMeWithVectorTimeMs1000 = 10000000;

  // pointer took 11 milliseconds to process 1,000,0000 function calls.
  // Works passing in the address of vector in params too such as
  // like &vector.
  Maths::Vector* vectorPointer = &vector;

  // Changing copy by value to reference took 14-17 milliseconds.
  // i.e. takeMe(Maths::Vector& vector).

  // Const reference also took 13 milliseconds for 1,000,0000 function calls.
  // i.e. takeMe(const Maths::Vector& vector).

  // Adding copy body to const reference gave 1000ms.
  // Adding copy body to pointer gave about 1000ms.
  // Adding copy body to pass by value gave about 1985.
  // Adding create body to no params gave about 1300.

  int takeMeWithVectorTimeMs100 = 1000000;

  auto start = std::chrono::high_resolution_clock::now();

  auto thing = [takeMeWithVectorTimeMs1000]() {
    for (int i = 0; i < takeMeWithVectorTimeMs1000; i++)
      takeMe();
  };

  // Threads runs about 10x faster than the below.
  for (int i = 0; i < takeMeWithVectorTimeMs1000; i++) {
    takeMe();
  }

  // Fast threads.
  std::thread thread1 (thing);
  std::thread thread2 (thing);
  std::thread thread3 (thing);
  std::thread thread4 (thing);
  std::thread thread5 (thing);
  std::thread thread6 (thing);
  std::thread thread7 (thing);
  std::thread thread8 (thing);
  std::thread thread9 (thing);
  std::thread thread10 (thing);

  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  thread6.join();
  thread7.join();
  thread8.join();
  thread9.join();
  thread10.join();
  
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
    stop - start);

  std::cout << "It takes " << duration.count()
    << " milliseconds to process.\n";
}