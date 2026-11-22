#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d %d" , &n,&k);
    int count=0;
    while(count<k){
        if(n%10!=0){
            n=n-1;
            count++;
        }
        else{
            n=n/10;
            count++;
        }
    }
    printf("%d" , n);
     
    return 0;
}
