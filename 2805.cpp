#include <iostream>
#include <vector>
/*
	2019.1.22
	단순한 이분 분해 문제이다 
	int -> long long 바꾸는 거랑 check함수에서 low == mid 이부분을 어디에 넣는냐에 따라서 답이 달라졌다. 
*/

#include <algorithm>
using namespace std;
vector<long long> tree;
long long M,N;

void check(long long low, long long high){
	
	long long mid = (low + high)/2;

	long long sum = 0;
	
	long long a;
	for(long long i = 0; i< N; i++){
		a = tree[i] - mid;
		if(a>0)
			sum+= tree[i] - mid;
	}
		
	if(sum == M){
		cout<<mid;
		return;
	}
	if(low == mid){
		cout<<low;
		return;
	}
	else if(sum < M)
		check(low, mid);	
	else
		check(mid, high);	
}

int main(void){
	cin>>N>>M;
	
	long long a;
	long long max = 0;
	for(long long i = 0; i<N; i++){
		cin>>a;
		tree.push_back(a);
		if( max < a)
			max = a;
	}


	check(0, max);
} 
