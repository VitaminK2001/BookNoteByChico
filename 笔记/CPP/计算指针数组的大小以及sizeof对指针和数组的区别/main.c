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
    const char *s = "we are the champion";
    //当sizeof用于指针的时 = 指针所占的字节数量 8
    int len = sizeof(s) / sizeof(char);
    printf("%d %d \n", sizeof(s), sizeof(char));

    int a[10];
    printf("%ld\n", sizeof(a));
    int *b = a;
    printf("%ld\n", sizeof(b));

    const char *c = "we are losers?";
    printf("%s", c);
}
