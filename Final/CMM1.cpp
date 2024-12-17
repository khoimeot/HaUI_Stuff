#include<bits/stdc++.h>

using namespace std;

float chiadetri(float a[] , int left , int right ) {
  if (left == right) {
    return a[left];
  }

  int mid = left + (right - left ) / 2;
  float leftsum = chiadetri(a , left , mid );
  float rightsum = chiadetri(a , mid+1 ,right);


  return leftsum + rightsum;
}

int main(){
  //- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số thực.
  int n = 22;
  float a[n] = {1.1,2.2,4.5,8.5,7.5,33.5,21.5,345.5,76.5,54.5,23.5,67.5,44.5,23.5,12.5,15.5,75.5,55.5,86.5,97.5,753.5,312.5};
  //Cài đặt một thuật toán tính tổng tất cả các số trong mảng a theo chiến lược chia để trị. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.
  float sum = chiadetri(a,0,n-1);
  cout<<sum;
  cout<<chiadetri(a , 0 , n-1 );
  return 0;
}