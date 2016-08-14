#include "stdio.c"
int findThreeMax(int a,int b,int c){
	return a>b?a>c?a:c:b>c?b:c
}
int findMaxSequance(int a[],int n){
	int maxSum=0;
	int thissum=0;
	for (int i = 0; i < n; ++i)
	{
		thissum+=a[i];
		if (thissum>maxSum)
		{
		maxSum=thissum
		}else if (thissum<0)
		{
		thissum=0;
		}
	}
	return maxSum;
}
