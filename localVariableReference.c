#include <stdio.h>

int& doSomething(){
	//X is local
	int x = 30;
	return x; //Returning an reference to local variable
}

int main(){
	//Will produce an error
	printf("its %i", doSomething()); 
}
