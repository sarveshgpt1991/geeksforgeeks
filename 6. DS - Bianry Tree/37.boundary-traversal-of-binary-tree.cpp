// http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree

#include <iostream>
#include <queue>
#include "bt.h"

void printLeftWall(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	printLeftWall(root->left);
}

void printLeafNode(node *root, bool left, bool right){
	if(root == NULL)
		return;
	if(!root->left && !root->right && !left && !right)
		cout<<root->data<<" ";
	printLeafNode(root->left, left, false);
	printLeafNode(root->right, false, right);
}

void printRightWall(node *root){
	if(root == NULL)
		return;
	printRightWall(root->right);
	cout<<root->data<<" ";
}
void printBoundary(node *root){
	if(root == NULL)
		return;
	printLeftWall(root);
	printLeafNode(root, true, true);
	printRightWall(root);
}

int main(){
	// Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printBoundary( root );
	return 0;
}

