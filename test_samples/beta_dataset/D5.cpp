#include<iostream>
using namespace std;
int main(){
int x[5];
int c[5];
int y[100];
int i;
for( i=0;i<=4;i++){
cout<<"enter 1 =";
cin>>x[i];}
for( i=0;i<=4;i++){
cout<<"enter 2 =";
cin>>c[i];}
for( i=0;i<=4;i++){
	if(x[i]==c[i] ){
		y[i]=x[i];}
}
for( i=0;i<=4;i++){
	cout<<" the ="<<y[i]<<endl;
}
system("pause");
}