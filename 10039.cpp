#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int a;
		scanf("%d", &a);
		
		if (a < 40)
			a = 40;
		sum += a;
	}
	printf("%d", sum/5);
	return 0;
}