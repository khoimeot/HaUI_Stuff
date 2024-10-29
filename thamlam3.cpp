#include <bits/stdc++.h>
using namespace std;

void NhapMang(int a[] , int n ) {
	cout<<"Nhap cac menh gia ban muon"<<endl;
	for (int i = 0 ; i < n ; i++) {
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0 ; i < n ; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void BubbleSort(int a[],int n) {
	int temp;
	for (int i = 0 ; i < n ; i++) {
		for (int j = n-1;j>i;j--) {
			if (a[j-1] < a[j]) {
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}
int RutTien(int a[] , int n , int b[] , int &m ) {
	int sototien;
	cout<<"Nhap so tien anh An muon rut : "; cin>>m;
	for (int i = 0 ; i < n ; i ++) {
		if (m >= a[i]) {
			sototien = m / a[i];
			m -= sototien*a[i];
			if (sototien == 0 ) {
				b[i] = 0;
			}
			else b[i] = sototien;
			sototien = 0;
		}
	}
	cout<<"Ban rut duoc :"<<endl;
	for (int i = 0 ; i < n ; i ++) {
		cout<<b[i]<<" so to tien menh gia "<<a[i]<<endl;
	}
}

int TienThua(int m) {
	if (m>0) {
		cout<<"Ngan hang khong co to tien menh gia nao thoa man de tra so tien thua "<<m<<" .";
	}
}
int main() {
	int a[100] , n , m ;
	cout<<"Nhap n = ";cin>>n;
	int b[n];
	NhapMang(a,n);
	BubbleSort(a,n);
	XuatMang(a,n);
	RutTien(a,n,b,m);
	TienThua(m);
	
}