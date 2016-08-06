#include "stdio.h"
int findMax(int a,int b,int c){

	return a>b?a>c?a:c:b>c?b:c;
}
int main(int argc, char const *argv[])
{
	int a,b,c,ret;
	a=3,b=4,c=5;
	ret=findMax(3,4,5);
	printf("%d\n", ret);
	return 0;
}