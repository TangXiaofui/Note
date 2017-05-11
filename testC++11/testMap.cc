#include <iostream>
#include <map>
using namespace std;


int main(int argc,char *argv[])
{
	map<int,int> a;
	for(int i = 10 ; i > 0; i--)
		a[i] = i;
	
	for(auto m = a.begin() ; m != a.end() ; ++m)
	{
		cout << "first = " << m->first << " second = " << m->second  << " " << endl;
	}
}
