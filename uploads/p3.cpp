#include<stdio.h>
int main()
{
int no[100],j,i=0;
scanf("%d",&no[0]);
while(no[i]!=42)
{
++i;
scanf("%d",&no[i]);
}
for(j=0;j<i;j++)
printf("\n%d",no[j]);
return 0;
}
 