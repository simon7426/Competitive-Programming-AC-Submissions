#include<bits/stdc++.h>
using namespace std;

//Euler phi for n
int EulerPhi(int n)
{
    int ret=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            ret-=ret/i;
        }
    }
    if(n>1)
        ret-=ret/n;
    return ret;
}

//Euler sieve until N
vector<int> phi;
void phiuptoN(int n)
{
    phi.resize(n+1);
    phi[0]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=n;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<EulerPhi(n)<<endl;
    phiuptoN(n);
    for(auto it:phi)
        cout<<it<<" ";
    cout<<endl;
}
