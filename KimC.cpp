#include <cstdio>
#include <iostream>
#include<queue>


using namespace std;
int n, in;
int pushback = 0;
int color = 4;
int Kim[200][200] = { 0, };
int level[201] = { 0, };
bool check(int x, int y, int z) {

	if (Kim[x][y] == Kim[z][y]) {
		return false;
	}
	else return true;

}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	int T;
	int test_case;


	queue<pair<int, int> > q;
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

		cin >> n;
		cin >> in;
		int x, y;
		for (int i = 0; i < in; i++) {
			cin >> x >> y;
			Kim[x - 1][y - 1] = 1;
			Kim[y - 1][x - 1] = 1;


		}

		int breakcheck = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Kim[i][j] == 1) {
					q.push(make_pair(i, j));
					Kim[i][j] = color;
					breakcheck = 1;
					pushback++;
				}

			}
			if (breakcheck == 1) {
				break;
			}
		}//첫 시작의 데이터들을 큐에 삽입!
		breakcheck = 0;
		//color = 5;
		while (!q.empty()) {

			int d1 = q.front().first;
			int d2 = q.front().second;//
			q.pop();
			if (q.empty()) {
				pushback = 1;
			}
			for (int k = 0; k < n; k++) {
				if (Kim[d2][k] == 1) {
					if (d1 == k) {
						continue;
					}
					else {
						if (check(k, d2, d1)) {
							q.push(make_pair(d2, k));
							if (Kim[d1][d2] == 4) {
								Kim[d2][k] = 5;
							}
							else {
								Kim[d2][k] = 4;
							}



						}
						else
							breakcheck = 1;
					}
				}
			}
			if (breakcheck == 1) break;
			if (pushback == 1) {
				if (color == 5)color = 4;
				else color = 5;
				pushback = 0;
			}
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		if (breakcheck == 1) {
			cout << 0 << endl;
		}
		else cout << 1 << endl;

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}