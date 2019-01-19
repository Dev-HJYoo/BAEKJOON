#include <iostream>
#include <math.h>
using namespace std;

int main(void){
	int x,y,w,h;
	cin>>x>>y>>w>>h;
	int min = abs(x) > abs(y) ? y : x;
	int min2 = abs(x-w) > abs(y-h) ? abs(y-h) : abs(x-w) ;
	min = min > min2 ? min2 : min;
	cout<<min;
}
