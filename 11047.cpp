#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	int K;
	vector<int> v;

	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int num = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (v[i] > K)
			continue;
		else if (K == 0)
			break;
		else {
			num += K / v[i];
			K %= v[i];
		}
	}
	cout << num;
	system("pause");
	return 0;
}