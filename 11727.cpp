/*
	2019.1.17
	�̰� �׳� ���ͳݺ��� �ߴ�... �̷��� ��ȭ���� �������� ���� ã�ƾ� ���ٵ�.. ������..
	 
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

