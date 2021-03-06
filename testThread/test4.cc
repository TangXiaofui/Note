#include <iostream>       // std::cout
#include <chrono>         // std::chrono::milliseconds
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex

std::timed_mutex mtx;

void fireworks(int i) {
  // waiting to get a lock: each thread prints "-" every 200ms:
  std::cout << i ;
  while (!mtx.try_lock_for(std::chrono::milliseconds(2))) {
    std::cout << "-" ;
  }
  // got a lock! - wait for 1s, then this thread prints "*"
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  std::cout << "*" << i << std::endl;
  mtx.unlock();
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(fireworks,i+1);

  for (auto& th : threads) th.join();

  return 0;
}
