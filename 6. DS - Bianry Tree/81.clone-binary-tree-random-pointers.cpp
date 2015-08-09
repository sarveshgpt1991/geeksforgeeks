// http://www.geeksforgeeks.org/clone-binary-tree-random-pointers

#include <iostream>
#include <climits>
using namespace std;

struct node {
    int data;
    struct node* left, *right, *random;
};
 
/* Helper function that allocates a new Node with the
   given data and NULL left, right and random pointers. */
node* newNode(int key){
    node* temp = new node;
    temp->key = key;
    temp->random = temp->right = temp->left = NULL;
    return (temp);
}
 
/* Given a binary tree, print its Nodes in inorder*/
void printInorder(node* node) {
    if (node == NULL)
        return;
 
    /* First recur on left sutree */
    printInorder(node->left);
 
    /* then print data of Node and its random */
    cout << "[" << node->key << " ";
    if (node->random == NULL)
        cout << "NULL], ";
    else
        cout << node->random->key << "], ";
 
    /* now recur on right subtree */
    printInorder(node->right);
}

node *cloneTree(node *root){
	if(root == NULL)
		return;
}

int main(){
	//Test No 1
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;
 
    //  Test No 2
    //    tree = NULL;
 
    //  Test No 3
    //    tree = newNode(1);
 
    //  Test No 4
    /*    tree = newNode(1);
        tree->left = newNode(2);
        tree->right = newNode(3);
        tree->random = tree->right;
        tree->left->random = tree;
    */
 
    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);
 
    Node *clone = cloneTree(tree);
 
    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);
}