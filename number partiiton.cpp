#include <iostream>
#include <vector>

using namespace std;

// Hàm in ra các phân tích
void printPartition(const vector<int>& partition) {
    for (int i = 0; i < partition.size(); ++i) {
        cout << partition[i];
        if (i != partition.size() - 1) cout << " + ";
    }
    cout << endl;
}

// Hàm đệ quy để phân tích số n thành tổng các số nguyên dương
void partitionHelper(int n, int maxPart, vector<int>& partition) {
    if (n == 0) {
        // Khi n = 0, in ra một phân tích hợp lệ
        printPartition(partition);
        return;
    }

    // Duyệt qua các số từ maxPart xuống 1
    for (int i = min(n, maxPart); i >= 1; --i) {
        partition.push_back(i);
        partitionHelper(n - i, i, partition);  // Đệ quy tiếp
        partition.pop_back();  // Quay lại, thử số khác
    }
}

void partition(int n) {
    vector<int> partition;
    partitionHelper(n, n, partition);
}

int main() {
    int n;
    cout << "Nhập một số nguyên dương: ";
    cin >> n;

    cout << "Các cách phân tích số " << n << " thành tổng các số nguyên dương là:" << endl;
    partition(n);
    
    return 0;
}
