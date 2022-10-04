#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define PB push_back
bool seive[1010000];
vi prime;
 
void seiveGen(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
            if(!seive[i>>1]) {
                    for(int j = i * i; j < limit; j += i + i) {
                            seive[j>>1] = 1;
                    }
            }
    }
    prime.PB(2);
    for(int i = 3; i < limit; i += 2) {
            if(!seive[i>>1]) prime.PB(i);
    }
}
int main()
{
    seiveGen(100100);
    int n,m,i,j,t;
    vi::iterator x;
    cin>>n>>m;
    int a[n+2][m+2];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
                cin>>t;
                x=lower_bound(prime.begin(),prime.end(),t);
                a[i][j]=(*x)-t;
            }
    }
    int mi,s=0;
    t=0;
    for(i=0;i<m;i++)
    {
        t+=a[0][i];
    }
    mi=t;
    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<m;j++)
        {
            t+=a[i][j];
        }
        mi=min(mi,t);
    }
    for(i=0;i<m;i++)
    {
        t=0;
        for(j=0;j<n;j++)
        {
            t+=a[j][i];
        }
        mi=min(mi,t);
    }
    cout<<mi<<endl;
    return 0;
}