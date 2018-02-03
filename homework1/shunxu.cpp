#include<stdio.h>
#include"head.h"
#include<stdlib.h>

void init_sqlist(list *p) //1.初始化顺序表(建立空表)
{
	p->elem=(elemtype *)malloc(sizeof(elemtype)*init_size);
	p->len=0;
	p->total_size=init_size;
}

void destroy_sqlist(list *p)//2.销毁不定长顺序表
{
	free(p->elem);
	p->elem=NULL;
	p->len=0;
	p->total_size=0;
}

void clear_sqlist(list *p)//3.清零顺序表
{
	p->len=0;
}

bool is_empty(list *p)//4.判断顺序表是否为空
{
	/*if(p->len==0)
	{
		return true;
	}
	return false;*/
	return (p->len==0);
}

int get_length(list *p)//5.获得顺序表长度
{
	return p->len;
}

void incr_list(list *p) //扩容
{
	p->elme=(elemtype *)realloc(p->elme,(p->total_size+incr_size)*(sizeof(elemtype)));
	p->total_size += incr_size;
}

bool is_full(list *p)  //判断顺序表是否为满
{
	if(p->len == p->total_size)
		return true;
	else
		return false;
}

bool insert(list *p,int pos,elemtype val)//6.根据位置向顺序表中插入元素
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

bool delete_value(list *p,elemtype val)  //7.根据数据项删除表中的元素
{
	for(i = 0;i < p->len;i++)
	{
		if(p->elem[i] == val)
		{
			
		}
	}
	
}









bool delete_value(list *p,elemtype val)//7.根据数据项删除表中的元素
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
bool delete_pos(list *p,elemtype pos)//根据位置删除顺序表中的元素
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
int search(list *p,elemtype key)//返回查找到的元素的位置
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
void show(list *p)//打印顺序表
{
	for(int i=0;i<p->len;i++)
	{
		printf("%d ",p->elem[i]);
	}
	printf("\n");
}

bool get_elem(list *p,int pos,elemtype *e)//把顺序表中第pos个位置的元素返回给e
{
	if(pos>0 && pos<p->len)
	{
		*e=p->elem[pos-1];
		return true;
	}
	return false;
}
