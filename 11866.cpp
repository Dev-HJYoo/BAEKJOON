/*
	2019.1.18
	�̰͵� �׳� ���ݸ� �����غ��ϱ� ��ȭ���� ���ͼ� Ǯ����/.	
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
