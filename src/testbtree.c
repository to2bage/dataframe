#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

int main(int argc, char *argv[])
{
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






	return 0;
}
