#include <iostream>
#include <map>
using namespace std;


int main(int argc,char *argv[])
{
	map<int,int> a;
	for(int i = 0 ; i < 10 ; i++)
	{
		a[i] = i;	
	}

	for(auto &e : a){
		cout << e.first << endl;	
	}
	//find 返回的是一个const类型因此不能使用引用
//	auto &p = a.find({2,2});
//	cout << p->first << " " << p->second << endl;
}
