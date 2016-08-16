#include "stdio.h"
#include "stdlib.h"
struct PolyNode
{
	int coef;//指数
	int expon;
	struct PolyNode *link;
	
};

typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

Polynomial Addition(Polynomial P1,Polynomial P2){
	Polynomial tmp,front,rear;
	rear=(Polynomial)malloc(sizeof(PolyNode));
	int sum;
	front=rear;
	while(P1&&P2) {
	   switch(Compare(P1->expon,P2->expon)){
	   	case 1:
	   			Attach(P1->coef,P1->expon,&rear);
	   			P1=P1->link;
	   	case -1:
	   		   	Attach(P2->coef,P2->expon,&rear);
	   			P2=P2->link;

	   	case 0:
	   			sum=P1->coef+P2->coef;
	   			if (sum!=0)
	   			{
	   				Attach(sum,P1->expon,&rear);	
	   			}
	   			P1=P1->link;
	   			P2=P2->link;

	   }
	}

	for(;P1;P1=P1->link)Attach(P1->coef,P1->expon,&rear);
	for(;P2;P2=P2->link)Attach(P2->coef,P2->expon,&rear);
	tmp=front;
	front=front->link;
	free(tmp);
	return front;
}
int Compare(int a,int b){
	if (a>b)
	{
		return 1;
	}else if (a<b)
	{
		return -1;
	}else{
		return 0;
	}
}

void Attach(int coef,int expon,Polynomial pRear){
	Polynomial p;
	p=(Polynomial)malloc(sizeof(struct PolyNode));
	p->coef=coef;
	p->expon=expon;
	(*pRear)->link=p;
	(*pRear)=p;
}




int main(int argc, char const *argv[])
{
	
	return 0;
}