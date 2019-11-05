/*
	2019.11.4
	����.. �ᱹ Ǯ��� �ߴµ� �̰� long long�� ���� �������ִ°� ��������. ��, �Ѱ谪 ������ �˰� �ؾ��� �� ����.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define SIZE 64
#define M 1000000007
using namespace std;

long long a, x;
long long store[SIZE] = { 0 };

void input() {
	scanf("%lld %lld", &a, &x);
}

string check(long long num) {
	string temp = "";
	while (num > 1) {
		long long t = num % 2;
		if (t)
			temp = "1" + temp;
		else
			temp = "0" + temp;

		num /= 2;
	}
	return "1" + temp;
}

long long total(string str) {
	long long size = str.size();
	long long t = 0;
	long long result = 1;
	for (long long i = size - 1; i >= 0; i--, t++) {
		if (str[i] == '1') {
			result *= store[t] % M;
			result %= M;
			//cout << i - size+1 << " " << store[t] % M << " " << result<<endl;
		}
	}
	return result % M;
}

void solve() {
	store[0] = a % M;
	//cout << 0 << " "<<store[0] << endl;
	for (long long i = 1,t = 1;; i++) {
		t *= 2;
		if (t > x)
			break;
		store[i] = (store[i - 1] * store[i - 1]) % M;
		//cout << i<<" "<< store[i]<< endl;
	}
	string num = check(x);
	//cout << num<<endl;
	long long result = total(num);
	cout << result;
}

int main(void) {
	input();
	solve();
}