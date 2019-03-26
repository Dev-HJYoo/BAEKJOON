/*
	2019.3.25
	단순한 스택으로 푸는 문제이다.
	여기서 geline과 ignore을 통해서 문자열 조절을 하는 것을 습득해 갔다.
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
