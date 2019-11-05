/*
	2019.11.5
	�丣���� �������� �̿��� �����̴�.. �ٵ� �ʹ� ��Ƴ� ��� �̰͵� �׳� �P�ܼ� Ǭ����... ������ ���� �����ϰڴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 4000001
#define M 1000000007LL

using namespace std;

long long n, k;

long long fac[SIZE] = { 0 };
long long inv[SIZE] = { 0 };

void input() {
	scanf("%lld %lld", &n, &k);
}

long long power(long long x, long long y) {
	if (y == 0)
		return 1;
	else {
		long long temp = power(x, y / 2) ;
		if (y % 2)
			return (((temp * temp) % M) * x) % M; // ���� �� ���� ����ؼ� ��������Ѵ�.
		else
			return (temp * temp) % M;
	}
}

void solve() {
	fac[1] = 1;
	for (int i = 2; i < SIZE; i++) // factorial ���ϱ�
 		fac[i] = (fac[i - 1] * i) % M;
	inv[SIZE - 1] = power(fac[SIZE - 1], M - 2); // 400�� �ڸ� ���ϱ�
	for (int i = SIZE - 2; i > 0; i--) // inverse ���ϱ�.  ������ inv(n) = inv(n+1) * n+1
		inv[i] = (inv[i + 1] *(i+1)) % M;
	
	long long answer = (fac[n] * inv[k]) % M;
	answer = (answer * inv[n - k]) % M;
	if (k == 0 || n == k)
		printf("1");
	else
		printf("%lld", answer);
}

int main(void) {
	input();
	solve();
}