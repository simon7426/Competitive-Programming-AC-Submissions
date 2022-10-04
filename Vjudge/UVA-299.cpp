#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
int i,j,k,a,n,t,it[100],count;
while(cin>>a)
{
for(k=1;k<=a;k++)
    {
    count=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>it[i];

    for(i=1;i<n;i++)
        for(j=n-1;j>=i;j--)
            if(it[j-1]>it[j])
                {
                count=count+1;
                t=it[j-1];
                it[j-1]=it[j];
                it[j]=t;
                }
    cout<<"Optimal train swapping takes "<<count<< " swaps."<<endl;
    }
}
return 0;
}
