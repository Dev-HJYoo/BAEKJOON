/*
2018.7.11 클리어
코드소스 길이가 너무 길긴한데...
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int main(void) {
	int N;
	scanf("%d", &N);
	int i = 1;
	int set[6];
	int total[10] = { 0,0,0,0,0,0,0,0,0,0 };
	if (N == 1000000 || N == 0) {
		printf("1");
		return 0;
	}
	
	while (N > 0) {
		int n = N % 10;
		set[i - 1] = n;
		N = N / 10;
		if (n == 9) {
			total[6]++;
			continue;
		}
		total[n]++;
		i++;
	}
	if (total[6] % 2)
		total[6] = total[6] / 2 + 1;
		
	else
		total[6] /= 2;
	int max = total[0];
	int maxIndex = 0;
	for (int i = 1; i < 10; i++) {
		if (max < total[i]) {
			max = total[i];
			maxIndex = i;
		}
	}
	printf("%d", max);
	return 0;
}