#include "stdio.h"


int findMax(int a[],int n){
	int thisSum=0;
	int MaxSum=0;
	for (int i = 0; i < n; ++i)
	{
		thisSum+=a[i];
		if (thisSum>MaxSum)
		{
			MaxSum=thisSum;
		}else if(thisSum<0){
			thisSum=0;
		}
	}
	return MaxSum;

}


int main(int argc, char const *argv[])

{
	int n;
	int b;
	int i;
	printf("%s\n","请输入整数:");
	scanf("%d",&n);
	printf("%d\n", n);
	int a[n];

	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		
		
	}
	for ( i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
	b=findMax(a,n);
	
	printf("%d\n", b);
	return 0;
}


