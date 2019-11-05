/*
	2019.10.26
	ó���� �ٸ� �귣�忡�� �絵 �Ǵ��� ���� Ʋ�ȴٰ� �װ� Ȯ���ϰ� �ٷ� Ǯ����.
	3���� ��츦 �����ϸ�ȴ�.
	1. �������� �� ���
	2. �������� �� �� �ִ� ��ŭ ��� ��ǰ���� ���
	3. ��ǰ���� �� ���
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