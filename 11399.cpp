#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(void) {
	int number;
	vector<int> v;
	int s;
	cin >> number;
	for (int i = 0; i<number; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	s = 0;
	int t = 0;
	for (int i = 0; i < number; i++) {
		s += v[i] + t;
		t += v[i];
	}
	cout << s;
	system("pause");
	return 0;
}