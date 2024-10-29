#include <bits/stdc++.h>
using namespace std;

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

void NhapMang(int a[] , int n ) {
	for (int i = 0 ; i < n ; i++) {
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0 ; i < n ; i++) {
		cout<<a[i]<<" ";
	}
}
int Thamlam(int a[], int n , int s ,int b[]) {
	int i = 0 , p = 0 ;
	while (i<n && p <=s) {
		p+= a[i];
		b[i] = a[i];
		i++;
	}
	if (p>s) return i;
	else return -1;
}

int main() {
	int a[100], n , s , i , p;
	cout<<"Nhap n = "; cin>>n;
	cout<<"Nhap s = "; cin>>s;
	int *b = new int[1];
	NhapMang(a,n);
	BubbleSort(a,n);
	cout<<"Mang sau khi sap xep : "<<endl;
	XuatMang(a,n);
	cout<<endl;
	cout<<"Can lay it nhat "<<Thamlam(a,n,s,b) <<" phan tu trong day a de duoc tong lon hon " << s << " ."<<endl;
}