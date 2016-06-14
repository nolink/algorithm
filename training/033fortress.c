

#include <stdio.h>
#include <stdlib.h>

struct sTreeNode
{
	int val;
	struct sTreeNode* left;
	struct sTreeNode* right;
} ;

typedef struct sTreeNode TreeNode;

int max(int a, int b){
	return a > b ? a : b;
}

TreeNode* create(int val){
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	t->val = val;
	t->left = NULL;
	t->right = NULL;
	return t;
}

TreeNode* insert(TreeNode* parent, TreeNode* child, int left){

	if(left){
		parent->left = child;
	}else{
		parent->right = child;
	}

	return child;
}

void destroy(TreeNode* node){

	if(NULL != node->left){
		destroy(node->left);
	}

	if(NULL != node->right){
		destroy(node->right);
	}	

	free(node);

	node = NULL;

}

//定义：一棵树中，从一个叶子节点，到另一个叶子节点的最长路径
//longest表示，该节点左、右两条路径中，较长的一条的长度
//返回值：所有路径中最长的
int longestSubPath(TreeNode* tree, int* longest){

	if(NULL == tree || (NULL == tree->left && NULL == tree->right)){
		return 0;
	}

	int left_longest = 0, right_longest = 0;

	int left = longestSubPath(tree->left, &left_longest);

	int right = longestSubPath(tree->right, &right_longest);

	*longest = max(left_longest, right_longest) + 1;

	int children = (NULL != tree->left && NULL != tree->right) ? 2 : 1;

	return max(left+right, left_longest + right_longest + children);

}


int main(int argc, char const *argv[])
{
	
	TreeNode* root = create(1);

	// TreeNode* n2 = insert(root, create(2), 1);
	// TreeNode* n3 = insert(root, create(3), 0);

	// TreeNode* n4 = insert(n2, create(4), 1);
	// TreeNode* n5 = insert(n2, create(5), 0);

	// TreeNode* n6 = insert(n3, create(6), 1);
	// TreeNode* n7 = insert(n3, create(7), 0);

	// TreeNode* n8 = insert(n4, create(8), 1);


	TreeNode* n2 = insert(root, create(2), 1);

	TreeNode* n3 = insert(n2, create(3), 1);
	TreeNode* n4 = insert(n2, create(4), 0);
	
	TreeNode* n5 = insert(n3, create(5), 1);

	TreeNode* n6 = insert(n4, create(6), 1);
	TreeNode* n7 = insert(n6, create(7), 1);

	TreeNode* n8 = insert(n7, create(8), 1);

	int v=0;
	printf("%d\n", longestSubPath(root, &v));

	destroy(root);

	return 0;
}