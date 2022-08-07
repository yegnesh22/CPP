#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define is_char(a) (((a >= 'A') && (a <= 'Z')) || \
			((a >= 'a') && (a <= 'z')))

struct node;

struct node {
	int position;
	struct node* next;
};

struct node* insert_node(struct node* first, unsigned char position)
{
	struct node* newnode;

	newnode = (struct node*) malloc (sizeof(struct node));
	newnode->position = position;
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

void print_letter_positions(struct node *list_start, unsigned char ch)
{
	if (list_start == NULL)
		return;

	printf("%c occurs at : ", ch);
	while (list_start != NULL) {
		printf("%d, ", list_start->position);
		list_start = list_start->next;
	}
	printf("\n");

	return;
}

main()
{
	char str[128]= {0};
	int i = 0, length, list_index;
	struct node* list[64] = {NULL};

	scanf("%[^\n]", str);
	length = strlen(str);

	for (i = 0; i < length; i++) {
		if (is_char(str[i])) {
			list_index = str[i] % 64 - 1;
			list[list_index] = insert_node(list[list_index],
							i+1);
			//printf("char:%c index:%d\n", str[i], str[i] % 64);
		}
	}

	for (i = 0; i < 64; i++)
		print_letter_positions(list[i], 'A' + i);
}

