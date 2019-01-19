/*
	2019.1.19
	이건 그냥 쉬운 문제다. 
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int arr[1001] = {0};

int main(void){
	int c;
	cin>>c;
	
	for(int _ = 0; _<c; _++){
		int n;
		cin>>n;
		int sum = 0;
		for(int i = 1; i<=n; i++){
			cin>>arr[i];
			sum+= arr[i];
		}
		sum /= n;
		float total = 0;
		for(int i = 1; i<=n; i++)
			if(sum < arr[i])
				total++;
		printf("%0.3f%%\n", total/n*100);	
	}
}
