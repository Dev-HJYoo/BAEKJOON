/*
	2019.1.28
	�׳� �ܼ��� ���й����̴�.
	ó���� Ʋ�ȴ� ������ sum�� long long���� ���� �ʾƼ� Ʋ�ȴ�. 
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main(void){
	
	int n;
	cin>>n;
	
	
	for(int i= 0; i<n; i++){
		int a;
		cin>>a;
		vec.push_back(a);
	}
	
	int super,semi;
	cin>>super>>semi;
	
	long long sum = n;
	
	for(int i = 0; i<n; i++){
		vec[i] -= super;
		if(vec[i] <= 0)
			continue;
		if(vec[i]%semi)
			sum += vec[i]/semi +1;
		
		else
			sum += vec[i]/semi;
	}
	cout<<sum;
}
