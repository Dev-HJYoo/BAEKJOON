/*
	2019.1.18
	�׳� �Ӹ� ���ݸ� ������ Ǯ �� �ִ� ���� ����. 
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
