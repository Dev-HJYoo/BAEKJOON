/*
	2019.10.19
	ó���� ��¥ ����� �ùķ��̼� ������� �����ߴµ�, �����غ��ϱ� �ε����� ��찡 ������ �����̿���. 
	�ε��ĺ��� �ᱹ�� �״�� ���°Ŷ�� �����ϸ� �ȴ�. �̷��� �����ϴϱ� 
	1. �ּڰ��� �� �ִ� ���� ���� ���� �Ÿ�
	2. �ִ񰪵� �� �ִ� ���� ���� ���� �Ÿ�
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
