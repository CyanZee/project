#include <iostream>
#include <string>
using namespace std;
string strOperator(string originStr)
{	
/*
	string afters;
	int i;
	string unique = "1234";	
	i = originStr.find('.', 0);
	cout << "+++ i: " << i << endl;
	afters = originStr.insert(i,unique);	
	cout << "+++ the originStr: " << originStr << endl;
	cout << "+++ the afters: " << afters << endl;
	return afters;
*/
	string afters;
	int i;
	i = originStr.find_last_of('/');
	afters = originStr.erase(0,i+1);
	cout << "+++ the originStr: " << originStr << endl;
	cout << "+++ the afters: " << afters << endl;	
	return afters;
}	


int main() 
{
	string reStr;
	reStr = strOperator("/home/x/test.h264");
	cout << "+++ the result string: " << reStr << endl;
	return 0;

}

