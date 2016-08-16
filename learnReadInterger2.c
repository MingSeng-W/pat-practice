// 读入两行数字
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int a[5],b[3];
	int i=0;
	char c;
	while(1) {
	   c=getchar();
	    if (c=='\n')
	    {
	    	break;
	    }
	    a[i]=c-'0';
	    i++;
	}
	for (int i = 0; i < 3; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}