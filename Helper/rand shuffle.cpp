#include<bits/stdc++.h>
using namespace std;
main()
{
    vector<int> v;
    int n,i,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    srand(time(0));
    random_shuffle(v.begin(),v.end());
    for(i=0;i<n;i++)
        cout<<v[i]<<" ";
}
