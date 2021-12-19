#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node;

struct node {
	int element;
	struct node* link;
};

void push_back(struct node** head, struct node** last, int element)
{
	struct node* newnode = (struct node *)malloc(sizeof(struct node));

	newnode->element = element;
	newnode->link = NULL;
	if (*head == NULL) {
		*head = newnode;
		*last = newnode;
	} else {
		(*last)->link = newnode;
		*last = newnode;
	}
}

void print_list(struct node* head, struct node* last)
{
	struct node* ptr = head;

	while (ptr != NULL) {
		printf("%d\t", ptr->element);
		ptr = ptr->link;
	}
	printf("\n");
}

int list_size(struct node* head)
{
	struct node* ptr = head;
	unsigned int index = 0;

	while (ptr != NULL) {
		index++;
		ptr = ptr->link;
	}

	return index;
}

int main()
{
	struct node* head = NULL;
	struct node* last = NULL;
	struct node* iptr;
	int reverse_index;
	struct node* ptr;
	int i;

	for (i = 1; i <= 10; i++)
		push_back(&head, &last, i);

	print_list(head, last);
	printf("Enter reverse index: ");
	scanf("%d", &reverse_index);
	if ( (reverse_index < 0) || (reverse_index > list_size(head)) ) {
		printf("List too short!!\n");
		exit(0);
	}

	ptr = head;
	iptr = head;
	while (ptr != NULL) {
		if (reverse_index >= 0)
			reverse_index-- ;
		else
			iptr = iptr->link ;
		ptr = ptr->link ;
	}
	printf("Element : %d\n", iptr->element);
}
