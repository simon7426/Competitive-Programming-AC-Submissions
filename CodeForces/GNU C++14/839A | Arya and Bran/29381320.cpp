#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t,k,ac=0,bc=0;
    string s;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        ac=ac+t;
        if(ac<=8)
        {
 
            bc=bc+ac;
            ac=0;
        }
        else
        {
            bc+=8;
            ac-=8;
        }
        if(bc>=k)
        {
            cout<<i<<endl;
            return 0;
        }
        //cout<<bc<<" "<<ac<<endl;
    }
    cout<<-1<<endl;
    return 0;
}