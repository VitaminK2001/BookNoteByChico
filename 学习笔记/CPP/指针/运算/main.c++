#include <iostream>
#include <vector>
using namespace std;

int main() {
    /**
     * @brief 
     * char型数组
     */
    char ac[] = {0,1,2,3,4,5};
    char *p = ac;
    char *p1 = &ac[5];
    printf("p     = %p\n", p);
    printf("p + 1 = %p\n", p+1);
    printf("p1 - p = %d\n", p1-p);

    /**
     * @brief 
     * int型数组
     */
    int ai[] = {0,1,2,3,4,5};
    int *q = ai;
    int *q1 = &ai[4];
    printf("q     = %p\n", q);
    printf("q + 1 = %p\n", q+1);
    printf("q1 - q = %d\n", q1-q);
    /**
     * p     = 0x7ff7bee791da
     * p + 1 = 0x7ff7bee791db
     * p1 - p = 5
     * q     = 0x7ff7bee791e0
     * q + 1 = 0x7ff7bee791e4
     * q1 - q = 4
     * 
     * 
     * 给指针加1表示要指针指向下一个变量
     * 如果指针指向的不是一片连续的空间，则加1是没有意义的
     * 两个指针相减，告诉两个地址之间有多少个元素存在
     * *p++表示取出p所指向的那个数据，之后将p移动到下一个元素的位置
     * ++的优先级确实比*高，但是p++是p+1之前的值
     * 
     */

    printf("%p", NULL); //0x0 NULL是一个预定义的符号 表示0地址 0地址通常是不能随便碰的地址 表示特殊含义
    
}
