/*
	2019.10.1
	백트레킹으로 푸는 문제인데 check 배열이랑 잘 써먹으니깐 풀렸음!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int store[13] = { 0 };
int check[13] = { 0 };

int k = 1;

void input() {
	for (int i = 0; i < 13; i++) {
		store[i] = 0;
		check[i] = 0;
	}
	scanf("%d", &k);

	if (k == 0)
		return;
	for (int i = 0; i < k; i++)
		scanf("%d", &store[i]);
}

void tracking(int* temp, int start, int size) {

	if (size == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", store[temp[i]]);
		printf("\n");
		return;
	}

	for (int i = start + 1; i < k; i++) {
		if (check[i])
			continue;
		temp[size] = i;
		check[i] = 1;
		tracking(temp, i, size + 1);
		for (int j = i + 1; j < k; j++)
			check[j] = 0;
	}
}

void solve() {

	for (int i = 0; i < k - 5; i++) {
		int temp[6];
		temp[0] = i;
		check[i] = 1;
		tracking(temp, i, 1);
		for (int j = i + 1; j < k; j++)
			check[j] = 0;
	}
}

int main(void) {

	while (k) {
		input();
		if (k == 0)
			break;
		solve();
		printf("\n");
	}
}