/*
	2019.11.5
	�ϵ� ����� ���� ���Ƽ� �����̶�� �� �� �ִ� ���� ������ Ǯ����. DnC ������� Ǯ����.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int a, b, c;

void input() {
	scanf("%d %d %d", &a, &b, &c);
}

void solve() {
	long long mul = a;
	long long sum = 1;
	while (b) { // DnC�� Ǯ����.
		if (b % 2) { // ���� ���� ���� ���� ���
			sum = (sum * mul) % c;
		}
		mul = (mul * mul) % c; // ������ ������ ���Ѵ�.
		b /= 2;
	}
	printf("%lld", sum);
}

int main(void) {
	input();
	solve();
}