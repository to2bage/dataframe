#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *plchild;
	struct node *prchild;
};

typedef struct node Node;

//二叉树的前序遍历
void preOrder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%4d", root->data);

	preOrder(root->plchild);
	preOrder(root->prchild);
}
//二叉树的中序遍历
void midOrder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	midOrder(root->plchild);
	printf("%4d", root->data);
	midOrder(root->prchild);
}
//二叉树的后序遍历
void afterOrder(Node *root)
{
	if(root == NULL)
	{
		return;	
	}

	afterOrder(root->plchild);
	afterOrder(root->prchild);
	printf("%4d", root->data);
}

//获得二叉树的叶子节点的个数
#if 0
void countOfLeaf(Node *root, int *pcount)
{
	if(root)
	{
		if(root->plchild == NULL && root->prchild == NULL)
		{
			(*pcount)++;
			//return;
		}
		else
		{
			if(root->plchild)
			{
				countOfLeaf(root->plchild, pcount);
			}

			if(root->prchild)
			{
				countOfLeaf(root->prchild, pcount);
			}
		}
	}
}
#else
void countOfLeaf(Node *root, int *pcount)
{
	if(root == NULL)
	{
		return;
	}
	else if(root->plchild == NULL || root->prchild == NULL)
	{
		(*pcount)++;
	}
	else
	{
		if(root->plchild)
		{
			countOfLeaf(root->plchild, pcount);
		}
		
		if(root->prchild)
		{
			countOfLeaf(root->prchild, pcount);
		}
	}
}
#endif

//获得二叉树的高度
int deepOfTree(Node *root)
{
	int ldeep = 0;
	int rdeep = 0;
	int deep = 0;

	if(root == NULL)
	{
		return deep;
	}

	if(root->plchild)
	{
		ldeep = deepOfTree(root->plchild);
	}

	if(root->prchild)
	{
		rdeep = deepOfTree(root->prchild);
	}

	deep = 1 + (ldeep > rdeep ? ldeep : rdeep);

	return deep;
}

//递归实现拷贝二叉树
//拷贝是从左子树的最底层的叶子节点开始拷贝，拷贝完两个叶子节点，再拷贝父节点
Node *copyBinTree(Node *root)
{
	if(root == NULL)
	{
		return NULL;
	}

	Node *pltree = NULL;
	Node *prtree = NULL;

	if(root->plchild != NULL)
	{
		pltree = copyBinTree(root->plchild);
	}
	
	if(root->prchild != NULL)
	{
		prtree = copyBinTree(root->prchild);
	}	
	
	Node *newroot = (Node *)malloc(sizeof(Node));
	if(newroot == NULL)
	{
		printf("copy bin tree failed\n");
		return NULL;
	}
	memset(newroot, 0, sizeof(Node));
	newroot->data = root->data;
	newroot->plchild = pltree;
	newroot->prchild = prtree;	

	return newroot;
}

int main(int argc, char *argv[])
{
	//建立二叉树
	Node t1, t2, t3, t4, t5;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.plchild = &t2;
	t1.prchild = &t3;

	t2.plchild = &t4;
	t2.prchild = &t5;

	t3.plchild = t3.prchild = NULL;
	t4.plchild = t4.prchild = NULL;
	t5.plchild = t5.prchild = NULL;

	//前序遍历
	printf("前序遍历:");
	preOrder(&t1);
	printf("\n");
	printf("中序遍历:");
	midOrder(&t1);
	printf("\n");
	printf("后序遍历:");
	afterOrder(&t1);
	printf("\n");
	
	//获得二叉树的叶子节点个数
	int count = 0;
	countOfLeaf(&t1, &count);
	printf("二叉树叶子节点的个数是: %d\n", count);

	//获得二叉树的高度
	int deep = deepOfTree(&t1);
	printf("二叉树的高度是: %d\n", deep);

	//拷贝二叉树
	Node *newroot = copyBinTree(&t1);
	printf("前序遍历:");
	preOrder(newroot);
	printf("\n");
	printf("中序遍历:");
	midOrder(newroot);
	printf("\n");
	printf("后序遍历:");
	afterOrder(newroot);
	printf("\n");
	

	return 0;
}
