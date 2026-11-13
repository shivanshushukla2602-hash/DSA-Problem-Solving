#include <stdio.h>
#include <string.h>

int main()
{   int n;
    scanf("%d" , &n);
    int X = 0;
    char s[5];
    for(int i=0;i<n;++i){
        scanf("%s" , s);
        if(strcmp(s , "X++") == 0  || strcmp(s , "++X") == 0){
            X++;
        }
        else{
            X--;
        }
    }
    printf("%d" , X);

    return 0;
}
