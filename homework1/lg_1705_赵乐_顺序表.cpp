#include<stdio.h>
#include"head.h"
/*
#define init_size 10
typedef int elemtype
typedef struct sqlist
{
	elemtype *elme; 
	int len;   //有效数据
	int total_size;  //总共大小
}list;
*/
void main()
{
	list list0;
	int q;
	init_sqlist(&list0);//初始化测试
	for(int i=0;i<10;i++)
	{
		 insert(&list0,i,i*10);
	}
	insert(&list0,4,22);//插入元素测试
	printf("%d\n",search(&list0,40));//查找元素测试
	delete_pos(&list0,5);//删除指定位置元素测试
	delete_value(&list0,30);//删除元素
	printf("%d\n",get_length(&list0));//获得顺序表长度测试
	get_elem(&list0,5,&q);//获得元素测试
	printf("%d\n",q);
	is_empty(&list0);//判断是否为空
	clear_sqlist(&list0);//清零顺序表
	destroy_sqlist(&list0);//销毁顺序表

/*
	//1.如果在顺序表A中出现的元素，在顺序表B中也出现，则将A中该元素删除
	list listA,listB;
	init_sqlist(&listA);
	init_sqlist(&listB);
	for(int i=0;i<10;i++)
	{
		insert(&listA,i,2*(i+1));
		insert(&listB,i,3*(i+1));
	}
	for(int i=0;i<listB.len;i++)
	{
		if(search(&listA,listB.elem[i])!=-1)
		{
			delete_value(&listA,listB.elem[i]);//删除A中出现在B中的元素
		}
	}
	show(&listA);
	show(&listB);


	//2.顺序表C中元素非递减排列
   list listA,listB,listC;
   init_sqlist(&listA);
   init_sqlist(&listB);
   init_sqlist(&listC);
   for(int i=0;i<10;i++)
   {
	   insert(&listA,i,2*(i+1));
	   insert(&listB,i,3*(i+1));
   }
   for(int i=0;i<listA.len;i++)
   {
	   insert(&listC,i,listA.elem[i]);
   }
   for(int i=listA.len;i<listA.len+listB.len;i++)
   {
	   insert(&listC,i,listB.elem[i-listA.len]);
   }
   show(&listC);
   for(int i=0;i<listC.len;i++)
   {
	   for(int j=i+1;j<listC.len;j++)
	   {
		   if(listC.elem[i]>listC.elem[j])
		   {
			   int temp;
			   temp=listC.elem[i];
			   listC.elem[i]=listC.elem[j];
			   listC.elem[j]=temp;
		   }
	   }
   }
 show(&listC);*/
}