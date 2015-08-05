// http://www.geeksforgeeks.org/connect-nodes-at-same-level

#include <iostream>
#include <queue>
using namespace std;

struct node {
	int data;
	node *right, *left, *next;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->left = n->right = n->next = NULL;
	return n;
}

void connect(node *root){
	if(root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	bool flag = false;
	while(true){
		node *tmp = q.front();  q.pop();
		if(tmp == NULL){
			if(flag)
				return;
			q.push(NULL);
			flag = true;
			continue;
		}
		flag = false;
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
		tmp->next = q.front();
	}
}

int main(){
	node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);

  // Populates nextRight pointer in all nodes
  connect(root);

  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->next? root->next->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->next? root->left->next->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->next? root->right->next->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->next? root->left->left->next->data: -1);
	return 0;
}

