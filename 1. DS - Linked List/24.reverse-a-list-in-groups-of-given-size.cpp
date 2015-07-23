// http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

#include <iostream>
#include "linkedList.h"

void reverse(node **head, int start, int end){
	if(*head == NULL)
		return;
	// includes head
	if(start == 1) {
		node *prev = *head;
		node *current = (*head)->next;
		node *ptr = (*head)->next->next;
		while(end>1){
			current->next = prev;
			prev = current;
			current = ptr;
			ptr = ptr->next;
			end--;
		}
		(*head)->next = current;
		*head = prev;
	}
	if(start>2)
		reverse(head, start-1, end-1);

	//next to head
	else {
		node *nextHead = (*head)->next;
		node *prev = nextHead;
		node *current = nextHead->next;
		node *ptr = nextHead->next->next;
		while(end>2){
			current->next = prev;
			prev = current;
			current = ptr;
			ptr = ptr->next;
			end--;
		}
		(*head)->next = prev;
		nextHead->next = current;
	}
}

int main(){
	node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8 */
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\n Given linked list \n");
     printList(head);
     reverse(&head, 2, 4);
 
     printf("\n Reversed Linked list \n");
     printList(head);
	return 0;
}

