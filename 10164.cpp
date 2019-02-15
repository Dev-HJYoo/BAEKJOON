/*
	2019.2.14
	���ݸ� �����ϸ� Ǯ �� �ִ� dp���� ����.
	ó���� ���� ��Ŵٰ� �ᱹ���� ����� ã�Ҵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int graph[16][16] = { 0 };

int main(void) {
	int n, m, k;

	// �Էº�
	scanf("%d %d %d", &n, &m, &k);

	//�ʱ�ȭ��
	int sum = 1;
	int i, j;
	bool check = true; //k���� ã��

	// k��ȣ ������ Ž��
	for (i = 0; i < n && check; i++) {
		for (j = 0; j<m && check; j++) {
			
			if (i == 0 || j == 0)
				graph[i][j] = 1;
			else {
				graph[i][j] += graph[i - 1][j] + graph[i][j - 1];
			}
			if (sum == k)
				check = false;
			sum++;
		}
	}
	// i�� j �� 1���� �� ������ ���ֱ�
	j--;
	i--;

	
	// �ι�° Ž��
	sum = graph[i][j];
	int i2, j2;
	for (i2 = i; i2 < n; i2++) {
		for (j2 = j; j2 < m; j2++) {
			if (i2 == i || j2 == j)
				graph[i2][j2] = 1;
			else {
				graph[i2][j2] += graph[i2 - 1][j2] + graph[i2][j2 - 1];
			}
		}
	}

	cout << sum * graph[n-1][m-1]<<"\n";

}