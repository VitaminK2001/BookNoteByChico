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
void quicksort(int* arr, int l, int r){
    if(l < r){ //注意l要在小于r的时候才有必要排序 l == r 时就是一个元素，没有必要排序
        int j = r, i = l;
        int key = arr[i];
        while(i < j){
            while(j > i && arr[j] > key){
                --j;
            }
            arr[i] = arr[j];
            while(i < j && arr[i] < key){
                ++i;
            }
            arr[j] = arr[i];
        }
        arr[i] = key;
        quicksort(arr, l, i-1);
        quicksort(arr, i+1, r);
    }
}

void quick_sort(int* arr, int n){
    quicksort(arr, 0, n-1);
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
    quick_sort(a, n);
    cout << "排序后" << endl;
    display(a, n);
}
