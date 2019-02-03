/*
	2019.2.2
	일단 답을 보고 문제를 이해하고 풀었다... dp문제는 아직도 힘든 것 같다
	먼저 홀수일 경우에는 되는 경우의 수가 없다
	짝수일 경우 
	1) -2의 경우에서 3x2의 경우의 수를 곱해준다.
	2) -4부터 끝까지는 각 자리에서 고유의 수(2)와 남은 타일의 경우의 수를 곱해준다.
	3) i일때 고유한 경우의 수(2)를 더한다. 
*/
#include <iostream>


using namespace std;

int dp[31] = {0};
int main(void){
	int n;
	cin>>n;
	
	dp[2] = 3;
	dp[3] = 0;
	for(int i = 4; i<=n; i++){
		if(i%2)
			dp[i] = 0;
		else{
			dp[i] += dp[i-2] * dp[2];
			for(int j = 4; j<i; j++)
				dp[i] += 2 * dp[i - j];
			dp[i] += 2;
		}
	}
	cout<<dp[n];
}
