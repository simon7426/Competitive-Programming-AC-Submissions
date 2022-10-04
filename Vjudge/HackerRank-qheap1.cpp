#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n,i,t,m;
    set<int> a;
    set<int>::iterator it;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        if(m==1)
        {
            cin>>t;
            a.insert(t);
        }
        else if(m==2)
        {
            cin>>t;
            a.erase(t);
        }
        else{it=a.begin();
            cout<<*it<<endl;
        }
    }
    return 0;
}
