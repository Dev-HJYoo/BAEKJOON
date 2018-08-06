#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	long *data = new long[N];

	for (int i = 0; i < N; i++) {
		long a;
		scanf("%ld", &a);
		data[i] = a;
	}

	int size;
	scanf("%d", &size);

	long sum = 0;
	for (int i = 0; i < N; i++) {
		long a = data[i] / size;
		long b = data[i] % size;
		if (b != 0)
			sum++;
		sum += a;
	}

	printf("%ld", size * sum);
	return 0;
}