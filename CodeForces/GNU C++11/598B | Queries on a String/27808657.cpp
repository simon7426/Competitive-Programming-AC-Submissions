#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    string s;
    int n,l,r,i,t,k;
    cin>>s>>n;
    for(i=0;i<n;i++)
    {
        cin>>l>>r>>k;
        --l,--r;
        k%=(r-l+1);
        rotate(s.begin()+l,s.begin()+r+1-k,s.begin()+r+1);
    }
    cout<<s<<endl;
    return 0;
}