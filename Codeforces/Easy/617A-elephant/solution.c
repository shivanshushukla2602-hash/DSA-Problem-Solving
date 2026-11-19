#include <stdio.h>

int main()
{
     int n;
     scanf("%d" , &n);
     int rem;
     int count=0;
         if(n<5){
         printf("1");
         return 0;
         }
         else{
             rem=n%5;
             count=count+n/5;
             if(rem<5 && rem!=0){
                count=count+1;
             }
         }
         printf("%d" , count);
     
    return 0;
}
