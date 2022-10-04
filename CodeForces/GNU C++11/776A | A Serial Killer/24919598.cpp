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
    string a,b,c,d;
    cin>>a>>b;
    int n,i,j;
    cin>>n;
    cout<<a<<" "<<b<<endl;
    for(i=0;i<n;i++)
    {
        cin>>c>>d;
        if(c==a)
        {
            cout<<b<<" "<<d<<endl;
            a=d;
        }
        else
        {
            cout<<a<<" "<<d<<endl;
            b=d;
        }
    }
    return 0;
}