// http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

#include <iostream>
#include "bt.h"

void convertTree(node *root){
	if(root == NULL || (!root->left && !root->right))
		return;
	convertTree(root->left);
	convertTree(root->right);
	int sum = 0;
	if(root->left)
		sum += root->left->data;
	if(root->right)
		sum += root->right->data;
	if(sum > root->data)
		root->data = sum;
	else {
		if(root->left){
			root->left->data += root->data - sum;
			convertTree(root->left);
		}
		else {
			root->right->data += root->data - sum;
			convertTree(root->right);
		}
	}
}

int main(){
	node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
	return 0;
}

