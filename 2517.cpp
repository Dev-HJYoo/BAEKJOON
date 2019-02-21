/*
	2019.2.21
	저번에 풀었던 10090번 문제 counting inversions 문제랑 거의 동일하다.
	이 문제는 상대적인 값을 절대적인 값으로 변환시키는 과정만 필요할 뿐이다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define SIZE 500000

using namespace std;
class cls {
public:
	int num;
	int idx;
};
vector<long long> tree(SIZE * 4, 0);

long long init(vector<long long> & tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = 0;
	else
		return init(tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);

}

long long search(vector<long long> & tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	return search(tree, node * 2, start, (start + end) / 2, left, right) + search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void change(vector<long long> & tree, int node, int start, int end, int index, long long num) {
	if (index < start || index > end)
		return;
	tree[node] += 1;
	if (start != end) {
		change(tree, node * 2, start, (start + end) / 2, index, num);
		change(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, num);
	}
}

bool operator <(cls a, cls b) {
	return a.num > b.num ? true : false;
}

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> st(SIZE);
	priority_queue<cls> pq;
	for (int i = 0; i < n; i++) {
		cls a;
		scanf("%d", &a.num);
		a.idx = i;
		pq.push(a);
	}

	int i = 0;
	while (!pq.empty()) {
		st[pq.top().idx] = i;
		i++;
		pq.pop();
	}
	init(tree, 1, 0, n - 1);
	long long sum = 0;
	
	for(int i = 0; i<n; i++){
		
		int num = st[i];
		sum = search(tree, 1, 0, n - 1, 0, num);
		cout << i-sum+1 << "\n";
		change(tree, 1, 0, n - 1, num, 1);
		
	}
}
