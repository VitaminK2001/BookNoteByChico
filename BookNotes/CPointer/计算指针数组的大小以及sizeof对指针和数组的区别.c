//
// Created by #Vitamink on 2022/12/15.
//
#include <stdio.h>
#include <string.h>
int arrlen(char* s){
    int len = 0;
    while(*s){ //直到*s是空字符
        s++;
        len++;
    }
    return len;
}

int main(){
    char* s = "we are the champion";
    int len = arrlen(s);
    printf("%d", len);

    int a[10];
    printf("\n%ld\n", sizeof(a));
    int *b = a;
    printf("%ld\n", sizeof(b));
}
