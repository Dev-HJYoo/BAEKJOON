/*
	2019.1.27
	단순한 if문 문제 였다. 
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	int size;
	string s;
	cin>>s;
	size = s.size();
	
	int sum = 0;
	for(int i = 0; i<size; i++){
		if(s[i] <= 67)
			sum += 2;
		else if(s[i] <= 70)
			sum += 3;
		else if(s[i] <= 73)
			sum += 4;
		else if(s[i] <= 76)
			sum += 5;
		else if(s[i] <= 79)
			sum += 6;
		else if(s[i] <= 83)
			sum += 7;
		else if(s[i] <= 86)
			sum += 8;
		else 
			sum += 9;
	}
	
	cout<<sum + size;
}
