#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int mod=1e9+7;
 
main()
{
  int n=0,i,t=1;
  string s;
  cin>>s;
  for(i=0;s[i];i++)
  {
      if(s[i]=='a') t=(t<<1)%mod;
      else n = (n+t-1)%mod;
  }
  cout<<n<<endl;
  return 0;
}