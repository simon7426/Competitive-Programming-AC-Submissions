#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<set>
typedef long long int ll;
using namespace std;
struct fri
{
    int cn;
    int bn;
    int p1;
    int p2;
    int p3;
    int p4;
    bool operator<(const fri& b) const
    {
        if(cn==b.cn)
    {
        if(bn==b.bn)
        {
            if(p1==b.p1)
            {
                if(p2==b.p2)
                {
                    if(p3==b.p3)
                    {
                        return p4<b.p4;
                    }
                    return p3<b.p3;
                }
               return p2<b.p2;
            }
            return p1<b.p1;
        }
        return bn<b.bn;
    }
    return cn<b.cn;
    }
    bool operator==(const fri& b) const
    {
        if(b.cn==cn&&b.bn==bn&&b.p1==p1&&b.p2==p2&&b.p3==p1&&b.p4==p4)
            return true;
        else
            return false;
    }
};
main()
{
    //freopen("input.txt","r",stdin);
    int t,i,j;
    cin>>t;
    for(j=0;j<t;j++)
    {
    int n,p,q,r,c,t,u,cnt=0;
    cin>>n;
    vector<fri> a;
    map<fri,int> b;
    for(i=0;i<n;i++)
    {
        cin>>p>>q>>r>>c>>t>>u;
        a.push_back(fri());
        a[i].cn=p;
        a[i].bn=q;
        a[i].p1=r;
        a[i].p2=c;
        a[i].p3=t;
        a[i].p4=u;
        b[a[i]]++;}
    //sort(a.begin(),a.end());
    set<fri> s(a.begin(),a.end());
    set<fri>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        printf("%02d %08d %04d %04d %04d %04d ",it->cn,it->bn,it->p1,it->p2,it->p3,it->p4);
        cout<<b[*it]<<endl;
    }
    cout<<endl;
        getchar();
    }
    return 0;
}
