#include<iostream>
#include<queue>
#include<algorithm>
typedef long long int ll;
using namespace std;
int main()
{
    queue<ll> a,b,c;
    ll n,m,l,i,j,t;
    cin>>n>>m>>l;
    ll sum1=0,sum2=0,sum3=0;
    for(i=0;i<n;i++)
    {
        cin>>t;
        sum1+=t;
        a.push(t);
    }
    for(i=0;i<m;i++)
    {
        cin>>t;
        sum2+=t;
        b.push(t);
    }
    for(i=0;i<l;i++)
    {
        cin>>t;
        sum3+=t;
        c.push(t);
    }

    while(a.size()!=0&&b.size()!=0&&c.size()!=0)
    {
        //cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
        if(sum1==sum2&&sum2==sum3)
            break;
        else{
        if(sum1<sum2&&sum1<sum3)
        {
            sum2-=b.front();
            b.pop();
            sum3-=c.front();
            c.pop();
        }
        else if(sum2<sum3&&sum2<sum1)
        {
            sum1-=a.front();
            a.pop();
            sum3-=c.front();
            c.pop();
        }
        else if(sum3<sum2&&sum3<sum1)
        {
            sum1-=a.front();
            a.pop();
            sum2-=b.front();
            b.pop();
        }
        else if(sum1==sum2)
        {
            sum3-=c.front();
            c.pop();
        }
        else if(sum3==sum2)
        {
            sum1-=a.front();
            a.pop();
        }
        else if(sum3==sum1)
        {
            sum2-=b.front();
            b.pop();
        }}
    }
    cout<<min(sum1,min(sum2,sum3))<<endl;
    return 0;
}
