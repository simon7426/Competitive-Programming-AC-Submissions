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
    int n,m,i,j,cnt=0;
    char ch;
    char a[1010][1010];
    map<int,int> r,c;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ch;
            if(ch=='*')
            {
                r[i+1]++;
                c[j+1]++;
                cnt++;
                a[i][j]=1;
            }
            else
                a[i][j]=0;
        }
    }
    //cout<<a[0][0]<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(r[i+1]+c[j+1]-a[i][j]==cnt)
            {
                cout<<"YES\n"<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}