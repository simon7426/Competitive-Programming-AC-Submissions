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
//typedefs
typedef long long int ll;
typedef vector<int> vi;
main()
{
    int a[110];
    int n,m,k,i,j,cnt1=0,cnt2=0;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=m-2;i>=0;i--)
    {
        cnt1++;
        if(a[i]!=0&&a[i]<=k)
            break;
        if(i==0) cnt1=0;
    }
    for(i=m;i<n;i++)
    {
        cnt2++;
        if(a[i]!=0&&a[i]<=k)
            break;
        if(i==n-1) cnt2=0;
    }
    //cout<<cnt1<<" "<<cnt2<<endl;
    if(cnt1==0&&cnt2!=0) cout<<cnt2*10<<endl;
    else if(cnt2==0&&cnt1!=0) cout<<cnt1*10<<endl;
    else cout<<min(cnt1,cnt2)*10<<endl;
    return 0;
}