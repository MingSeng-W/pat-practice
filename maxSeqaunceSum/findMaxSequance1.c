#include "stdio.h"
int findMaxSequance(int a[],int n){
	int thisMax,maxNum=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			thisMax=0;
			for (int k = i; k < j; ++k)
			{
				thisMax+=a[k];
			}
			if (thisMax>maxNum)
			{
				maxNum=thisMax;
			}
		}
	}
	return maxNum;
}
int main(int argc, char const *argv[])
{
	int b=0;
	int c=100000000;
	int a[]={23,-24,646,25,-244,-53,-756,-35,4325,-435,75,-979,543};
	do{
		
		if (c==1)
		{
			b=findMaxSequance(a,13);
		}else{
			findMaxSequance(a,13);
		}
		c--;
	}while(c>0);
	
	printf("%d\n", b);
	return 0;
}