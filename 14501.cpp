#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class cls {
public:
	int t;
	int p;
};

int ans = 0;
int n;
vector<cls> vec;

void sum(int day, int temp) {

	ans = ans < temp ? temp : ans;

	for (int i = day; i <= n; i++) {
		if (i + vec[i].t<= n+1)
			sum(i + vec[i].t, temp + vec[i].p);
	}
}
int main(void) {


	scanf("%d", &n);
	cls temp;
	vec.push_back(temp);
	for (int i = 1; i <= n; i++) {
		cls temp;
		scanf("%d %d", &temp.t, &temp.p);
		vec.push_back(temp);
	}

	sum(1, 0);
	cout << ans;
	

}