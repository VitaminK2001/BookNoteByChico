#include <stdio.h>
#include <string.h>
int getLucky(char * s, int k){
    int n = strlen(s);
    char digits[n*2+1];
    int pos = 0;
    for(int i = 0; i < n; ++i){
        pos += sprintf(digits+pos, "%d", s[i]-'a'+1);
    }
    int len = pos;
    for(int i = 1; i <= k && len > 1; ++i){
        int sum = 0;
        for(int j = 0; j < len; ++j){
            sum += digits[j]-'0'; // 得到每一位的数字
        }
        len = sprintf(digits, "%d", sum); //如果陷入的字符数量只有一位则不能进行运算求和了
    }
    return atoi(digits);
}