/*
	2019.2.7
	결국에 답을 보고 했는데 이렇게 푸는 방법도 있다는 것을 기억하자. 
	미리 어느정도 답을 구해놓고 밑에서는 그냥 풀어버리기만 하면 되는 것 같다.
	그리고 scanf, printf가 시간 고촤 안나게 해주긴 한다. 
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

vector<bool> store(1000001);
vector<int> real;
int main(void){
	
	int a;
	
	for(int i = 3; i<=1000000; i+=2){
		store[i] = true;
	}
	for(int i = 3; i<=sqrt(1000000); i+=2){
		if(!store[i])
			continue;
		else{
			for(int j = i*3; j<=1000000; j += i * 2)
				store[j] = false;
		}
	}
	
	
	for(int i = 3; i<=1000000; i+=2){
		if(store[i])
			real.push_back(i);
	}
	
	scanf("%d", &a); 
	int size = real.size();
	while(a){  // 0 이 나올경우 종료  
		for(int i = 0; i<size; i++){
			if(store[a-real[i]]){
				printf("%d = %d + %d\n", a, real[i], a-real[i]);
				break;
			}
		}
		scanf("%d", &a);
	}
}
