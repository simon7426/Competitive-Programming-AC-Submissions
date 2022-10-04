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
    int si,n=0,k,i=0,t=0,cnt=0;
    string s;
    cin>>s>>k;
    reverse(s.begin(),s.end());
    si=s.size();
    while(t!=k)
    {
        if(i>=si)
            break;
        if(s[i]=='0')
        {
            t++;
        }
        else
            n++;
        i++;
    }
    if(t==k)
        cout<<n<<endl;
    else
    {
            cout<<si-1<<endl;
    }
}