// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list

#include<iostream>
#include "linkedList.h"

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void pairWiseSwap(node *head){
	if(head == NULL || head->next == NULL)
		return;
	node *prev = head;
	node *ptr = head->next;
	swap(&prev->data, &ptr->data);
	pairWiseSwap(head->next->next);
}

int main(){
	 node *start = NULL;
 
  /* The constructed linked list is:
   1->2->3->4->5 */
  push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);
 
  printf("\n Linked list before calling  pairWiseSwap() ");
  printList(start);
 
  pairWiseSwap(start);
 
  printf("\n Linked list after calling  pairWiseSwap() ");
  printList(start);
  return 0;
}

