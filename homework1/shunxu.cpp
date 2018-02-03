#include<stdio.h>
#include"head.h"
#include<stdlib.h>

void init_sqlist(list *p) //1.��ʼ��˳���(�����ձ�)
{
	p->elem=(elemtype *)malloc(sizeof(elemtype)*init_size);
	p->len=0;
	p->total_size=init_size;
}

void destroy_sqlist(list *p)//2.���ٲ�����˳���
{
	free(p->elem);
	p->elem=NULL;
	p->len=0;
	p->total_size=0;
}

void clear_sqlist(list *p)//3.����˳���
{
	p->len=0;
}

bool is_empty(list *p)//4.�ж�˳����Ƿ�Ϊ��
{
	/*if(p->len==0)
	{
		return true;
	}
	return false;*/
	return (p->len==0);
}

int get_length(list *p)//5.���˳�����
{
	return p->len;
}

void incr_list(list *p) //����
{
	p->elme=(elemtype *)realloc(p->elme,(p->total_size+incr_size)*(sizeof(elemtype)));
	p->total_size += incr_size;
}

bool is_full(list *p)  //�ж�˳����Ƿ�Ϊ��
{
	if(p->len == p->total_size)
		return true;
	else
		return false;
}

bool insert(list *p,int pos,elemtype val)//6.����λ����˳����в���Ԫ��
{
	if(pos < 0 || pos > p->len)
	{
		return false;
	}
	if(is_full(p))
	{
		incr_list(p);
	}
	for (i=p->len;i>pos;i--)
	{
		p->elme[i]=p->elem[i-1];
	}
	p->elme[pos]=val;
	p->len ++;
	}
}

bool delete_value(list *p,elemtype val)  //7.����������ɾ�����е�Ԫ��
{
	for(i = 0;i < p->len;i++)
	{
		if(p->elem[i] == val)
		{
			
		}
	}
	
}









bool delete_value(list *p,elemtype val)//7.����������ɾ�����е�Ԫ��
{
	for(int i=0;i<p->len;i++)
	{
		if(p->elem[i]==val)
		{
			for(int j=i;j<p->len;j++)
			{
				p->elem[j]=p->elem[j+1];
			}
			p->len--;
			return true;
		}
	}
	return false;

}
bool delete_pos(list *p,elemtype pos)//����λ��ɾ��˳����е�Ԫ��
{
	if(pos>0 && pos < p->len)
	{
		for(int i=pos-1;i<p->len;i++)
	   {
		   p->elem[i]=p->elem[i+1];
	    }
	    p->len--;
	   return true; 
	}
	return false;
}
int search(list *p,elemtype key)//���ز��ҵ���Ԫ�ص�λ��
{
	for(int i=0;i<p->len;i++)
	{
		if(p->elem[i]==key)
		{
			return i+1;
		}
	}
	return -1;
}
void show(list *p)//��ӡ˳���
{
	for(int i=0;i<p->len;i++)
	{
		printf("%d ",p->elem[i]);
	}
	printf("\n");
}

bool get_elem(list *p,int pos,elemtype *e)//��˳����е�pos��λ�õ�Ԫ�ط��ظ�e
{
	if(pos>0 && pos<p->len)
	{
		*e=p->elem[pos-1];
		return true;
	}
	return false;
}
