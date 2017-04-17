#include <cstdio>
#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int Pan[21][21];
int Pan_check[21][21];
int Pan_N[21][21];
int Pan_W[21][21];
int Pan_E[21][21];
int Pan_S[21][21];
int n, val=0;

int Check_Pan(int * tmp[21][21]) {
	int now_block = *tmp[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (now_block < *tmp[i][j])
				now_block = *tmp[i][j];

		}
	}
	return now_block;
};

int DP_BFS_Algorithm(int to) {
	int now_block = Check_Pan(Pan);
	int	next_block;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (now_block < Pan[i][j])
				now_block = Pan[i][j];

		}
	}
	//4가지 방향으로 조사를 한 결과를 비교한다.그중 가장 큰 녀석을 넥스트 블록에 담고 그것이 현재 큰놈 보다도 더 크면 한번더 수행한다.
	int count = 0;
	
	while (count<5) {
		int recent_i = -1;
		int recent_j = -1;
		for (int i = 0; i < n; i++) {//서쪽
			for (int j = 0; j < n; j++) {
				if (Pan[i][j] != 0) {
					val = Pan[i][j];
					
						for(int k = i + 1; k < n; k++) {
							if (Pan[i][k] != 0) {
								if (val == Pan[i][k] && Pan_check[i][k] == Pan_check[i][j])
								{
									Pan_check[i][j] = 1;
									Pan_check[i][k] = 1;
									if (recent_i = -1) {
										Pan[i][j] = val * 2;
										recent_i = i;
										recent_j = j;
									}
									else{
										Pan[recent_i][recent_j+1]= val * 2;
									}
									Pan[i][k] = 0;
								}
							}
						}
				}
			}
		
		
		}
		for (int i = 0; i < n; i++) {//동쪽
			for (int j = 0; j < n; j++) {

			}

		}
		for (int i = 0; i < n; i++) {//남
			for (int j = 0; j < n; j++) {

			}

		}
		for (int i = 0; i < n; i++) {//북
			for (int j = 0; j < n; j++) {

			}

		}


		count++;
		if (next_block <= now_block) return now_block;
		else now_block = next_block;
	}

};
int main() {

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> val;
			Pan[i][j] = val;
			Pan_check[i][j] = 0;
		
		}
	}

	cout << DP_BFS_Algorithm() << endl;

}