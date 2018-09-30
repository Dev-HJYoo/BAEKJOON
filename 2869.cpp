/*
	2018.9.20
	와우... ㄹㅇ 수학문제 어렵네 ㅋㅋㅋㅋ 처음에 밑에 처럼 풀다가 시간 초과나고
	결국에는 공식 써서 만들었다...
	2번안에 안되면...
	2 + 올림(((높이 - (2 * up - down))/ (up -down)) 이다...
	잘 골라서 해봐봐 맞다 이게
	*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <cmath>

int main(void) {
	double up;
	double down;
	double height;

	scanf("%lf %lf %lf", &up, &down, &height);

	if (up >= height)
		printf("1");
	else if (height <= 2 * up - down) {
		printf("2");
	}
	else
		printf("%d", 2 + (int)ceil((height-(2 * up - down)) / (up - down)));
	/*
	이렇게 풀면 그냥 시간 초과가 된다...
	int check = 1;
	int gap = up - down;
	while ((gap * check) + up <= height)
		check++;
	printf("%d", check);*/
	return 0;
}