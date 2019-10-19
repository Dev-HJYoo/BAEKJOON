/*
	2019.10.19
	처음에 진짜 어려운 시뮬레이션 문제라고 생각했는데, 생각해보니깐 부딪히는 경우가 정말로 함정이였다. 
	부딪쳐봤자 결국엔 그대로 가는거라고 생각하면 된다. 이렇게 생각하니깐 
	1. 최솟값들 중 최대 값이 가장 빠른 거리
	2. 최댓값들 중 최대 값이 가장 느린 거리
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

void input() {
	scanf("%d %d", &n, &k);
	int mins = -~(1 << 31) - 1;
	int maxs = -~(1 << 31) - 1;
	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		int end = n - a;
		int ma = max(a, end);
		int mi = min(a, end);
		maxs = max(ma, maxs);
		mins = max(mi, mins);
	}
	printf("%d %d\n", maxs, mins);
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		input();
	}
}
