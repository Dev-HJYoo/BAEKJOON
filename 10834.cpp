/*
	2019.2.27
	단순한 사칙연산 문제였다. 이번에 xor을 사용해서 방향을 정했다. xor => !=
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define SIZE 1000

using namespace std;

int arr[3][SIZE];
int main(void) {
	
	//선언부
	int n;
	int sum = 1;
	bool check = false;
	int a, b, c;

	// 초기화
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[0][i] = a;
		arr[1][i] = b;
		arr[2][i] = c;
	}

	// 솔루션
	for (int i = 0; i < n; i++) {
		sum = (sum / arr[0][i]) * arr[1][i];
		check = check != arr[2][i];
	}
	cout << check << " " << sum;
	
}