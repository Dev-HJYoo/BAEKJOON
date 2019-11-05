/*
	2019.10.26
	처음에 다른 브랜드에서 사도 되는지 몰라서 틀렸다가 그거 확인하고 바로 풀었다.
	3가지 경우를 생각하면된다.
	1. 묶음으로 다 사기
	2. 묶음으로 살 수 있는 만큼 사고 단품으로 사기
	3. 단품으로 다 사기
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, m;
int sum_min = ~(1 << 31);
int piece_min = ~(1 << 31);
int min = ~(1 << 31);

void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 || b == 0) {
			sum_min = 0;
			piece_min = 0;
			break;
		}
		sum_min = sum_min > a ? a : sum_min;
		piece_min = piece_min > b ? b : piece_min;
	}
}

void solve() {
	if (sum_min == 0 || piece_min == 0) {
		printf("0");
		return;
	}
	int remain = n % 6;
	int a = (n / 6+1) * (sum_min);
	int b = n / 6 * sum_min + remain * piece_min;
	int c = n * piece_min;
	min = min > a ? a : min;
	min = min > b ? b : min;
	min = min > c ? c : min;
	printf("%d", min);
}

int main(void) {
	input();
	solve();
}