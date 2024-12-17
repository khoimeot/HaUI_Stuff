//Câu 1.3. Viết chương trình gồm các yêu cầu sau:
//- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số thực.
//- Cài đặt một thuật toán tính tổng tất cả các số dương trong mảng a theo chiến lược
//chia để trị. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.


#include<bits/stdc++.h>

using namespace std;

float chiadetri(float a[] , int left , int right) {
  if (left == right) {
    return (a[left] > 0) ? a[left]:0;
  }

  int mid = left + (right - left)/2;
  float leftsum = chiadetri(a,left , mid);
  float rightsum = chiadetri(a, mid+1,right);

  return leftsum + rightsum;
}

int main() {
  int n = 22;
  float a[n] = {1.1,2.2,4.5,8.5,7.5,33.5,21.5,-345.5,76.5,54.5,23.5,-67.5,44.5,23.5,12.5,-15.5,75.5,-55.5,86.5,-97.5,753.5,-312.5};
  cout<<chiadetri(a, 0 , n -1);
  return 0;
}