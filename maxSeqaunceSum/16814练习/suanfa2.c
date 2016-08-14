#include "stdio.h"

int threeFindMax(int a, int b, int c){
	return a>b?a>c?a:c:b>c?b:c;
}

int findMax(int a[],int n){
	int maxsum=0;
	for (int i = 0; i < n; ++i)
	{
		int thissum=0;
		for (int k = i; i < n; ++i)
		{
			if (thissum>maxsum)
			{
				maxsum=thissum;
			}
		}
	}
	return maxsum;
}