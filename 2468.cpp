/*
	2019.1.28
	�̰� ������ Ǯ���� ���� �������� Ǫ�ϱ� �ٷεǳ�...
	dfs�� �����ϰ� ����ϸ� �ٷ� Ǯ���ִ� ������. 
*/

#include <iostream>

using namespace std;


int graph[101][101] = {0};
bool dumy[101][101] = {0};

void dfs(int i, int j){
	if(dumy[i][j]){
		dumy[i][j] = false;
		dfs(i+1,j);
		dfs(i-1,j);
		dfs(i,j+1);
		dfs(i,j-1);
	}
}
int main(void){
	int n;
	cin>>n;
	
	int min = 101;
	int max = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>graph[i][j];
			if(min > graph[i][j])
				min = graph[i][j];
			if(max < graph[i][j])
				max = graph[i][j];
		}
	}
	
	int max_sum = 1;
	
	for(int bound = min; bound<=max; bound++){
		int sum = 0;
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=n; j++)
	 		if(graph[i][j] > bound)
					dumy[i][j] = true;
		
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(dumy[i][j]){
					dumy[i][j] = false;
					sum++;
					dfs(i+1,j);
					dfs(i,j+1);
				}
			}
		}
		if(max_sum < sum)
			max_sum = sum;
	}	
	
	cout<<max_sum;
			
	
	
}
