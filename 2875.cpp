/*
	2019.1.18
	�׳� ���ݸ� �����c�� �ϴϱ� �ٷ� Ǯ���� ������  
*/
#include <iostream>

using namespace std;

int main(void){
	int n,m,k;
	cin>>n>>m>>k;
	
	int man = m;
	int woman = n/2;
	
	int sum = k;
	int total = man>woman ? woman:man;
	sum -= m - total;
	sum -= n - total*2;
	for(int i = 0 ; sum>0; i++){
		total--;
		sum-=3;
	}
	cout<<total;
}
