#include "iostream"
using namespace std; 

void main ()
{
int a1[4];
int a2[4];
int a3[4] = {}; 
cout << "input the array number 1 " << endl; 

for (int i = 0 ; i<4 ; i++)
{
cin >> a1[i]; 
}
cout << "input array number 2"<< endl; 

for (int i = 0 ; i < 4 ; i++)
{
cin >>a2[i]; 
}

for (int i = 0 ; i < 4 ; i++)
{
for (int j = 0 ; j < 4 ; j++)
{
{
	if ((a1[i]== a2[j])&& (a1[i]%2 == 0 && a2[j]%2==0 ))
	{
	a3[i] = a1[i];	
	}

}
}

}
for (int i = 0 ; i < 4 ; i++)
{
	cout <<a3[i]<< "  ";
}

}