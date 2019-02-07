/*
	2019.2.7
	�ᱹ�� ���� ���� �ߴµ� �̷��� Ǫ�� ����� �ִٴ� ���� �������. 
	�̸� ������� ���� ���س��� �ؿ����� �׳� Ǯ������⸸ �ϸ� �Ǵ� �� ����.
	�׸��� scanf, printf�� �ð� ���� �ȳ��� ���ֱ� �Ѵ�. 
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
	while(a){  // 0 �� ���ð�� ����  
		for(int i = 0; i<size; i++){
			if(store[a-real[i]]){
				printf("%d = %d + %d\n", a, real[i], a-real[i]);
				break;
			}
		}
		scanf("%d", &a);
	}
}
