#include <iostream>
using namespace std;

int lowerBoundSearch(int arr[], int n, int x) {
	int lo = 0, up = n-1;
	while(lo < up){ //最后的时候是lo = up
		int mid = (lo+up)/2;
		if(x <= arr[mid]) up = mid;
		else lo = mid+1;
	}
	return lo;
}

int upperBoundSearch(int arr[], int n, int x) {
	int lo = 0, up = n-1;
	while(lo < up){
		int mid = (lo+up)/2;
		if(x < arr[mid]) up = mid; //只有小于的时候才会调整上界
		else lo = mid+1;
	}
	return lo;
}

int binarySearch(int arr[], int n, int target){
	int left = 0, right = n-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(arr[mid] == target){
			return mid;
		}
		if(arr[mid] < target){
			left = mid+1;
		}else {
			right = mid-1;
		}
	}
	return -1;
}
int main(){
	int arr[9] = {0,1,1,1,1,2,3,4,5};
	cout << binarySearch(arr, 9, 1);	
}

