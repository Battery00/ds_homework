#include<stdio.h>

typedef int elemtype;
typedef struct looplist
{
	elemtype data;
	struct looplist *next;
}node;
void init_node(node *phead);
void insert_tail(node *phead,elemtype value);
int yusefu_list(node *phead,elemtype number,elemtype m);