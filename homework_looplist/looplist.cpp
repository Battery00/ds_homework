#include<stdlib.h>
#include<assert.h>
#include"looplist.h"

void init_node(node *phead)//����ѭ�������ʼ��
{
	phead->data=0;
	phead->next=phead;
}

void insert_tail(node *phead,elemtype value)//����ѭ������β��
{
	node *newnode=(node *)malloc(sizeof(node)*1);
	assert(newnode!=NULL);
	newnode->data=value;
	node *p=phead;
	while(p->next!=phead)
	{
		p=p->next;
	}
	p->next=newnode;
	newnode->next=phead;
}

//void insert_tail(node *phead,elemtype value)//����ѭ������β��
//{
//	node *newnode=(node *)malloc(sizeof(node)*1);
//	assert(newnode!=NULL);
//	newnode->data=value;
//	node *p=phead;
//	while(p->next!=phead)
//	{
//		p=p->next;
//	}
//	p->next=newnode;
//	newnode->next=phead;
//}

int yusefu_list(node *phead,elemtype number,elemtype m)//����ѭ��ʵ��Լɪ��
{
	node *p=phead;	
	while(phead->next->next!=phead)
	{
		for(int i=1;i<=m-1;i++)
		{
			p=p->next;
			if(p->next==phead)
			{
				p=p->next;
			}
		}
		if(p->next==phead)
		{
			p=p->next;
		}
		node *q=p->next;
		p->next=p->next->next;
		free(q);
	}
	return phead->next->data;
}