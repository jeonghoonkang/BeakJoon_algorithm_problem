#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int testcase;
int m = 0;
int	n = 0;
int value;
int check = 0;
int day = 0;
int d[8] = { 1,0,0,1,-1,0,0,-1 };
int Tomato[1001][1001] = { 0, };
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

bool check_tomato(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	if (Tomato[x][y] == 0) {
		return true;
	}
	else { return false; }
}
void bfs_algorithm(int num) {
	if (num == 2) {
		while (!q2.empty()) {
			int check_data_x = q2.front().first;
			int check_data_y = q2.front().second;

			q2.pop();
			for (int i = 0; i * 2 < 8; i++) {
				if (check_tomato(check_data_x + d[i * 2], check_data_y + d[i * 2 + 1])) {
					q1.push(make_pair(check_data_x + d[i * 2], check_data_y + d[i * 2 + 1]));
					Tomato[check_data_x + d[i * 2]][check_data_y + d[i * 2 + 1]] = 1;

				}
			}
		}

		day++;
	}
	else {
		while (!q1.empty()) {
			int check_data_x = q1.front().first;
			int check_data_y = q1.front().second;
			q1.pop();

			for (int i = 0; i * 2 < 8; i++) {
				if (check_tomato(check_data_x + d[i * 2], check_data_y + d[i * 2 + 1])) {
					q2.push(make_pair(check_data_x + d[i * 2], check_data_y + d[i * 2 + 1]));
					Tomato[check_data_x + d[i * 2]][check_data_y + d[i * 2 + 1]] = 1;

				}
			}
		}
		day++;
	}

}

int main() {


	cin >> m >> n;

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {

			cin >> value;
			Tomato[j][k] = value;

			if (value == 1) {
				q1.push(make_pair(j, k));
				check++;
			}
		}
	}


	if (check == 0) {
		cout << -1 << endl;
		
	}
	else if (check == m*n) {
		cout << 0 << endl;
		
	}
	else {
		while (!q1.empty() || !q2.empty()) {
			if (q1.empty()) {
				bfs_algorithm(2);

			}
			else {
				bfs_algorithm(1);


			}
		}

		check = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j < m; j++) {
				if (Tomato[i][j] == 0) {
					check = 1;
					
				}
			}
		}
		if (check==1) cout << -1 << endl;
		else cout << day - 1 << endl;
		
	}
}
