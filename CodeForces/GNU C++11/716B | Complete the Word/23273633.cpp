#include<iostream>
#include<string>
#include<vector>
using namespace std;
main()
{
    bool f=false;
    vector<int> a;
    string s;
    int n,i,j,cnt,qm;
    cin>>s;
    n=s.size();
    //cout<<n<<endl;
    for(i=0;i<=n-26;i++)
    {
        a.clear();
        for(int k=0;k<26;k++)
            a.push_back(0);
        cnt=0;
        qm=0;
        for(j=i;j<i+26;j++)
        {
        if(s[j]=='?')
            qm++;
        else if(a[s[j]-65]==1)
        {
            a[s[j]-65]=1;
        }
        else{
            a[s[j]-65]=1;
            cnt++;}
        }
        //cout<<cnt+qm<<endl;
        if(cnt+qm==26)
        {
            f=true;
            for(j=i;j<i+26;j++)
            {
                if(s[j]=='?')
                {
                    for(int k=0;k<26;k++)
                    {
                        if(a[k]==0)
                        {
                            s[j]=65+k;
                            a[k]=1;
                            break;
                        }
                    }
                }
            }
        }
 
    }
    if(f==false)
        cout<<-1<<endl;
    else
    {
        for(i=0;i<n;i++)
        {
            if(s[i]=='?')
                s[i]='A';
            cout<<s[i];
        }
    }
    return 0;
 
}