#include <iostream>
#include <vector>
using namespace std;

// Hàm tính tổng các phần tử trong mảng a từ chỉ số low đến high
double sumArray(const vector<double>& a, int low, int high) {
    // Nếu chỉ có một phần tử, trả về giá trị của nó
    if (low == high) {
        return a[low];
    }
    // Tính chỉ số giữa của mảng
    int mid = (low + high) / 2;
    
    // Tính tổng của nửa bên trái và nửa bên phải
    double leftSum = sumArray(a, low, mid);
    double rightSum = sumArray(a, mid + 1, high);
    
    // Trả về tổng của hai nửa
    return leftSum + rightSum;
}

int main() {
    int n;
    
    // Nhập số phần tử của mảng (n ≥ 10)
    cout << "Nhập số phần tử của mảng (n >= 10): ";
    cin >> n;

    // Kiểm tra nếu n >= 10
    if (n < 10) {
        cout << "Số phần tử phải lớn hơn hoặc bằng 10!" << endl;
        return 1;
    }

    // Khởi tạo mảng a
    vector<double> a(n);

    // Nhập các phần tử của mảng a
    cout << "Nhập các phần tử của mảng a: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Tính tổng các phần tử của mảng a
    double result = sumArray(a, 0, n - 1);

    // Hiển thị kết quả
    cout << "Tổng các phần tử trong mảng a là: " << result << endl;

    return 0;
}
