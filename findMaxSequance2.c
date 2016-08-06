#include "stdio.h"
int findMax(int a[],int n){
	int thisMax,maxNum=0;
	for (int i = 0; i < n; ++i)
	{
		thisMax=0;
		for (int k = i; k < n; ++k)
		{
			thisMax+=a[i];
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
	int b;
	int c=1000000;
	int a[]={23,-24,646,25,-244,-53,-756,-35,4325,-435,75,-979,543};
	do{
		
		if (c==1)
		{
			b=findMax(a,13);
		}else{
			findMax(a,13);
		}
		c--;
	}while(c>0);
	
	printf("%d\n", b);
	return 0;

}