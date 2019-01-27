/*
	2019.1.21
	ó���� �迭 ������ �ð��� �� �ɷȴٰ� �����ϰ� Ǯ����.
	���⼭ �� �������� �ѹ��� ū���� ���� ���� ���ϰ� true �� �ٲ�µ� �׷��� �Ǹ� ������ �� ������ ������ ����. 
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
