#include <iostream>
#include <vector>
using namespace std;

// Hàm đệ quy tính tổng các số lẻ trong mảng a
int sumOddNumbers(const vector<int>& a, int index) {
    // Điều kiện dừng: nếu index vượt qua kích thước mảng
    if (index == a.size()) {
        return 0;
    }
    
    // Nếu a[index] là số lẻ, cộng vào tổng
    if (a[index] % 2 != 0) {
        return a[index] + sumOddNumbers(a, index + 1);
    } else {
        return sumOddNumbers(a, index + 1);
    }
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

    vector<int> a(n);

    // Nhập các phần tử của mảng a
    cout << "Nhập các phần tử của mảng a: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Tính tổng các số lẻ trong mảng a bằng thuật toán đệ quy
    int totalOddSum = sumOddNumbers(a, 0);

    // Hiển thị kết quả
    cout << "Tổng các số lẻ trong mảng a là: " << totalOddSum << endl;

    return 0;
}
