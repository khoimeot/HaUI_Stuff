#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc để lưu thông tin về từng gói hàng
struct Item {
    int weight;  // Khối lượng
    int value;   // Giá trị
};

// Hàm thuật toán tham lam để tìm số lượng gói hàng có tổng giá trị bằng đúng C
void greedyMaxItems(const vector<Item>& a, double C) {
    vector<Item> selectedItems;
    double totalValue = 0;
    
    // Duyệt qua danh sách gói hàng đã được sắp xếp theo giá trị
    for (const Item& item : a) {
        if (totalValue + item.value <= C) {
            selectedItems.push_back(item);
            totalValue += item.value;
        }
    }

    cout << "Số lượng gói hàng lấy được: " << selectedItems.size() << endl;
    cout << "Các gói hàng đã lấy: ";
    for (const Item& item : selectedItems) {
        cout << "(" << item.weight << ", " << item.value << ") ";
    }
    cout << endl;
}

// Hàm thuật toán quy hoạch động (DP) để tìm giá trị lớn nhất với tổng khối lượng không vượt quá M
void knapsackDP(const vector<Item>& a, int M) {
    int n = a.size();
    vector<int> dp(M + 1, 0);  // dp[i] là giá trị lớn nhất có thể đạt được với khối lượng i

    // Duyệt qua các gói hàng
    for (int i = 0; i < n; i++) {
        // Duyệt từ M xuống 0 để đảm bảo không tính lại gói hàng đã dùng
        for (int j = M; j >= a[i].weight; j--) {
            dp[j] = max(dp[j], dp[j - a[i].weight] + a[i].value);
        }
    }

    // Hiển thị giá trị tối đa
    cout << "Giá trị tối đa có thể đạt được: " << dp[M] << endl;

    // Tìm ra các gói hàng đã chọn
    int w = M;
    vector<Item> selectedItems;
    for (int i = n - 1; i >= 0; i--) {
        if (w >= a[i].weight && dp[w] == dp[w - a[i].weight] + a[i].value) {
            selectedItems.push_back(a[i]);
            w -= a[i].weight;
        }
    }

    // Hiển thị các gói hàng đã lấy
    cout << "Các gói hàng đã lấy: ";
    for (const Item& item : selectedItems) {
        cout << "(" << item.weight << ", " << item.value << ") ";
    }
    cout << endl;
}

int main() {
    int n, M;
    double C;
    
    // Nhập số lượng gói hàng
    cout << "Nhập số lượng gói hàng n: ";
    cin >> n;

    vector<Item> a(n);

    // Nhập các gói hàng
    cout << "Nhập các gói hàng (khối lượng và giá trị): " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Gói hàng " << i + 1 << " (Khối lượng, Giá trị): ";
        cin >> a[i].weight >> a[i].value;
    }

    // Nhập giá trị C và M
    cout << "Nhập giá trị C: ";
    cin >> C;
    cout << "Nhập giá trị M: ";
    cin >> M;

    // Ứng dụng thuật toán tham lam để tìm số lượng gói hàng có tổng giá trị bằng C
    // Sắp xếp gói hàng theo giá trị (có thể sắp xếp theo khối lượng nếu cần)
    sort(a.begin(), a.end(), [](const Item& x, const Item& y) {
        return x.value > y.value;
    });
    greedyMaxItems(a, C);

    // Ứng dụng thuật toán DP để tìm giá trị tối đa với tổng khối lượng không vượt quá M
    knapsackDP(a, M);

    return 0;
}
