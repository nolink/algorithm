

#include <stdio.h>
#include <stdlib.h>

struct doubly_linked_list
{
	int val;
	struct doubly_linked_list* prev;
	struct doubly_linked_list* next;
};

typedef struct doubly_linked_list d_link;

d_link* create(){
	d_link* link = (d_link*)malloc(sizeof(d_link));
	link->val = 0;
	link->prev=NULL;
	link->next=NULL;
	return link;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}

