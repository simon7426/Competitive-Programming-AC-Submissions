#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
    int n,s,a,b,i,j;
    cin>>n>>s;
    if(n==1&&s<10)
    {
        cout<<s<<" "<<s;
        return 0;
    }
    if(s==0)
    {
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    a=n;b=s;
    vector<char> mi,ma;
    while(a--)
    {
        //cout<<b<<endl;
        if(b>9)
        {
            ma.push_back('9');
            b-=9;
        }
        else if(b>0&&b<10)
        {
            ma.push_back(48+b);
            b=0;
        }
        else
            ma.push_back('0');
    }
    if(b!=0)
    {
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    mi=ma;
    reverse(mi.begin(),mi.end());
    if(mi[0]=='0')
    {
        mi[0]='1';
        for(i=1;i<mi.size();i++)
        {
            if(mi[i]!='0')
            {
                mi[i]=mi[i]-1;
                break;
            }
        }
    }
    for(auto it:mi)
        cout<<it;
        cout<<" ";
    for(auto it:ma)
        cout<<it;
    return 0;
}