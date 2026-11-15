#include <stdio.h>


int toUpperCase(char i){
    int ch = i;
    if(i>=97 && i<=122){
        return i-32;
    }
    else{
        return i;
    }
}
int main()
{
    char str1[101];
    char str2[101];
    scanf("%s" , str1);
    scanf("%s" , str2);
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(toUpperCase(str1[i])-toUpperCase(str2[i])>0){
            printf("1");
            break;
        }
        else if(toUpperCase(str1[i])-toUpperCase(str2[i])<0){
            printf("-1");
            break;
        }
        ++i;
    }
    if(str1[i]=='\0' && str2[i]=='\0'){
            printf("0");
    }
    

    return 0;
}
