#include<stdio.h>

typedef int elemtype;
typedef struct s_node//��ջ�ڵ�
{
	elemtype data;
	struct s_node *next; 
}stacknode;
typedef struct 
{
	stacknode *top;//ջ��ָ��
	int count;
}linkstack;


void init_stack(linkstack *s);//1.��ʼ��
bool push_stack(linkstack *s,elemtype value);//2.��ջ
bool is_stackempty(linkstack *s);//3.ջ�Ƿ�Ϊ��
bool pop_stack(linkstack *s,elemtype *e);//4.��ջ(ջ��)
void destory_stack(linkstack *s);//5.������ջ
elemtype top_stack(linkstack *s,elemtype *e);//6.��ջ�����ҷǿ� ����ջ��Ԫ��
int stack_length(linkstack *s);//7.����ջԪ�ظ���
bool pop0(linkstack *s,char *e);
bool push0(linkstack *s,char value);
void mid_to_rear(linkstack *s,char *str1,char *str2)

