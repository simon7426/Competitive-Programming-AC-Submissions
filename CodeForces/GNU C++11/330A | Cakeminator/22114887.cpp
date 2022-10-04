#include<iostream>
#include<set>
using namespace std;
main()
{
    int a,b,i,j;
    char s;
    set<int> r,c;
    cin>>a>>b;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            cin>>s;
            if(s=='S')
            {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    cout<<(a*b)-(r.size()*c.size())<<endl;
    return 0;
}