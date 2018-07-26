#include<iostream>
#include <vector>

using namespace std;

int main(void) {
	int man;
	int con;
	vector<int> multi;
	cin >> man;
	cin >> con;

	for (int i = 0; i < con; i++) {
		int a;
		cin >> a;
		multi.push_back(a);
	}
	int n = multi.size();
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (temp >= man)
			break;
		if (multi[i] % 2 == 0)
			temp += multi[i] / 2;
		else
			temp += multi[i] / 2 + 1;
	}

	if (temp < man)
		cout << "NO";
	else
		cout << "YES";
	system("pause");
	return 0;
}