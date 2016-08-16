#include "stdio.h"
int main(int argc, char const *argv[])
{
		int a[3] ,b[3];
		char c;
		int i=0;
		for (int j = 0; j < 3; ++j)
		{
			a[i]=0;
			b[i]=0;
		}
	while(1) {
	   scanf("%d ",&a[i]);
	   scanf("%d",&b[i]);
	   i++;
	   c=getchar();
	   if(c=='\n'){
	   	break;
	   } 
	   
	}
	for (int k = 0; k < 3; ++k)
	   {
	   		printf("%d\n",a[k]);
	   		printf("%d\n",b[k]);

	   }
	return 0;
}