#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int A3(string &p) {
	istringstream iss(p);
	string word;
	int count = 0 ;
	while (iss >> word) {
		if (word == "child" || word =="Child ") {
			count++;
		}
	}
	return count;
}

string A4(string &p) {
	istringstream iss(p);
	string word;
	string result;
	
	while(iss >> word) {
		if (word == "child" || word == "Child") {
			word = "children";
		}
		result += word + " ";
	}
	
	if (!result.empty()) {
		result.pop_back();
	}
	return result;
}
int main() {
	string s = "Child is in the hood and now child is gonna be rushed";
//	cout<<"Nhap sau s : " ; cin>>s;
	
	int count = A3(s);
	cout<<"So tu 'child' trong string s la "<<count<<endl;
	string replaced_s = A4(s);
	cout<<"Xau sau khi thay the la : "<<endl <<replaced_s<<endl;
	return 0;
}