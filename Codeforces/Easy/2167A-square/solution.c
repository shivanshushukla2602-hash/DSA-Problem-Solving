#include <stdio.h>

int main()
{
   int t;
   scanf("%d" , &t);
   int a,b,c,d;
   for(int i=1;i<=t;++i){
       scanf("%d %d %d %d" , &a , &b , &c , &d);
       if(a==b && b==c && c==d){
       printf("Yes\n");
   }
   else{
       printf("No\n");
   }
   }

    return 0;
}
