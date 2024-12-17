#include<bits/stdc++.h>

using namespace std;

int c(int k , int n , vector<vector<int>> current) {
	if ( k > n) return 0;
	if (k == 0 || k== n) return 1;
	if ( current[k][n]  != -1) return current[k][n];
	return c(k-1 , n-1, current) + c(k, n -1 , current);
}

int main() {
	int n = 5 , k = 2;
	vector<vector<int>> memo(k+1 , vector<int>(n+1 , -1)) ;
	cout<<"To hop chap k cua n la :"<<c(k , n , memo)<<endl;
	
	return 0;
}