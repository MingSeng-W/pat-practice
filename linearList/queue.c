// 2.3循环队列的实现

#include "stdio.h"
#include "stdlib.h"
typedef int Postion;
typedef int ElemtType;
struct Qnode
{
	Postion front;
	Postion rear;
	ElemtType *data;
	int maxsize;
};
typedef struct Qnode *Queue;
//创建循环队列
Queue createQueue(int maxsize){
	Queue q;
	q=(Queue)malloc(sizeof(struct Qnode));
	q->data=(ElemtType*)malloc(maxsize*sizeof(ElemtType));
	q->front=0;
	q->rear=0;
	q->maxsize=maxsize;
	return q;
}

//判空

bool IsEmpty(Queue q){
	return (q->rear==q->front);

}
//判满
bool IsFull(Queue q){
return((q->rear+1)%q->maxsize==q->front);


}
//入队
bool AddQ(Queue q,ElemtType x){
	if (IsFull(q))
	{
		printf("%s\n", "队列已满");
		return false;
	}else{
		q->rear=(q->rear+1)%q->maxsize;
		q->data[q->rear]=x;
		return true;
	}

}
//出队

ElemtType Delete(Queue q){
	ElemtType tmp;
		if (IsEmpty(q))
		{
			printf("%s\n","队列为空" );
			return NULL;
		}else{
			
			
			q->front=(q->front+1)%q->maxsize;
			tmp=q->data[q->front];
			return tmp;

		}
}

int main(int argc, char const *argv[])
{
	
	Queue q=createQueue(100);
	printf("%d\n",IsFull(q));
	printf("%d\n",IsEmpty(q));
	AddQ(q,20);
	AddQ(q,30);
	AddQ(q,40);
	AddQ(q,50);
	AddQ(q,60);

	

	while(!IsEmpty(q)) {
	    printf("%d\n", Delete(q));
	}


	return 0;
}

