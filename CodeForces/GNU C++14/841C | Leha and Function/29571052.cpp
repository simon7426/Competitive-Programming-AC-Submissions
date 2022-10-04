#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[200010],ans[200010];
pair<int,int> p[200010];
struct great
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
main()
{
    optimize();
    int n,m,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>t;
        p[i]=make_pair(t,i);
    }
    sort(a,a+n,great());
    sort(p,p+n);
    pair<int,int> x;
    for(i=0;i<n;i++)
    {
        x=p[i];
        ans[x.second]=a[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}