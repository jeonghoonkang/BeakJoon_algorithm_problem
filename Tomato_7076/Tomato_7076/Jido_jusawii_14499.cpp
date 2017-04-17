#include<iostream>
#include<vector>
#include<string>
using namespace std;


int m,n,x, y, k;
int Jido[21][21] = { 0, };
int jusawii[6] = { 0,0,0,0,0,0 };
int jusawii_pair[5] = { 0,2,1,4,3 };
int cross_pair[7] = { 0,6,5,4,3,2,1 };
int go[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int myungr[1001];
bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	else
		return true;
}
int main() {
	cin >> n >> m >> x >> y >> k;
	int val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> val;
			Jido[i][j] = val;
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> val;
		myungr[i] = val;
	}
	for (int i = 0; i < k; i++) {
		val = myungr[i];
		int xx = x + go[val][0];
		int yy = y + go[val][1];
		if (check(xx, yy)) {
			x = xx;
			y = yy;
			int temp=jusawii[0];
			jusawii[0] = jusawii[val];
			int temp2 = jusawii[jusawii_pair[val]];
			jusawii[jusawii_pair[val]] = temp;
			jusawii[val] = jusawii[5];
			jusawii[5] = temp2;
			
			if (Jido[x][y] == 0) {
				Jido[x][y] = jusawii[0];
				
			}
			else {//지도가 0이 아닌경우
				jusawii[0] = Jido[x][y];
				Jido[x][y] = 0;
			}
			cout << jusawii[5] << endl;
		}
	}
}