#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string makeKey(const string &section,const string &name)
{
	string key = section + "." + name;
	return key; 
}

int main()
{
	cout << makeKey("section","name");
	return 0;	
}
