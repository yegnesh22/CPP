/* Backward Linked list */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node;

struct node {
	int val;
	struct node *next;
};


struct node* add_element(struct node *n, int val)
{
	struct node *first = n;
	struct node *newnode;

	newnode = (struct node *) malloc (sizeof(struct node));
	newnode->val = val;
	newnode->next = first;

	return newnode;
}

struct node* delete_element(struct node *n, int val)
{
	struct node *first = n;
	struct node *delnode;

	if (n->val == val) {
		first = n->next;
		free(n);
		return first;
	}

	while(n->next != NULL && n->next->val != val)
		n = n->next;

	if (n->next == NULL)
		return first;
	else {
		delnode = n->next;
		n->next = n->next->next;
		free(delnode);
	}
	return first;
}

void traverse_list(struct node *n)
{
	while (n != NULL) {
		printf("%d ",n->val);
		n = n->next;
	}
	printf("\n");
}

main()
{
	struct node *first = NULL;

	first = add_element(first, 1);
	traverse_list(first);
	first = add_element(first, 2);
	traverse_list(first);
	first = add_element(first, 3);
	traverse_list(first);
	first = add_element(first, 4);
	traverse_list(first);
	first = add_element(first, 5);
	traverse_list(first);

	first = delete_element(first, 1);
	traverse_list(first);
	first = delete_element(first, 4);
	traverse_list(first);
	first = delete_element(first, 5);
	traverse_list(first);
}

