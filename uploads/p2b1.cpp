#include<stdio.h>
const int CON = 999+1;
int main()
{
int my_a[CON];
int counter = 0;
for(int i=0;i<CON;i++)
	{
	scanf("%d",&my_a[i]);
	counter = 0;
	for(int j=0;j<=i;j++)
		{
		if(my_a[j]!=42)
		counter++;
		}
	if(counter==i+1)
	printf("%d\n",my_a[i]);
	}
return 0;
}
