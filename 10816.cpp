#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define SIZE 500000
#define SIZE2 10000000
using namespace std;
int N;
vector<int> vec;

void right(int a, int c, int &t) {
	a++;
	if (a < N && vec[a] == c) {
		t++;
		right(a, c, t);
	}
	else
		return;
}

void left(int a, int c, int &t) {
	a--;
	if (a > -1 && vec[a] == c) {
		t++;
		left(a, c, t);
	}
	else
		return;
}

void binary(int start, int end, int check, int & total) {
	if (end < start)
		return;
	int m = start + (end - start) / 2;
	if (check == vec[m]) {
		total++;
		right(m, check, total);
		left(m, check, total);
	}
	else if (check > vec[m])
		binary(m + 1, end, check, total);
	else
		binary(start, m - 1, check, total);
}


int main(void) {
	
	// init
	map<int, int> m;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a;
		int total = 0;
		scanf("%d", &a);
		if (m.find(a) != m.end())
			total = m[a];
		else
			binary(0, N - 1, a, total);
		printf("%d ", total);
		m.insert({ a,total });
	}
}