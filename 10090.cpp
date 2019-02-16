/*
	2019.2.16
	�̹� ������ ���ؼ� n������ ������ ���׸�Ʈ Ʈ���� �̿��ؼ� Ǫ�� ����� ���ؼ� �˰� �Ǿ���.
	�׸��� SIZE�� n��4�踦 �ؾ� �Ǵ°� ������ �ֱ׷����� �𸣰ڳ�... ��������
	�ϴ� ���׸�Ʈ Ʈ���� �ظ��� �������� Ǯ �� ���� �� ����.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#define SIZE 1000000 

using namespace std;
vector<long long> tree(SIZE*2+1, 0);

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
	if (index < start|| index > end)
		return;
	tree[node] += 1;
	if (start != end) {
		change(tree, node * 2, start, (start + end) / 2, index, num);
		change(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, num);
	}
}



int main(void) {
	int n;
	scanf("%d", &n);

	stack<int> st;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		st.push(temp);
	}

	
	init(tree, 1, 0, n-1);
	long long sum = 0;
	while (!st.empty()) {
		int num = st.top();
		sum += search(tree, 1, 0, n - 1, 0, num-1);
		change(tree, 1, 0, n - 1, num - 1, 1);
		st.pop();
	}
	cout << sum;
}
