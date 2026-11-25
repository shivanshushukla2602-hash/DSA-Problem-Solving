#include <stdio.h>
#include <string.h>

int main()
{
    char s[101];
    char t[101];
    scanf("%s %s" , s , t);
    int length1=strlen(s);
    int length2=strlen(t);
    if(length1!=length2){
        printf("NO");
        return 0;
    }
    for(int i=0;i<length1;++i){
        if(s[i]!=t[length1-i-1]){
              printf("NO");
              return 0;
        }
    }
    printf("YES");

    return 0;
}
