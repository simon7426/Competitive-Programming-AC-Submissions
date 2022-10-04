#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int m;
    m=min(a,min(b/2,c/4));
    cout<<m+m*2+m*4<<endl;
    return 0;
}