#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    int t;
    scanf("%d",&t);
    int h1,m1;
    h1=t/60;
    m1=t%60;
    if(m+m1>=60) h1++;
    m=(m1+m)%60;
    h=(h1+h)%24;
    printf("%02d:%02d\n",h,m);
}