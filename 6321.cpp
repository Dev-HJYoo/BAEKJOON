/*
	2019.1.18
	출력형식때문에 틀렸따가 그냥 바로 풀었다.
	아스키 코드 쓰면 바로 풀 수 있다. 
*?
#include <iostream>
#include <string>

using namespace std;

int main(void){
	int N;
	cin>>N;
	
	string temp;
	for(int i = 1; i<=N; i++){
		cin>>temp;
		int size = temp.size();
		for(int j = 0; j<size; j++){
			temp[j]++;
			if(temp[j] == '[')
				temp[j] = 'A';
		}
		cout<<"String #"<<i<<"\n";
		cout<<temp;
		if(i==N)
			continue;
		else
			cout<<"\n\n";
	}
} 
