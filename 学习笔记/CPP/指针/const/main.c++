#include <iostream>
using namespace std;

int main() {
    // const 在*前面，表示不能通过指针改变值
    const int *p = nullptr; // => int const *p = nullptr;
    int a[] = {1,2,3,4};
    p = a;
    printf("%d\n", *p); // 1
    *p++; // ++的优先级比*高 先移动p再取值
    printf("%d\n", *p); // 2

    // 下面代码报错 表达式必须是可修改的左值C/C++(137)
    // (*p)++;

    // 但是可以改变指针的指向
    int i = 10;
    p = &i;
    printf("%d\n", *p); // 10


    // const 在*后面，表示指针不能改变
    int b[] = {1,2,3};
    int * const q = b; 
    int c[] = {4,5};
    // 下面代码报错 表达式必须是可修改的左值C/C++(137)
    // q = c;

    // 但是可以通过指针改变值
    (*q)++;
    printf("%d\n", b[0]); // 2
}