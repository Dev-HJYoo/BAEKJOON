/*
	2019.1.16
	무슨 방법이 있을줄 알았는데 그냥 다 때려 박고 하면 되는 거였네.. 일단!
	밑에 층이랑 바로 옆에 층이랑 합하면 자신의 층을 알 수 있다.
	그리고 계속 틀렸던 것은 개행문자를 넣지 않아서 틀렸다. 
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
