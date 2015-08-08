// http://www.geeksforgeeks.org/find-distance-two-given-nodes/

#include <iostream>
#include "bt.h"

bool findPath(node *root, vector<int> &path, int k){
	if(root == NULL)
		return false;
	path.push_back(root->data);
	if(root->data == k)
		return true;
	if(root->left && findPath(root->left, path, k) || root->right && findPath(root->right, path, k))
		return true;
	path.pop_back();
	return false;
}

int findDistance(node *root, int k1, int k2){
	if(root == NULL)
		return -1;
	vector<int> path1, path2;
	findPath(root, path1, k1);
	findPath(root, path2, k2);
	int i=0;
	for(; i<path1.size() && i<path2.size(); i++){
		if(path1[i] != path2[i])
			break;
	}
	return path1.size()-i + path2.size()-i;
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
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
	return 0;
}

