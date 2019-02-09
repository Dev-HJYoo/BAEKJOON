/*
	2019.2.9
	�������� �ڵ带 �޾Ƽ� Ǯ���ߴµ�... �� �����ڵ�� �� �ð��ʰ������� �������� �� �𸣰ڳ�...
	�������� �׸��� ����� �̿��� ���α׷��� ��������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stdio.h>
#define SIZE 500000
using namespace std;


int input[SIZE];


struct compare { // pq �� ����, 
	constexpr bool operator()(pair<int, int> const & a,
		pair<int, int> const & b) const noexcept
	{	
		// ���� �� ��
		if (a.first > b.first)
			return false;
		else if (a.first == b.first) { // ���� ���� ������� ���� �ε����� ������ �켱���� ������.
			if (a.second < b.second)
				return false;
			else
				return true;
		}
		else
			return true;
	}
};


int main(void) {
	int n, k;
	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%1d", &input[i]);
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
	for (int i = 0; i < k; i++)
		pq.push({ input[i], i });

	int max_i = -1;

	for (int i = k; i < n; i++) {
		pq.push({ input[i],i });
		
		while (max_i > pq.top().second)
			pq.pop();
		
		max_i = pq.top().second;
		printf("%d", pq.top().first);
		pq.pop();
	}
}