/*
	2019.1.22
	와.. 이게 맞을줄은 몰랐네
	일단.... head node를 제외하고는 +1을 더해서( 인덱스 맞추기 위해서)  각 인덱에 맞게 1로 바꿔 준다.
	그 후에 삭제 시킬 번호를 받고 그 번호에 해당하는 열,행을 전부다 0으로 바꾼다.
	마지막으로 head node 부터 시작해서 재귀적으로 1이면 계속해서 들어가고 만약에 들어갔는데 전부다 0이면 그건 리프 노드이기 때문에 total++을 한다. 
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
