#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int ma = 3e5+10;
 
pair<int,int> a[ma];
bool com(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
main()
{
    optimize();
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    //for(i=0;i<n;i++)
    //    cout<<a[i].first<<" "<<a[i].second<<endl;
    int k=1;
    for(i=1;i<n;i++)
    {
        if(a[i].first<=a[i-1].first) a[i].first=a[i-1].first+1;
    }
    sort(a,a+n,com);
    for(i=0;i<n;i++)
        cout<<a[i].first<<" ";
    cout<<endl;
}