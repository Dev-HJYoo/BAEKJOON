/*
	2019.4.18
	마지막에 자기자신으로도 소인수 분해 할 수 있는걸 깜빡했다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void print(int i, int k) {
	printf("%d %d\n", i, k);
}

void solve(int n) {
	int temp = n;
	for (int i = 2; n > 1 && i <= temp; i++) {
		int k = 0;
		while (!(n%i)) {
			k++;
			n /= i;
		}
		if(k)
			print(i, k);
	}
}

void input() {
	int n;
	scanf("%d", &n);
	solve(n);
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
		input();
}