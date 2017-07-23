#include <iostream>
using namespace std;
void main () 
{ int x[6] , y[6] ;
cout <<"Please enter 6 numbers of thr array 1 : ";
for ( int i = 0 ; i <= 5 ; i++) 
cin >> x[i];
cout <<"Please enter 6 numbers of thr array 2 : ";
for ( int i = 0 ; i <= 5 ; i++) 
cin >> y[i];
for ( int i = 0 ; i <= 5 ; i++) 
	if ( x[i] == y[i] && i%2==0)

cout << i ;
} 