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

void merge(int* arr, int l, int m, int r){
    int* a1 = (int*)malloc(sizeof(int)*(m-l+1));
    int* a2 = (int*)malloc(sizeof(int)*(r-m));
    int i = 0, j = 0, k = l;
    while(i < m-l+1){
        a1[i] = arr[l+i];
        ++i;
    }
    while(j < r-m){
        a2[j] = arr[m+1+j];
        ++j;
    }
    i = 0;
    j = 0;
    while(i < m-l+1 && j < r-m){
        if(a1[i] < a2[j]){
            arr[k++] = a1[i++];
        }else {
            arr[k++] = a2[j++];
        }
    }
    while(i < m-l+1){
        arr[k++] = a1[i++];
    }
    while(j < r-m){
        arr[k++] = a2[j++];
    }
    cout << "当前" << l << "排序结果" << endl;
    for(int i = l; i <= r; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int* arr, int l, int r){
    if(l < r){
        //分到数组中只有一个元素为止
        int m = (l+r)/2;
        sort(arr, l, m);
        sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge_sort(int* arr, int n){
    sort(arr, 0, n-1);
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
    merge_sort(a, n);
    cout << "排序后" << endl;
    display(a, n);
}