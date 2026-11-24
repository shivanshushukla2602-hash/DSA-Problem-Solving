#include <stdio.h>

int main()
{
    int n;
    scanf("%d" , &n);
    char str[n+1];
    scanf("%s" , str);
    int dCount=0;
    int aCount=0;
    for(int i=0;i<n;++i){
        if(str[i]=='D'){
            dCount++;
        }
        else if(str[i]=='A'){
            aCount++;
        }
    }
    if(aCount>dCount){
        printf("Anton");
    }
    else if(aCount<dCount){
        printf("Danik");
    }
    else{
        printf("Friendship");
    }
     
    return 0;
}
