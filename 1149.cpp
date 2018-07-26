/*
 2018.7.17
 이번에도 인터넷 도움을 좀 받았지만 그래도 어느 정도는 머리를 굴려서 만들었다.
  정말로 모든 경우를 다해봐서 넣었다. 
  i-1 이 R,G,B 각각 일때 
  i-1 = R => i= G,B
  i-1 = G => i= R,B
  i-1 = B => i= R,G 

  이렇게 해서 각각 다구하고 최솟값을 찾았다.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int min(int a, int b) {
	return a > b ? b : a;
}

int min(int a, int b, int c) {
	return a > b ? (b > c ? c : b) : (a > c ? c : a);
}

int main(void) {
	int N;
	scanf("%d", &N);

	int ** color = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		color[i] = new int[3];

	for (int i = 1; i <=N; i++) {
		for (int j = 0; j < 3; j++) {
			int n;
			scanf("%d", &n);
			color[i][j] = n;
		}
	}

	color[0][0] = 0;
	color[0][1] = 0;
	color[0][2] = 0;
	
	int ** dp = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		dp[i] = new int[3];

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	printf("%d", min(dp[N][0], dp[N][1], dp[N][2]));
	return 0;
}