#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s,t;
 
bool faltu(int x,int y,int n)
{
    int i,j,k;
    //cout<<x<<" "<<y<<" "<<n<<endl;
    for(i=x,j=y,k=1;k<=n;i++,j++,k++) if(s[i]!=t[j])break;
    //else cout<<n<<" "<<k<<" "<<s[i]<<" "<<t[j]<<endl;
    if(k>n) return true;
    if(n&1) return false;
    n >>= 1;
    if(faltu(x,y,n)&&faltu(x+n,y+n,n)) return true;
    if(faltu(x,y+n,n)&&faltu(x+n,y,n)) return true;
    return false;
}
main()
{
    optimize();
    cin>>s>>t;
    int n=s.size();
    if(faltu(0,0,n))
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}