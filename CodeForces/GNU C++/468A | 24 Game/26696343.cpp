#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n;
    cin>>n;
    if(n<=3)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int x=24;
    if(n&1)
    {
        cout<<2<<" - "<<1<<" = "<<1<<endl;
        cout<<1<<" + "<<3<<" = "<<4<<endl;
        cout<<4<<" * "<<5<<" = "<<20<<endl;
        cout<<4<<" + "<<20<<" = "<<24<<endl;
        for(int i=6;i<n;i+=2)
        {
            cout<<i+1<<" - "<<i<<" = "<<1<<endl;
            cout<<24<<" * "<<1<<" = "<<24<<endl;
        }
    }
    else
    {
        cout<<1<<" * "<<2<<" = "<<2<<endl;
        cout<<2<<" * "<<3<<" = "<<6<<endl;
        cout<<6<<" * "<<4<<" = "<<24<<endl;
        //cout<<4<<" + "<<20<<" = "<<24<<endl;
        for(int i=5;i<n;i+=2)
        {
            cout<<i+1<<" - "<<i<<" = "<<1<<endl;
            cout<<24<<" * "<<1<<" = "<<24<<endl;
        }
    }
    return 0;
}