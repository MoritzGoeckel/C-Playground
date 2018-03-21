#include <stdio.h>

int getSize(char c[]){
	return sizeof(c);
}

int main(){
	char quote[] = "Hallo Welt!";
	printf("size of quote: %i \n", sizeof(quote));
	printf("size of quote in function: %i", getSize(quote));
}
