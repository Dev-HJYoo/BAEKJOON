/*
	2019.1.21
	처음에 배열 떄문에 시간이 좀 걸렸다가 무난하게 풀었다.
	여기서 또 문제점은 한번에 큰수와 작은 수를 더하고 true 로 바꿨는데 그렇게 되면 ㄷ다음 번 수에서 오류가 났다. 
*/
#include <iostream>
#include <vector>
using namespace std;

bool arr[50001] = {0};

int main(void){
	
	while(true){
		int n;
		cin>>n;
		
		if(n == -1)
			break;
		
		
		
		int sum = 1;
		for(int i = 2; i<=n/2; i++){
			if(sum > n)
				continue;
			if(n%i){
				arr[i] = false;
				continue;
			}
			else{
				arr[i] = true;
				sum += i;
			}
		}
		if(sum == n){
			cout<<n<<" = 1";
			for(int i = 2; i<=n/2; i++){
				if(arr[i] == true){
					cout<<" + "<<i;
				}
			}
			cout<<"\n";
		}
		else
			cout<<n<<" is NOT perfect.\n";
		
	}
}
