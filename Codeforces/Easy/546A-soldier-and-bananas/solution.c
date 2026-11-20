#include <stdio.h>

int main()
{
    int k,n,w;
    scanf("%d %d %d" , &k , &n , &w);
    long long amount=0;
    for(int i=1;i<=w;++i){
        amount=amount+i*k;
    }
    if(amount>n){
        printf("%lld" , amount-n);
    }
    else{
        printf("0");
    }
     
    return 0;
}
