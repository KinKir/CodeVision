#include<stdio.h>
int main()
{
	long int min,max;
	scanf("%lld",&t);
  for(int i =0; i<t; i++)
	{
    long int t,c,d,l;
		scanf("%lld%lld%lld",&c,&d,&l);
		max = (c+d)*4;
		if (c<=d*2) min = (d*4);
    else min = ((c-d*2)+d)*4;
		if(l%4==0 || l>min || l<max)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;

}
