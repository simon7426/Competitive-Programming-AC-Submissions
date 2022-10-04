#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
 
int a[200010];
string s,t;
int n;
 
bool check(int x)
{
    int i,k=0;
    string str=s;
    for(i=0;i<x;i++)
        str[a[i]-1]='.';
 
    for(i=0;i<n;i++)
    {
        if(str[i]==t[k])
            k++;
    }
    //cout<<x<<" "<<k<<" "<<t.size()<<endl;
    if(k==t.size())
        return true;
    return false;
}
 
main()
{
    optimize();
    int i;
    cin>>s;
    cin>>t;
    n=s.size();
    for(i=0;i<n;i++)
        cin>>a[i];
    int low=0,high=n,mid;
    while(low<high)
    {
        mid=(low+high+1)>>1;
        //cout<<low<<" "<<high<<" "<<mid<<endl;
        if(check(mid))
            low=mid;
        else
            high=mid-1;
    }
    cout<<low<<endl;
    return 0;
}