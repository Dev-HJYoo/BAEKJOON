/*
	2019.3.20
	재미있는 문제였다 ㅋㅋㅋ 그냥 단순하게 자릿수를 구하는 문제였다.
	마지막에 무조건 1번씩 더해지기 때문에 뺴주는 거 했다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void) {
	
	// init
	int t;
	
	scanf("%d", &t);

	//solution
	for(int i = 1; i<=t; i++) { 
		bool arr[10] = { 0,0,0,0,0,0,0,0,0,0};
		int n;
		scanf("%d", &n);

		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", i);
			continue;
		}
		int mul = n;
		while (1) {
			if (arr[0] && arr[1] && arr[2] && arr[3] && arr[4] && arr[5] && arr[6] && arr[7] && arr[8] && arr[9])
				break;
			int temp = n;
			while (temp > 0) {
				arr[temp % 10] = true;
				temp /= 10;
			}
			n += mul;
		}
		printf("Case #%d: %d\n", i, n - mul);
	}
}