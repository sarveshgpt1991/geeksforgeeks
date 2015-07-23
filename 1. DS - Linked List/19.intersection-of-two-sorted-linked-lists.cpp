// http://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists

#include <iostream>
#include "linkedList.h"

node* sortedIntersect(node *head1, node *head2){
	node *head = NULL;
	node *ptr1 = head1;
	node *ptr2 = head2;
	while(ptr1 && ptr2){
		if(ptr1->data == ptr2->data){
			append(&head, ptr1->data);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if(ptr1->data < ptr2->data){
			ptr1 = ptr1->next;
		}
		else{
			ptr2 = ptr2->next;
		}
	}
	return head;
}

int main() {
	node* a = NULL;
  struct node* b = NULL;
  struct node *intersect = NULL;
  
  /* Let us create the first sorted linked list to test the functions
   Created linked list will be 1->2->3->4->5->6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);                                   
  
  /* Let us create the second sorted linked list 
   Created linked list will be 2->4->6->8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);                                    
  
  /* Find the intersection two linked lists */
  intersect = sortedIntersect(a, b);
  
  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect); 
	return 0;
}

