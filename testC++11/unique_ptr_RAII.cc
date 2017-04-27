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
void deleteTest(test *t)
{
	cout << t << endl;
	delete t;
}
int main()
{	
//	test t = testUnique();
//	t[0].a = 4;
//	t[1].a = 5;
//	cout << t[0].a << endl;
//	cout << t[1].a << endl;
	test *t = new test;
	cout << t << endl;
	unique_ptr<test,decltype(deleteTest)*> release(t,deleteTest);
	cout << "before return " << endl;
	return 0;	
}
