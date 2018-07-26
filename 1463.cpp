/*
2018.7.15
dp문제의 시작!!

*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {
	int N;
	scanf("%d", &N);
	int * arr = new int[N+1];
	arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}
	printf("%d", arr[N]);
	delete arr;
	return 0;
}