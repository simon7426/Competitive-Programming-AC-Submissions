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
    string a,b,s,t;
    int n,i,j,ma=0,mi=0;
    cin>>n;
    cin>>a>>b;
    s=a;
    t=b;
    sort(t.begin(),t.end());
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[j]!='.')
            {
                if(s[i]<t[j])
                {
                    ma++;
                    t[j]='.';
                    break;
                }
            }
        }
    }
    s=a;
    t=b;
    sort(t.begin(),t.end());
    //cout<<s<<" "<<t<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[j]!='a')
            {
                if(s[i]<=t[j])
                {
                    //cout<<s[i]<<" "<<t[j]<<endl;
                    mi++;
                    t[j]='a';
                    break;
                }
            }
        }
    }
    cout<<n-mi<<"\n"<<ma<<endl;
    return 0;
}