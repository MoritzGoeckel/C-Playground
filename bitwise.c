#include <stdio.h>
#include <limits.h>

typedef unsigned short int NUM;

void outputBitwise(int num){
    int size = sizeof(short);
    int maxPow = 1u << (size * 8 - 1); //Todo: Why?
    while(maxPow){
        printf("%u ", num & maxPow ? 1 : 0); //Todo: Why?
        maxPow >>= 1;
    }

    printf("-> %u\r\n", num);
}

int main(){
    puts("Bitwise test");

    NUM max = USHRT_MAX;

    //outputBitwise(5);
    outputBitwise(4);
    outputBitwise(5);

    outputBitwise(max);

    printf("\r\n");
    printf("AND &\r\n");
    outputBitwise(4&5);

    printf("OR |\r\n");
    outputBitwise(4|5);

    printf("XOR ^\r\n");
    outputBitwise(4^5);

    printf("NOT ~\r\n");
    outputBitwise(~4);

    printf("Shift <<\r\n");
    outputBitwise(1 << 8);
    outputBitwise(max << 8);

    return 0;
}
