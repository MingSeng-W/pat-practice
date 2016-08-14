#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		int b;
		scanf("%d",&b);
		a[i]=b;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
