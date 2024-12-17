#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int char_in_string(char ch , const char* s) {
	int x = 0 ;
	while (s[x]  != '\0' ) {
		if(s[x] == ch) return x;
		x++;
	}
	return -1;
}
bool BoyerMooreHospool(const char* T , const char* P) {
	int v = strlen(P) , i = v - 1;
	while ( i < strlen(T)) {
		int k = v -1;
		while(k >-1 && T[i] == P[k]) {
			i-- ; k--;
		}
		if(k < 0) return true;
		else {
			int x = char_in_string(T[i] , P);
			if( x < 0) {
				i = i+v;
			}
			else {
				i = i+v-x-1;
			}
		}
	}
	return false;
}
int main() {
//    char* T = "GHP011H00HP00HP";
//    char* P = "HP0";
//	char* T = "abdcgtwsdvx";
//    char* P = "dcg";
	char* T = "abab";
    char* P = "cab";
    bool ans = BoyerMooreHospool(T, P);
	if(ans)  cout << "Số lần xuất hiện của P trong T (Boyer-Moore-Horspool): "<< endl;
	else cout<<"Nah";
    return 0;
}
