/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{   int n;
    scanf("%d" , &n);
    int a[n][3];
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            scanf("%d" , &a[i][j]);
        }
    }
    int count=0;
    for(int i=0;i<n;++i){
        int sum=0;
        for(int j=0;j<3;++j){
          sum=sum+a[i][j];
        }
        if(sum>1){
            count++;
        }
    }
    printf("%d" , count);

    return 0;
}
