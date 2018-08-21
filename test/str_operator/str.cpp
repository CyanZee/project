#include <iostream>
#include <string>
using namespace std;
string getFilename(string filepath)
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
	i = filepath.find_last_of('/');
	afters = filepath.erase(0,i+1);
	return afters;
}	

string getPath(string filepath)
{
	string afters;
	int i;
	i = filepath.find_last_of('/');
	afters = filepath.erase(i+1);
	return afters;
}

string eraseTail(string filepath)
{
	string afters;
	int i;
	i = filepath.size();
	cout<< "+++ i = " << i << endl;
	afters = filepath.erase(i - 8);	
	return afters;
}
int main() 
{
	string filename;
	filename = getFilename("/home/x/test.h264");
	cout << "+++ the filename string is: " << filename << endl;
	string path;
	path = getPath("/home/x/test.h264");
	cout << "+++ the path string is: " << path << endl;
	string result;
	result = eraseTail("/home/az/cyan/test/v1_cyan.tar.bz2");
	cout << "+++ the result string is: " << result << endl;
	return 0;

}

