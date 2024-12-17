#include<bits/stdc++.h>

using namespace std;

int fibo1(int n ) {
	if (n <= 1) return n ;
	return fibo1(n-1) + fibo1(n-2);
}
int fibo2(int n ) {
	if (n <= 1) return n ;
	int p1 = 0  , p2 = 1 ,curr;
	for ( int i = 2 ; i <=n ; i++) {
		curr = p1 + p2 ;
		p1 = p2;
		p2 = curr;
	}
	return curr;
}

int fibo3(int n , vector<int> arr) {
	if ( n <=1 ) return n ;
	if (arr[n] != -1) return arr[n];
	return arr[n] = fibo3(n-1 , arr) + fibo3(n-2 , arr);
}
int main() {
	int n = 4 ;
	vector<int> arr(n+1 , -1);
	cout<<"Fibonacci("<<n<<") = "<<fibo1(n)<<endl;
	cout<<"Fibonacci("<<n<<") = "<<fibo2(n)<<endl;
	cout<<"Fibonacci("<<n<<") = "<<fibo3(n,arr)<<endl;
	return 0;
}