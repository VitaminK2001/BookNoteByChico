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

void insertion_sort(int* a, int n){
    //打牌时理牌
    //第一张牌默认排好序，后面的牌按照大小插入到排好序的牌中
    for(int i = 1; i < n; ++i){
        int j = i;
        int cur = a[j];
        while(j >= 1 && a[j-1] > cur){
            a[j] = a[j-1];
            j--;
        }
        //当a[j-1]<cur时 a[j-1]后面就是cur
        a[j] = cur;
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
    insertion_sort(a, n);
    cout << "排序后" << endl;
    display(a, n);
}