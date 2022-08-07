#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node;
struct node {
	int val;
	struct node *next;
};

struct node* insert_node(struct node* first, int val)
{
	struct node* newnode;

	newnode = (struct node*) malloc (sizeof(struct node));
	newnode->val = val;
	newnode->next = NULL;

	if (first == NULL) {
		first = newnode;
	} else {
		struct node* curnode;
		curnode = first;
		while (curnode->next != NULL)
			curnode = curnode->next;
		curnode->next = newnode;
	}

	return first;
}

void print_list(struct node *list)
{
	while (list != NULL) {
		if (list->next != NULL)
			printf("%d -->", list->val);
		else
			printf("%d\n", list->val);
		list = list->next;
	}
	return;
}

struct node* reverse_list(struct node* first)
{
	struct node* temp;
	struct node* temp1;
	struct node* temp2;

	temp = first;
	/* Empty list */
	if (first != NULL)
		temp1 = temp->next;
	else
		return NULL;

	/* Only one element in the list */
	if (temp1 != NULL)
		temp2 = temp1->next;
	else
		return temp;

	while(temp1) {
		temp1->next = temp;
		temp = temp1;
		temp1 = temp2;
		if (temp2 != NULL)
			temp2 = temp2->next;
	}

	first->next = NULL;

	return temp;
}

main()
{
	struct node *list = NULL;
	int count, i, val;
	
	printf("Enter number of elements in the list: ");
	scanf("%d", &count);
	for(i = 0; i < count; i++) {
		scanf("%d", &val);
		list = insert_node(list, val);
	}
	printf("List before reversal: ");
	print_list(list);
	printf("List after reversal: ");
	list = reverse_list(list);
	print_list(list);
}
