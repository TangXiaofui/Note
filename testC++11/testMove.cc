#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct test{
	test():str(NULL){}
	test(const char*msg)
	{
		str = new char[strlen(msg)];
		memcpy(str,msg,strlen(msg));	
	}
	test(test &&r){
		cout << "test(&&)" << endl;
		str = r.str;
		r.str = NULL;
	}
	~test(){ 
		cout << "~test" << endl;
			delete[] str;
	}
	

	char *str;	
};

int main()
{
	test t2(  move(test((char *)"abc")) );
	test t3;
	return 0;
}
