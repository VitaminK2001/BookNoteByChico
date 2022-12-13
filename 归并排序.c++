#include <iostream>
#include <vector>
using namespace std;
void merge(int* arr, int l, int m, int r);
void sort(int* arr, int l, int r){
	if(l < r){ //这里l不能等于r l等于r的时候没有sort的必要了
		int m = l + (r-l)/2;	
		sort(arr, l, m);
		sort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}
void merge(int* arr, int l, int m, int r){
	vector<int> v1;
	vector<int> v2;
	int i = 0, j = 0, k = l;
	for(; i < m-l+1; ++i){
		v1.push_back(arr[l+i]);
	}
	for(; j < r-m; ++j){
		v2.push_back(arr[m+1+j]);
	}
	i = 0;
	j = 0;
	while(i < m-l+1 && j < r-m){
		if(v1[i] < v2[j]){
			arr[k++] = v1[i++];	
		}else {
			arr[k++] = v2[j++];
		}
	}
	while(i < m-l+1){
		arr[k++] = v1[i++];
	}
	while(j < r-m){
		arr[k++] = v2[j++];
	}
}
int main(){
	int arr[10] = {1,2,3,6,4,5,7,9,8,10};
	sort(arr, 0, 9);
	for(int a : arr){
		cout << a << " ";
	}
}