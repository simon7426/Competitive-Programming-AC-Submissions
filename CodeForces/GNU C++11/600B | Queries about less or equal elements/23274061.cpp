#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int i,a,b,t;
    cin>>a>>b;
    int arr[a];
    for(i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+a);
    for(i=0;i<b;i++)
    {
        cin>>t;
        cout<<(int)(upper_bound(arr,arr+a,t)-arr)<<" ";
    }
    return 0;
}