#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int typ(string s)
{
    int a[6],i;
    a[0]=s[0]-'0';
    a[1]=s[1]-'0';
    a[2]=s[3]-'0';
    a[3]=s[4]-'0';
    a[4]=s[6]-'0';
    a[5]=s[7]-'0';
    int f=0;
    for(i=1;i<6;i++)
    {
        if(a[i]!=a[i-1])
          {
              f=1;
              break;}
    }
    if(f==0)return 1;
    f=0;
    for(i=1;i<6;i++)
    {
        if(a[i]>=a[i-1])
        {
            f=1;
            break;
        }
    }
    if(f==0)return 2;
    return 3;
}
struct fri
{
    string na;
    int ta;
    int pi;
    int gi;
    int no;
};
bool tax(fri a,fri b)
{
    if(a.ta==b.ta)
        return a.no<b.no;
    return a.ta>b.ta;
}
bool piz(fri a,fri b)
{
    if(a.pi==b.pi)
        return a.no<b.no;
    return a.pi>b.pi;
}
bool gir(fri a,fri b)
{
    if(a.gi==b.gi)
        return a.no<b.no;
    return a.gi>b.gi;
}
 
main()
{
    string s;
    int n,m,i,j,k;
    struct fri a[101];
    cin>>n;
    for(i=0;i<n;i++)
    {
        a[i].no=i;
        a[i].ta=a[i].pi=a[i].gi=0;
        cin>>m>>a[i].na;
        for(j=0;j<m;j++)
        {
            cin>>s;
            k=typ(s);
            if(k==1)a[i].ta++;
            else if(k==2)a[i].pi++;
            else a[i].gi++;
        }
    }
    stable_sort(a,a+n,tax);
    cout<<"If you want to call a taxi, you should call: "<<a[0].na;
    for(i=1;i<n;i++)
    {
        if(a[i].ta==a[i-1].ta)
            cout<<", "<<a[i].na;
        else
            break;
    }
    cout<<"."<<endl;
    stable_sort(a,a+n,piz);
    cout<<"If you want to order a pizza, you should call: "<<a[0].na;
    for(i=1;i<n;i++)
    {
        if(a[i].pi==a[i-1].pi)
            cout<<", "<<a[i].na;
        else
            break;
    }
    cout<<"."<<endl;
    stable_sort(a,a+n,gir);
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: "<<a[0].na;
    for(i=1;i<n;i++)
    {
        if(a[i].gi==a[i-1].gi)
            cout<<", "<<a[i].na;
        else
            break;
    }
    cout<<"."<<endl;
    return 0;
}