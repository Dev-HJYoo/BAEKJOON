/*
	2019.3.19
	���շ� �̶� ����� �������� �˾����� �׳� �ܼ��ϰ� �밡�� �ϴ� ��������...
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