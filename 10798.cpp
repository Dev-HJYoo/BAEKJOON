#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

char store[5][15] ;
int main(void) {
	
	for (int i = 0; i < 5; i++) 
		scanf("%s", store[i]);
	

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (store[j][i] != NULL)
				printf("%c", store[j][i]);
		}
	}

	
}