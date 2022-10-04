#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
void swap(char &a,char &b)
{
    char c;
    c=a;
    a=b;
    b=c;
}
main()
{
    optimize();
    string s;
    cin>>s;
    int n,i,l,r,si=s.size();
    int a[si];
    memset(a,0,sizeof a);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>l;
        l-=1;
        a[l]++;
    }
    for(i=1;i<si/2;i++) a[i]+=a[i-1];
    for(i=0;i<si/2;i++)
    {
        if(a[i]&1) swap(s[i],s[si-i-1]);
    }
    cout<<s<<endl;
    return 0;
}