/*
	2019.3.28
	�ܼ��� bfs �Ǵ� dfs �����̴�.
	���� bfs�� Ǫ�°� ���ؼ� �׷��� Ǯ���� x�� y�� ���� ���ؼ� Ǯ��.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;
bool graph[52][52] = { 0 };
int x, y;
void reset() {
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			graph[i][j] = 0;
}

void bfs(int a, int b) {
	int xx[4] = { 0,1,0,-1 };
	int yy[4] = { -1,0,1,0 };

	for (int i = 0; i < 4; i++) {
		int temp1 = a + xx[i];
		int temp2 = b + yy[i];
		if (!(temp1 >= 0 && temp2 >= 0 && temp1 != x && temp2 != y))
			continue;
		if (graph[temp1][temp2] == 1) {
			graph[temp1][temp2] = 0;
			bfs(temp1, temp2);
		}
	}
}

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d %d %d", &y, &x, &n);

		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			graph[b][a] = 1;
		}

		int total = 0;

		for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) {
				if (graph[i][j] == 1) {
					total++;
					bfs(i, j);
				}
			}
		}
		

		printf("%d\n", total);

		reset();
	}
}