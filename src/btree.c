#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

#if 1
Node *push(Node *phead, TNode *pTNode)
{
	Node *pnew = (Node *)malloc(sizeof(Node));
	if(pnew == NULL)
	{
		printf("malloc error\n");
		return phead;
	}	
	memset(pnew, 0, sizeof(Node));
	pnew->pTNode = (TNode *)malloc(sizeof(TNode));
	pnew->pTNode->data = pTNode->data;
	pnew->pTNode->lchild = pTNode->lchild;
	pnew->pTNode->rchild = pTNode->rchild;
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
	free(pdeletenode->pTNode);
	pdeletenode->pTNode = NULL;
	free(pdeletenode);
	pdeletenode = NULL; 
	
	return phead;
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
