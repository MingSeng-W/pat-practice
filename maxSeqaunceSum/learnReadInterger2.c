#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n;
	int i=0;
	int v;
	int k;
	scanf("%d",&n);
	int a[n];
	while(1) {
		k=scanf("%d",&v);
		if (k==1)
		{
			a[i]=v;
			i++;
			if (i>=n)
			{
				break;
			}
		}else if (k==0)
		{
			scanf("%*c");
		}else{//eof
			break;
		}
	  

	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}