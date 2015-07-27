// http://www.geeksforgeeks.org/maximum-product-subarray/

#include <iostream>
#include <algorithm>
#include "array.h"

int maxSubProduct(int *a, int start, int end){
	int productHere=1, maxProduct = 0, after=1;
	
	for(int i=start; i<=end; i++){
		if(a[i] < 0){
			maxProduct = max(maxProduct, after);
			after = 1;
		}
		else {
			after *= a[i];
		}
		productHere *= a[i];
		maxProduct = max(maxProduct, productHere);
	}
	maxProduct = max(maxProduct, after);
	return maxProduct;
}

int maxSubarrayProduct(int *a, int n){
	int start = -1;
	int m = -1;
	int i=0;
	while(a[i]==0){
		start = i;
		i++;
	}
	start++;
	for(; i<n; i++){
		if(a[i]==0){
			m = max(m, maxSubProduct(a, start, i-1));
			start = i+1;
		}
	}
	//cout<<"@"<<start<<" "<<i<<" "<<maxSubProduct(a, start, i-1);
	m = max(m, maxSubProduct(a, start, i-1));
	return m;
}

int main(){
    int arr[] = {-2, -3, 0, -2, -40};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Sub array product is %d", maxSubarrayProduct(arr, n));
    return 0;
}
