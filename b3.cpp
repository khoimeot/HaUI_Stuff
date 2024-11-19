#include<bits/stdc++.h>
#include<sstream>
#include<unordered_map>

using namespace std;

unordered_map<char , int > createShiftTable(const string &pattern) {
	unordered_map<char,int> shiftTable;
	int m = pattern.size();
	for (int i = 0 ; i < m - 1 ; i++) {
		shiftTable[pattern[i]] = m - i - 1;
		
	}
	return shiftTable;
}

int boyerMooreHorspool(const string text , const string & pattern) {
	int n = text.size();
	int m = pattern.size();
	unordered_map<char , int > shiftTable = createShiftTable(pattern);
	int i = 0 ; 
	while (i <= n - m) {
		int j = m -1 ;
		while (j >= 0 && pattern[j] == text[i + j]) {
			j--;
		}
		if (j < 0 ) return i ;
		i += (shiftTable.count(text[i + m - 1]) > 0 ) ? shiftTable[text[i+m-1]] : m;
	}
	return -1;
}

string replaceFirstOccurrence(string text , const string &pattern , const string &replacement) {
	int pos = boyerMooreHorspool(text , pattern);
	if (pos != -1) {
		text.replace(pos , pattern.size()  , replacement);
		
	}
	return text;
}
int main() {
	string s;
	cout<<"Nhap xau ki tu s : ";cin>>s;
	getline(cin , s);
	
	string p = "1000";
	string q = "mot nghin dong";
	int position = boyerMooreHorspool(s,p);
	if (position != -1) {
		cout<<"Xau " << p << " xuat hien tai vi tri "<<position <<endl;
		s = replaceFirstOccurrence(s , p , q);
		cout<<"Xau moi sau khi thay the : " << s << endl;
	}
	else {
		cout<<"Xau "<<p << " khong xuat hien trong sau s . "<<endl;
	}
	return 0;
}