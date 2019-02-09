/*
	2019.2.8
	단순하게 다 구해놓고 구현하는 문제였다. 
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void){
	vector<bool> vec(123456*2 + 1);
	vec[1] = 1;
	vec[2] = 1;
	for(int i = 3; i<=123456 * 2; i+=2)
		vec[i] = true;
	for(int i = 3; i<=sqrt(123456 * 2); i+=2){
		if(!vec[i])
			continue;
		for(int j = i*3; j<=123456 * 2; j+= i*2)
			vec[j] = false;
		
	}
	int a;
	cin>>a;
	
	while(a){
		int sum = 0;
		for(int i = a+1; i<=2*a;i++)
			if(vec[i])
				sum++;
		cout<<sum<<"\n";
		cin>>a;
	}
}
