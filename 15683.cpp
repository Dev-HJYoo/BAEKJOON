/*
	2019.4.12
	겨우 풀었다.. 재귀 푸는게 진짜 힘들긴 하네 ㅋㅋㅋ 좀 더 생각헤ㅐ보자 0에서 최대까지 가거나
	최대에서 0으로 가는 방법으로 생각해보자.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class cls {
public:
	int x, y, type, d;
};

int n, m;
int maps[8][8];
vector<cls> cctv;
int s = 0;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
int mins = 65;
int cas[5] = { 4,2,4,4,1 };

void x2n(int temp[8][8], int start, int fix) {
	for (int i = start; i != n; i++) {
		if (temp[i][fix] == 6)
			break;
		temp[i][fix] = 7;
	}
}
void x20(int temp[8][8], int start, int fix) {
	for (int i = start; i != -1; i--) {
		if (temp[i][fix] == 6)
			break;
		temp[i][fix] = 7;
	}
}
void y2m(int temp[8][8], int start, int fix) {
	for (int i = start; i != m; i++) {
		if (temp[fix][i] == 6)
			break;
		temp[fix][i] = 7;
	}
}
void y20(int temp[8][8], int start, int fix) {
	for (int i = start; i != -1; i--) {
		if (temp[fix][i] == 6)
			break;
		temp[fix][i] = 7;
	}
}

void get(vector<cls> k, int temp[8][8]) {
	int size = k.size();
	for (int i = 0; i < size; i++) {
		int x = k[i].x;
		int y = k[i].y;
		int type = k[i].type;
		int d = k[i].d;
	
		switch (type) {
		case 1:
			if (d == 0) {
				x20(temp, x, y);
			}
			else if (d == 1) {
				y2m(temp, y, x);
			}
			else if (d == 2) {
				x2n(temp, x, y);
			}
			else {
				y20(temp, y, x);
			}
			break;
		case 2:
			if (d == 0) {
				x20(temp, x, y);
				x2n(temp, x, y);
			}
			else{
				y20(temp, y, x);
				y2m(temp, y, x);
			}
			break;
		case 3:
			if (d == 0) {
				x20(temp, x, y);
				y2m(temp, y, x);
			}
			else if (d == 1) {
				y2m(temp, y, x);
				x2n(temp, x, y);
			}
			else if (d == 2) {
				x2n(temp, x, y);
				y20(temp, y, x);
			}
			else {
				y20(temp, y, x);
				x20(temp, x, y);
			}
			break;
		case 4:
			if (d == 0) {
				x20(temp, x, y);
				y2m(temp, y, x);
				y20(temp, y, x);
			}
			else if (d == 1) {
				x20(temp, x, y);
				x2n(temp, x, y);
				y2m(temp, y, x);
			}
			else if (d == 2) {
				y2m(temp, y, x);
				y20(temp, y, x);
				x2n(temp, x, y);
			}
			else {
				x20(temp, x, y);
				x2n(temp, x, y);
				y20(temp, y, x);
			}
			break;
		case 5:
			x20(temp, x, y);
			x2n(temp, x, y);
			y20(temp, y, x);
			y2m(temp, y, x);
			break;
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)
				sum++;
		}
	}
	if (mins > sum) {
		mins = sum;
	}
}
void create(int temp[8][8]) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			temp[i][j] = maps[i][j];
}


void solve(vector<cls> k, int a) {
	
	if (a == s) {
		int temp[8][8];
		create(temp);
		get(k, temp);
		return;
	}
	
	for (int i = 0; i < cas[cctv[a].type - 1]; i++) {
		cls t = cctv[a];
		t.d = i;
		k.push_back(t);
		solve(k, a + 1);
		k.pop_back();
	}
}

void input() {
	memset(maps, 0, sizeof(maps));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &maps[i][j]);
			if (maps[i][j] > 0 && maps[i][j] < 6) {
				s++;
				cls temp;
				temp.x = i;
				temp.y = j;
				temp.type = maps[i][j];
				temp.d = 0;
				cctv.push_back(temp);
			}
		}
	}
}
int main(void) {
	input();
	vector<cls> k;
	solve(k, 0);
	cout << mins;
}