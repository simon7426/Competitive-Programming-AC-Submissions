#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define d 256
string s,t;
int n,m;
int q=199;
void rabkarp()
{
    int i,j;
    n=s.size();
    m=t.size();
    int x=0,y=0,h=1;
    for(i=0;i<m-1;i++)
    {
        h=(d*h)%q;
    }
    for(i=0;i<m;i++)
    {
        x=(d*x+t[i])%q;
        y=(d*y+s[i])%q;
    }
    for(i=0;i<n-m;i++)
    {
        if(x==y)
        {
            cout<<"hash matched"<<endl;
            for(j=0;j<m;j++)
                if(s[i+j]!=t[j]) break;
            if(j==m) cout<<"match found at "<<i+j<<endl;
        }
        if(i<n-m)
        {
            y=(d*(y-s[i]*h)+s[i+m])%q;
        }
        if(y<0) y+=q;
    }

}
main()
{
    cin>>s>>t;
    rabkarp();
}
