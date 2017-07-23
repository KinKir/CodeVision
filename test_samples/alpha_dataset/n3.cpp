#include<stdio.h>
int main()
{
	long long int t,c,d,l,min,max;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&c,&d,&l);
		min = (c<=d*2)?(d*4):((c-d*2)+d)*4;
		max = (c+d)*4;
		if(l%4!=0 ||l<min ||l>max)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;

}
