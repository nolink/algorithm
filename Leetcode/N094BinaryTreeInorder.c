/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Stack{
    struct TreeNode** elements;
    int capacity;
    int size;
};

typedef struct Stack Stack;

void stackCreate(Stack* stack, int maxSize){
    stack->elements = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*maxSize);
    stack->capacity = maxSize;
    stack->size = 0;
}

void stackPop(Stack* stack){
    (stack->elements)[stack->size - 1]=NULL;
    stack->size = stack->size - 1;
}

struct TreeNode* stackTop(Stack* stack){
   return (stack->elements)[stack->size-1]; 
}

void stackPush(Stack* stack, struct TreeNode* value){
    if(stack->size == stack->capacity){
        stack->capacity += stack->capacity;
        stack->elements = (struct TreeNode**)realloc(stack->elements, sizeof(struct TreeNode*)*(stack->capacity));
    }
    (stack->elements)[stack->size]=value;
    stack->size = stack->size + 1;
}

bool stackEmpty(Stack* stack){
    return stack->size == 0;
}

void stackDestroy(Stack* stack){
    free(stack->elements);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    *returnSize = 0;
    if(NULL == root){
        return NULL;
    }
    
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stackCreate(stack, 16);
    
    int* result = (int*)malloc(sizeof(int)*16);
    
    struct TreeNode* current = NULL;
    do{
        if(!stackEmpty(stack)){
            current = stackTop(stack);
            stackPop(stack);
        }else{
            current = root;
        }
        if(NULL == current->left && NULL == current->right){
            result[*returnSize] = current->val;
            *returnSize = *returnSize + 1;
            if(*returnSize > 16){
            	result = (int*)realloc(result, sizeof(int)*(*returnSize+16));
            }
        }else{
            if(current->right){
                stackPush(stack, current->right);
                current->right = NULL;
            }
            stackPush(stack, current);
            if(current->left){
                stackPush(stack, current->left);
                current->left = NULL;
            }
        }
    }while(!stackEmpty(stack));
    
    stackDestroy(stack);
    free(stack);
    return result;
}