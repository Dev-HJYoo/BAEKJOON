/*
	2019.4.10
	단순한 시뮬레이션 문제였다... 제대로 보고 그대로 풀면 도니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int maps[51][51];
int n, m;
int r, c;
int d;

int xx[4] = {-1,0,1,0};
int yy[4] = {0,1,0,-1};

int direct[4][4] = {
	{3,2,1,0}, {0,3,2,1}, {1,0,3,2}, {2,1,0,3} // 북 동 남 서
};

int main(void) {
	memset(maps, 1, sizeof(maps));
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);

	for (int i = 0; i < n; i++)
		for (int j = 0; j< m; j++)
			scanf("%d", &maps[i][j]);
	maps[r][c] = 2;
	int sum = 1;
	while (true) {
		bool check = 1;
		for (int i = 0;  check && i < 4; i++) {
			if (maps[r + xx[direct[d][i]]][c + yy[direct[d][i]]] == 0) {
				r += xx[direct[d][i]];
				c += yy[direct[d][i]];
				maps[r][c] = 2;
				sum++;
				d = direct[d][i];
				check = 0;
			}
		}

		if (!check)
			continue;
		if (maps[r + xx[direct[d][1]]][c + yy[direct[d][1]]] == 2) {
			r += xx[direct[d][1]];
			c += yy[direct[d][1]];
		}
		else {
			break;
		}
		
	}
	cout << sum;
}