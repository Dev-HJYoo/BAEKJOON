/*
	2019.2.14
	조금만 생각하면 풀 수 있는 dp문제 였다.
	처음에 조금 헤매다가 결국에는 방법을 찾았다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int graph[16][16] = { 0 };

int main(void) {
	int n, m, k;

	// 입력부
	scanf("%d %d %d", &n, &m, &k);

	//초기화부
	int sum = 1;
	int i, j;
	bool check = true; //k구역 찾기

	// k번호 까지의 탐색
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
	// i랑 j 가 1개씩 더 해진거 없애기
	j--;
	i--;

	
	// 두번째 탐색
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