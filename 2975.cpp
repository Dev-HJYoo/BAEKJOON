/*
	2019.3.19
	조합론 이라서 어려운 문제인줄 알았지만 그냥 단순하게 노가다 하는 문제였다...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void) {

	// 
	int a, b, c;
	char c1, c2;
	scanf("%d %d %d", &a, &b, &c);
	
	if (a + b == c) {
		c1 = '+';
		c2 = '=';
	}
	else if (a - b == c) {
		c1 = '-';
		c2 = '=';
	}
	else if (a * b == c) {
		c1 = '*';
		c2 = '=';
	}
	else if (a / b == c) {
		c1 = '/';
		c2 = '=';
	}

	if (a == b + c) {
		c1 = '=';
		c2 = '+';
	}

	else if (a == b - c) {
		c1 = '=';
		c2 = '-';
	}
	else if (a == b * c) {
		c1 = '=';
		c2 = '*';
	}
	else if (a == b / c) {
		c1 = '=';
		c2 = '/';
	}

	printf("%d%c%d%c%d", a, c1, b, c2, c);
}