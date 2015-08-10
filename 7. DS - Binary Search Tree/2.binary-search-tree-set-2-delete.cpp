// http://geeksquiz.com/binary-search-tree-set-2-delete

#include <iostream>
#include "bst.h"

node *deleteNode(node *root, int data){
	 if(root == NULL)
	     return NULL;
	 if(root->data == data){
	     node *tmp = root->left;
	     node *pre = root;
		 while(tmp && tmp->right){
             pre = tmp;
		     tmp = tmp->right;		
		 }
		 if(tmp){
		     root->data = tmp->data;
		     if(pre == root)
		         pre->left = NULL;
   			 else
   			 	 pre->right = NULL;
		     delete(tmp);
		     return root;
		 }
		 tmp = root->right;
		 while(tmp && tmp->left){
   		     pre = tmp;
		     tmp = tmp->left;		
		 }
		 if(tmp){
		     root->data = tmp->data;
		     if(pre == root)
		         pre->right = NULL;
   			 else
   			 	 pre->left = NULL;
		     delete(tmp);
		     return root;
		 }
		 delete(root);
		 return NULL;
     }
     else if(root->data > data){
	 	  root->left = deleteNode(root->left, data);
     }
     else
     	 root->right = deleteNode(root->right, data);
 	 return root;
}

int main(){
	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder traversal of the given tree \n");
    printInorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    printInorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    printInorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    printInorder(root);
    getchar();
}
