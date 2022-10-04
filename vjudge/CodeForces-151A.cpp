#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int t,q,r,s;
    t=(k*l)/nl;
    q=c*d;
    r=p/np;
    s=min(t,min(q,r));
    cout<<s/n<<endl;
    return 0;

}
