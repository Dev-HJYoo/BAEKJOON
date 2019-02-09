/*
	2019.2.9
	정훈이형 코드를 받아서 풀긴했는데... 내 원래코드는 왜 시간초과나는지 아직까진 잘 모르겠네...
	전형적인 그리드 기법을 이용한 프로그래밍 문제였다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stdio.h>
#define SIZE 500000
using namespace std;


int input[SIZE];


struct compare { // pq 비교 구문, 
	constexpr bool operator()(pair<int, int> const & a,
		pair<int, int> const & b) const noexcept
	{	
		// 실제 값 비교
		if (a.first > b.first)
			return false;
		else if (a.first == b.first) { // 실제 값이 같을경우 낮은 인덱스를 가진게 우선권을 가진다.
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