#include<bits/stdc++.h>

using namespace std;

bool check(string &s) {
	int n = s.length();
	for (int i = 0 ; i < n/2 ; i++) {
		if (s[i] != s[n - i - 1]) {
			return false;
		}
		
	}
	return true ;
}
string F2(string &s , int k ) {
	int n = s.length();
	int left = k ,right = k ;
	while (left >= 0 && right < n && s[left] == s[right]) {
		left -- ;
		right++;
	}
	return s.substr(left + 1 , right - left - 1);
}
int main() {
	string s ;
	cout<<"Nhap sau s : " ; cin>>s;
	
	if (check(s)) {
		cout<<"Xau la doi xung";
		
	}
	else {
		cout<<"Xau khong doi xung"<<endl;	
		int k ;
		cout<<"Nhap vi tri k :";
		cin>>k;
		if(k >= 0 && k <s.length()) {
			string result = F2(s , k-1);
			cout<<"xau con dai nhat co tam la s["<<k-1<<"] la :"<<result <<endl;
		}
		else {
			cout<<"Vi tri khong hop le "<<endl;
		}
	}
	return 0;
	
}