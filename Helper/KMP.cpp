#include<bits/stdc++.h>
using namespace std;

void prekmp(string p,int f[])
{
    int m=p.size(),k;
    f[0]=-1;
    for(int i=1;i<m;i++)
    {
        k=f[i-1];
        while(k>=0)
        {
            if(p[k]==p[i-1])
                break;
            else
                k=f[k];
        }
        f[i]=k+1;
    }
    //for(int i=0;i<m;i++) cout<<f[i]<<" ";
}

bool kmp(string s,string p)
{
    int n=s.size();
    int m=p.size();
    int f[m];
    prekmp(p,f);
    int i=0,k=0;
    while(i<n)
    {
        if(k==-1)
        {
            i++;
            k=0;
        }
        else if(s[i]==p[k])
        {
            i++;
            k++;
            if(k==m)
                return 1;
        }
        else
            k=f[k];
    }
    return 0;
}
main()
{
    string s,p;
    cin>>s>>p;
    if(kmp(s,p))
        cout<<"Matched"<<endl;
    else
        cout<<"Not matched"<<endl;
}
