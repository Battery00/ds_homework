#include<stdio.h>
#include"looplist.h"

void main()
{
	node p_loop;
	int n=10;
	int m=3;
	int i;
	init_node(&p_loop);
	for(i=0;i<n;i++)
	{
		insert_tail(&p_loop,i+1);
	}
	int tem=yusefu_list(&p_loop,n,m);
	printf("%d\n",tem);
	



}
