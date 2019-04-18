#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int to[4][8];

void move(int n) { // 시계방향
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = to[n][i];
	for (int i = 1; i < 8; i++)
		to[n][i] = temp[i - 1];
	to[n][0] = temp[7];
}

void rmove(int n) { // 반시계방향
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = to[n][i];
	for (int i = 6; i >=0; i--)
		to[n][i] = temp[i + 1];
	to[n][7] = temp[0];
}


int main(void) {
	memset(to, 0, sizeof(to));
	for (int i = 0; i < 4; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < 8; j++)
			to[i][j] = a[j] - 48;
	}
	
	
	int k;
	scanf("%d", &k);

	while (k--) {
		int state[4] = { 2,2,2,2 };
		int n, d;
		scanf("%d %d", &n, &d);
		state[n - 1] = d;
		switch (n) {
		case 1:
			if (to[n - 1][2] != to[n][6]) { // 1-2비교
				if (to[n][2] != to[n + 1][6]) { // 2-3비교
					if (to[n + 1][2] != to[n + 2][6]) { // 3-4비교
						state[n + 2] = -d;
					}
					state[n + 1] = d;
				}
				state[n] = -d;
			}
			break;
		case 2:
			if (to[n - 2][2] != to[n-1][6]) { // 1-2비교
				state[n - 2] = -d;
			}
			if (to[n-1][2] != to[n][6]) { // 2-3비교
				if (to[n][2] != to[n + 1][6]) { // 3-4비교
					state[n + 1] = d;
				}
				state[n] = -d;
			}
			break;
		case 3:
			if (to[n-1][2] != to[n][6]) { // 3-4비교
				state[n] = -d;
			}
			if (to[n - 2][2] != to[n-1][6]) { // 2-3비교
				if (to[n - 3][2] != to[n - 2][6]) { //1-2비교
					state[n - 3] = d;
				}
				state[n - 2] = -d;
			}
			break;
		case 4:
			if (to[n - 2][2] != to[n-1][6]) { // 3-4비교
				if (to[n - 3][2] != to[n - 2][6]) { // 2-3비교
					if (to[n - 4][2] != to[n - 3][6]) { // 1-2비교
						state[n - 4] = -d;
					}
					state[n - 3] = d;
				}
				state[n - 2] = -d;
			}
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (state[i] == 1)
				move(i);
			if (state[i] == -1)
				rmove(i);
		}
	
	}
	int sum = 0;
	int mo = 1;
	for (int i = 0; i < 4; i++) {
		if (to[i][0] == 1)
			sum += mo;
		mo *= 2;
	}
	cout << sum;
}