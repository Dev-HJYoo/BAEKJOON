/*
	2019.4.9
	하... 이것도 결국엔 답지 보고 풀었네.. 재귀를 활용한 방법을 잘 생각해보자.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
int num[101];
int t[5];
int n;
int a[100];

int maxs = -1000000001;
int mins = 1000000001;

void input() {
	memset(num, 0, sizeof(num));
	memset(t, 0, sizeof(t));
	memset(a, 0, sizeof(a));
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	for (int i = 1; i <= 4; i++) {
		scanf("%d", &t[i]);
	}

}

void check(int result, int p, int m, int g, int na, int idx) {
	if (p == -1 || m == -1 || g == -1 || na == -1)
		return;
	if (idx == n) {
		if (result < mins)
			mins = result;
		if (result > maxs)
			maxs = result;
		return;
	}
	idx++;
	check(result + num[idx], p - 1, m, g, na, idx);
	check(result - num[idx], p, m - 1, g, na, idx);
	check(result * num[idx], p, m, g - 1, na, idx);
	check(result / num[idx], p, m, g, na - 1, idx);
}
void print() {
	cout << maxs << endl << mins;
}


int main(void) {
	input();
	check(num[1], t[1], t[2], t[3], t[4], 1);
	print();
}