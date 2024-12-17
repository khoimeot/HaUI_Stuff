#include <iostream>
#include <string>
using namespace std;

int countOccurrences(const string& T, const string& P) {
    int n = T.size();
    int m = P.size();
    int count = 0;

    // Duyệt qua xâu T và kiểm tra tại mỗi vị trí
    for (int i = 0; i <= n - m; i++) {
        if (T.substr(i, m) == P) {
            count++;
        }
    }

    return count;
}

int main() {
    string T = "ababcababc";
    string P = "cab";

    cout << "Số lần xuất hiện của P trong T: " << countOccurrences(T, P) << endl;

    return 0;
}
