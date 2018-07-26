#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int T;
	scanf("%d", &T);
	int total = 0;
	for (int _ = 0; _ < T; _++) {
		int n;
		scanf("%d", &n);
		int i;
		for (i = 2; i < n; i++)
			if (n%i == 0)
				break;
		if (i == n)
			total++;
	}
	printf("%d", total);
	return 0;
}