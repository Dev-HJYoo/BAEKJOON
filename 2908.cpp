/*
	2019.2.2
	�ܼ��� ���ϱ� �����̸� ��� Ʋ�ȴ� ������ c,d�� �ʱ�ȭ ���� �ʾƼ� �߻��� ��������. 
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
