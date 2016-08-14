#include "stdio.h"
int start;
int end;
int findMax(int a[],int n){

	int thisMax,maxNum=0;
	for (int i = 0; i < n; ++i)
	{
		thisMax=0;
		for (int k = i; k < n; ++k)
		{
			thisMax+=a[k];
			if (thisMax>maxNum)
			{
				maxNum=thisMax;
				start=a[i];
				end=a[k];
			}
		}

	}
	return maxNum;
}


int main(int argc, char const *argv[])
{
	int b;
	int c=10000;
	int a[]={-10, 1, 2 ,3, 4 ,-5 ,-23 ,3 ,7 ,-21};
	do{
		
		if (c==1)
		{
			b=findMax(a,10);
		}else{
			findMax(a,10);
		}
		c--;
	}while(c>0);
	
	
	printf("%d\n", b);
	printf("%d\n", start);
	printf("%d\n", end);
	return 0;

}