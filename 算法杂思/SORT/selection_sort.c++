#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;

void display(int* arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int* a, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void selection_sort(int* arr, int n){
    //每次选择最小的值
    for(int i = 0; i < n; ++i){
        int minV = arr[i];
        int minK = i;
        for(int j = i; j < n; ++j){
            if(arr[j] < minV){
                minV = arr[j];
                minK = j;
            }
        }
        //经过调试发现bug在于一个数字不能重复使用
        //简单的赋值是不对的必须交换两者的位置
        // printf("第%d次\n", i);
        // cout << "更新前" << arr[i] << endl;
        int tmp = arr[i];
        arr[i] = minV;
        arr[minK] = tmp;
        // cout << "更新后" << arr[i] << endl;
    }
}

int main(){
    int n = 0;
    cout << "输入数组长度: " << endl;
    cin >> n;
    int* a = (int*) malloc(sizeof(int)*n);
    int i = 0;
    cout << "输入数组元素: " << endl;
    while(i < n){
        cin >> a[i];
        i++;
    }
    cout << "排序前" << endl;
    display(a, n);
    selection_sort(a, n-1);
    cout << "排序后" << endl;
    display(a, n);
}