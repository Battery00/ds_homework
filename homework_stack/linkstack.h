#include<stdio.h>

typedef int elemtype;
typedef struct s_node//链栈节点
{
	elemtype data;
	struct s_node *next; 
}stacknode;
typedef struct 
{
	stacknode *top;//栈顶指针
	int count;
}linkstack;


void init_stack(linkstack *s);//1.初始化
bool push_stack(linkstack *s,elemtype value);//2.入栈
bool is_stackempty(linkstack *s);//3.栈是否为空
bool pop_stack(linkstack *s,elemtype *e);//4.出栈(栈顶)
void destory_stack(linkstack *s);//5.销毁链栈
elemtype top_stack(linkstack *s,elemtype *e);//6.若栈存在且非空 返回栈顶元素
int stack_length(linkstack *s);//7.返回栈元素个数
bool pop0(linkstack *s,char *e);
bool push0(linkstack *s,char value);
void mid_to_rear(linkstack *s,char *str1,char *str2)

