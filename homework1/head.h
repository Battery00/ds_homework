#include<stdio.h>
#define init_size 10
#define incr_size 5
typedef int elemtype

typedef struct sqlist
{
	elemtype *elem; 
	int len;   //有效数据
	int total_size;  //总共大小
}list;

void init_sqlist(list *p);
void destroy_sqlist(list *p);
void clear_sqlist(list *p);
bool is_empty(list *p);
int get_length(list *p);
bool insert(list *p,int pos,elemtype val);
void inc(list *p);
bool delete_value(list *p,elemtype val);
bool delete_pos(list *p,elemtype pos);
int search(list *p,elemtype key);
void show(list *p);
bool get_elem(list *p,int pos,elemtype *e);