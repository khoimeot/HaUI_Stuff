#include<bits/stdc++.h>

using namespace std;

int fibo(int n , vector<int> arr) {
	if ( n <= 1) return n;
	if (arr[n] != -1) return arr[n];
	return arr[n] = fibo(n-1 , arr) + fibo(n-2 , arr);
}

int main() {
	int n = 4;
	vector<int> arr (n+1 , -1);
	cout<<"Fibonacci ("<<n<<") = "<<fibo(n , arr);
	return 0;
}