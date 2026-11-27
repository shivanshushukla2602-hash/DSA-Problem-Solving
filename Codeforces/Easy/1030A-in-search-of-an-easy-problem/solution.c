#include <stdio.h>

int main()
{
    int n;
    scanf("%d" , &n);
    int sum=0;
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d" , &x);
        sum=sum+x;
    }
    if(sum==0){
        printf("easy");
    }
    else{
        printf("hard");
    }

    return 0;
}
