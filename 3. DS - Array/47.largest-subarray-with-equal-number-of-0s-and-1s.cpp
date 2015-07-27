// http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

#include <iostream>
#include "array.h"

void findSubArray(int *a, int n){
	int leftSum[n];
	int sum=0;
	int k=0, l=-1;
	int max = -1;
	for(int i=0; i<n; i++){
		if(a[i]){
			sum++;
		}
		else{
			sum--;
		}
		leftSum[i] = sum;
	}
	printArray(leftSum, n);
	int i=n-1;
	while(i>=0){
		if(leftSum[i]==0){
			l=i;
			max = l-k+1;
			break;
		}
		i--;
	}
	i=0;
	int j=n-1;
	while(i <= j && j-i+1 > max){
		if(leftSum[i]==leftSum[j]){
			if(j-(i+1)+1 > max){
				max = j-(i+1)-1;
				k = (i+1);
				l = j;
			}
			cout<<k<<" to "<<l;
			return;
		}
	}
	cout<<k<<" to "<<l;
	return;
}

int main(){
    int arr[] =  {1, 0, 1, 1, 1, 0, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    findSubArray(arr, size);
}
