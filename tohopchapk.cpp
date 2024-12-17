#include<bits/stdc++.h>

using namespace std;

int tohopchapk(int k , int n ) {
	if ( k > n) return 0;
	if (k == 0 || k == n) return 1;
	return tohopchapk(k-1 , n-1) + tohopchapk(k , n-1);
}

int main() {
	int n = 5 , k = 2 ;
	cout<<"To hop chap" << k <<" cua "<<n<<" la : "<<tohopchapk(k , n)<<endl;
	
}