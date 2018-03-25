# Cheat sheet
## String to Int
```c
int num = atoi(char[] str)
```

## Console out
```c
puts("...")
```

## Formatted multitype output
```c
printf("%s %i %p", somechar[], someint, somepointer)
```

## Read int
```c
int decks
scanf("%i", &decks) //have to use the adress
//%f for floating point number
```

## Read string
```c
char s[20];
scanf("%19s", s) //up to 19 chars into s
```

## Read string fgets
```c
fgets(s, sizeof(s), stdin); //stdin == keyboard
```

## Main
```c
int main(){ return 0; }
```

## libs
```c
#include <stdio.h>
#include <stdlib.h>
```

## Adress
```c
&var
```

## Pointer
```c
int* p = &var;
```

## Dereference
```c
int num = *p;
*p = 10;
```

## Create a string
```c
char s[] = "Hallo Welt";
```

## String pointers are immutable
```c
char* s = "Hallo Welt"
s[5] = 'A'; //-> ERROR
```

## Sizeof
```c
sizeof(int) -> 4
sizeof("1234") -> 4 + 1 -> 5
```

## Arrays and pointers

Arrays are implicitly converted to pointers to the first element

```c
int c[] = {1,2,3};
int* pi = c; //Ok
*pi // -> 1
```

Arrays are converted to pointers to first element when passed to a function. Size of array is not retrievable after conversion to pointer. This loss of information is called "decay"

```c
char s[] = "Hallo Welt"
sizeof(s) -> 11 //Size of the array
size(s); -> 8 //Size of the pointer s
void size(char s[]){
	return sizeof(s) 
}
```

## Init an array
```c
int i[] = {1, 2, 3, 4};
```

## Accessing array element
```c
i[0]
*(i + 0)
```

## Accessing array from element 6
```c
i + 6
```

## A riddle
```c
int i[] = {1, 2, 3};
i[2] == *(i + 2) == *(2 + i) == 2[i]
```


## Const!
```c
const int i = 0;
```

## String functions
```c
#include <string.h>
strlen //length
strcat //concatinate two strings
strcpy //copy string from one to another
strstr //find location of one string in another
strcmp //compare two strings
strchr //find location of char in string
```

## Redirecting input with < and the output with >
```sh
first < data.txt > out.txt
```

## Redirecting stderr
```sh
first < data.txt 2> errors.txt
```

## Piping data from one software to the other
```c
some | thing < input.txt > output.txt
```

## Send to stdout and stderr
```c
fprintf(stdout, "I like turtles")
fprintf(stderr, "I like turtles %i", someint)
```

## File
```c
FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");

fprintf(out, "Yo");
fscanf(in, "%79", chars)

fclose(in);
```

## Commandline parameters
```c
int main(int argcount, char *argv[]){ return 0; }
//First parameter is name of software
```

## Read option flags
```c
#include <unistd.h>
getopt(argc, argv, "optionstring")
```

## Casting like in Java
```c
float x = (float) y / z;
```

## Unsigned and long variables
```c
unsigned long x; //Double the size of a long
long long x; //Really big number
long double x; //Really percise number
```

## Get limits
```c
#include <limits.h> //For int ant chars etc
#include <float.h> //For float
INT_MAX, INT_MIN
FLT_MAX, FLT_MIN
```

## Declare functions via their signature first to avoid problems with the order of definition
```c
float returnsomeFloat(int x);
```

## This can be extracted into a h header file
The import of this file looks like this
```c
#include "filename.h"
```

## Share variables: Define them in an header file, mark them with extern
```c
extern int a = 0;
```

## Compile and link multiple files
Create header, include header in all c files -> can use function
```sh
g++ somename.c someother.c -o out
```

## Compile all files to object code (auto skip existing)
```sh
gcc -c *.c
```

## Link files after object code is generated
```sh
gcc *.o -o out
```

## Make compile
```make
target.o: dependency1.c dependency2.c dependency3.h
	gcc -c target.c
```	
	
## Make link
```make
target: dependency1.o dependency2.o
	gcc dependency1.o dependency2.o -o target
```	
	
## Create makefiles automatically
With autoconf

## Strunct
```c
struct fish {
	int size;
	const char* name; 
}

// Instanciate
struct fish mark = {10, "Mark"};

// Access
mark.size = 20;
```

## typedef to alias types
```c
typedef int zahl;
zahl a = 10;
```

## Possible to skip struct name with typedef
```c
typedef struct {
	int size;
	const char* name; 
} fish;

//fish* f = &{10, "Mark"};
(*f).size //10
*f.size // == *(f.size) ERROR
f->size //10

//Init struct
fish f = {.size = 10};
```

## Union is a struct that only holds only one data field

You can only set one value, the size is equal to the bigger possible types size

```c
typedef union{
	int count;
	float liters;
} quantity;
```

## enums
```c
enum colors {RED, GREEN, BLUE};
enum colors favoriteColor = BLUE;
typedef enum {RED, GREEN, BLUE} colors;
```

## Bitfields; How many bits shoulds be reserved?
```c
unsigned int onebit:1; //Only uses one bit -> 0/1
```

## Allocate memory
```c
#include<stdlib.h>
somestruct* p = malloc(sizeof(somestruct))
p->somevalue = 10;

//Dealocate
free(p);
```

## Creating function pointers
```c
returnType (*varName) (paramType1, paramType2, ...)
```

## Example: Function pointers -> squared
```c
int square(int a){
 return a * a;
}

int (*squaredPointer) (int);
squaredPointer = square;
int b = square(10);
```

## void pointer can be anything. Cast it to an int:
```c
int a = *(int*)thePointer; //Casting to int pointer, then dereferencing it
```

## Sorting
```c
#include <stdlib.h>
int scores = {1,3,6,2,7,4};
int compareFun(const void* a, const void* b){
	int av = *(int*)a;
	int bv = *(int*)b;
	return bv - av;
}
qsort(scores, sizeof(int), compareFun); //inplace sorting
```

## Function array
```c
void (*functions[])(int) = {... some already defined functions ...};
(functions[2])(10); //Calling it
```

## Threads
```c
#include <pthread.h>
pthread_t thread;
if(pthread_create(&thread, NULL, startingFunction, NULL) == -1)
	//error

//Join thread
void* result;
if(pthread_join(thread, &result) == -1)
	//error
```	