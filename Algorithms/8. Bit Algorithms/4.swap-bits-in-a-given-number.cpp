// http://www.geeksforgeeks.org/swap-bits-in-a-given-number

#include <iostream>
using namespace std;

int swapBits(int n, int pos1, int pos2, int k){
    if(pos2 < pos1)
        swapBits(n, pos2, pos1, k);
    int a = ~0;
    a <<= k;
    a = ~a;
    int b = a;
    a <<= pos1;
    b <<= pos2;
    a = a&n;
    b = b&n;
    a >>= pos1;
    b >>= pos2;
    int left = n>>(pos2+k);
    int mid = (n>>(pos1+k))|((~0)<<(pos2 - pos1-k));
    int right = (n>>(pos1))|((~0)<<pos1);
    int res = left;
    res = (res<<k)|a;
    res = (res<<(pos2-pos1-k))&mid;
    res = (res<<k)|b;
    res = (res<<pos1)&right;
    cout<<right;
    return res;
}

int main() {
    int res =  swapBits(47, 1, 5, 3);
    printf("\nResult = %d ", res);
	return 0;
}


