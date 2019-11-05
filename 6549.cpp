/*
	2019.11.5
	처음으로 세그먼트 트리로 풀어보는 문제이다.... 진짜 어렵다. 어떻게 자료형 보면수 풀긴했는데 찝찝하네...
	분할 정복으로 나누고 거기다가 세그먼트 트리로 합 구하는 방법이다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define SIZE 400000

using namespace std;

int tree[SIZE] = { 0 };
long long store[SIZE] = { 0LL };
int n;
long long maxs = 0;

void input() {
	maxs = 0;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &store[i]);
}


int init(int node, int start, int end) { // 세그먼트 트리 초기화 - 최솟값 인덱스가 들어가 있음
	if (start == end)
		return tree[node] = start;
	else {
		int a = init(node * 2, start, (start + end) / 2);
		int b = init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = store[a] < store[b] ? a : b;
		return tree[node];
	}
}

int search(int node, int left, int right,int start, int end) { // 세그먼트 트리 찾기
	if (left > end || right < start) // 범위 이탈
		return 0;
	if (left <= start && end <= right) // 범위 안에 있을 경우
		return tree[node];

	// 찾으러 갑시다.
	int a = search(node * 2, left, right, start, (start + end) / 2);
	int b = search(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return store[a] < store[b] ? a : b; // 최솟값 보내기
}

void DnC(long long start, long long end) { // 주의할 점은 현재 최솟값은 포함시키면 안된다는 것이다. 포함시키면 무한루프에 빠진다.
	if (start > end)
		return;
	int temp = search(1, start, end, 1, n); // 범위에 속하는 최솟값 찾기
	maxs = maxs < (end-start+1LL) * store[temp] ? (end -start+1LL) * store[temp] : maxs; // 직사각형 구하고 값 비교하기

	DnC(start, temp-1); // 왼쪽
	DnC(temp + 1, end); // 오른쪽
}


void solve() {
	init(1, 1, n); // 세그먼트 트리 만들기
	DnC(1, n); // 분할 정복으로 찾으러 가기
	printf("%lld\n",maxs);
}

int main(void) {
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		input();
		solve();
	}
}
