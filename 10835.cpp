#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int leftdec[2000] = { 0 };
int rightdec[2000] = { 0 };
int dp[2000][2000] = { -1 };
int n;

int max(int a, int b) {
	return a > b ? a : b;
}

int solution(int x, int y) {
	
	if (x == n || y == n)
		return 0;
	
	int &result = dp[x][y];
	cout << result;
	if (result != -1)
		return result;

	result = 0;
	
	if (leftdec[x] > rightdec[y])
		result += rightdec[y] + solution(x, y + 1);
	else
		result += max(solution(x + 1, y + 1), solution(x + 1, y));

	return result ;
}

int main(void) {


	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &leftdec[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &rightdec[i]);

	memset(dp, -1, sizeof(dp));
	
	printf("%d",solution(0, 0));

}