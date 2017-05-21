#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

int main(int argc, char *argv[])
{
#if 0
	//测试链式栈
	Node *phead = NULL;
	
	for(int i = 0; i < 10; i++)
	{
		phead = push(phead, i + 1);		
		showstack(phead);
	}

	while(isEmpty(phead))
	{
		printf("pop %2d ==> ", top(phead));
		phead = pop(phead);
		showstack(phead);
	}
#else
	//测试二叉树的节点
	TNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.data = 2;
	t2.lchild = &t4;
	t2.rchild = &t5;

	t3.data = 3;
	t3.lchild = t3.rchild = NULL;

	t4.data = 4;
	t4.lchild = t4.rchild = NULL;

	t5.data = 5;
	t5.lchild = t5.rchild = NULL;
/*
	Node *phead = NULL;
	phead = push(phead, &t1);
	phead = push(phead, &t2);
	phead = push(phead, &t3);
	phead = push(phead, &t4);
	phead = push(phead, &t5);
	showstack(phead);

	while(isEmpty(phead))
	{
		printf("pop %d ==> ", top(phead)->data);	
		phead = pop(phead);
		showstack(phead);
	}
*/	
	//二叉树的递归中序遍历
	midOrderDG(&t1);	
	printf("\n");

	midOrder(&t1);

#endif





	return 0;
}
