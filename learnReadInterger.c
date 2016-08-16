#include <stdio.h>
int main(){
    int num;
    int i=0;
    int arr[10];
    for (int i = 0; i < 10; ++i)
    {
      arr[i]=0;
    }
   while(1){
        scanf("%d",&num);
        char c=getchar();
        arr[i++]=num;
        if(c=='\n'){
            break;
        }
   }
   for(int i=0;i<10;i++){
    printf("%d\n",arr[i]);
   }
  return 0;
}