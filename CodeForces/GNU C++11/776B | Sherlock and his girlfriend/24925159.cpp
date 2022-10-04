#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
using namespace std;
typedef long long int ll;
main()
{
    int n,i,j;
    cin>>n;
    bool a[n+2];
    memset(a,true,sizeof a);
    for(i=2;i*i<=n+2;i++)
    {
        if(a[i]==true)
        for(j=i*2;j<=n+2;j+=i)
            a[j]=false;
    }
    if(n>2)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
    for(i=2;i<=n+1;i++)
    {
        if(a[i]==true)
            cout<<1<<" ";
        else
            cout<<2<<" ";
    }
    return 0;
}