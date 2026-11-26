#include <stdio.h>
#include <string.h>

int main()
{
    int n,h;
    scanf("%d %d" , &n,&h);
    int width=0;
    for(int i=0;i<n;++i){
        int num;
        scanf("%d" , &num);
        if(num>h){
            width=width+2;
        }
        else{
            width++;
        }
    }
    printf("%d" , width);

    return 0;
}
