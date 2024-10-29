#include<bits/stdc++.h>
#include<string>
using namespace std;

const int N = 4;

void quaylui(string songuoi[] , string chongoi[] , pair<string , string> sapxep[] , bool dangoi[] , int vitri , int &dem) {
	if (vitri == N) {
		for (int i = 0 ; i < N ; i++) {
			cout<< sapxep[i].first<<" : " << sapxep[i].second<< " ";
			if (i != N-1) {
				cout<<";  ";
			}
		}
		cout<<endl;
		dem++;
		return;
	}
	for (int i = 0 ; i < N ; i++ ) {
		if (!dangoi[i]) {
			dangoi[i] = true ;
			sapxep[vitri] = {chongoi[vitri] , songuoi[i]} ;
			quaylui(songuoi , chongoi , sapxep , dangoi ,  vitri + 1 ,  dem);
			dangoi[i] = false;
		}
	}
}

int main() {
	int n = 4;
	string G[N] = {	"A" ,"B" ,"C" , "D"};
	string P[N] = {	"Tung" , "Cuc" , "Truc","Mai"};
	pair<string , string > sapxep[N];
	bool dangoi[N] = {false};
	int dem = 0 ;
	quaylui(P,G,sapxep , dangoi , 0 , dem);
	cout<< "Tong so cach sap xep la " <<dem <<endl;
	return 0;
}