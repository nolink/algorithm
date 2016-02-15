

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct RBNode{
    bool isBlack;
    int key;
    int value;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
};

struct RBTree{
  struct RBNode* root;             
  struct RBNode* nil;              
};

typedef struct RBNode RBNode;
typedef struct RBTree RBTree;

struct Stack{
    RBNode** elements;
    int capacity;
    int size;
};

typedef struct Stack Stack;

void stackCreate(Stack* stack, int maxSize){
    stack->elements = (RBNode**)malloc(sizeof(RBNode*)*maxSize);
    stack->capacity = maxSize;
    stack->size = 0;
}

void stackPop(Stack* stack){
    (stack->elements)[stack->size - 1]=NULL;
    stack->size = stack->size - 1;
}

RBNode* stackTop(Stack* stack){
   return (stack->elements)[stack->size-1]; 
}

void stackPush(Stack* stack, RBNode* value){
    if(stack->size == stack->capacity){
        stack->capacity += stack->capacity;
        stack->elements = (RBNode**)realloc(stack->elements, sizeof(RBNode*)*(stack->capacity));
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

char** preorderTraversal(RBTree* tree, int* returnSize) {
    
    *returnSize = 0;
    if(NULL == tree){
        return NULL;
    }
    
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stackCreate(stack, 16);
    
    char** result = (char**)malloc(sizeof(char*)*16);
    
    RBNode* current = tree->nil;
    do{
        if(!stackEmpty(stack)){
            current = stackTop(stack);
            stackPop(stack);
        }else{
            current = tree->root;
        }
        result[*returnSize] = (char*)malloc(100);
        sprintf(result[*returnSize], "%d-%d", current->key, current->isBlack);
        *returnSize = *returnSize + 1;
        if(*returnSize > 16){
          result = (char**)realloc(result, sizeof(char*)*(*returnSize+16));
        }
        if(current->right != tree->nil){
            stackPush(stack, current->right);
        }
        if(current->left != tree->nil){
            stackPush(stack, current->left);
        }
    }while(!stackEmpty(stack));
    
    stackDestroy(stack);
    free(stack);
    return result;
}

void leftRotate(RBTree* tree, RBNode* down){

  RBNode* up = down->right;

  if(down->parent != tree->nil){
    if(down == down->parent->left){
      down->parent->left = up;
    }else{
      down->parent->right = up;
    }
  }

  up->parent = down->parent;
  if(down->parent == tree->nil){
    tree->root = up;
  }
  down->parent = up;

  down->right = up->left;
  if(up->left != tree->nil){
    up->left->parent = down;  
  }

  up->left = down;
}

void rightRotate(RBTree* tree, RBNode* down){
  RBNode* up = down->left;

  if(down->parent != tree->nil){
    if(down == down->parent->left){
      down->parent->left = up;
    }else{
      down->parent->right = up;
    }
  }

  up->parent = down->parent;
  if(down->parent == tree->nil){
    tree->root = up;
  }
  down->parent = up;

  down->left = up->right;
  if(up->right != tree->nil){
    up->right->parent = down;  
  }

  up->right = down;
}

RBTree* RBCreate(){
  RBTree* tree = (RBTree*)malloc(sizeof(RBTree));

  tree->nil = tree->root = (RBNode*)malloc(sizeof(RBNode));

  tree->nil->left = tree->nil->right = tree->nil->parent = NULL;

  tree->nil->key = tree->nil->value = 0;

  tree->nil->isBlack = true;

  tree->root->left = tree->root->right = tree->root->parent = NULL;

  tree->root->key = tree->root->value = 0;

  tree->root->isBlack = true;

  return tree;
}

void RBDestroy(RBTree* tree){

  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stackCreate(stack, 16);

  RBNode* current = tree->nil;
  do{
    if(!stackEmpty(stack)){
        current = stackTop(stack);
        stackPop(stack);
    }else{
        current = tree->root;
    }
    if(current->right != tree->nil){
        stackPush(stack, current->right);
    }
    if(current->left != tree->nil){
        stackPush(stack, current->left);
    }
    free(current);
  }while(!stackEmpty(stack));
  
  stackDestroy(stack);
  free(stack);

  free(tree->root);
  free(tree->nil);
  free(tree);
}

void RBInsert(RBTree* tree, int key, int value){
  RBNode* node = (RBNode*)malloc(sizeof(RBNode));
  node->isBlack = false;
  node->key = key;
  node->value = value;
  node->left = tree->nil;
  node->right = tree->nil;
  node->parent = tree->nil;

  if(tree->root == tree->nil){
    node->isBlack = true;
    tree->root = node;
    return;
  }

  //O(lgn)
  RBNode* current = tree->root;
  while(current != tree->nil){
    if(key < current->key){
      if(tree->nil == current->left){
        current->left = node;
        node->parent = current;
        break;
      }else{
        current = current->left;
      }
    }else{
      if(tree->nil == current->right){
        current->right = node;
        node->parent = current;
        break;
      }else{
        current = current->right;
      }
    }
  }

  if(node->parent->isBlack){
    return;
  }

  RBNode* grandParent = tree->nil;
  RBNode* parent = tree->nil;
  RBNode* uncle = tree->nil;
  while(node->parent != tree->nil){

    grandParent = node->parent->parent;
    parent = node->parent;
    uncle = parent == grandParent->left ? grandParent->right : grandParent->left;

    if(parent->isBlack){
      return;
    }else{
      if(!uncle->isBlack){
        parent->isBlack = true;
        uncle->isBlack = true;
        grandParent->isBlack = false;
        node = grandParent;
      }else{
        if(node == parent->right && parent == grandParent->left){
          leftRotate(tree, node->parent);
          node = node->left;
        }else if(node == parent->left && parent == grandParent->right){
          rightRotate(tree, node->parent);
          node = node->right;
        }else if(node == parent->left && parent == grandParent->left){
          parent->isBlack = true;
          grandParent->isBlack = false;
          rightRotate(tree, grandParent);
        }else{
          parent->isBlack = true;
          grandParent->isBlack = false;
          leftRotate(tree, grandParent);
        }
      }
    }
    
  }

  tree->root->isBlack = true;
}

void replace_node(RBTree* tree, RBNode* toBeReplaced, RBNode* toReplace){
  toReplace->parent = toBeReplaced->parent;
  if(toBeReplaced->parent != tree->nil){
    if(toBeReplaced == toBeReplaced->parent->left){
      toBeReplaced->parent->left = toReplace;
    }else{
      toBeReplaced->parent->right = toReplace;
    }
  }
}

void RBDeleteNode(RBTree* tree, RBNode* node){

  RBNode* child = node->left == tree->nil ? node->right : node->left;

  //node is root, and have no child at all
  if(child == tree->nil && node->isBlack){
    free(node);
    tree->root = tree->nil;
    return;
  }

  replace_node(tree, node, child);

  //if node is red, replace and free will just work
  if(node->isBlack){
    if(!child->isBlack){
      child->isBlack = true;
      free(node);  
      if(node == tree->root){
        tree->root = child;
      }
      return;
    }else{
      //node will never be root, because child is black, and exactly one child exists
      //so node->parent will never be tree->nil
      RBNode* sibling = node == node->parent->left ? node->parent->right : node->parent->left;
      if(!sibling->isBlack){
        node->parent->isBlack = false;
        sibling->isBlack = true;
        if(node == node->parent->left){
          leftRotate(tree, node->parent);
        }else{
          rightRotate(tree, node->parent);
        }
      }else{
        if(node->parent->isBlack && sibling->left->isBlack && sibling->right->isBlack){
          sibling->isBlack = false;
          RBDeleteNode(tree, node->parent);
        }else if(!node->parent->isBlack && sibling->left->isBlack && sibling->right->isBlack){
          sibling->isBlack = false;
          node->parent->isBlack = true;
        }else if(node == node->parent->left && sibling->right->isBlack && !sibling->left->isBlack){
          sibling->isBlack = false;
          sibling->left->isBlack = true;
          rightRotate(tree, sibling);
        }else if(node == node->parent->right && sibling->left->isBlack && !sibling->right->isBlack){
          sibling->isBlack = false;
          sibling->right->isBlack = true;
          leftRotate(tree, sibling);
        }else{
          sibling->isBlack = node->parent->isBlack;
          node->parent->isBlack = true;
          if(node == node->parent->left){
            sibling->right->isBlack = true;
            leftRotate(tree, node->parent);
          }else{
            sibling->left->isBlack = true;
            rightRotate(tree, node->parent);
          }
        }
      }
    }
  }

  free(node);
}


void RBDelete(RBTree* tree, int key){
  RBNode* current = tree->root;
  while(current != tree->nil){
    if(key == current->key){
      break;
    }
    if(key < current->key){
      current = current->left;
    }else{
      current = current->right;
    }
  }

  if(current == tree->nil){
    return;
  }

  RBNode* replace = tree->nil;
  if(current->left == tree->nil && current->right == tree->nil){
    replace = current;
  }else if(current->left != tree->nil){
    replace = current->left;
    while(replace->right != tree->nil){
      replace = replace->right;
    }
  }else{
    replace = current->right;
    while(replace->left != tree->nil){
      replace = replace->left;
    }
  }

  current->key = replace->key;
  current->value = replace->value;

  RBDeleteNode(tree, replace);
}

int main(int argc, char const *argv[])
{
	
  RBTree* tree = RBCreate();
  while(true){
    int num = 0;

    printf("please enter num: \n");
    scanf("%d", &num);

    if(num == 0){
      break;
    }

    int i=0;

    RBInsert(tree, num, num);

    int size = 0;
    char** preorder = preorderTraversal(tree, &size);
    
    for(i=0;i<size;i++){
      printf("%s\n", preorder[i]);
    }
    free(preorder); 
  }
  
  RBDestroy(tree);

	return 0;
}