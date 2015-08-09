// http://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node
/***/

#include <iostream>
#include "bt.h"

void printKDistant(node *root, int *path, bool *visited, int k, int level){
	if(root == NULL)
		return;
	path[level] = root->data;
	visited[level] = false;
	level++;
	
	if(!root->left && !root->right && level >= k+1 && visited[level-k-1] == false){
		cout<<path[level-k-1]<<" ";
		visited[level-k-1] = true;
		return;
	}
	printKDistant(root->left, path, visited, k, level);
	printKDistant(root->right, path, visited, k, level);
}

void printKDistantfromLeaf(node *root, int k){
	int path[100] = {0};
	bool visited[100] = {0};
	printKDistant(root, path, visited, k, 1);
}

int main(){
	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout << "Nodes at distance 2 are: ";
    printKDistantfromLeaf(root, 2);
	return 0;
}

