#include<iostream>
using namespace std;
void main() {
int A[5] , z=0 ;
int B[5] ;
int C[]={0} ; 
for ( int i=0 ; i <5 ; i++ ) {
	cin >> A[i] ;
	cout << endl; 
	cin >> B[i] ;
	cout <<endl;

}

for ( int j =0 ; j < 5 ; j++) 
{
	for (int x=0 ;A[j] % 2 == 0 && x < 5; x++  ){
		if ( B[j] =A[j] ) {
			C[z] = B[j] ;
			z++;
		} }
}
for (int t =0 ; t <z ; t++){
	cout <<  C[t]<<endl ;}
system("pause") ; 
} 
