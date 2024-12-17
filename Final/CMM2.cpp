//Câu 1.2. Viết chương trình gồm các yêu cầu sau:
//- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số nguyên.
//- Cài đặt một thuật toán tính tổng tất cả các số lẻ trong mảng a theo chiến lược đệ
//qui. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.


#include<bits/stdc++.h>

using namespace std;

int dequy(int a[] , int n , int idx ) {
  if (idx == n) {
    return 0;
  }

  if (a[idx] %2 == 1) {
    return a[idx] + dequy(a , n ,idx+1 );
  }
  return dequy(a , n ,idx+1 );
}

int main() {
  int n = 15;
  int a[n] = {1,4,6,9,14,64,23,41,32,77,65,12,43,545,631};
  cout<<dequy(a,n,0);
  return 0;
}