#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int tomato_array[1001][1001];
int check[1001][1001];
int m, n;
int check_1=0;
int dx[5] = { 1,-1,0,0 };
int dy[5] = { 0,0,1,-1 };
int main()
{
	queue<pair<int, int>> q;
	scanf("%d %d", &m, &n);

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &tomato_array[i][j]);
			
			if (tomato_array[i][j] == 1) {
				check_1 = 1;
				q.push(make_pair(i, j));
			}
		}
	}
	if (check_1 == 0) {
		cout << -1 << endl;
		return;
	}
	else if (q.size() == m*n) {
		cout << 0 << endl;
		return;
	}
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (tomato_array[nx][ny] == 0 && check[nx][ny] == -1)
			{
				if (nx >= 0 && ny >= 0 && nx < n && ny < m)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int maxVal = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (maxVal < check[i][j])
				maxVal = check[i][j];
		}
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (tomato_array[i][j] == 0 && check[i][j] == -1)
				maxVal = -1;
		}
	}
	cout << maxVal << endl;
}

