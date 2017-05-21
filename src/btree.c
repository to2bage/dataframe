#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

void midOrderDG(TNode *root)
{
	if(root == NULL)
	{
		return;
	}

	if(root->lchild)
	{
		midOrderDG(root->lchild);
	}

	printf("%4d", root->data);

	if(root->rchild)
	{
		midOrderDG(root->rchild);
	}
}

//找到中序遍历的左子树的开始位置
TNode *goLeft(Node **pphead, TNode *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	TNode *px = root;
	while(1)
	{
		if(px->lchild)
		{
			//如果节点有左子树，将该节点入栈
			push(pphead, px);	
			px = px->lchild;
		}
		else if(px->lchild == NULL)
		{
			//printf("isEmpty(phead) == %d\n", isEmpty(*pphead));
			return px;	
		}
	}	
}

void midOrder(TNode *root)
{
	//定义栈
	Node *phead = NULL;
	TNode *pleft = goLeft(&phead, root);
	//printf("isEmpty(phead) == %d\n", isEmpty(phead));
	while(1)
	{
		printf("%4d\n", pleft->data);
		if(pleft->rchild)
		{
			//如果右子树存在
			//printf("a\n");
			pleft = goLeft(&phead, pleft->rchild);	
		}
		else if(pleft->rchild == NULL && isEmpty(phead) == 1)
		{
			//如果没有右子树，并且栈不为空
			//弹出栈顶节点
			//printf("b\n");
			pleft = top(phead);
			pop(&phead);
		}
		else if(pleft->rchild == NULL && isEmpty(phead) == 0)
		{
			//如果没有右子树，并且栈为空
			//退出while循环
			//printf("c\n");	
			pleft = NULL;
			break;
		}
	}		
}

#if 1
void push(Node **pphead, TNode *pTNode)
{
	Node *pnew = (Node *)malloc(sizeof(Node));
	if(pnew == NULL)
	{
		printf("malloc error\n");
		return ;
	}	
	memset(pnew, 0, sizeof(Node));
	pnew->pTNode = (TNode *)malloc(sizeof(TNode));
	pnew->pTNode->data = pTNode->data;
	pnew->pTNode->lchild = pTNode->lchild;
	pnew->pTNode->rchild = pTNode->rchild;
	pnew->pNext = NULL;

	if(*pphead == NULL)
	{
		*pphead = pnew;
	}
	else
	{
		pnew->pNext = *pphead;
		*pphead = pnew;
	}
}

void pop(Node **pphead)
{
	if(*pphead == NULL)
	{
		return; 
	}
	Node *pdeletenode = *pphead;
	*pphead = (*pphead)->pNext;
	free(pdeletenode->pTNode);
	pdeletenode->pTNode = NULL;
	free(pdeletenode);
	pdeletenode = NULL; 
	
}

TNode *top(Node *phead)
{
	if(phead == NULL)
	{
		return NULL;
	}

	return phead->pTNode;
}

void showstack(Node *phead)
{
	if(phead == NULL)
	{
		return;
	}

	Node *px = phead;
	while(px)
	{
		printf("%5d", px->pTNode->data);
		px = px->pNext;
	}
	printf("\n");
}

int isEmpty(Node *phead)
{
	if(phead == NULL)
	{
		return 0;	//为空
	}
	else
	{
		return 1;	//不为空
	}
}

#else

Node *push(Node *phead, int data)
{
	Node *pnew = (Node *)malloc(sizeof(Node));
	if(pnew == NULL)
	{
		printf("malloc error\n");
		return phead;
	}	
	memset(pnew, 0, sizeof(Node));
	pnew->data = data;
	pnew->pNext = NULL;

	if(phead == NULL)
	{
		phead = pnew;
	}
	else
	{
		pnew->pNext = phead;
		phead = pnew;
	}
	return phead;	
}

Node *pop(Node *phead)
{
	if(phead == NULL)
	{
		return phead;
	}
	Node *pdeletenode = phead;
	phead = phead->pNext;
	free(pdeletenode);
	pdeletenode = NULL; 
	
	return phead;
}

int top(Node *phead)
{
	if(phead == NULL)
	{
		return -1;
	}

	return phead->data;
}

void showstack(Node *phead)
{
	if(phead == NULL)
	{
		return;
	}

	Node *px = phead;
	while(px)
	{
		printf("%5d", px->data);
		px = px->pNext;
	}
	printf("\n");
}

int isEmpty(Node *phead)
{
	if(phead == NULL)
	{
		return 0;	//为空
	}
	else
	{
		return 1;	//不为空
	}
}

#endif
