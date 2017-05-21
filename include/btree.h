#ifndef _B_TREE_H
#define _B_TREE_H

//定义二叉树的节点
struct treenode
{
	int data;
	struct treenode *lchild;
	struct treenode *rchild;
};

typedef struct treenode TNode;

//二叉树的中序遍历(递归)
void midOrderDG(TNode *root);
void midOrder(TNode *root);	//非递归

//定义栈
#if 1
struct node
{
	TNode *pTNode;
	struct node *pNext;
};

typedef struct node Node;


void push(Node **pphead, TNode *pTNode);
void pop(Node **pphead);
TNode *top(Node *phead);
void showstack(Node *phead);
int isEmpty(Node *phead);

#else

struct node
{
	int data;
	struct node *pNext;
};

typedef struct node Node;

Node *push(Node *pnode, int data);
Node *pop(Node *pnode);
int top(Node *pnode);
void showstack(Node *pnode);
int isEmpty(Node *pnode);

#endif


#endif
