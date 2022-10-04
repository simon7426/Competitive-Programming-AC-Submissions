#include<stdio.h>
int main(){
 
    long long n,k;
    scanf("%I64d %I64d",&n,&k);
    if(n%2==0)
    {
              if(k<n/2+1){printf("%I64d",2*k-1);}
              else{printf("%I64d",2*(k-n/2));}
    }
    if(n%2==1)
    {
              if(k<(n+1)/2+1){printf("%I64d",2*k-1);}
              else{printf("%I64d",2*(k-(n+1)/2));}
    }
    return 0;
}