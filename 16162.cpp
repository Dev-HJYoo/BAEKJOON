/*
	2019.1.17
	��մ� �����̳� ������ �׳� �ܼ��ϰ� ��Ģ�� ã���� �� �� �ִ� ��������. 
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
