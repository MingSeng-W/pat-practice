#include "stdio.h"


int max3(int a,int b,int c){
	return a>b?a>c?a:c:b>c?b:c;
}


int DivideAndConquer(int a[],int left,int right){
	int center,i;
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRigthBorderSum;
	int LeftBorderSum,rightBorderSum;

	//"分的结束条件"
	if (left==right)
	{
		if (a[left]>0)
		{
			return a[left];
		}else{
			return 0;
		}
	}
	center=(left+right)/2;
	MaxLeftSum=DivideAndConquer(a,left,center);
	MaxRightSum=DivideAndConquer(a,center+1,right);
//开始"治"

//左边开始扫描	
	LeftBorderSum=0;MaxLeftBorderSum=0;
	for ( i = center; i >=left; i--)
	{
		LeftBorderSum+=a[i];
		if (LeftBorderSum>MaxLeftBorderSum)
		{
			MaxLeftBorderSum=LeftBorderSum;
		}
	}
//右边开始扫描
	rightBorderSum=0;MaxRigthBorderSum=0;
	for ( i = center+1; i <=right ; ++i)
	{
		rightBorderSum+=a[i];
		if (rightBorderSum>MaxRigthBorderSum)
		{
			MaxRigthBorderSum=rightBorderSum;
		}
	}

	return max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRigthBorderSum);
}



int getResult(int a[],int n){
	
	return DivideAndConquer(a,0,n-1);

}


int main(int argc, char const *argv[])
{
	int b;
	int c=100000000;
	int a[]={23,-24,646,25,-244,-53,-756,-35,4325,-435,75,-979,543};
	do{
		
		if (c==1)
		{
			b=getResult(a,13);
		}else{
			getResult(a,13);
		}
		c--;
	}while(c>0);
	
	printf("%d\n", b);
	return 0;
	
}