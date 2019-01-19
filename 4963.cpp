#include <iostream>

using namespace std;
bool store[52][52] = {false};

void search(int x, int y){
	store[x][y] = false;
	int xs[] = {-1,0,1,-1,1,-1,0,1};
	int ys[] = {-1,-1,-1,0,0,1,1,1};
	for(int i = 0; i<8; i++){
		int dx = x + xs[i];
		int dy = y + ys[i];
		if(store[dx][dy]){
			search(dx,dy);
		}
	}
}
int main(void){
	
	while(1){
		int x,y;
		cin>>y>>x;
		if(x == 0|| y == 0){
			break;
		}
		for(int i = 1; i<=x; i++)
			for(int j = 1; j<=y; j++)
				cin>>store[i][j];
				
		int num = 0;
		for(int i = 1; i<=x; i++){
			for(int j = 1; j<=y; j++){
				if(store[i][j]){
					num++;
					search(i,j);
				}
			}
		}
		cout<<num<<"\n";
	}
}
