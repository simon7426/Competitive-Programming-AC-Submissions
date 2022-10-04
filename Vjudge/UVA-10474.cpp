#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
    int n,m,t,k=0,i;
    vector<int> v;
    while(cin>>n>>m)
    {
        ++k;
        if(n==0&&m==0)
            break;
        else
        {
            for(i=0;i<n;i++)
            {
                cin>>t;
                v.push_back(t);
            }
            sort(v.begin(),v.end());
            vector<int>::iterator lo;
            cout<<"CASE# "<<k<<":"<<endl;
            for(i=0;i<m;i++)
            {
                cin>>t;
                if(binary_search(v.begin(),v.end(),t))
                {
                    lo=lower_bound(v.begin(),v.end(),t);
                    int x=lo-v.begin();
                    cout<<t<<" found at "<<x+1<<endl;
                }
                else
                    cout<<t<<" not found"<<endl;
            }
            v.erase(v.begin(),v.end());
        }
    }
    return 0;
}
