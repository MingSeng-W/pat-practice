//队列的链表的实现

#include "stdio.h"
#include "stdlib.h"
typedef struct Node *ptrlToNode;
typedef	int ELemtype;
typedef ptrlToNode Posotion;
struct Node{
	ptrlToNode next ;
	ELemtype data;
};
struct QNode{
	Posotion front,rear;
	int maxsize;
};

typedef struct QNode *Queue;

//初始化
Queue createQueue(int maxsize){
	Queue q;
	q=(Queue)malloc(sizeof(struct QNode));
	q->front=q->rear=NULL;
	q->maxsize=maxsize;
	return q;
}
//判空
bool IsEmpty(Queue q){
	return (q->front==NULL);

}
//判满
bool IsFull(Queue q){
	int i;
	ptrlToNode tmp;
	tmp=q->front;
	for ( i = 0;tmp!=q->rear; )
	{
		++i;
		tmp=tmp->next;
		
	}
	if (i==q->maxsize-1)
	{
		printf("%s\n", "队列已经满了");
		return true;
	}else{
		return false;
	}


}
//入队
bool AddQ(Queue q,ELemtype x){
	if (IsFull(q))
	{
		printf("%s\n", "队列已经满了");
		return false;
	}
	ptrlToNode tmp;
	tmp=(ptrlToNode)malloc(sizeof(struct Node));
		tmp->data=x;
	if (q->front==q->rear)
	{
	q->front=q->rear=tmp;

	}else{
	q->rear->next=tmp;
	q->rear=tmp;
	}
	tmp->next=NULL;
	return true;




}
//出队

ELemtype Delete(Queue q){

	if (IsEmpty(q))
	{
		printf("%s\n","队列为空" );
		return NULL;
	}
	ptrlToNode tmp;
	ELemtype tmpdata;
	tmp=q->front;
	if (q->front==q->rear)
	{
		q->front=q->rear=NULL;

	}
	else{
			q->front=tmp->next;
	}
	tmpdata=tmp->data;
	free(tmp);
	return  tmpdata;

}

int main(int argc, char const *argv[])
{
	Queue q;
	q=createQueue(3);
	AddQ(q,30);
	AddQ(q,40);
	AddQ(q,50);

	printf("%d\n",IsFull(q) );
	printf("%d\n",IsEmpty(q) );
	printf("%d\n", Delete(q));
	printf("%d\n", Delete(q));
	printf("%d\n", Delete(q));

	return 0;
}

