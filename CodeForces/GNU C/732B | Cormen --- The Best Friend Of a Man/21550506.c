#include<stdio.h>
main()
{
 int n,k,t,c;
 scanf("%d%d",&n,&k);
 int i;
 int a[n];
 c=0,t=0;
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=0;i<n-1;i++)
 {
  if((a[i]+a[i+1])<k)
  {
  t=(k-(a[i]+a[i+1]));
  a[i+1]+=t;
  c+=t;
  }
 }
 printf("%d\n",c);
 for(i=0;i<n;i++)
 printf("%d ",a[i]);
}