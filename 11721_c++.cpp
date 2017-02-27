#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int len=a.length();
	int i = 0;
	for (i = 0; i < len / 10; i++) {
		cout << a.substr(i * 10, 10) << endl;
	}
	cout << a.substr((i) * 10, (len + 1)-i*10) << endl;
}