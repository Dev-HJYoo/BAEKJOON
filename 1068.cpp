/*
	2019.1.22
	��.. �̰� �������� ������
	�ϴ�.... head node�� �����ϰ�� +1�� ���ؼ�( �ε��� ���߱� ���ؼ�)  �� �ε��� �°� 1�� �ٲ� �ش�.
	�� �Ŀ� ���� ��ų ��ȣ�� �ް� �� ��ȣ�� �ش��ϴ� ��,���� ���δ� 0���� �ٲ۴�.
	���������� head node ���� �����ؼ� ��������� 1�̸� ����ؼ� ���� ���࿡ ���µ� ���δ� 0�̸� �װ� ���� ����̱� ������ total++�� �Ѵ�. 
*/

#include <iostream>

using namespace std;

int tree[51][51] = {0};

int total;

int N;

void check(int a){
	bool c = true;
	for(int i = 1; i<=N ; i++){
		if(tree[a][i]){
			c = false;
			check(i);
		}
	}
	if(c)
		total++;
}

int main(void){
	
	int a;
	int head;
	
	cin>>N;
	for(int i = 1; i<=N; i++){
		cin>>a;
		if(a == -1){
			head = i;	
			continue;
		}
		a++;
		tree[a][i] = 1;
	}
	
	
	int deletes;
	cin>>deletes;
	deletes++;
	if(deletes == head){
		cout<<"0";
		return 0;
	}
	for(int i = 1; i<=N; i++){
		tree[i][deletes] = 0;
		tree[deletes][i] = 0;
	}
	
	total = 0;
	check(head);
	cout<<total;
}
