/*
	2019.2.18
	단순하게 갯수 세어서 조합을 찾는 문제이다.
	(갯수 + 1) * .... - 1(다 벗은 경우) = 답
	*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class cls {
public:
	string name, kind;
};



int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<cls> vec;
		for (int i = 0; i < n; i++) {
			cls a;
			cin >> a.name;
			cin >> a.kind;
			vec.push_back(a);
		}
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			if (m.end() == m.find(vec[i].kind))
				m.insert(make_pair(vec[i].kind, 1));
			else
				m[vec[i].kind] += 1;
		}
		int a = 1;

		for (auto it = m.begin(); it != m.end(); it++) {
			a *= (it->second + 1);
		}
		
		
		cout << a - 1 << "\n";
	}
}