/*
	2019.2.11
	bfs 랑 queue를 이용한 문제이다.
	한번에 풀려서 다행이고 bfs에서 좋은 코드 축약을 한것 같다.
	굿
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define SIZE 1001 // 최대 크기

using namespace std;

int graph[SIZE][SIZE];


int sum = 0;
int N, M;

// bfs 딱 한번만
bool bfs(int i, int j, queue<pair<int, int> > &temp) {
	bool check = false;
	int x[4] = { i + 1, i, i - 1, i };
	int y[4] = { j, j + 1, j, j - 1 };
	// 상하좌우 움직이기
	for (int idx = 0; idx < 4; idx++) { 
		if (graph[x[idx]][y[idx]] == 0 && x[idx] != N && y[idx] != M && x[idx] != -1 && y[idx] != -1) {
			graph[x[idx]][y[idx]] = 1;
			check = true;
			temp.push({ x[idx],y[idx] });
		}
	}
	
	return check;
}
int main(void) {


	scanf("%d %d", &M, &N);

	//입력부
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			scanf("%d", &graph[i][j]);
		
	
	
	
	//초기화부
	queue<pair<int, int> > a;
	queue<pair<int, int> > b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1)
				a.push({ i,j });
		}
	}

	
	//솔루션
	while (!a.empty() || !b.empty()) {
		if (!a.empty())
			sum++;
		while (!a.empty()) {
			bool check = bfs(a.front().first, a.front().second, b);
			a.pop();
		}
		
		if (!b.empty())
			sum++;
		while (!b.empty()) {

			bool check = bfs(b.front().first, b.front().second, a);

			b.pop();
		}
		
	}

	//출력부
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << sum-1; // -1 하는 이유는 처음에 무조건 +1이 되기댸문이다.
}