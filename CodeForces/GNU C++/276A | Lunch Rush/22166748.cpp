#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,k,i,ta,ti,max,joy;
    cin>>n>>k;
    cin>>ta>>ti;
        if(ti>k)
            max=ta-(ti-k);
        else
            max=ta;
    for(i=1;i<n;i++)
    {
        cin>>ta>>ti;
        if(ti>k)
            joy=ta-(ti-k);
        else
            joy=ta;
        if(joy>max)
            max=joy;
    }
    cout<<max<<endl;
    return 0;
}
 