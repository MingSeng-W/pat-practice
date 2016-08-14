#include "stdio.h"

int threeFindMax(int a, int b, int c){
	return a>b?a>c?a:c:b>c?b:c;
}

int findmax(int a[],int left,int right){
	int maxleftsum=0;
	int maxrightSum=0;
	int maxleftbordersum=0;
	int maxrightborderSum=0;
	int leftBorderSum=0;
	int rightBorderSum=0;


	if (left==right)
	{
		if (a[left]>0)
		{
			return a[left];
		}else{
			return 0;
		}
	}
	int center=(left+right)/2;


	maxleftsum=findmax(a,left,center);
	maxleftsum=findmax(a,center+1,right);

	for (int i = center; i >=left; i--)
	{
		leftBorderSum+=a[i];
		if (leftBorderSum>maxleftbordersum)
		{
			maxleftbordersum=leftBorderSum;
		}
	}
	for (int i = center+1; i <=right; ++i)
	{
		rightBorderSum+=a[i]
		if (rightBorderSum>maxrightborderSum)
		{
			maxrightborderSum=rightBorderSum
		}
	}

	return threeFindMax(maxleftsum,maxrightSum,maxleftbordersum+maxrightborderSum);

}

int jiekou(int a[],int n){
	maxsum=findmax(a[],0,n-1);
	return maxsum;

}