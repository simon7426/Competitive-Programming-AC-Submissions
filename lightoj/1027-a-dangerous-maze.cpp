#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    int n,i,t,x,tc,tcc,cp,sum;
    cin>>tcc;
    for(tc=1;tc<=tcc;tc++)
    {
        cp=sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>t;
            if(t>=0) cp++;
            sum+=abs(t);
        }
        x=__gcd(sum,cp);
        cout<<"Case "<<tc<<": ";
        if(cp==0)
        {
            cout<<"inf"<<endl;
        }
        else
            cout<<sum/x<<"/"<<cp/x<<endl;
    }
    return 0;

}
