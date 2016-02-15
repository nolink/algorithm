
struct Stack{
    char* elements;
    int size;
};

typedef struct Stack Stack;

void stackCreate(Stack* stack, int maxSize){
    stack->elements = (char*)malloc(sizeof(char)*maxSize);
    stack->size = 0;
}

void stackPop(Stack* stack){
    (stack->elements)[stack->size - 1]='\0';
    stack->size = stack->size - 1;
}

char stackTop(Stack* stack){
   return (stack->elements)[stack->size-1]; 
}

void stackPush(Stack* stack, char value){
    (stack->elements)[stack->size]=value;
    stack->size = stack->size + 1;
}

bool stackEmpty(Stack* stack){
    return stack->size == 0;
}

void stackDestroy(Stack* stack){
    free(stack->elements);
}

bool isValid(char* s) {
    
    if(NULL == s){
        return 1;
    }
    
    int len = strlen(s);
    
    if(len % 2 != 0){
        return 0;
    }
    
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
    stackCreate(stack, len+1);
    
    int i=0;
    
    for(;i<len;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stackPush(stack, s[i]);
        }else{
            char top = stackTop(stack);
            if((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{')){
                stackPop(stack);
            }else{
                return 0;
            }
        }
    }
    
    bool valid = stackEmpty(stack);
    stackDestroy(stack);
    free(stack);
    return valid;
    
}