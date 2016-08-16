//多项式乘法
#include "stdio.h"
#include "stdlib.h"
struct PolyNode
{
	int coef;
	int expon;
	struct PolyNode *link;
}*Polynomial;
void Attach(int ceof,int expon,Polynomial *rear){
	Polynomial tmp;
	tmp=(Polynomial)malloc(sizeof(struct PolyNode));
	tmp->ceof=ceof;
	tmp->expon=expon;
	(*rear)->link=tmp;
	(*rear)=tmp;
}
void PolyRead(Polynomial *rear){
	int total,ceof,expon;
	scanf("%d",&total);
	while(1) {
	   scanf("%d ",&ceof);
	   scanf("%d",&expon);
	   Attach(ceof,expon,&rear);
	   c=getchar();
	   if (c=='\n')
	   {
	   	break;
	   }
	}
}
void createPoly(Polynomial *p){
	Polynomial tmp,rear;
	tmp=(Polynomial)malloc(sizeof(struct PolyNode));
	rear=tmp;
	PolyRead(&rear);
	rear->link=NULL;
	*p=tmp->link;
	free(tmp);
}
int Compare(int a,int b){
	if (a>b)
	{
		return 1;
	}else if (a<b)
	{
		return -1
	}else{
		return 0;
	}
}

Polynomial Addition(Polynomial p1,Polynomial p2){
	Polynomial front,rear;
	front=(Polynomial)malloc(sizeof(struct PolyNode));
	rear=front;
	int sum=0;
	while(p1&&p2) {
	    switch(Compare(p1->expon,p2->expon)){
	    	case 1:
	    		Attach(p1->ceof,p1->expon,&rear);
	    		p1=p1->link
	    		break;
	    	case -1:
	    		Attach(p2->ceof,p2->expon,&rear);
	    		p2=p2->link;
	    		break;
	    	case 0:
	    		sum=p1->ceof+p2->ceof;
	    		if (sum)
	    		{
	    			Attach(sum,p1->ceof,&rear)
	    		}
	    		p1=p1->link;
	    		p2=p2->link
	    		break;
	    }
	}
	for(;p1;p1=p1->link) Attach(p1->ceof,p1->expon,&rear);
	for(;p2;p2=p2->link) Attach(p2->ceof,p2->expon,&rear);
	rear->link=NULL;
	rear=front->link;
	free(front);
	return rear;

}

Polynomial Mutiplytion(Polynomial p1,Polynomial p2){
	Polynomial front,rear,tmp,tmprear;
	front=(Polynomial)malloc(sizeof(struct PolyNode));
	rear=front;
    rear->link=NULL;
	while(p1) {
		tmp=(Polynomial)malloc(sizeof(struct PolyNode));
		tmprear=tmp;
	   while(p2) {
	   	   ceof=p1->ceof*p2->ceof;
	   	   expon=(p1->expon)+(p2->expon);
	   	   Attach(ceof,expon,&tmprear);
	       p2=p2->link;
	   }
	   if (!p2)
	   {
	   	tmprear->link=NULL;
	   	tmprear=tmp;
	   	tmp=tmp->link;
	   	free(tmprear); 	
	   }
	   front=Addition(tmp,front);
	   p1=p1->link;
	}
	rear->link=NULL;
	rear=front->link;
	free(front);
	return front;
}

void myPrint(Polynomial p){
	while(p) {
		printf("%d ", p->ceof);
		printf("%d",p->expon);
	  p=p->link;
	}
	printf("\n");
}








int main(int argc, char const *argv[])
{
	Polynomial p1,p2,addR,MutiR;
	createPoly(&p1);
	createPoly(&p2);
	addR=Addition(p1,p2);
	MutiR=Mutiplytion(p1,p2);
	myPrint(addR);
	myPrint(MutiR);
	return 0;
}
// int main(int argc, char const *argv[])
// {
// 	Polynomial p1,p2,p3;
// 	p1=init();
// 	p2=init();
// 	p3=Addition(p1,p2);
// 	myPrint(p3);

// 	return 0;
// }