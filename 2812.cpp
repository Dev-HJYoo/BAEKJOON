/*
	2019.2.4
	�ϴ� �̹��� ignore �̶�� �Լ��� �˰� �Ǿ��� ���๮�ڸ� �ȳ־ ��� Ʋ�ȴٰ� ���Գ�...
	 
*/
#include <iostream>
#include <string>
using namespace std;

int main(void){
	 int n;
	 
	 cin>>n;
	 
	 for(int i = 0; i<n; i++){
	 	string s;
	 	cin>>s;
	 	cin.ignore(80,'\n');
		
		int size = s.size();
		int sum = 0;
		int longs = 0;
		for(int j = 0; j<size; j++){
			if(s[j] == 'O'){
				longs++;
				sum += longs;
			}
			else
				longs = 0;
			
		}
		cout<<sum<<"\n";
	 }
}
