#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Thuật toán tham lam để tìm số lượng phần tử ít nhất trong mảng a sao cho tổng > C
void greedySelection(const vector<double>& a, double C, vector<double>& selected, double& totalSum, int& D) {
    totalSum = 0;
    D = 0;
    // Duyệt mảng từ cuối
    for (int i = a.size() - 1; i >= 0; i--) {
        selected.push_back(a[i]);
        totalSum += a[i];
        D++;
        if (totalSum > C) {
            break;
        }
    }
}

// Cài đặt thuật toán Boyer-Moore-Horspool
unordered_map<char, int> createShiftTable(const string& pattern) {
    int m = pattern.size();
    unordered_map<char, int> shiftTable;
    for (int i = 0; i < 256; i++) {
        shiftTable[i] = m; // Mặc định dịch chuyển toàn bộ
    }
    for (int i = 0; i < m - 1; i++) {
        shiftTable[pattern[i]] = m - 1 - i; // Cập nhật bảng dịch chuyển
    }
    return shiftTable;
}

int boyerMooreHorspool(const string& P, const string& Q) {
    int n = Q.size();
    int m = P.size();
    if (m > n) return -1;  // Nếu P dài hơn Q thì không thể tìm thấy

    unordered_map<char, int> shiftTable = createShiftTable(P);
    int i = m - 1; // Bắt đầu từ cuối chuỗi mẫu P
    int j = m - 1; // Bắt đầu từ cuối chuỗi Q

    while (i < n) {
        if (Q[j] == P[i]) {
            if (j == 0) return i;  // Nếu khớp hết chuỗi P, trả về vị trí bắt đầu
            j--; i--;
        } else {
            int shift = shiftTable[Q[i]]; // Dịch chuyển theo bảng dịch chuyển
            i = i + m - 1 < n ? i + shift : n;
            j = m - 1;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy P trong Q
}

int main() {
    int n;
    
    // Nhập số phần tử của mảng (n >= 8)
    cout << "Nhập số phần tử của mảng (n >= 8): ";
    cin >> n;

    if (n < 8) {
        cout << "Số phần tử phải lớn hơn hoặc bằng 8!" << endl;
        return 1;
    }

    vector<double> a(n);

    // Nhập các phần tử của mảng a (đã được sắp xếp theo chiều tăng dần)
    cout << "Nhập các phần tử của mảng a (theo chiều tăng dần): " << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    double C;
    cout << "Nhập giá trị C: ";
    cin >> C;

    // 1. Thuật toán tham lam để tính số lượng phần tử và tổng vượt qua C
    vector<double> selected;
    double totalSum;
    int D;
    greedySelection(a, C, selected, totalSum, D);

    cout << "Số lượng phần tử được chọn: " << D << endl;
    cout << "Tổng các phần tử được chọn: " << totalSum << endl;
    cout << "Các phần tử đã chọn trong mảng a: ";
    for (double val : selected) {
        cout << val << " ";
    }
    cout << endl;

    // 2. Thuật toán Boyer-Moore-Horspool để tìm vị trí chuỗi P trong chuỗi Q
    string P, Q;
    cout << "Nhập chuỗi P: ";
    cin.ignore();  // Để bỏ qua ký tự newline còn lại trong buffer
    getline(cin, P);
    cout << "Nhập chuỗi Q: ";
    getline(cin, Q);

    int position = boyerMooreHorspool(P, Q);
    if (position != -1) {
        cout << "Chuỗi P xuất hiện trong chuỗi Q tại vị trí: " << position << endl;
    } else {
        cout << "Chuỗi P không xuất hiện trong chuỗi Q." << endl;
    }

    return 0;
}
