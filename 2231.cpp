#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1000000
using namespace std;
int check[SIZE + 1] = { 0 };
int main(void) {

	int n;
	scanf("%d", &n);
	for (int i = 10; i <= SIZE; i++) {
		int temp = i;
		int sum = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		if(!check[sum])
			check[sum] = i;
	}
	cout << check[n];
}