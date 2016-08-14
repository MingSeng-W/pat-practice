#include "stdio.h"

int threeFindMax(int a, int b, int c){
	return a>b?a>c?a:c:b>c?b:c;
}


int suanfa1(int a[],int n){
	int maxsum=0;

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < count; ++k)
		{
			int thissum=0;

			for (int j = i; j < k; ++j) {
					thissum+=a[i];
			 }
			 if (thissum>maxsum)
			 {
			 	maxsum=thissum;
			 }
		}
	}
	return maxsum;
}