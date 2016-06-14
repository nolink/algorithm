

#include <stdio.h>
#include <stdlib.h>


struct linked_list{
    int val;
    struct linked_list *prev, *next;
};

typedef struct linked_list list;

list* create(int v){
	list* l = (list*)malloc(sizeof(list));
	l->val = v;
	l->prev = NULL;
	l->next = NULL;
	return l;
}

list* insert(list* origin, list* after){
	after->next = origin->next;
	if(NULL != origin->next){
		origin->next->prev = after;
	}

	origin->next = after;
	after->prev = origin;
	return after;
}

list* del_node(list* to_delete){
	if(NULL == to_delete->prev){
		list* result = to_delete->next;
		if(NULL != result){
			result->prev = NULL;
		}
		free(to_delete);
		return result;
	}else{
		list* result = to_delete->next;
		if(NULL != result){
			result->prev = to_delete->prev;
		}
		to_delete->prev->next = result;
		free(to_delete);
		return result;
	}
}

int* josephus(int n, int k){

	int i=1;
	list* head = create(i);
	list* tail = head;
	for(i=2;i<=n;i++){
		tail = insert(tail, create(i));
	}

	int left = n;
	tail = head;
	while(left > 2){
		if(head == tail){
			head = head->next;
		}
		tail = del_node(tail);
		if(NULL == tail){
			tail = head;
		}
		i = 1;
		while(i<k){
			tail = tail->next;
			if(NULL == tail){
				tail = head;
			}
			i++;
		}
		left--;
	}

	int* result = (int*)malloc(sizeof(int)*2);

	result[0] = head->val;
	result[1] = head->next->val;

	head = del_node(head);
	head = del_node(head);

	return result;

}


int main(int argc, char const *argv[])
{	
	int* result = josephus(40, 3);
	printf("%d %d\n", result[0], result[1]);
	free(result);
	return 0;
}
