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
main()
{
    int a[5],b[5],cnt=0;
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a[t-1]++;
    }
    for(i=0;i<n;i++)
    {
        cin>>t;
        b[t-1]++;
    }
    for(i=0;i<5;i++)
    {
        if((a[i]+b[i])%2!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(i=0;i<5;i++)
    {
        //cout<<a[i]<<" "<<b[i]<<endl;
        cnt+=abs(a[i]-b[i]);
    }
    cout<<cnt/4<<endl;
    return 0;
}