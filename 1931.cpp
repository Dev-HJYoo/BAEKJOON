#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>


using namespace std;


struct pll {
	int start, end;
};

bool operator < (pll a, pll b) {
	if (a.end != b.end) {
		return a.end > b.end;
	}
	else {
		return a.start > b.start;
	}
}

int n;
priority_queue<pll> pq;

void input() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pll p;
		p.start = a;
		p.end = b;
		pq.push(p);
	}
	
}

void solve() {
	int sum = 0;
	int end = -1;
	while (!pq.empty()) {
		pll temp = pq.top();
		
		if (temp.start >= end) {
			sum++;
			end = temp.end;
		}
		pq.pop();
	}
	printf("%d\n", sum);
}

int main(void) {
	input();
	solve();
}