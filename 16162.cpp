/*
	2019.1.17
	재밌는 문제이네 ㅋㅋㅋ 그냥 단순하게 규칙만 찾으면 할 수 있는 문제였다. 
*/

#include <iostream>

using namespace std;

int main(void){
	
	int n,a,d;
	cin>>n>>a>>d;
	
	int sum = 0;
	int temp;
	for(int i = 0; i<n; i++){
		cin>>temp;
		
		if(temp == a +  d*sum){
			sum++;	
		}
	}
	cout<<sum;
}
