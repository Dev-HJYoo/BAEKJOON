/*
	2019.2.2
	단순한 곱하기 문제이며 계속 틀렸던 이유는 c,d를 초기화 하지 않아서 발생한 문제였다. 
*/
#include <iostream>

using namespace std;

int main(void){
	int a,b;
	cin>>a>>b;
	
	int c = 0;
	int d = 0;
	int t = 100;
	while(a>=1){
		c += a%10 * t;
		d += b%10 * t;
		t/=10;
		a/=10;
		b/=10;
	}
	if(c>=d)
		cout<<c;
	else
		cout<<d;
}
