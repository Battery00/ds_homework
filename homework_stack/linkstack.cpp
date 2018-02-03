#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkstack.h"

void init_stack(linkstack *s)//1.链栈初始化
{
	assert(s!=NULL);
	s->top=NULL;
	s->count=0;
}
bool push_stack(linkstack *s,elemtype value)//2.进栈(为空&多数情况)
{
	assert(s!=NULL);
	stacknode *newnode=(stacknode *)malloc(sizeof(linkstack)*1);
	assert(newnode!=NULL);
	newnode->data=value;
	newnode->next=s->top;
	s->top=newnode;
	s->count++;
	return true;
}
bool is_stackempty(linkstack *s)//3.栈是否为空
{
	assert(s!=NULL);
	return (s->top=NULL);

}
bool pop_stack(linkstack *s,elemtype *e)//4.出栈(栈顶)
{
	assert(s!=NULL);
	if(is_stackempty(s))
	{
		return false;
	}
	*e=s->top->data;
	stacknode *q=s->top;
	s->top=s->top->next;
	free(q);
	s->count--;
	return true;
}
void destory_stack(linkstack *s)//5.销毁链栈
{
	assert(s!=NULL);
	while(s->count!=0)
	{
		stacknode *q=s->top;
		s->top=s->top->next;
		free(q);
		s->count--;
	}
}
elemtype top_stack(linkstack *s,elemtype *e)//6.若栈存在且非空 返回栈顶元素
{
	assert(s!=NULL);
	if(!is_stackempty(s))
	{
		return *e=s->top->data;
	}
}
int stack_length(linkstack *s)//7.返回栈元素个数
{
	assert(s!=NULL);
	return s->count;
}
//2.逆波兰
bool pop0(linkstack *s,char *e)
{
	if(is_stackempty(s))
	{
		return false;
	}
	*e=s->top->data;
	stacknode *q=s->top;
	s->top=s->top->next;
	free(q);
	s->count--;
	return true;
}
bool push0(linkstack *s,char value)
{
	stacknode *newnode=(stacknode *)malloc(sizeof(stacknode));
	newnode->data=value;
	newnode->next=s->top;
	s->top=newnode;
	s->count++;
	retrun true;
}
void mid_to_rear(linkstack *s,char *str1,char *str2)
{
	int i=0;
	int	j=0;
	while(str1[i]!='\0')
	{
		if(str1[i]>='0' && str1[i]<='9')//输出数字
		{
			str2[j]=str1[i];
			j++;
		}
		//顺带括号匹配
		else if(str1[i]=='(' || str1[i]=='[' || str1[i]=='{')//左括号入栈
		{
			push0(s,str1[i]);
		}
		char a='c';
		else if(str1[i]!=' ')//符号入栈
		{
			if(str1[i]=='+' || str1[i]=='-')//将不低于‘+’和‘-’优先级的全部出栈
			{
				while(a!='(' && a!='{' && a!='[')//遇到括号停止
			   {
				   if(is_stackempty(s))
				   {
					   break;
				   }
				   pop0(s,&str2[j]); 
				   a=str2[j];
				   if(f=='(' || f=='[' || f=='{')
				   {
                       push0(s,f);
					   str2[j]=0;
					   j--;
				   } 
				   j++;
			   }
				push0(s,str1[i]);
			}
		}
		i++;
		else if(str1[i]==')'||str1[i]==']'||str1[i]=='}')//将左括号之前的全部出栈
		{
			while(a!='(' && a!='[' && a!='}')
			{
				pop0(s,&str2[j]);
				a=str2[j];
				j++;
			}
			j--;
			str2[j]=0;
			pop0(s,&str2[j]);//左括号出栈		
		}
	}


	//while(!is_empty(s))//全部出栈
	//{
	//	pop0(s,&str2[j]);
	//	j++;
	//}
	/*str2[j]=0;*/
}

