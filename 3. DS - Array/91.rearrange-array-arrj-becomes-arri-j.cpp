// http://www.geeksforgeeks.org/rearrange-array-arrj-becomes-arri-j/

#include <iostream>
#include "array.h"

void rearrangeNaive(int *a, int n){
	int help[n];
	for(int i=0; i<n; i++){
		int idx = a[i];
		help[idx] = i;
	}
	printArray(help, n);
}

int main(){
	int arr[] = {1, 3, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, n);
 
 
    printf("Modified array is \n");
    rearrangeNaive(arr,  n);
	return 0;
}

