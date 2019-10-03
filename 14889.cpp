/*
	2019.10.3
	��Ʈ��ŷ�� �Բ� Ǫ�ϱ� �׳� �ƴ�. ���Ʈ���� ������ �� �غ��� �Ǵ� �����ε�
	�׸��� ��� Ʋ�ȴ� ������ �ִ� ������ �̻��ؼ� �ȵƴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int graph[21][21] = { 0 };
int n;
int maxs = 10000000;

void input() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);
}

int sum(int *temp) {
	int s = 0;
	int o = 0;
	int idx = 0;
	int o_idx = 0;
	int opos[10];
	for (int i = 1; i <= n; i++) {
		if (temp[idx] == i) {
			idx++;
			continue;
		}
		opos[o_idx] = i;
		o_idx++;
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			s += graph[temp[i]][temp[j]];
			o += graph[opos[i]][opos[j]];
		}
	}
	
	return s - o >= 0 ? s - o : o - s;
}

void tracking(int *temp, int num, int size) {

	if (size == n/2) {
		int total = sum(temp);
		if (maxs > total) 
			maxs = total;
		return;
	}

	for (int i = num+1; i <= n; i++) {
		temp[size] = i;
		tracking(temp, i, size+1);
	}

}

void solve() {
	int temp[10];
	temp[0] = 1;

	for (int i = 2; i <= n; i++) {
		temp[1] = i;
		tracking(temp, i, 2);
	}
}

int main(void) {
	input();
	solve();
	printf("%d", maxs);
	return 0;
}
