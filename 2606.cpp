/*
	2019.2.2
	�� ������ �ܼ��ϰ� dfs �����ϸ� Ǯ���� ������. 
*/
#include <iostream>

using namespace std;

int total;
bool com[101][101] = {0};
bool c[101] = {0};
int n;

void check(int i){
	bool ccc = false;
	for(int j = 2; j<=n; j++){
		if(com[i][j]){
			com[i][j] = false;
			com[j][i] = false;
			if(!c[j])
				total++;
			c[j] = true;
			check(j);
		}
	}
	
	
}
int main(void){
	int t;
	
	cin>>n>>t;
	
	for(int i = 0; i<t; i++){
		int a,b;
		cin>>a>>b;
		com[a][b] = true;
		com[b][a] = true;
	}
	
	total = 0;
	check(1);
	cout<<total;
}
