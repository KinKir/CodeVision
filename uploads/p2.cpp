#include<stdio.h>
int main()
{
	int arr[1000];
	for(int i=0;i<1000;i++)
	{ scanf("%d",&arr[i]);
	int z=0;
	for(int x=0;x<=i;x++)
	{
		if(arr[x]!=42)
		z++;
		}	
	if(z==i+1)
	printf("%d\n",arr[i]);
	}
}