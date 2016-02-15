typedef struct {
    int* elements;
    int size;
    int* mins;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->elements=(int*)malloc(sizeof(int)*maxSize);
    stack->mins=(int*)malloc(sizeof(int)*(maxSize));
    stack->size=0;
}

void minStackPush(MinStack *stack, int element) {
    if(stack->size == 0){
        (stack->mins)[0] = 0;
    }
    else{
        int current_min = (stack->mins)[(stack->size) - 1];
        if(element < (stack->elements)[current_min]){
            (stack->mins)[stack->size]=stack->size;
        }else{
            (stack->mins)[stack->size]=current_min;
        }
    }
    (stack->elements)[stack->size] = element;
    stack->size = stack->size + 1;
}

void minStackPop(MinStack *stack) {
    (stack->mins)[(stack->size) - 1] = 0;
    (stack->elements)[(stack->size) - 1] = 0;
    stack->size = (stack->size) - 1;
}

int minStackTop(MinStack *stack) {
    return (stack->elements)[(stack->size) - 1];
}

int minStackGetMin(MinStack *stack) {
    return (stack->elements)[(stack->mins)[(stack->size)-1]];
}

void minStackDestroy(MinStack *stack) {
    free(stack->elements);
    free(stack->mins);
}