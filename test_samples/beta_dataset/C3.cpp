#include<iostream>
using namespace std;
void main(){
	int x[5],y[5],z[5],b[5],n=0 ;
	cout<<"please enter 5 no. " << endl;
	for(int i = 0 ; i < 5 ; i++)
		cin>>x[i];
	cout<<"please enter 5 no. " << endl;
	for(int i = 0 ; i < 5 ; i++)
		cin>>y[i];

	for(int i = 0 ; i < 5 ; i++){
	        if(x[i] % 2 == 0 && y[i] % 2 == 0 )
			z[i] = x[i];
			b[i] = y[i];
			cout<< z << endl;
	}
	for(int i = 0 ; i < 5 ; i++){
	for(int j = 0 ; j < 5 ; i++)
		if(z[i]==b[n])
		cout<<z[i];
n++;
}
}
