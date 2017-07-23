#include <iostream>
using namespace std;
void main () 
{int x[5];
int y[6];

cout << "please enter the numbers for the array x" << endl; 
for(int i=0; i<5; i++) 
{	cin >> x[i] ; }

cout << "please enter the numbers for the array y" << endl;
for(int i=0; i<6; i++) 
{cin >> y[i];}

int new_arr[10];

for (int i=0; x[i] && y[i]; i++)
	if (x[i] %2==0 && y[i] %2==0)

		cout << "the common numbers between the x array & y array are " << new_array[i];

		new_arr[i]= x[i];

} 

