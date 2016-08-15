// 一个数组实现两个堆栈
#include "stdio.h"
#include "stdlib.h"

typedef int Postion;
typedef int ElemType;
#define ERROR -1000000

typedef struct Snode *Stack;
struct Snode
{
	Postion top1;
	Postion top2;
	ElemType *data;
	int maxsize;
	
};

Stack createStack(int maxsize){
	Stack s;
	s=(Stack)malloc(sizeof(struct Snode));
	s->data=(ElemType*)malloc(maxsize*sizeof(ElemType));
	s->top1=-1;
	s->top2=maxsize;
	return s;

}
bool IsEmpty(Stack s,int flag){
if (flag==1)
{
	return(s->top1==-1);
}else{
	return(s->top2==s->maxsize);
}
}
bool IsFull(Stack s){
	return ((s->top2)-(s->top1)==1);

}

bool push(Stack s,ElemType x,int flag){
	if (IsFull(s))
	{
		printf("%s\n","堆栈已满" );
		return false;
	}else{
		if (flag==1)
		{
			s->data[++(s->top1)]=x;
		}else{
			s->data[--(s->top2)]=x;	
		}

			return true;
	}

}

ElemType pop(Stack s,int flag){
if (IsEmpty(s,flag))
{
	printf("%s\n", "堆栈已经满了");
	return ERROR;
}else{
	if (flag==1)
	{
		return (s->data[(s->top1)--]);
		
	}else{
		return(s->data[(s->top2)++]);
	}

}

}

int main(int argc, char const *argv[])
{	
	Stack s;
	s=createStack(100);
	push(s,2,1);//1代表从数组左边进栈
	push(s,3,2);//2代表从数组的右边进栈
	int result1=pop(s,2);
	int result2=pop(s,1);
	printf("%d %d\n",result1,result2 );


}