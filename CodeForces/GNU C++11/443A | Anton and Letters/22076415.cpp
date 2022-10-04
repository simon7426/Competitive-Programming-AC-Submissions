#include<iostream>
#include<string>
using namespace std;
main()
{
    int i,j,k,l;
    string a,b,tmp;
    getline(cin,a);
    for(auto &c: a)
        if(isalpha(c))
        b+=c;
    l=b.size();
    for(i=0;i<l;i++)
    {
        for (j=i+1;j<l;j++)
            {
                if(b[i]==b[j])
                {
                    for(k=j;k<l;k++)
                    {
                        b[k]=b[k+1];
                    }
                    l--;
                    j--;
                }
            }
    }
    cout<<l<<endl;
    return 0;
}