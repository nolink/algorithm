
#ifndef NOLINK_STACK

#define NOLINK_STACK

typedef struct
{
	
} stack;

stack* stack_create(int);
int stack_push(stack* s, int v);
int stack_pop(stack* s);
void stack_destroy(stack* s);

#endif
