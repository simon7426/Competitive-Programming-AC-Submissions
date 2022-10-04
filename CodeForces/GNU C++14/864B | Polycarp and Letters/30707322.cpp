#include<bits/stdc++.h>
using namespace std;
int ma=0;
 string s;
 
typedef long long ll;
 
void f(int x,int y)
{
    int i;
    set<char> ss;
    for(i=x;i<y;i++)
        ss.insert(s[i]);
    ma=max(ma,(int)ss.size());
}
main()
{
    int n,l,i,j,t,cnt[205];
    memset(cnt,0,sizeof cnt);
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(isupper(s[i]))
        {
            cnt[i+1]++;
        }
        else ma=1;
    }
    for(i=1;i<205;i++)
        cnt[i]+=cnt[i-1];
    for(i=0;i<n;i++)
    {
        if(isupper(s[i]))
            continue;
        for(j=i+1;j<=n;j++)
        {
            if(isupper(s[j])||s[j]==0)
            {
                f(i,j);
                i=j;
                break;
            }
        }
    }
    cout<<ma<<endl;
}