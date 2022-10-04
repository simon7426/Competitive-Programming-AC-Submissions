#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
string s,t;
int b[5050],n,m,f[5050],k=0;
 
void prekmp()
{
    int i=0,j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0&&t[i]!=t[j]) j=b[j];
        i++,j++;
        b[i]=j;
    }
}
void kmp()
{
    prekmp();
    int i=0,j=0;
    memset(f,0,sizeof f);
    while(i<n)
    {
        while(j>=0&&s[i]!=t[j]) j=b[j];
        i++,j++;
        if(j==m)
        {
            f[i-j]=++k;
            j=b[j];
        }
    }
}
 
 
main()
{
    cin>>s;
    t="bear";
    n=s.size();
    m=t.size();
    kmp();
    int cnt=0;
    if(k==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int p=-1;
    for(int i=0;i<n;i++)
    {
        if(f[i]!=0)
        {
            cnt+=n-i-3;
            cnt+=(i-p-1)*(n-i-3);
            p=i;
        }
    }
    cout<<cnt<<endl;
}
 