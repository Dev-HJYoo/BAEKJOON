/*
	2019.4.11
	아씨 개어렵네 ㅋㅋㅋㅋㅋ 어떻게 해서 풀었다. 진짜 설꼐가 제일 중요한거 같다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int maps[8][8];
int n, m;
int total[64];
int xx[4] = { -1, 0 ,1 , 0 };
int yy[4] = { 0,1,0,-1 };
int mins = 0;
int temp[8][8];
vector<int> virus;



pair<int,int> check(int c) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp == c)
				return { i,j };
			temp++;
		}
	}
}

int check2(int x, int y) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == x && j == y)
				return temp;
			temp++;
		}
	}
}
void bfs(queue<int> q) {
	while (!q.empty()) {
		pair<int, int> c = check(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (c.first + xx[i] == n || c.first + xx[i] == -1 || c.second + yy[i] == m || c.second + yy[i] == -1)
				continue;

			int a = check2(c.first + xx[i], c.second + yy[i]);
			if (temp[c.first + xx[i]][c.second + yy[i]] == 0) {
				temp[c.first + xx[i]][c.second + yy[i]] = 2;
				q.push(a);
			}
		}
	}
}


void get(vector<int> wall) {
	for (int i = 0; i < 3; i++) {
		pair<int, int> c = check(wall[i]);
		temp[c.first][c.second] = 1;
	}
	queue<int> q;
	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);
	bfs(q);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)
				sum++;
		}
	}
	if (sum > mins) {
		mins = sum;
	}
	for (int i = 0; i < 3; i++) {
		pair<int, int> c = check(wall[i]);
		temp[c.first][c.second] = 0;
	}
}

void create() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			temp[i][j] = maps[i][j];
	}
}

void solve(vector<int> wall, int size, int a) {
	for (int i = 0; i < size - 1; i++) {
		if (wall[i] > wall[i + 1])
			return;
	}
	
	if (size == 3) {
		create();
		get(wall);
		return;
	}

	if (a == n * m)
		return;

	pair<int, int > temp = check(a);
	if (maps[temp.first][temp.second] == 0) {
		wall.push_back(a);
		solve(wall, wall.size(), a+1);
		wall.erase(wall.end() - 1);
	}
	solve(wall, wall.size(), a+1);
}

void input() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &maps[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] == 2)
				virus.push_back(check2(i, j));
		}
	}
}

void print() {
	cout << mins;
}
int main(void) {
	memset(maps, 0, sizeof(maps));
	memset(total, 0, sizeof(total));
	vector<int> wall;
	input();
	solve(wall, wall.size(), 0);
	print();
}