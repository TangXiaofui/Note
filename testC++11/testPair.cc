#include <utility>
#include <iostream>
using namespace std;

//max a b : b
//max a c : a

int main(int argc,char *argv[])
{
	pair<int,int> a(1,3),b(2,1),c(1,2);
	cout << "max a b : " << (a > b ? "a" : "b") << endl;
	cout << "max a c : " << (a > c ? "a" : "c") << endl;
	return 0;	
}
