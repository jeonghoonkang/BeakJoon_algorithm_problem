#include <vector>
#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

void main() {
	vector<float> a;
	a.push_back(3.14);
	cout << a[0] << endl;
	vector<float> b(10);
	b[0] = 2.14;
	b[1] = 2.44;
	b[2] = 5.67;
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << endl;
	}
	vector<pair<int, int>> xydata;
	xydata.push_back(make_pair(3, 4));
	xydata.push_back(make_pair(5, 1));
	cout << xydata[0].first << endl;
	cout << xydata[1].second << endl;
	queue<pair<int, int>> q;
	q.push(make_pair(1,2));
	q.push(make_pair(3, 4));
	q.push(make_pair(5, 6));
	cout <<"큐의 맨 앞 변수:"<< q.front().first << endl;
	vector<queue<pair<int,int>>> a;



}