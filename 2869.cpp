/*
	2018.9.20
	�Ϳ�... ���� ���й��� ��Ƴ� �������� ó���� �ؿ� ó�� Ǯ�ٰ� �ð� �ʰ�����
	�ᱹ���� ���� �Ἥ �������...
	2���ȿ� �ȵǸ�...
	2 + �ø�(((���� - (2 * up - down))/ (up -down)) �̴�...
	�� ��� �غ��� �´� �̰�
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
	�̷��� Ǯ�� �׳� �ð� �ʰ��� �ȴ�...
	int check = 1;
	int gap = up - down;
	while ((gap * check) + up <= height)
		check++;
	printf("%d", check);*/
	return 0;
}