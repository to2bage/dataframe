#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.h"
//#include "comm.h"

void preOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return;
	}	

	printf("%4d", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void inOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return;
	}

	inOrder(root->lchild);
	printf("%4d", root->data);
	inOrder(root->rchild);
}

void postOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return;
	}

	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%4d", root->data);
}

//int count = 0;

void getCountOfLeaf(BiTNode *root, int *count)
{
	if(root)
	{
		if(root->lchild == NULL && root->rchild == NULL)
		{
			(*count)++;
		}

		if(root->lchild)
		{
			getCountOfLeaf(root->lchild, count);
		}

		if(root->rchild)
		{
			getCountOfLeaf(root->rchild, count);
		}
	}
}

int getDeepOfTree(BiTNode *root)
{
	int rdeep = 0;
	int ldeep = 0;
	int deep_value = 0;

	if(root == NULL)
	{
		deep_value = 0;
		return deep_value;
	}

	ldeep = getDeepOfTree(root->lchild);
	rdeep = getDeepOfTree(root->rchild);

	deep_value = 1 + ((ldeep > rdeep)? ldeep : rdeep);

	return deep_value;
}

BiTNode *copyTree(BiTNode *root)
{
	BiTNode *newroot = (BiTNode *)malloc(sizeof(BiTNode));
	if(newroot == NULL)
	{
		return NULL;
	}
	newroot->data = root->data;
	newroot->lchild = NULL;
	newroot->rchild = NULL;

	BiTNode *rchild = NULL;
	BiTNode *lchild = NULL;

	if(root == NULL)
	{
		return NULL;
	}

	if(root->lchild != NULL)
	{
		lchild = copyTree(root->lchild);
	}	
	else
	{
		lchild = NULL;
	}

	if(root->rchild != NULL)
	{
		rchild = copyTree(root->rchild);
	}
	else
	{
		rchild = NULL;
	}

	newroot->lchild = lchild;
	newroot->rchild = rchild;

	return newroot;
}
