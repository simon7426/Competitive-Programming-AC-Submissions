#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll;
int n,a[500050];
 
bool check(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        if(2*a[i]>a[n-x+i])
            return false;
    }
    return true;
}
 
main()
{
    optimize();
    int i,j,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int low=0,high=n/2,mid;
    while(low<high)
    {
        mid=(low+high+1)>>1;
        if(check(mid)) low=mid;
        else high=mid-1;
    }
    cout<<n-low<<endl;
}