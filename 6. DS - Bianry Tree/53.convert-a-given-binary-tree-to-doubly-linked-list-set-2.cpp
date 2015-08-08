// http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2

#include <iostream>
#include "bt.h"

void fixPrevPtr(node *root) {
	static node *pre = NULL;
	if(root){
		fixPrevPtr(root->left);
		root->left = pre;
		pre = root;
		fixPrevPtr(root->right);
	}
}

node* fixNextPtr(node *root){
	static node *prev = NULL;
	while(root && root->right){
		root = root->right;
	}
	while(root && root->left){
		prev = root;
		root = root->left;
		root->right = prev;
	}
	return root;
}

node *BTToDLL(node *root){
	if(root == NULL)
		return NULL;
	fixPrevPtr(root);
	fixNextPtr(root);
}

void printList(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->right;
	}
}

int main(){	
	node *root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    printf("\n\t\tInorder Tree Traversal\n\n");
   printInorder(root);
 
    struct node *head = BTToDLL(root);
 
    printf("\n\n\t\tDLL Traversal\n\n");
    printList(head);
}
