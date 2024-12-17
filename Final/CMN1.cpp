#include<bits/stdc++.h>
using namespace std;

int dequy(int a[] ,int n, int k , int index , int min) {
  if (index == n) {
    return min;
  }
  if (a[index] > k && a[index] < min) {
    min = a[index];
  }

 return dequy(a,n,k,index + 1 , min);
 }


int chiadetri(int a[] ,int k , int left , int right ) {
  if (left == right ) {
    return (a[left] > k) ? a[left] : INT_MAX;
  }
  int mid = (left + right) / 2;

  int leftmin = chiadetri(a , k , left , mid );
  int rightmin = chiadetri(a , k , mid+1 , right );

  return min(leftmin,rightmin );
}
int main() {
  int k = 15;
  int a[] = {1,3,4,6,8,12,56,87,45,23,12,22,34,123,45,65 ,234, 127 ,632};
  int n = sizeof(a) / sizeof(a[0]);
  cout<<dequy(a,n,k,0 , INT_MAX);
  cout<<chiadetri(a,k,0 , n-1 );

  return 0;
}