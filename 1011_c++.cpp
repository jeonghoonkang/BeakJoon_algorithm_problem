#include <stdio.h>
#include <iostream>
#include<cmath>
using namespace std;

int main()
{

	int n=1;
	cin >> n;
	int * array=new int[n]; //int a[n]; 선언이 불가능한 이유?: const int a=5;로 만들어 줘야함,.
/*	const 예약어를 붙이지 않고 정적할당을 사용하면 에러가 나는 이유는 const를 붙이지 않으면 그 변수가 변할 수 있기 때문에
 배열의 크기를 정확하게 모르므로 스택부분에서 이 배열의 메모리를 얼마나 잡아야 하는지를 알 수가 없다.
그래서 이와 같이 일반 변수의 크기만큼에 해당하는 배열을 선언하기 위해서는 동적할당을 이용해서 선언을 해야한다. */
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int k=int(sqrt(b-a));
		if (k*(k + 1) + a - b< 0) {
			k=k+1;
		}
		if (k*(k + 1) + a - b >= k) {
			array[i] = k * 2 - 1;
		}
		else {
			array[i] = k * 2;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << array[i] << endl;
	}

}