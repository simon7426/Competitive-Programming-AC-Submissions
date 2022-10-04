#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<cstdio>
typedef long long int ll;
using namespace std;
main()
{
    //freopen("input.txt","r",stdin);
    ll n,i,t,cnt=0;
    string s;
    cin>>n;
    map<ll,ll> a;
    map<ll,ll>::iterator it;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        if(s=="insert")
        {
            a[t]++;
            cnt++;
        }
        else
        {
            if(a[t]>1){
                a[t]--;cnt--;}
            else
            {
                if(a[t]!=0)
                    cnt--;
                a.erase(t);
            }
        }
        //cout<<a.size()<<" "<<cnt<<" ";
        it=a.begin();
        if(a.empty())
            cout<<"neither"<<endl;
        else if(a.size()==1)
        {
            if(it->second>1)
                cout<<"homo"<<endl;
            else
                cout<<"neither"<<endl;
        }
        else if(a.size()==cnt)
        {
            cout<<"hetero"<<endl;
        }
        else
            cout<<"both"<<endl;
    }
    return 0;
}
