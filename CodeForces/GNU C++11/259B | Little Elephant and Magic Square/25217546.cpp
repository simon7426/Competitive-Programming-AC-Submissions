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
    ll a[3][3],i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cin>>a[i][j];
    }
    k=a[0][1]+a[0][2]+a[1][0]+a[1][2]+a[2][0]+a[2][1];
    k/=2;
    a[0][0]=k-(a[0][1]+a[0][2]);
    a[1][1]=k-(a[1][0]+a[1][2]);
    a[2][2]=k-(a[2][0]+a[2][1]);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}