#include <iostream> 
using namespace std; 
void main () 
{
	int X[5]; 
	int Y[5]; 
	int Z[10]; 
	
	cout << "enter the first array numbers" << endl;
	for (int i = 0; i < 5; i++)
	cin >> X[i]; 

	cout << "enter the second array numbers" << endl;
	for (int i = 0; i < 5; i++)
	cin >> Y[i]; 

	
	cout <<"the even numbers in the first array  " << endl;
	for (int i = 0; i < 5; i++)
	if ( X[i] % 2 == 0  ) 
	
	{
		 cout << X[i] << endl;
	   

}
	cout <<"the even numbers in the second array " << endl;
	for (int i = 0; i < 5; i++)
	if ( Y[i] % 2 == 0 ) 
	{
		 cout << Y[i] << endl; 
	}

	
	for (int i = 0; i < 5; i++)
	{
		if ( X[i] == Y[i] ) 
		{
			cout << "the mutual numbers are  " << X[i] << Y[i] << endl; 
		}

		
}
}










