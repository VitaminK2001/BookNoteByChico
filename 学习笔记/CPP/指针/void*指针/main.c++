#include <iostream>
using namespace std;

int main() {
    int a = 10;
    void *b;
    b = &a;
    printf("%p\n", (int*)b);
    printf("%d\n", *(int*)b); // 强制转换成int *指针才能取值 10
    
}