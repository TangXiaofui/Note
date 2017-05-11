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
	
	void testMove(int &&num){
		cout << "testMove(int &&num)" << endl;	
	}
	void testMove(const int &&num){
		cout << "testMove(const int &&num)" << endl;
		testMove(int(num));
	}
	char *str;	
};

int main()
{
	test t2(  move(test((char *)"abc")) );
	test t3;
	const int i = 3;
	t3.testMove(move(i));

	int a = 3;
	int &&b = move(a);
	b = 4;
	cout << a << " " << b << endl;
	return 0;
}
