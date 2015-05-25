// http://geeksquiz.com/quick-sort/
#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

void printArray(int a[], int start, int end) {
	for (int i=start; i<=end; i++) {
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

int partition(int *arr, int start, int end) {
	int piv = arr[end];
	int j = start-1;
	for (int i = start; i < end; ++i) {
		if(arr[i] <= piv) {
			j++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[j+1], &arr[end]);
	return j+1;
}

void quickSort(int *arr, int start, int end) {
	if(end <= start)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p-1);
	quickSort(arr, p+1, end);
}

int main(){
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	quickSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}