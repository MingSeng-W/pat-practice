//2.2堆栈的顺序实现

#include "stdio.h"
#include "stdlib.h"
#define ERROR -10000
typedef int Postion;
typedef int ElememtType;
struct SNode
{
	ElememtType *data;
	Postion top;
	int maxSize;
};

typedef struct SNode *Stack;


Stack init(int maxSize){
		Stack s;
		s=(Stack)malloc(sizeof(struct SNode));
		s->data=(ElememtType *)malloc(maxSize*sizeof(ElememtType));
		s->top=-1;
		s->maxSize=maxSize;
		return s;

}
bool IsEmpty(Stack S){
	return(S->top==-1);

}
bool IsFull(Stack S){
	return(S->top==(S->maxSize)-1);
}


ElememtType Pop(Stack S){
	if (IsEmpty(S))
	{
		printf("%s\n", "堆栈为空");
		return ERROR;
		
	}else{

		return S->data[(S->top)--];
	}


}

bool Push(Stack S,ElememtType x){
	if (IsFull(S))
	{
		printf("%s\n","堆栈已经满了" );
		return false;
	}else{
		S->data[++(S->top)]=x;
		return true;
	}
}

int main(int argc, char const *argv[])
{		Stack s;

	s=init(100);
	Push(s,2);
	Push(s,3);
	int result1=Pop(s);
	int result2=Pop(s);
	printf("%d %d\n",result1,result2 );
	printf("%d\n", IsEmpty(s));

}

//可执行文件为stack2
	



