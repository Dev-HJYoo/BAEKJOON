#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

string n;
long long b;

void input() {
	cin >> n;
	scanf("%lld", &b);
}

void solve() {
	map<char, int> m;
	m.insert({ '1',1 });
	m.insert({ '2',2 });
	m.insert({ '3',3 });
	m.insert({ '4',4 });
	m.insert({ '5',5 });
	m.insert({ '6',6 });
	m.insert({ '7',7 });
	m.insert({ '8',8 });
	m.insert({ '9',9 });
	m.insert({ 'A', 10 });
	m.insert({ 'B',11 });
	m.insert({ 'C',12 });
	m.insert({ 'D',13 });
	m.insert({ 'E',14 });
	m.insert({ 'F',15 });
	m.insert({ 'G',16 });
	m.insert({ 'H',17 });
	m.insert({ 'I',18 });
	m.insert({ 'J',19 });
	m.insert({ 'K',20 });
	m.insert({ 'L',21 });
	m.insert({ 'M',22 });
	m.insert({ 'N',23 });
	m.insert({ 'O',24 });
	m.insert({ 'P',25 });
	m.insert({ 'Q',26 });
	m.insert({ 'R',27 });
	m.insert({ 'S',28 });
	m.insert({ 'T',29 });
	m.insert({ 'U',30 });
	m.insert({ 'V',31 });
	m.insert({ 'W',32 });
	m.insert({ 'X',33 });
	m.insert({ 'Y',34 });
	m.insert({ 'Z',35 });
	
	int size = n.size();
	long long sum = 0;
	long long cop = 1;
	for (int i = size - 1; i >= 0; i--, cop *= b) {
		sum += m[n[i]] * cop;
		cout << sum << endl;
	}
	printf("%lld", sum);
}
int main(void) {
	input();
	solve();
}