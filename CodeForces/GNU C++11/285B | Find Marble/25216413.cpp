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
#include<iterator>
#include<set>
using namespace std;
typedef long long int ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
main()
{
    optimize();
    int n,s,t,i,p,cnt=0;
    int a[100100];
    memset(a,0,sizeof a);
    bool vi[100100];
    memset(vi,0,sizeof vi);
    cin>>n>>s>>t;
    for(i=1;i<=n;i++)
    {
        cin>>p;
        a[i]=p;
    }
    while(s!=t)
    {
        p=s;
        if(vi[s]==1)
        {
            cout<<-1<<endl;
            return 0;
        }
        vi[s]=1;
        s=a[s];
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
 