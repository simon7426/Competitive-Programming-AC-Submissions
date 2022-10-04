#include<iostream>
using namespace std;
int cnt=0;
void solve(int n,int k)
{
    if(n>k)return;
    if(n<=k)cnt++;
    solve(n*10,k);
    solve(n*10+1,k);
}
main()
{
    int k;
    cin>>k;
    solve(1,k);
    cout<<cnt<<endl;
    return 0;
}