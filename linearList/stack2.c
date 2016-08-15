// 2.2
#include "stdio.h"
#include "malloc.h"
#define MAXSIZE 1000

// 堆栈的顺序实现

typedef struct Snode{
	ElemType data[MAXSIZE];
	int top;

}Stack;


int init(Stack s){
	s.top=0;
	return 1
}

int isEmpty(Stack s){
	if (s.top==0)
	{
		return 1
	}else{
		return 0
	}
}

int push(Stack s,ElemType x){
	if (s.top>MAXSIZE-1)
	{
		printf("%s\n","堆栈已经满" );
		return 0
	}else{
		s.top++;
		s.data[s.top]=x;
		return 1;
	}
	
}

ElemType Pop(Stack S){
	s.top--;
	return s.data[s.top+1]
}

int main(int argc, char const *argv[])
{
	init();
	
	return 0;
}




