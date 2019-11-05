/*
	2019.11.5
	ó������ ���׸�Ʈ Ʈ���� Ǯ��� �����̴�.... ��¥ ��ƴ�. ��� �ڷ��� ����� Ǯ���ߴµ� �����ϳ�...
	���� �������� ������ �ű�ٰ� ���׸�Ʈ Ʈ���� �� ���ϴ� ����̴�.
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


int init(int node, int start, int end) { // ���׸�Ʈ Ʈ�� �ʱ�ȭ - �ּڰ� �ε����� �� ����
	if (start == end)
		return tree[node] = start;
	else {
		int a = init(node * 2, start, (start + end) / 2);
		int b = init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = store[a] < store[b] ? a : b;
		return tree[node];
	}
}

int search(int node, int left, int right,int start, int end) { // ���׸�Ʈ Ʈ�� ã��
	if (left > end || right < start) // ���� ��Ż
		return 0;
	if (left <= start && end <= right) // ���� �ȿ� ���� ���
		return tree[node];

	// ã���� ���ô�.
	int a = search(node * 2, left, right, start, (start + end) / 2);
	int b = search(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return store[a] < store[b] ? a : b; // �ּڰ� ������
}

void DnC(long long start, long long end) { // ������ ���� ���� �ּڰ��� ���Խ�Ű�� �ȵȴٴ� ���̴�. ���Խ�Ű�� ���ѷ����� ������.
	if (start > end)
		return;
	int temp = search(1, start, end, 1, n); // ������ ���ϴ� �ּڰ� ã��
	maxs = maxs < (end-start+1LL) * store[temp] ? (end -start+1LL) * store[temp] : maxs; // ���簢�� ���ϰ� �� ���ϱ�

	DnC(start, temp-1); // ����
	DnC(temp + 1, end); // ������
}


void solve() {
	init(1, 1, n); // ���׸�Ʈ Ʈ�� �����
	DnC(1, n); // ���� �������� ã���� ����
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
