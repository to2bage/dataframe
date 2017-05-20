#ifndef _B_TREE_H
#define _B_TREE_H

struct treenode
{
	int data;
	struct treenode *lchild;
	struct treenode *rchild;
};

typedef struct treenode TNode;

//定义栈
#if 1
struct node
{
	TNode *pTNode;
	struct node *pNext;
};

typedef struct node Node;

Node *push(Node *phead, TNode *pTNode);
Node *pop(Node *phead);
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
