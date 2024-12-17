#include<bits/stdc++.h>

using namespace std;

struct goiHang{
  int khoiluong;
  int giatri;
};

vector<goiHang> thamlam(vector<goiHang> a , int &D , int C) {
  int Tong = 0;vector<goiHang> b;
  for(const auto& part : a) {
    if (Tong + part.giatri >= C) {
      break;
    }
    b.push_back(part);
    D++;
    Tong+=part.giatri;
  }
  return b;
}
void knapsack(vector<goiHang>& a, int n, int M) {
    // dp[i][w] là giá trị tối đa khi chọn từ gói hàng 1 đến i và tổng khối lượng không vượt quá w
    int dp[n+1][M+1];

    // Khởi tạo dp
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            dp[i][w] = 0;
        }
    }

    // Cài đặt thuật toán quy hoạch động
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (a[i-1].khoiluong <= w) {
                // Chọn gói hàng thứ i hoặc không chọn
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - a[i-1].khoiluong] + a[i-1].giatri);
            } else {
                dp[i][w] = dp[i-1][w];  // Không chọn gói hàng thứ i
            }
        }
    }

    // Trả về giá trị tối đa
    int maxValue = dp[n][M];

    // Truy vết các gói hàng được chọn
    vector<int> goiHangChon;
    int w = M;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            goiHangChon.push_back(i-1);  // Gói hàng thứ i được chọn
            w -= a[i-1].khoiluong;  // Giảm trọng lượng còn lại
        }
    }

    // Đảo ngược lại để theo thứ tự chọn
    reverse(goiHangChon.begin(), goiHangChon.end());

    // In kết quả
    cout << "Gia tri lon nhat la: " << maxValue << endl;
    cout << "Cac goi hang duoc chon la: ";
    for (int i : goiHangChon) {
        cout << i + 1 << " ";  // In ra số thứ tự gói hàng (1-based)
    }
    cout << endl;
}
int main() {
  int n = 10;
  float C = 99.4;
  vector<goiHang> a;

    // Thêm dữ liệu gói hàng vào vector
    a.push_back({34, 75});   // Gói hàng 1: Khối lượng 34, Giá trị 75
    a.push_back({15, 95});   // Gói hàng 2: Khối lượng 15, Giá trị 50
    a.push_back({50, 120});  // Gói hàng 3: Khối lượng 50, Giá trị 120
    a.push_back({22, 135});   // Gói hàng 4: Khối lượng 22, Giá trị 80
  int D;
  vector<goiHang> c = thamlam(a , D , C);
  cout << "Cac goi hang duoc chon: \n";
  for(const auto& part : c) {
    cout << "Khoi luong: " << part.khoiluong << ", Gia tri: " << part.giatri << endl;
  }
  cout << "So phan tu da chon: " << D << endl;
  int M = 50;
  knapsack(a, n, M);
  return 0;
}