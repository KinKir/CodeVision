#include<stdio.h>
const int max = 100000;
int main()
{
int n;
scanf("%d",&n);
int c[max],d[max],l[max];
for(int i=0;i<n;i++)
scanf("%d %d %d",&c[i],&d[i],&l[i]);
for(int i=0;i<n;i++)
{
if(d[i]<c[i])
{
  if((2*d[i])>=c[i])
  {
   if(l[i]>=(d[i]*4) && l[i]<=((d[i]*4)+(c[i]*4)) && l[i]%4==0)
    printf("yes\n");
   else
    printf("no\n");
  }
 if((2*d[i])<c[i])
 {
  if(l[i]>=((d[i]*4)+((c[i]-(2*d[i]))*4)) && l[i]<=((d[i]*4)+(c[i]*4))  && l[i]%4==0)
   printf("yes\n");
  else
  printf("no\n");
 }
}
else if(d[i]>=c[i])
{
if(l[i]>=(d[i]*4) && l[i]<=((d[i]+c[i])*4) && l[i]%4==0)
printf("yes\n");
else
printf("no\n");
}
}
}
