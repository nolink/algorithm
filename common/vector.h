
#ifndef NOLINK_VECTOR

#define NOLINK_VECTOR

typedef struct 
{
	
} vector;

vector* vector_create(int);
int vector_add(vector* v, int val);
void vector_destroy(vector* v);

#endif