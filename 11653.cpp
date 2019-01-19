/*
	2019.1.18
	그냥 머리 조금만 굴리면 풀 수 있는 문제 였다. 
*/
#include <iostream>

using namespace std;

int main(void){
	
	int N;
	cin>>N;
	while(N!=1){
		for(int i = 2; i<=N; i++){
			if(N%i)
				continue;
			else{
				N/=i;
				cout<<i<<"\n";
				break;
			}
		}
	}
}
