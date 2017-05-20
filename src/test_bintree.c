#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bin_tree.h"
//#include "comm.h"

int main(int argc, char *argv[])
{
#if 1
	BiTNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.data = 2;
	t2.lchild = &t4;
	t2.rchild = NULL;

	t3.data = 3;
	t3.lchild = &t5;
	t3.rchild = NULL;

	t4.data = 4;
	t4.lchild = t4.rchild = NULL;

	t5.data = 5;
	t5.lchild = t5.rchild = NULL;
#else
	BiTNode *p1, *p2, *p3, *p4, *p5;

	p1 = (BiTNode *)malloc(sizeof(BiTNode));
	memset(p1, 0, sizeof(BiTNode));
	p2 = (BiTNode *)malloc(sizeof(BiTNode));
	memset(p2, 0, sizeof(BiTNode));
	p3 = (BiTNode *)malloc(sizeof(BiTNode));
	memset(p3, 0, sizeof(BiTNode));
	p4 = (BiTNode *)malloc(sizeof(BiTNode));
	memset(p4, 0, sizeof(BiTNode));
	p5 = (BiTNode *)malloc(sizeof(BiTNode));
	memset(p5, 0, sizeof(BiTNode));

	p1->data = 1;
	p1->lchild = p2;
	p1->rchild = p3;

	p2->data = 2;
	p2->lchild = p4;
	p2->rchild = NULL;

	p3->data = 3;
	p3->lchild = p5;
	p3->rchild = NULL;

	p4->data = 4;
	p4->lchild = p4->rchild = NULL;
	p5->data = 5;
	p5->lchild = p5->rchild = NULL;
#endif

	//先序遍历
	preOrder(&t1);
	printf("\n");
	//中序遍历
	inOrder(&t1);
	printf("\n");
	//后续遍历
	postOrder(&t1);
	printf("\n");

	//获得叶子节点的个数
	int count = 0;
	getCountOfLeaf(&t1, &count);
	printf("叶子节点的个数是：%d\n", count);

	//获得二叉树的高度
	int deep = getDeepOfTree(&t1);
	printf("二叉树的高度是: %d\n", deep);	

	//拷贝二叉树
	BiTNode *newroot = copyTree(&t1);
	preOrder(newroot);
	printf("\n");

	return 0;
}
