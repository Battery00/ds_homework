#include<stdio.h>
#include"head.h"
/*
#define init_size 10
typedef int elemtype
typedef struct sqlist
{
	elemtype *elme; 
	int len;   //��Ч����
	int total_size;  //�ܹ���С
}list;
*/
void main()
{
	list list0;
	int q;
	init_sqlist(&list0);//��ʼ������
	for(int i=0;i<10;i++)
	{
		 insert(&list0,i,i*10);
	}
	insert(&list0,4,22);//����Ԫ�ز���
	printf("%d\n",search(&list0,40));//����Ԫ�ز���
	delete_pos(&list0,5);//ɾ��ָ��λ��Ԫ�ز���
	delete_value(&list0,30);//ɾ��Ԫ��
	printf("%d\n",get_length(&list0));//���˳����Ȳ���
	get_elem(&list0,5,&q);//���Ԫ�ز���
	printf("%d\n",q);
	is_empty(&list0);//�ж��Ƿ�Ϊ��
	clear_sqlist(&list0);//����˳���
	destroy_sqlist(&list0);//����˳���

/*
	//1.�����˳���A�г��ֵ�Ԫ�أ���˳���B��Ҳ���֣���A�и�Ԫ��ɾ��
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
			delete_value(&listA,listB.elem[i]);//ɾ��A�г�����B�е�Ԫ��
		}
	}
	show(&listA);
	show(&listB);


	//2.˳���C��Ԫ�طǵݼ�����
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