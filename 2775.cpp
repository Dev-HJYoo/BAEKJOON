/*
	2019.1.16
	���� ����� ������ �˾Ҵµ� �׳� �� ���� �ڰ� �ϸ� �Ǵ� �ſ���.. �ϴ�!
	�ؿ� ���̶� �ٷ� ���� ���̶� ���ϸ� �ڽ��� ���� �� �� �ִ�.
	�׸��� ��� Ʋ�ȴ� ���� ���๮�ڸ� ���� �ʾƼ� Ʋ�ȴ�. 
*/
#include <iostream> 

using namespace std;

long arr[15][15] = {0};

int main(void){
	int t;
	cin>>t;
	for(int i = 1; i<15; i++)
		arr[0][i] = i;
	
	for(int i = 1; i<15;i++){
		for(int j = 1; j<15; j++){
			if(j==1)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}	
	
	while(t--){ 
		int k;
		int n;
		cin>>k>>n;
		
		cout<<arr[k][n]<<"\n";
	}
	
}
