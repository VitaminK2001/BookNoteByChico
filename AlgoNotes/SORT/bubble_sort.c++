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

void bubble_sort(int* arr, int n){
    for(int i = 0; i < n-1; ++i){
        int flag = 0;
        //算法一共需要重复n-1次
        for(int j = 0; j < n-1-i; ++j){
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(arr, j, j+1);
            }
        }
        //如果有一次从头到尾都不需要swap则停止
        if(flag == 0) break; 
    }
}

int main(){
    int* a = (int*) malloc(sizeof(int)*10);
    int i = 0;
    while(i < 10){
        cin >> a[i];
        i++;
    }
    cout << "排序前" << endl;
    display(a, 10);
    bubble_sort(a, 10);
    cout << "排序后" << endl;
    display(a, 10);
}