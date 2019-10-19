/*
	2019.10.18
	풀긴 했는데..... 100점 중 90 점이다. 
	그 이유는 일단 페르마의 소정리로 풀면 log 만에 풀리는데 dp로 하면 시간 초가가 나기 때문이라는데.... 페르마의 소정리가 이해가 안감..
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1000000
#include <vector>
using namespace std;

vector<vector<int> > dp;
int n,p;

void input() {
	scanf("%d %d", &n, &p);
	for (int i = 0; i <= n; i++) {
		vector<int> temp(i + 1,1);
		for (int j = 1; j <= i - 1; j++)
			temp[j] = (dp[i-1][j - 1] + dp[i-1][j]) % 1000000007;
		dp.push_back(temp);
	}
	cout << dp[n][p];
}

int main(void) {
	input();
}

