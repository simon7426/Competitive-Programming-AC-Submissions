#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
main()
{
    int n,m,t,i,j;
    cin>>n;
    vector<int> a,b;
    for(i=0;i<n;i++)
        {
            cin>>t;
            a.push_back(t);
        }
    sort(a.begin(),a.end());
    cin>>m;
    for(i=0;i<m;i++)
        {
             cin>>t;
            b.push_back(t);
        }
    sort(b.begin(),b.end());
    int cnt=0;
    i=j=0;
    //cout<<n<<m<<endl;
    while(i<n&&j<m)
    {
        //cout<<a[i]-b[j]<<endl;
        if(abs(a[i]-b[j])<=1)
        {
            cnt++;
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else
            j++;
       // cout<<i<<j<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}