#include <stdio.h>

int main(){
	puts("What is your name?");
	char name[20];
	scanf("%19s", name);
	printf("Hallo %s", name);
	return 0;
}
