/*
	2019.1.19
	단방향 그래프로 하다가 안되서 결국엔 양방향 그래프로 풀었다. 
	생각해보니깐 양방향 그래프로 풀어야 되더라... 
*/
#include <iostream>
#include <vector>
using namespace std;

bool arr[501][501] = {0};

void check(int n){
	
}
int main(void){
	int N;
	int M;
	vector<int> f;
	int a,b; 
	cin>> N>>M;
	
	for(int _; _<M; _++){
		cin>>a>>b;
		arr[a][b] = 1;
		arr[b][a] = 1;
		if(a == 1)
			f.push_back(b);
	}
	int size = f.size();	
	int total = size;
	
	for(int i = 0; i < size ; i++){
		int j = f[i];
		for(int z = 2; z<=N; z++){
			if(arr[z][j]  && !arr[1][z] ){
				total++;
				arr[1][z] = true;
			}
		} 
	}
	cout<<total;
}
