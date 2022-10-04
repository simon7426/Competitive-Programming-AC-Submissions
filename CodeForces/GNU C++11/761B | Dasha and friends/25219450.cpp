#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
typedef long long int ll;
main()
{
   int n,l,s,t,i,j,cnt=0,f;
   deque<int> v1,v2;
   cin>>n>>l;
   cin>>s;
   f=s;
   for(i=1;i<n;i++)
   {
       cin>>t;
       v1.push_back(t-s);
       s=t;
   }
   v1.push_back(f+l-s);
   cin>>s;
   f=s;
   for(i=1;i<n;i++)
   {
       cin>>t;
       v2.push_back(t-s);
       s=t;
   }
   v2.push_back(f+l-s);
   bool ff=0;
   while(cnt<=n)
   {
       ff=0;
       for(i=0;i<n;i++)
       {
           if(v1[i]!=v2[i])
             {ff=1;break;}
       }
       if(ff==0)
        break;
       else
       {
           cnt++;
           s=v2[0];
           v2.pop_front();
           v2.push_back(s);
       }
   }
  // for(i=0;i<n;i++)
 //   cout<<v1[i]<<" "<<v2[i]<<endl;
//    cout<<cnt<<endl;
   if(ff==0)cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;
}