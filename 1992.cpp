/*
	2019.11.3
	��.. ���� ���� �����ε� ��¼�� ���ϱ� Ǯ�ȳ�... ��� Ʋ�ȴ� ������ ��ġ�� �������� ũ�Ⱑ 4�̿����� ��ĥ �� �ִµ� �׳� ���ļ� ���������� ����.
	���������� �� �� �����ؾ��ҵ�...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 64
#include <string>
using namespace std;

int n;
char arr[SIZE][SIZE] = { 0 };

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++)
			arr[i][j] = a[j];
	}
}

string divide(int x, int y, int s) {
	string temp = "";
	if (s == 1) {
		string z = "";
		z += arr[x][y];
		return z;
	}
	temp += divide(x, y, s / 2);
	temp += divide(x , y + s/2, s / 2);
	temp += divide(x + s / 2, y, s / 2);
	temp += divide(x + s / 2, y + s/2, s / 2);
	//cout << x << " " << y << " " << temp << endl;
	if(temp.size() != 4)
		return "(" + temp + ")";
	for(int i = 0; i<3; i++)
		if(temp[i] != temp[i+1])
			return "(" + temp + ")";
	string a = "";
	a += temp[0];
	return a;
}



void solve() {
	string answer = divide(0,0,n);
	cout << answer << endl;;
}

int main(void) {
	input();
	solve();
}