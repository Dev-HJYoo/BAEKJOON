#include <iostream>

using namespace std;

int map[101][101];
int main(void){
	int n,m;
	cin>>n>>m;
	for(int i = 1; i<=n ; i++){
		for(int j = 1; j<=n; j++){
			if(i==j)
				map[i][j] = 0;
			else
				map[i][j] = 100001;
		}
	}
	for(int i = 1; i<=m; i++){
		int x,y, weight;
		cin>>x>>y>>weight;
		if(map[x][y] > weight)
			map[x][y] = weight;
	}
		
	int check = 1;
	while(check <= n){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(map[i][j] > map[i][check] + map[check][j])
					map[i][j] = map[i][check] + map[check][j];
			}
		}
		check++;
	}
	
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(map[i][j] == 100001){
				map[i][j] = 0;
			}
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
