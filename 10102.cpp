/*
	2019.1.19
	음... 그냥 너무 쉬운문제네	
*/
#include <iostream>

using namespace std;

int main(void){
	int N;
	int a=0;
	int b=0;
	
	cin>>N;
	char temp;
	for(int i=0 ;i<N; i++){
		cin>>temp;
		if(temp == 'A')
			a++;
		else
			b++;
		
	}
	if(a == b)
		cout<<"Tie";
	else if(a>b)
		cout<<"A";
	else
		cout<<"B";
}
