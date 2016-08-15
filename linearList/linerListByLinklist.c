
#include "stdio.h"
typedef stuct Lnode *ptrloNode;
typedef ptrloNode List;
typedef ptrloNode Position;
struct Lnode
{
	ElemType data;
	ptrloNode next;
};

// 查找

Position find(List L, ElemType x){
		Position tmp=L;
	while(tmp&&tmp->data!=x) {
	    tmp=tmp->next;
	}
	if (tmp)
	{
		return tmp
	}else{
		return NULL;
	}
}
// 删除
bool delete(List L,Position P){
	Postion pre,tmp;
	for(pre=L;pre&&pre->next!=P;pre=pre->next){
	}
	if (pre)
	{
		pre->next=P->next;
		free(P);
		return true;
	}else{
		printf("%s\n","删除错误" );
		return false;
	}
}
// 插入
bool insert(List L,Position P,ElemType x){
	Postion tmp,pre;
	for(pre=L;pre&&pre->next!=P;pre=pre->next){}
	if (pre==NULL)
	{
		printf("%s\n","查找位置错误" );
		return false;
	}else{
		tmp=(List)malloc(sizeof(Lnode));
		tmp->data=x;
		tmp->next=P;
		pre->next=tmp;
		return true;
	}

