// 2.2堆栈
#include "stdio.h"
#include "stdlib.h"


//堆栈的链表实现
typedef int ElemType;
typedef struct Snode *PtrlToSNode;
struct Snode
{
	ElemType data;
	PtrlToSNode next;
};
typedef PtrlToSNode Stack;



Stack createStack(){
	Stack s;
	s=(PtrlToSNode)malloc(sizeof(Snode));
	s->next=NULL;
	return s;
}
//判空
bool Empty(Stack S){
	return (S->next==NULL);
}


//push方法
bool push(Stack S,ElemType x){
	PtrlToSNode tmp;
	tmp=(PtrlToSNode)malloc(sizeof(Snode));
	tmp->data=x;
	tmp->next=S->next;
	S->next=tmp;
	return true;
}

//pop方法

ElemType pop(Stack S){
	PtrlToSNode tmp=S->next;
	if (Empty(S))
	{
		return NULL;
	}else{
	S->next=tmp->next;
	ElemType returndata=tmp->data;
	free(tmp);
	return returndata;
	}
	
}

int main(int argc, char const *argv[])
{		Stack s;

	s=createStack();
	push(s,2);
	push(s,3);
	int result1=pop(s);
	int result2=pop(s);
	printf("%d %d\n",result1,result2 );


}
//改文件的可执行文件为stack


