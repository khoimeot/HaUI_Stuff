#include<bits/stdc++.h>

using namespace std;

int fibo(int n ) {
	if ( n <= 1) return n;
	return fibo(n-1) + fibo(n-2);
}

int main() {
	int n = 3 ;
	cout<<"Fibonnaci ("<<n<<") = "<<fibo(n)<<endl;
	return 0;
}