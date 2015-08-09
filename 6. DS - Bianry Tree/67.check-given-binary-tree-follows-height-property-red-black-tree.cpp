// http://www.geeksforgeeks.org/check-given-binary-tree-follows-height-property-red-black-tree

#include <iostream>
#include "bt.h"

void isBalancedRec(node *root, int *Min, int *Max, int level){
	if(root == NULL)
		return;
	level++;
	if(root->left && root->right){
		(*Min)++;
		(*Max)++;
	}
	else if(root->left || root->right){
		(*Max)++;
	}
	isBalancedRec(root->left, Min, Max, level);
	isBalancedRec(root->right, Min, Max, level);
}

bool isBalanced(node *root){
	int Min = 0;
	int Max = 0;
	isBalancedRec(root, &Min, &Max, 0);
	cout<<Min<<" "<<Max<<'\n';
	return (2*Min >= Max);
}

int main(){
	node * root = newNode(10);
    //root->left = newNode(5);
    root->right = newNode(100);
    root->right->left = newNode(50);
    root->right->right = newNode(150);
    root->right->left->left = newNode(40);
    isBalanced(root)? cout << "Balanced" : cout << "Not Balanced";
	return 0;
}

