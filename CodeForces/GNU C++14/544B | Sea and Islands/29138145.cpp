#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,k,t,j;
    cin>>n>>k;
    t=((n*n)/2)+((n*n)&1);
    //cout<<k<<" "<<t<<endl;
    if(k>t)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int cnt=0;
    cout<<"YES"<<endl;
    for(i=0;i<n;i++)
    {
        if(i&1)
        {
            for(j=0;j<n;j++)
            {
                if(!(j&1)) cout<<"S";
                else
                {
                    if(cnt>=k)
                        cout<<"S";
                    else
                    {
                        cout<<"L";
                        cnt++;
                    }
                }
            }
            cout<<endl;
        }
        else
        {
            for(j=0;j<n;j++)
            {
                if(j&1) cout<<"S";
                else
                {
                    if(cnt>=k)
                        cout<<"S";
                    else
                    {
                        cout<<"L";
                        cnt++;
                    }
                }
            }
            cout<<endl;
        }
    }
}