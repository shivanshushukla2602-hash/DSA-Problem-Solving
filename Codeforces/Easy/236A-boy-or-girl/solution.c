#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    scanf("%s" , str);
    int length=strlen(str);
    int count=0;
    for(int i=0;i<length;++i){
        int freq=0;
        for(int j=0;j<i;++j){
            if(str[i]==str[j]){
               freq=1;
               break;
            }
        }
        if(freq==0){
            count++;
        }
    }
    if(count%2==0){
        printf("CHAT WITH HER!");
    }
    else{
        printf("IGNORE HIM!");
    }

    return 0;
}
