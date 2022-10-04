#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
main()
{
    //freopen("input.txt","r",stdin);
    int n,m,i,j;
    char ma='1';
    set<int> s;
    cin>>n>>m;
    string a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(j=0;j<m;j++)
    {
        ma=a[0][j];
        for(i=1;i<n;i++)
        {
                if(a[i][j]>ma)
                ma=a[i][j];
                //cout<<ma<<" "<<a[i][j]<<endl;
        }
        for(i=0;i<n;i++)
        {
            if(a[i][j]==ma)
            {
                //cout<<ma<<" "<<i+1<<" "<<j+1<<endl;
                s.insert(i+1);
            }
        }
    }
    cout<<s.size()<<endl;
    //set<int>::iterator it;
    //for(it=s.begin();it!=s.end();it++)
        //cout<<*it<<" ";
    return 0;
}