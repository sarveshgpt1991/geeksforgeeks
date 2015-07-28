// http://www.geeksforgeeks.org/tug-of-war/

#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include "array.h"

void printBool(bool *a, int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<'\n';
}

int check(int *a, int n, bool *taken){
	int sum0=0, sum1=0;
	for(int i=0; i<n; i++){
		if(taken[i])
			sum0 += a[i];
		else
			sum1 += a[i];
	}
	return abs(sum0-sum1);
}

void tugOfWarUtil(int *a, int n, bool *taken, int curr_idx, int &countTaken, int &mini, bool *res){
	if(curr_idx >= n || countTaken > (n+1)/2)
		return;
	if(countTaken == (n+1)/2){
		cout<<"@";
		int tmp = check(a, n, taken);
		printBool(res, n);
		printBool(taken, n);
		cout<<tmp;
		if(mini > tmp){
			mini = tmp;
			for(int i=0; i<n; i++)
				res[i] = taken[i];
		}
	}
	else
	for(int i=0; i<2; i++){
		taken[curr_idx] = i;
		countTaken += i;
		tugOfWarUtil(a, n, taken, curr_idx+1, countTaken, mini, res);
	}
}

void tugOfWar(int *a, int n){
	bool taken[n], result[n];
	memset(taken, false, sizeof(a));
	memset(result, false, sizeof(result));
	int countTaken = 0;
	int mini = INT_MAX;
	tugOfWarUtil(a, n, taken, 0, countTaken, mini, result);
	//printBool(result, n);
	cout<<mini;
}

int main(){
	int arr[] = {23, -34, 12, 0, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
	return 0;
}

