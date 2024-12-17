#include<bits/stdc++.h>

using namespace std;

void in01(int n , vector<int> current) {
	if ( current.size() == n) {
		for (auto i : current) {
			cout<<i;
		}
		cout<<endl;
		return;
	}
	
	current.push_back(0);
	in01(n , current);
	current.pop_back();
	
	current.push_back(1);
	in01(n , current);
	current.pop_back();
}

int main() {
	int n = 5;
	vector<int> arr;
	in01(n ,arr);
	return 0;
} 