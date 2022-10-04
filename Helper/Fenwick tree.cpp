#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define lsb(x) ( x & (-x) )
vi ft,a;
int n;
void Ftree(int n)
{
    ft.assign(n+2,0);
}
int rsq(int b)
{
    int sum=0;
    for(;b;b-=lsb(b))
    {
        sum+=ft[b];
    }
    return sum;
}
int rsq(int l,int r)
{
    return rsq(r) - ( (l==1)? 0: rsq(l-1));
}
void update(int b,int x)
{
    for(;b<=n;b+=lsb(b))
        ft[b]+=x;
}
main()
{
    int i,t;
    cin>>n;
    Ftree(n);
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
        update(i+1,t);
    }
    int q,l,r;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l>>r;
            update(l,r-a[l-1]);
            a[l-1]=r;
        }
        else if(t==2)
        {
            cin>>l>>r;
            cout<<rsq(l,r)<<endl;
        }
    }
    return 0;
}

