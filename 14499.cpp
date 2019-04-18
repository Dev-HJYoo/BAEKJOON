/*
	2019.4.8
	접근 방법이 잘못되서 결국에 답지 보고 풀었다... 너무 어렵다 싶으면 다른 방법으로 접근해 보자
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
map<int, int> ma = { {1,3},{3,1},{2,5},{5,2},{4,6},{6,4} };

int maps[20][20];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };
int n, m, x, y, k;
int dice[7] = {0,0,0,0,0,0,0 };
int rdice[7] = { 0,0,0,0,0,0,0 };
int d = 3;
int main(void) {
	memset(maps, 0, sizeof(maps));

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &maps[i][j]);

	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		temp--;
		if (x + xx[temp] == -1 || x + xx[temp] == n || y + yy[temp] == -1 || y + yy[temp] == m)
			continue;
		x += xx[temp];
		y += yy[temp];

		switch (temp) {
		case 0:
			rdice[5] = dice[1];
			rdice[6] = dice[3];
			rdice[2] = dice[2];
			rdice[4] = dice[4];
			rdice[3] = dice[5];
			rdice[1] = dice[6];
			break;
		case 1:
			rdice[5] = dice[3];
			rdice[6] = dice[1];
			rdice[2] = dice[2];
			rdice[4] = dice[4];
			rdice[3] = dice[6];
			rdice[1] = dice[5];
			break;
		case 2:
			rdice[5] = dice[5];
			rdice[6] = dice[6];
			rdice[2] = dice[3];
			rdice[4] = dice[1];
			rdice[3] = dice[4];
			rdice[1] = dice[2];
			break;
		case 3:
			rdice[5] = dice[5];
			rdice[6] = dice[6];
			rdice[2] = dice[1];
			rdice[4] = dice[3];
			rdice[3] = dice[2];
			rdice[1] = dice[4];
			break;
		}
		for (int i = 1; i < 7; i++)
			dice[i] = rdice[i];
		if (maps[x][y] == 0) {
			maps[x][y] = dice[3];
		}
		else {
			dice[3] = maps[x][y];
			maps[x][y] = 0;
		}
		cout << dice[1] << endl;
	}
}