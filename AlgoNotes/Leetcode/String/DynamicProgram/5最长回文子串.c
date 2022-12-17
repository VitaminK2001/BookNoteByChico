//
// Created by #Vitamink on 2022/12/15.
//
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char * longestPalindrome(char * s){
    int n = strlen(s);
    bool dp[n][n];
    int maxlen = 1;
    int begin = 0;
    for(int i = 0; i < n; ++i){
        dp[i][i] = true; //所有长度为1的字符串都是回文串
    }
    for(int l = 2; l < n; ++l){
        for(int i = 0; i < n; ++i){
            int j = i+l-1;
            if(j >= n) break;
            if(s[i] != s[j]) dp[i][j] = false;
            else {
                if(j-i < 3){
                    dp[i][j] = true;
                }else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j] && j-i+1 > maxlen){
                maxlen = j-i+1;
                begin = i;
            }
        }
    }
    char* c = (char*) malloc(sizeof(char*));
    strncpy(c, s[begin], maxlen);
    return c;
}

int main(){
    longestPalindrome("abcdcba");
}
