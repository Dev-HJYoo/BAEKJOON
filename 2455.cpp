/*
	2019.1.27
	시물레이션 이라고 해서 풀었는데.... 그냥 단순한 문제였네 ㅂㄷㅂㄷ. 
*/
#include <iostream>
#include <stack>

using namespace std;



int main(void){
	
	int in,out;
	
	int sum = 0;
	int max = 0;
	
	for(int i = 0; i<4; i++){
		cin>>out>>in;
		sum -= out;
		if (max < sum)
			max = sum;
		sum += in;
		if (max < sum)
			max = sum;
	}
	cout<<max;
	
	
} 
