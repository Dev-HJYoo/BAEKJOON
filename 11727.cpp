/*
	2019.1.17
	이거 그냥 인터넷보고 했다... 이렇게 점화식을 가져오는 법을 찾아야 할텐데.. 힘내자..
	 
*/
#include <iostream>

using namespace std;

long long dp[1001] = {0};
int main(void){
	
	int N;
	cin>>N;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i<=N; i++)
		dp[i] = (dp[i-1] + dp[i-2]*2) %10007;
	cout<<dp[N];
}

