#include <stdio.h>
#include <string.h>

char changeToUpper(char ch){
    if(ch>='a' && ch<='z'){
        return ch-32;
    }
    return ch;
} 
char changeToLower(char ch){
    if(ch>='A' && ch<='Z'){
        return ch+32;
    }
    return ch;
} 
int main()
{
    char str[101];
    scanf("%s" , str);
    int upCount=0;
    int lowCount=0;
    int length=strlen(str);
    for(int i=0;i<length;++i){
        if(str[i]>='a' && str[i]<='z'){
            lowCount++;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            upCount++;
        }
    }
    for(int i=0;i<length;++i){
        if(upCount>lowCount){
            str[i]=changeToUpper(str[i]);
        }
        else{
            str[i]=changeToLower(str[i]);
        }
    }
    printf("%s" , str);
     
    return 0;
}
