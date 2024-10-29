#include <bits/stdc++.h>
using namespace std;


struct Dovat{
	float trongluong , giatri , dongia; 
};


void BubbleSort(Dovat a[],int n) {
	int temp;
	for (int i = 0 ; i < n ; i++) {
		for (int j = n-1;j>i;j--) {
			if (a[j-1].dongia < a[j].dongia) {
				temp = a[j-1].dongia;
				a[j-1].dongia = a[j].dongia;
				a[j].dongia = temp;
			}
		}
	}
}


void nhap(Dovat a[], int &n , int &w) {
	cout<<"Nhap tong so luong do vat : ";cin>>n;
	cout<<"Nhap tong trong luong do vat :  ";cin>>w;
	cout<<"Vui long nhap thong tin cho "<<n<<" do vat : "<<endl;
	for (int i = 0 ; i < n ; i ++) {
		cout<<"\t Nhap thong tin cho do vat thu "<<i+1<<" :"<<endl;
		cout<<"\t\t Trong luong : "; cin>>a[i].trongluong;
		cout<<"\t\t Gia tri : ";cin>>a[i].giatri;
		a[i].dongia = a[i].giatri / a[i].trongluong ;
	}
}

int XepBalo(Dovat a[] , int n , int w) {
	int tongkl =0 , tonggt = 0;
	cout<<"Cac do vat duoc xep vao Balo la : "<<endl;
	for ( int i = 0 ; i < n ; i++) {
		if (a[i].trongluong < w) {
			tongkl += a[i].trongluong;
			tonggt += a[i].giatri;
			w-= a[i].trongluong;
			cout<<"\t - Do vat co gia tri la : "<<a[i].giatri<<" va co trong luong la "<<a[i].trongluong<<endl;
		}
	}
	cout<<"=> Balo chua duoc tong gia tri la "<<tonggt<<" va co trong luong la "<<tongkl ;
}

int main() {
	Dovat a[100];
	int n , w ;
	nhap(a,n,w);
	BubbleSort(a,n);
	XepBalo(a,n,w);
}