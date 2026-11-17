#include <stdio.h>
#include <string.h>

char cap(char ch){
    if(ch>='a' && ch<='z'){
        return ch-32;
    }
    return ch;
}
int main()
{
    char str[1001];
    scanf("%s" , str);
    str[0]=cap(str[0]);
    printf("%s" , str);

    return 0;
}
