



#include <stdio.h>
#include <stdlib.h>


struct sVertex
{
	int val;
	int color;
	int nexts_count;
	struct sVertex** nexts;
};

typedef struct sVertex vertex;

typedef struct
{
	int size;
	int capacity;
	int idx;
	vertex** vals;
} queue;

queue* create_q(int capacity){
	queue* q = (queue*)malloc(sizeof(queue));

	q->size = 0;
	q->idx = 0;
	q->capacity = capacity;
	q->vals = (vertex**)malloc(sizeof(vertex*)*capacity);

	return q;
}

void push(queue* q, vertex* v){
	q->vals[q->size] = v;
	(q->size)++;
}

vertex* pop(queue* q){
	vertex* v = q->vals[q->idx];
	//(q->size)--;
	(q->idx)++;
	return v;
}

int empty(queue* q){
	return q->size == q->idx;
}

vertex* create(int val){
	vertex* v = (vertex*)malloc(sizeof(vertex));
	v->val = val;
	v->color = 0;
	v->nexts_count = 0;
	v->nexts = NULL;

	return v;
}

void destroy(vertex* v){

	if(NULL == v){
		return;
	}

	free(v->nexts);
	free(v);
	v->nexts = NULL;
	v = NULL;
}

//using queue
void breadth_first(vertex* v){

	queue* q = create_q(16);

	push(q, v);

	int i=0;

	while(!empty(q)){
		vertex* ver = pop(q);
		if(ver->color == 0){
			ver->color = 1;
			printf("%d\n", ver->val);
			if(ver->nexts_count > 0){
				for(i=0;i<ver->nexts_count;i++){
					if((ver->nexts[i])->color == 0){
						push(q, ver->nexts[i]);
					}
				}
			}
			ver->color = 2;
		}
	}
}


int main(int argc, char const *argv[])
{

	vertex* v0 = create(0);
	vertex* v1 = create(1);
	vertex* v2 = create(2);
	vertex* v3 = create(3);
	vertex* v4 = create(4);

	v0->nexts_count = 2;
	v0->nexts = (vertex**)malloc(sizeof(vertex*)*2);
	v0->nexts[0] = v1;
	v0->nexts[1] = v4;

	v2->nexts_count = 2;
	v2->nexts = (vertex**)malloc(sizeof(vertex*)*2);
	v2->nexts[0] = v0;
	v2->nexts[1] = v3;

	v3->nexts_count = 2;
	v3->nexts = (vertex**)malloc(sizeof(vertex*)*2);
	v3->nexts[0] = v2;
	v3->nexts[1] = v4;

	v4->nexts_count = 1;
	v4->nexts = (vertex**)malloc(sizeof(vertex*)*1);
	v4->nexts[0] = v0;
	
	breadth_first(v3);

	destroy(v0);
	destroy(v1);
	destroy(v2);
	destroy(v3);
	destroy(v4);

	return 0;
}