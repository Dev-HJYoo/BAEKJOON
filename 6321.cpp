/*
	2019.1.18
	������Ķ����� Ʋ�ȵ��� �׳� �ٷ� Ǯ����.
	�ƽ�Ű �ڵ� ���� �ٷ� Ǯ �� �ִ�. 
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
