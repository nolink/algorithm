

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

void deep_first(vertex* v){

	if(v->color == 0){
		v->color = 1;
		printf("%d\n", v->val);
		if(v->nexts_count > 0){
			int i=0;
			for(;i<v->nexts_count;i++){
				deep_first(v->nexts[i]);
			}
		}
		v->color = 2;
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
	
	deep_first(v3);

	destroy(v0);
	destroy(v1);
	destroy(v2);
	destroy(v3);
	destroy(v4);

	return 0;
}