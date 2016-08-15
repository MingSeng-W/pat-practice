#include "stdio.h"
#define MAXSIZE 100
#define ERROR -1
// 定义线性表

typedef int position;
typedef struct Lnode *list;

struct Lnode
{
	Elemtype data[MAXSIZE];
	position last;
};


// 构造线性表

list init(){
list l;
l=(list)malloc(sizeof(struct Lnode));
l->last=-1;
return l;
}


// 插入操作
bool insert(Elemtype x,position p,list l){
	position i;

	if (l->last==MAXSIZE-1)
	{
		printf("%s\n", "线性表已经插满");
		return false
	}
	if (p<0||p>l->last+1)
	{
		printf("%s\n", "插入的位置不合法");
		return false
	}
	for (int i = l->last; i>=p; i--)
	{
		l->data[i+1]=l->data[i];
	}
	l->data[p]=x;
	l->last++;
return true;
}

// 删除操作
bool delet(list l,position p){
	position i;
	if (p<0||p>l->last+1)
	{
		printf("%s\n","删除的位置不适合");
		return false;
	}
	for ( i = p+1; i < l->last; ++i)
	{
		l->data[i]=l->data[i+1];
		
	}
	l->last--;
	return true;


}
// 查找操作

position find(list l,Elemtype x){
	position i=0;
	
	while(i<=l->last&&l->data[i]!=x) {
	    i++;
	}
	if (i>l->last)
	{
		return ERROR;
	}else{
		return i;
	}
}
