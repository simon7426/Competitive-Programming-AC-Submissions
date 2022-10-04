#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,x,y,z,ma=2,cnt=2;
    cin>>n;
    if(n<=2)
    {
        cout<<n<<endl;
        return 0;
    }
    cin>>x>>y;
    for(i=2;i<n;i++)
    {
        cin>>z;
        if(z==x+y)
        {
            cnt++;
            ma=max(ma,cnt);
        }
        else
        {
            cnt=2;
        }
        x=y;
        y=z;
    }
    cout<<ma<<endl;
}