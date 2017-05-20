#ifndef _BIN_TREE_H
#define _BIN_TREE_H

struct BiTNode
{
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
};

typedef struct BiTNode BiTNode;
typedef struct BitNode *BiTree;

//先序遍历
void preOrder(BiTNode *root);
//中序遍历
void inOrder(BiTNode *root);
//后序遍历
void postOrder(BiTNode *root);

//树的叶子节点的个数
void getCountOfLeaf(BiTNode *root, int *count);

//树的深度
int getDeepOfTree(BiTNode *rootp);

//树的拷贝
BiTNode *copyTree(BiTNode *root);


#endif
