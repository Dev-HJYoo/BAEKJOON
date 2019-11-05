/*
	2019.11.5
	하도 비슷한 문제 많아서 정석이라고 할 수 있는 지금 문제를 풀었다. DnC 방법으로 풀었다.
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
	while (b) { // DnC로 풀었다.
		if (b % 2) { // 만약 현재 값을 가질 경우
			sum = (sum * mul) % c;
		}
		mul = (mul * mul) % c; // 무조건 제곱씩 곱한다.
		b /= 2;
	}
	printf("%lld", sum);
}

int main(void) {
	input();
	solve();
}