// Header for Binary Tree

#include <iostream>
using namespace std;

struct node {
	int data;
	node *right, *left;
};

void printArray(int *arr, int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<'\n';
}

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->right = NULL;
	n->left = NULL;
	return n;
}

void printPreorder(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(node *root){
	if(root == NULL)
		return;
	printInorder(root->left);
	cout<<root->data;
	printInorder(root->right);
}

void printPostorder(node *root){
	if(root == NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data;
}

int maxDepth(node *root){
	if(root == NULL)
		return 0;
	return 1+ max(maxDepth(root->left), maxDepth(root->right));
}
