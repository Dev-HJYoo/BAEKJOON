/*
	2019.2.10
	오랜만에 내 힘으로 풀어본 것 같다. 어제 한 크게 만들기가 도움이 됐다.
	pq의 존재를 잘 이용하면 그리드 문제는 쉽게 풀 수 있는 것같다.
	밑의 코드는 지금 너무 난잡하다....
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define SIZE 200000 // n 크기
#define SIZE2 2000 // scale 크기

using namespace std;

// 색깔,크기,인덱스 
class cls {
public:
	int color;
	int scale;
	int idx;
};

// 크기가 작은 것 부터 넣는다. 그리고 크기가 같을경우 색깔은 큰 것 부터 넣는다.
bool operator <(cls p, cls q) {
	if (p.scale < q.scale)
		return false;
	else if (p.scale == q.scale) {
		if (p.color < q.color)
			return true;
		else
			return false;
	}
	else
		return true;
}

long long store[SIZE] = { 0 }; // 인덱스 저장소
long long colors[SIZE + 1] = { 0 }; // 같은 색깔 저장소
long long scals[SIZE2 + 1] = { 0 }; // 같은 크기 저장소

int main(void){
	int n;
	scanf("%d", &n);


	priority_queue<cls> pq;

	// 다 넣기
	for (int i = 0; i < n; i++) {
		cls temp;
		scanf("%d %d", &temp.color, &temp.scale);
		temp.idx = i;
		pq.push(temp);
	}

	// pq의 첫번째 실행
	int sum = 0; // 이때까지의 합
	int color = pq.top().color; // 전 색깔
	int scale = pq.top().scale; // 전 크기
	int idx = pq.top().idx; // 전 인덱스
	int error = 1; // 크기도 같고 색깔도 같을 경우

	store[idx] = sum; 
	colors[pq.top().color] += scale;
	scals[scale] ++;
	pq.pop();
	
	// pq 두번쨰부터 마지막까지 실행
	while (!pq.empty()) {
		
		if (scale != pq.top().scale || color != pq.top().color) // 크기가 다르거나 색깔이 다를 경우 
			error = 0;

		sum += scale; // 이때까지 합
		store[pq.top().idx] = sum - colors[pq.top().color] - scals[pq.top().scale] *pq.top().scale; // 인덱스 저장소에 이때까지 합 - 같은색깔 - 같은 크기 * 갯수
		
		if (color == pq.top().color && scale == pq.top().scale) { // 같은 색깔 같은 크기가 있을 경우 두번 빼기 때문에 더해준다.
			error++;
			store[pq.top().idx] += scale * error;
		}

		color = pq.top().color; // 색깔 저장
		scale = pq.top().scale; // 크기 저장
		idx = pq.top().idx; // 인덱스 저장
		colors[pq.top().color] += scale; // 색깔 저장
		scals[scale] ++; // 크기 저장
		
		pq.pop();
	}

	for (int i = 0; i < n; i++)
		cout << store[i] << "\n";
	
}
