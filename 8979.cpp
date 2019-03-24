/*
	2019.3.20
	ó������ ����� �������� �˾�����.... �׳� �ܼ��ϰ� �񱳹��� ������ ���� �Ǵ� ���̿���.
	�׸��� ó���� �����ߴ��Ŷ� �ٸ��� �׳� ū�� � �ִ����� ���ϸ� �Ǵ� ��������...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class cls {
public:
	int n, g, s, b;
};

bool checks(cls a, cls b) {
	if (a.g > b.g)
		return true;
	if (a.g < b.g)
		return false;

	if (a.s > b.s)
		return true;
	if (a.s < b.s)
		return false;

	if (a.b > b.b)
		return true;
	if (a.b < b.b)
		return false;

	return true;
}

int main(void) {

	// init
	int n, k;
	vector<cls> vec;
	scanf("%d %d", &n, &k);

	cls check;

	for (int i = 0; i < n; i++) {
		cls temp;
		scanf("%d %d %d %d", &temp.n, &temp.g, &temp.s, &temp.b);
		vec.push_back(temp);
		if (temp.n == k) {
			check.g = temp.g;
			check.s = temp.s;
			check.b = temp.b;
			check.n = k;
		}
	}


	// solution
	int top = 0;
	int equal = 0;
	for (int i = 0; i < n; i++) 
		if (!checks(check, vec[i]))
			top++;
	
	cout << top + 1;
}