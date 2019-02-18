#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int graph[100][100][100] = { 0 };
int n, m, h;

class cls {
public:
	int x, y, z;
};

void bfs(cls a, queue<cls> &q) {
	int x[6] = { -1,0,1,0,0,0 };
	int y[6] = { 0,1,0,-1,0,0 };
	int z[6] = { 0,0,0,0,1,-1 };

	for (int i = 0; i < 6; i++) {
		if (a.x + x[i] >= 0 && a.x + x[i] < m && a.y + y[i] >= 0 && a.y + y[i] < n && a.z + z[i] >= 0 && a.z + z[i] < h ) {
			if (graph[a.z + z[i]][a.x + x[i]][a.y + y[i]] == 0) {
				graph[a.z + z[i]][a.x + x[i]][a.y + y[i]] = 1;
				cls temp;
				temp.x = a.x + x[i];
				temp.y = a.y + y[i];
				temp.z = a.z + z[i];
				q.push(temp);
			}
		}
	}
 }


int main(void) {
	
	scanf("%d %d %d", &n, &m, &h);

	queue<cls> q;

	for (int z = 0; z < h; z++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &graph[z][i][j]);
				if (graph[z][i][j] == 1) {
					cls a;
					a.x = i;
					a.y = j;
					a.z = z;
					q.push(a);
				}
			}
		}
	}


	queue<cls> b;
	long long sum = 0;
	while (!q.empty() || !b.empty()) {
		if (!q.empty())
			sum++;
		while (!q.empty()) {
			bfs(q.front(), b);
			q.pop();
		}

		if (!b.empty())
			sum++;
		while (!b.empty()) {
			bfs(b.front(), q);
			b.pop();
		}
	}

	for (int z = 0; z < h; z++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[z][i][j] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	
	cout << sum - 1;

}