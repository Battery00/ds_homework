#include"linkstack.h"
#include<stdio.h>


void main()
{
	linkstack p;
	init_stack(&p);
	push_stack(&p,5);
	push_stack(&p,8);
	printf("%d\n",stack_length(&p));
	int e;
	printf("%d\n",top_stack(&p,&e));
	/*pop_stack(&p,&e);
	printf("%d\n",e);*/
	char *str="6 + { ( 7 - 1 )  * 3 + 8 } / 2";
	char arr[50]={0};
	mid_to_rear(&p,str,arr);//中缀转后缀
	printf("中缀转后缀结果为:%s\n",arr);
}