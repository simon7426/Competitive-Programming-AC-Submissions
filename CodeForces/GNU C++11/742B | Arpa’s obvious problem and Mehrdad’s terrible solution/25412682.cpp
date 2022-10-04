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
typedef pair<int,int> pii;
typedef vector<pair<int,pii> > viii;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    map<int,int> a;
    ll n,x,i,t,cnt=0;
    cin>>n>>x;
    int v[n];
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        a[v[i]]++;
    }
    for(i=0;i<n;i++)
    {
        a[v[i]]--;
        t=v[i]^x;
        cnt+=a[t];
    }
    cout<<cnt<<endl;
    return 0;
}