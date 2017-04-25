#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


thread_local int j = 0;
mutex m;
void foo() 
{ 
 	 m.lock();
 	 j++; // j is now 1, no matter the thread. j is local to this thread.
	 cout << j << endl;
 	 m.unlock();
}

void func()
{
  j = 0;
  std::thread t1(foo); 
  std::thread t2(foo); 
  t1.join();
  t2.join();
 // j still 0. The other "j"s were local to the threads
}

int main()
{
	func();
	return 0;	
}
