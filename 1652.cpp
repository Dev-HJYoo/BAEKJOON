/*
	Ʋ�� ����� ���� �� �𸣰ڴ�......
	2018.7.27
	�ƈ��������� ������ �߸������ߴ�.
	..xx.. �̸� +1 �� �ƴ϶� +2��.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>

using namespace std;
int main(void) {
	int N;
	scanf("%d", &N);
	char **store = new char*[N];
	for (int _ = 0; _ < N; _++) {
		store[_] = new char[N];
		scanf("%s", store[_]);
	}

	int col = 0;
	for (int i = 0; i < N; i++) {
		string a = "";
		if (store[i][0] == '.')
			a +=store[i][0];
		for (int _ = 1; _ < N; _++) {
			char n = store[i][_];
			if (n == '.')
				a += n;
			else
				a = "";
			if (a == "..") {
				col++;
			}
		}
	}

	int row = 0;
	for (int i = 0; i < N; i++) {
		string a = "";
		if (store[0][i] == '.')
			a += store[0][i];
		for (int _ = 1; _ < N; _++) {
			char n = store[_][i];
			
			if (n == '.')
				a += n;
			else
				a = "";
			if (a == "..") {
				row++;
			}
		}
	}
	printf("%d %d", col, row);
	return 0;
}