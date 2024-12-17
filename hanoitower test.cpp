#include<bits/stdc++.h>
using namespace std;

void hanoitower(int n , char a , char b , char c) {
	if ( n ==1 ) {
		cout<<"Chuyen dia thu 1 tu " << a <<" sang "<<b<<endl;
		return;
	}
	hanoitower(n-1 , a , c , b);
	cout<<"Chuyen dia thu "<<n<<" tu " << a <<" sang "<<b<<endl;
	hanoitower(n-1 , c , b , a);
}
int main() {
	hanoitower(3 , 'a' , 'c' , 'b');
	return 0;
	
}