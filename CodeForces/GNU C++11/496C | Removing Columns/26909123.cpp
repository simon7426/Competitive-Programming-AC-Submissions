#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    string s[105];
    int n,m,i,j,k,cnt=0,f=0,c[105];
    memset(c,0,sizeof c);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(i=0;i<m;i++)
    {
        f=0;
        for(j=1;j<n;j++)
        {
            if(c[j]!=-1&&s[j][i]<s[j-1][i])
            {
                cnt++;
                f=1;
                break;
            }
        }
        if(f) continue;
        for(j=1;j<n;j++)
            if(s[j][i]>s[j-1][i])c[j]=-1;
    }
    cout<<cnt<<endl;
}