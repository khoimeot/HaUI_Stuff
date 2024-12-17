#include<bits/stdc++.h>

using namespace std;

int fibo(int n ) {
	if (n <=1) return n ;
	int p1 =0, p2 = 1 ,curr;
	for(int i = 2 ; i <=n ; i++) {
		curr = p1  + p2 ;
		p1 = p2 ;
		p2 = curr;
	}
	return curr;
}

int main() {
	int n = 4;
	cout<<"Fibonacci ("<<n<<") = "<<fibo(n)<<endl;
	return 0;
}