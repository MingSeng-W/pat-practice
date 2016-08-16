#include "stdio.h"
#include "stdlib.h"
struct PolyNode
{
	int coef;//指数
	int expon;
	struct PolyNode *link;
	
};

typedef struct PolyNode *Polynomial;


void Attach(int coef,int expon,Polynomial *pRear){
	Polynomial p;
	p=(Polynomial)malloc(sizeof(struct PolyNode));
	p->coef=coef;
	p->expon=expon;
	(*pRear)->link=p;
	(*pRear)=p;
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
Polynomial Addition(Polynomial P1,Polynomial P2){
	Polynomial tmp,front,rear;
	rear=(Polynomial)malloc(sizeof(struct PolyNode));
	int sum;
	front=rear;
	while(P1&&P2) {
	   switch(Compare(P1->expon,P2->expon)){
	   	case 1:
	   			Attach(P1->coef,P1->expon,&rear);
	   			P1=P1->link;
	   			break;
	   	case -1:
	   		   	Attach(P2->coef,P2->expon,&rear);
	   			P2=P2->link;
	   			break;

	   	case 0:
	   			sum=P1->coef+P2->coef;
	   			if (sum)
	   			{
	   				Attach(sum,P1->expon,&rear);	
	   			}
	   			P1=P1->link;
	   			P2=P2->link;
	   			break;

	   }
	}
		while(P1) {
		   Attach(P1->coef,P1->expon,&rear);
		   P1=P1->link;
		}
		while(P2) {
		    Attach(P2->coef,P2->expon,&rear);
		    P2=P2->link;
		}
	rear->link=NULL;
	tmp=front;
	front=front->link;
	free(tmp);
	return front;
}


int AppendNode(int coef,int expon,Polynomial *rear){
	Polynomial tmp;
	tmp=(Polynomial)malloc(sizeof(struct PolyNode));
	tmp->coef=coef;
	tmp->expon=expon;
	(*rear)->link=tmp;
	(*rear)=tmp;
	return 0;
}

Polynomial init(){
	Polynomial tmp,rear;
	tmp=(Polynomial)malloc(sizeof(struct PolyNode));
	rear=tmp;
	int coef,expon;
	int i=0;
	char c;
	int f;
	scanf("%d ",&f);
	while(1) {
		scanf("%d ",&coef);
		scanf("%d",&expon);
		AppendNode(coef,expon,&rear);
		c=getchar();
		if (c=='\n')
		{
			break;
		}
	}
		rear->link=NULL;
		rear=tmp;
		tmp=tmp->link;
		free(rear);
	return tmp;
}

int printTotal(Polynomial p){
	int i;
	for (i = 0; p!=NULL; ++i){
			p=p->link;
	};
	return i;
}


void myPrint(Polynomial p){

	while(p) {
	   	printf("%d\n",p->coef );
		printf("%d\n",p->expon); 
		p=p->link;
	}
	
}



int main(int argc, char const *argv[])
{
	Polynomial p1,p2,p3;
	p1=init();
	p2=init();
	p3=Addition(p1,p2);
	myPrint(p3);

	return 0;
}