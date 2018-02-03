#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkstack.h"

void init_stack(linkstack *s)//1.��ջ��ʼ��
{
	assert(s!=NULL);
	s->top=NULL;
	s->count=0;
}
bool push_stack(linkstack *s,elemtype value)//2.��ջ(Ϊ��&�������)
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
bool is_stackempty(linkstack *s)//3.ջ�Ƿ�Ϊ��
{
	assert(s!=NULL);
	return (s->top=NULL);

}
bool pop_stack(linkstack *s,elemtype *e)//4.��ջ(ջ��)
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
void destory_stack(linkstack *s)//5.������ջ
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
elemtype top_stack(linkstack *s,elemtype *e)//6.��ջ�����ҷǿ� ����ջ��Ԫ��
{
	assert(s!=NULL);
	if(!is_stackempty(s))
	{
		return *e=s->top->data;
	}
}
int stack_length(linkstack *s)//7.����ջԪ�ظ���
{
	assert(s!=NULL);
	return s->count;
}
//2.�沨��
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
		if(str1[i]>='0' && str1[i]<='9')//�������
		{
			str2[j]=str1[i];
			j++;
		}
		//˳������ƥ��
		else if(str1[i]=='(' || str1[i]=='[' || str1[i]=='{')//��������ջ
		{
			push0(s,str1[i]);
		}
		char a='c';
		else if(str1[i]!=' ')//������ջ
		{
			if(str1[i]=='+' || str1[i]=='-')//�������ڡ�+���͡�-�����ȼ���ȫ����ջ
			{
				while(a!='(' && a!='{' && a!='[')//��������ֹͣ
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
		else if(str1[i]==')'||str1[i]==']'||str1[i]=='}')//��������֮ǰ��ȫ����ջ
		{
			while(a!='(' && a!='[' && a!='}')
			{
				pop0(s,&str2[j]);
				a=str2[j];
				j++;
			}
			j--;
			str2[j]=0;
			pop0(s,&str2[j]);//�����ų�ջ		
		}
	}


	//while(!is_empty(s))//ȫ����ջ
	//{
	//	pop0(s,&str2[j]);
	//	j++;
	//}
	/*str2[j]=0;*/
}

