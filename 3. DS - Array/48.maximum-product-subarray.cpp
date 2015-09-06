// http://www.geeksforgeeks.org/maximum-product-subarray/

#include <iostream>
#include <cstdio>
using namespace std;

int maxSubarrayProduct(int *arr, int n){
    int min_prod=1, max_ending=1, max_so_far = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            max_ending = max_ending*arr[i];
            min_prod = min(min_prod*arr[i], 1);
        }
        else if(arr[i] == 0){
            max_ending = 1;
            min_prod = 1;
        }
        else {
            int tmp = max_ending;
            max_ending = max(min_prod*arr[i], 1);
            min_prod = tmp*arr[i];
        }
        if(max_so_far < max_ending)
            max_so_far = max_ending;
    }
    return max_so_far;
}

int main(){
	int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Sub array product is %d", maxSubarrayProduct(arr, n));
    getchar();
}
