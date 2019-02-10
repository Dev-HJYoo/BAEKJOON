/*
	2019.2.10
	�������� �� ������ Ǯ� �� ����. ���� �� ũ�� ����Ⱑ ������ �ƴ�.
	pq�� ���縦 �� �̿��ϸ� �׸��� ������ ���� Ǯ �� �ִ� �Ͱ���.
	���� �ڵ�� ���� �ʹ� �����ϴ�....
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define SIZE 200000 // n ũ��
#define SIZE2 2000 // scale ũ��

using namespace std;

// ����,ũ��,�ε��� 
class cls {
public:
	int color;
	int scale;
	int idx;
};

// ũ�Ⱑ ���� �� ���� �ִ´�. �׸��� ũ�Ⱑ ������� ������ ū �� ���� �ִ´�.
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

long long store[SIZE] = { 0 }; // �ε��� �����
long long colors[SIZE + 1] = { 0 }; // ���� ���� �����
long long scals[SIZE2 + 1] = { 0 }; // ���� ũ�� �����

int main(void){
	int n;
	scanf("%d", &n);


	priority_queue<cls> pq;

	// �� �ֱ�
	for (int i = 0; i < n; i++) {
		cls temp;
		scanf("%d %d", &temp.color, &temp.scale);
		temp.idx = i;
		pq.push(temp);
	}

	// pq�� ù��° ����
	int sum = 0; // �̶������� ��
	int color = pq.top().color; // �� ����
	int scale = pq.top().scale; // �� ũ��
	int idx = pq.top().idx; // �� �ε���
	int error = 1; // ũ�⵵ ���� ���� ���� ���

	store[idx] = sum; 
	colors[pq.top().color] += scale;
	scals[scale] ++;
	pq.pop();
	
	// pq �ι������� ���������� ����
	while (!pq.empty()) {
		
		if (scale != pq.top().scale || color != pq.top().color) // ũ�Ⱑ �ٸ��ų� ������ �ٸ� ��� 
			error = 0;

		sum += scale; // �̶����� ��
		store[pq.top().idx] = sum - colors[pq.top().color] - scals[pq.top().scale] *pq.top().scale; // �ε��� ����ҿ� �̶����� �� - �������� - ���� ũ�� * ����
		
		if (color == pq.top().color && scale == pq.top().scale) { // ���� ���� ���� ũ�Ⱑ ���� ��� �ι� ���� ������ �����ش�.
			error++;
			store[pq.top().idx] += scale * error;
		}

		color = pq.top().color; // ���� ����
		scale = pq.top().scale; // ũ�� ����
		idx = pq.top().idx; // �ε��� ����
		colors[pq.top().color] += scale; // ���� ����
		scals[scale] ++; // ũ�� ����
		
		pq.pop();
	}

	for (int i = 0; i < n; i++)
		cout << store[i] << "\n";
	
}
