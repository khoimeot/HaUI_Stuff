#include <iostream>
#include <vector>
using namespace std;

// Hàm tính tổng các số dương trong mảng bằng cách chia để trị
double sumPositiveNumbers(const vector<double>& a, int left, int right) {
    // Điều kiện dừng: Nếu chỉ còn một phần tử trong mảng
    if (left == right) {
        return a[left] > 0 ? a[left] : 0; // Nếu phần tử là số dương thì cộng, ngược lại không cộng
    }
    
    // Chia mảng thành hai phần
    int mid = (left + right) / 2;
    
    // Tính tổng các số dương trong hai phần mảng
    double leftSum = sumPositiveNumbers(a, left, mid);
    double rightSum = sumPositiveNumbers(a, mid + 1, right);
    
    // Hợp nhất kết quả
    return leftSum + rightSum;
}

int main() {
    int n;
    
    // Nhập số phần tử của mảng (n >= 10)
    cout << "Nhập số phần tử của mảng (n >= 10): ";
    cin >> n;

    if (n < 10) {
        cout << "Số phần tử phải lớn hơn hoặc bằng 10!" << endl;
        return 1;
    }

    vector<double> a(n);

    // Nhập các phần tử của mảng a
    cout << "Nhập các phần tử của mảng a: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Tính tổng các số dương trong mảng a bằng thuật toán chia để trị
    double totalPositiveSum = sumPositiveNumbers(a, 0, n - 1);

    // Hiển thị kết quả
    cout << "Tổng các số dương trong mảng a là: " << totalPositiveSum << endl;

    return 0;
}
