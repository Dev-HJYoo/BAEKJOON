/*
	2019.1.18
	이것도 그냥 조금만 생각해보니깐 점화식이 나와서 풀었따/.	
*/

#include <iostream>

using namespace std;

int arr[1001] = {0};
int main(void){
	int N;
	int M;
	
	cin>>N>>M;
	int num = 0;
	cout<<"<";
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; ){
			num++;
			if(arr[num] == 1)
				continue;
			j++;
			if(num > N){
				num = 1;
				while(arr[num] == 1)
					num++;
			}
		}
		arr[num] = 1;
		if(i == N-1)
			cout<<num<<">";
		else
			cout<<num<<", ";
	}
}  
