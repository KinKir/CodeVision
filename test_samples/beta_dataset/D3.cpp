#include "stdafx.h"
#include "iostream"
using namespace std;
void main()
{
int x[5];
int y[5];
int res[10];
cout<<"enter first array :"<<endl;
for(int i=0;i<5;i++)
	cin>>x[i];
cout<<"enter second array :"<<endl;
for(int i=0;i<5;i++)
	cin>>y[i];
int j=0;
for(int i=0;i<5;i++)
	for(int z=0;z<5;z++)
	if(x[i]==y[z]&&x[i]%2==0)
	{
	res[j]=x[i];
	j++;
	}
	cout<<"the even and shared numbers : ";
for(int i=0;i<j;i++)
cout<<res[i]<<" ";
cout<<endl;

}
