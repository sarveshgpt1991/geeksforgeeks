// http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced

#include <iostream>
#include <cmath>
#include "bt.h"

bool isBalanced(node *root){
	if(root == NULL)
		return true;
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	if(abs(left-right) < 2)
		return isBalanced(root->left) && isBalanced(root->right);
	else
		return false;
}

int main(){
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");
	return 0;
}

