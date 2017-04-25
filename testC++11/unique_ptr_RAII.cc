#include <iostream>
#include <memory>

using namespace std;

struct test{
	test():a(3){
		cout << "test build" << endl;
	}	
	~test(){
		cout << "test dest" << endl;
	}
	int a;
};


test testUnique()
{
	test* t = new test[2];
	{	
		unique_ptr<test[]> ut;
		ut.reset(t);
	}
	return *t;	
}

int main()
{	

	test t = testUnique();
//	t[0].a = 4;
//	t[1].a = 5;
//	cout << t[0].a << endl;
//	cout << t[1].a << endl;
	cout << "before return " << endl;
	return 0;	
}
