#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	if ((a == 4) || (a == 7))
	{
		cout << -1 << endl;
		return 0;
	}
	else {

		switch (a % 5) {
		case 0:
			cout << a / 5 << endl;
			break;
		case 1:
		case 3:
			cout << a / 5 + 1 << endl;
			break;
		case 2:
		case 4:
			cout << a / 5 + 2 << endl;
			break;

		}
		return 0;
	}

}