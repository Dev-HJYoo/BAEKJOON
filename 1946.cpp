/*
	2019.10.3
	여러번의 시행착오를 거쳐 풀었긴한데.. 좀 아쉽네
	그리디 문제로 현재 기준으로 최저값 계속 비교해 가면 된다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> vec;

void input() {
	vec.clear();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
}

void solve() {
	int total = 1;
	int maxs = vec[0].second;
	for (int i = 1; i < n; i++) {
		if (vec[i].second < maxs) {
			total++;
			maxs = vec[i].second;
		}
	}

	printf("%d\n", total);
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		input();
		solve();
	}
}