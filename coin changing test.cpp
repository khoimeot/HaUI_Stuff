#include<bits/stdc++.h>
using namespace std;

void swap(int &a , int &b) {
	int temp = a ; a = b ; b = temp;
}

int partition(vector<int> &arr , int left , int right ) {
	int i = left -1 ;
	int pivot = arr[right];
	for (int j = left ; j < right ; j++) {
		if ( arr[j] > pivot) {
			i++;
			swap(arr[i] , arr[j]);
		}
	}
	swap(arr[i+1 ] , arr[right]);
	return i+1;
}

void quicksort(vector<int> &arr , int left , int right) {
	if ( left < right) {
		int pi = partition(arr,left , right);
		quicksort(arr , left , pi-1);
		quicksort(arr , pi+1 , right);
	}
}

int coinchanging(vector<int> &arr , int total ) {
	quicksort(arr , 0 , arr.size() - 1);
	int count = 0;
	for(int i : arr) {
		if (total == 0) break;
		count += total / i;
		total %= i; 
	}	
	return (total == 0) ? count : -1;
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	cout<<coinchanging(arr , 1203)<<" la so tien can dung den";
	return 0;
}