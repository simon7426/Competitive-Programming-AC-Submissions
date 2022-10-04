#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
main()
{
    string s;
    cin>>s;
    int i,n=s.size();
    map<char,int> a;
    a['B']=0;
    a['u']=0;
    a['l']=0;
    a['b']=0;
    a['a']=0;
    a['s']=0;
    a['r']=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='B')
            a[s[i]]++;
        else if(s[i]=='u')
            a[s[i]]++;
        else if(s[i]=='l')
            a[s[i]]++;
        else if(s[i]=='b')
            a[s[i]]++;
        else if(s[i]=='a')
            a[s[i]]++;
        else if(s[i]=='s')
            a[s[i]]++;
        else if(s[i]=='r')
            a[s[i]]++;
    }
    a['u']/=2;
    a['a']/=2;
    map<char,int>::iterator it;
    vector<int> v;
    for(it=a.begin();it!=a.end();it++)
        {v.push_back(it->second);}
    sort(v.begin(),v.end());
    cout<<v[0]<<endl;
    return 0;
}