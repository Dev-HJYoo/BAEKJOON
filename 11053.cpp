/*
	2019.7.23
	그냥 번뜩 아이디어가 떠올라서 풀었다. 
	이 문제 같은 경우 그냥 현재를 먹냐 안먹냐 이것으로 생각하다가 현재를 기준으로 전에꺼 중에 자기보다 작으면서 길이가 큰 값을 고르면 되겠다는 생각이들었다.
	즉, 현재 값 > 전의 값 & 이때까지의 길이 < 전의 값에 대한 길이
	이런 점화식을 만들어 풀었다.
	*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1001
using namespace std;

int n;
int dp[2][SIZE] = { 0 };

void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &dp[0][i]);
}

void solve() {
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		int num = dp[0][i];
		for (int j = 1; j < i; j++) {
			if (dp[0][j] < num && dp[1][j] > dp[1][i] ) {
				dp[1][i] = dp[1][j];
			}
		}
		dp[1][i]++;
	}
	
}

void print() {
	int max = dp[1][1];
	for (int i = 2; i <= n; i++)
		if (dp[1][i] > max)
			max = dp[1][i];
	printf("%d", max);
}

int main(void) {
	input();
	solve();
	print();
}