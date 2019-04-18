#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <limits.h>
using namespace std;

int maps[52][52];
vector<pair<int, int> > chi;
vector<pair<int, int> > zip;
int n, m;
int mins = INT_MAX;
vector<pair<int, int > > chis;


int distance(int x, int y, int r, int c) {
	return abs(x - r) + abs(y - c);
}

void check(int pos, int size) {
	
	if (size == m) {
		int s = zip.size();
		int soso = 0;
		for (int i = 0; i < s; i++) {
			int so = INT_MAX;
			for (int j = 0; j < size; j++) {
				int a = distance(zip[i].first, zip[i].second, chis[j].first, chis[j].second);
				if (a < so) {
					so = a;
					
				}
			}
			soso += so;
		}
		if (mins > soso)
			mins = soso;
		return;
	}

	if (pos == chi.size())
		return;

	chis.push_back(chi[pos]);
	check(pos + 1, size + 1);

	vector<pair<int, int> > ::iterator it = chis.end() - 1;
	chis.erase(it);
	check(pos + 1, size);
	
}

int main(void) {
	memset(maps, 0, sizeof(maps));
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &maps[i][j]);
			if (maps[i][j] == 1)
				zip.push_back({ i,j });
			if (maps[i][j] == 2)
				chi.push_back({ i,j });
		}
	}
	
	check(0, 0);
	cout << mins;
}