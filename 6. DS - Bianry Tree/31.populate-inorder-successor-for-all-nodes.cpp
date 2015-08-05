// http://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes

#include <iostream>
using namespace std;

struct node {
	int data;
	node *left, *right, *next;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->right = n->left = n->next = NULL;
	return n;
}

void populateNext(node *root){
	if(root == NULL)
		return;
	populateNext(root->left);
	populateNext(root->right);
	node *ptr = root->left;
	while(ptr && ptr->right)
		ptr = ptr->right;
	if(ptr)
		ptr->next = root;

	ptr = root->right;
	while(ptr && ptr->left)
		ptr = ptr->left;
	root->next = ptr;
}

int main(){
	/* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(12);
    root->right->left = newNode (11);
    root->left->left  = newNode(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    struct node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }

	return 0;
}

