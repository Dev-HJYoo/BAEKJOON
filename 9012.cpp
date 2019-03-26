/*
	2019.3.25
	�ܼ��� �������� Ǫ�� �����̴�.
	���⼭ geline�� ignore�� ���ؼ� ���ڿ� ������ �ϴ� ���� ������ ����.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {

	// init
	int t;
	scanf("%d", &t);
	cin.ignore();
	while (t--) {
		stack<char> st;
		char a[51];
		cin.getline(a, 51);
		for (int i = 0; a[i] != NULL; i++) {
			if (a[i] == '(')
				st.push('(');
			else {
				if (st.empty()) {
					st.push(a[i]);
					break;
				}
				else
					st.pop();
			}
		}
		if (st.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
}
