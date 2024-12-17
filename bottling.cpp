#include<bits/stdc++.h>

using namespace std;
void swap(int &a , int &b) {
	int temp = a ; a = b ; b = temp;
}

int partition(vector<int> &arr , int low ,  int high) {
	int i = low -1 ;
	int pivot = arr[high];
	
	for (int j = low ; j < high ; j++ ) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quicksort(vector<int> &arr , int low , int high) {
	if ( low < high ) {
		int pi = partition(arr , low , high);
		quicksort(arr , low , pi  - 1);
		quicksort(arr , pi+1 , high);
	}
}

int maxBottleFilled(vector<int> &arr , int n , long m ) {
	int filledBottles = 0 ;
	for(int i = 0 ; i < n ; i++) {
		if (m > arr[i]) {
			m-=arr[i];
			filledBottles++;
		}
		else break;
	}
	return filledBottles;
}
int main() {
	int m, n ;
	cout<<"Nhap so chai nuoc muon do nuoc vao : ";cin>>n;
	cout<<"Nhap so dung tich cua binh nuoc ban dau : ";cin>>m;
	
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++ ) {
		cout<<"Nhap dung tich chai nuoc thu "<<i+1<<" :";
		cin>>arr[i];
	}
	
	quicksort(arr,0 , n -1);
	int result = maxBottleFilled(arr,n,m);
	if(result !=0) cout<<"Vay ta co the do toi da la "<<result<<" binh nuoc ! ";
	else cout<<"Khong do duoc vao bih nuoc nao !";	